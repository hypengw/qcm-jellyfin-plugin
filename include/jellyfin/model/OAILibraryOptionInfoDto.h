#pragma once

/*
 * OAILibraryOptionInfoDto.h
 * name: LibraryOptionInfoDto
 * schemaName: LibraryOptionInfoDto
 * classFilename: LibraryOptionInfoDto
 * classVarName: LibraryOptionInfoDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Library option info dto.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAILibraryOptionInfoDto {
    public:
    
        // Gets or sets name.
        std::optional<std::string> Name;

        // Gets or sets a value indicating whether default enabled.
        bool DefaultEnabled;

        OAILibraryOptionInfoDto();
        ~OAILibraryOptionInfoDto();
    };
    extern void to_json(json_t&, const OAILibraryOptionInfoDto&);
    extern void from_json(const json_t&, OAILibraryOptionInfoDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAILibraryOptionInfoDto);
