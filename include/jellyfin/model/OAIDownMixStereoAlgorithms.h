#pragma once

/*
 * OAIDownMixStereoAlgorithms.h
 * name: DownMixStereoAlgorithms
 * schemaName: DownMixStereoAlgorithms
 * classFilename: DownMixStereoAlgorithms
 * classVarName: DownMixStereoAlgorithms
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * An enum representing an algorithm to downmix 6ch+ to stereo.  Algorithms sourced from https://superuser.com/questions/852400/properly-downmix-5-1-to-stereo-using-ffmpeg/1410620#1410620.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIDownMixStereoAlgorithms {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        NONE, // None
        DAVE750, // Dave750
        NIGHTMODEDIALOGUE, // NightmodeDialogue
    };
    extern void to_json(json_t&, const OAIDownMixStereoAlgorithms&);
    extern void from_json(const json_t&, OAIDownMixStereoAlgorithms&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIDownMixStereoAlgorithms);
