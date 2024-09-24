#pragma once
/*
 * OAIArtistsApi.h
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
#include "jellyfin/model/OAIItemFilter.h"
#include "jellyfin/model/OAIItemSortBy.h"
#include "jellyfin/model/OAIMediaType.h"
#include "jellyfin/model/OAISortOrder.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getAlbumArtists = OAIBaseItemDtoQueryResult;
using return_type_getArtistByName = OAIBaseItemDto;
using return_type_getArtists = OAIBaseItemDtoQueryResult;
}

namespace api::param 
{
struct getAlbumArtists {
    std::optional<double> minCommunityRating; // Optional filter by minimum community rating.
    std::optional<std::int32_t> startIndex; // Optional. The record index to start at. All items with a lower index will be dropped from the results.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::string> searchTerm; // Optional. Search term.
    std::optional<std::string> parentId; // Specify this to localize the search to a specific item or folder. Omit to use the root.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<std::vector<OAIBaseItemKind>> excludeItemTypes; // Optional. If specified, results will be filtered out based on item type. This allows multiple, comma delimited.
    std::optional<std::vector<OAIBaseItemKind>> includeItemTypes; // Optional. If specified, results will be filtered based on item type. This allows multiple, comma delimited.
    std::optional<std::vector<OAIItemFilter>> filters; // Optional. Specify additional filters to apply.
    std::optional<bool> isFavorite; // Optional filter by items that are marked as favorite, or not.
    std::optional<std::vector<OAIMediaType>> mediaTypes; // Optional filter by MediaType. Allows multiple, comma delimited.
    std::optional<std::vector<std::string>> genres; // Optional. If specified, results will be filtered based on genre. This allows multiple, pipe delimited.
    std::optional<std::vector<std::string>> genreIds; // Optional. If specified, results will be filtered based on genre id. This allows multiple, pipe delimited.
    std::optional<std::vector<std::string>> officialRatings; // Optional. If specified, results will be filtered based on OfficialRating. This allows multiple, pipe delimited.
    std::optional<std::vector<std::string>> tags; // Optional. If specified, results will be filtered based on tag. This allows multiple, pipe delimited.
    std::optional<std::vector<std::int32_t>> years; // Optional. If specified, results will be filtered based on production year. This allows multiple, comma delimited.
    std::optional<bool> enableUserData; // Optional, include user data.
    std::optional<std::int32_t> imageTypeLimit; // Optional, the max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
    std::optional<std::string> person; // Optional. If specified, results will be filtered to include only those containing the specified person.
    std::optional<std::vector<std::string>> personIds; // Optional. If specified, results will be filtered to include only those containing the specified person ids.
    std::optional<std::vector<std::string>> personTypes; // Optional. If specified, along with Person, results will be filtered to include only those containing the specified person and PersonType. Allows multiple, comma-delimited.
    std::optional<std::vector<std::string>> studios; // Optional. If specified, results will be filtered based on studio. This allows multiple, pipe delimited.
    std::optional<std::vector<std::string>> studioIds; // Optional. If specified, results will be filtered based on studio id. This allows multiple, pipe delimited.
    std::optional<std::string> userId; // User id.
    std::optional<std::string> nameStartsWithOrGreater; // Optional filter by items whose name is sorted equally or greater than a given input string.
    std::optional<std::string> nameStartsWith; // Optional filter by items whose name is sorted equally than a given input string.
    std::optional<std::string> nameLessThan; // Optional filter by items whose name is equally or lesser than a given input string.
    std::optional<std::vector<OAIItemSortBy>> sortBy; // Optional. Specify one or more sort orders, comma delimited.
    std::optional<std::vector<OAISortOrder>> sortOrder; // Sort Order - Ascending,Descending.
    std::optional<bool> enableImages; // Optional, include image information in output.
    std::optional<bool> enableTotalRecordCount; // Total record count.
};
struct getArtistByName {
    std::string name; // Studio name.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
};
struct getArtists {
    std::optional<double> minCommunityRating; // Optional filter by minimum community rating.
    std::optional<std::int32_t> startIndex; // Optional. The record index to start at. All items with a lower index will be dropped from the results.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::string> searchTerm; // Optional. Search term.
    std::optional<std::string> parentId; // Specify this to localize the search to a specific item or folder. Omit to use the root.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<std::vector<OAIBaseItemKind>> excludeItemTypes; // Optional. If specified, results will be filtered out based on item type. This allows multiple, comma delimited.
    std::optional<std::vector<OAIBaseItemKind>> includeItemTypes; // Optional. If specified, results will be filtered based on item type. This allows multiple, comma delimited.
    std::optional<std::vector<OAIItemFilter>> filters; // Optional. Specify additional filters to apply.
    std::optional<bool> isFavorite; // Optional filter by items that are marked as favorite, or not.
    std::optional<std::vector<OAIMediaType>> mediaTypes; // Optional filter by MediaType. Allows multiple, comma delimited.
    std::optional<std::vector<std::string>> genres; // Optional. If specified, results will be filtered based on genre. This allows multiple, pipe delimited.
    std::optional<std::vector<std::string>> genreIds; // Optional. If specified, results will be filtered based on genre id. This allows multiple, pipe delimited.
    std::optional<std::vector<std::string>> officialRatings; // Optional. If specified, results will be filtered based on OfficialRating. This allows multiple, pipe delimited.
    std::optional<std::vector<std::string>> tags; // Optional. If specified, results will be filtered based on tag. This allows multiple, pipe delimited.
    std::optional<std::vector<std::int32_t>> years; // Optional. If specified, results will be filtered based on production year. This allows multiple, comma delimited.
    std::optional<bool> enableUserData; // Optional, include user data.
    std::optional<std::int32_t> imageTypeLimit; // Optional, the max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
    std::optional<std::string> person; // Optional. If specified, results will be filtered to include only those containing the specified person.
    std::optional<std::vector<std::string>> personIds; // Optional. If specified, results will be filtered to include only those containing the specified person ids.
    std::optional<std::vector<std::string>> personTypes; // Optional. If specified, along with Person, results will be filtered to include only those containing the specified person and PersonType. Allows multiple, comma-delimited.
    std::optional<std::vector<std::string>> studios; // Optional. If specified, results will be filtered based on studio. This allows multiple, pipe delimited.
    std::optional<std::vector<std::string>> studioIds; // Optional. If specified, results will be filtered based on studio id. This allows multiple, pipe delimited.
    std::optional<std::string> userId; // User id.
    std::optional<std::string> nameStartsWithOrGreater; // Optional filter by items whose name is sorted equally or greater than a given input string.
    std::optional<std::string> nameStartsWith; // Optional filter by items whose name is sorted equally than a given input string.
    std::optional<std::string> nameLessThan; // Optional filter by items whose name is equally or lesser than a given input string.
    std::optional<std::vector<OAIItemSortBy>> sortBy; // Optional. Specify one or more sort orders, comma delimited.
    std::optional<std::vector<OAISortOrder>> sortOrder; // Sort Order - Ascending,Descending.
    std::optional<bool> enableImages; // Optional, include image information in output.
    std::optional<bool> enableTotalRecordCount; // Total record count.
};
}

namespace api 
{
// Gets all album artists from a given item, folder, or the entire library.
struct getAlbumArtists {
public:
    using in_type                      = param::getAlbumArtists;
    using out_type                     = model::return_type_getAlbumArtists;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Artists/AlbumArtists"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.minCommunityRating)
            p.set_param("minCommunityRating", convert_from<std::string>(input.minCommunityRating.value()));
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.searchTerm)
            p.set_param("searchTerm", convert_from<std::string>(input.searchTerm.value()));
        if(input.parentId)
            p.set_param("parentId", convert_from<std::string>(input.parentId.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.excludeItemTypes)
            p.set_param("excludeItemTypes", input.excludeItemTypes.value());
        if(input.includeItemTypes)
            p.set_param("includeItemTypes", input.includeItemTypes.value());
        if(input.filters)
            p.set_param("filters", input.filters.value());
        if(input.isFavorite)
            p.set_param("isFavorite", convert_from<std::string>(input.isFavorite.value()));
        if(input.mediaTypes)
            p.set_param("mediaTypes", input.mediaTypes.value());
        if(input.genres)
            p.set_param("genres", input.genres.value());
        if(input.genreIds)
            p.set_param("genreIds", input.genreIds.value());
        if(input.officialRatings)
            p.set_param("officialRatings", input.officialRatings.value());
        if(input.tags)
            p.set_param("tags", input.tags.value());
        if(input.years)
            p.set_param("years", input.years.value());
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
        if(input.person)
            p.set_param("person", convert_from<std::string>(input.person.value()));
        if(input.personIds)
            p.set_param("personIds", input.personIds.value());
        if(input.personTypes)
            p.set_param("personTypes", input.personTypes.value());
        if(input.studios)
            p.set_param("studios", input.studios.value());
        if(input.studioIds)
            p.set_param("studioIds", input.studioIds.value());
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.nameStartsWithOrGreater)
            p.set_param("nameStartsWithOrGreater", convert_from<std::string>(input.nameStartsWithOrGreater.value()));
        if(input.nameStartsWith)
            p.set_param("nameStartsWith", convert_from<std::string>(input.nameStartsWith.value()));
        if(input.nameLessThan)
            p.set_param("nameLessThan", convert_from<std::string>(input.nameLessThan.value()));
        if(input.sortBy)
            p.set_param("sortBy", input.sortBy.value());
        if(input.sortOrder)
            p.set_param("sortOrder", input.sortOrder.value());
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.enableTotalRecordCount)
            p.set_param("enableTotalRecordCount", convert_from<std::string>(input.enableTotalRecordCount.value()));
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
 * baseName: Artists
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets an artist by name.
struct getArtistByName {
public:
    using in_type                      = param::getArtistByName;
    using out_type                     = model::return_type_getArtistByName;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Artists/{}"sv,
            input.name
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
 * baseName: Artists
 * defaultResponse: OAIBaseItemDto()
 */
};
// Gets all artists from a given item, folder, or the entire library.
struct getArtists {
public:
    using in_type                      = param::getArtists;
    using out_type                     = model::return_type_getArtists;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Artists"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.minCommunityRating)
            p.set_param("minCommunityRating", convert_from<std::string>(input.minCommunityRating.value()));
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.searchTerm)
            p.set_param("searchTerm", convert_from<std::string>(input.searchTerm.value()));
        if(input.parentId)
            p.set_param("parentId", convert_from<std::string>(input.parentId.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.excludeItemTypes)
            p.set_param("excludeItemTypes", input.excludeItemTypes.value());
        if(input.includeItemTypes)
            p.set_param("includeItemTypes", input.includeItemTypes.value());
        if(input.filters)
            p.set_param("filters", input.filters.value());
        if(input.isFavorite)
            p.set_param("isFavorite", convert_from<std::string>(input.isFavorite.value()));
        if(input.mediaTypes)
            p.set_param("mediaTypes", input.mediaTypes.value());
        if(input.genres)
            p.set_param("genres", input.genres.value());
        if(input.genreIds)
            p.set_param("genreIds", input.genreIds.value());
        if(input.officialRatings)
            p.set_param("officialRatings", input.officialRatings.value());
        if(input.tags)
            p.set_param("tags", input.tags.value());
        if(input.years)
            p.set_param("years", input.years.value());
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
        if(input.person)
            p.set_param("person", convert_from<std::string>(input.person.value()));
        if(input.personIds)
            p.set_param("personIds", input.personIds.value());
        if(input.personTypes)
            p.set_param("personTypes", input.personTypes.value());
        if(input.studios)
            p.set_param("studios", input.studios.value());
        if(input.studioIds)
            p.set_param("studioIds", input.studioIds.value());
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.nameStartsWithOrGreater)
            p.set_param("nameStartsWithOrGreater", convert_from<std::string>(input.nameStartsWithOrGreater.value()));
        if(input.nameStartsWith)
            p.set_param("nameStartsWith", convert_from<std::string>(input.nameStartsWith.value()));
        if(input.nameLessThan)
            p.set_param("nameLessThan", convert_from<std::string>(input.nameLessThan.value()));
        if(input.sortBy)
            p.set_param("sortBy", input.sortBy.value());
        if(input.sortOrder)
            p.set_param("sortOrder", input.sortOrder.value());
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.enableTotalRecordCount)
            p.set_param("enableTotalRecordCount", convert_from<std::string>(input.enableTotalRecordCount.value()));
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
 * baseName: Artists
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
}
}
