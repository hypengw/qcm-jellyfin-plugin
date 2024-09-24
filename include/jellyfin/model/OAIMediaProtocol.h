#pragma once

/*
 * OAIMediaProtocol.h
 * name: MediaProtocol
 * schemaName: MediaProtocol
 * classFilename: MediaProtocol
 * classVarName: MediaProtocol
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

    enum class OAIMediaProtocol {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        FILE, // File
        HTTP, // Http
        RTMP, // Rtmp
        RTSP, // Rtsp
        UDP, // Udp
        RTP, // Rtp
        FTP, // Ftp
    };
    extern void to_json(json_t&, const OAIMediaProtocol&);
    extern void from_json(const json_t&, OAIMediaProtocol&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMediaProtocol);
