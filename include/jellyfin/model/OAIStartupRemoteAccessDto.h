#pragma once

/*
 * OAIStartupRemoteAccessDto.h
 * name: StartupRemoteAccessDto
 * schemaName: StartupRemoteAccessDto
 * classFilename: StartupRemoteAccessDto
 * classVarName: StartupRemoteAccessDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Startup remote access dto.
 */


#include "jellyfin/type.h"


#include <cstdint>



namespace jellyfin::model {


    class OAIStartupRemoteAccessDto {
    public:
    
        // Gets or sets a value indicating whether enable remote access.
        bool EnableRemoteAccess;

        // Gets or sets a value indicating whether enable automatic port mapping.
        bool EnableAutomaticPortMapping;

        OAIStartupRemoteAccessDto();
        ~OAIStartupRemoteAccessDto();
    };
    extern void to_json(json_t&, const OAIStartupRemoteAccessDto&);
    extern void from_json(const json_t&, OAIStartupRemoteAccessDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIStartupRemoteAccessDto);
