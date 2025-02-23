use std::error;
use std::fmt;

#[derive(Debug, Clone)]
pub struct ResponseContent<T> {
    pub status: reqwest::StatusCode,
    pub content: String,
    pub entity: Option<T>,
}

#[derive(Debug)]
pub enum Error<T> {
    Reqwest(reqwest::Error),
    Serde(serde_json::Error),
    Io(std::io::Error),
    ResponseError(ResponseContent<T>),
}

impl <T> fmt::Display for Error<T> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let (module, e) = match self {
            Error::Reqwest(e) => ("reqwest", e.to_string()),
            Error::Serde(e) => ("serde", e.to_string()),
            Error::Io(e) => ("IO", e.to_string()),
            Error::ResponseError(e) => ("response", format!("status code {}", e.status)),
        };
        write!(f, "error in {}: {}", module, e)
    }
}

impl <T: fmt::Debug> error::Error for Error<T> {
    fn source(&self) -> Option<&(dyn error::Error + 'static)> {
        Some(match self {
            Error::Reqwest(e) => e,
            Error::Serde(e) => e,
            Error::Io(e) => e,
            Error::ResponseError(_) => return None,
        })
    }
}

impl <T> From<reqwest::Error> for Error<T> {
    fn from(e: reqwest::Error) -> Self {
        Error::Reqwest(e)
    }
}

impl <T> From<serde_json::Error> for Error<T> {
    fn from(e: serde_json::Error) -> Self {
        Error::Serde(e)
    }
}

impl <T> From<std::io::Error> for Error<T> {
    fn from(e: std::io::Error) -> Self {
        Error::Io(e)
    }
}

pub fn urlencode<T: AsRef<str>>(s: T) -> String {
    ::url::form_urlencoded::byte_serialize(s.as_ref().as_bytes()).collect()
}

pub fn parse_deep_object(prefix: &str, value: &serde_json::Value) -> Vec<(String, String)> {
    if let serde_json::Value::Object(object) = value {
        let mut params = vec![];

        for (key, value) in object {
            match value {
                serde_json::Value::Object(_) => params.append(&mut parse_deep_object(
                    &format!("{}[{}]", prefix, key),
                    value,
                )),
                serde_json::Value::Array(array) => {
                    for (i, value) in array.iter().enumerate() {
                        params.append(&mut parse_deep_object(
                            &format!("{}[{}][{}]", prefix, key, i),
                            value,
                        ));
                    }
                },
                serde_json::Value::String(s) => params.push((format!("{}[{}]", prefix, key), s.clone())),
                _ => params.push((format!("{}[{}]", prefix, key), value.to_string())),
            }
        }

        return params;
    }

    unimplemented!("Only objects are supported with style=deepObject")
}

pub mod activity_log_api;
pub mod api_key_api;
pub mod artists_api;
pub mod audio_api;
pub mod branding_api;
pub mod channels_api;
pub mod client_log_api;
pub mod collection_api;
pub mod configuration_api;
pub mod dashboard_api;
pub mod devices_api;
pub mod display_preferences_api;
pub mod environment_api;
pub mod filter_api;
pub mod genres_api;
pub mod hls_segment_api;
pub mod image_api;
pub mod instant_mix_api;
pub mod item_lookup_api;
pub mod item_refresh_api;
pub mod item_update_api;
pub mod items_api;
pub mod library_api;
pub mod library_structure_api;
pub mod live_tv_api;
pub mod localization_api;
pub mod lyrics_api;
pub mod media_info_api;
pub mod movies_api;
pub mod music_genres_api;
pub mod package_api;
pub mod persons_api;
pub mod playlists_api;
pub mod playstate_api;
pub mod plugins_api;
pub mod quick_connect_api;
pub mod remote_image_api;
pub mod scheduled_tasks_api;
pub mod search_api;
pub mod session_api;
pub mod startup_api;
pub mod studios_api;
pub mod subtitle_api;
pub mod suggestions_api;
pub mod sync_play_api;
pub mod system_api;
pub mod time_sync_api;
pub mod tmdb_api;
pub mod trailers_api;
pub mod trickplay_api;
pub mod tv_shows_api;
pub mod universal_audio_api;
pub mod user_api;
pub mod user_library_api;
pub mod user_views_api;
pub mod video_attachments_api;
pub mod years_api;

pub mod configuration;
