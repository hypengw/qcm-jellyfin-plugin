#pragma once

/*
 * OAIGroupRepeatMode.h
 * name: GroupRepeatMode
 * schemaName: GroupRepeatMode
 * classFilename: GroupRepeatMode
 * classVarName: GroupRepeatMode
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum GroupRepeatMode.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIGroupRepeatMode {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        REPEATONE, // RepeatOne
        REPEATALL, // RepeatAll
        REPEATNONE, // RepeatNone
    };
    extern void to_json(json_t&, const OAIGroupRepeatMode&);
    extern void from_json(const json_t&, OAIGroupRepeatMode&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIGroupRepeatMode);
