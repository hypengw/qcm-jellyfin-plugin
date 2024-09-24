#pragma once

/*
 * OAIPlaybackOrder.h
 * name: PlaybackOrder
 * schemaName: PlaybackOrder
 * classFilename: PlaybackOrder
 * classVarName: PlaybackOrder
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum PlaybackOrder.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIPlaybackOrder {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        DEFAULT, // Default
        SHUFFLE, // Shuffle
    };
    extern void to_json(json_t&, const OAIPlaybackOrder&);
    extern void from_json(const json_t&, OAIPlaybackOrder&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlaybackOrder);
