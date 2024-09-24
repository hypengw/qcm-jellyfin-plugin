#pragma once
/*
 * OAIPluginsApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIPluginInfo.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include <memory>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_disablePlugin = std::nullptr_t;
using return_type_enablePlugin = std::nullptr_t;
using return_type_getPluginConfiguration = rc<json_t>;
using return_type_getPluginImage = std::vector<std::byte>;
using return_type_getPluginManifest = std::nullptr_t;
using return_type_getPlugins = std::vector<OAIPluginInfo>;
using return_type_uninstallPlugin = std::nullptr_t;
using return_type_uninstallPluginByVersion = std::nullptr_t;
using return_type_updatePluginConfiguration = std::nullptr_t;
}

namespace api::param 
{
struct disablePlugin {
    std::string pluginId; // Plugin id.
    std::string version; // Plugin version.
};
struct enablePlugin {
    std::string pluginId; // Plugin id.
    std::string version; // Plugin version.
};
struct getPluginConfiguration {
    std::string pluginId; // Plugin id.
};
struct getPluginImage {
    std::string pluginId; // Plugin id.
    std::string version; // Plugin version.
};
struct getPluginManifest {
    std::string pluginId; // Plugin id.
};
struct getPlugins {
};
struct uninstallPlugin {
    std::string pluginId; // Plugin id.
};
struct uninstallPluginByVersion {
    std::string pluginId; // Plugin id.
    std::string version; // Plugin version.
};
struct updatePluginConfiguration {
    std::string pluginId; // Plugin id.
};
}

namespace api 
{
// Disable a plugin.
struct disablePlugin {
public:
    using in_type                      = param::disablePlugin;
    using out_type                     = model::return_type_disablePlugin;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Plugins/{}/{}/Disable"sv,
            input.pluginId,
            input.version
        );
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
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Plugins
 * defaultResponse: 
 */
};
// Enables a disabled plugin.
struct enablePlugin {
public:
    using in_type                      = param::enablePlugin;
    using out_type                     = model::return_type_enablePlugin;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Plugins/{}/{}/Enable"sv,
            input.pluginId,
            input.version
        );
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
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Plugins
 * defaultResponse: 
 */
};
// Gets plugin configuration.
struct getPluginConfiguration {
public:
    using in_type                      = param::getPluginConfiguration;
    using out_type                     = model::return_type_getPluginConfiguration;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Plugins/{}/Configuration"sv,
            input.pluginId
        );
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
 * returnType: rc&lt;json_t&gt;
 * returnFormat: 
 * returnBaseType: rc&lt;json_t&gt;
 * returnContainer: 
 * baseName: Plugins
 * defaultResponse: {}
 */
};
// Gets a plugin&#39;s image.
struct getPluginImage {
public:
    using in_type                      = param::getPluginImage;
    using out_type                     = model::return_type_getPluginImage;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Plugins/{}/{}/Image"sv,
            input.pluginId,
            input.version
        );
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
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Plugins
 * defaultResponse: {}
 */
};
// Gets a plugin&#39;s manifest.
struct getPluginManifest {
public:
    using in_type                      = param::getPluginManifest;
    using out_type                     = model::return_type_getPluginManifest;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Plugins/{}/Manifest"sv,
            input.pluginId
        );
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
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Plugins
 * defaultResponse: 
 */
};
// Gets a list of currently installed plugins.
struct getPlugins {
public:
    using in_type                      = param::getPlugins;
    using out_type                     = model::return_type_getPlugins;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Plugins"sv; 
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
 * returnType: std::vector&lt;OAIPluginInfo&gt;
 * returnFormat: 
 * returnBaseType: OAIPluginInfo
 * returnContainer: array
 * baseName: Plugins
 * defaultResponse: {}
 */
};
// Uninstalls a plugin.
struct uninstallPlugin {
public:
    using in_type                      = param::uninstallPlugin;
    using out_type                     = model::return_type_uninstallPlugin;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/Plugins/{}"sv,
            input.pluginId
        );
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
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Plugins
 * defaultResponse: 
 */
};
// Uninstalls a plugin by version.
struct uninstallPluginByVersion {
public:
    using in_type                      = param::uninstallPluginByVersion;
    using out_type                     = model::return_type_uninstallPluginByVersion;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/Plugins/{}/{}"sv,
            input.pluginId,
            input.version
        );
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
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Plugins
 * defaultResponse: 
 */
};
// Updates plugin configuration.
struct updatePluginConfiguration {
public:
    using in_type                      = param::updatePluginConfiguration;
    using out_type                     = model::return_type_updatePluginConfiguration;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Plugins/{}/Configuration"sv,
            input.pluginId
        );
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
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Plugins
 * defaultResponse: 
 */
};
}
}
