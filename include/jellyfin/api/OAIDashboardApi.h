#pragma once
/*
 * OAIDashboardApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIConfigurationPageInfo.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getConfigurationPages = std::vector<OAIConfigurationPageInfo>;
using return_type_getDashboardConfigurationPage = std::vector<std::byte>;
}

namespace api::param 
{
struct getConfigurationPages {
    std::optional<bool> enableInMainMenu; // Whether to enable in the main menu.
};
struct getDashboardConfigurationPage {
    std::optional<std::string> name; // The name of the page.
};
}

namespace api 
{
// Gets the configuration pages.
struct getConfigurationPages {
public:
    using in_type                      = param::getConfigurationPages;
    using out_type                     = model::return_type_getConfigurationPages;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/web/ConfigurationPages"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.enableInMainMenu)
            p.set_param("enableInMainMenu", convert_from<std::string>(input.enableInMainMenu.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;OAIConfigurationPageInfo&gt;
 * returnFormat: 
 * returnBaseType: OAIConfigurationPageInfo
 * returnContainer: array
 * baseName: Dashboard
 * defaultResponse: {}
 */
};
// Gets a dashboard configuration page.
struct getDashboardConfigurationPage {
public:
    using in_type                      = param::getDashboardConfigurationPage;
    using out_type                     = model::return_type_getDashboardConfigurationPage;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/web/ConfigurationPage"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.name)
            p.set_param("name", convert_from<std::string>(input.name.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Dashboard
 * defaultResponse: {}
 */
};
}
}
