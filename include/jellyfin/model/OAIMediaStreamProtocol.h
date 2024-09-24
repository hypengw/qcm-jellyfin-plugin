#pragma once

/*
 * OAIMediaStreamProtocol.h
 * name: MediaStreamProtocol
 * schemaName: MediaStreamProtocol
 * classFilename: MediaStreamProtocol
 * classVarName: MediaStreamProtocol
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Media streaming protocol.  Lowercase for backwards compatibility.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIMediaStreamProtocol {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        HTTP, // http
        HLS, // hls
    };
    extern void to_json(json_t&, const OAIMediaStreamProtocol&);
    extern void from_json(const json_t&, OAIMediaStreamProtocol&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMediaStreamProtocol);
