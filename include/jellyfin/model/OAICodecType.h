#pragma once

/*
 * OAICodecType.h
 * name: CodecType
 * schemaName: CodecType
 * classFilename: CodecType
 * classVarName: CodecType
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

    enum class OAICodecType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        VIDEO, // Video
        VIDEOAUDIO, // VideoAudio
        AUDIO, // Audio
    };
    extern void to_json(json_t&, const OAICodecType&);
    extern void from_json(const json_t&, OAICodecType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAICodecType);
