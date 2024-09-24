#pragma once
/*
 * OAIMoviesApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIItemFields.h"
#include "jellyfin/model/OAIRecommendationDto.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getMovieRecommendations = std::vector<OAIRecommendationDto>;
}

namespace api::param 
{
struct getMovieRecommendations {
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
    std::optional<std::string> parentId; // Specify this to localize the search to a specific item or folder. Omit to use the root.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. The fields to return.
    std::optional<std::int32_t> categoryLimit; // The max number of categories to return.
    std::optional<std::int32_t> itemLimit; // The max number of items to return per category.
};
}

namespace api 
{
// Gets movie recommendations.
struct getMovieRecommendations {
public:
    using in_type                      = param::getMovieRecommendations;
    using out_type                     = model::return_type_getMovieRecommendations;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Movies/Recommendations"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.parentId)
            p.set_param("parentId", convert_from<std::string>(input.parentId.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.categoryLimit)
            p.set_param("categoryLimit", convert_from<std::string>(input.categoryLimit.value()));
        if(input.itemLimit)
            p.set_param("itemLimit", convert_from<std::string>(input.itemLimit.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;OAIRecommendationDto&gt;
 * returnFormat: 
 * returnBaseType: OAIRecommendationDto
 * returnContainer: array
 * baseName: Movies
 * defaultResponse: {}
 */
};
}
}
