#pragma once

/*
 * OAIEncodingContext.h
 * name: EncodingContext
 * schemaName: EncodingContext
 * classFilename: EncodingContext
 * classVarName: EncodingContext
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

    enum class OAIEncodingContext {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        STREAMING, // Streaming
        STATIC, // Static
    };
    extern void to_json(json_t&, const OAIEncodingContext&);
    extern void from_json(const json_t&, OAIEncodingContext&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIEncodingContext);
