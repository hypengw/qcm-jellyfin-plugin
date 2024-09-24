#pragma once

/*
 * OAIPlayMessage.h
 * name: PlayMessage
 * schemaName: PlayMessage
 * classFilename: PlayMessage
 * classVarName: PlayMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Play command websocket message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIPlayRequest.h"
#include "jellyfin/model/OAISessionMessageType.h"
#include <string>



namespace jellyfin::model {
class OAIPlayRequest;


    class OAIPlayMessage {
    public:
    
        // Gets or sets the data.
        std::optional<OAIPlayRequest> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIPlayMessage();
        ~OAIPlayMessage();
    };
    extern void to_json(json_t&, const OAIPlayMessage&);
    extern void from_json(const json_t&, OAIPlayMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlayMessage);
