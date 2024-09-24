#pragma once

/*
 * OAIPlaybackRequestType.h
 * name: PlaybackRequestType
 * schemaName: PlaybackRequestType
 * classFilename: PlaybackRequestType
 * classVarName: PlaybackRequestType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum PlaybackRequestType.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIPlaybackRequestType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        PLAY, // Play
        SETPLAYLISTITEM, // SetPlaylistItem
        REMOVEFROMPLAYLIST, // RemoveFromPlaylist
        MOVEPLAYLISTITEM, // MovePlaylistItem
        QUEUE, // Queue
        UNPAUSE, // Unpause
        PAUSE, // Pause
        STOP, // Stop
        SEEK, // Seek
        BUFFER, // Buffer
        READY, // Ready
        NEXTITEM, // NextItem
        PREVIOUSITEM, // PreviousItem
        SETREPEATMODE, // SetRepeatMode
        SETSHUFFLEMODE, // SetShuffleMode
        PING, // Ping
        IGNOREWAIT, // IgnoreWait
    };
    extern void to_json(json_t&, const OAIPlaybackRequestType&);
    extern void from_json(const json_t&, OAIPlaybackRequestType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlaybackRequestType);
