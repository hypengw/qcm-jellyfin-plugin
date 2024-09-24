#pragma once

/*
 * OAIServerRestartingMessage.h
 * name: ServerRestartingMessage
 * schemaName: ServerRestartingMessage
 * classFilename: ServerRestartingMessage
 * classVarName: ServerRestartingMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Server restarting down message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"
#include <string>



namespace jellyfin::model {


    class OAIServerRestartingMessage {
    public:
    
        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIServerRestartingMessage();
        ~OAIServerRestartingMessage();
    };
    extern void to_json(json_t&, const OAIServerRestartingMessage&);
    extern void from_json(const json_t&, OAIServerRestartingMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIServerRestartingMessage);
