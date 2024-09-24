#pragma once

/*
 * OAISessionsMessage.h
 * name: SessionsMessage
 * schemaName: SessionsMessage
 * classFilename: SessionsMessage
 * classVarName: SessionsMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Sessions message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionInfo.h"
#include "jellyfin/model/OAISessionMessageType.h"
#include <string>
#include <vector>



namespace jellyfin::model {
class OAISessionInfo;


    class OAISessionsMessage {
    public:
    
        // Gets or sets the data.
        std::optional<std::vector<OAISessionInfo>> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAISessionsMessage();
        ~OAISessionsMessage();
    };
    extern void to_json(json_t&, const OAISessionsMessage&);
    extern void from_json(const json_t&, OAISessionsMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISessionsMessage);
