#pragma once

/*
 * OAIConfigurationPageInfo.h
 * name: ConfigurationPageInfo
 * schemaName: ConfigurationPageInfo
 * classFilename: ConfigurationPageInfo
 * classVarName: ConfigurationPageInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * The configuration page info.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIConfigurationPageInfo {
    public:
    
        // Gets or sets the name.
        std::string Name;

        // Gets or sets a value indicating whether the configurations page is enabled in the main menu.
        bool EnableInMainMenu;

        // Gets or sets the menu section.
        std::optional<std::string> MenuSection;

        // Gets or sets the menu icon.
        std::optional<std::string> MenuIcon;

        // Gets or sets the display name.
        std::optional<std::string> DisplayName;

        // Gets or sets the plugin id.
        std::optional<std::string> PluginId;

        OAIConfigurationPageInfo();
        ~OAIConfigurationPageInfo();
    };
    extern void to_json(json_t&, const OAIConfigurationPageInfo&);
    extern void from_json(const json_t&, OAIConfigurationPageInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIConfigurationPageInfo);
