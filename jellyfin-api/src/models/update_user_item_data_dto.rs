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

/// UpdateUserItemDataDto : This is used by the api to get information about a item user data.
#[derive(Clone, Default, Debug, PartialEq, Serialize, Deserialize)]
pub struct UpdateUserItemDataDto {
    /// Gets or sets the rating.
    #[serde(rename = "Rating", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub rating: Option<Option<f64>>,
    /// Gets or sets the played percentage.
    #[serde(rename = "PlayedPercentage", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub played_percentage: Option<Option<f64>>,
    /// Gets or sets the unplayed item count.
    #[serde(rename = "UnplayedItemCount", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub unplayed_item_count: Option<Option<i32>>,
    /// Gets or sets the playback position ticks.
    #[serde(rename = "PlaybackPositionTicks", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub playback_position_ticks: Option<Option<i64>>,
    /// Gets or sets the play count.
    #[serde(rename = "PlayCount", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub play_count: Option<Option<i32>>,
    /// Gets or sets a value indicating whether this instance is favorite.
    #[serde(rename = "IsFavorite", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub is_favorite: Option<Option<bool>>,
    /// Gets or sets a value indicating whether this MediaBrowser.Model.Dto.UpdateUserItemDataDto is likes.
    #[serde(rename = "Likes", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub likes: Option<Option<bool>>,
    /// Gets or sets the last played date.
    #[serde(rename = "LastPlayedDate", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub last_played_date: Option<Option<String>>,
    /// Gets or sets a value indicating whether this MediaBrowser.Model.Dto.UserItemDataDto is played.
    #[serde(rename = "Played", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub played: Option<Option<bool>>,
    /// Gets or sets the key.
    #[serde(rename = "Key", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub key: Option<Option<String>>,
    /// Gets or sets the item identifier.
    #[serde(rename = "ItemId", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub item_id: Option<Option<String>>,
}

impl UpdateUserItemDataDto {
    /// This is used by the api to get information about a item user data.
    pub fn new() -> UpdateUserItemDataDto {
        UpdateUserItemDataDto {
            rating: None,
            played_percentage: None,
            unplayed_item_count: None,
            playback_position_ticks: None,
            play_count: None,
            is_favorite: None,
            likes: None,
            last_played_date: None,
            played: None,
            key: None,
            item_id: None,
        }
    }
}

