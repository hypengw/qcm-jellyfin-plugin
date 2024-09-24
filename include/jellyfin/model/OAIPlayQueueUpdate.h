#pragma once

/*
 * OAIPlayQueueUpdate.h
 * name: PlayQueueUpdate
 * schemaName: PlayQueueUpdate
 * classFilename: PlayQueueUpdate
 * classVarName: PlayQueueUpdate
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class PlayQueueUpdate.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIGroupRepeatMode.h"
#include "jellyfin/model/OAIGroupShuffleMode.h"
#include "jellyfin/model/OAIPlayQueueUpdateReason.h"
#include "jellyfin/model/OAISyncPlayQueueItem.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAISyncPlayQueueItem;


    class OAIPlayQueueUpdate {
    public:
    
        // Gets the request type that originated this update.
        OAIPlayQueueUpdateReason Reason;

        // Gets the UTC time of the last change to the playing queue.
        std::string LastUpdate;

        // Gets the playlist.
        std::vector<OAISyncPlayQueueItem> Playlist;

        // Gets the playing item index in the playlist.
        std::int32_t PlayingItemIndex;

        // Gets the start position ticks.
        std::int64_t StartPositionTicks;

        // Gets a value indicating whether the current item is playing.
        bool IsPlaying;

        // Gets the shuffle mode.
        OAIGroupShuffleMode ShuffleMode;

        // Gets the repeat mode.
        OAIGroupRepeatMode RepeatMode;

        OAIPlayQueueUpdate();
        ~OAIPlayQueueUpdate();
    };
    extern void to_json(json_t&, const OAIPlayQueueUpdate&);
    extern void from_json(const json_t&, OAIPlayQueueUpdate&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlayQueueUpdate);
