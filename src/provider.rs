use crate::default::JFDefault;
use chrono::{DateTime, Utc};
use jellyfin_api::{
    apis::{
        self as japis, configuration::Configuration, image_api::GetItemImageParams, items_api,
        library_structure_api, user_api,
    },
    models::{self as jmodels, AuthenticateUserByName, AuthenticationResult},
};
use qcm_core::{
    anyhow,
    db::values::StringVec,
    error::ConnectError,
    global::{APP_NAME, APP_VERSION},
    http::{CookieStoreRwLock, HasCookieJar, HeaderMap, HeaderValue, HttpClient},
    provider::{AuthInfo, AuthMethod, Context, Provider, SyncState},
    Error as AnyError, Result,
};
use qcm_core::{
    error::SyncError,
    model::{
        album::{self, ActiveModel as AlbumModel},
        library,
        provider::{self, ActiveModel as ProviderModel},
    },
};
use reqwest::Response;
use sea_orm::*;
use serde::{Deserialize, Serialize};
use std::sync::{Arc, RwLock};

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
                    Some(Some(id)) => Some(library::ActiveModel {
                        library_id: NotSet,
                        name: Set(item.name.clone().flatten().unwrap_or_default()),
                        provider_id: Set(self.id().unwrap()),
                        native_id: Set(id.to_string()),
                        edit_time: Set(chrono::Local::now().naive_local()),
                    }),
                    _ => None,
                });
                library::Entity::insert_many(items)
                    .on_conflict(
                        sea_query::OnConflict::columns([
                            library::Column::ProviderId,
                            library::Column::NativeId,
                        ])
                        .update_columns([library::Column::Name, library::Column::EditTime])
                        .to_owned(),
                    )
                    .exec(&ctx.db)
                    .await?;
                Ok(())
            }
            _ => Err(anyhow!("[jellyfin] no folder found")),
        }
    }

    async fn sync_albums(&self, library_id: i64, ctx: &Context) -> Result<(), SyncError> {
        let config = self.config().ok_or(ConnectError::NotAuth)?;

        let items = items_api::get_items(
            &config,
            items_api::GetItemsParams {
                parent_id: None,
                include_item_types: Some(vec![jmodels::BaseItemKind::MusicAlbum]),
                recursive: Some(true),
                fields: Some(vec![jmodels::ItemFields::Genres]),
                ..JFDefault::jf_default()
            },
        )
        .await
        .map_err(AnyError::from)?;

        if let Some(items_api::GetItemsSuccess::Status200(result)) = items.entity {
            let now = chrono::Utc::now();
            let albums = result
                .items
                .unwrap_or_default()
                .into_iter()
                .filter_map(|item| {
                    item.id.map(|id| AlbumModel {
                        id: NotSet,
                        item_id: Set(id.to_string()),
                        library_id: Set(library_id),
                        name: Set(item.name.flatten().unwrap_or_default()),
                        pic_id: Set(item
                            .image_tags
                            .flatten()
                            .and_then(|m| m.get("Primary").cloned())
                            .unwrap_or_default()),
                        publish_time: Set(item
                            .premiere_date
                            .flatten()
                            .and_then(|d| d.parse().ok())
                            .unwrap_or(now)),
                        track_count: Set(item.child_count.flatten().unwrap_or_default() as i32),
                        description: Set(item.overview.flatten().unwrap_or_default()),
                        company: Set(String::new()),
                        type_: Set("album".to_string()),
                        genres: Set(item
                            .genres
                            .flatten()
                            .map(|v| StringVec(v))
                            .unwrap_or_default()),
                        edit_time: Set(now),
                    })
                });

            album::Entity::insert_many(albums)
                .on_conflict(
                    sea_query::OnConflict::columns([
                        album::Column::LibraryId,
                        album::Column::ItemId,
                    ])
                    .update_columns([
                        album::Column::Name,
                        album::Column::PicId,
                        album::Column::PublishTime,
                        album::Column::TrackCount,
                        album::Column::Description,
                        album::Column::Genres,
                        album::Column::EditTime,
                    ])
                    .to_owned(),
                )
                .exec(&ctx.db)
                .await?;
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

    fn from_model(&self, model: &provider::Model) -> Result<()> {
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

    fn to_model(&self) -> ProviderModel {
        let inner = self.inner.read().unwrap();
        let provider = ProviderModel {
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

        let libraries = library::Entity::find()
            .filter(library::Column::ProviderId.eq(self.id().unwrap()))
            .all(&ctx.db)
            .await?;
        for lib in libraries {
            self.sync_albums(lib.library_id, ctx).await?;
        }
        Ok(())
    }

    async fn image(
        &self,
        _ctx: &Context,
        item_id: &str,
        _image_id: &str,
    ) -> Result<Response, ConnectError> {
        let config = self.config().ok_or(ConnectError::NotAuth)?;

        let rsp = {
            let req = self
                .client()
                .get(format!(
                    "{0}/Items/{1}/Images/Primary",
                    config.base_path, item_id
                ))
                .build()?;
            self.client().execute(req).await?
        };
        Ok(rsp)
    }
}
