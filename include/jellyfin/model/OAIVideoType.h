#pragma once

/*
 * OAIVideoType.h
 * name: VideoType
 * schemaName: VideoType
 * classFilename: VideoType
 * classVarName: VideoType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum VideoType.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIVideoType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        VIDEOFILE, // VideoFile
        ISO, // Iso
        DVD, // Dvd
        BLURAY, // BluRay
    };
    extern void to_json(json_t&, const OAIVideoType&);
    extern void from_json(const json_t&, OAIVideoType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIVideoType);
