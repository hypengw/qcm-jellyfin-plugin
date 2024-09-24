#pragma once

/*
 * OAICreateUserByName.h
 * name: CreateUserByName
 * schemaName: CreateUserByName
 * classFilename: CreateUserByName
 * classVarName: CreateUserByName
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * The create user by name request body.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAICreateUserByName {
    public:
    
        // Gets or sets the username.
        std::string Name;

        // Gets or sets the password.
        std::optional<std::string> Password;

        OAICreateUserByName();
        ~OAICreateUserByName();
    };
    extern void to_json(json_t&, const OAICreateUserByName&);
    extern void from_json(const json_t&, OAICreateUserByName&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAICreateUserByName);
