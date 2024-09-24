#pragma once

/*
 * OAIRecommendationType.h
 * name: RecommendationType
 * schemaName: RecommendationType
 * classFilename: RecommendationType
 * classVarName: RecommendationType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIRecommendationType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        SIMILARTORECENTLYPLAYED, // SimilarToRecentlyPlayed
        SIMILARTOLIKEDITEM, // SimilarToLikedItem
        HASDIRECTORFROMRECENTLYPLAYED, // HasDirectorFromRecentlyPlayed
        HASACTORFROMRECENTLYPLAYED, // HasActorFromRecentlyPlayed
        HASLIKEDDIRECTOR, // HasLikedDirector
        HASLIKEDACTOR, // HasLikedActor
    };
    extern void to_json(json_t&, const OAIRecommendationType&);
    extern void from_json(const json_t&, OAIRecommendationType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIRecommendationType);
