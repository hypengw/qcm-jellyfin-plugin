#pragma once

/*
 * OAIPlayerStateInfo.h
 * name: PlayerStateInfo
 * schemaName: PlayerStateInfo
 * classFilename: PlayerStateInfo
 * classVarName: PlayerStateInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIPlayMethod.h"
#include "jellyfin/model/OAIPlaybackOrder.h"
#include "jellyfin/model/OAIRepeatMode.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIPlayerStateInfo {
    public:
    
        // Gets or sets the now playing position ticks.
        std::optional<std::int64_t> PositionTicks;

        // Gets or sets a value indicating whether this instance can seek.
        bool CanSeek;

        // Gets or sets a value indicating whether this instance is paused.
        bool IsPaused;

        // Gets or sets a value indicating whether this instance is muted.
        bool IsMuted;

        // Gets or sets the volume level.
        std::optional<std::int32_t> VolumeLevel;

        // Gets or sets the index of the now playing audio stream.
        std::optional<std::int32_t> AudioStreamIndex;

        // Gets or sets the index of the now playing subtitle stream.
        std::optional<std::int32_t> SubtitleStreamIndex;

        // Gets or sets the now playing media version identifier.
        std::optional<std::string> MediaSourceId;

        // Gets or sets the play method.
        std::optional<OAIPlayMethod> PlayMethod;

        // Gets or sets the repeat mode.
        OAIRepeatMode RepeatMode;

        // Gets or sets the playback order.
        OAIPlaybackOrder PlaybackOrder;

        // Gets or sets the now playing live stream identifier.
        std::optional<std::string> LiveStreamId;

        OAIPlayerStateInfo();
        ~OAIPlayerStateInfo();
    };
    extern void to_json(json_t&, const OAIPlayerStateInfo&);
    extern void from_json(const json_t&, OAIPlayerStateInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlayerStateInfo);
