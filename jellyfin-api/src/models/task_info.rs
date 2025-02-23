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

/// TaskInfo : Class TaskInfo.
#[derive(Clone, Default, Debug, PartialEq, Serialize, Deserialize)]
pub struct TaskInfo {
    /// Gets or sets the name.
    #[serde(rename = "Name", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub name: Option<Option<String>>,
    /// Gets or sets the state of the task.
    #[serde(rename = "State", skip_serializing_if = "Option::is_none")]
    pub state: Option<models::TaskState>,
    /// Gets or sets the progress.
    #[serde(rename = "CurrentProgressPercentage", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub current_progress_percentage: Option<Option<f64>>,
    /// Gets or sets the id.
    #[serde(rename = "Id", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub id: Option<Option<String>>,
    /// Gets or sets the last execution result.
    #[serde(rename = "LastExecutionResult", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub last_execution_result: Option<Option<Box<models::TaskResult>>>,
    /// Gets or sets the triggers.
    #[serde(rename = "Triggers", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub triggers: Option<Option<Vec<models::TaskTriggerInfo>>>,
    /// Gets or sets the description.
    #[serde(rename = "Description", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub description: Option<Option<String>>,
    /// Gets or sets the category.
    #[serde(rename = "Category", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub category: Option<Option<String>>,
    /// Gets or sets a value indicating whether this instance is hidden.
    #[serde(rename = "IsHidden", skip_serializing_if = "Option::is_none")]
    pub is_hidden: Option<bool>,
    /// Gets or sets the key.
    #[serde(rename = "Key", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub key: Option<Option<String>>,
}

impl TaskInfo {
    /// Class TaskInfo.
    pub fn new() -> TaskInfo {
        TaskInfo {
            name: None,
            state: None,
            current_progress_percentage: None,
            id: None,
            last_execution_result: None,
            triggers: None,
            description: None,
            category: None,
            is_hidden: None,
            key: None,
        }
    }
}

