#pragma once

/*
 * OAIScheduledTaskEndedMessage.h
 * name: ScheduledTaskEndedMessage
 * schemaName: ScheduledTaskEndedMessage
 * classFilename: ScheduledTaskEndedMessage
 * classVarName: ScheduledTaskEndedMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Scheduled task ended message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"
#include "jellyfin/model/OAITaskResult.h"
#include <string>



namespace jellyfin::model {
class OAITaskResult;


    class OAIScheduledTaskEndedMessage {
    public:
    
        // Gets or sets the data.
        std::optional<OAITaskResult> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIScheduledTaskEndedMessage();
        ~OAIScheduledTaskEndedMessage();
    };
    extern void to_json(json_t&, const OAIScheduledTaskEndedMessage&);
    extern void from_json(const json_t&, OAIScheduledTaskEndedMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIScheduledTaskEndedMessage);
