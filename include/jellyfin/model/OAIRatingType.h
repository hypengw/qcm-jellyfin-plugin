#pragma once

/*
 * OAIRatingType.h
 * name: RatingType
 * schemaName: RatingType
 * classFilename: RatingType
 * classVarName: RatingType
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

    enum class OAIRatingType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        SCORE, // Score
        LIKES, // Likes
    };
    extern void to_json(json_t&, const OAIRatingType&);
    extern void from_json(const json_t&, OAIRatingType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIRatingType);
