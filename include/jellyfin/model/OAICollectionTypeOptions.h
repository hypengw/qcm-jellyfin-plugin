#pragma once

/*
 * OAICollectionTypeOptions.h
 * name: CollectionTypeOptions
 * schemaName: CollectionTypeOptions
 * classFilename: CollectionTypeOptions
 * classVarName: CollectionTypeOptions
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * The collection type options.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAICollectionTypeOptions {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        MOVIES, // movies
        TVSHOWS, // tvshows
        MUSIC, // music
        MUSICVIDEOS, // musicvideos
        HOMEVIDEOS, // homevideos
        BOXSETS, // boxsets
        BOOKS, // books
        MIXED, // mixed
    };
    extern void to_json(json_t&, const OAICollectionTypeOptions&);
    extern void from_json(const json_t&, OAICollectionTypeOptions&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAICollectionTypeOptions);
