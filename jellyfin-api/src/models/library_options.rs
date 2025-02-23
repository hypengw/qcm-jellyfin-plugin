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

#[derive(Clone, Default, Debug, PartialEq, Serialize, Deserialize)]
pub struct LibraryOptions {
    #[serde(rename = "Enabled", skip_serializing_if = "Option::is_none")]
    pub enabled: Option<bool>,
    #[serde(rename = "EnablePhotos", skip_serializing_if = "Option::is_none")]
    pub enable_photos: Option<bool>,
    #[serde(rename = "EnableRealtimeMonitor", skip_serializing_if = "Option::is_none")]
    pub enable_realtime_monitor: Option<bool>,
    #[serde(rename = "EnableLUFSScan", skip_serializing_if = "Option::is_none")]
    pub enable_lufs_scan: Option<bool>,
    #[serde(rename = "EnableChapterImageExtraction", skip_serializing_if = "Option::is_none")]
    pub enable_chapter_image_extraction: Option<bool>,
    #[serde(rename = "ExtractChapterImagesDuringLibraryScan", skip_serializing_if = "Option::is_none")]
    pub extract_chapter_images_during_library_scan: Option<bool>,
    #[serde(rename = "EnableTrickplayImageExtraction", skip_serializing_if = "Option::is_none")]
    pub enable_trickplay_image_extraction: Option<bool>,
    #[serde(rename = "ExtractTrickplayImagesDuringLibraryScan", skip_serializing_if = "Option::is_none")]
    pub extract_trickplay_images_during_library_scan: Option<bool>,
    #[serde(rename = "PathInfos", skip_serializing_if = "Option::is_none")]
    pub path_infos: Option<Vec<models::MediaPathInfo>>,
    #[serde(rename = "SaveLocalMetadata", skip_serializing_if = "Option::is_none")]
    pub save_local_metadata: Option<bool>,
    #[serde(rename = "EnableInternetProviders", skip_serializing_if = "Option::is_none")]
    pub enable_internet_providers: Option<bool>,
    #[serde(rename = "EnableAutomaticSeriesGrouping", skip_serializing_if = "Option::is_none")]
    pub enable_automatic_series_grouping: Option<bool>,
    #[serde(rename = "EnableEmbeddedTitles", skip_serializing_if = "Option::is_none")]
    pub enable_embedded_titles: Option<bool>,
    #[serde(rename = "EnableEmbeddedExtrasTitles", skip_serializing_if = "Option::is_none")]
    pub enable_embedded_extras_titles: Option<bool>,
    #[serde(rename = "EnableEmbeddedEpisodeInfos", skip_serializing_if = "Option::is_none")]
    pub enable_embedded_episode_infos: Option<bool>,
    #[serde(rename = "AutomaticRefreshIntervalDays", skip_serializing_if = "Option::is_none")]
    pub automatic_refresh_interval_days: Option<i32>,
    /// Gets or sets the preferred metadata language.
    #[serde(rename = "PreferredMetadataLanguage", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub preferred_metadata_language: Option<Option<String>>,
    /// Gets or sets the metadata country code.
    #[serde(rename = "MetadataCountryCode", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub metadata_country_code: Option<Option<String>>,
    #[serde(rename = "SeasonZeroDisplayName", skip_serializing_if = "Option::is_none")]
    pub season_zero_display_name: Option<String>,
    #[serde(rename = "MetadataSavers", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub metadata_savers: Option<Option<Vec<String>>>,
    #[serde(rename = "DisabledLocalMetadataReaders", skip_serializing_if = "Option::is_none")]
    pub disabled_local_metadata_readers: Option<Vec<String>>,
    #[serde(rename = "LocalMetadataReaderOrder", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub local_metadata_reader_order: Option<Option<Vec<String>>>,
    #[serde(rename = "DisabledSubtitleFetchers", skip_serializing_if = "Option::is_none")]
    pub disabled_subtitle_fetchers: Option<Vec<String>>,
    #[serde(rename = "SubtitleFetcherOrder", skip_serializing_if = "Option::is_none")]
    pub subtitle_fetcher_order: Option<Vec<String>>,
    #[serde(rename = "DisabledMediaSegmentProviders", skip_serializing_if = "Option::is_none")]
    pub disabled_media_segment_providers: Option<Vec<String>>,
    #[serde(rename = "MediaSegmentProvideOrder", skip_serializing_if = "Option::is_none")]
    pub media_segment_provide_order: Option<Vec<String>>,
    #[serde(rename = "SkipSubtitlesIfEmbeddedSubtitlesPresent", skip_serializing_if = "Option::is_none")]
    pub skip_subtitles_if_embedded_subtitles_present: Option<bool>,
    #[serde(rename = "SkipSubtitlesIfAudioTrackMatches", skip_serializing_if = "Option::is_none")]
    pub skip_subtitles_if_audio_track_matches: Option<bool>,
    #[serde(rename = "SubtitleDownloadLanguages", default, with = "::serde_with::rust::double_option", skip_serializing_if = "Option::is_none")]
    pub subtitle_download_languages: Option<Option<Vec<String>>>,
    #[serde(rename = "RequirePerfectSubtitleMatch", skip_serializing_if = "Option::is_none")]
    pub require_perfect_subtitle_match: Option<bool>,
    #[serde(rename = "SaveSubtitlesWithMedia", skip_serializing_if = "Option::is_none")]
    pub save_subtitles_with_media: Option<bool>,
    #[serde(rename = "SaveLyricsWithMedia", skip_serializing_if = "Option::is_none")]
    pub save_lyrics_with_media: Option<bool>,
    #[serde(rename = "SaveTrickplayWithMedia", skip_serializing_if = "Option::is_none")]
    pub save_trickplay_with_media: Option<bool>,
    #[serde(rename = "DisabledLyricFetchers", skip_serializing_if = "Option::is_none")]
    pub disabled_lyric_fetchers: Option<Vec<String>>,
    #[serde(rename = "LyricFetcherOrder", skip_serializing_if = "Option::is_none")]
    pub lyric_fetcher_order: Option<Vec<String>>,
    #[serde(rename = "PreferNonstandardArtistsTag", skip_serializing_if = "Option::is_none")]
    pub prefer_nonstandard_artists_tag: Option<bool>,
    #[serde(rename = "UseCustomTagDelimiters", skip_serializing_if = "Option::is_none")]
    pub use_custom_tag_delimiters: Option<bool>,
    #[serde(rename = "CustomTagDelimiters", skip_serializing_if = "Option::is_none")]
    pub custom_tag_delimiters: Option<Vec<String>>,
    #[serde(rename = "DelimiterWhitelist", skip_serializing_if = "Option::is_none")]
    pub delimiter_whitelist: Option<Vec<String>>,
    #[serde(rename = "AutomaticallyAddToCollection", skip_serializing_if = "Option::is_none")]
    pub automatically_add_to_collection: Option<bool>,
    /// An enum representing the options to disable embedded subs.
    #[serde(rename = "AllowEmbeddedSubtitles", skip_serializing_if = "Option::is_none")]
    pub allow_embedded_subtitles: Option<models::EmbeddedSubtitleOptions>,
    #[serde(rename = "TypeOptions", skip_serializing_if = "Option::is_none")]
    pub type_options: Option<Vec<models::TypeOptions>>,
}

impl LibraryOptions {
    pub fn new() -> LibraryOptions {
        LibraryOptions {
            enabled: None,
            enable_photos: None,
            enable_realtime_monitor: None,
            enable_lufs_scan: None,
            enable_chapter_image_extraction: None,
            extract_chapter_images_during_library_scan: None,
            enable_trickplay_image_extraction: None,
            extract_trickplay_images_during_library_scan: None,
            path_infos: None,
            save_local_metadata: None,
            enable_internet_providers: None,
            enable_automatic_series_grouping: None,
            enable_embedded_titles: None,
            enable_embedded_extras_titles: None,
            enable_embedded_episode_infos: None,
            automatic_refresh_interval_days: None,
            preferred_metadata_language: None,
            metadata_country_code: None,
            season_zero_display_name: None,
            metadata_savers: None,
            disabled_local_metadata_readers: None,
            local_metadata_reader_order: None,
            disabled_subtitle_fetchers: None,
            subtitle_fetcher_order: None,
            disabled_media_segment_providers: None,
            media_segment_provide_order: None,
            skip_subtitles_if_embedded_subtitles_present: None,
            skip_subtitles_if_audio_track_matches: None,
            subtitle_download_languages: None,
            require_perfect_subtitle_match: None,
            save_subtitles_with_media: None,
            save_lyrics_with_media: None,
            save_trickplay_with_media: None,
            disabled_lyric_fetchers: None,
            lyric_fetcher_order: None,
            prefer_nonstandard_artists_tag: None,
            use_custom_tag_delimiters: None,
            custom_tag_delimiters: None,
            delimiter_whitelist: None,
            automatically_add_to_collection: None,
            allow_embedded_subtitles: None,
            type_options: None,
        }
    }
}

