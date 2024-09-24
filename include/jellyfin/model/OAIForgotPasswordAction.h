#pragma once

/*
 * OAIForgotPasswordAction.h
 * name: ForgotPasswordAction
 * schemaName: ForgotPasswordAction
 * classFilename: ForgotPasswordAction
 * classVarName: ForgotPasswordAction
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIForgotPasswordAction {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        CONTACTADMIN, // ContactAdmin
        PINCODE, // PinCode
        INNETWORKREQUIRED, // InNetworkRequired
    };
    extern void to_json(json_t&, const OAIForgotPasswordAction&);
    extern void from_json(const json_t&, OAIForgotPasswordAction&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIForgotPasswordAction);
