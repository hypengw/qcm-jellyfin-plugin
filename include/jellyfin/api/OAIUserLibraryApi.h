#pragma once
/*
 * OAIUserLibraryApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIBaseItemDto.h"
#include "jellyfin/model/OAIBaseItemDtoQueryResult.h"
#include "jellyfin/model/OAIBaseItemKind.h"
#include "jellyfin/model/OAIImageType.h"
#include "jellyfin/model/OAIItemFields.h"
#include "jellyfin/model/OAIUserItemDataDto.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_deleteUserItemRating = OAIUserItemDataDto;
using return_type_getIntros = OAIBaseItemDtoQueryResult;
using return_type_getItem = OAIBaseItemDto;
using return_type_getLatestMedia = std::vector<OAIBaseItemDto>;
using return_type_getLocalTrailers = std::vector<OAIBaseItemDto>;
using return_type_getRootFolder = OAIBaseItemDto;
using return_type_getSpecialFeatures = std::vector<OAIBaseItemDto>;
using return_type_markFavoriteItem = OAIUserItemDataDto;
using return_type_unmarkFavoriteItem = OAIUserItemDataDto;
using return_type_updateUserItemRating = OAIUserItemDataDto;
}

namespace api::param 
{
struct deleteUserItemRating {
    std::string itemId; // Item id.
    std::optional<std::string> userId; // User id.
};
struct getIntros {
    std::string itemId; // Item id.
    std::optional<std::string> userId; // User id.
};
struct getItem {
    std::string itemId; // Item id.
    std::optional<std::string> userId; // User id.
};
struct getLatestMedia {
    std::optional<std::string> userId; // User id.
    std::optional<std::string> parentId; // Specify this to localize the search to a specific item or folder. Omit to use the root.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<std::vector<OAIBaseItemKind>> includeItemTypes; // Optional. If specified, results will be filtered based on item type. This allows multiple, comma delimited.
    std::optional<bool> isPlayed; // Filter by items that are played, or not.
    std::optional<bool> enableImages; // Optional. include image information in output.
    std::optional<std::int32_t> imageTypeLimit; // Optional. the max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
    std::optional<bool> enableUserData; // Optional. include user data.
    std::optional<std::int32_t> limit; // Return item limit.
    std::optional<bool> groupItems; // Whether or not to group items into a parent container.
};
struct getLocalTrailers {
    std::string itemId; // Item id.
    std::optional<std::string> userId; // User id.
};
struct getRootFolder {
    std::optional<std::string> userId; // User id.
};
struct getSpecialFeatures {
    std::string itemId; // Item id.
    std::optional<std::string> userId; // User id.
};
struct markFavoriteItem {
    std::string itemId; // Item id.
    std::optional<std::string> userId; // User id.
};
struct unmarkFavoriteItem {
    std::string itemId; // Item id.
    std::optional<std::string> userId; // User id.
};
struct updateUserItemRating {
    std::string itemId; // Item id.
    std::optional<std::string> userId; // User id.
    std::optional<bool> likes; // Whether this M:Jellyfin.Api.Controllers.UserLibraryController.UpdateUserItemRating(System.Nullable{System.Guid},System.Guid,System.Nullable{System.Boolean}) is likes.
};
}

namespace api 
{
// Deletes a user&#39;s saved personal rating for an item.
struct deleteUserItemRating {
public:
    using in_type                      = param::deleteUserItemRating;
    using out_type                     = model::return_type_deleteUserItemRating;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/UserItems/{}/Rating"sv,
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
 * baseName: UserLibrary
 * defaultResponse: OAIUserItemDataDto()
 */
};
// Gets intros to play before the main media item plays.
struct getIntros {
public:
    using in_type                      = param::getIntros;
    using out_type                     = model::return_type_getIntros;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/Intros"sv,
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
 * returnType: OAIBaseItemDtoQueryResult
 * returnFormat: 
 * returnBaseType: OAIBaseItemDtoQueryResult
 * returnContainer: 
 * baseName: UserLibrary
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets an item from a user&#39;s library.
struct getItem {
public:
    using in_type                      = param::getItem;
    using out_type                     = model::return_type_getItem;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}"sv,
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
 * returnType: OAIBaseItemDto
 * returnFormat: 
 * returnBaseType: OAIBaseItemDto
 * returnContainer: 
 * baseName: UserLibrary
 * defaultResponse: OAIBaseItemDto()
 */
};
// Gets latest media.
struct getLatestMedia {
public:
    using in_type                      = param::getLatestMedia;
    using out_type                     = model::return_type_getLatestMedia;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Items/Latest"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.parentId)
            p.set_param("parentId", convert_from<std::string>(input.parentId.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.includeItemTypes)
            p.set_param("includeItemTypes", input.includeItemTypes.value());
        if(input.isPlayed)
            p.set_param("isPlayed", convert_from<std::string>(input.isPlayed.value()));
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.groupItems)
            p.set_param("groupItems", convert_from<std::string>(input.groupItems.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;OAIBaseItemDto&gt;
 * returnFormat: 
 * returnBaseType: OAIBaseItemDto
 * returnContainer: array
 * baseName: UserLibrary
 * defaultResponse: {}
 */
};
// Gets local trailers for an item.
struct getLocalTrailers {
public:
    using in_type                      = param::getLocalTrailers;
    using out_type                     = model::return_type_getLocalTrailers;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/LocalTrailers"sv,
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
 * returnType: std::vector&lt;OAIBaseItemDto&gt;
 * returnFormat: 
 * returnBaseType: OAIBaseItemDto
 * returnContainer: array
 * baseName: UserLibrary
 * defaultResponse: {}
 */
};
// Gets the root folder from a user&#39;s library.
struct getRootFolder {
public:
    using in_type                      = param::getRootFolder;
    using out_type                     = model::return_type_getRootFolder;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Items/Root"sv; 
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
 * returnType: OAIBaseItemDto
 * returnFormat: 
 * returnBaseType: OAIBaseItemDto
 * returnContainer: 
 * baseName: UserLibrary
 * defaultResponse: OAIBaseItemDto()
 */
};
// Gets special features for an item.
struct getSpecialFeatures {
public:
    using in_type                      = param::getSpecialFeatures;
    using out_type                     = model::return_type_getSpecialFeatures;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/SpecialFeatures"sv,
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
 * returnType: std::vector&lt;OAIBaseItemDto&gt;
 * returnFormat: 
 * returnBaseType: OAIBaseItemDto
 * returnContainer: array
 * baseName: UserLibrary
 * defaultResponse: {}
 */
};
// Marks an item as a favorite.
struct markFavoriteItem {
public:
    using in_type                      = param::markFavoriteItem;
    using out_type                     = model::return_type_markFavoriteItem;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/UserFavoriteItems/{}"sv,
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
 * baseName: UserLibrary
 * defaultResponse: OAIUserItemDataDto()
 */
};
// Unmarks item as a favorite.
struct unmarkFavoriteItem {
public:
    using in_type                      = param::unmarkFavoriteItem;
    using out_type                     = model::return_type_unmarkFavoriteItem;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/UserFavoriteItems/{}"sv,
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
 * baseName: UserLibrary
 * defaultResponse: OAIUserItemDataDto()
 */
};
// Updates a user&#39;s rating for an item.
struct updateUserItemRating {
public:
    using in_type                      = param::updateUserItemRating;
    using out_type                     = model::return_type_updateUserItemRating;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/UserItems/{}/Rating"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.likes)
            p.set_param("likes", convert_from<std::string>(input.likes.value()));
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
 * baseName: UserLibrary
 * defaultResponse: OAIUserItemDataDto()
 */
};
}
}
