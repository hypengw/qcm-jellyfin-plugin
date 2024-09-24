#pragma once

/*
 * OAIUpdateUserPassword.h
 * name: UpdateUserPassword
 * schemaName: UpdateUserPassword
 * classFilename: UpdateUserPassword
 * classVarName: UpdateUserPassword
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * The update user password request body.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIUpdateUserPassword {
    public:
    
        // Gets or sets the current sha1-hashed password.
        std::optional<std::string> CurrentPassword;

        // Gets or sets the current plain text password.
        std::optional<std::string> CurrentPw;

        // Gets or sets the new plain text password.
        std::optional<std::string> NewPw;

        // Gets or sets a value indicating whether to reset the password.
        bool ResetPassword;

        OAIUpdateUserPassword();
        ~OAIUpdateUserPassword();
    };
    extern void to_json(json_t&, const OAIUpdateUserPassword&);
    extern void from_json(const json_t&, OAIUpdateUserPassword&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIUpdateUserPassword);
