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
pub struct MetadataConfiguration {
    #[serde(rename = "UseFileCreationTimeForDateAdded", skip_serializing_if = "Option::is_none")]
    pub use_file_creation_time_for_date_added: Option<bool>,
}

impl MetadataConfiguration {
    pub fn new() -> MetadataConfiguration {
        MetadataConfiguration {
            use_file_creation_time_for_date_added: None,
        }
    }
}

