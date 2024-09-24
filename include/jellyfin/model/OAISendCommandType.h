#pragma once

/*
 * OAISendCommandType.h
 * name: SendCommandType
 * schemaName: SendCommandType
 * classFilename: SendCommandType
 * classVarName: SendCommandType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum SendCommandType.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAISendCommandType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        UNPAUSE, // Unpause
        PAUSE, // Pause
        STOP, // Stop
        SEEK, // Seek
    };
    extern void to_json(json_t&, const OAISendCommandType&);
    extern void from_json(const json_t&, OAISendCommandType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISendCommandType);
