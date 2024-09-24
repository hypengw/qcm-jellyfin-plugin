#pragma once

/*
 * OAIUserDto.h
 * name: UserDto
 * schemaName: UserDto
 * classFilename: UserDto
 * classVarName: UserDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class UserDto.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIUserConfiguration.h"
#include "jellyfin/model/OAIUserPolicy.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {
class OAIUserConfiguration;
class OAIUserPolicy;


    class OAIUserDto {
    public:
    
        // Gets or sets the name.
        std::optional<std::string> Name;

        // Gets or sets the server identifier.
        std::optional<std::string> ServerId;

        // Gets or sets the name of the server.  This is not used by the server and is for client-side usage only.
        std::optional<std::string> ServerName;

        // Gets or sets the id.
        std::string Id;

        // Gets or sets the primary image tag.
        std::optional<std::string> PrimaryImageTag;

        // Gets or sets a value indicating whether this instance has password.
        bool HasPassword;

        // Gets or sets a value indicating whether this instance has configured password.
        bool HasConfiguredPassword;

        // Gets or sets a value indicating whether this instance has configured easy password.
        [[deprecated]] bool HasConfiguredEasyPassword;

        // Gets or sets whether async login is enabled or not.
        std::optional<bool> EnableAutoLogin;

        // Gets or sets the last login date.
        std::optional<std::string> LastLoginDate;

        // Gets or sets the last activity date.
        std::optional<std::string> LastActivityDate;

        // Gets or sets the configuration.
        std::optional<OAIUserConfiguration> Configuration;

        // Gets or sets the policy.
        std::optional<OAIUserPolicy> Policy;

        // Gets or sets the primary image aspect ratio.
        std::optional<double> PrimaryImageAspectRatio;

        OAIUserDto();
        ~OAIUserDto();
    };
    extern void to_json(json_t&, const OAIUserDto&);
    extern void from_json(const json_t&, OAIUserDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIUserDto);
