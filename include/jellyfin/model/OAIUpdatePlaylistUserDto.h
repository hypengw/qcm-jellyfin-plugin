#pragma once

/*
 * OAIUpdatePlaylistUserDto.h
 * name: UpdatePlaylistUserDto
 * schemaName: UpdatePlaylistUserDto
 * classFilename: UpdatePlaylistUserDto
 * classVarName: UpdatePlaylistUserDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Update existing playlist user dto. Fields set to &#x60;null&#x60; will not be updated and keep their current values.
 */


#include "jellyfin/type.h"


#include <cstdint>



namespace jellyfin::model {


    class OAIUpdatePlaylistUserDto {
    public:
    
        // Gets or sets a value indicating whether the user can edit the playlist.
        std::optional<bool> CanEdit;

        OAIUpdatePlaylistUserDto();
        ~OAIUpdatePlaylistUserDto();
    };
    extern void to_json(json_t&, const OAIUpdatePlaylistUserDto&);
    extern void from_json(const json_t&, OAIUpdatePlaylistUserDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIUpdatePlaylistUserDto);
