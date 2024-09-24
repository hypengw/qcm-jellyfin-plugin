#pragma once

/*
 * OAIPluginStatus.h
 * name: PluginStatus
 * schemaName: PluginStatus
 * classFilename: PluginStatus
 * classVarName: PluginStatus
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Plugin load status.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIPluginStatus {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        ACTIVE, // Active
        RESTART, // Restart
        DELETED, // Deleted
        SUPERCEDED, // Superceded
        MALFUNCTIONED, // Malfunctioned
        NOTSUPPORTED, // NotSupported
        DISABLED, // Disabled
    };
    extern void to_json(json_t&, const OAIPluginStatus&);
    extern void from_json(const json_t&, OAIPluginStatus&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPluginStatus);
