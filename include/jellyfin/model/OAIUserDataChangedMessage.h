#pragma once

/*
 * OAIUserDataChangedMessage.h
 * name: UserDataChangedMessage
 * schemaName: UserDataChangedMessage
 * classFilename: UserDataChangedMessage
 * classVarName: UserDataChangedMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * User data changed message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"
#include "jellyfin/model/OAIUserDataChangeInfo.h"
#include <string>



namespace jellyfin::model {
class OAIUserDataChangeInfo;


    class OAIUserDataChangedMessage {
    public:
    
        // Gets or sets the data.
        std::optional<OAIUserDataChangeInfo> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIUserDataChangedMessage();
        ~OAIUserDataChangedMessage();
    };
    extern void to_json(json_t&, const OAIUserDataChangedMessage&);
    extern void from_json(const json_t&, OAIUserDataChangedMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIUserDataChangedMessage);
