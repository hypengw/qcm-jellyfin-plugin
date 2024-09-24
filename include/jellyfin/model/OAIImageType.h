#pragma once

/*
 * OAIImageType.h
 * name: ImageType
 * schemaName: ImageType
 * classFilename: ImageType
 * classVarName: ImageType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum ImageType.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIImageType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        PRIMARY, // Primary
        ART, // Art
        BACKDROP, // Backdrop
        BANNER, // Banner
        LOGO, // Logo
        THUMB, // Thumb
        DISC, // Disc
        BOX, // Box
        SCREENSHOT, // Screenshot
        MENU, // Menu
        CHAPTER, // Chapter
        BOXREAR, // BoxRear
        PROFILE, // Profile
    };
    extern void to_json(json_t&, const OAIImageType&);
    extern void from_json(const json_t&, OAIImageType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIImageType);
