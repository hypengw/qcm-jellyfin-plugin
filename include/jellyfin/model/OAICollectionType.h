#pragma once

/*
 * OAICollectionType.h
 * name: CollectionType
 * schemaName: CollectionType
 * classFilename: CollectionType
 * classVarName: CollectionType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Collection type.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAICollectionType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        UNKNOWN, // unknown
        MOVIES, // movies
        TVSHOWS, // tvshows
        MUSIC, // music
        MUSICVIDEOS, // musicvideos
        TRAILERS, // trailers
        HOMEVIDEOS, // homevideos
        BOXSETS, // boxsets
        BOOKS, // books
        PHOTOS, // photos
        LIVETV, // livetv
        PLAYLISTS, // playlists
        FOLDERS, // folders
    };
    extern void to_json(json_t&, const OAICollectionType&);
    extern void from_json(const json_t&, OAICollectionType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAICollectionType);
