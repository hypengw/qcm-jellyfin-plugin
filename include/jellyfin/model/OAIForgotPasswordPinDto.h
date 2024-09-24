#pragma once

/*
 * OAIForgotPasswordPinDto.h
 * name: ForgotPasswordPinDto
 * schemaName: ForgotPasswordPinDto
 * classFilename: ForgotPasswordPinDto
 * classVarName: ForgotPasswordPinDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Forgot Password Pin enter request body DTO.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAIForgotPasswordPinDto {
    public:
    
        // Gets or sets the entered pin to have the password reset.
        std::string Pin;

        OAIForgotPasswordPinDto();
        ~OAIForgotPasswordPinDto();
    };
    extern void to_json(json_t&, const OAIForgotPasswordPinDto&);
    extern void from_json(const json_t&, OAIForgotPasswordPinDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIForgotPasswordPinDto);
