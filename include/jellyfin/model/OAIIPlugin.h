#pragma once

/*
 * OAIIPlugin.h
 * name: IPlugin
 * schemaName: IPlugin
 * classFilename: IPlugin
 * classVarName: IPlugin
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Defines the MediaBrowser.Common.Plugins.IPlugin.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIIPlugin {
    public:
    
        // Gets the name of the plugin.
        std::optional<std::string> Name;

        // Gets the Description.
        std::optional<std::string> Description;

        // Gets the unique id.
        std::string Id;

        // Gets the plugin version.
        std::optional<std::string> Version;

        // Gets the path to the assembly file.
        std::optional<std::string> AssemblyFilePath;

        // Gets a value indicating whether the plugin can be uninstalled.
        bool CanUninstall;

        // Gets the full path to the data folder, where the plugin can store any miscellaneous files needed.
        std::optional<std::string> DataFolderPath;

        OAIIPlugin();
        ~OAIIPlugin();
    };
    extern void to_json(json_t&, const OAIIPlugin&);
    extern void from_json(const json_t&, OAIIPlugin&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIIPlugin);
