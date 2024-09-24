#pragma once

/*
 * OAIForgotPasswordResult.h
 * name: ForgotPasswordResult
 * schemaName: ForgotPasswordResult
 * classFilename: ForgotPasswordResult
 * classVarName: ForgotPasswordResult
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIForgotPasswordAction.h"
#include <string>



namespace jellyfin::model {


    class OAIForgotPasswordResult {
    public:
    
        // Gets or sets the action.
        OAIForgotPasswordAction Action;

        // Gets or sets the pin file.
        std::optional<std::string> PinFile;

        // Gets or sets the pin expiration date.
        std::optional<std::string> PinExpirationDate;

        OAIForgotPasswordResult();
        ~OAIForgotPasswordResult();
    };
    extern void to_json(json_t&, const OAIForgotPasswordResult&);
    extern void from_json(const json_t&, OAIForgotPasswordResult&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIForgotPasswordResult);
