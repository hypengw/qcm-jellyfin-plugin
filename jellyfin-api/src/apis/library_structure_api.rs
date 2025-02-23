/*
 * Jellyfin API
 *
 * No description provided (generated by Openapi Generator https://github.com/openapitools/openapi-generator)
 *
 * The version of the OpenAPI document: 10.10.6
 * 
 * Generated by: https://openapi-generator.tech
 */


use reqwest;
use serde::{Deserialize, Serialize};
use crate::{apis::ResponseContent, models};
use super::{Error, configuration};

/// struct for passing parameters to the method [`add_media_path`]
#[derive(Clone, Debug)]
pub struct AddMediaPathParams {
    /// The media path dto.
    pub media_path_dto: models::MediaPathDto,
    /// Whether to refresh the library.
    pub refresh_library: Option<bool>
}

/// struct for passing parameters to the method [`add_virtual_folder`]
#[derive(Clone, Debug)]
pub struct AddVirtualFolderParams {
    /// The name of the virtual folder.
    pub name: Option<String>,
    /// The type of the collection.
    pub collection_type: Option<String>,
    /// The paths of the virtual folder.
    pub paths: Option<Vec<String>>,
    /// Whether to refresh the library.
    pub refresh_library: Option<bool>,
    /// The library options.
    pub add_virtual_folder_dto: Option<models::AddVirtualFolderDto>
}

/// struct for passing parameters to the method [`remove_media_path`]
#[derive(Clone, Debug)]
pub struct RemoveMediaPathParams {
    /// The name of the library.
    pub name: Option<String>,
    /// The path to remove.
    pub path: Option<String>,
    /// Whether to refresh the library.
    pub refresh_library: Option<bool>
}

/// struct for passing parameters to the method [`remove_virtual_folder`]
#[derive(Clone, Debug)]
pub struct RemoveVirtualFolderParams {
    /// The name of the folder.
    pub name: Option<String>,
    /// Whether to refresh the library.
    pub refresh_library: Option<bool>
}

/// struct for passing parameters to the method [`rename_virtual_folder`]
#[derive(Clone, Debug)]
pub struct RenameVirtualFolderParams {
    /// The name of the virtual folder.
    pub name: Option<String>,
    /// The new name.
    pub new_name: Option<String>,
    /// Whether to refresh the library.
    pub refresh_library: Option<bool>
}

/// struct for passing parameters to the method [`update_library_options`]
#[derive(Clone, Debug)]
pub struct UpdateLibraryOptionsParams {
    /// The library name and options.
    pub update_library_options_dto: Option<models::UpdateLibraryOptionsDto>
}

/// struct for passing parameters to the method [`update_media_path`]
#[derive(Clone, Debug)]
pub struct UpdateMediaPathParams {
    /// The name of the library and path infos.
    pub update_media_path_request_dto: models::UpdateMediaPathRequestDto
}


/// struct for typed successes of method [`add_media_path`]
#[derive(Debug, Clone, Serialize, Deserialize)]
#[serde(untagged)]
pub enum AddMediaPathSuccess {
    Status204(),
    UnknownValue(serde_json::Value),
}

/// struct for typed successes of method [`add_virtual_folder`]
#[derive(Debug, Clone, Serialize, Deserialize)]
#[serde(untagged)]
pub enum AddVirtualFolderSuccess {
    Status204(),
    UnknownValue(serde_json::Value),
}

/// struct for typed successes of method [`get_virtual_folders`]
#[derive(Debug, Clone, Serialize, Deserialize)]
#[serde(untagged)]
pub enum GetVirtualFoldersSuccess {
    Status200(Vec<models::VirtualFolderInfo>),
    UnknownValue(serde_json::Value),
}

/// struct for typed successes of method [`remove_media_path`]
#[derive(Debug, Clone, Serialize, Deserialize)]
#[serde(untagged)]
pub enum RemoveMediaPathSuccess {
    Status204(),
    UnknownValue(serde_json::Value),
}

/// struct for typed successes of method [`remove_virtual_folder`]
#[derive(Debug, Clone, Serialize, Deserialize)]
#[serde(untagged)]
pub enum RemoveVirtualFolderSuccess {
    Status204(),
    UnknownValue(serde_json::Value),
}

/// struct for typed successes of method [`rename_virtual_folder`]
#[derive(Debug, Clone, Serialize, Deserialize)]
#[serde(untagged)]
pub enum RenameVirtualFolderSuccess {
    Status204(),
    UnknownValue(serde_json::Value),
}

/// struct for typed successes of method [`update_library_options`]
#[derive(Debug, Clone, Serialize, Deserialize)]
#[serde(untagged)]
pub enum UpdateLibraryOptionsSuccess {
    Status204(),
    UnknownValue(serde_json::Value),
}

/// struct for typed successes of method [`update_media_path`]
#[derive(Debug, Clone, Serialize, Deserialize)]
#[serde(untagged)]
pub enum UpdateMediaPathSuccess {
    Status204(),
    UnknownValue(serde_json::Value),
}

/// struct for typed errors of method [`add_media_path`]
#[derive(Debug, Clone, Serialize, Deserialize)]
#[serde(untagged)]
pub enum AddMediaPathError {
    Status401(),
    Status403(),
    UnknownValue(serde_json::Value),
}

/// struct for typed errors of method [`add_virtual_folder`]
#[derive(Debug, Clone, Serialize, Deserialize)]
#[serde(untagged)]
pub enum AddVirtualFolderError {
    Status401(),
    Status403(),
    UnknownValue(serde_json::Value),
}

/// struct for typed errors of method [`get_virtual_folders`]
#[derive(Debug, Clone, Serialize, Deserialize)]
#[serde(untagged)]
pub enum GetVirtualFoldersError {
    Status401(),
    Status403(),
    UnknownValue(serde_json::Value),
}

/// struct for typed errors of method [`remove_media_path`]
#[derive(Debug, Clone, Serialize, Deserialize)]
#[serde(untagged)]
pub enum RemoveMediaPathError {
    Status401(),
    Status403(),
    UnknownValue(serde_json::Value),
}

/// struct for typed errors of method [`remove_virtual_folder`]
#[derive(Debug, Clone, Serialize, Deserialize)]
#[serde(untagged)]
pub enum RemoveVirtualFolderError {
    Status401(),
    Status403(),
    UnknownValue(serde_json::Value),
}

/// struct for typed errors of method [`rename_virtual_folder`]
#[derive(Debug, Clone, Serialize, Deserialize)]
#[serde(untagged)]
pub enum RenameVirtualFolderError {
    Status404(models::ProblemDetails),
    Status409(models::ProblemDetails),
    Status401(),
    Status403(),
    UnknownValue(serde_json::Value),
}

/// struct for typed errors of method [`update_library_options`]
#[derive(Debug, Clone, Serialize, Deserialize)]
#[serde(untagged)]
pub enum UpdateLibraryOptionsError {
    Status404(models::ProblemDetails),
    Status401(),
    Status403(),
    UnknownValue(serde_json::Value),
}

/// struct for typed errors of method [`update_media_path`]
#[derive(Debug, Clone, Serialize, Deserialize)]
#[serde(untagged)]
pub enum UpdateMediaPathError {
    Status401(),
    Status403(),
    UnknownValue(serde_json::Value),
}


pub async fn add_media_path(configuration: &configuration::Configuration, params: AddMediaPathParams) -> Result<ResponseContent<AddMediaPathSuccess>, Error<AddMediaPathError>> {
    let local_var_configuration = configuration;

    // unbox the parameters
    let media_path_dto = params.media_path_dto;
    let refresh_library = params.refresh_library;


    let local_var_client = &local_var_configuration.client;

    let local_var_uri_str = format!("{}/Library/VirtualFolders/Paths", local_var_configuration.base_path);
    let mut local_var_req_builder = local_var_client.request(reqwest::Method::POST, local_var_uri_str.as_str());

    if let Some(ref local_var_str) = refresh_library {
        local_var_req_builder = local_var_req_builder.query(&[("refreshLibrary", &local_var_str.to_string())]);
    }
    if let Some(ref local_var_user_agent) = local_var_configuration.user_agent {
        local_var_req_builder = local_var_req_builder.header(reqwest::header::USER_AGENT, local_var_user_agent.clone());
    }
    if let Some(ref local_var_apikey) = local_var_configuration.api_key {
        let local_var_key = local_var_apikey.key.clone();
        let local_var_value = match local_var_apikey.prefix {
            Some(ref local_var_prefix) => format!("{} {}", local_var_prefix, local_var_key),
            None => local_var_key,
        };
        local_var_req_builder = local_var_req_builder.header("Authorization", local_var_value);
    };
    local_var_req_builder = local_var_req_builder.json(&media_path_dto);

    let local_var_req = local_var_req_builder.build()?;
    let local_var_resp = local_var_client.execute(local_var_req).await?;

    let local_var_status = local_var_resp.status();
    let local_var_content = local_var_resp.text().await?;

    if !local_var_status.is_client_error() && !local_var_status.is_server_error() {
        let local_var_entity: Option<AddMediaPathSuccess> = serde_json::from_str(&local_var_content).ok();
        let local_var_result = ResponseContent { status: local_var_status, content: local_var_content, entity: local_var_entity };
        Ok(local_var_result)
    } else {
        let local_var_entity: Option<AddMediaPathError> = serde_json::from_str(&local_var_content).ok();
        let local_var_error = ResponseContent { status: local_var_status, content: local_var_content, entity: local_var_entity };
        Err(Error::ResponseError(local_var_error))
    }
}

pub async fn add_virtual_folder(configuration: &configuration::Configuration, params: AddVirtualFolderParams) -> Result<ResponseContent<AddVirtualFolderSuccess>, Error<AddVirtualFolderError>> {
    let local_var_configuration = configuration;

    // unbox the parameters
    let name = params.name;
    let collection_type = params.collection_type;
    let paths = params.paths;
    let refresh_library = params.refresh_library;
    let add_virtual_folder_dto = params.add_virtual_folder_dto;


    let local_var_client = &local_var_configuration.client;

    let local_var_uri_str = format!("{}/Library/VirtualFolders", local_var_configuration.base_path);
    let mut local_var_req_builder = local_var_client.request(reqwest::Method::POST, local_var_uri_str.as_str());

    if let Some(ref local_var_str) = name {
        local_var_req_builder = local_var_req_builder.query(&[("name", &local_var_str.to_string())]);
    }
    if let Some(ref local_var_str) = collection_type {
        local_var_req_builder = local_var_req_builder.query(&[("collectionType", &local_var_str.to_string())]);
    }
    if let Some(ref local_var_str) = paths {
        local_var_req_builder = match "multi" {
            "multi" => local_var_req_builder.query(&local_var_str.into_iter().map(|p| ("paths".to_owned(), p.to_string())).collect::<Vec<(std::string::String, std::string::String)>>()),
            _ => local_var_req_builder.query(&[("paths", &local_var_str.into_iter().map(|p| p.to_string()).collect::<Vec<String>>().join(",").to_string())]),
        };
    }
    if let Some(ref local_var_str) = refresh_library {
        local_var_req_builder = local_var_req_builder.query(&[("refreshLibrary", &local_var_str.to_string())]);
    }
    if let Some(ref local_var_user_agent) = local_var_configuration.user_agent {
        local_var_req_builder = local_var_req_builder.header(reqwest::header::USER_AGENT, local_var_user_agent.clone());
    }
    if let Some(ref local_var_apikey) = local_var_configuration.api_key {
        let local_var_key = local_var_apikey.key.clone();
        let local_var_value = match local_var_apikey.prefix {
            Some(ref local_var_prefix) => format!("{} {}", local_var_prefix, local_var_key),
            None => local_var_key,
        };
        local_var_req_builder = local_var_req_builder.header("Authorization", local_var_value);
    };
    local_var_req_builder = local_var_req_builder.json(&add_virtual_folder_dto);

    let local_var_req = local_var_req_builder.build()?;
    let local_var_resp = local_var_client.execute(local_var_req).await?;

    let local_var_status = local_var_resp.status();
    let local_var_content = local_var_resp.text().await?;

    if !local_var_status.is_client_error() && !local_var_status.is_server_error() {
        let local_var_entity: Option<AddVirtualFolderSuccess> = serde_json::from_str(&local_var_content).ok();
        let local_var_result = ResponseContent { status: local_var_status, content: local_var_content, entity: local_var_entity };
        Ok(local_var_result)
    } else {
        let local_var_entity: Option<AddVirtualFolderError> = serde_json::from_str(&local_var_content).ok();
        let local_var_error = ResponseContent { status: local_var_status, content: local_var_content, entity: local_var_entity };
        Err(Error::ResponseError(local_var_error))
    }
}

pub async fn get_virtual_folders(configuration: &configuration::Configuration) -> Result<ResponseContent<GetVirtualFoldersSuccess>, Error<GetVirtualFoldersError>> {
    let local_var_configuration = configuration;

    // unbox the parameters


    let local_var_client = &local_var_configuration.client;

    let local_var_uri_str = format!("{}/Library/VirtualFolders", local_var_configuration.base_path);
    let mut local_var_req_builder = local_var_client.request(reqwest::Method::GET, local_var_uri_str.as_str());

    if let Some(ref local_var_user_agent) = local_var_configuration.user_agent {
        local_var_req_builder = local_var_req_builder.header(reqwest::header::USER_AGENT, local_var_user_agent.clone());
    }
    if let Some(ref local_var_apikey) = local_var_configuration.api_key {
        let local_var_key = local_var_apikey.key.clone();
        let local_var_value = match local_var_apikey.prefix {
            Some(ref local_var_prefix) => format!("{} {}", local_var_prefix, local_var_key),
            None => local_var_key,
        };
        local_var_req_builder = local_var_req_builder.header("Authorization", local_var_value);
    };

    let local_var_req = local_var_req_builder.build()?;
    let local_var_resp = local_var_client.execute(local_var_req).await?;

    let local_var_status = local_var_resp.status();
    let local_var_content = local_var_resp.text().await?;

    if !local_var_status.is_client_error() && !local_var_status.is_server_error() {
        let local_var_entity: Option<GetVirtualFoldersSuccess> = serde_json::from_str(&local_var_content).ok();
        let local_var_result = ResponseContent { status: local_var_status, content: local_var_content, entity: local_var_entity };
        Ok(local_var_result)
    } else {
        let local_var_entity: Option<GetVirtualFoldersError> = serde_json::from_str(&local_var_content).ok();
        let local_var_error = ResponseContent { status: local_var_status, content: local_var_content, entity: local_var_entity };
        Err(Error::ResponseError(local_var_error))
    }
}

pub async fn remove_media_path(configuration: &configuration::Configuration, params: RemoveMediaPathParams) -> Result<ResponseContent<RemoveMediaPathSuccess>, Error<RemoveMediaPathError>> {
    let local_var_configuration = configuration;

    // unbox the parameters
    let name = params.name;
    let path = params.path;
    let refresh_library = params.refresh_library;


    let local_var_client = &local_var_configuration.client;

    let local_var_uri_str = format!("{}/Library/VirtualFolders/Paths", local_var_configuration.base_path);
    let mut local_var_req_builder = local_var_client.request(reqwest::Method::DELETE, local_var_uri_str.as_str());

    if let Some(ref local_var_str) = name {
        local_var_req_builder = local_var_req_builder.query(&[("name", &local_var_str.to_string())]);
    }
    if let Some(ref local_var_str) = path {
        local_var_req_builder = local_var_req_builder.query(&[("path", &local_var_str.to_string())]);
    }
    if let Some(ref local_var_str) = refresh_library {
        local_var_req_builder = local_var_req_builder.query(&[("refreshLibrary", &local_var_str.to_string())]);
    }
    if let Some(ref local_var_user_agent) = local_var_configuration.user_agent {
        local_var_req_builder = local_var_req_builder.header(reqwest::header::USER_AGENT, local_var_user_agent.clone());
    }
    if let Some(ref local_var_apikey) = local_var_configuration.api_key {
        let local_var_key = local_var_apikey.key.clone();
        let local_var_value = match local_var_apikey.prefix {
            Some(ref local_var_prefix) => format!("{} {}", local_var_prefix, local_var_key),
            None => local_var_key,
        };
        local_var_req_builder = local_var_req_builder.header("Authorization", local_var_value);
    };

    let local_var_req = local_var_req_builder.build()?;
    let local_var_resp = local_var_client.execute(local_var_req).await?;

    let local_var_status = local_var_resp.status();
    let local_var_content = local_var_resp.text().await?;

    if !local_var_status.is_client_error() && !local_var_status.is_server_error() {
        let local_var_entity: Option<RemoveMediaPathSuccess> = serde_json::from_str(&local_var_content).ok();
        let local_var_result = ResponseContent { status: local_var_status, content: local_var_content, entity: local_var_entity };
        Ok(local_var_result)
    } else {
        let local_var_entity: Option<RemoveMediaPathError> = serde_json::from_str(&local_var_content).ok();
        let local_var_error = ResponseContent { status: local_var_status, content: local_var_content, entity: local_var_entity };
        Err(Error::ResponseError(local_var_error))
    }
}

pub async fn remove_virtual_folder(configuration: &configuration::Configuration, params: RemoveVirtualFolderParams) -> Result<ResponseContent<RemoveVirtualFolderSuccess>, Error<RemoveVirtualFolderError>> {
    let local_var_configuration = configuration;

    // unbox the parameters
    let name = params.name;
    let refresh_library = params.refresh_library;


    let local_var_client = &local_var_configuration.client;

    let local_var_uri_str = format!("{}/Library/VirtualFolders", local_var_configuration.base_path);
    let mut local_var_req_builder = local_var_client.request(reqwest::Method::DELETE, local_var_uri_str.as_str());

    if let Some(ref local_var_str) = name {
        local_var_req_builder = local_var_req_builder.query(&[("name", &local_var_str.to_string())]);
    }
    if let Some(ref local_var_str) = refresh_library {
        local_var_req_builder = local_var_req_builder.query(&[("refreshLibrary", &local_var_str.to_string())]);
    }
    if let Some(ref local_var_user_agent) = local_var_configuration.user_agent {
        local_var_req_builder = local_var_req_builder.header(reqwest::header::USER_AGENT, local_var_user_agent.clone());
    }
    if let Some(ref local_var_apikey) = local_var_configuration.api_key {
        let local_var_key = local_var_apikey.key.clone();
        let local_var_value = match local_var_apikey.prefix {
            Some(ref local_var_prefix) => format!("{} {}", local_var_prefix, local_var_key),
            None => local_var_key,
        };
        local_var_req_builder = local_var_req_builder.header("Authorization", local_var_value);
    };

    let local_var_req = local_var_req_builder.build()?;
    let local_var_resp = local_var_client.execute(local_var_req).await?;

    let local_var_status = local_var_resp.status();
    let local_var_content = local_var_resp.text().await?;

    if !local_var_status.is_client_error() && !local_var_status.is_server_error() {
        let local_var_entity: Option<RemoveVirtualFolderSuccess> = serde_json::from_str(&local_var_content).ok();
        let local_var_result = ResponseContent { status: local_var_status, content: local_var_content, entity: local_var_entity };
        Ok(local_var_result)
    } else {
        let local_var_entity: Option<RemoveVirtualFolderError> = serde_json::from_str(&local_var_content).ok();
        let local_var_error = ResponseContent { status: local_var_status, content: local_var_content, entity: local_var_entity };
        Err(Error::ResponseError(local_var_error))
    }
}

pub async fn rename_virtual_folder(configuration: &configuration::Configuration, params: RenameVirtualFolderParams) -> Result<ResponseContent<RenameVirtualFolderSuccess>, Error<RenameVirtualFolderError>> {
    let local_var_configuration = configuration;

    // unbox the parameters
    let name = params.name;
    let new_name = params.new_name;
    let refresh_library = params.refresh_library;


    let local_var_client = &local_var_configuration.client;

    let local_var_uri_str = format!("{}/Library/VirtualFolders/Name", local_var_configuration.base_path);
    let mut local_var_req_builder = local_var_client.request(reqwest::Method::POST, local_var_uri_str.as_str());

    if let Some(ref local_var_str) = name {
        local_var_req_builder = local_var_req_builder.query(&[("name", &local_var_str.to_string())]);
    }
    if let Some(ref local_var_str) = new_name {
        local_var_req_builder = local_var_req_builder.query(&[("newName", &local_var_str.to_string())]);
    }
    if let Some(ref local_var_str) = refresh_library {
        local_var_req_builder = local_var_req_builder.query(&[("refreshLibrary", &local_var_str.to_string())]);
    }
    if let Some(ref local_var_user_agent) = local_var_configuration.user_agent {
        local_var_req_builder = local_var_req_builder.header(reqwest::header::USER_AGENT, local_var_user_agent.clone());
    }
    if let Some(ref local_var_apikey) = local_var_configuration.api_key {
        let local_var_key = local_var_apikey.key.clone();
        let local_var_value = match local_var_apikey.prefix {
            Some(ref local_var_prefix) => format!("{} {}", local_var_prefix, local_var_key),
            None => local_var_key,
        };
        local_var_req_builder = local_var_req_builder.header("Authorization", local_var_value);
    };

    let local_var_req = local_var_req_builder.build()?;
    let local_var_resp = local_var_client.execute(local_var_req).await?;

    let local_var_status = local_var_resp.status();
    let local_var_content = local_var_resp.text().await?;

    if !local_var_status.is_client_error() && !local_var_status.is_server_error() {
        let local_var_entity: Option<RenameVirtualFolderSuccess> = serde_json::from_str(&local_var_content).ok();
        let local_var_result = ResponseContent { status: local_var_status, content: local_var_content, entity: local_var_entity };
        Ok(local_var_result)
    } else {
        let local_var_entity: Option<RenameVirtualFolderError> = serde_json::from_str(&local_var_content).ok();
        let local_var_error = ResponseContent { status: local_var_status, content: local_var_content, entity: local_var_entity };
        Err(Error::ResponseError(local_var_error))
    }
}

pub async fn update_library_options(configuration: &configuration::Configuration, params: UpdateLibraryOptionsParams) -> Result<ResponseContent<UpdateLibraryOptionsSuccess>, Error<UpdateLibraryOptionsError>> {
    let local_var_configuration = configuration;

    // unbox the parameters
    let update_library_options_dto = params.update_library_options_dto;


    let local_var_client = &local_var_configuration.client;

    let local_var_uri_str = format!("{}/Library/VirtualFolders/LibraryOptions", local_var_configuration.base_path);
    let mut local_var_req_builder = local_var_client.request(reqwest::Method::POST, local_var_uri_str.as_str());

    if let Some(ref local_var_user_agent) = local_var_configuration.user_agent {
        local_var_req_builder = local_var_req_builder.header(reqwest::header::USER_AGENT, local_var_user_agent.clone());
    }
    if let Some(ref local_var_apikey) = local_var_configuration.api_key {
        let local_var_key = local_var_apikey.key.clone();
        let local_var_value = match local_var_apikey.prefix {
            Some(ref local_var_prefix) => format!("{} {}", local_var_prefix, local_var_key),
            None => local_var_key,
        };
        local_var_req_builder = local_var_req_builder.header("Authorization", local_var_value);
    };
    local_var_req_builder = local_var_req_builder.json(&update_library_options_dto);

    let local_var_req = local_var_req_builder.build()?;
    let local_var_resp = local_var_client.execute(local_var_req).await?;

    let local_var_status = local_var_resp.status();
    let local_var_content = local_var_resp.text().await?;

    if !local_var_status.is_client_error() && !local_var_status.is_server_error() {
        let local_var_entity: Option<UpdateLibraryOptionsSuccess> = serde_json::from_str(&local_var_content).ok();
        let local_var_result = ResponseContent { status: local_var_status, content: local_var_content, entity: local_var_entity };
        Ok(local_var_result)
    } else {
        let local_var_entity: Option<UpdateLibraryOptionsError> = serde_json::from_str(&local_var_content).ok();
        let local_var_error = ResponseContent { status: local_var_status, content: local_var_content, entity: local_var_entity };
        Err(Error::ResponseError(local_var_error))
    }
}

pub async fn update_media_path(configuration: &configuration::Configuration, params: UpdateMediaPathParams) -> Result<ResponseContent<UpdateMediaPathSuccess>, Error<UpdateMediaPathError>> {
    let local_var_configuration = configuration;

    // unbox the parameters
    let update_media_path_request_dto = params.update_media_path_request_dto;


    let local_var_client = &local_var_configuration.client;

    let local_var_uri_str = format!("{}/Library/VirtualFolders/Paths/Update", local_var_configuration.base_path);
    let mut local_var_req_builder = local_var_client.request(reqwest::Method::POST, local_var_uri_str.as_str());

    if let Some(ref local_var_user_agent) = local_var_configuration.user_agent {
        local_var_req_builder = local_var_req_builder.header(reqwest::header::USER_AGENT, local_var_user_agent.clone());
    }
    if let Some(ref local_var_apikey) = local_var_configuration.api_key {
        let local_var_key = local_var_apikey.key.clone();
        let local_var_value = match local_var_apikey.prefix {
            Some(ref local_var_prefix) => format!("{} {}", local_var_prefix, local_var_key),
            None => local_var_key,
        };
        local_var_req_builder = local_var_req_builder.header("Authorization", local_var_value);
    };
    local_var_req_builder = local_var_req_builder.json(&update_media_path_request_dto);

    let local_var_req = local_var_req_builder.build()?;
    let local_var_resp = local_var_client.execute(local_var_req).await?;

    let local_var_status = local_var_resp.status();
    let local_var_content = local_var_resp.text().await?;

    if !local_var_status.is_client_error() && !local_var_status.is_server_error() {
        let local_var_entity: Option<UpdateMediaPathSuccess> = serde_json::from_str(&local_var_content).ok();
        let local_var_result = ResponseContent { status: local_var_status, content: local_var_content, entity: local_var_entity };
        Ok(local_var_result)
    } else {
        let local_var_entity: Option<UpdateMediaPathError> = serde_json::from_str(&local_var_content).ok();
        let local_var_error = ResponseContent { status: local_var_status, content: local_var_content, entity: local_var_entity };
        Err(Error::ResponseError(local_var_error))
    }
}

