#pragma once

/*
 * OAIPreviousItemRequestDto.h
 * name: PreviousItemRequestDto
 * schemaName: PreviousItemRequestDto
 * classFilename: PreviousItemRequestDto
 * classVarName: PreviousItemRequestDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class PreviousItemRequestDto.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAIPreviousItemRequestDto {
    public:
    
        // Gets or sets the playing item identifier.
        std::string PlaylistItemId;

        OAIPreviousItemRequestDto();
        ~OAIPreviousItemRequestDto();
    };
    extern void to_json(json_t&, const OAIPreviousItemRequestDto&);
    extern void from_json(const json_t&, OAIPreviousItemRequestDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPreviousItemRequestDto);
