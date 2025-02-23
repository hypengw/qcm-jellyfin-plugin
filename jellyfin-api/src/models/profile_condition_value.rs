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
pub enum ProfileConditionValue {
    #[serde(rename = "AudioChannels")]
    AudioChannels,
    #[serde(rename = "AudioBitrate")]
    AudioBitrate,
    #[serde(rename = "AudioProfile")]
    AudioProfile,
    #[serde(rename = "Width")]
    Width,
    #[serde(rename = "Height")]
    Height,
    #[serde(rename = "Has64BitOffsets")]
    Has64BitOffsets,
    #[serde(rename = "PacketLength")]
    PacketLength,
    #[serde(rename = "VideoBitDepth")]
    VideoBitDepth,
    #[serde(rename = "VideoBitrate")]
    VideoBitrate,
    #[serde(rename = "VideoFramerate")]
    VideoFramerate,
    #[serde(rename = "VideoLevel")]
    VideoLevel,
    #[serde(rename = "VideoProfile")]
    VideoProfile,
    #[serde(rename = "VideoTimestamp")]
    VideoTimestamp,
    #[serde(rename = "IsAnamorphic")]
    IsAnamorphic,
    #[serde(rename = "RefFrames")]
    RefFrames,
    #[serde(rename = "NumAudioStreams")]
    NumAudioStreams,
    #[serde(rename = "NumVideoStreams")]
    NumVideoStreams,
    #[serde(rename = "IsSecondaryAudio")]
    IsSecondaryAudio,
    #[serde(rename = "VideoCodecTag")]
    VideoCodecTag,
    #[serde(rename = "IsAvc")]
    IsAvc,
    #[serde(rename = "IsInterlaced")]
    IsInterlaced,
    #[serde(rename = "AudioSampleRate")]
    AudioSampleRate,
    #[serde(rename = "AudioBitDepth")]
    AudioBitDepth,
    #[serde(rename = "VideoRangeType")]
    VideoRangeType,

}

impl std::fmt::Display for ProfileConditionValue {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        match self {
            Self::AudioChannels => write!(f, "AudioChannels"),
            Self::AudioBitrate => write!(f, "AudioBitrate"),
            Self::AudioProfile => write!(f, "AudioProfile"),
            Self::Width => write!(f, "Width"),
            Self::Height => write!(f, "Height"),
            Self::Has64BitOffsets => write!(f, "Has64BitOffsets"),
            Self::PacketLength => write!(f, "PacketLength"),
            Self::VideoBitDepth => write!(f, "VideoBitDepth"),
            Self::VideoBitrate => write!(f, "VideoBitrate"),
            Self::VideoFramerate => write!(f, "VideoFramerate"),
            Self::VideoLevel => write!(f, "VideoLevel"),
            Self::VideoProfile => write!(f, "VideoProfile"),
            Self::VideoTimestamp => write!(f, "VideoTimestamp"),
            Self::IsAnamorphic => write!(f, "IsAnamorphic"),
            Self::RefFrames => write!(f, "RefFrames"),
            Self::NumAudioStreams => write!(f, "NumAudioStreams"),
            Self::NumVideoStreams => write!(f, "NumVideoStreams"),
            Self::IsSecondaryAudio => write!(f, "IsSecondaryAudio"),
            Self::VideoCodecTag => write!(f, "VideoCodecTag"),
            Self::IsAvc => write!(f, "IsAvc"),
            Self::IsInterlaced => write!(f, "IsInterlaced"),
            Self::AudioSampleRate => write!(f, "AudioSampleRate"),
            Self::AudioBitDepth => write!(f, "AudioBitDepth"),
            Self::VideoRangeType => write!(f, "VideoRangeType"),
        }
    }
}

impl Default for ProfileConditionValue {
    fn default() -> ProfileConditionValue {
        Self::AudioChannels
    }
}

