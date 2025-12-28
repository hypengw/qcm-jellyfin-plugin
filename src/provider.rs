use crate::default::JFDefault;
use crate::error::FromJellyfinError;
use chrono::{DateTime, Utc};
use jellyfin_api::{
    apis::{
        self as japis, configuration::Configuration, image_api::GetItemImageParams,
        library_structure_api, user_api,
    },
    models::{self as jmodels, AuthenticateUserByName, AuthenticationResult},
};
use qcm_core::{
    anyhow,
    db::{sync::sync_song_album_ids, values::Timestamp, DbChunkOper, DbOper, IteratorConstChunks},
    error::ProviderError,
    event::{Event as CoreEvent, SyncCommit},
    global::{APP_NAME, APP_VERSION},
    http::{CookieStoreRwLock, HasCookieJar, HeaderMap, HeaderValue, HttpClient},
    model::{self as sqlm, type_enum::ImageType},
    provider::{
        AuthInfo, AuthMethod, AuthResult, Context, HasCommonData, Provider, ProviderCommon,
        ProviderCommonData,
    },
    subtitle::{Subtitle, SubtitleItem},
    Error as AnyError, Result,
};
use reqwest::Response;
use sea_orm::{
    prelude::DateTimeUtc,
    sea_query::{IntoIden, IntoIndexColumn},
    *,
};
use serde::{Deserialize, Serialize};
use std::{any::type_name, collections::BTreeMap, str::FromStr};
use std::{
    ops::Not,
    sync::{Arc, RwLock},
};
use strum::IntoEnumIterator;

#[derive(Default, Clone, Debug, Serialize, Deserialize)]
struct CustomData {
    token: Option<String>,
}

struct JellyfinProviderInner {
    client: HttpClient,
    config: Option<Configuration>,
}

pub struct JellyfinProvider {
    jar: Arc<CookieStoreRwLock>,
    common: ProviderCommonData,
    inner: RwLock<JellyfinProviderInner>,
}

#[derive(Debug, Default)]
struct SyncItemCommon {
    native_id: String,
    dynamic: Option<sqlm::dynamic::ActiveModel>,
}

impl JellyfinProvider {
    pub fn new(id: Option<i64>, name: &str, device_id: &str) -> Self {
        let jar = Arc::new(CookieStoreRwLock::default());
        let mut headers = HeaderMap::new();
        headers.insert(
            "Authorization",
            HeaderValue::from_str(&Self::static_format_auth(device_id, None)).unwrap(),
        );
        Self {
            jar: jar.clone(),
            common: ProviderCommonData::new(id, name, device_id, JellyfinProvider::type_name()),
            inner: RwLock::new(JellyfinProviderInner {
                client: qcm_core::http::client_builder_with_jar(jar.clone())
                    .default_headers(headers)
                    .build()
                    .unwrap(),
                config: None,
            }),
        }
    }

    pub fn type_name() -> &'static str {
        return "jellyfin";
    }

    pub fn static_format_auth(device_id: &str, token: Option<&str>) -> String {
        let mut parts = vec![
            format!("Client={}", APP_NAME),
            format!("Version={}", APP_VERSION),
            "Device=Linux".to_string(),
            format!("DeviceId={}", device_id),
        ];

        if let Some(token) = token {
            parts.push(format!("Token={}", token));
        }

        format!("MediaBrowser {}", parts.join(", "))
    }

    pub fn format_auth(&self, token: Option<&str>) -> String {
        let device_id = &self.common.device_id;
        Self::static_format_auth(&device_id, token.as_deref())
    }

    pub fn client(&self) -> HttpClient {
        return self.inner.read().unwrap().client.clone();
    }

    pub fn config(&self) -> Option<Configuration> {
        let inner = self.inner.read().unwrap();
        return inner.config.clone();
    }

    async fn sync_libraries(&self, ctx: &Context) -> Result<()> {
        let config = self.config().ok_or(ProviderError::NotAuth)?;
        let libraries = library_structure_api::get_virtual_folders(&config).await?;

        match libraries.entity {
            Some(library_structure_api::GetVirtualFoldersSuccess::Status200(items)) => {
                let items = items.iter().filter_map(|item| match &item.item_id {
                    Some(Some(id)) => match item.collection_type.flatten() {
                        Some(t) if t == jmodels::CollectionTypeOptions::Music => {
                            Some(sqlm::library::ActiveModel {
                                library_id: NotSet,
                                name: Set(item.name.clone().flatten().unwrap_or_default()),
                                provider_id: Set(self.id().unwrap()),
                                native_id: Set(id.to_string()),
                                edit_time: Set(chrono::Local::now().to_utc()),
                            })
                        }
                        _ => None,
                    },
                    _ => None,
                });

                let txn = ctx.db.begin().await?;
                let conflict = [
                    sqlm::library::Column::ProviderId,
                    sqlm::library::Column::NativeId,
                ];
                let exclude = [sqlm::library::Column::LibraryId];
                DbOper::insert(&txn, items, &conflict, &exclude).await?;

                txn.commit().await?;
                Ok(())
            }
            _ => Err(anyhow!("[jellyfin] no folder found")),
        }
    }

    async fn sync_albums(
        &self,
        library_id: i64,
        parent_id: &str,
        ctx: &Context,
    ) -> Result<(), ProviderError> {
        let self_id = self.id().unwrap_or(-1);
        let config = self.config().ok_or(ProviderError::NotAuth)?;

        let items = japis::items_api::get_items(
            &config,
            japis::items_api::GetItemsParams {
                parent_id: Some(parent_id.to_string()),
                include_item_types: Some(vec![jmodels::BaseItemKind::MusicAlbum]),
                recursive: Some(true),
                fields: Some(vec![
                    // jmodels::ItemFields::Genres,
                    jmodels::ItemFields::ChildCount,
                    jmodels::ItemFields::Overview,
                    jmodels::ItemFields::DateCreated,
                ]),
                ..JFDefault::jf_default()
            },
        )
        .await
        .map_err(AnyError::from)?;

        if let Some(japis::items_api::GetItemsSuccess::Status200(result)) = items.entity {
            let now = chrono::Utc::now();

            let mut album_artists: Vec<(String, String)> = Vec::new();

            let mut dynamics = Vec::new();
            let mut albums = Vec::new();

            let items = result
                .items
                .unwrap_or_default()
                .into_iter()
                .filter_map(|item| {
                    item.id.map(|id| {
                        if let (Some(id), Some(artists)) = (item.id, item.album_artists.flatten()) {
                            for a in artists {
                                if let Some(a_id) = a.id {
                                    album_artists.push((id.to_string(), a_id.to_string()));
                                }
                            }
                        }

                        dynamics.push(
                            item.user_data
                                .flatten()
                                .map(|u| userdata_to_dynamic(&u, now.into())),
                        );

                        let _ = ctx.ev_sender.try_send(CoreEvent::SyncCommit {
                            id: self_id,
                            commit: SyncCommit::AddAlbum(1),
                        });

                        let album = sqlm::album::ActiveModel {
                            id: NotSet,
                            name: Set(item.name.flatten().unwrap_or_default()),
                            sort_name: Set(item.sort_name.flatten()),
                            duration: Set(item.run_time_ticks.flatten().unwrap_or_default() / 10),
                            added_at: Set(item
                                .date_created
                                .flatten()
                                .and_then(|d| d.parse().ok())
                                .map(|t: DateTimeUtc| t.into())),
                            publish_time: Set(item
                                .premiere_date
                                .flatten()
                                .and_then(|d| d.try_into().ok())),
                            track_count: Set(item.child_count.flatten().unwrap_or_default() as i32),
                            description: Set(item.overview.flatten()),
                            company: Set(None),
                            disc_count: Set(1),
                            // genres: Set(item
                            //     .genres
                            //     .flatten()
                            //     .map(|v| StringVec(v))
                            //     .unwrap_or_default()),
                            ..Default::default()
                        };
                        albums.push(album);

                        sqlm::item::ActiveModel {
                            id: NotSet,
                            native_id: Set(id.to_string()),
                            library_id: Set(Some(library_id)),
                            provider_id: Set(self_id),
                            r#type: Set(sqlm::type_enum::ItemType::Album),
                            update_at: Set(now.into()),
                            last_sync_at: Set(now.into()),
                            ..Default::default()
                        }
                    })
                });

            let txn = ctx.db.begin().await?;
            {
                let ids = qcm_core::db::sync::allocate_items(&txn, items).await?;
                DbChunkOper::<50>::insert(
                    &txn,
                    albums.into_iter().zip(ids.clone()).map(|(mut a, id)| {
                        a.id = Set(id);
                        a
                    }),
                    &[sqlm::album::Column::Id],
                    &[],
                )
                .await?;
                qcm_core::db::sync::sync_album_artist_ids(&txn, library_id, album_artists).await?;
                DbChunkOper::<50>::insert(
                    &txn,
                    dynamics.into_iter().zip(ids).filter_map(|(a, id)| {
                        a.map(|mut a| {
                            a.id = Set(id);
                            a
                        })
                    }),
                    &[sqlm::dynamic::Column::Id],
                    &[],
                )
                .await?;
            }
            txn.commit().await?;
        }

        Ok(())
    }

    async fn sync_album_artists(
        &self,
        library_id: i64,
        parent_id: &str,
        ctx: &Context,
    ) -> Result<(), ProviderError> {
        let self_id = self.id().unwrap_or(-1);
        let config = self.config().ok_or(ProviderError::NotAuth)?;

        let items = japis::artists_api::get_album_artists(
            &config,
            japis::artists_api::GetAlbumArtistsParams {
                parent_id: Some(parent_id.to_string()),
                fields: Some(vec![jmodels::ItemFields::Overview]),
                ..JFDefault::jf_default()
            },
        )
        .await
        .map_err(AnyError::from)?;

        if let Some(japis::artists_api::GetAlbumArtistsSuccess::Status200(result)) = items.entity {
            let now = chrono::Utc::now();
            let mut artists = Vec::new();
            let items = result
                .items
                .unwrap_or_default()
                .into_iter()
                .filter_map(|item| {
                    item.id.map(|id| {
                        let _ = ctx.ev_sender.try_send(CoreEvent::SyncCommit {
                            id: self_id,
                            commit: SyncCommit::AddArtist(1),
                        });
                        let artist = sqlm::artist::ActiveModel {
                            id: NotSet,
                            name: Set(item.name.flatten().unwrap_or_default()),
                            sort_name: Set(item.sort_name.flatten()),
                            music_count: Set(0),
                            album_count: Set(0),
                            description: Set(item.overview.flatten().unwrap_or_default()),
                            ..Default::default()
                        };
                        artists.push(artist);
                        sqlm::item::ActiveModel {
                            id: NotSet,
                            native_id: Set(id.to_string()),
                            library_id: Set(Some(library_id)),
                            provider_id: Set(self_id),
                            r#type: Set(sqlm::type_enum::ItemType::Artist),
                            update_at: Set(now.into()),
                            last_sync_at: Set(now.into()),
                            ..Default::default()
                        }
                    })
                });

            let txn = ctx.db.begin().await?;
            let ids = qcm_core::db::sync::allocate_items(&txn, items).await?;

            DbChunkOper::<50>::insert(
                &txn,
                artists.into_iter().zip(ids.clone()).map(|(mut a, id)| {
                    a.id = Set(id);
                    a
                }),
                &[sqlm::artist::Column::Id],
                &[
                    sqlm::artist::Column::MusicCount,
                    sqlm::artist::Column::AlbumCount,
                ],
            )
            .await?;
            txn.commit().await?;
        }

        Ok(())
    }

    async fn sync_artists(
        &self,
        library_id: i64,
        parent_id: &str,
        ctx: &Context,
    ) -> Result<(), ProviderError> {
        let self_id = self.id().unwrap_or(-1);
        let config = self.config().ok_or(ProviderError::NotAuth)?;

        let items = japis::artists_api::get_artists(
            &config,
            japis::artists_api::GetArtistsParams {
                parent_id: Some(parent_id.to_string()),
                fields: Some(vec![jmodels::ItemFields::Overview]),
                ..JFDefault::jf_default()
            },
        )
        .await
        .map_err(AnyError::from)?;

        if let Some(japis::artists_api::GetArtistsSuccess::Status200(result)) = items.entity {
            let now = chrono::Utc::now();
            let mut artists = Vec::new();
            let items = result
                .items
                .unwrap_or_default()
                .into_iter()
                .filter_map(|item| {
                    item.id.map(|id| {
                        let _ = ctx.ev_sender.try_send(CoreEvent::SyncCommit {
                            id: self_id,
                            commit: SyncCommit::AddArtist(1),
                        });
                        let artist = sqlm::artist::ActiveModel {
                            id: NotSet,
                            name: Set(item.name.flatten().unwrap_or_default()),
                            sort_name: Set(item.sort_name.flatten()),
                            music_count: Set(0),
                            album_count: Set(0),
                            description: Set(item.overview.flatten().unwrap_or_default()),
                            ..Default::default()
                        };

                        artists.push(artist);
                        sqlm::item::ActiveModel {
                            id: NotSet,
                            native_id: Set(id.to_string()),
                            library_id: Set(Some(library_id)),
                            provider_id: Set(self_id),
                            r#type: Set(sqlm::type_enum::ItemType::Artist),
                            update_at: Set(now.into()),
                            last_sync_at: Set(now.into()),
                            ..Default::default()
                        }
                    })
                });

            let txn = ctx.db.begin().await?;
            let ids = qcm_core::db::sync::allocate_items(&txn, items).await?;

            DbChunkOper::<50>::insert(
                &txn,
                artists.into_iter().zip(ids).map(|(mut a, id)| {
                    a.id = Set(id);
                    a
                }),
                &[sqlm::artist::Column::Id],
                &[
                    sqlm::artist::Column::MusicCount,
                    sqlm::artist::Column::AlbumCount,
                ],
            )
            .await?;
            txn.commit().await?;
        }

        Ok(())
    }

    async fn sync_songs(
        &self,
        library_id: i64,
        parent_id: &str,
        ctx: &Context,
    ) -> Result<(), ProviderError> {
        let self_id = self.id().unwrap_or(-1);
        let config = self.config().ok_or(ProviderError::NotAuth)?;

        let items = japis::items_api::get_items(
            &config,
            japis::items_api::GetItemsParams {
                parent_id: Some(parent_id.to_string()),
                include_item_types: Some(vec![jmodels::BaseItemKind::Audio]),
                recursive: Some(true),
                fields: Some(vec![
                    jmodels::ItemFields::Overview,
                    jmodels::ItemFields::Tags,
                ]),
                ..JFDefault::jf_default()
            },
        )
        .await
        .map_err(AnyError::from)?;

        if let Some(japis::items_api::GetItemsSuccess::Status200(result)) = items.entity {
            let now = chrono::Utc::now();

            let mut song_album_maps: Vec<(String, String)> = Vec::new();
            let mut song_artist_maps: Vec<(String, String)> = Vec::new();

            let mut dynamics = Vec::new();

            let mut songs = Vec::new();
            let items = result
                .items
                .unwrap_or_default()
                .into_iter()
                .filter_map(|item| {
                    item.id.map(|id| {
                        // Collect song-album mapping
                        if let (Some(id), Some(Some(album_id))) =
                            (item.id.as_ref(), item.album_id.as_ref())
                        {
                            song_album_maps.push((id.to_string(), album_id.to_string()));
                        }
                        if let (Some(id), Some(Some(artist_items))) =
                            (item.id.as_ref(), item.artist_items.as_ref())
                        {
                            for ar in artist_items {
                                if let Some(ar_id) = ar.id {
                                    song_artist_maps.push((id.to_string(), ar_id.to_string()));
                                }
                            }
                        }

                        let _ = ctx.ev_sender.try_send(CoreEvent::SyncCommit {
                            id: self_id,
                            commit: SyncCommit::AddSong(1),
                        });

                        dynamics.push(
                            item.user_data
                                .flatten()
                                .map(|u| userdata_to_dynamic(&u, now.into())),
                        );

                        let song = sqlm::song::ActiveModel {
                            id: NotSet,
                            album_id: Set(None),
                            name: Set(item.name.flatten().unwrap_or_default()),
                            sort_name: Set(item.sort_name.flatten()),
                            can_play: Set(true),
                            track_number: Set(item.index_number.flatten().unwrap_or_default()),
                            disc_number: Set(item
                                .parent_index_number
                                .flatten()
                                .unwrap_or_default()),
                            // it's 1e7
                            duration: Set(item.run_time_ticks.flatten().unwrap_or_default() / 10),
                            popularity: Set(0.0),
                            publish_time: Set(item
                                .premiere_date
                                .flatten()
                                .and_then(|d| d.try_into().ok())),
                            tags: Set(item.tags.flatten().unwrap_or_default().into()),
                            added_at: NotSet,
                        };

                        songs.push(song);

                        sqlm::item::ActiveModel {
                            id: NotSet,
                            native_id: Set(id.to_string()),
                            library_id: Set(Some(library_id)),
                            provider_id: Set(self_id),
                            r#type: Set(sqlm::type_enum::ItemType::Song),
                            update_at: Set(now.into()),
                            last_sync_at: Set(now.into()),
                            ..Default::default()
                        }
                    })
                });

            let txn = ctx.db.begin().await?;
            {
                let ids = qcm_core::db::sync::allocate_items(&txn, items).await?;
                DbChunkOper::<50>::insert(
                    &txn,
                    songs.into_iter().zip(ids.clone()).map(|(mut s, id)| {
                        s.id = Set(id);
                        s
                    }),
                    &[sqlm::song::Column::Id],
                    &[],
                )
                .await?;

                sync_song_album_ids(&txn, library_id, song_album_maps).await?;

                qcm_core::db::sync::sync_song_artist_ids(&txn, library_id, song_artist_maps)
                    .await?;

                DbChunkOper::<50>::insert(
                    &txn,
                    dynamics.into_iter().zip(ids).filter_map(|(a, id)| {
                        a.map(|mut a| {
                            a.id = Set(id);
                            a
                        })
                    }),
                    &[sqlm::dynamic::Column::Id],
                    &[],
                )
                .await?;
            }

            txn.commit().await?;
        }

        Ok(())
    }

    async fn sync_mixes(&self, ctx: &Context) -> Result<(), ProviderError> {
        let self_id = self.id().unwrap_or(-1);
        let config = self.config().ok_or(ProviderError::NotAuth)?;

        let items = japis::items_api::get_items(
            &config,
            japis::items_api::GetItemsParams {
                parent_id: None,
                include_item_types: Some(vec![jmodels::BaseItemKind::Playlist]),
                recursive: Some(true),
                fields: Some(vec![
                    jmodels::ItemFields::Overview,
                    jmodels::ItemFields::Tags,
                    jmodels::ItemFields::ChildCount,
                ]),
                ..JFDefault::jf_default()
            },
        )
        .await
        .map_err(AnyError::from)?;

        if let Some(japis::items_api::GetItemsSuccess::Status200(result)) = items.entity {
            let now = chrono::Utc::now();

            let mut mixes = Vec::new();
            let items = result
                .items
                .unwrap_or_default()
                .into_iter()
                .filter_map(|item| {
                    item.id.map(|id| {
                        let mix = sqlm::remote_mix::ActiveModel {
                            id: NotSet,
                            name: Set(item.name.flatten().unwrap_or_default()),
                            track_count: Set(item.child_count.flatten().unwrap_or_default() as i32),
                            description: Set(item.overview.flatten()),
                            mix_type: Set("user".to_string()),
                        };

                        mixes.push(mix);
                        sqlm::item::ActiveModel {
                            id: NotSet,
                            native_id: Set(id.to_string()),
                            library_id: Set(None),
                            provider_id: Set(self_id),
                            r#type: Set(sqlm::type_enum::ItemType::Mix),
                            update_at: Set(now.into()),
                            last_sync_at: Set(now.into()),
                            ..Default::default()
                        }
                    })
                });

            let txn = ctx.db.begin().await?;
            {
                let ids = qcm_core::db::sync::allocate_items(&txn, items).await?;

                DbChunkOper::<50>::insert(
                    &txn,
                    mixes
                        .clone()
                        .into_iter()
                        .zip(ids.clone())
                        .map(|(mut s, id)| {
                            s.id = Set(id);
                            s
                        }),
                    &[sqlm::remote_mix::Column::Id],
                    &[],
                )
                .await?;

                DbChunkOper::<50>::insert(
                    &txn,
                    mixes
                        .into_iter()
                        .zip(ids.clone())
                        .map(|(mut s, id)| sqlm::mix::ActiveModel {
                            id: NotSet,
                            name: s.name,
                            track_count: s.track_count,
                            sort_name: NotSet,
                            mix_type: Set(sqlm::type_enum::MixType::Cache),
                            remote_id: Set(Some(id)),
                            description: Set(s.description.take().flatten().unwrap_or_default()),
                            create_at: Set(now.into()),
                            update_at: Set(now.into()),
                            content_update_at: NotSet,
                        }),
                    &[sqlm::mix::Column::RemoteId],
                    &[
                        sqlm::mix::Column::Id,
                        sqlm::mix::Column::SortName,
                        sqlm::mix::Column::MixType,
                        sqlm::mix::Column::CreateAt,
                        sqlm::mix::Column::ContentUpdateAt,
                    ],
                )
                .await?;
            }
            txn.commit().await?;
        }

        Ok(())
    }
}

impl HasCookieJar for JellyfinProvider {
    fn jar(&self) -> Arc<CookieStoreRwLock> {
        self.jar.clone()
    }
}

impl HasCommonData for JellyfinProvider {
    fn common<'a>(&'a self) -> &'a ProviderCommonData {
        return &self.common;
    }
}

#[async_trait::async_trait]
impl Provider for JellyfinProvider {
    fn save(&self) -> String {
        let custom_data = CustomData {
            token: self
                .inner
                .read()
                .unwrap()
                .config
                .as_ref()
                .and_then(|c| c.bearer_access_token.clone()),
        };
        serde_json::to_string(&custom_data).unwrap()
    }

    fn load(&self, data: &str) {
        let custom_data: CustomData = serde_json::from_str(&data).unwrap_or_default();
        let auth_line = self.format_auth(custom_data.token.as_deref());
        let base_url = self.base_url();
        {
            let mut inner = self.inner.write().unwrap();
            let mut headers = HeaderMap::new();
            headers.insert("Authorization", HeaderValue::from_str(&auth_line).unwrap());
            log::warn!("auth: {}", &auth_line);
            inner.client = qcm_core::http::client_builder_with_jar(self.jar.clone())
                .default_headers(headers)
                .build()
                .unwrap();
            let config = Configuration {
                base_path: base_url,
                user_agent: Some(format!("{}/{}", APP_NAME, APP_VERSION)),
                client: inner.client.clone(),
                ..Default::default()
            };
            inner.config = Some(config);
        }
    }

    async fn check(&self, _ctx: &Context) -> Result<(), ProviderError> {
        let config = self.config().ok_or(ProviderError::NotAuth)?;
        japis::system_api::get_endpoint_info(&config)
            .await
            .map_err(ProviderError::from_err)
            .map(|_| ())
    }

    async fn auth(&self, _ctx: &Context, info: &AuthInfo) -> Result<AuthResult, ProviderError> {
        let mut config = Configuration {
            base_path: info.server_url.clone(),
            user_agent: Some(format!("{}/{}", APP_NAME, APP_VERSION)),
            client: self.client(),
            ..Default::default()
        };

        if let Some(AuthMethod::Username { username, pw }) = &info.method {
            let auth_result = user_api::authenticate_user_by_name(
                &config,
                user_api::AuthenticateUserByNameParams {
                    authenticate_user_by_name: AuthenticateUserByName {
                        username: Some(Some(username.clone())),
                        pw: Some(Some(pw.clone())),
                    },
                },
            )
            .await
            .map_err(ProviderError::from_err)?;

            if let Some(user_api::AuthenticateUserByNameSuccess::Status200(result)) =
                auth_result.entity
            {
                self.load_auth_info(&info.server_url, info.method.clone());
                let token = result.access_token.flatten().clone();
                let auth_line = self.format_auth(token.as_deref());
                config.bearer_access_token = token;
                {
                    let mut inner = self.inner.write().unwrap();
                    let mut headers = HeaderMap::new();
                    headers.insert("Authorization", HeaderValue::from_str(&auth_line).unwrap());
                    inner.client = qcm_core::http::client_builder_with_jar(self.jar.clone())
                        .default_headers(headers)
                        .build()
                        .unwrap();
                    config.client = inner.client.clone();
                    inner.config = Some(config);
                }
                return Ok(AuthResult::Ok);
            }
        }
        Ok(AuthResult::Failed {
            message: String::new(),
        })
    }

    async fn sync(&self, ctx: &Context) -> Result<(), ProviderError> {
        let now = chrono::Utc::now();

        self.sync_libraries(ctx).await?;

        let libraries = sqlm::library::Entity::find()
            .filter(sqlm::library::Column::ProviderId.eq(self.id().unwrap()))
            .all(&ctx.db)
            .await?;

        for lib in &libraries {
            self.sync_album_artists(lib.library_id, &lib.native_id, ctx)
                .await?;
            self.sync_artists(lib.library_id, &lib.native_id, ctx)
                .await?;
            self.sync_albums(lib.library_id, &lib.native_id, ctx)
                .await?;
            self.sync_songs(lib.library_id, &lib.native_id, ctx).await?;
        }
        if let Some(_) = libraries.iter().next() {
            self.sync_mixes(ctx).await?;
        }

        if let Some(id) = self.id() {
            let txn = ctx.db.begin().await?;
            qcm_core::db::sync::sync_drop_before(&txn, id, now).await?;
            txn.commit().await?;
        }
        Ok(())
    }

    async fn sync_item(&self, ctx: &Context, item: sqlm::item::Model) -> Result<(), ProviderError> {
        let self_id = self.id().unwrap_or(-1);
        let config = self.config().ok_or(ProviderError::NotAuth)?;
        let now = chrono::Utc::now();

        match item.r#type {
            sqlm::type_enum::ItemType::Mix => {
                let items = japis::user_library_api::get_item(
                    &config,
                    japis::user_library_api::GetItemParams {
                        item_id: item.native_id.clone(),
                        user_id: None,
                    },
                )
                .await
                .map_err(AnyError::from)?;

                let mut local_mix_id = 0;

                if let Some(japis::user_library_api::GetItemSuccess::Status200(result)) =
                    items.entity
                {
                    let txn = ctx.db.begin().await?;
                    {
                        let mut item = sqlm::item::Entity::find()
                            .filter(sqlm::item::Column::Id.eq(item.id))
                            .one(&txn)
                            .await?
                            .ok_or(ProviderError::NotFound)?;

                        let item_id = item.id;

                        let remote_mix = sqlm::remote_mix::ActiveModel {
                            id: Set(item.id),
                            mix_type: Set("user".to_string()),
                            name: Set(result.name.clone().flatten().unwrap_or_default()),
                            track_count: Set(
                                result.child_count.flatten().unwrap_or_default() as i32
                            ),
                            description: Set(result.overview.clone().flatten()),
                        };

                        item.last_sync_at = now.into();

                        sqlm::item::Entity::update(item.into_active_model())
                            .exec(&txn)
                            .await?;

                        sqlm::remote_mix::Entity::update(remote_mix)
                            .exec(&txn)
                            .await?;

                        let mix = sqlm::mix::ActiveModel {
                            name: Set(result.name.flatten().unwrap_or_default()),
                            track_count: Set(
                                result.child_count.flatten().unwrap_or_default() as i32
                            ),
                            sort_name: NotSet,
                            mix_type: Set(sqlm::type_enum::MixType::Cache),
                            remote_id: Set(Some(item_id)),
                            description: Set(result.overview.flatten().unwrap_or_default()),
                            create_at: NotSet,
                            update_at: Set(now.into()),
                            content_update_at: Set(now.into()),
                            id: NotSet,
                        };

                        let local_mix = sqlm::mix::Entity::insert(mix)
                            .on_conflict(
                                sea_query::OnConflict::columns([sqlm::mix::Column::RemoteId])
                                    .update_columns([
                                        sqlm::mix::Column::Name,
                                        sqlm::mix::Column::TrackCount,
                                        sqlm::mix::Column::Description,
                                        sqlm::mix::Column::UpdateAt,
                                        sqlm::mix::Column::ContentUpdateAt,
                                    ])
                                    .to_owned(),
                            )
                            .exec_with_returning(&txn)
                            .await?;

                        local_mix_id = local_mix.id;
                    }
                    txn.commit().await?;
                }

                let songs = japis::playlists_api::get_playlist_items(
                    &config,
                    japis::playlists_api::GetPlaylistItemsParams {
                        playlist_id: item.native_id.clone(),
                        ..JFDefault::jf_default()
                    },
                )
                .await
                .map_err(AnyError::from)?;

                if let Some(japis::playlists_api::GetPlaylistItemsSuccess::Status200(result)) =
                    songs.entity
                {
                    let mut song_ids: Vec<i64> = Vec::new();
                    for song in result.items.unwrap_or_default() {
                        if let Some(song_id) = song.id {
                            if let Some(sql_item) = sqlm::item::Entity::find()
                                .filter(sqlm::item::Column::NativeId.eq(song_id.to_string()))
                                .filter(sqlm::item::Column::ProviderId.eq(self_id))
                                .one(&ctx.db)
                                .await?
                            {
                                song_ids.push(sql_item.id);
                            }
                        }
                    }

                    let txn = ctx.db.begin().await?;
                    {
                        sqlm::rel_mix_song::Entity::delete_many()
                            .filter(sqlm::rel_mix_song::Column::MixId.eq(local_mix_id))
                            .exec(&txn)
                            .await?;

                        DbChunkOper::<50>::insert(
                            &txn,
                            song_ids.into_iter().enumerate().map(|(idx, song_id)| {
                                sqlm::rel_mix_song::ActiveModel {
                                    id: NotSet,
                                    mix_id: Set(local_mix_id),
                                    song_id: Set(song_id),
                                    order_idx: Set(idx as i64),
                                    update_at: Set(now.into()),
                                }
                            }),
                            &[
                                sqlm::rel_mix_song::Column::MixId,
                                sqlm::rel_mix_song::Column::SongId,
                            ],
                            &[],
                        )
                        .await?;
                    }
                    txn.commit().await?;
                }

                Ok(())
            }
            _ => Err(ProviderError::NotImplemented),
        }
    }

    async fn favorite(
        &self,
        _ctx: &Context,
        item_id: &str,
        _item_type: sqlm::type_enum::ItemType,
        value: bool,
    ) -> Result<(), ProviderError> {
        let config = self.config().ok_or(ProviderError::NotAuth)?;
        if value {
            let res = japis::user_library_api::mark_favorite_item(
                &config,
                japis::user_library_api::MarkFavoriteItemParams {
                    item_id: item_id.to_string(),
                    user_id: None,
                },
            )
            .await
            .map_err(ProviderError::from_err)?;

            match res.entity {
                Some(japis::user_library_api::MarkFavoriteItemSuccess::Status200(_)) => Ok(()),
                Some(japis::user_library_api::MarkFavoriteItemSuccess::UnknownValue(v)) => {
                    Err(ProviderError::Internal(anyhow!("{}", v)))
                }
                None => Err(ProviderError::Internal(anyhow!("{}", res.status))),
            }
        } else {
            let res = japis::user_library_api::unmark_favorite_item(
                &config,
                japis::user_library_api::UnmarkFavoriteItemParams {
                    item_id: item_id.to_string(),
                    user_id: None,
                },
            )
            .await
            .map_err(ProviderError::from_err)?;

            match res.entity {
                Some(japis::user_library_api::UnmarkFavoriteItemSuccess::Status200(_)) => Ok(()),
                Some(japis::user_library_api::UnmarkFavoriteItemSuccess::UnknownValue(v)) => {
                    Err(ProviderError::Internal(anyhow!("{}", v)))
                }
                None => Err(ProviderError::Internal(anyhow!("{}", res.status))),
            }
        }
    }

    async fn image(
        &self,
        _ctx: &Context,
        item_id: &str,
        _image_id: Option<&str>,
        image_type: ImageType,
    ) -> Result<Response, ProviderError> {
        let config = self.config().ok_or(ProviderError::NotAuth)?;
        let item_id = uuid::Uuid::from_str(item_id)?;

        let rsp = {
            let req = self
                .client()
                .get(format!(
                    "{0}/Items/{1}/Images/{2}?fillHeight=420&fillWidth=400",
                    config.base_path,
                    item_id,
                    image_type.to_string()
                ))
                .build()?;
            self.client().execute(req).await?
        };
        Ok(rsp)
    }

    async fn audio(
        &self,
        _ctx: &Context,
        item_id: &str,
        headers: Option<qcm_core::http::HeaderMap>,
    ) -> Result<Response, ProviderError> {
        let config = self.config().ok_or(ProviderError::NotAuth)?;
        let item_id = uuid::Uuid::from_str(item_id)?;

        let rsp = {
            let mut req = self
                .client()
                .get(format!("{0}/Audio/{1}/stream", config.base_path, item_id))
                .query(&[("static", "true")]);
            if let Some(headers) = headers.clone() {
                req = req.headers(headers);
            }
            let req = req.build()?;
            self.client().execute(req).await?
        };
        Ok(rsp)
    }
    async fn subtitle(&self, item_id: &str) -> Result<Subtitle, ProviderError> {
        let config = self.config().ok_or(ProviderError::NotAuth)?;

        let items = japis::lyrics_api::get_lyrics(
            &config,
            japis::lyrics_api::GetLyricsParams {
                item_id: item_id.to_string(),
            },
        )
        .await
        .map_err(AnyError::from)?;

        if let Some(japis::lyrics_api::GetLyricsSuccess::Status200(result)) = items.entity {
            if let Some(lines) = result.lyrics {
                let mut out = Subtitle::default();
                out.items = lines
                    .into_iter()
                    .map(|l| SubtitleItem {
                        start: l.start.flatten().map(|t| t / 10_i64.pow(4)),
                        end: None,
                        text: l.text,
                    })
                    .collect();
                return Ok(out);
            }
        }

        Err(ProviderError::NotFound)
    }
}

fn userdata_to_dynamic(
    user_data: &jmodels::UserItemDataDto,
    update_at: Timestamp,
) -> sqlm::dynamic::ActiveModel {
    sqlm::dynamic::ActiveModel {
        id: NotSet,
        favorite_at: Set(user_data
            .is_favorite
            .and_then(|is_favorite| match is_favorite {
                true => Some(Timestamp::new()),
                false => None,
            })),
        is_external: NotSet,
        last_position: NotSet,
        last_played_at: NotSet,
        remote_last_played_at: Set(user_data
            .last_played_date
            .clone()
            .flatten()
            .and_then(|d| d.try_into().ok())),
        play_count: NotSet,
        remote_play_count: Set(user_data.play_count.unwrap_or(0) as i64),
        update_at: Set(update_at),
    }
}
