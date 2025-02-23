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

/// PlayQueueUpdateReason : Enum PlayQueueUpdateReason.
/// Enum PlayQueueUpdateReason.
#[derive(Clone, Copy, Debug, Eq, PartialEq, Ord, PartialOrd, Hash, Serialize, Deserialize)]
pub enum PlayQueueUpdateReason {
    #[serde(rename = "NewPlaylist")]
    NewPlaylist,
    #[serde(rename = "SetCurrentItem")]
    SetCurrentItem,
    #[serde(rename = "RemoveItems")]
    RemoveItems,
    #[serde(rename = "MoveItem")]
    MoveItem,
    #[serde(rename = "Queue")]
    Queue,
    #[serde(rename = "QueueNext")]
    QueueNext,
    #[serde(rename = "NextItem")]
    NextItem,
    #[serde(rename = "PreviousItem")]
    PreviousItem,
    #[serde(rename = "RepeatMode")]
    RepeatMode,
    #[serde(rename = "ShuffleMode")]
    ShuffleMode,

}

impl std::fmt::Display for PlayQueueUpdateReason {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        match self {
            Self::NewPlaylist => write!(f, "NewPlaylist"),
            Self::SetCurrentItem => write!(f, "SetCurrentItem"),
            Self::RemoveItems => write!(f, "RemoveItems"),
            Self::MoveItem => write!(f, "MoveItem"),
            Self::Queue => write!(f, "Queue"),
            Self::QueueNext => write!(f, "QueueNext"),
            Self::NextItem => write!(f, "NextItem"),
            Self::PreviousItem => write!(f, "PreviousItem"),
            Self::RepeatMode => write!(f, "RepeatMode"),
            Self::ShuffleMode => write!(f, "ShuffleMode"),
        }
    }
}

impl Default for PlayQueueUpdateReason {
    fn default() -> PlayQueueUpdateReason {
        Self::NewPlaylist
    }
}

