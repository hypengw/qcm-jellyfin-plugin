#pragma once

/*
 * OAISubtitleDeliveryMethod.h
 * name: SubtitleDeliveryMethod
 * schemaName: SubtitleDeliveryMethod
 * classFilename: SubtitleDeliveryMethod
 * classVarName: SubtitleDeliveryMethod
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Delivery method to use during playback of a specific subtitle format.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAISubtitleDeliveryMethod {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        ENCODE, // Encode
        EMBED, // Embed
        EXTERNAL, // External
        HLS, // Hls
        DROP, // Drop
    };
    extern void to_json(json_t&, const OAISubtitleDeliveryMethod&);
    extern void from_json(const json_t&, OAISubtitleDeliveryMethod&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISubtitleDeliveryMethod);
