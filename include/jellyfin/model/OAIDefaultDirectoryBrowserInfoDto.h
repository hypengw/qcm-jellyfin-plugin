#pragma once

/*
 * OAIDefaultDirectoryBrowserInfoDto.h
 * name: DefaultDirectoryBrowserInfoDto
 * schemaName: DefaultDirectoryBrowserInfoDto
 * classFilename: DefaultDirectoryBrowserInfoDto
 * classVarName: DefaultDirectoryBrowserInfoDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Default directory browser info.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAIDefaultDirectoryBrowserInfoDto {
    public:
    
        // Gets or sets the path.
        std::optional<std::string> Path;

        OAIDefaultDirectoryBrowserInfoDto();
        ~OAIDefaultDirectoryBrowserInfoDto();
    };
    extern void to_json(json_t&, const OAIDefaultDirectoryBrowserInfoDto&);
    extern void from_json(const json_t&, OAIDefaultDirectoryBrowserInfoDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIDefaultDirectoryBrowserInfoDto);
