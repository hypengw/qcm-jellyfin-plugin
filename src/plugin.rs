use qcm_core::provider::{AuthMethod, Provider, ProviderMeta};
use qcm_core::{plugin::Plugin, Result};
use rust_embed::Embed;
use std::sync::Arc;

use crate::provider::JellyfinProvider;

#[derive(Embed)]
#[folder = "$CARGO_MANIFEST_DIR/assets"]
struct Asset;

pub struct JellyfinPlugin {}

impl JellyfinPlugin {
    pub fn new() -> Self {
        Self {}
    }
}

impl Plugin for JellyfinPlugin {
    fn id(&self) -> &str {
        return "qcm.plugin.jellyfin";
    }
    fn name(&self) -> &str {
        return "jellyfin";
    }

    fn provider_metas(&self) -> Vec<ProviderMeta> {
        let p = ProviderMeta::new(
            JellyfinProvider::type_name(),
            &[0],
            Arc::new(
                std::str::from_utf8(Asset::get("jellyfin.svg").unwrap().data.as_ref())
                    .unwrap()
                    .to_string(),
            ),
            Arc::new(|id, name, device_id| -> Result<Arc<dyn Provider>> {
                Ok(Arc::new(JellyfinProvider::new(id, name, device_id)))
            }),
        );
        vec![p]
    }
}
