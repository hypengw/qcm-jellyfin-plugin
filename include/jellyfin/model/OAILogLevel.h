#pragma once

/*
 * OAILogLevel.h
 * name: LogLevel
 * schemaName: LogLevel
 * classFilename: LogLevel
 * classVarName: LogLevel
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAILogLevel {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        TRACE, // Trace
        DEBUG, // Debug
        INFORMATION, // Information
        WARNING, // Warning
        ERROR, // Error
        CRITICAL, // Critical
        NONE, // None
    };
    extern void to_json(json_t&, const OAILogLevel&);
    extern void from_json(const json_t&, OAILogLevel&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAILogLevel);
