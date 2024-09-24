#pragma once

/*
 * OAIAuthenticationResult.h
 * name: AuthenticationResult
 * schemaName: AuthenticationResult
 * classFilename: AuthenticationResult
 * classVarName: AuthenticationResult
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionInfo.h"
#include "jellyfin/model/OAIUserDto.h"
#include <string>



namespace jellyfin::model {
class OAIUserDto;
class OAISessionInfo;


    class OAIAuthenticationResult {
    public:
    
        // Class UserDto.
        std::optional<OAIUserDto> User;

        // Class SessionInfo.
        std::optional<OAISessionInfo> SessionInfo;

        std::optional<std::string> AccessToken;

        std::optional<std::string> ServerId;

        OAIAuthenticationResult();
        ~OAIAuthenticationResult();
    };
    extern void to_json(json_t&, const OAIAuthenticationResult&);
    extern void from_json(const json_t&, OAIAuthenticationResult&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIAuthenticationResult);
