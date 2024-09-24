#pragma once

/*
 * OAIJoinGroupRequestDto.h
 * name: JoinGroupRequestDto
 * schemaName: JoinGroupRequestDto
 * classFilename: JoinGroupRequestDto
 * classVarName: JoinGroupRequestDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class JoinGroupRequestDto.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAIJoinGroupRequestDto {
    public:
    
        // Gets or sets the group identifier.
        std::string GroupId;

        OAIJoinGroupRequestDto();
        ~OAIJoinGroupRequestDto();
    };
    extern void to_json(json_t&, const OAIJoinGroupRequestDto&);
    extern void from_json(const json_t&, OAIJoinGroupRequestDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIJoinGroupRequestDto);
