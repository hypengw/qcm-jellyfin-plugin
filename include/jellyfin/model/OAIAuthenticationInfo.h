#pragma once

/*
 * OAIAuthenticationInfo.h
 * name: AuthenticationInfo
 * schemaName: AuthenticationInfo
 * classFilename: AuthenticationInfo
 * classVarName: AuthenticationInfo
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


    class OAIAuthenticationInfo {
    public:
    
        // Gets or sets the identifier.
        std::int64_t Id;

        // Gets or sets the access token.
        std::optional<std::string> AccessToken;

        // Gets or sets the device identifier.
        std::optional<std::string> DeviceId;

        // Gets or sets the name of the application.
        std::optional<std::string> AppName;

        // Gets or sets the application version.
        std::optional<std::string> AppVersion;

        // Gets or sets the name of the device.
        std::optional<std::string> DeviceName;

        // Gets or sets the user identifier.
        std::string UserId;

        // Gets or sets a value indicating whether this instance is active.
        bool IsActive;

        // Gets or sets the date created.
        std::string DateCreated;

        // Gets or sets the date revoked.
        std::optional<std::string> DateRevoked;

        std::string DateLastActivity;

        std::optional<std::string> UserName;

        OAIAuthenticationInfo();
        ~OAIAuthenticationInfo();
    };
    extern void to_json(json_t&, const OAIAuthenticationInfo&);
    extern void from_json(const json_t&, OAIAuthenticationInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIAuthenticationInfo);
