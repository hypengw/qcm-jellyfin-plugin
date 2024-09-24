#pragma once

/*
 * OAIPlaylistUserPermissions.h
 * name: PlaylistUserPermissions
 * schemaName: PlaylistUserPermissions
 * classFilename: PlaylistUserPermissions
 * classVarName: PlaylistUserPermissions
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class to hold data on user permissions for playlists.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIPlaylistUserPermissions {
    public:
    
        // Gets or sets the user id.
        std::string UserId;

        // Gets or sets a value indicating whether the user has edit permissions.
        bool CanEdit;

        OAIPlaylistUserPermissions();
        ~OAIPlaylistUserPermissions();
    };
    extern void to_json(json_t&, const OAIPlaylistUserPermissions&);
    extern void from_json(const json_t&, OAIPlaylistUserPermissions&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlaylistUserPermissions);
