use crate::default::JFDefault;
use chrono::NaiveDateTime;
use jellyfin_api::apis::items_api;
use jellyfin_api::{
    apis::configuration::Configuration, apis::user_api, models as jmodels,
    models::AuthenticateUserByName, models::AuthenticationResult,
};
use qcm_core::global::{APP_NAME, APP_VERSION};
use qcm_core::http::{CookieStoreRwLock, HasCookieJar, HeaderMap, HeaderValue, HttpClient};
use qcm_core::model::album::ActiveModel as AlbumModel;
use qcm_core::model::provider::{self, ActiveModel as ProviderModel};
use qcm_core::model::{album, library};
use qcm_core::provider::{AuthInfo, AuthMethod, Context, Provider, SyncState};
use qcm_core::{anyhow, Result};
use sea_orm::*;
use serde::{Deserialize, Serialize};
use std::sync::{Arc, RwLock};

#[derive(Default, Clone, Debug, Serialize, Deserialize)]
struct CustomData {
    pub auth_info: AuthInfo,
    pub token: Option<String>,
}

struct JellyfinProviderInner {
    client: HttpClient,
    id: Option<i64>,
    name: String,
    config: Option<Configuration>,
    data: CustomData,
    // auth_info: Option<AuthenticationResult>,
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

    async fn sync_albums(&self, library_id: i32, state: &dyn SyncState) -> Result<()> {
        let inner = self.inner.read().unwrap();
        let config = inner.config.as_ref().ok_or(anyhow!("Not configured"))?;

        let items = items_api::get_items(
            config,
            items_api::GetItemsParams {
                parent_id: None,
                include_item_types: Some(vec![jmodels::BaseItemKind::MusicAlbum]),
                recursive: Some(true),
                ..JFDefault::jf_default()
            },
        )
        .await?;

        if let Some(items_api::GetItemsSuccess::Status200(result)) = items.entity {
            if let Some(items) = result.items {
                for item in items {
                    if let Some(id) = item.id {
                        let album = AlbumModel {
                            id: NotSet,
                            item_id: Set(id.to_string()),
                            library_id: Set(library_id),
                            name: Set(item.name.flatten().unwrap_or_default()),
                            pic_url: Set(String::new()), // TODO: implement image url
                            publish_time: Set(item
                                .premiere_date
                                .flatten()
                                .and_then(|d| d.parse().ok())
                                .unwrap_or_else(|| chrono::Local::now().naive_local())),
                            track_count: Set(item.child_count.flatten().unwrap_or_default() as i32),
                            description: Set(item.overview.flatten().unwrap_or_default()),
                            company: Set(String::new()), // Jellyfin doesn't provide this info
                            type_: Set("album".to_string()),
                            edit_time: Set(chrono::Local::now().naive_local()),
                        };

                        // state.save_album(album).await?;
                    }
                }
            }
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
            inner.client = qcm_core::http::client_builder_with_jar(self.jar.clone())
                .default_headers(headers)
                .build()
                .unwrap();
        }

        Ok(())
    }

    fn to_model(&self) -> ProviderModel {
        let provider = ProviderModel {
            provider_id: match self.id() {
                Some(id) => Set(id),
                None => NotSet,
            },
            name: Set(self.name()),
            type_: Set(self.type_name().to_string()),
            cookie: Set(String::new()),
            custom: Set(serde_json::to_string(&self.inner.read().unwrap().data).unwrap_or_default()),
            edit_time: Set(chrono::Local::now().naive_local()),
        };
        provider
    }

    async fn login(&self, _ctx: &Context, info: &AuthInfo) -> Result<()> {
        let config = Configuration {
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
                let auth_line = self.format_auth();
                {
                    let mut inner = self.inner.write().unwrap();
                    // inner.data.auth_info = Some(result.clone());
                    inner.config = Some(config);
                    inner.data.auth_info = info.clone();
                    inner.data.token = result.access_token.flatten().clone();

                    let mut headers = HeaderMap::new();
                    headers.insert("Authorization", HeaderValue::from_str(&auth_line).unwrap());
                    inner.client = qcm_core::http::client_builder_with_jar(self.jar.clone())
                        .default_headers(headers)
                        .build()
                        .unwrap();
                }

                return Ok(());
            }
        }
        Err(anyhow!("Login failed"))
    }

    async fn sync(&self, ctx: &Context, state: &dyn SyncState) -> Result<()> {
        let libraries = ctx.find_libraries_by_provider(self.id().unwrap()).await?;

        for lib in libraries {
            self.sync_albums(lib.library_id, state).await?;
        }

        Ok(())
    }
}
