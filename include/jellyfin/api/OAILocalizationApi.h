#pragma once
/*
 * OAILocalizationApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAICountryInfo.h"
#include "jellyfin/model/OAICultureDto.h"
#include "jellyfin/model/OAILocalizationOption.h"
#include "jellyfin/model/OAIParentalRating.h"
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getCountries = std::vector<OAICountryInfo>;
using return_type_getCultures = std::vector<OAICultureDto>;
using return_type_getLocalizationOptions = std::vector<OAILocalizationOption>;
using return_type_getParentalRatings = std::vector<OAIParentalRating>;
}

namespace api::param 
{
struct getCountries {
};
struct getCultures {
};
struct getLocalizationOptions {
};
struct getParentalRatings {
};
}

namespace api 
{
// Gets known countries.
struct getCountries {
public:
    using in_type                      = param::getCountries;
    using out_type                     = model::return_type_getCountries;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Localization/Countries"sv; 
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
 * returnType: std::vector&lt;OAICountryInfo&gt;
 * returnFormat: 
 * returnBaseType: OAICountryInfo
 * returnContainer: array
 * baseName: Localization
 * defaultResponse: {}
 */
};
// Gets known cultures.
struct getCultures {
public:
    using in_type                      = param::getCultures;
    using out_type                     = model::return_type_getCultures;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Localization/Cultures"sv; 
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
 * returnType: std::vector&lt;OAICultureDto&gt;
 * returnFormat: 
 * returnBaseType: OAICultureDto
 * returnContainer: array
 * baseName: Localization
 * defaultResponse: {}
 */
};
// Gets localization options.
struct getLocalizationOptions {
public:
    using in_type                      = param::getLocalizationOptions;
    using out_type                     = model::return_type_getLocalizationOptions;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Localization/Options"sv; 
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
 * returnType: std::vector&lt;OAILocalizationOption&gt;
 * returnFormat: 
 * returnBaseType: OAILocalizationOption
 * returnContainer: array
 * baseName: Localization
 * defaultResponse: {}
 */
};
// Gets known parental ratings.
struct getParentalRatings {
public:
    using in_type                      = param::getParentalRatings;
    using out_type                     = model::return_type_getParentalRatings;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Localization/ParentalRatings"sv; 
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
 * returnType: std::vector&lt;OAIParentalRating&gt;
 * returnFormat: 
 * returnBaseType: OAIParentalRating
 * returnContainer: array
 * baseName: Localization
 * defaultResponse: {}
 */
};
}
}
