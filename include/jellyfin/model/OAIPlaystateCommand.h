#pragma once

/*
 * OAIPlaystateCommand.h
 * name: PlaystateCommand
 * schemaName: PlaystateCommand
 * classFilename: PlaystateCommand
 * classVarName: PlaystateCommand
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum PlaystateCommand.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIPlaystateCommand {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        STOP, // Stop
        PAUSE, // Pause
        UNPAUSE, // Unpause
        NEXTTRACK, // NextTrack
        PREVIOUSTRACK, // PreviousTrack
        SEEK, // Seek
        REWIND, // Rewind
        FASTFORWARD, // FastForward
        PLAYPAUSE, // PlayPause
    };
    extern void to_json(json_t&, const OAIPlaystateCommand&);
    extern void from_json(const json_t&, OAIPlaystateCommand&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlaystateCommand);
