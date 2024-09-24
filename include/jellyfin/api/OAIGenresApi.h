#pragma once
/*
 * OAIGenresApi.h
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
#include "jellyfin/model/OAIItemSortBy.h"
#include "jellyfin/model/OAISortOrder.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getGenre = OAIBaseItemDto;
using return_type_getGenres = OAIBaseItemDtoQueryResult;
}

namespace api::param 
{
struct getGenre {
    std::string genreName; // The genre name.
    std::optional<std::string> userId; // The user id.
};
struct getGenres {
    std::optional<std::int32_t> startIndex; // Optional. The record index to start at. All items with a lower index will be dropped from the results.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::string> searchTerm; // The search term.
    std::optional<std::string> parentId; // Specify this to localize the search to a specific item or folder. Omit to use the root.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<std::vector<OAIBaseItemKind>> excludeItemTypes; // Optional. If specified, results will be filtered out based on item type. This allows multiple, comma delimited.
    std::optional<std::vector<OAIBaseItemKind>> includeItemTypes; // Optional. If specified, results will be filtered in based on item type. This allows multiple, comma delimited.
    std::optional<bool> isFavorite; // Optional filter by items that are marked as favorite, or not.
    std::optional<std::int32_t> imageTypeLimit; // Optional, the max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
    std::optional<std::string> userId; // User id.
    std::optional<std::string> nameStartsWithOrGreater; // Optional filter by items whose name is sorted equally or greater than a given input string.
    std::optional<std::string> nameStartsWith; // Optional filter by items whose name is sorted equally than a given input string.
    std::optional<std::string> nameLessThan; // Optional filter by items whose name is equally or lesser than a given input string.
    std::optional<std::vector<OAIItemSortBy>> sortBy; // Optional. Specify one or more sort orders, comma delimited.
    std::optional<std::vector<OAISortOrder>> sortOrder; // Sort Order - Ascending,Descending.
    std::optional<bool> enableImages; // Optional, include image information in output.
    std::optional<bool> enableTotalRecordCount; // Optional. Include total record count.
};
}

namespace api 
{
// Gets a genre, by name.
struct getGenre {
public:
    using in_type                      = param::getGenre;
    using out_type                     = model::return_type_getGenre;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Genres/{}"sv,
            input.genreName
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
 * baseName: Genres
 * defaultResponse: OAIBaseItemDto()
 */
};
// Gets all genres from a given item, folder, or the entire library.
struct getGenres {
public:
    using in_type                      = param::getGenres;
    using out_type                     = model::return_type_getGenres;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Genres"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
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
        if(input.isFavorite)
            p.set_param("isFavorite", convert_from<std::string>(input.isFavorite.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
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
 * baseName: Genres
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
}
}
