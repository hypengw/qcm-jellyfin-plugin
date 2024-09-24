#pragma once
/*
 * OAIChannelsApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIBaseItemDtoQueryResult.h"
#include "jellyfin/model/OAIChannelFeatures.h"
#include "jellyfin/model/OAIItemFields.h"
#include "jellyfin/model/OAIItemFilter.h"
#include "jellyfin/model/OAIItemSortBy.h"
#include "jellyfin/model/OAISortOrder.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getAllChannelFeatures = std::vector<OAIChannelFeatures>;
using return_type_getChannelFeatures = OAIChannelFeatures;
using return_type_getChannelItems = OAIBaseItemDtoQueryResult;
using return_type_getChannels = OAIBaseItemDtoQueryResult;
using return_type_getLatestChannelItems = OAIBaseItemDtoQueryResult;
}

namespace api::param 
{
struct getAllChannelFeatures {
};
struct getChannelFeatures {
    std::string channelId; // Channel id.
};
struct getChannelItems {
    std::string channelId; // Channel Id.
    std::optional<std::string> folderId; // Optional. Folder Id.
    std::optional<std::string> userId; // Optional. User Id.
    std::optional<std::int32_t> startIndex; // Optional. The record index to start at. All items with a lower index will be dropped from the results.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAISortOrder>> sortOrder; // Optional. Sort Order - Ascending,Descending.
    std::optional<std::vector<OAIItemFilter>> filters; // Optional. Specify additional filters to apply.
    std::optional<std::vector<OAIItemSortBy>> sortBy; // Optional. Specify one or more sort orders, comma delimited. Options: Album, AlbumArtist, Artist, Budget, CommunityRating, CriticRating, DateCreated, DatePlayed, PlayCount, PremiereDate, ProductionYear, SortName, Random, Revenue, Runtime.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
};
struct getChannels {
    std::optional<std::string> userId; // User Id to filter by. Use System.Guid.Empty to not filter by user.
    std::optional<std::int32_t> startIndex; // Optional. The record index to start at. All items with a lower index will be dropped from the results.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<bool> supportsLatestItems; // Optional. Filter by channels that support getting latest items.
    std::optional<bool> supportsMediaDeletion; // Optional. Filter by channels that support media deletion.
    std::optional<bool> isFavorite; // Optional. Filter by channels that are favorite.
};
struct getLatestChannelItems {
    std::optional<std::string> userId; // Optional. User Id.
    std::optional<std::int32_t> startIndex; // Optional. The record index to start at. All items with a lower index will be dropped from the results.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemFilter>> filters; // Optional. Specify additional filters to apply.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<std::vector<std::string>> channelIds; // Optional. Specify one or more channel id&#39;s, comma delimited.
};
}

namespace api 
{
// Get all channel features.
struct getAllChannelFeatures {
public:
    using in_type                      = param::getAllChannelFeatures;
    using out_type                     = model::return_type_getAllChannelFeatures;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Channels/Features"sv; 
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
 * returnType: std::vector&lt;OAIChannelFeatures&gt;
 * returnFormat: 
 * returnBaseType: OAIChannelFeatures
 * returnContainer: array
 * baseName: Channels
 * defaultResponse: {}
 */
};
// Get channel features.
struct getChannelFeatures {
public:
    using in_type                      = param::getChannelFeatures;
    using out_type                     = model::return_type_getChannelFeatures;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Channels/{}/Features"sv,
            input.channelId
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
 * returnType: OAIChannelFeatures
 * returnFormat: 
 * returnBaseType: OAIChannelFeatures
 * returnContainer: 
 * baseName: Channels
 * defaultResponse: OAIChannelFeatures()
 */
};
// Get channel items.
struct getChannelItems {
public:
    using in_type                      = param::getChannelItems;
    using out_type                     = model::return_type_getChannelItems;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Channels/{}/Items"sv,
            input.channelId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.folderId)
            p.set_param("folderId", convert_from<std::string>(input.folderId.value()));
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.sortOrder)
            p.set_param("sortOrder", input.sortOrder.value());
        if(input.filters)
            p.set_param("filters", input.filters.value());
        if(input.sortBy)
            p.set_param("sortBy", input.sortBy.value());
        if(input.fields)
            p.set_param("fields", input.fields.value());
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
 * baseName: Channels
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets available channels.
struct getChannels {
public:
    using in_type                      = param::getChannels;
    using out_type                     = model::return_type_getChannels;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Channels"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.supportsLatestItems)
            p.set_param("supportsLatestItems", convert_from<std::string>(input.supportsLatestItems.value()));
        if(input.supportsMediaDeletion)
            p.set_param("supportsMediaDeletion", convert_from<std::string>(input.supportsMediaDeletion.value()));
        if(input.isFavorite)
            p.set_param("isFavorite", convert_from<std::string>(input.isFavorite.value()));
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
 * baseName: Channels
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets latest channel items.
struct getLatestChannelItems {
public:
    using in_type                      = param::getLatestChannelItems;
    using out_type                     = model::return_type_getLatestChannelItems;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Channels/Items/Latest"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.filters)
            p.set_param("filters", input.filters.value());
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.channelIds)
            p.set_param("channelIds", input.channelIds.value());
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
 * baseName: Channels
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
}
}
