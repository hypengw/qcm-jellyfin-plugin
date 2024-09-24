#pragma once

/*
 * OAIUtcTimeResponse.h
 * name: UtcTimeResponse
 * schemaName: UtcTimeResponse
 * classFilename: UtcTimeResponse
 * classVarName: UtcTimeResponse
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class UtcTimeResponse.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAIUtcTimeResponse {
    public:
    
        // Gets the UTC time when request has been received.
        std::string RequestReceptionTime;

        // Gets the UTC time when response has been sent.
        std::string ResponseTransmissionTime;

        OAIUtcTimeResponse();
        ~OAIUtcTimeResponse();
    };
    extern void to_json(json_t&, const OAIUtcTimeResponse&);
    extern void from_json(const json_t&, OAIUtcTimeResponse&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIUtcTimeResponse);
