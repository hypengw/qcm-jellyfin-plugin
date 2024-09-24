#pragma once

/*
 * OAISubtitlePlaybackMode.h
 * name: SubtitlePlaybackMode
 * schemaName: SubtitlePlaybackMode
 * classFilename: SubtitlePlaybackMode
 * classVarName: SubtitlePlaybackMode
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * An enum representing a subtitle playback mode.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAISubtitlePlaybackMode {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        DEFAULT, // Default
        ALWAYS, // Always
        ONLYFORCED, // OnlyForced
        NONE, // None
        SMART, // Smart
    };
    extern void to_json(json_t&, const OAISubtitlePlaybackMode&);
    extern void from_json(const json_t&, OAISubtitlePlaybackMode&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISubtitlePlaybackMode);
