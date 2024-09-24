#pragma once

/*
 * OAIPlayAccess.h
 * name: PlayAccess
 * schemaName: PlayAccess
 * classFilename: PlayAccess
 * classVarName: PlayAccess
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

    enum class OAIPlayAccess {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        FULL, // Full
        NONE, // None
    };
    extern void to_json(json_t&, const OAIPlayAccess&);
    extern void from_json(const json_t&, OAIPlayAccess&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlayAccess);
