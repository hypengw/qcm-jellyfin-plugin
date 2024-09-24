#pragma once

/*
 * OAIVideoRangeType.h
 * name: VideoRangeType
 * schemaName: VideoRangeType
 * classFilename: VideoRangeType
 * classVarName: VideoRangeType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * An enum representing types of video ranges.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIVideoRangeType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        UNKNOWN, // Unknown
        SDR, // SDR
        HDR10, // HDR10
        HLG, // HLG
        DOVI, // DOVI
        DOVIWITHHDR10, // DOVIWithHDR10
        DOVIWITHHLG, // DOVIWithHLG
        DOVIWITHSDR, // DOVIWithSDR
        HDR10PLUS, // HDR10Plus
    };
    extern void to_json(json_t&, const OAIVideoRangeType&);
    extern void from_json(const json_t&, OAIVideoRangeType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIVideoRangeType);
