#pragma once
/*
 * OAIBrandingApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIBrandingOptions.h"
#include <string>

namespace jellyfin {
namespace model
{
using return_type_getBrandingCss = std::string;
using return_type_getBrandingCss2 = std::string;
using return_type_getBrandingOptions = OAIBrandingOptions;
}

namespace api::param 
{
struct getBrandingCss {
};
struct getBrandingCss2 {
};
struct getBrandingOptions {
};
}

namespace api 
{
// Gets branding css.
struct getBrandingCss {
public:
    using in_type                      = param::getBrandingCss;
    using out_type                     = model::return_type_getBrandingCss;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Branding/Css"sv; 
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
 * returnType: std::string
 * returnFormat: 
 * returnBaseType: std::string
 * returnContainer: 
 * baseName: Branding
 * defaultResponse: {}
 */
};
// Gets branding css.
struct getBrandingCss2 {
public:
    using in_type                      = param::getBrandingCss2;
    using out_type                     = model::return_type_getBrandingCss2;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Branding/Css.css"sv; 
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
 * returnType: std::string
 * returnFormat: 
 * returnBaseType: std::string
 * returnContainer: 
 * baseName: Branding
 * defaultResponse: {}
 */
};
// Gets branding configuration.
struct getBrandingOptions {
public:
    using in_type                      = param::getBrandingOptions;
    using out_type                     = model::return_type_getBrandingOptions;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Branding/Configuration"sv; 
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
 * returnType: OAIBrandingOptions
 * returnFormat: 
 * returnBaseType: OAIBrandingOptions
 * returnContainer: 
 * baseName: Branding
 * defaultResponse: OAIBrandingOptions()
 */
};
}
}
