#pragma once

/*
 * OAIPublicSystemInfo.h
 * name: PublicSystemInfo
 * schemaName: PublicSystemInfo
 * classFilename: PublicSystemInfo
 * classVarName: PublicSystemInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIPublicSystemInfo {
    public:
    
        // Gets or sets the local address.
        std::optional<std::string> LocalAddress;

        // Gets or sets the name of the server.
        std::optional<std::string> ServerName;

        // Gets or sets the server version.
        std::optional<std::string> Version;

        // Gets or sets the product name. This is the AssemblyProduct name.
        std::optional<std::string> ProductName;

        // Gets or sets the operating system.
        [[deprecated]] std::optional<std::string> OperatingSystem;

        // Gets or sets the id.
        std::optional<std::string> Id;

        // Gets or sets a value indicating whether the startup wizard is completed.
        std::optional<bool> StartupWizardCompleted;

        OAIPublicSystemInfo();
        ~OAIPublicSystemInfo();
    };
    extern void to_json(json_t&, const OAIPublicSystemInfo&);
    extern void from_json(const json_t&, OAIPublicSystemInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPublicSystemInfo);
