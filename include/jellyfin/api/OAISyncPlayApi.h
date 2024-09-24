#pragma once
/*
 * OAISyncPlayApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIBufferRequestDto.h"
#include "jellyfin/model/OAIGroupInfoDto.h"
#include "jellyfin/model/OAIIgnoreWaitRequestDto.h"
#include "jellyfin/model/OAIJoinGroupRequestDto.h"
#include "jellyfin/model/OAIMovePlaylistItemRequestDto.h"
#include "jellyfin/model/OAINewGroupRequestDto.h"
#include "jellyfin/model/OAINextItemRequestDto.h"
#include "jellyfin/model/OAIPingRequestDto.h"
#include "jellyfin/model/OAIPlayRequestDto.h"
#include "jellyfin/model/OAIPreviousItemRequestDto.h"
#include "jellyfin/model/OAIQueueRequestDto.h"
#include "jellyfin/model/OAIReadyRequestDto.h"
#include "jellyfin/model/OAIRemoveFromPlaylistRequestDto.h"
#include "jellyfin/model/OAISeekRequestDto.h"
#include "jellyfin/model/OAISetPlaylistItemRequestDto.h"
#include "jellyfin/model/OAISetRepeatModeRequestDto.h"
#include "jellyfin/model/OAISetShuffleModeRequestDto.h"
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_syncPlayBuffering = std::nullptr_t;
using return_type_syncPlayCreateGroup = std::nullptr_t;
using return_type_syncPlayGetGroups = std::vector<OAIGroupInfoDto>;
using return_type_syncPlayJoinGroup = std::nullptr_t;
using return_type_syncPlayLeaveGroup = std::nullptr_t;
using return_type_syncPlayMovePlaylistItem = std::nullptr_t;
using return_type_syncPlayNextItem = std::nullptr_t;
using return_type_syncPlayPause = std::nullptr_t;
using return_type_syncPlayPing = std::nullptr_t;
using return_type_syncPlayPreviousItem = std::nullptr_t;
using return_type_syncPlayQueue = std::nullptr_t;
using return_type_syncPlayReady = std::nullptr_t;
using return_type_syncPlayRemoveFromPlaylist = std::nullptr_t;
using return_type_syncPlaySeek = std::nullptr_t;
using return_type_syncPlaySetIgnoreWait = std::nullptr_t;
using return_type_syncPlaySetNewQueue = std::nullptr_t;
using return_type_syncPlaySetPlaylistItem = std::nullptr_t;
using return_type_syncPlaySetRepeatMode = std::nullptr_t;
using return_type_syncPlaySetShuffleMode = std::nullptr_t;
using return_type_syncPlayStop = std::nullptr_t;
using return_type_syncPlayUnpause = std::nullptr_t;
}

namespace api::param 
{
struct syncPlayBuffering {
    OAIBufferRequestDto body; // The player status.
};
struct syncPlayCreateGroup {
    OAINewGroupRequestDto body; // The settings of the new group.
};
struct syncPlayGetGroups {
};
struct syncPlayJoinGroup {
    OAIJoinGroupRequestDto body; // The group to join.
};
struct syncPlayLeaveGroup {
};
struct syncPlayMovePlaylistItem {
    OAIMovePlaylistItemRequestDto body; // The new position for the item.
};
struct syncPlayNextItem {
    OAINextItemRequestDto body; // The current item information.
};
struct syncPlayPause {
};
struct syncPlayPing {
    OAIPingRequestDto body; // The new ping.
};
struct syncPlayPreviousItem {
    OAIPreviousItemRequestDto body; // The current item information.
};
struct syncPlayQueue {
    OAIQueueRequestDto body; // The items to add.
};
struct syncPlayReady {
    OAIReadyRequestDto body; // The player status.
};
struct syncPlayRemoveFromPlaylist {
    OAIRemoveFromPlaylistRequestDto body; // The items to remove.
};
struct syncPlaySeek {
    OAISeekRequestDto body; // The new playback position.
};
struct syncPlaySetIgnoreWait {
    OAIIgnoreWaitRequestDto body; // The settings to set.
};
struct syncPlaySetNewQueue {
    OAIPlayRequestDto body; // The new playlist to play in the group.
};
struct syncPlaySetPlaylistItem {
    OAISetPlaylistItemRequestDto body; // The new item to play.
};
struct syncPlaySetRepeatMode {
    OAISetRepeatModeRequestDto body; // The new repeat mode.
};
struct syncPlaySetShuffleMode {
    OAISetShuffleModeRequestDto body; // The new shuffle mode.
};
struct syncPlayStop {
};
struct syncPlayUnpause {
};
}

namespace api 
{
// Notify SyncPlay group that member is buffering.
struct syncPlayBuffering {
public:
    using in_type                      = param::syncPlayBuffering;
    using out_type                     = model::return_type_syncPlayBuffering;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/Buffering"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Create a new SyncPlay group.
struct syncPlayCreateGroup {
public:
    using in_type                      = param::syncPlayCreateGroup;
    using out_type                     = model::return_type_syncPlayCreateGroup;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/New"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Gets all SyncPlay groups.
struct syncPlayGetGroups {
public:
    using in_type                      = param::syncPlayGetGroups;
    using out_type                     = model::return_type_syncPlayGetGroups;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/SyncPlay/List"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;OAIGroupInfoDto&gt;
 * returnFormat: 
 * returnBaseType: OAIGroupInfoDto
 * returnContainer: array
 * baseName: SyncPlay
 * defaultResponse: {}
 */
};
// Join an existing SyncPlay group.
struct syncPlayJoinGroup {
public:
    using in_type                      = param::syncPlayJoinGroup;
    using out_type                     = model::return_type_syncPlayJoinGroup;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/Join"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Leave the joined SyncPlay group.
struct syncPlayLeaveGroup {
public:
    using in_type                      = param::syncPlayLeaveGroup;
    using out_type                     = model::return_type_syncPlayLeaveGroup;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/Leave"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
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
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Request to move an item in the playlist in SyncPlay group.
struct syncPlayMovePlaylistItem {
public:
    using in_type                      = param::syncPlayMovePlaylistItem;
    using out_type                     = model::return_type_syncPlayMovePlaylistItem;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/MovePlaylistItem"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Request next item in SyncPlay group.
struct syncPlayNextItem {
public:
    using in_type                      = param::syncPlayNextItem;
    using out_type                     = model::return_type_syncPlayNextItem;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/NextItem"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Request pause in SyncPlay group.
struct syncPlayPause {
public:
    using in_type                      = param::syncPlayPause;
    using out_type                     = model::return_type_syncPlayPause;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/Pause"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
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
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Update session ping.
struct syncPlayPing {
public:
    using in_type                      = param::syncPlayPing;
    using out_type                     = model::return_type_syncPlayPing;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/Ping"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Request previous item in SyncPlay group.
struct syncPlayPreviousItem {
public:
    using in_type                      = param::syncPlayPreviousItem;
    using out_type                     = model::return_type_syncPlayPreviousItem;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/PreviousItem"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Request to queue items to the playlist of a SyncPlay group.
struct syncPlayQueue {
public:
    using in_type                      = param::syncPlayQueue;
    using out_type                     = model::return_type_syncPlayQueue;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/Queue"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Notify SyncPlay group that member is ready for playback.
struct syncPlayReady {
public:
    using in_type                      = param::syncPlayReady;
    using out_type                     = model::return_type_syncPlayReady;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/Ready"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Request to remove items from the playlist in SyncPlay group.
struct syncPlayRemoveFromPlaylist {
public:
    using in_type                      = param::syncPlayRemoveFromPlaylist;
    using out_type                     = model::return_type_syncPlayRemoveFromPlaylist;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/RemoveFromPlaylist"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Request seek in SyncPlay group.
struct syncPlaySeek {
public:
    using in_type                      = param::syncPlaySeek;
    using out_type                     = model::return_type_syncPlaySeek;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/Seek"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Request SyncPlay group to ignore member during group-wait.
struct syncPlaySetIgnoreWait {
public:
    using in_type                      = param::syncPlaySetIgnoreWait;
    using out_type                     = model::return_type_syncPlaySetIgnoreWait;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/SetIgnoreWait"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Request to set new playlist in SyncPlay group.
struct syncPlaySetNewQueue {
public:
    using in_type                      = param::syncPlaySetNewQueue;
    using out_type                     = model::return_type_syncPlaySetNewQueue;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/SetNewQueue"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Request to change playlist item in SyncPlay group.
struct syncPlaySetPlaylistItem {
public:
    using in_type                      = param::syncPlaySetPlaylistItem;
    using out_type                     = model::return_type_syncPlaySetPlaylistItem;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/SetPlaylistItem"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Request to set repeat mode in SyncPlay group.
struct syncPlaySetRepeatMode {
public:
    using in_type                      = param::syncPlaySetRepeatMode;
    using out_type                     = model::return_type_syncPlaySetRepeatMode;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/SetRepeatMode"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Request to set shuffle mode in SyncPlay group.
struct syncPlaySetShuffleMode {
public:
    using in_type                      = param::syncPlaySetShuffleMode;
    using out_type                     = model::return_type_syncPlaySetShuffleMode;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/SetShuffleMode"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Request stop in SyncPlay group.
struct syncPlayStop {
public:
    using in_type                      = param::syncPlayStop;
    using out_type                     = model::return_type_syncPlayStop;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/Stop"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
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
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
// Request unpause in SyncPlay group.
struct syncPlayUnpause {
public:
    using in_type                      = param::syncPlayUnpause;
    using out_type                     = model::return_type_syncPlayUnpause;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/SyncPlay/Unpause"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
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
 * baseName: SyncPlay
 * defaultResponse: 
 */
};
}
}
