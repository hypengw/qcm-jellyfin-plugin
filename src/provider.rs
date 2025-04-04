use crate::default::JFDefault;
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
    db::{columns_contains, IteratorConstChunks},
    error::ConnectError,
    global::{APP_NAME, APP_VERSION},
    http::{CookieStoreRwLock, HasCookieJar, HeaderMap, HeaderValue, HttpClient},
    model::type_enum::ImageType,
    provider::{AuthInfo, AuthMethod, Context, Provider, SyncState},
    Error as AnyError, Result,
};
use qcm_core::{error::SyncError, model as sqlm};
use reqwest::Response;
use sea_orm::{sea_query::IntoIndexColumn, *};
use serde::{Deserialize, Serialize};
use std::{collections::BTreeMap, str::FromStr};
use std::{
    ops::Not,
    sync::{Arc, RwLock},
};

#[derive(Default, Clone, Debug, Serialize, Deserialize)]
struct CustomData {
    pub auth_info: AuthInfo,
    pub token: Option<String>,
    // auth_info: Option<AuthenticationResult>,
}

struct JellyfinProviderInner {
    client: HttpClient,
    id: Option<i64>,
    name: String,
    config: Option<Configuration>,
    data: CustomData,
    device_id: String,
}

pub struct JellyfinProvider {
    jar: Arc<CookieStoreRwLock>,
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
            inner: RwLock::new(JellyfinProviderInner {
                client: qcm_core::http::client_builder_with_jar(jar.clone())
                    .default_headers(headers)
                    .build()
                    .unwrap(),
                id,
                name: name.to_string(),
                config: None,
                data: CustomData::default(),
                device_id: device_id.to_string(),
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

    pub fn format_auth(&self) -> String {
        let inner = self.inner.read().unwrap();
        let token = inner.data.token.clone();
        let device_id = inner.device_id.clone();
        Self::static_format_auth(&device_id, token.as_deref())
    }

    pub fn client(&self) -> HttpClient {
        return self.inner.read().unwrap().client.clone();
    }

    pub fn base_url(&self) -> Option<String> {
        return self
            .inner
            .read()
            .unwrap()
            .config
            .as_ref()
            .map(|c| c.base_path.clone());
    }

    pub fn config(&self) -> Option<Configuration> {
        let inner = self.inner.read().unwrap();
        return inner.config.clone();
    }

    async fn sync_libraries(&self, ctx: &Context) -> Result<()> {
        let config = self.config().ok_or(ConnectError::NotAuth)?;
        let libraries = library_structure_api::get_virtual_folders(&config).await?;

        match libraries.entity {
            Some(library_structure_api::GetVirtualFoldersSuccess::Status200(items)) => {
                let items = items.iter().filter_map(|item| match &item.item_id {
                    Some(Some(id)) => Some(sqlm::library::ActiveModel {
                        library_id: NotSet,
                        name: Set(item.name.clone().flatten().unwrap_or_default()),
                        provider_id: Set(self.id().unwrap()),
                        native_id: Set(id.to_string()),
                        edit_time: Set(chrono::Local::now().naive_local()),
                    }),
                    _ => None,
                });
                sqlm::library::Entity::insert_many(items)
                    .on_conflict(
                        sea_query::OnConflict::columns([
                            sqlm::library::Column::ProviderId,
                            sqlm::library::Column::NativeId,
                        ])
                        .update_columns([
                            sqlm::library::Column::Name,
                            sqlm::library::Column::EditTime,
                        ])
                        .to_owned(),
                    )
                    .exec(&ctx.db)
                    .await?;
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
    ) -> Result<(), SyncError> {
        let config = self.config().ok_or(ConnectError::NotAuth)?;

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

            for iter in albums.const_chunks::<50>() {
                sqlm::album::Entity::insert_many(iter)
                    .on_conflict(
                        sea_query::OnConflict::columns(conflict)
                            .update_columns(
                                sqlm::album::Column::iter()
                                    .filter(|e| {
                                        !columns_contains(&conflict, e)
                                            && !columns_contains(&exclude, e)
                                    })
                                    .collect::<Vec<_>>(),
                            )
                            .to_owned(),
                    )
                    .on_empty_do_nothing()
                    .exec(&txn)
                    .await?;
            }

            if !album_artists.is_empty() {
                let conflict = [
                    sqlm::rel_album_artist::Column::LibraryId,
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
                    .expr(Expr::col((
                        sqlm::album::Entity,
                        sqlm::album::Column::LibraryId,
                    )))
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
                        Expr::col((sqlm::album::Entity, sqlm::album::Column::LibraryId))
                            .equals((sqlm::artist::Entity, sqlm::artist::Column::LibraryId)),
                    )
                    .and_where(
                        Expr::col((sqlm::artist::Entity, sqlm::artist::Column::NativeId))
                            .equals((Alias::new("item_id_map"), Alias::new("artist_item_id"))),
                    )
                    .to_owned();

                let stmt = sea_query::Query::insert()
                    .into_table(sqlm::rel_album_artist::Entity)
                    .columns([
                        sqlm::rel_album_artist::Column::LibraryId,
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
    ) -> Result<(), SyncError> {
        let config = self.config().ok_or(ConnectError::NotAuth)?;

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

            for iter in artists.const_chunks::<50>() {
                sqlm::artist::Entity::insert_many(iter)
                    .on_conflict(
                        sea_query::OnConflict::columns(conflict)
                            .update_columns(
                                sqlm::artist::Column::iter()
                                    .filter(|e| {
                                        !columns_contains(&conflict, e)
                                            && !columns_contains(&exclude, e)
                                    })
                                    .collect::<Vec<_>>(),
                            )
                            .to_owned(),
                    )
                    .on_empty_do_nothing()
                    .exec(&txn)
                    .await?;
            }
            txn.commit().await?;
        }

        Ok(())
    }

    async fn sync_songs(
        &self,
        library_id: i64,
        parent_id: &str,
        ctx: &Context,
    ) -> Result<(), SyncError> {
        let config = self.config().ok_or(ConnectError::NotAuth)?;

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

            for iter in songs.const_chunks::<50>() {
                sqlm::song::Entity::insert_many(iter)
                    .on_conflict(
                        sea_query::OnConflict::columns(conflict)
                            .update_columns(
                                sqlm::song::Column::iter()
                                    .filter(|e| {
                                        !columns_contains(&conflict, e)
                                            && !columns_contains(&exclude, e)
                                    })
                                    .collect::<Vec<_>>(),
                            )
                            .to_owned(),
                    )
                    .on_empty_do_nothing()
                    .exec(&txn)
                    .await?;
            }

            if !song_album_maps.is_empty() {
                use sea_query::{Alias, Asterisk, CommonTableExpression, Expr, Query, WithClause};
                let al_item_id_map = Alias::new("item_id_map");

                let relations = sea_query::Query::select()
                    .expr(Expr::col((sqlm::song::Entity, sqlm::song::Column::Id)))
                    .expr(Expr::col((sqlm::album::Entity, sqlm::album::Column::Id)))
                    .from(sqlm::song::Entity)
                    .inner_join(
                        al_item_id_map.clone(),
                        Expr::col((sqlm::song::Entity, sqlm::song::Column::NativeId))
                            .equals((al_item_id_map.clone(), Alias::new("song_item_id"))),
                    )
                    .inner_join(
                        sqlm::album::Entity,
                        Expr::col((sqlm::album::Entity, sqlm::album::Column::NativeId))
                            .equals((al_item_id_map.clone(), Alias::new("album_item_id"))),
                    )
                    .and_where(
                        Expr::col((sqlm::song::Entity, sqlm::song::Column::LibraryId))
                            .eq(library_id),
                    )
                    .to_owned();

                let with_clause = WithClause::new()
                    .cte(
                        CommonTableExpression::new()
                            .query(
                                Query::select()
                                    .column(Asterisk)
                                    .from_values(song_album_maps, Alias::new("input"))
                                    .to_owned(),
                            )
                            .columns([Alias::new("song_item_id"), Alias::new("album_item_id")])
                            .table_name(al_item_id_map.clone())
                            .to_owned(),
                    )
                    .cte(
                        CommonTableExpression::new()
                            .query(relations)
                            .columns([Alias::new("id"), Alias::new("album_id")])
                            .table_name(Alias::new("res"))
                            .to_owned(),
                    )
                    .to_owned();

                let builder = txn.get_database_backend();
                let stmt = sea_query::Query::update()
                    .table(sqlm::song::Entity)
                    .value(
                        sqlm::song::Column::AlbumId,
                        Expr::col((Alias::new("res"), Alias::new("album_id"))),
                    )
                    .to_owned()
                    .with(with_clause)
                    .to_owned();

                let raw = format!(
                    "
                {}
                FROM res
                WHERE res.id = song.id
                ",
                    builder.build(&stmt).to_string()
                );
                txn.execute(Statement::from_string(builder, raw)).await?;
            }

            if !song_artist_maps.is_empty() {
                let conflict = [
                    sqlm::rel_song_artist::Column::LibraryId,
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
                    .expr(Expr::col((
                        sqlm::song::Entity,
                        sqlm::song::Column::LibraryId,
                    )))
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
                        Expr::col((sqlm::song::Entity, sqlm::song::Column::LibraryId))
                            .equals((sqlm::artist::Entity, sqlm::artist::Column::LibraryId)),
                    )
                    .and_where(
                        Expr::col((sqlm::artist::Entity, sqlm::artist::Column::NativeId))
                            .equals((Alias::new("item_id_map"), Alias::new("artist_item_id"))),
                    )
                    .to_owned();

                let stmt = sea_query::Query::insert()
                    .into_table(sqlm::rel_song_artist::Entity)
                    .columns([
                        sqlm::rel_song_artist::Column::LibraryId,
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
}

impl HasCookieJar for JellyfinProvider {
    fn jar(&self) -> Arc<CookieStoreRwLock> {
        self.jar.clone()
    }
}

#[async_trait::async_trait]
impl Provider for JellyfinProvider {
    fn id(&self) -> Option<i64> {
        self.inner.read().unwrap().id
    }
    fn set_id(&self, id: Option<i64>) {
        let mut inner = self.inner.write().unwrap();
        inner.id = id;
    }
    fn name(&self) -> String {
        self.inner.read().unwrap().name.clone()
    }
    fn type_name(&self) -> &str {
        JellyfinProvider::type_name()
    }

    fn from_model(&self, model: &sqlm::provider::Model) -> Result<()> {
        let custom_data: CustomData = serde_json::from_str(&model.custom)
            .map_err(|e| anyhow!("Failed to parse custom data: {}", e))?;

        {
            let mut inner = self.inner.write().unwrap();
            inner.data = custom_data;
        }
        let auth_line = self.format_auth();
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
                base_path: model.base_url.clone(),
                user_agent: Some(format!("{}/{}", APP_NAME, APP_VERSION)),
                client: inner.client.clone(),
                ..Default::default()
            };
            inner.config = Some(config);
        }

        Ok(())
    }

    fn to_model(&self) -> sqlm::provider::ActiveModel {
        let inner = self.inner.read().unwrap();
        let provider = sqlm::provider::ActiveModel {
            provider_id: match self.id() {
                Some(id) => Set(id),
                None => NotSet,
            },
            name: Set(self.name()),
            type_: Set(self.type_name().to_string()),
            base_url: Set(inner.config.clone().map_or(String::new(), |c| c.base_path)),
            cookie: Set(String::new()),
            custom: Set(serde_json::to_string(&inner.data).unwrap_or_default()),
            edit_time: Set(chrono::Local::now().naive_local()),
        };
        provider
    }

    async fn login(&self, _ctx: &Context, info: &AuthInfo) -> Result<()> {
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
            .await?;

            if let Some(user_api::AuthenticateUserByNameSuccess::Status200(result)) =
                auth_result.entity
            {
                {
                    let mut inner = self.inner.write().unwrap();
                    inner.data.auth_info = info.clone();
                    inner.data.token = result.access_token.flatten().clone();
                }
                let auth_line = self.format_auth();
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
                return Ok(());
            }
        }
        Err(anyhow!("Login failed"))
    }

    async fn sync(&self, ctx: &Context) -> Result<()> {
        self.sync_libraries(ctx).await?;

        let libraries = sqlm::library::Entity::find()
            .filter(sqlm::library::Column::ProviderId.eq(self.id().unwrap()))
            .all(&ctx.db)
            .await?;
        for lib in libraries {
            self.sync_artists(lib.library_id, &lib.native_id, ctx)
                .await?;
            self.sync_albums(lib.library_id, &lib.native_id, ctx)
                .await?;
            self.sync_songs(lib.library_id, &lib.native_id, ctx).await?;

            // TODO: drop by time
        }
        Ok(())
    }

    async fn image(
        &self,
        _ctx: &Context,
        item_id: &str,
        image_type: ImageType,
    ) -> Result<Response, ConnectError> {
        let config = self.config().ok_or(ConnectError::NotAuth)?;
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
    ) -> Result<Response, ConnectError> {
        let config = self.config().ok_or(ConnectError::NotAuth)?;
        let item_id = uuid::Uuid::from_str(item_id)?;

        let rsp = {
            let mut req = self
                .client()
                .get(format!(
                    "{0}/Audio/{1}/stream",
                    config.base_path,
                    item_id
                ))
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
