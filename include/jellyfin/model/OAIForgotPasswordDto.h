#pragma once

/*
 * OAIForgotPasswordDto.h
 * name: ForgotPasswordDto
 * schemaName: ForgotPasswordDto
 * classFilename: ForgotPasswordDto
 * classVarName: ForgotPasswordDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Forgot Password request body DTO.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAIForgotPasswordDto {
    public:
    
        // Gets or sets the entered username to have its password reset.
        std::string EnteredUsername;

        OAIForgotPasswordDto();
        ~OAIForgotPasswordDto();
    };
    extern void to_json(json_t&, const OAIForgotPasswordDto&);
    extern void from_json(const json_t&, OAIForgotPasswordDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIForgotPasswordDto);
