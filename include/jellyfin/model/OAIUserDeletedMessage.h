#pragma once

/*
 * OAIUserDeletedMessage.h
 * name: UserDeletedMessage
 * schemaName: UserDeletedMessage
 * classFilename: UserDeletedMessage
 * classVarName: UserDeletedMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * User deleted message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"
#include <string>



namespace jellyfin::model {


    class OAIUserDeletedMessage {
    public:
    
        // Gets or sets the data.
        std::string Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIUserDeletedMessage();
        ~OAIUserDeletedMessage();
    };
    extern void to_json(json_t&, const OAIUserDeletedMessage&);
    extern void from_json(const json_t&, OAIUserDeletedMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIUserDeletedMessage);
