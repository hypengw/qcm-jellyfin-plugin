#pragma once

/*
 * OAIRepeatMode.h
 * name: RepeatMode
 * schemaName: RepeatMode
 * classFilename: RepeatMode
 * classVarName: RepeatMode
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

    enum class OAIRepeatMode {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        REPEATNONE, // RepeatNone
        REPEATALL, // RepeatAll
        REPEATONE, // RepeatOne
    };
    extern void to_json(json_t&, const OAIRepeatMode&);
    extern void from_json(const json_t&, OAIRepeatMode&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIRepeatMode);
