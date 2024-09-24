#pragma once

/*
 * OAIVideo3DFormat.h
 * name: Video3DFormat
 * schemaName: Video3DFormat
 * classFilename: Video3DFormat
 * classVarName: Video3DFormat
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

    enum class OAIVideo3DFormat {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        HALFSIDEBYSIDE, // HalfSideBySide
        FULLSIDEBYSIDE, // FullSideBySide
        FULLTOPANDBOTTOM, // FullTopAndBottom
        HALFTOPANDBOTTOM, // HalfTopAndBottom
        MVC, // MVC
    };
    extern void to_json(json_t&, const OAIVideo3DFormat&);
    extern void from_json(const json_t&, OAIVideo3DFormat&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIVideo3DFormat);
