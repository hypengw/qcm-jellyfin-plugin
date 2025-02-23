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
pub struct MusicVideoInfo {
    /// Gets or sets the name.
    #[serde(rename = "Name", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub name: Option<Option<String>>,
    /// Gets or sets the original title.
    #[serde(rename = "OriginalTitle", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub original_title: Option<Option<String>>,
    /// Gets or sets the path.
    #[serde(rename = "Path", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub path: Option<Option<String>>,
    /// Gets or sets the metadata language.
    #[serde(rename = "MetadataLanguage", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub metadata_language: Option<Option<String>>,
    /// Gets or sets the metadata country code.
    #[serde(rename = "MetadataCountryCode", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub metadata_country_code: Option<Option<String>>,
    /// Gets or sets the provider ids.
    #[serde(rename = "ProviderIds", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub provider_ids: Option<Option<std::collections::HashMap<String, String>>>,
    /// Gets or sets the year.
    #[serde(rename = "Year", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub year: Option<Option<i32>>,
    #[serde(rename = "IndexNumber", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub index_number: Option<Option<i32>>,
    #[serde(rename = "ParentIndexNumber", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub parent_index_number: Option<Option<i32>>,
    #[serde(rename = "PremiereDate", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub premiere_date: Option<Option<String>>,
    #[serde(rename = "IsAutomated", skip_serializing_if = "Option::is_none")]
    pub is_automated: Option<bool>,
    #[serde(rename = "Artists", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub artists: Option<Option<Vec<String>>>,
}

impl MusicVideoInfo {
    pub fn new() -> MusicVideoInfo {
        MusicVideoInfo {
            name: None,
            original_title: None,
            path: None,
            metadata_language: None,
            metadata_country_code: None,
            provider_ids: None,
            year: None,
            index_number: None,
            parent_index_number: None,
            premiere_date: None,
            is_automated: None,
            artists: None,
        }
    }
}

