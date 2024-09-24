#pragma once

/*
 * OAIStartupUserDto.h
 * name: StartupUserDto
 * schemaName: StartupUserDto
 * classFilename: StartupUserDto
 * classVarName: StartupUserDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * The startup user DTO.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAIStartupUserDto {
    public:
    
        // Gets or sets the username.
        std::optional<std::string> Name;

        // Gets or sets the user&#39;s password.
        std::optional<std::string> Password;

        OAIStartupUserDto();
        ~OAIStartupUserDto();
    };
    extern void to_json(json_t&, const OAIStartupUserDto&);
    extern void from_json(const json_t&, OAIStartupUserDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIStartupUserDto);
