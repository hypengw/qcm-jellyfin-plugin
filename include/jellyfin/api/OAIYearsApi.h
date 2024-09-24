#pragma once
/*
 * OAIYearsApi.h
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
#include "jellyfin/model/OAIMediaType.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAISortOrder.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getYear = OAIBaseItemDto;
using return_type_getYears = OAIBaseItemDtoQueryResult;
}

namespace api::param 
{
struct getYear {
    std::int32_t year; // The year.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
};
struct getYears {
    std::optional<std::int32_t> startIndex; // Skips over a given number of items within the results. Use for paging.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAISortOrder>> sortOrder; // Sort Order - Ascending,Descending.
    std::optional<std::string> parentId; // Specify this to localize the search to a specific item or folder. Omit to use the root.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<std::vector<OAIBaseItemKind>> excludeItemTypes; // Optional. If specified, results will be excluded based on item type. This allows multiple, comma delimited.
    std::optional<std::vector<OAIBaseItemKind>> includeItemTypes; // Optional. If specified, results will be included based on item type. This allows multiple, comma delimited.
    std::optional<std::vector<OAIMediaType>> mediaTypes; // Optional. Filter by MediaType. Allows multiple, comma delimited.
    std::optional<std::vector<OAIItemSortBy>> sortBy; // Optional. Specify one or more sort orders, comma delimited. Options: Album, AlbumArtist, Artist, Budget, CommunityRating, CriticRating, DateCreated, DatePlayed, PlayCount, PremiereDate, ProductionYear, SortName, Random, Revenue, Runtime.
    std::optional<bool> enableUserData; // Optional. Include user data.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
    std::optional<std::string> userId; // User Id.
    std::optional<bool> recursive; // Search recursively.
    std::optional<bool> enableImages; // Optional. Include image information in output.
};
}

namespace api 
{
// Gets a year.
struct getYear {
public:
    using in_type                      = param::getYear;
    using out_type                     = model::return_type_getYear;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Years/{}"sv,
            input.year
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
 * baseName: Years
 * defaultResponse: OAIBaseItemDto()
 */
};
// Get years.
struct getYears {
public:
    using in_type                      = param::getYears;
    using out_type                     = model::return_type_getYears;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Years"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.sortOrder)
            p.set_param("sortOrder", input.sortOrder.value());
        if(input.parentId)
            p.set_param("parentId", convert_from<std::string>(input.parentId.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.excludeItemTypes)
            p.set_param("excludeItemTypes", input.excludeItemTypes.value());
        if(input.includeItemTypes)
            p.set_param("includeItemTypes", input.includeItemTypes.value());
        if(input.mediaTypes)
            p.set_param("mediaTypes", input.mediaTypes.value());
        if(input.sortBy)
            p.set_param("sortBy", input.sortBy.value());
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.recursive)
            p.set_param("recursive", convert_from<std::string>(input.recursive.value()));
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
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
 * baseName: Years
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
}
}
