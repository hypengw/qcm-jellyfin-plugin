#pragma once
/*
 * OAITmdbApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIConfigImageTypes.h"

namespace jellyfin {
namespace model
{
using return_type_tmdbClientConfiguration = OAIConfigImageTypes;
}

namespace api::param 
{
struct tmdbClientConfiguration {
};
}

namespace api 
{
// Gets the TMDb image configuration options.
struct tmdbClientConfiguration {
public:
    using in_type                      = param::tmdbClientConfiguration;
    using out_type                     = model::return_type_tmdbClientConfiguration;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Tmdb/ClientConfiguration"sv; 
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
 * returnType: OAIConfigImageTypes
 * returnFormat: 
 * returnBaseType: OAIConfigImageTypes
 * returnContainer: 
 * baseName: Tmdb
 * defaultResponse: OAIConfigImageTypes()
 */
};
}
}
