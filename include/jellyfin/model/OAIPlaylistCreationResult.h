#pragma once

/*
 * OAIPlaylistCreationResult.h
 * name: PlaylistCreationResult
 * schemaName: PlaylistCreationResult
 * classFilename: PlaylistCreationResult
 * classVarName: PlaylistCreationResult
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAIPlaylistCreationResult {
    public:
    
        std::string Id;

        OAIPlaylistCreationResult();
        ~OAIPlaylistCreationResult();
    };
    extern void to_json(json_t&, const OAIPlaylistCreationResult&);
    extern void from_json(const json_t&, OAIPlaylistCreationResult&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlaylistCreationResult);
