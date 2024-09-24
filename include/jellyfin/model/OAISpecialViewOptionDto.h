#pragma once

/*
 * OAISpecialViewOptionDto.h
 * name: SpecialViewOptionDto
 * schemaName: SpecialViewOptionDto
 * classFilename: SpecialViewOptionDto
 * classVarName: SpecialViewOptionDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Special view option dto.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAISpecialViewOptionDto {
    public:
    
        // Gets or sets view option name.
        std::optional<std::string> Name;

        // Gets or sets view option id.
        std::optional<std::string> Id;

        OAISpecialViewOptionDto();
        ~OAISpecialViewOptionDto();
    };
    extern void to_json(json_t&, const OAISpecialViewOptionDto&);
    extern void from_json(const json_t&, OAISpecialViewOptionDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISpecialViewOptionDto);
