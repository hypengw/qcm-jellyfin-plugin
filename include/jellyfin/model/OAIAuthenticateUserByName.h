#pragma once

/*
 * OAIAuthenticateUserByName.h
 * name: AuthenticateUserByName
 * schemaName: AuthenticateUserByName
 * classFilename: AuthenticateUserByName
 * classVarName: AuthenticateUserByName
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * The authenticate user by name request body.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAIAuthenticateUserByName {
    public:
    
        // Gets or sets the username.
        std::optional<std::string> Username;

        // Gets or sets the plain text password.
        std::optional<std::string> Pw;

        OAIAuthenticateUserByName();
        ~OAIAuthenticateUserByName();
    };
    extern void to_json(json_t&, const OAIAuthenticateUserByName&);
    extern void from_json(const json_t&, OAIAuthenticateUserByName&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIAuthenticateUserByName);
