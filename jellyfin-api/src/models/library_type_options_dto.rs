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

/// LibraryTypeOptionsDto : Library type options dto.
#[derive(Clone, Default, Debug, PartialEq, Serialize, Deserialize)]
pub struct LibraryTypeOptionsDto {
    /// Gets or sets the type.
    #[serde(rename = "Type", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub r#type: Option<Option<String>>,
    /// Gets or sets the metadata fetchers.
    #[serde(rename = "MetadataFetchers", skip_serializing_if = "Option::is_none")]
    pub metadata_fetchers: Option<Vec<models::LibraryOptionInfoDto>>,
    /// Gets or sets the image fetchers.
    #[serde(rename = "ImageFetchers", skip_serializing_if = "Option::is_none")]
    pub image_fetchers: Option<Vec<models::LibraryOptionInfoDto>>,
    /// Gets or sets the supported image types.
    #[serde(rename = "SupportedImageTypes", skip_serializing_if = "Option::is_none")]
    pub supported_image_types: Option<Vec<models::ImageType>>,
    /// Gets or sets the default image options.
    #[serde(rename = "DefaultImageOptions", skip_serializing_if = "Option::is_none")]
    pub default_image_options: Option<Vec<models::ImageOption>>,
}

impl LibraryTypeOptionsDto {
    /// Library type options dto.
    pub fn new() -> LibraryTypeOptionsDto {
        LibraryTypeOptionsDto {
            r#type: None,
            metadata_fetchers: None,
            image_fetchers: None,
            supported_image_types: None,
            default_image_options: None,
        }
    }
}

