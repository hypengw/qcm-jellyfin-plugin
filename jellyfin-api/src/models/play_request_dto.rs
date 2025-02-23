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

/// PlayRequestDto : Class PlayRequestDto.
#[derive(Clone, Default, Debug, PartialEq, Serialize, Deserialize)]
pub struct PlayRequestDto {
    /// Gets or sets the playing queue.
    #[serde(rename = "PlayingQueue", skip_serializing_if = "Option::is_none")]
    pub playing_queue: Option<Vec<uuid::Uuid>>,
    /// Gets or sets the position of the playing item in the queue.
    #[serde(rename = "PlayingItemPosition", skip_serializing_if = "Option::is_none")]
    pub playing_item_position: Option<i32>,
    /// Gets or sets the start position ticks.
    #[serde(rename = "StartPositionTicks", skip_serializing_if = "Option::is_none")]
    pub start_position_ticks: Option<i64>,
}

impl PlayRequestDto {
    /// Class PlayRequestDto.
    pub fn new() -> PlayRequestDto {
        PlayRequestDto {
            playing_queue: None,
            playing_item_position: None,
            start_position_ticks: None,
        }
    }
}

