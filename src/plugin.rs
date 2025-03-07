use qcm_core::plugin::Plugin;

pub struct JellyfinPlugin {}

impl Plugin for JellyfinPlugin {
    fn name(&self) -> &str {
        return "jellyfin";
    }
}
