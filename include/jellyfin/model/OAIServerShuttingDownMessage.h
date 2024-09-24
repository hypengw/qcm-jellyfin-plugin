#pragma once

/*
 * OAIServerShuttingDownMessage.h
 * name: ServerShuttingDownMessage
 * schemaName: ServerShuttingDownMessage
 * classFilename: ServerShuttingDownMessage
 * classVarName: ServerShuttingDownMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Server shutting down message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"
#include <string>



namespace jellyfin::model {


    class OAIServerShuttingDownMessage {
    public:
    
        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIServerShuttingDownMessage();
        ~OAIServerShuttingDownMessage();
    };
    extern void to_json(json_t&, const OAIServerShuttingDownMessage&);
    extern void from_json(const json_t&, OAIServerShuttingDownMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIServerShuttingDownMessage);
