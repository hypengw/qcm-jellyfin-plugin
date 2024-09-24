#pragma once

/*
 * OAISetPlaylistItemRequestDto.h
 * name: SetPlaylistItemRequestDto
 * schemaName: SetPlaylistItemRequestDto
 * classFilename: SetPlaylistItemRequestDto
 * classVarName: SetPlaylistItemRequestDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class SetPlaylistItemRequestDto.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAISetPlaylistItemRequestDto {
    public:
    
        // Gets or sets the playlist identifier of the playing item.
        std::string PlaylistItemId;

        OAISetPlaylistItemRequestDto();
        ~OAISetPlaylistItemRequestDto();
    };
    extern void to_json(json_t&, const OAISetPlaylistItemRequestDto&);
    extern void from_json(const json_t&, OAISetPlaylistItemRequestDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISetPlaylistItemRequestDto);
