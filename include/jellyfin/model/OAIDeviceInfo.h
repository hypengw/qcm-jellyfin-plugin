#pragma once

/*
 * OAIDeviceInfo.h
 * name: DeviceInfo
 * schemaName: DeviceInfo
 * classFilename: DeviceInfo
 * classVarName: DeviceInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIClientCapabilities.h"
#include <string>



namespace jellyfin::model {
class OAIClientCapabilities;


    class OAIDeviceInfo {
    public:
    
        std::optional<std::string> Name;

        std::optional<std::string> CustomName;

        // Gets or sets the access token.
        std::optional<std::string> AccessToken;

        // Gets or sets the identifier.
        std::optional<std::string> Id;

        // Gets or sets the last name of the user.
        std::optional<std::string> LastUserName;

        // Gets or sets the name of the application.
        std::optional<std::string> AppName;

        // Gets or sets the application version.
        std::optional<std::string> AppVersion;

        // Gets or sets the last user identifier.
        std::string LastUserId;

        // Gets or sets the date last modified.
        std::string DateLastActivity;

        // Gets or sets the capabilities.
        std::optional<OAIClientCapabilities> Capabilities;

        std::optional<std::string> IconUrl;

        OAIDeviceInfo();
        ~OAIDeviceInfo();
    };
    extern void to_json(json_t&, const OAIDeviceInfo&);
    extern void from_json(const json_t&, OAIDeviceInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIDeviceInfo);
