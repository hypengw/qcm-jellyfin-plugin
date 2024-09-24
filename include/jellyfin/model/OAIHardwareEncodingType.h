#pragma once

/*
 * OAIHardwareEncodingType.h
 * name: HardwareEncodingType
 * schemaName: HardwareEncodingType
 * classFilename: HardwareEncodingType
 * classVarName: HardwareEncodingType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum HardwareEncodingType.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIHardwareEncodingType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        AMF, // AMF
        QSV, // QSV
        NVENC, // NVENC
        V4L2M2M, // V4L2M2M
        VAAPI, // VAAPI
        VIDEOTOOLBOX, // VideoToolBox
        RKMPP, // RKMPP
    };
    extern void to_json(json_t&, const OAIHardwareEncodingType&);
    extern void from_json(const json_t&, OAIHardwareEncodingType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIHardwareEncodingType);
