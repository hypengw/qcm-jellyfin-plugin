#pragma once
/*
 * OAIPlaylistsApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIBaseItemDtoQueryResult.h"
#include "jellyfin/model/OAICreatePlaylistDto.h"
#include "jellyfin/model/OAIImageType.h"
#include "jellyfin/model/OAIItemFields.h"
#include "jellyfin/model/OAIMediaType.h"
#include "jellyfin/model/OAIPlaylistCreationResult.h"
#include "jellyfin/model/OAIPlaylistUserPermissions.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAIUpdatePlaylistDto.h"
#include "jellyfin/model/OAIUpdatePlaylistUserDto.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_addItemToPlaylist = std::nullptr_t;
using return_type_createPlaylist = OAIPlaylistCreationResult;
using return_type_getPlaylistItems = OAIBaseItemDtoQueryResult;
using return_type_getPlaylistUser = OAIPlaylistUserPermissions;
using return_type_getPlaylistUsers = std::vector<OAIPlaylistUserPermissions>;
using return_type_moveItem = std::nullptr_t;
using return_type_removeItemFromPlaylist = std::nullptr_t;
using return_type_removeUserFromPlaylist = std::nullptr_t;
using return_type_updatePlaylist = std::nullptr_t;
using return_type_updatePlaylistUser = std::nullptr_t;
}

namespace api::param 
{
struct addItemToPlaylist {
    std::string playlistId; // The playlist id.
    std::optional<std::vector<std::string>> ids; // Item id, comma delimited.
    std::optional<std::string> userId; // The userId.
};
struct createPlaylist {
    std::optional<std::string> name; // The playlist name.
    std::optional<std::vector<std::string>> ids; // The item ids.
    std::optional<std::string> userId; // The user id.
    std::optional<OAIMediaType> mediaType; // The media type.
    std::optional<OAICreatePlaylistDto> body; // The create playlist payload.
};
struct getPlaylistItems {
    std::string playlistId; // The playlist id.
    std::optional<std::string> userId; // User id.
    std::optional<std::int32_t> startIndex; // Optional. The record index to start at. All items with a lower index will be dropped from the results.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<bool> enableImages; // Optional. Include image information in output.
    std::optional<bool> enableUserData; // Optional. Include user data.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
};
struct getPlaylistUser {
    std::string playlistId; // The playlist id.
    std::string userId; // The user id.
};
struct getPlaylistUsers {
    std::string playlistId; // The playlist id.
};
struct moveItem {
    std::string playlistId; // The playlist id.
    std::string itemId; // The item id.
    std::int32_t newIndex; // The new index.
};
struct removeItemFromPlaylist {
    std::string playlistId; // The playlist id.
    std::optional<std::vector<std::string>> entryIds; // The item ids, comma delimited.
};
struct removeUserFromPlaylist {
    std::string playlistId; // The playlist id.
    std::string userId; // The user id.
};
struct updatePlaylist {
    std::string playlistId; // The playlist id.
    OAIUpdatePlaylistDto body; // The Jellyfin.Api.Models.PlaylistDtos.UpdatePlaylistDto id.
};
struct updatePlaylistUser {
    std::string playlistId; // The playlist id.
    std::string userId; // The user id.
    OAIUpdatePlaylistUserDto body; // The Jellyfin.Api.Models.PlaylistDtos.UpdatePlaylistUserDto.
};
}

namespace api 
{
// Adds items to a playlist.
struct addItemToPlaylist {
public:
    using in_type                      = param::addItemToPlaylist;
    using out_type                     = model::return_type_addItemToPlaylist;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Playlists/{}/Items"sv,
            input.playlistId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.ids)
            p.set_param("ids", input.ids.value());
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
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Playlists
 * defaultResponse: 
 */
};
// Creates a new playlist.
struct createPlaylist {
public:
    using in_type                      = param::createPlaylist;
    using out_type                     = model::return_type_createPlaylist;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Playlists"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.name)
            p.set_param("name", convert_from<std::string>(input.name.value()));
        if(input.ids)
            p.set_param("ids", input.ids.value());
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.mediaType)
            p.set_param("mediaType", convert_from<std::string>(input.mediaType.value()));
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
 * returnType: OAIPlaylistCreationResult
 * returnFormat: 
 * returnBaseType: OAIPlaylistCreationResult
 * returnContainer: 
 * baseName: Playlists
 * defaultResponse: OAIPlaylistCreationResult()
 */
};
// Gets the original items of a playlist.
struct getPlaylistItems {
public:
    using in_type                      = param::getPlaylistItems;
    using out_type                     = model::return_type_getPlaylistItems;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Playlists/{}/Items"sv,
            input.playlistId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIBaseItemDtoQueryResult
 * returnFormat: 
 * returnBaseType: OAIBaseItemDtoQueryResult
 * returnContainer: 
 * baseName: Playlists
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Get a playlist user.
struct getPlaylistUser {
public:
    using in_type                      = param::getPlaylistUser;
    using out_type                     = model::return_type_getPlaylistUser;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Playlists/{}/Users/{}"sv,
            input.playlistId,
            input.userId
        );
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
 * returnType: OAIPlaylistUserPermissions
 * returnFormat: 
 * returnBaseType: OAIPlaylistUserPermissions
 * returnContainer: 
 * baseName: Playlists
 * defaultResponse: OAIPlaylistUserPermissions()
 */
};
// Get a playlist&#39;s users.
struct getPlaylistUsers {
public:
    using in_type                      = param::getPlaylistUsers;
    using out_type                     = model::return_type_getPlaylistUsers;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Playlists/{}/Users"sv,
            input.playlistId
        );
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
 * returnType: std::vector&lt;OAIPlaylistUserPermissions&gt;
 * returnFormat: 
 * returnBaseType: OAIPlaylistUserPermissions
 * returnContainer: array
 * baseName: Playlists
 * defaultResponse: {}
 */
};
// Moves a playlist item.
struct moveItem {
public:
    using in_type                      = param::moveItem;
    using out_type                     = model::return_type_moveItem;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Playlists/{}/Items/{}/Move/{}"sv,
            input.playlistId,
            input.itemId,
            input.newIndex
        );
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
 * baseName: Playlists
 * defaultResponse: 
 */
};
// Removes items from a playlist.
struct removeItemFromPlaylist {
public:
    using in_type                      = param::removeItemFromPlaylist;
    using out_type                     = model::return_type_removeItemFromPlaylist;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/Playlists/{}/Items"sv,
            input.playlistId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.entryIds)
            p.set_param("entryIds", input.entryIds.value());
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
 * baseName: Playlists
 * defaultResponse: 
 */
};
// Remove a user from a playlist&#39;s users.
struct removeUserFromPlaylist {
public:
    using in_type                      = param::removeUserFromPlaylist;
    using out_type                     = model::return_type_removeUserFromPlaylist;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/Playlists/{}/Users/{}"sv,
            input.playlistId,
            input.userId
        );
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
 * baseName: Playlists
 * defaultResponse: 
 */
};
// Updates a playlist.
struct updatePlaylist {
public:
    using in_type                      = param::updatePlaylist;
    using out_type                     = model::return_type_updatePlaylist;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Playlists/{}"sv,
            input.playlistId
        );
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
 * baseName: Playlists
 * defaultResponse: 
 */
};
// Modify a user of a playlist&#39;s users.
struct updatePlaylistUser {
public:
    using in_type                      = param::updatePlaylistUser;
    using out_type                     = model::return_type_updatePlaylistUser;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Playlists/{}/Users/{}"sv,
            input.playlistId,
            input.userId
        );
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
 * baseName: Playlists
 * defaultResponse: 
 */
};
}
}
