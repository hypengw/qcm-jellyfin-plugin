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

/// VideoRange : An enum representing video ranges.
/// An enum representing video ranges.
#[derive(Clone, Copy, Debug, Eq, PartialEq, Ord, PartialOrd, Hash, Serialize, Deserialize)]
pub enum VideoRange {
    #[serde(rename = "Unknown")]
    Unknown,
    #[serde(rename = "SDR")]
    Sdr,
    #[serde(rename = "HDR")]
    Hdr,

}

impl std::fmt::Display for VideoRange {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        match self {
            Self::Unknown => write!(f, "Unknown"),
            Self::Sdr => write!(f, "SDR"),
            Self::Hdr => write!(f, "HDR"),
        }
    }
}

impl Default for VideoRange {
    fn default() -> VideoRange {
        Self::Unknown
    }
}

