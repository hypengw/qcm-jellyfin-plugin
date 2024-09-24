#pragma once

/*
 * OAIPlaybackStopInfo.h
 * name: PlaybackStopInfo
 * schemaName: PlaybackStopInfo
 * classFilename: PlaybackStopInfo
 * classVarName: PlaybackStopInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class PlaybackStopInfo.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIBaseItemDto.h"
#include "jellyfin/model/OAIQueueItem.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIBaseItemDto;
class OAIQueueItem;


    class OAIPlaybackStopInfo {
    public:
    
        // Gets or sets the item.
        std::optional<OAIBaseItemDto> Item;

        // Gets or sets the item identifier.
        std::string ItemId;

        // Gets or sets the session id.
        std::optional<std::string> SessionId;

        // Gets or sets the media version identifier.
        std::optional<std::string> MediaSourceId;

        // Gets or sets the position ticks.
        std::optional<std::int64_t> PositionTicks;

        // Gets or sets the live stream identifier.
        std::optional<std::string> LiveStreamId;

        // Gets or sets the play session identifier.
        std::optional<std::string> PlaySessionId;

        // Gets or sets a value indicating whether this MediaBrowser.Model.Session.PlaybackStopInfo is failed.
        bool Failed;

        std::optional<std::string> NextMediaType;

        std::optional<std::string> PlaylistItemId;

        std::optional<std::vector<OAIQueueItem>> NowPlayingQueue;

        OAIPlaybackStopInfo();
        ~OAIPlaybackStopInfo();
    };
    extern void to_json(json_t&, const OAIPlaybackStopInfo&);
    extern void from_json(const json_t&, OAIPlaybackStopInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlaybackStopInfo);
