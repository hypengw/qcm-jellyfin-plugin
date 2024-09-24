#pragma once

/*
 * OAITranscodeSeekInfo.h
 * name: TranscodeSeekInfo
 * schemaName: TranscodeSeekInfo
 * classFilename: TranscodeSeekInfo
 * classVarName: TranscodeSeekInfo
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

    enum class OAITranscodeSeekInfo {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        AUTO, // Auto
        BYTES, // Bytes
    };
    extern void to_json(json_t&, const OAITranscodeSeekInfo&);
    extern void from_json(const json_t&, OAITranscodeSeekInfo&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITranscodeSeekInfo);
