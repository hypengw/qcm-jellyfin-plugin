#pragma once

/*
 * OAIItemFilter.h
 * name: ItemFilter
 * schemaName: ItemFilter
 * classFilename: ItemFilter
 * classVarName: ItemFilter
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum ItemFilter.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIItemFilter {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        ISFOLDER, // IsFolder
        ISNOTFOLDER, // IsNotFolder
        ISUNPLAYED, // IsUnplayed
        ISPLAYED, // IsPlayed
        ISFAVORITE, // IsFavorite
        ISRESUMABLE, // IsResumable
        LIKES, // Likes
        DISLIKES, // Dislikes
        ISFAVORITEORLIKES, // IsFavoriteOrLikes
    };
    extern void to_json(json_t&, const OAIItemFilter&);
    extern void from_json(const json_t&, OAIItemFilter&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIItemFilter);
