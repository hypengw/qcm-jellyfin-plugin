#pragma once

/*
 * OAILocationType.h
 * name: LocationType
 * schemaName: LocationType
 * classFilename: LocationType
 * classVarName: LocationType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum LocationType.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAILocationType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        FILESYSTEM, // FileSystem
        REMOTE, // Remote
        VIRTUAL, // Virtual
        OFFLINE, // Offline
    };
    extern void to_json(json_t&, const OAILocationType&);
    extern void from_json(const json_t&, OAILocationType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAILocationType);
