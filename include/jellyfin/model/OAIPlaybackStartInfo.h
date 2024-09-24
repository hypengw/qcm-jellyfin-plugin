#pragma once

/*
 * OAIPlaybackStartInfo.h
 * name: PlaybackStartInfo
 * schemaName: PlaybackStartInfo
 * classFilename: PlaybackStartInfo
 * classVarName: PlaybackStartInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class PlaybackStartInfo.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIBaseItemDto.h"
#include "jellyfin/model/OAIPlayMethod.h"
#include "jellyfin/model/OAIPlaybackOrder.h"
#include "jellyfin/model/OAIQueueItem.h"
#include "jellyfin/model/OAIRepeatMode.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIBaseItemDto;
class OAIQueueItem;


    class OAIPlaybackStartInfo {
    public:
    
        // Gets or sets a value indicating whether this instance can seek.
        bool CanSeek;

        // Gets or sets the item.
        std::optional<OAIBaseItemDto> Item;

        // Gets or sets the item identifier.
        std::string ItemId;

        // Gets or sets the session id.
        std::optional<std::string> SessionId;

        // Gets or sets the media version identifier.
        std::optional<std::string> MediaSourceId;

        // Gets or sets the index of the audio stream.
        std::optional<std::int32_t> AudioStreamIndex;

        // Gets or sets the index of the subtitle stream.
        std::optional<std::int32_t> SubtitleStreamIndex;

        // Gets or sets a value indicating whether this instance is paused.
        bool IsPaused;

        // Gets or sets a value indicating whether this instance is muted.
        bool IsMuted;

        // Gets or sets the position ticks.
        std::optional<std::int64_t> PositionTicks;

        std::optional<std::int64_t> PlaybackStartTimeTicks;

        // Gets or sets the volume level.
        std::optional<std::int32_t> VolumeLevel;

        std::optional<std::int32_t> Brightness;

        std::optional<std::string> AspectRatio;

        // Gets or sets the play method.
        OAIPlayMethod PlayMethod;

        // Gets or sets the live stream identifier.
        std::optional<std::string> LiveStreamId;

        // Gets or sets the play session identifier.
        std::optional<std::string> PlaySessionId;

        // Gets or sets the repeat mode.
        OAIRepeatMode RepeatMode;

        // Gets or sets the playback order.
        OAIPlaybackOrder PlaybackOrder;

        std::optional<std::vector<OAIQueueItem>> NowPlayingQueue;

        std::optional<std::string> PlaylistItemId;

        OAIPlaybackStartInfo();
        ~OAIPlaybackStartInfo();
    };
    extern void to_json(json_t&, const OAIPlaybackStartInfo&);
    extern void from_json(const json_t&, OAIPlaybackStartInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlaybackStartInfo);
