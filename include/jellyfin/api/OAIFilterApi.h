#pragma once
/*
 * OAIFilterApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIBaseItemKind.h"
#include "jellyfin/model/OAIMediaType.h"
#include "jellyfin/model/OAIQueryFilters.h"
#include "jellyfin/model/OAIQueryFiltersLegacy.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getQueryFilters = OAIQueryFilters;
using return_type_getQueryFiltersLegacy = OAIQueryFiltersLegacy;
}

namespace api::param 
{
struct getQueryFilters {
    std::optional<std::string> userId; // Optional. User id.
    std::optional<std::string> parentId; // Optional. Specify this to localize the search to a specific item or folder. Omit to use the root.
    std::optional<std::vector<OAIBaseItemKind>> includeItemTypes; // Optional. If specified, results will be filtered based on item type. This allows multiple, comma delimited.
    std::optional<bool> isAiring; // Optional. Is item airing.
    std::optional<bool> isMovie; // Optional. Is item movie.
    std::optional<bool> isSports; // Optional. Is item sports.
    std::optional<bool> isKids; // Optional. Is item kids.
    std::optional<bool> isNews; // Optional. Is item news.
    std::optional<bool> isSeries; // Optional. Is item series.
    std::optional<bool> recursive; // Optional. Search recursive.
};
struct getQueryFiltersLegacy {
    std::optional<std::string> userId; // Optional. User id.
    std::optional<std::string> parentId; // Optional. Parent id.
    std::optional<std::vector<OAIBaseItemKind>> includeItemTypes; // Optional. If specified, results will be filtered based on item type. This allows multiple, comma delimited.
    std::optional<std::vector<OAIMediaType>> mediaTypes; // Optional. Filter by MediaType. Allows multiple, comma delimited.
};
}

namespace api 
{
// Gets query filters.
struct getQueryFilters {
public:
    using in_type                      = param::getQueryFilters;
    using out_type                     = model::return_type_getQueryFilters;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Items/Filters2"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.parentId)
            p.set_param("parentId", convert_from<std::string>(input.parentId.value()));
        if(input.includeItemTypes)
            p.set_param("includeItemTypes", input.includeItemTypes.value());
        if(input.isAiring)
            p.set_param("isAiring", convert_from<std::string>(input.isAiring.value()));
        if(input.isMovie)
            p.set_param("isMovie", convert_from<std::string>(input.isMovie.value()));
        if(input.isSports)
            p.set_param("isSports", convert_from<std::string>(input.isSports.value()));
        if(input.isKids)
            p.set_param("isKids", convert_from<std::string>(input.isKids.value()));
        if(input.isNews)
            p.set_param("isNews", convert_from<std::string>(input.isNews.value()));
        if(input.isSeries)
            p.set_param("isSeries", convert_from<std::string>(input.isSeries.value()));
        if(input.recursive)
            p.set_param("recursive", convert_from<std::string>(input.recursive.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIQueryFilters
 * returnFormat: 
 * returnBaseType: OAIQueryFilters
 * returnContainer: 
 * baseName: Filter
 * defaultResponse: OAIQueryFilters()
 */
};
// Gets legacy query filters.
struct getQueryFiltersLegacy {
public:
    using in_type                      = param::getQueryFiltersLegacy;
    using out_type                     = model::return_type_getQueryFiltersLegacy;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Items/Filters"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.parentId)
            p.set_param("parentId", convert_from<std::string>(input.parentId.value()));
        if(input.includeItemTypes)
            p.set_param("includeItemTypes", input.includeItemTypes.value());
        if(input.mediaTypes)
            p.set_param("mediaTypes", input.mediaTypes.value());
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIQueryFiltersLegacy
 * returnFormat: 
 * returnBaseType: OAIQueryFiltersLegacy
 * returnContainer: 
 * baseName: Filter
 * defaultResponse: OAIQueryFiltersLegacy()
 */
};
}
}
