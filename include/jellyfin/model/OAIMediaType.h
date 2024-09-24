#pragma once

/*
 * OAIMediaType.h
 * name: MediaType
 * schemaName: MediaType
 * classFilename: MediaType
 * classVarName: MediaType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Media types.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIMediaType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        UNKNOWN, // Unknown
        VIDEO, // Video
        AUDIO, // Audio
        PHOTO, // Photo
        BOOK, // Book
    };
    extern void to_json(json_t&, const OAIMediaType&);
    extern void from_json(const json_t&, OAIMediaType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMediaType);
