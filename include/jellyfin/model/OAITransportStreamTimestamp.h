#pragma once

/*
 * OAITransportStreamTimestamp.h
 * name: TransportStreamTimestamp
 * schemaName: TransportStreamTimestamp
 * classFilename: TransportStreamTimestamp
 * classVarName: TransportStreamTimestamp
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

    enum class OAITransportStreamTimestamp {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        NONE, // None
        ZERO, // Zero
        VALID, // Valid
    };
    extern void to_json(json_t&, const OAITransportStreamTimestamp&);
    extern void from_json(const json_t&, OAITransportStreamTimestamp&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITransportStreamTimestamp);
