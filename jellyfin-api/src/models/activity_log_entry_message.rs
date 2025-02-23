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

/// ActivityLogEntryMessage : Activity log created message.
#[derive(Clone, Default, Debug, PartialEq, Serialize, Deserialize)]
pub struct ActivityLogEntryMessage {
    /// Gets or sets the data.
    #[serde(rename = "Data", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub data: Option<Option<Vec<models::ActivityLogEntry>>>,
    /// Gets or sets the message id.
    #[serde(rename = "MessageId", skip_serializing_if = "Option::is_none")]
    pub message_id: Option<uuid::Uuid>,
    /// The different kinds of messages that are used in the WebSocket api.
    #[serde(rename = "MessageType", skip_serializing_if = "Option::is_none")]
    pub message_type: Option<models::SessionMessageType>,
}

impl ActivityLogEntryMessage {
    /// Activity log created message.
    pub fn new() -> ActivityLogEntryMessage {
        ActivityLogEntryMessage {
            data: None,
            message_id: None,
            message_type: None,
        }
    }
}

