#pragma once

/*
 * OAIAudioSpatialFormat.h
 * name: AudioSpatialFormat
 * schemaName: AudioSpatialFormat
 * classFilename: AudioSpatialFormat
 * classVarName: AudioSpatialFormat
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * An enum representing formats of spatial audio.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIAudioSpatialFormat {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        NONE, // None
        DOLBYATMOS, // DolbyAtmos
        DTSX, // DTSX
    };
    extern void to_json(json_t&, const OAIAudioSpatialFormat&);
    extern void from_json(const json_t&, OAIAudioSpatialFormat&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIAudioSpatialFormat);
