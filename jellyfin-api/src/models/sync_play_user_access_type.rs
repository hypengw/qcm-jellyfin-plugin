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

/// SyncPlayUserAccessType : Enum SyncPlayUserAccessType.
/// Enum SyncPlayUserAccessType.
#[derive(Clone, Copy, Debug, Eq, PartialEq, Ord, PartialOrd, Hash, Serialize, Deserialize)]
pub enum SyncPlayUserAccessType {
    #[serde(rename = "CreateAndJoinGroups")]
    CreateAndJoinGroups,
    #[serde(rename = "JoinGroups")]
    JoinGroups,
    #[serde(rename = "None")]
    None,

}

impl std::fmt::Display for SyncPlayUserAccessType {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        match self {
            Self::CreateAndJoinGroups => write!(f, "CreateAndJoinGroups"),
            Self::JoinGroups => write!(f, "JoinGroups"),
            Self::None => write!(f, "None"),
        }
    }
}

impl Default for SyncPlayUserAccessType {
    fn default() -> SyncPlayUserAccessType {
        Self::CreateAndJoinGroups
    }
}

