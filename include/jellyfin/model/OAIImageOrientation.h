#pragma once

/*
 * OAIImageOrientation.h
 * name: ImageOrientation
 * schemaName: ImageOrientation
 * classFilename: ImageOrientation
 * classVarName: ImageOrientation
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

    enum class OAIImageOrientation {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        TOPLEFT, // TopLeft
        TOPRIGHT, // TopRight
        BOTTOMRIGHT, // BottomRight
        BOTTOMLEFT, // BottomLeft
        LEFTTOP, // LeftTop
        RIGHTTOP, // RightTop
        RIGHTBOTTOM, // RightBottom
        LEFTBOTTOM, // LeftBottom
    };
    extern void to_json(json_t&, const OAIImageOrientation&);
    extern void from_json(const json_t&, OAIImageOrientation&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIImageOrientation);
