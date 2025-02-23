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

/// 
#[derive(Clone, Copy, Debug, Eq, PartialEq, Ord, PartialOrd, Hash, Serialize, Deserialize)]
pub enum RecordingStatus {
    #[serde(rename = "New")]
    New,
    #[serde(rename = "InProgress")]
    InProgress,
    #[serde(rename = "Completed")]
    Completed,
    #[serde(rename = "Cancelled")]
    Cancelled,
    #[serde(rename = "ConflictedOk")]
    ConflictedOk,
    #[serde(rename = "ConflictedNotOk")]
    ConflictedNotOk,
    #[serde(rename = "Error")]
    Error,

}

impl std::fmt::Display for RecordingStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        match self {
            Self::New => write!(f, "New"),
            Self::InProgress => write!(f, "InProgress"),
            Self::Completed => write!(f, "Completed"),
            Self::Cancelled => write!(f, "Cancelled"),
            Self::ConflictedOk => write!(f, "ConflictedOk"),
            Self::ConflictedNotOk => write!(f, "ConflictedNotOk"),
            Self::Error => write!(f, "Error"),
        }
    }
}

impl Default for RecordingStatus {
    fn default() -> RecordingStatus {
        Self::New
    }
}

