use jellyfin_api::apis::Error as JError;
use qcm_core::anyhow;
use qcm_core::error::ProviderError;
use reqwest::StatusCode;

pub trait FromJellyfinError<F> {
    fn from_err(err: F) -> ProviderError;
}

impl<T> FromJellyfinError<JError<T>> for ProviderError {
    fn from_err(err: JError<T>) -> ProviderError {
        match err {
            JError::Io(e) => e.into(),
            JError::Reqwest(e) => e.into(),
            JError::Serde(e) => e.into(),
            JError::ResponseError(e) => match e.status {
                StatusCode::UNAUTHORIZED => ProviderError::NotAuth,
                _ => anyhow!("{}: {}", e.status, e.content).into(),
            },
        }
    }
}
