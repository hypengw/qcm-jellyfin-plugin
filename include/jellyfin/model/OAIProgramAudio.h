#pragma once

/*
 * OAIProgramAudio.h
 * name: ProgramAudio
 * schemaName: ProgramAudio
 * classFilename: ProgramAudio
 * classVarName: ProgramAudio
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

    enum class OAIProgramAudio {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        MONO, // Mono
        STEREO, // Stereo
        DOLBY, // Dolby
        DOLBYDIGITAL, // DolbyDigital
        THX, // Thx
        ATMOS, // Atmos
    };
    extern void to_json(json_t&, const OAIProgramAudio&);
    extern void from_json(const json_t&, OAIProgramAudio&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIProgramAudio);
