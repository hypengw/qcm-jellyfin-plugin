#pragma once
/*
 * OAITvShowsApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIBaseItemDtoQueryResult.h"
#include "jellyfin/model/OAIImageType.h"
#include "jellyfin/model/OAIItemFields.h"
#include "jellyfin/model/OAIItemSortBy.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getEpisodes = OAIBaseItemDtoQueryResult;
using return_type_getNextUp = OAIBaseItemDtoQueryResult;
using return_type_getSeasons = OAIBaseItemDtoQueryResult;
using return_type_getUpcomingEpisodes = OAIBaseItemDtoQueryResult;
}

namespace api::param 
{
struct getEpisodes {
    std::string seriesId; // The series id.
    std::optional<std::string> userId; // The user id.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output. This allows multiple, comma delimited. Options: Budget, Chapters, DateCreated, Genres, HomePageUrl, IndexOptions, MediaStreams, Overview, ParentId, Path, People, ProviderIds, PrimaryImageAspectRatio, Revenue, SortName, Studios, Taglines, TrailerUrls.
    std::optional<std::int32_t> season; // Optional filter by season number.
    std::optional<std::string> seasonId; // Optional. Filter by season id.
    std::optional<bool> isMissing; // Optional. Filter by items that are missing episodes or not.
    std::optional<std::string> adjacentTo; // Optional. Return items that are siblings of a supplied item.
    std::optional<std::string> startItemId; // Optional. Skip through the list until a given item is found.
    std::optional<std::int32_t> startIndex; // Optional. The record index to start at. All items with a lower index will be dropped from the results.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<bool> enableImages; // Optional, include image information in output.
    std::optional<std::int32_t> imageTypeLimit; // Optional, the max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
    std::optional<bool> enableUserData; // Optional. Include user data.
    std::optional<OAIItemSortBy> sortBy; // Optional. Specify one or more sort orders, comma delimited. Options: Album, AlbumArtist, Artist, Budget, CommunityRating, CriticRating, DateCreated, DatePlayed, PlayCount, PremiereDate, ProductionYear, SortName, Random, Revenue, Runtime.
};
struct getNextUp {
    std::optional<std::string> userId; // The user id of the user to get the next up episodes for.
    std::optional<std::int32_t> startIndex; // Optional. The record index to start at. All items with a lower index will be dropped from the results.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<std::string> seriesId; // Optional. Filter by series id.
    std::optional<std::string> parentId; // Optional. Specify this to localize the search to a specific item or folder. Omit to use the root.
    std::optional<bool> enableImages; // Optional. Include image information in output.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
    std::optional<bool> enableUserData; // Optional. Include user data.
    std::optional<std::string> nextUpDateCutoff; // Optional. Starting date of shows to show in Next Up section.
    std::optional<bool> enableTotalRecordCount; // Whether to enable the total records count. Defaults to true.
    std::optional<bool> disableFirstEpisode; // Whether to disable sending the first episode in a series as next up.
    std::optional<bool> enableResumable; // Whether to include resumable episodes in next up results.
    std::optional<bool> enableRewatching; // Whether to include watched episodes in next up results.
};
struct getSeasons {
    std::string seriesId; // The series id.
    std::optional<std::string> userId; // The user id.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output. This allows multiple, comma delimited. Options: Budget, Chapters, DateCreated, Genres, HomePageUrl, IndexOptions, MediaStreams, Overview, ParentId, Path, People, ProviderIds, PrimaryImageAspectRatio, Revenue, SortName, Studios, Taglines, TrailerUrls.
    std::optional<bool> isSpecialSeason; // Optional. Filter by special season.
    std::optional<bool> isMissing; // Optional. Filter by items that are missing episodes or not.
    std::optional<std::string> adjacentTo; // Optional. Return items that are siblings of a supplied item.
    std::optional<bool> enableImages; // Optional. Include image information in output.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
    std::optional<bool> enableUserData; // Optional. Include user data.
};
struct getUpcomingEpisodes {
    std::optional<std::string> userId; // The user id of the user to get the upcoming episodes for.
    std::optional<std::int32_t> startIndex; // Optional. The record index to start at. All items with a lower index will be dropped from the results.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<std::string> parentId; // Optional. Specify this to localize the search to a specific item or folder. Omit to use the root.
    std::optional<bool> enableImages; // Optional. Include image information in output.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
    std::optional<bool> enableUserData; // Optional. Include user data.
};
}

namespace api 
{
// Gets episodes for a tv season.
struct getEpisodes {
public:
    using in_type                      = param::getEpisodes;
    using out_type                     = model::return_type_getEpisodes;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Shows/{}/Episodes"sv,
            input.seriesId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.season)
            p.set_param("season", convert_from<std::string>(input.season.value()));
        if(input.seasonId)
            p.set_param("seasonId", convert_from<std::string>(input.seasonId.value()));
        if(input.isMissing)
            p.set_param("isMissing", convert_from<std::string>(input.isMissing.value()));
        if(input.adjacentTo)
            p.set_param("adjacentTo", convert_from<std::string>(input.adjacentTo.value()));
        if(input.startItemId)
            p.set_param("startItemId", convert_from<std::string>(input.startItemId.value()));
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.sortBy)
            p.set_param("sortBy", convert_from<std::string>(input.sortBy.value()));
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
 * baseName: TvShows
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets a list of next up episodes.
struct getNextUp {
public:
    using in_type                      = param::getNextUp;
    using out_type                     = model::return_type_getNextUp;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Shows/NextUp"sv; 
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
        if(input.seriesId)
            p.set_param("seriesId", convert_from<std::string>(input.seriesId.value()));
        if(input.parentId)
            p.set_param("parentId", convert_from<std::string>(input.parentId.value()));
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.nextUpDateCutoff)
            p.set_param("nextUpDateCutoff", convert_from<std::string>(input.nextUpDateCutoff.value()));
        if(input.enableTotalRecordCount)
            p.set_param("enableTotalRecordCount", convert_from<std::string>(input.enableTotalRecordCount.value()));
        if(input.disableFirstEpisode)
            p.set_param("disableFirstEpisode", convert_from<std::string>(input.disableFirstEpisode.value()));
        if(input.enableResumable)
            p.set_param("enableResumable", convert_from<std::string>(input.enableResumable.value()));
        if(input.enableRewatching)
            p.set_param("enableRewatching", convert_from<std::string>(input.enableRewatching.value()));
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
 * baseName: TvShows
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets seasons for a tv series.
struct getSeasons {
public:
    using in_type                      = param::getSeasons;
    using out_type                     = model::return_type_getSeasons;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Shows/{}/Seasons"sv,
            input.seriesId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.isSpecialSeason)
            p.set_param("isSpecialSeason", convert_from<std::string>(input.isSpecialSeason.value()));
        if(input.isMissing)
            p.set_param("isMissing", convert_from<std::string>(input.isMissing.value()));
        if(input.adjacentTo)
            p.set_param("adjacentTo", convert_from<std::string>(input.adjacentTo.value()));
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
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
 * baseName: TvShows
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets a list of upcoming episodes.
struct getUpcomingEpisodes {
public:
    using in_type                      = param::getUpcomingEpisodes;
    using out_type                     = model::return_type_getUpcomingEpisodes;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Shows/Upcoming"sv; 
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
        if(input.parentId)
            p.set_param("parentId", convert_from<std::string>(input.parentId.value()));
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
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
 * baseName: TvShows
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
}
}
