#pragma once

/*
 * OAIForceKeepAliveMessage.h
 * name: ForceKeepAliveMessage
 * schemaName: ForceKeepAliveMessage
 * classFilename: ForceKeepAliveMessage
 * classVarName: ForceKeepAliveMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Force keep alive websocket messages.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIForceKeepAliveMessage {
    public:
    
        // Gets or sets the data.
        std::int32_t Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIForceKeepAliveMessage();
        ~OAIForceKeepAliveMessage();
    };
    extern void to_json(json_t&, const OAIForceKeepAliveMessage&);
    extern void from_json(const json_t&, OAIForceKeepAliveMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIForceKeepAliveMessage);
