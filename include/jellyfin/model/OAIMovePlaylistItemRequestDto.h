#pragma once

/*
 * OAIMovePlaylistItemRequestDto.h
 * name: MovePlaylistItemRequestDto
 * schemaName: MovePlaylistItemRequestDto
 * classFilename: MovePlaylistItemRequestDto
 * classVarName: MovePlaylistItemRequestDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class MovePlaylistItemRequestDto.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIMovePlaylistItemRequestDto {
    public:
    
        // Gets or sets the playlist identifier of the item.
        std::string PlaylistItemId;

        // Gets or sets the new position.
        std::int32_t NewIndex;

        OAIMovePlaylistItemRequestDto();
        ~OAIMovePlaylistItemRequestDto();
    };
    extern void to_json(json_t&, const OAIMovePlaylistItemRequestDto&);
    extern void from_json(const json_t&, OAIMovePlaylistItemRequestDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMovePlaylistItemRequestDto);
