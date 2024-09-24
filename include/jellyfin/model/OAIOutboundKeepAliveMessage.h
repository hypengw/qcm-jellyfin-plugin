#pragma once

/*
 * OAIOutboundKeepAliveMessage.h
 * name: OutboundKeepAliveMessage
 * schemaName: OutboundKeepAliveMessage
 * classFilename: OutboundKeepAliveMessage
 * classVarName: OutboundKeepAliveMessage
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
#include <string>



namespace jellyfin::model {


    class OAIOutboundKeepAliveMessage {
    public:
    
        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIOutboundKeepAliveMessage();
        ~OAIOutboundKeepAliveMessage();
    };
    extern void to_json(json_t&, const OAIOutboundKeepAliveMessage&);
    extern void from_json(const json_t&, OAIOutboundKeepAliveMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIOutboundKeepAliveMessage);
