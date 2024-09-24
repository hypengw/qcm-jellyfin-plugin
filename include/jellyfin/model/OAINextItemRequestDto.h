#pragma once

/*
 * OAINextItemRequestDto.h
 * name: NextItemRequestDto
 * schemaName: NextItemRequestDto
 * classFilename: NextItemRequestDto
 * classVarName: NextItemRequestDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class NextItemRequestDto.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAINextItemRequestDto {
    public:
    
        // Gets or sets the playing item identifier.
        std::string PlaylistItemId;

        OAINextItemRequestDto();
        ~OAINextItemRequestDto();
    };
    extern void to_json(json_t&, const OAINextItemRequestDto&);
    extern void from_json(const json_t&, OAINextItemRequestDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAINextItemRequestDto);
