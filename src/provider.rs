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
    db::{sync::sync_song_album_ids, DbChunkOper, DbOper, IteratorConstChunks},
    error::ProviderError,
    event::{Event as CoreEvent, SyncCommit},
    global::{APP_NAME, APP_VERSION},
    http::{CookieStoreRwLock, HasCookieJar, HeaderMap, HeaderValue, HttpClient},
    model::{self as sqlm, type_enum::ImageType},
    provider::{
        AuthInfo, AuthMethod, AuthResult, Context, HasCommonData, Provider, ProviderCommon,
        ProviderCommonData,
    },
    Error as AnyError, Result,
};
use reqwest::Response;
use sea_orm::{
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
                    jmodels::ItemFields::Genres,
                    jmodels::ItemFields::ChildCount,
                    jmodels::ItemFields::Overview,
                ]),
                ..JFDefault::jf_default()
            },
        )
        .await
        .map_err(AnyError::from)?;

        if let Some(japis::items_api::GetItemsSuccess::Status200(result)) = items.entity {
            let now = chrono::Utc::now();

            let mut album_artists: Vec<(String, String)> = Vec::new();
            // First sync albums
            let albums = result
                .items
                .unwrap_or_default()
                .into_iter()
                .filter_map(|item| {
                    if let (Some(id), Some(artists)) = (item.id, item.artist_items.flatten()) {
                        for a in artists {
                            if let Some(a_id) = a.id {
                                album_artists.push((id.to_string(), a_id.to_string()));
                            }
                        }
                    }

                    let _ = ctx.ev_sender.try_send(CoreEvent::SyncCommit {
                        id: self_id,
                        commit: SyncCommit::AddAlbum(1),
                    });

                    item.id.map(|id| sqlm::album::ActiveModel {
                        id: NotSet,
                        native_id: Set(id.to_string()),
                        library_id: Set(library_id),
                        name: Set(item.name.flatten().unwrap_or_default()),
                        // pic_id: Set(item
                        //     .image_tags
                        //     .flatten()
                        //     .and_then(|m| m.get("Primary").cloned())
                        //     .unwrap_or_default()),
                        publish_time: Set(item
                            .premiere_date
                            .flatten()
                            .and_then(|d| d.parse().ok())
                            .unwrap_or(now)),
                        track_count: Set(item.child_count.flatten().unwrap_or_default() as i32),
                        description: Set(item.overview.flatten().unwrap_or_default()),
                        company: Set(String::new()),
                        // genres: Set(item
                        //     .genres
                        //     .flatten()
                        //     .map(|v| StringVec(v))
                        //     .unwrap_or_default()),
                        edit_time: Set(now),
                    })
                });

            let conflict = [
                sqlm::album::Column::LibraryId,
                sqlm::album::Column::NativeId,
            ];
            let exclude = [sqlm::album::Column::Id];

            let txn = ctx.db.begin().await?;

            DbChunkOper::<50>::insert(&txn, albums, &conflict, &exclude).await?;

            if !album_artists.is_empty() {
                let conflict = [
                    sqlm::rel_album_artist::Column::AlbumId,
                    sqlm::rel_album_artist::Column::ArtistId,
                ];
                use sea_query::{Alias, Asterisk, CommonTableExpression, Expr, Query, WithClause};

                let with_clause = WithClause::new()
                    .cte(
                        CommonTableExpression::new()
                            .query(
                                Query::select()
                                    .column(Asterisk)
                                    .from_values(album_artists, Alias::new("input"))
                                    .to_owned(),
                            )
                            .columns([Alias::new("album_item_id"), Alias::new("artist_item_id")])
                            .table_name(Alias::new("item_id_map"))
                            .to_owned(),
                    )
                    .to_owned();

                let relations = sea_query::Query::select()
                    .expr(Expr::col((sqlm::album::Entity, sqlm::album::Column::Id)))
                    .expr(Expr::col((sqlm::artist::Entity, sqlm::artist::Column::Id)))
                    .expr(Expr::value(now))
                    .from(sqlm::album::Entity)
                    .inner_join(
                        Alias::new("item_id_map"),
                        Expr::col((sqlm::album::Entity, sqlm::album::Column::NativeId))
                            .equals((Alias::new("item_id_map"), Alias::new("album_item_id"))),
                    )
                    .inner_join(
                        sqlm::artist::Entity,
                        Expr::col((sqlm::artist::Entity, sqlm::artist::Column::NativeId))
                            .equals((Alias::new("item_id_map"), Alias::new("artist_item_id"))),
                    )
                    .to_owned();

                let stmt = sea_query::Query::insert()
                    .into_table(sqlm::rel_album_artist::Entity)
                    .columns([
                        sqlm::rel_album_artist::Column::AlbumId,
                        sqlm::rel_album_artist::Column::ArtistId,
                        sqlm::rel_album_artist::Column::EditTime,
                    ])
                    .select_from(relations)
                    .unwrap()
                    .on_conflict(
                        sea_query::OnConflict::columns(conflict)
                            .update_column(sqlm::rel_album_artist::Column::EditTime)
                            .to_owned(),
                    )
                    .to_owned()
                    .with(with_clause)
                    .to_owned();
                let builder = txn.get_database_backend();
                txn.execute(builder.build(&stmt)).await?;
            }

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
            let artists = result
                .items
                .unwrap_or_default()
                .into_iter()
                .filter_map(|item| {
                    let _ = ctx.ev_sender.try_send(CoreEvent::SyncCommit {
                        id: self_id,
                        commit: SyncCommit::AddArtist(1),
                    });
                    item.id.map(|id| sqlm::artist::ActiveModel {
                        id: NotSet,
                        native_id: Set(id.to_string()),
                        library_id: Set(library_id),
                        name: Set(item.name.flatten().unwrap_or_default()),
                        music_count: Set(0),
                        album_count: Set(0),
                        description: Set(item.overview.flatten().unwrap_or_default()),
                        edit_time: Set(now),
                    })
                });

            let conflict = [
                sqlm::artist::Column::LibraryId,
                sqlm::artist::Column::NativeId,
            ];
            let exclude = [
                sqlm::artist::Column::Id,
                sqlm::artist::Column::MusicCount,
                sqlm::artist::Column::AlbumCount,
            ];

            let txn = ctx.db.begin().await?;
            DbChunkOper::<50>::insert(&txn, artists, &conflict, &exclude).await?;
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

            let songs = result
                .items
                .unwrap_or_default()
                .into_iter()
                .filter_map(|item| {
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

                    item.id.map(|id| sqlm::song::ActiveModel {
                        id: NotSet,
                        native_id: Set(id.to_string()),
                        library_id: Set(library_id),
                        album_id: Set(None),
                        name: Set(item.name.flatten().unwrap_or_default()),
                        can_play: Set(true),
                        track_number: Set(item.index_number.flatten().unwrap_or_default()),
                        disc_number: Set(item.parent_index_number.flatten().unwrap_or_default()),
                        // it's 1e7
                        duration: Set(item.run_time_ticks.flatten().unwrap_or_default() / 10),
                        edit_time: Set(now),
                        popularity: Set(0.0),
                        publish_time: Set(item
                            .premiere_date
                            .flatten()
                            .and_then(|d| d.parse().ok())
                            .unwrap_or(now)),
                        tags: Set(item.tags.flatten().unwrap_or_default().into()),
                    })
                });

            let conflict = [sqlm::song::Column::LibraryId, sqlm::song::Column::NativeId];
            let exclude = [sqlm::song::Column::Id];

            let txn = ctx.db.begin().await?;
            DbChunkOper::<50>::insert(&txn, songs, &conflict, &exclude).await?;

            if !song_album_maps.is_empty() {
                sync_song_album_ids(&txn, library_id, song_album_maps).await?;
            }

            if !song_artist_maps.is_empty() {
                let conflict = [
                    sqlm::rel_song_artist::Column::SongId,
                    sqlm::rel_song_artist::Column::ArtistId,
                ];
                use sea_query::{Alias, Asterisk, CommonTableExpression, Expr, Query, WithClause};

                let with_clause = WithClause::new()
                    .cte(
                        CommonTableExpression::new()
                            .query(
                                Query::select()
                                    .column(Asterisk)
                                    .from_values(song_artist_maps, Alias::new("input"))
                                    .to_owned(),
                            )
                            .columns([Alias::new("song_item_id"), Alias::new("artist_item_id")])
                            .table_name(Alias::new("item_id_map"))
                            .to_owned(),
                    )
                    .to_owned();

                let relations = sea_query::Query::select()
                    .expr(Expr::col((sqlm::song::Entity, sqlm::song::Column::Id)))
                    .expr(Expr::col((sqlm::artist::Entity, sqlm::artist::Column::Id)))
                    .expr(Expr::value(now))
                    .from(sqlm::song::Entity)
                    .inner_join(
                        Alias::new("item_id_map"),
                        Expr::col((sqlm::song::Entity, sqlm::song::Column::NativeId))
                            .equals((Alias::new("item_id_map"), Alias::new("song_item_id"))),
                    )
                    .inner_join(
                        sqlm::artist::Entity,
                        Expr::col((sqlm::artist::Entity, sqlm::artist::Column::NativeId))
                            .equals((Alias::new("item_id_map"), Alias::new("artist_item_id"))),
                    )
                    .to_owned();

                let stmt = sea_query::Query::insert()
                    .into_table(sqlm::rel_song_artist::Entity)
                    .columns([
                        sqlm::rel_song_artist::Column::SongId,
                        sqlm::rel_song_artist::Column::ArtistId,
                        sqlm::rel_song_artist::Column::EditTime,
                    ])
                    .select_from(relations)
                    .unwrap()
                    .on_conflict(
                        sea_query::OnConflict::columns(conflict)
                            .update_column(sqlm::rel_song_artist::Column::EditTime)
                            .to_owned(),
                    )
                    .to_owned()
                    .with(with_clause)
                    .to_owned();

                let builder = txn.get_database_backend();
                txn.execute(builder.build(&stmt)).await?;
            }

            txn.commit().await?;
        }

        Ok(())
    }

    async fn sync_mixes(&self, provider_id: i64, ctx: &Context) -> Result<(), ProviderError> {
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
                ]),
                ..JFDefault::jf_default()
            },
        )
        .await
        .map_err(AnyError::from)?;

        if let Some(japis::items_api::GetItemsSuccess::Status200(result)) = items.entity {
            let now = chrono::Utc::now();
            // let mut mix_song_maps: Vec<(String, String)> = Vec::new();

            let mixes = result
                .items
                .unwrap_or_default()
                .into_iter()
                .filter_map(|item| {
                    // Collect mix-song mapping if item has child items
                    // if let (Some(id), Some(child_count)) =
                    //     (item.id.as_ref(), item.child_count.flatten())
                    // {
                    //     if child_count > 0 {
                    //         // if let Ok(child_items) = japis::playlists_api::get_playlist_items(
                    //         //     &config,
                    //         //     japis::playlists_api::GetPlaylistItemsParams {
                    //         //         playlist_id: id.to_string(),
                    //         //         ..JFDefault::jf_default()
                    //         //     },
                    //         // )
                    //         // .await
                    //         {
                    //             if let Some(
                    //                 japis::playlists_api::GetPlaylistItemsSuccess::Status200(
                    //                     child_result,
                    //                 ),
                    //             ) = child_items.entity
                    //             {
                    //                 for child in child_result.items.unwrap_or_default() {
                    //                     if let Some(child_id) = child.id {
                    //                         mix_song_maps
                    //                             .push((id.to_string(), child_id.to_string()));
                    //                     }
                    //                 }
                    //             }
                    //         }
                    //     }
                    // }

                    item.id.map(|id| sqlm::mix::ActiveModel {
                        id: NotSet,
                        native_id: Set(id.to_string()),
                        provider_id: Set(provider_id),
                        name: Set(item.name.flatten().unwrap_or_default()),
                        track_count: Set(item.child_count.flatten().unwrap_or_default() as i32),
                        special_type: Set(0),
                        description: Set(item.overview.flatten().unwrap_or_default()),
                        tags: Set(item.tags.flatten().unwrap_or_default().into()),
                        create_time: Set(item
                            .date_created
                            .flatten()
                            .and_then(|d| d.parse().ok())
                            .unwrap_or(now)),
                        update_time: Set(item
                            .date_last_media_added
                            .flatten()
                            .and_then(|d| d.parse().ok())
                            .unwrap_or(now)),
                        edit_time: Set(now),
                    })
                });

            let conflict = [sqlm::mix::Column::ProviderId, sqlm::mix::Column::NativeId];
            let exclude = [sqlm::mix::Column::Id];

            let txn = ctx.db.begin().await?;

            DbChunkOper::<50>::insert(&txn, mixes, &conflict, &exclude).await?;

            // Handle mix-song relationships
            // if !mix_song_maps.is_empty() {
            //     use sea_query::{Alias, Asterisk, CommonTableExpression, Expr, Query, WithClause};

            //     let with_clause = WithClause::new()
            //         .cte(
            //             CommonTableExpression::new()
            //                 .query(
            //                     Query::select()
            //                         .column(Asterisk)
            //                         .from_values(mix_song_maps, Alias::new("input"))
            //                         .to_owned(),
            //                 )
            //                 .columns([Alias::new("mix_item_id"), Alias::new("song_item_id")])
            //                 .table_name(Alias::new("item_id_map"))
            //                 .to_owned(),
            //         )
            //         .to_owned();

            //     let relations = sea_query::Query::select()
            //         .expr(Expr::col((sqlm::mix::Entity, sqlm::mix::Column::LibraryId)))
            //         .expr(Expr::col((sqlm::mix::Entity, sqlm::mix::Column::Id)))
            //         .expr(Expr::col((sqlm::song::Entity, sqlm::song::Column::Id)))
            //         .expr(Expr::value(now))
            //         .from(sqlm::mix::Entity)
            //         .inner_join(
            //             Alias::new("item_id_map"),
            //             Expr::col((sqlm::mix::Entity, sqlm::mix::Column::NativeId))
            //                 .equals((Alias::new("item_id_map"), Alias::new("mix_item_id"))),
            //         )
            //         .inner_join(
            //             sqlm::song::Entity,
            //             Expr::col((sqlm::song::Entity, sqlm::song::Column::LibraryId))
            //                 .equals((sqlm::mix::Entity, sqlm::mix::Column::LibraryId)),
            //         )
            //         .and_where(
            //             Expr::col((sqlm::song::Entity, sqlm::song::Column::NativeId))
            //                 .equals((Alias::new("item_id_map"), Alias::new("song_item_id"))),
            //         )
            //         .to_owned();

            //     let stmt = sea_query::Query::insert()
            //         .into_table(sqlm::rel_mix_song::Entity)
            //         .columns([
            //             sqlm::rel_mix_song::Column::LibraryId,
            //             sqlm::rel_mix_song::Column::MixId,
            //             sqlm::rel_mix_song::Column::SongId,
            //             sqlm::rel_mix_song::Column::EditTime,
            //         ])
            //         .select_from(relations)
            //         .unwrap()
            //         .on_conflict(
            //             sea_query::OnConflict::columns([
            //                 sqlm::rel_mix_song::Column::LibraryId,
            //                 sqlm::rel_mix_song::Column::MixId,
            //                 sqlm::rel_mix_song::Column::SongId,
            //             ])
            //             .update_column(sqlm::rel_mix_song::Column::EditTime)
            //             .to_owned(),
            //         )
            //         .to_owned()
            //         .with(with_clause)
            //         .to_owned();

            //     let builder = txn.get_database_backend();
            //     txn.execute(builder.build(&stmt)).await?;
            // }

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

        if let AuthMethod::Username { username, pw } = &info.method {
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
                self.load_auth_info(&info.server_url, Some(info.method.clone()));
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
            self.sync_artists(lib.library_id, &lib.native_id, ctx)
                .await?;
            self.sync_albums(lib.library_id, &lib.native_id, ctx)
                .await?;
            self.sync_songs(lib.library_id, &lib.native_id, ctx).await?;
        }
        if let Some(lib) = libraries.iter().next() {
            self.sync_mixes(lib.provider_id, ctx).await?;
        }

        if let Some(id) = self.id() {
            let txn = ctx.db.begin().await?;
            qcm_core::db::sync::sync_drop_before(&txn, id, now).await?;
            txn.commit().await?;
        }
        Ok(())
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
                    "{0}/Items/{1}/Images/{2}",
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
}
