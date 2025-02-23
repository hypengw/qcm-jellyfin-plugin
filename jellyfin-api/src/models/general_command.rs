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
pub struct GeneralCommand {
    /// This exists simply to identify a set of known commands.
    #[serde(rename = "Name", skip_serializing_if = "Option::is_none")]
    pub name: Option<models::GeneralCommandType>,
    #[serde(rename = "ControllingUserId", skip_serializing_if = "Option::is_none")]
    pub controlling_user_id: Option<uuid::Uuid>,
    #[serde(rename = "Arguments", skip_serializing_if = "Option::is_none")]
    pub arguments: Option<std::collections::HashMap<String, String>>,
}

impl GeneralCommand {
    pub fn new() -> GeneralCommand {
        GeneralCommand {
            name: None,
            controlling_user_id: None,
            arguments: None,
        }
    }
}

