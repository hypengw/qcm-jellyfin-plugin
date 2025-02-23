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

/// GeneralCommandType : This exists simply to identify a set of known commands.
/// This exists simply to identify a set of known commands.
#[derive(Clone, Copy, Debug, Eq, PartialEq, Ord, PartialOrd, Hash, Serialize, Deserialize)]
pub enum GeneralCommandType {
    #[serde(rename = "MoveUp")]
    MoveUp,
    #[serde(rename = "MoveDown")]
    MoveDown,
    #[serde(rename = "MoveLeft")]
    MoveLeft,
    #[serde(rename = "MoveRight")]
    MoveRight,
    #[serde(rename = "PageUp")]
    PageUp,
    #[serde(rename = "PageDown")]
    PageDown,
    #[serde(rename = "PreviousLetter")]
    PreviousLetter,
    #[serde(rename = "NextLetter")]
    NextLetter,
    #[serde(rename = "ToggleOsd")]
    ToggleOsd,
    #[serde(rename = "ToggleContextMenu")]
    ToggleContextMenu,
    #[serde(rename = "Select")]
    Select,
    #[serde(rename = "Back")]
    Back,
    #[serde(rename = "TakeScreenshot")]
    TakeScreenshot,
    #[serde(rename = "SendKey")]
    SendKey,
    #[serde(rename = "SendString")]
    SendString,
    #[serde(rename = "GoHome")]
    GoHome,
    #[serde(rename = "GoToSettings")]
    GoToSettings,
    #[serde(rename = "VolumeUp")]
    VolumeUp,
    #[serde(rename = "VolumeDown")]
    VolumeDown,
    #[serde(rename = "Mute")]
    Mute,
    #[serde(rename = "Unmute")]
    Unmute,
    #[serde(rename = "ToggleMute")]
    ToggleMute,
    #[serde(rename = "SetVolume")]
    SetVolume,
    #[serde(rename = "SetAudioStreamIndex")]
    SetAudioStreamIndex,
    #[serde(rename = "SetSubtitleStreamIndex")]
    SetSubtitleStreamIndex,
    #[serde(rename = "ToggleFullscreen")]
    ToggleFullscreen,
    #[serde(rename = "DisplayContent")]
    DisplayContent,
    #[serde(rename = "GoToSearch")]
    GoToSearch,
    #[serde(rename = "DisplayMessage")]
    DisplayMessage,
    #[serde(rename = "SetRepeatMode")]
    SetRepeatMode,
    #[serde(rename = "ChannelUp")]
    ChannelUp,
    #[serde(rename = "ChannelDown")]
    ChannelDown,
    #[serde(rename = "Guide")]
    Guide,
    #[serde(rename = "ToggleStats")]
    ToggleStats,
    #[serde(rename = "PlayMediaSource")]
    PlayMediaSource,
    #[serde(rename = "PlayTrailers")]
    PlayTrailers,
    #[serde(rename = "SetShuffleQueue")]
    SetShuffleQueue,
    #[serde(rename = "PlayState")]
    PlayState,
    #[serde(rename = "PlayNext")]
    PlayNext,
    #[serde(rename = "ToggleOsdMenu")]
    ToggleOsdMenu,
    #[serde(rename = "Play")]
    Play,
    #[serde(rename = "SetMaxStreamingBitrate")]
    SetMaxStreamingBitrate,
    #[serde(rename = "SetPlaybackOrder")]
    SetPlaybackOrder,

}

impl std::fmt::Display for GeneralCommandType {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        match self {
            Self::MoveUp => write!(f, "MoveUp"),
            Self::MoveDown => write!(f, "MoveDown"),
            Self::MoveLeft => write!(f, "MoveLeft"),
            Self::MoveRight => write!(f, "MoveRight"),
            Self::PageUp => write!(f, "PageUp"),
            Self::PageDown => write!(f, "PageDown"),
            Self::PreviousLetter => write!(f, "PreviousLetter"),
            Self::NextLetter => write!(f, "NextLetter"),
            Self::ToggleOsd => write!(f, "ToggleOsd"),
            Self::ToggleContextMenu => write!(f, "ToggleContextMenu"),
            Self::Select => write!(f, "Select"),
            Self::Back => write!(f, "Back"),
            Self::TakeScreenshot => write!(f, "TakeScreenshot"),
            Self::SendKey => write!(f, "SendKey"),
            Self::SendString => write!(f, "SendString"),
            Self::GoHome => write!(f, "GoHome"),
            Self::GoToSettings => write!(f, "GoToSettings"),
            Self::VolumeUp => write!(f, "VolumeUp"),
            Self::VolumeDown => write!(f, "VolumeDown"),
            Self::Mute => write!(f, "Mute"),
            Self::Unmute => write!(f, "Unmute"),
            Self::ToggleMute => write!(f, "ToggleMute"),
            Self::SetVolume => write!(f, "SetVolume"),
            Self::SetAudioStreamIndex => write!(f, "SetAudioStreamIndex"),
            Self::SetSubtitleStreamIndex => write!(f, "SetSubtitleStreamIndex"),
            Self::ToggleFullscreen => write!(f, "ToggleFullscreen"),
            Self::DisplayContent => write!(f, "DisplayContent"),
            Self::GoToSearch => write!(f, "GoToSearch"),
            Self::DisplayMessage => write!(f, "DisplayMessage"),
            Self::SetRepeatMode => write!(f, "SetRepeatMode"),
            Self::ChannelUp => write!(f, "ChannelUp"),
            Self::ChannelDown => write!(f, "ChannelDown"),
            Self::Guide => write!(f, "Guide"),
            Self::ToggleStats => write!(f, "ToggleStats"),
            Self::PlayMediaSource => write!(f, "PlayMediaSource"),
            Self::PlayTrailers => write!(f, "PlayTrailers"),
            Self::SetShuffleQueue => write!(f, "SetShuffleQueue"),
            Self::PlayState => write!(f, "PlayState"),
            Self::PlayNext => write!(f, "PlayNext"),
            Self::ToggleOsdMenu => write!(f, "ToggleOsdMenu"),
            Self::Play => write!(f, "Play"),
            Self::SetMaxStreamingBitrate => write!(f, "SetMaxStreamingBitrate"),
            Self::SetPlaybackOrder => write!(f, "SetPlaybackOrder"),
        }
    }
}

impl Default for GeneralCommandType {
    fn default() -> GeneralCommandType {
        Self::MoveUp
    }
}

