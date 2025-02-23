/*
 * Jellyfin API
 *
 * No description provided (generated by Openapi Generator https://github.com/openapitools/openapi-generator)
 *
 * The version of the OpenAPI document: 10.10.6
 * 
 * Generated by: https://openapi-generator.tech
 */

use crate::models;
use serde::{Deserialize, Serialize};

#[derive(Clone, Default, Debug, PartialEq, Serialize, Deserialize)]
pub struct TunerHostInfo {
    #[serde(rename = "Id", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub id: Option<Option<String>>,
    #[serde(rename = "Url", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub url: Option<Option<String>>,
    #[serde(rename = "Type", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub r#type: Option<Option<String>>,
    #[serde(rename = "DeviceId", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub device_id: Option<Option<String>>,
    #[serde(rename = "FriendlyName", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub friendly_name: Option<Option<String>>,
    #[serde(rename = "ImportFavoritesOnly", skip_serializing_if = "Option::is_none")]
    pub import_favorites_only: Option<bool>,
    #[serde(rename = "AllowHWTranscoding", skip_serializing_if = "Option::is_none")]
    pub allow_hw_transcoding: Option<bool>,
    #[serde(rename = "AllowFmp4TranscodingContainer", skip_serializing_if = "Option::is_none")]
    pub allow_fmp4_transcoding_container: Option<bool>,
    #[serde(rename = "AllowStreamSharing", skip_serializing_if = "Option::is_none")]
    pub allow_stream_sharing: Option<bool>,
    #[serde(rename = "FallbackMaxStreamingBitrate", skip_serializing_if = "Option::is_none")]
    pub fallback_max_streaming_bitrate: Option<i32>,
    #[serde(rename = "EnableStreamLooping", skip_serializing_if = "Option::is_none")]
    pub enable_stream_looping: Option<bool>,
    #[serde(rename = "Source", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub source: Option<Option<String>>,
    #[serde(rename = "TunerCount", skip_serializing_if = "Option::is_none")]
    pub tuner_count: Option<i32>,
    #[serde(rename = "UserAgent", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub user_agent: Option<Option<String>>,
    #[serde(rename = "IgnoreDts", skip_serializing_if = "Option::is_none")]
    pub ignore_dts: Option<bool>,
}

impl TunerHostInfo {
    pub fn new() -> TunerHostInfo {
        TunerHostInfo {
            id: None,
            url: None,
            r#type: None,
            device_id: None,
            friendly_name: None,
            import_favorites_only: None,
            allow_hw_transcoding: None,
            allow_fmp4_transcoding_container: None,
            allow_stream_sharing: None,
            fallback_max_streaming_bitrate: None,
            enable_stream_looping: None,
            source: None,
            tuner_count: None,
            user_agent: None,
            ignore_dts: None,
        }
    }
}

