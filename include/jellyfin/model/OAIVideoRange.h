#pragma once

/*
 * OAIVideoRange.h
 * name: VideoRange
 * schemaName: VideoRange
 * classFilename: VideoRange
 * classVarName: VideoRange
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * An enum representing video ranges.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIVideoRange {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        UNKNOWN, // Unknown
        SDR, // SDR
        HDR, // HDR
    };
    extern void to_json(json_t&, const OAIVideoRange&);
    extern void from_json(const json_t&, OAIVideoRange&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIVideoRange);
