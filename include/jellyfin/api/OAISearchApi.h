#pragma once
/*
 * OAISearchApi.h
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
#include "jellyfin/model/OAISearchHintResult.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getSearchHints = OAISearchHintResult;
}

namespace api::param 
{
struct getSearchHints {
    std::string searchTerm; // The search term to filter on.
    std::optional<std::int32_t> startIndex; // Optional. The record index to start at. All items with a lower index will be dropped from the results.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::string> userId; // Optional. Supply a user id to search within a user&#39;s library or omit to search all.
    std::optional<std::vector<OAIBaseItemKind>> includeItemTypes; // If specified, only results with the specified item types are returned. This allows multiple, comma delimited.
    std::optional<std::vector<OAIBaseItemKind>> excludeItemTypes; // If specified, results with these item types are filtered out. This allows multiple, comma delimited.
    std::optional<std::vector<OAIMediaType>> mediaTypes; // If specified, only results with the specified media types are returned. This allows multiple, comma delimited.
    std::optional<std::string> parentId; // If specified, only children of the parent are returned.
    std::optional<bool> isMovie; // Optional filter for movies.
    std::optional<bool> isSeries; // Optional filter for series.
    std::optional<bool> isNews; // Optional filter for news.
    std::optional<bool> isKids; // Optional filter for kids.
    std::optional<bool> isSports; // Optional filter for sports.
    std::optional<bool> includePeople; // Optional filter whether to include people.
    std::optional<bool> includeMedia; // Optional filter whether to include media.
    std::optional<bool> includeGenres; // Optional filter whether to include genres.
    std::optional<bool> includeStudios; // Optional filter whether to include studios.
    std::optional<bool> includeArtists; // Optional filter whether to include artists.
};
}

namespace api 
{
// Gets the search hint result.
struct getSearchHints {
public:
    using in_type                      = param::getSearchHints;
    using out_type                     = model::return_type_getSearchHints;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Search/Hints"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        p.set_param("searchTerm", convert_from<std::string>(input.searchTerm));
        if(input.includeItemTypes)
            p.set_param("includeItemTypes", input.includeItemTypes.value());
        if(input.excludeItemTypes)
            p.set_param("excludeItemTypes", input.excludeItemTypes.value());
        if(input.mediaTypes)
            p.set_param("mediaTypes", input.mediaTypes.value());
        if(input.parentId)
            p.set_param("parentId", convert_from<std::string>(input.parentId.value()));
        if(input.isMovie)
            p.set_param("isMovie", convert_from<std::string>(input.isMovie.value()));
        if(input.isSeries)
            p.set_param("isSeries", convert_from<std::string>(input.isSeries.value()));
        if(input.isNews)
            p.set_param("isNews", convert_from<std::string>(input.isNews.value()));
        if(input.isKids)
            p.set_param("isKids", convert_from<std::string>(input.isKids.value()));
        if(input.isSports)
            p.set_param("isSports", convert_from<std::string>(input.isSports.value()));
        if(input.includePeople)
            p.set_param("includePeople", convert_from<std::string>(input.includePeople.value()));
        if(input.includeMedia)
            p.set_param("includeMedia", convert_from<std::string>(input.includeMedia.value()));
        if(input.includeGenres)
            p.set_param("includeGenres", convert_from<std::string>(input.includeGenres.value()));
        if(input.includeStudios)
            p.set_param("includeStudios", convert_from<std::string>(input.includeStudios.value()));
        if(input.includeArtists)
            p.set_param("includeArtists", convert_from<std::string>(input.includeArtists.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAISearchHintResult
 * returnFormat: 
 * returnBaseType: OAISearchHintResult
 * returnContainer: 
 * baseName: Search
 * defaultResponse: OAISearchHintResult()
 */
};
}
}
