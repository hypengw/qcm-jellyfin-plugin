#pragma once

/*
 * OAIRemoveFromPlaylistRequestDto.h
 * name: RemoveFromPlaylistRequestDto
 * schemaName: RemoveFromPlaylistRequestDto
 * classFilename: RemoveFromPlaylistRequestDto
 * classVarName: RemoveFromPlaylistRequestDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class RemoveFromPlaylistRequestDto.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {


    class OAIRemoveFromPlaylistRequestDto {
    public:
    
        // Gets or sets the playlist identifiers of the items. Ignored when clearing the playlist.
        std::vector<std::string> PlaylistItemIds;

        // Gets or sets a value indicating whether the entire playlist should be cleared.
        bool ClearPlaylist;

        // Gets or sets a value indicating whether the playing item should be removed as well. Used only when clearing the playlist.
        bool ClearPlayingItem;

        OAIRemoveFromPlaylistRequestDto();
        ~OAIRemoveFromPlaylistRequestDto();
    };
    extern void to_json(json_t&, const OAIRemoveFromPlaylistRequestDto&);
    extern void from_json(const json_t&, OAIRemoveFromPlaylistRequestDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIRemoveFromPlaylistRequestDto);
