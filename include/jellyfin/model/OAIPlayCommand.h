#pragma once

/*
 * OAIPlayCommand.h
 * name: PlayCommand
 * schemaName: PlayCommand
 * classFilename: PlayCommand
 * classVarName: PlayCommand
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum PlayCommand.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIPlayCommand {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        PLAYNOW, // PlayNow
        PLAYNEXT, // PlayNext
        PLAYLAST, // PlayLast
        PLAYINSTANTMIX, // PlayInstantMix
        PLAYSHUFFLE, // PlayShuffle
    };
    extern void to_json(json_t&, const OAIPlayCommand&);
    extern void from_json(const json_t&, OAIPlayCommand&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlayCommand);
