#pragma once

/*
 * OAIFileSystemEntryType.h
 * name: FileSystemEntryType
 * schemaName: FileSystemEntryType
 * classFilename: FileSystemEntryType
 * classVarName: FileSystemEntryType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum FileSystemEntryType.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIFileSystemEntryType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        FILE, // File
        DIRECTORY, // Directory
        NETWORKCOMPUTER, // NetworkComputer
        NETWORKSHARE, // NetworkShare
    };
    extern void to_json(json_t&, const OAIFileSystemEntryType&);
    extern void from_json(const json_t&, OAIFileSystemEntryType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIFileSystemEntryType);
