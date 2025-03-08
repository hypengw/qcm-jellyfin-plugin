use qcm_core::plugin::Plugin;
use qcm_core::provider::{Provider, ProviderMeta};
use std::sync::Arc;

use crate::provider::JellyfinProvider;

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
            Arc::new(|name| -> Box<dyn Provider> { Box::new(JellyfinProvider::new(None, name)) }),
        );
        vec![p]
    }
}
