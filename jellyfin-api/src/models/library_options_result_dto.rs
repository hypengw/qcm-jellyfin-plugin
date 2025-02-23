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

/// LibraryOptionsResultDto : Library options result dto.
#[derive(Clone, Default, Debug, PartialEq, Serialize, Deserialize)]
pub struct LibraryOptionsResultDto {
    /// Gets or sets the metadata savers.
    #[serde(rename = "MetadataSavers", skip_serializing_if = "Option::is_none")]
    pub metadata_savers: Option<Vec<models::LibraryOptionInfoDto>>,
    /// Gets or sets the metadata readers.
    #[serde(rename = "MetadataReaders", skip_serializing_if = "Option::is_none")]
    pub metadata_readers: Option<Vec<models::LibraryOptionInfoDto>>,
    /// Gets or sets the subtitle fetchers.
    #[serde(rename = "SubtitleFetchers", skip_serializing_if = "Option::is_none")]
    pub subtitle_fetchers: Option<Vec<models::LibraryOptionInfoDto>>,
    /// Gets or sets the list of lyric fetchers.
    #[serde(rename = "LyricFetchers", skip_serializing_if = "Option::is_none")]
    pub lyric_fetchers: Option<Vec<models::LibraryOptionInfoDto>>,
    /// Gets or sets the type options.
    #[serde(rename = "TypeOptions", skip_serializing_if = "Option::is_none")]
    pub type_options: Option<Vec<models::LibraryTypeOptionsDto>>,
}

impl LibraryOptionsResultDto {
    /// Library options result dto.
    pub fn new() -> LibraryOptionsResultDto {
        LibraryOptionsResultDto {
            metadata_savers: None,
            metadata_readers: None,
            subtitle_fetchers: None,
            lyric_fetchers: None,
            type_options: None,
        }
    }
}

