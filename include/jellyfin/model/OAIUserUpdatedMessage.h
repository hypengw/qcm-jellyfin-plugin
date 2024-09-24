#pragma once

/*
 * OAIUserUpdatedMessage.h
 * name: UserUpdatedMessage
 * schemaName: UserUpdatedMessage
 * classFilename: UserUpdatedMessage
 * classVarName: UserUpdatedMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * User updated message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"
#include "jellyfin/model/OAIUserDto.h"
#include <string>



namespace jellyfin::model {
class OAIUserDto;


    class OAIUserUpdatedMessage {
    public:
    
        // Gets or sets the data.
        std::optional<OAIUserDto> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIUserUpdatedMessage();
        ~OAIUserUpdatedMessage();
    };
    extern void to_json(json_t&, const OAIUserUpdatedMessage&);
    extern void from_json(const json_t&, OAIUserUpdatedMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIUserUpdatedMessage);
