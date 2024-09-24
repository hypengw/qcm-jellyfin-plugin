#pragma once

/*
 * OAIUpdatePlaylistDto.h
 * name: UpdatePlaylistDto
 * schemaName: UpdatePlaylistDto
 * classFilename: UpdatePlaylistDto
 * classVarName: UpdatePlaylistDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Update existing playlist dto. Fields set to &#x60;null&#x60; will not be updated and keep their current values.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIPlaylistUserPermissions.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIPlaylistUserPermissions;


    class OAIUpdatePlaylistDto {
    public:
    
        // Gets or sets the name of the new playlist.
        std::optional<std::string> Name;

        // Gets or sets item ids of the playlist.
        std::optional<std::vector<std::string>> Ids;

        // Gets or sets the playlist users.
        std::optional<std::vector<OAIPlaylistUserPermissions>> Users;

        // Gets or sets a value indicating whether the playlist is public.
        std::optional<bool> IsPublic;

        OAIUpdatePlaylistDto();
        ~OAIUpdatePlaylistDto();
    };
    extern void to_json(json_t&, const OAIUpdatePlaylistDto&);
    extern void from_json(const json_t&, OAIUpdatePlaylistDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIUpdatePlaylistDto);
