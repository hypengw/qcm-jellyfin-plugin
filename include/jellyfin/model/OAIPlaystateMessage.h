#pragma once

/*
 * OAIPlaystateMessage.h
 * name: PlaystateMessage
 * schemaName: PlaystateMessage
 * classFilename: PlaystateMessage
 * classVarName: PlaystateMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Playstate message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIPlaystateRequest.h"
#include "jellyfin/model/OAISessionMessageType.h"
#include <string>



namespace jellyfin::model {
class OAIPlaystateRequest;


    class OAIPlaystateMessage {
    public:
    
        // Gets or sets the data.
        std::optional<OAIPlaystateRequest> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIPlaystateMessage();
        ~OAIPlaystateMessage();
    };
    extern void to_json(json_t&, const OAIPlaystateMessage&);
    extern void from_json(const json_t&, OAIPlaystateMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlaystateMessage);
