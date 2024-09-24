#pragma once

/*
 * OAIEmbeddedSubtitleOptions.h
 * name: EmbeddedSubtitleOptions
 * schemaName: EmbeddedSubtitleOptions
 * classFilename: EmbeddedSubtitleOptions
 * classVarName: EmbeddedSubtitleOptions
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * An enum representing the options to disable embedded subs.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIEmbeddedSubtitleOptions {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        ALLOWALL, // AllowAll
        ALLOWTEXT, // AllowText
        ALLOWIMAGE, // AllowImage
        ALLOWNONE, // AllowNone
    };
    extern void to_json(json_t&, const OAIEmbeddedSubtitleOptions&);
    extern void from_json(const json_t&, OAIEmbeddedSubtitleOptions&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIEmbeddedSubtitleOptions);
