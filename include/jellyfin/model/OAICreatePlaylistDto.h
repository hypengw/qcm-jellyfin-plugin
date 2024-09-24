#pragma once

/*
 * OAICreatePlaylistDto.h
 * name: CreatePlaylistDto
 * schemaName: CreatePlaylistDto
 * classFilename: CreatePlaylistDto
 * classVarName: CreatePlaylistDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Create new playlist dto.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIMediaType.h"
#include "jellyfin/model/OAIPlaylistUserPermissions.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIPlaylistUserPermissions;


    class OAICreatePlaylistDto {
    public:
    
        // Gets or sets the name of the new playlist.
        std::string Name;

        // Gets or sets item ids to add to the playlist.
        std::vector<std::string> Ids;

        // Gets or sets the user id.
        std::optional<std::string> UserId;

        // Gets or sets the media type.
        std::optional<OAIMediaType> MediaType;

        // Gets or sets the playlist users.
        std::vector<OAIPlaylistUserPermissions> Users;

        // Gets or sets a value indicating whether the playlist is public.
        bool IsPublic;

        OAICreatePlaylistDto();
        ~OAICreatePlaylistDto();
    };
    extern void to_json(json_t&, const OAICreatePlaylistDto&);
    extern void from_json(const json_t&, OAICreatePlaylistDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAICreatePlaylistDto);
