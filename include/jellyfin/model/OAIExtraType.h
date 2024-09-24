#pragma once

/*
 * OAIExtraType.h
 * name: ExtraType
 * schemaName: ExtraType
 * classFilename: ExtraType
 * classVarName: ExtraType
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

    enum class OAIExtraType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        UNKNOWN, // Unknown
        CLIP, // Clip
        TRAILER, // Trailer
        BEHINDTHESCENES, // BehindTheScenes
        DELETEDSCENE, // DeletedScene
        INTERVIEW, // Interview
        SCENE, // Scene
        SAMPLE, // Sample
        THEMESONG, // ThemeSong
        THEMEVIDEO, // ThemeVideo
        FEATURETTE, // Featurette
        SHORT, // Short
    };
    extern void to_json(json_t&, const OAIExtraType&);
    extern void from_json(const json_t&, OAIExtraType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIExtraType);
