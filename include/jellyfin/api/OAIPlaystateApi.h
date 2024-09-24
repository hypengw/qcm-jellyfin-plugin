#pragma once
/*
 * OAIPlaystateApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIPlayMethod.h"
#include "jellyfin/model/OAIPlaybackProgressInfo.h"
#include "jellyfin/model/OAIPlaybackStartInfo.h"
#include "jellyfin/model/OAIPlaybackStopInfo.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAIRepeatMode.h"
#include "jellyfin/model/OAIUserItemDataDto.h"
#include <cstdint>
#include <string>

namespace jellyfin {
namespace model
{
using return_type_markPlayedItem = OAIUserItemDataDto;
using return_type_markUnplayedItem = OAIUserItemDataDto;
using return_type_onPlaybackProgress = std::nullptr_t;
using return_type_onPlaybackStart = std::nullptr_t;
using return_type_onPlaybackStopped = std::nullptr_t;
using return_type_pingPlaybackSession = std::nullptr_t;
using return_type_reportPlaybackProgress = std::nullptr_t;
using return_type_reportPlaybackStart = std::nullptr_t;
using return_type_reportPlaybackStopped = std::nullptr_t;
}

namespace api::param 
{
struct markPlayedItem {
    std::string itemId; // Item id.
    std::optional<std::string> userId; // User id.
    std::optional<std::string> datePlayed; // Optional. The date the item was played.
};
struct markUnplayedItem {
    std::string itemId; // Item id.
    std::optional<std::string> userId; // User id.
};
struct onPlaybackProgress {
    std::string itemId; // Item id.
    std::optional<std::string> mediaSourceId; // The id of the MediaSource.
    std::optional<std::int64_t> positionTicks; // Optional. The current position, in ticks. 1 tick &#x3D; 10000 ms.
    std::optional<std::int32_t> audioStreamIndex; // The audio stream index.
    std::optional<std::int32_t> subtitleStreamIndex; // The subtitle stream index.
    std::optional<std::int32_t> volumeLevel; // Scale of 0-100.
    std::optional<OAIPlayMethod> playMethod; // The play method.
    std::optional<std::string> liveStreamId; // The live stream id.
    std::optional<std::string> playSessionId; // The play session id.
    std::optional<OAIRepeatMode> repeatMode; // The repeat mode.
    std::optional<bool> isPaused; // Indicates if the player is paused.
    std::optional<bool> isMuted; // Indicates if the player is muted.
};
struct onPlaybackStart {
    std::string itemId; // Item id.
    std::optional<std::string> mediaSourceId; // The id of the MediaSource.
    std::optional<std::int32_t> audioStreamIndex; // The audio stream index.
    std::optional<std::int32_t> subtitleStreamIndex; // The subtitle stream index.
    std::optional<OAIPlayMethod> playMethod; // The play method.
    std::optional<std::string> liveStreamId; // The live stream id.
    std::optional<std::string> playSessionId; // The play session id.
    std::optional<bool> canSeek; // Indicates if the client can seek.
};
struct onPlaybackStopped {
    std::string itemId; // Item id.
    std::optional<std::string> mediaSourceId; // The id of the MediaSource.
    std::optional<std::string> nextMediaType; // The next media type that will play.
    std::optional<std::int64_t> positionTicks; // Optional. The position, in ticks, where playback stopped. 1 tick &#x3D; 10000 ms.
    std::optional<std::string> liveStreamId; // The live stream id.
    std::optional<std::string> playSessionId; // The play session id.
};
struct pingPlaybackSession {
    std::string playSessionId; // Playback session id.
};
struct reportPlaybackProgress {
    std::optional<OAIPlaybackProgressInfo> body; // The playback progress info.
};
struct reportPlaybackStart {
    std::optional<OAIPlaybackStartInfo> body; // The playback start info.
};
struct reportPlaybackStopped {
    std::optional<OAIPlaybackStopInfo> body; // The playback stop info.
};
}

namespace api 
{
// Marks an item as played for user.
struct markPlayedItem {
public:
    using in_type                      = param::markPlayedItem;
    using out_type                     = model::return_type_markPlayedItem;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/UserPlayedItems/{}"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.datePlayed)
            p.set_param("datePlayed", convert_from<std::string>(input.datePlayed.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIUserItemDataDto
 * returnFormat: 
 * returnBaseType: OAIUserItemDataDto
 * returnContainer: 
 * baseName: Playstate
 * defaultResponse: OAIUserItemDataDto()
 */
};
// Marks an item as unplayed for user.
struct markUnplayedItem {
public:
    using in_type                      = param::markUnplayedItem;
    using out_type                     = model::return_type_markUnplayedItem;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/UserPlayedItems/{}"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIUserItemDataDto
 * returnFormat: 
 * returnBaseType: OAIUserItemDataDto
 * returnContainer: 
 * baseName: Playstate
 * defaultResponse: OAIUserItemDataDto()
 */
};
// Reports a session&#39;s playback progress.
struct onPlaybackProgress {
public:
    using in_type                      = param::onPlaybackProgress;
    using out_type                     = model::return_type_onPlaybackProgress;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/PlayingItems/{}/Progress"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.mediaSourceId)
            p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId.value()));
        if(input.positionTicks)
            p.set_param("positionTicks", convert_from<std::string>(input.positionTicks.value()));
        if(input.audioStreamIndex)
            p.set_param("audioStreamIndex", convert_from<std::string>(input.audioStreamIndex.value()));
        if(input.subtitleStreamIndex)
            p.set_param("subtitleStreamIndex", convert_from<std::string>(input.subtitleStreamIndex.value()));
        if(input.volumeLevel)
            p.set_param("volumeLevel", convert_from<std::string>(input.volumeLevel.value()));
        if(input.playMethod)
            p.set_param("playMethod", convert_from<std::string>(input.playMethod.value()));
        if(input.liveStreamId)
            p.set_param("liveStreamId", convert_from<std::string>(input.liveStreamId.value()));
        if(input.playSessionId)
            p.set_param("playSessionId", convert_from<std::string>(input.playSessionId.value()));
        if(input.repeatMode)
            p.set_param("repeatMode", convert_from<std::string>(input.repeatMode.value()));
        if(input.isPaused)
            p.set_param("isPaused", convert_from<std::string>(input.isPaused.value()));
        if(input.isMuted)
            p.set_param("isMuted", convert_from<std::string>(input.isMuted.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Playstate
 * defaultResponse: 
 */
};
// Reports that a session has begun playing an item.
struct onPlaybackStart {
public:
    using in_type                      = param::onPlaybackStart;
    using out_type                     = model::return_type_onPlaybackStart;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/PlayingItems/{}"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.mediaSourceId)
            p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId.value()));
        if(input.audioStreamIndex)
            p.set_param("audioStreamIndex", convert_from<std::string>(input.audioStreamIndex.value()));
        if(input.subtitleStreamIndex)
            p.set_param("subtitleStreamIndex", convert_from<std::string>(input.subtitleStreamIndex.value()));
        if(input.playMethod)
            p.set_param("playMethod", convert_from<std::string>(input.playMethod.value()));
        if(input.liveStreamId)
            p.set_param("liveStreamId", convert_from<std::string>(input.liveStreamId.value()));
        if(input.playSessionId)
            p.set_param("playSessionId", convert_from<std::string>(input.playSessionId.value()));
        if(input.canSeek)
            p.set_param("canSeek", convert_from<std::string>(input.canSeek.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Playstate
 * defaultResponse: 
 */
};
// Reports that a session has stopped playing an item.
struct onPlaybackStopped {
public:
    using in_type                      = param::onPlaybackStopped;
    using out_type                     = model::return_type_onPlaybackStopped;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/PlayingItems/{}"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.mediaSourceId)
            p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId.value()));
        if(input.nextMediaType)
            p.set_param("nextMediaType", convert_from<std::string>(input.nextMediaType.value()));
        if(input.positionTicks)
            p.set_param("positionTicks", convert_from<std::string>(input.positionTicks.value()));
        if(input.liveStreamId)
            p.set_param("liveStreamId", convert_from<std::string>(input.liveStreamId.value()));
        if(input.playSessionId)
            p.set_param("playSessionId", convert_from<std::string>(input.playSessionId.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Playstate
 * defaultResponse: 
 */
};
// Pings a playback session.
struct pingPlaybackSession {
public:
    using in_type                      = param::pingPlaybackSession;
    using out_type                     = model::return_type_pingPlaybackSession;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Sessions/Playing/Ping"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("playSessionId", convert_from<std::string>(input.playSessionId));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Playstate
 * defaultResponse: 
 */
};
// Reports playback progress within a session.
struct reportPlaybackProgress {
public:
    using in_type                      = param::reportPlaybackProgress;
    using out_type                     = model::return_type_reportPlaybackProgress;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Sessions/Playing/Progress"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        if(input.body)
            out = format_param(input.body.value());
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Playstate
 * defaultResponse: 
 */
};
// Reports playback has started within a session.
struct reportPlaybackStart {
public:
    using in_type                      = param::reportPlaybackStart;
    using out_type                     = model::return_type_reportPlaybackStart;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Sessions/Playing"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        if(input.body)
            out = format_param(input.body.value());
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Playstate
 * defaultResponse: 
 */
};
// Reports playback has stopped within a session.
struct reportPlaybackStopped {
public:
    using in_type                      = param::reportPlaybackStopped;
    using out_type                     = model::return_type_reportPlaybackStopped;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Sessions/Playing/Stopped"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        if(input.body)
            out = format_param(input.body.value());
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Playstate
 * defaultResponse: 
 */
};
}
}
