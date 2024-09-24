#pragma once

/*
 * OAINewGroupRequestDto.h
 * name: NewGroupRequestDto
 * schemaName: NewGroupRequestDto
 * classFilename: NewGroupRequestDto
 * classVarName: NewGroupRequestDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class NewGroupRequestDto.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAINewGroupRequestDto {
    public:
    
        // Gets or sets the group name.
        std::string GroupName;

        OAINewGroupRequestDto();
        ~OAINewGroupRequestDto();
    };
    extern void to_json(json_t&, const OAINewGroupRequestDto&);
    extern void from_json(const json_t&, OAINewGroupRequestDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAINewGroupRequestDto);
