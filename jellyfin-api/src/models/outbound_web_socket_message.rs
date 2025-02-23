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

/// OutboundWebSocketMessage : Represents the list of possible outbound websocket types
#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
#[serde(tag = "MessageType")]
pub enum OutboundWebSocketMessage {
    #[serde(rename="ActivityLogEntry")]
    ActivityLogEntry(Box<models::ActivityLogEntryMessage>),
    #[serde(rename="ForceKeepAlive")]
    ForceKeepAlive(Box<models::ForceKeepAliveMessage>),
    #[serde(rename="GeneralCommand")]
    GeneralCommand(Box<models::GeneralCommandMessage>),
    #[serde(rename="LibraryChanged")]
    LibraryChanged(Box<models::LibraryChangedMessage>),
    #[serde(rename="KeepAlive")]
    KeepAlive(Box<models::OutboundKeepAliveMessage>),
    #[serde(rename="Play")]
    Play(Box<models::PlayMessage>),
    #[serde(rename="Playstate")]
    Playstate(Box<models::PlaystateMessage>),
    #[serde(rename="PackageInstallationCancelled")]
    PackageInstallationCancelled(Box<models::PluginInstallationCancelledMessage>),
    #[serde(rename="PackageInstallationCompleted")]
    PackageInstallationCompleted(Box<models::PluginInstallationCompletedMessage>),
    #[serde(rename="PackageInstallationFailed")]
    PackageInstallationFailed(Box<models::PluginInstallationFailedMessage>),
    #[serde(rename="PackageInstalling")]
    PackageInstalling(Box<models::PluginInstallingMessage>),
    #[serde(rename="PackageUninstalled")]
    PackageUninstalled(Box<models::PluginUninstalledMessage>),
    #[serde(rename="RefreshProgress")]
    RefreshProgress(Box<models::RefreshProgressMessage>),
    #[serde(rename="RestartRequired")]
    RestartRequired(Box<models::RestartRequiredMessage>),
    #[serde(rename="ScheduledTaskEnded")]
    ScheduledTaskEnded(Box<models::ScheduledTaskEndedMessage>),
    #[serde(rename="ScheduledTasksInfo")]
    ScheduledTasksInfo(Box<models::ScheduledTasksInfoMessage>),
    #[serde(rename="SeriesTimerCancelled")]
    SeriesTimerCancelled(Box<models::SeriesTimerCancelledMessage>),
    #[serde(rename="SeriesTimerCreated")]
    SeriesTimerCreated(Box<models::SeriesTimerCreatedMessage>),
    #[serde(rename="ServerRestarting")]
    ServerRestarting(Box<models::ServerRestartingMessage>),
    #[serde(rename="ServerShuttingDown")]
    ServerShuttingDown(Box<models::ServerShuttingDownMessage>),
    #[serde(rename="Sessions")]
    Sessions(Box<models::SessionsMessage>),
    #[serde(rename="SyncPlayCommand")]
    SyncPlayCommand(Box<models::SyncPlayCommandMessage>),
    #[serde(rename="SyncPlayGroupUpdate")]
    SyncPlayGroupUpdate(Box<models::SyncPlayGroupUpdateCommandMessage>),
    #[serde(rename="TimerCancelled")]
    TimerCancelled(Box<models::TimerCancelledMessage>),
    #[serde(rename="TimerCreated")]
    TimerCreated(Box<models::TimerCreatedMessage>),
    #[serde(rename="UserDataChanged")]
    UserDataChanged(Box<models::UserDataChangedMessage>),
    #[serde(rename="UserDeleted")]
    UserDeleted(Box<models::UserDeletedMessage>),
    #[serde(rename="UserUpdated")]
    UserUpdated(Box<models::UserUpdatedMessage>),
}

impl Default for OutboundWebSocketMessage {
    fn default() -> Self {
        Self::ActivityLogEntry(Default::default())
    }
}


