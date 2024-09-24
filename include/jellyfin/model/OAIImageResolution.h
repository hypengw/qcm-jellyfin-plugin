#pragma once

/*
 * OAIImageResolution.h
 * name: ImageResolution
 * schemaName: ImageResolution
 * classFilename: ImageResolution
 * classVarName: ImageResolution
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum ImageResolution.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIImageResolution {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        MATCHSOURCE, // MatchSource
        P144, // P144
        P240, // P240
        P360, // P360
        P480, // P480
        P720, // P720
        P1080, // P1080
        P1440, // P1440
        P2160, // P2160
    };
    extern void to_json(json_t&, const OAIImageResolution&);
    extern void from_json(const json_t&, OAIImageResolution&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIImageResolution);
