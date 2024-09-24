#pragma once

/*
 * OAIImageFormat.h
 * name: ImageFormat
 * schemaName: ImageFormat
 * classFilename: ImageFormat
 * classVarName: ImageFormat
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum ImageOutputFormat.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIImageFormat {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        BMP, // Bmp
        GIF, // Gif
        JPG, // Jpg
        PNG, // Png
        WEBP, // Webp
        SVG, // Svg
    };
    extern void to_json(json_t&, const OAIImageFormat&);
    extern void from_json(const json_t&, OAIImageFormat&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIImageFormat);
