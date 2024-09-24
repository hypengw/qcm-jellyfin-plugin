#pragma once

/*
 * OAIMediaSourceType.h
 * name: MediaSourceType
 * schemaName: MediaSourceType
 * classFilename: MediaSourceType
 * classVarName: MediaSourceType
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

    enum class OAIMediaSourceType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        DEFAULT, // Default
        GROUPING, // Grouping
        PLACEHOLDER, // Placeholder
    };
    extern void to_json(json_t&, const OAIMediaSourceType&);
    extern void from_json(const json_t&, OAIMediaSourceType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMediaSourceType);
