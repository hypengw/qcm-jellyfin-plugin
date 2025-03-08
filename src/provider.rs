use jellyfin_api::{
    apis::configuration::Configuration, apis::user_api, models as jmodels,
    models::AuthenticateUserByName, models::AuthenticationResult,
};
use qcm_core::http::{CookieStoreRwLock, HasCookieJar, HttpClient};
use qcm_core::model::provider::{self, ActiveModel as ProviderModel};
use qcm_core::provider::{AuthInfo, AuthMethod, Context, Provider, SyncState};
use qcm_core::{anyhow, Result};
use sea_orm::*;
use std::sync::{Arc, RwLock};

struct JellyfinProviderInner {
    id: Option<i64>,
    name: String,
    config: Option<Configuration>,
    auth_info: Option<AuthenticationResult>,
}

pub struct JellyfinProvider {
    client: HttpClient,
    jar: Arc<CookieStoreRwLock>,
    inner: Arc<RwLock<JellyfinProviderInner>>,
}

impl JellyfinProvider {
    pub fn new(id: Option<i64>, name: &str) -> Self {
        let jar = Arc::new(CookieStoreRwLock::default());
        Self {
            client: qcm_core::http::client_builder_with_jar(jar.clone())
                .build()
                .unwrap(),
            jar: jar,
            inner: Arc::new(RwLock::new(JellyfinProviderInner {
                id,
                name: name.to_string(),
                config: None,
                auth_info: None,
            })),
        }
    }

    pub fn type_name() -> &'static str {
        return "jellyfin";
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
    async fn login(&self, ctx: &Context, info: AuthInfo) -> Result<()> {
        let config = Configuration {
            base_path: info.server_url.clone(),
            user_agent: Some("QcmBackend/1.0".to_string()),
            client: self.client.clone(),
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
                    inner.auth_info = Some(result.clone());
                    inner.config = Some(config);
                }

                let provider = ProviderModel {
                    provider_id: match self.id() {
                        Some(id) => Set(id),
                        None => NotSet,
                    },
                    name: Set("jellyfin".to_string()),
                    type_: Set(self.type_name().to_string()),
                    auth: Set(serde_json::to_string(&info).unwrap_or_default()),
                    cookie: Set(serde_json::to_string(&result).unwrap_or_default()),
                    edit_time: Set(chrono::Local::now().naive_local()),
                };

                provider::Entity::insert(provider.clone())
                    .on_conflict(
                        sea_query::OnConflict::column(provider::Column::ProviderId)
                            .update_columns([
                                provider::Column::Auth,
                                provider::Column::Cookie,
                                provider::Column::EditTime,
                            ])
                            .to_owned(),
                    )
                    .exec(&ctx.db)
                    .await?;

                return Ok(());
            }
        }
        Err(anyhow!("Login failed"))
    }

    async fn sync(&self, ctx: &Context, state: &dyn SyncState) -> Result<()> {
        let inner = self.inner.read().unwrap();
        // 获取用户的媒体库
        // let libraries = user_api::get_user_views(
        //     &config,
        //     &auth_info.user.as_ref().unwrap().id,
        // ).await?;

        // // 遍历媒体库并同步数据
        // for library in libraries.items.unwrap_or_default() {
        //     state.update_progress(format!(
        //         "正在同步媒体库: {}",
        //         library.name.unwrap_or_default()
        //     ));
        //     // TODO: 实现具体的媒体库同步逻辑
        // }
        Ok(())
    }
}
