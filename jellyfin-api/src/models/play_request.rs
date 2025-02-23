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

/// PlayRequest : Class PlayRequest.
#[derive(Clone, Default, Debug, PartialEq, Serialize, Deserialize)]
pub struct PlayRequest {
    /// Gets or sets the item ids.
    #[serde(rename = "ItemIds", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub item_ids: Option<Option<Vec<uuid::Uuid>>>,
    /// Gets or sets the start position ticks that the first item should be played at.
    #[serde(rename = "StartPositionTicks", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub start_position_ticks: Option<Option<i64>>,
    /// Gets or sets the play command.
    #[serde(rename = "PlayCommand", skip_serializing_if = "Option::is_none")]
    pub play_command: Option<models::PlayCommand>,
    /// Gets or sets the controlling user identifier.
    #[serde(rename = "ControllingUserId", skip_serializing_if = "Option::is_none")]
    pub controlling_user_id: Option<uuid::Uuid>,
    #[serde(rename = "SubtitleStreamIndex", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub subtitle_stream_index: Option<Option<i32>>,
    #[serde(rename = "AudioStreamIndex", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub audio_stream_index: Option<Option<i32>>,
    #[serde(rename = "MediaSourceId", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub media_source_id: Option<Option<String>>,
    #[serde(rename = "StartIndex", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub start_index: Option<Option<i32>>,
}

impl PlayRequest {
    /// Class PlayRequest.
    pub fn new() -> PlayRequest {
        PlayRequest {
            item_ids: None,
            start_position_ticks: None,
            play_command: None,
            controlling_user_id: None,
            subtitle_stream_index: None,
            audio_stream_index: None,
            media_source_id: None,
            start_index: None,
        }
    }
}

