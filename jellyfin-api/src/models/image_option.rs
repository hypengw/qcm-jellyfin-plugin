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
pub struct ImageOption {
    /// Gets or sets the type.
    #[serde(rename = "Type", skip_serializing_if = "Option::is_none")]
    pub r#type: Option<models::ImageType>,
    /// Gets or sets the limit.
    #[serde(rename = "Limit", skip_serializing_if = "Option::is_none")]
    pub limit: Option<i32>,
    /// Gets or sets the minimum width.
    #[serde(rename = "MinWidth", skip_serializing_if = "Option::is_none")]
    pub min_width: Option<i32>,
}

impl ImageOption {
    pub fn new() -> ImageOption {
        ImageOption {
            r#type: None,
            limit: None,
            min_width: None,
        }
    }
}

