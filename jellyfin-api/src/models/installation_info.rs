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

/// InstallationInfo : Class InstallationInfo.
#[derive(Clone, Default, Debug, PartialEq, Serialize, Deserialize)]
pub struct InstallationInfo {
    /// Gets or sets the Id.
    #[serde(rename = "Guid", skip_serializing_if = "Option::is_none")]
    pub guid: Option<uuid::Uuid>,
    /// Gets or sets the name.
    #[serde(rename = "Name", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub name: Option<Option<String>>,
    /// Gets or sets the version.
    #[serde(rename = "Version", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub version: Option<Option<String>>,
    /// Gets or sets the changelog for this version.
    #[serde(rename = "Changelog", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub changelog: Option<Option<String>>,
    /// Gets or sets the source URL.
    #[serde(rename = "SourceUrl", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub source_url: Option<Option<String>>,
    /// Gets or sets a checksum for the binary.
    #[serde(rename = "Checksum", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub checksum: Option<Option<String>>,
    /// Gets or sets package information for the installation.
    #[serde(rename = "PackageInfo", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub package_info: Option<Option<Box<models::PackageInfo>>>,
}

impl InstallationInfo {
    /// Class InstallationInfo.
    pub fn new() -> InstallationInfo {
        InstallationInfo {
            guid: None,
            name: None,
            version: None,
            changelog: None,
            source_url: None,
            checksum: None,
            package_info: None,
        }
    }
}

