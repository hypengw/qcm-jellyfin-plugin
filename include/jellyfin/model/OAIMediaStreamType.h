#pragma once

/*
 * OAIMediaStreamType.h
 * name: MediaStreamType
 * schemaName: MediaStreamType
 * classFilename: MediaStreamType
 * classVarName: MediaStreamType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum MediaStreamType.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIMediaStreamType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        AUDIO, // Audio
        VIDEO, // Video
        SUBTITLE, // Subtitle
        EMBEDDEDIMAGE, // EmbeddedImage
        DATA, // Data
        LYRIC, // Lyric
    };
    extern void to_json(json_t&, const OAIMediaStreamType&);
    extern void from_json(const json_t&, OAIMediaStreamType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMediaStreamType);
