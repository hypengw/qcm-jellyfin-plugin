#pragma once

/*
 * OAIPlayMethod.h
 * name: PlayMethod
 * schemaName: PlayMethod
 * classFilename: PlayMethod
 * classVarName: PlayMethod
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

    enum class OAIPlayMethod {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        TRANSCODE, // Transcode
        DIRECTSTREAM, // DirectStream
        DIRECTPLAY, // DirectPlay
    };
    extern void to_json(json_t&, const OAIPlayMethod&);
    extern void from_json(const json_t&, OAIPlayMethod&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlayMethod);
