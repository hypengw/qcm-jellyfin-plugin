#pragma once

/*
 * OAIDlnaProfileType.h
 * name: DlnaProfileType
 * schemaName: DlnaProfileType
 * classFilename: DlnaProfileType
 * classVarName: DlnaProfileType
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

    enum class OAIDlnaProfileType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        AUDIO, // Audio
        VIDEO, // Video
        PHOTO, // Photo
        SUBTITLE, // Subtitle
        LYRIC, // Lyric
    };
    extern void to_json(json_t&, const OAIDlnaProfileType&);
    extern void from_json(const json_t&, OAIDlnaProfileType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIDlnaProfileType);
