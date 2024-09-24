#pragma once

/*
 * OAIImageSavingConvention.h
 * name: ImageSavingConvention
 * schemaName: ImageSavingConvention
 * classFilename: ImageSavingConvention
 * classVarName: ImageSavingConvention
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

    enum class OAIImageSavingConvention {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        LEGACY, // Legacy
        COMPATIBLE, // Compatible
    };
    extern void to_json(json_t&, const OAIImageSavingConvention&);
    extern void from_json(const json_t&, OAIImageSavingConvention&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIImageSavingConvention);
