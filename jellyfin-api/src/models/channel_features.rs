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
pub struct ChannelFeatures {
    /// Gets or sets the name.
    #[serde(rename = "Name", skip_serializing_if = "Option::is_none")]
    pub name: Option<String>,
    /// Gets or sets the identifier.
    #[serde(rename = "Id", skip_serializing_if = "Option::is_none")]
    pub id: Option<uuid::Uuid>,
    /// Gets or sets a value indicating whether this instance can search.
    #[serde(rename = "CanSearch", skip_serializing_if = "Option::is_none")]
    pub can_search: Option<bool>,
    /// Gets or sets the media types.
    #[serde(rename = "MediaTypes", skip_serializing_if = "Option::is_none")]
    pub media_types: Option<Vec<models::ChannelMediaType>>,
    /// Gets or sets the content types.
    #[serde(rename = "ContentTypes", skip_serializing_if = "Option::is_none")]
    pub content_types: Option<Vec<models::ChannelMediaContentType>>,
    /// Gets or sets the maximum number of records the channel allows retrieving at a time.
    #[serde(rename = "MaxPageSize", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub max_page_size: Option<Option<i32>>,
    /// Gets or sets the automatic refresh levels.
    #[serde(rename = "AutoRefreshLevels", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub auto_refresh_levels: Option<Option<i32>>,
    /// Gets or sets the default sort orders.
    #[serde(rename = "DefaultSortFields", skip_serializing_if = "Option::is_none")]
    pub default_sort_fields: Option<Vec<models::ChannelItemSortField>>,
    /// Gets or sets a value indicating whether a sort ascending/descending toggle is supported.
    #[serde(rename = "SupportsSortOrderToggle", skip_serializing_if = "Option::is_none")]
    pub supports_sort_order_toggle: Option<bool>,
    /// Gets or sets a value indicating whether [supports latest media].
    #[serde(rename = "SupportsLatestMedia", skip_serializing_if = "Option::is_none")]
    pub supports_latest_media: Option<bool>,
    /// Gets or sets a value indicating whether this instance can filter.
    #[serde(rename = "CanFilter", skip_serializing_if = "Option::is_none")]
    pub can_filter: Option<bool>,
    /// Gets or sets a value indicating whether [supports content downloading].
    #[serde(rename = "SupportsContentDownloading", skip_serializing_if = "Option::is_none")]
    pub supports_content_downloading: Option<bool>,
}

impl ChannelFeatures {
    pub fn new() -> ChannelFeatures {
        ChannelFeatures {
            name: None,
            id: None,
            can_search: None,
            media_types: None,
            content_types: None,
            max_page_size: None,
            auto_refresh_levels: None,
            default_sort_fields: None,
            supports_sort_order_toggle: None,
            supports_latest_media: None,
            can_filter: None,
            supports_content_downloading: None,
        }
    }
}

