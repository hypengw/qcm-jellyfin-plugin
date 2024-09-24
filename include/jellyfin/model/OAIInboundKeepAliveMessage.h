#pragma once

/*
 * OAIInboundKeepAliveMessage.h
 * name: InboundKeepAliveMessage
 * schemaName: InboundKeepAliveMessage
 * classFilename: InboundKeepAliveMessage
 * classVarName: InboundKeepAliveMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Keep alive websocket messages.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"



namespace jellyfin::model {


    class OAIInboundKeepAliveMessage {
    public:
    
        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIInboundKeepAliveMessage();
        ~OAIInboundKeepAliveMessage();
    };
    extern void to_json(json_t&, const OAIInboundKeepAliveMessage&);
    extern void from_json(const json_t&, OAIInboundKeepAliveMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIInboundKeepAliveMessage);
