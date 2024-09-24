#pragma once

/*
 * OAIPluginInfo.h
 * name: PluginInfo
 * schemaName: PluginInfo
 * classFilename: PluginInfo
 * classVarName: PluginInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * This is a serializable stub class that is used by the api to provide information about installed plugins.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIPluginStatus.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIPluginInfo {
    public:
    
        // Gets or sets the name.
        std::string Name;

        // Gets or sets the version.
        std::string Version;

        // Gets or sets the name of the configuration file.
        std::optional<std::string> ConfigurationFileName;

        // Gets or sets the description.
        std::string Description;

        // Gets or sets the unique id.
        std::string Id;

        // Gets or sets a value indicating whether the plugin can be uninstalled.
        bool CanUninstall;

        // Gets or sets a value indicating whether this plugin has a valid image.
        bool HasImage;

        // Gets or sets a value indicating the status of the plugin.
        OAIPluginStatus Status;

        OAIPluginInfo();
        ~OAIPluginInfo();
    };
    extern void to_json(json_t&, const OAIPluginInfo&);
    extern void from_json(const json_t&, OAIPluginInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPluginInfo);
