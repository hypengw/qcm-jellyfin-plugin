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
pub enum PlaybackErrorCode {
    #[serde(rename = "NotAllowed")]
    NotAllowed,
    #[serde(rename = "NoCompatibleStream")]
    NoCompatibleStream,
    #[serde(rename = "RateLimitExceeded")]
    RateLimitExceeded,

}

impl std::fmt::Display for PlaybackErrorCode {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        match self {
            Self::NotAllowed => write!(f, "NotAllowed"),
            Self::NoCompatibleStream => write!(f, "NoCompatibleStream"),
            Self::RateLimitExceeded => write!(f, "RateLimitExceeded"),
        }
    }
}

impl Default for PlaybackErrorCode {
    fn default() -> PlaybackErrorCode {
        Self::NotAllowed
    }
}

