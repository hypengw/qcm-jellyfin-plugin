#pragma once

/*
 * OAIUpdateMediaPathRequestDto.h
 * name: UpdateMediaPathRequestDto
 * schemaName: UpdateMediaPathRequestDto
 * classFilename: UpdateMediaPathRequestDto
 * classVarName: UpdateMediaPathRequestDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Update library options dto.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIMediaPathInfo.h"
#include <string>



namespace jellyfin::model {
class OAIMediaPathInfo;


    class OAIUpdateMediaPathRequestDto {
    public:
    
        // Gets or sets the library name.
        std::string Name;

        // Gets or sets library folder path information.
        OAIMediaPathInfo PathInfo;

        OAIUpdateMediaPathRequestDto();
        ~OAIUpdateMediaPathRequestDto();
    };
    extern void to_json(json_t&, const OAIUpdateMediaPathRequestDto&);
    extern void from_json(const json_t&, OAIUpdateMediaPathRequestDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIUpdateMediaPathRequestDto);
