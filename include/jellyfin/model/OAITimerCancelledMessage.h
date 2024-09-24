#pragma once

/*
 * OAITimerCancelledMessage.h
 * name: TimerCancelledMessage
 * schemaName: TimerCancelledMessage
 * classFilename: TimerCancelledMessage
 * classVarName: TimerCancelledMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Timer cancelled message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"
#include "jellyfin/model/OAITimerEventInfo.h"
#include <string>



namespace jellyfin::model {
class OAITimerEventInfo;


    class OAITimerCancelledMessage {
    public:
    
        // Gets or sets the data.
        std::optional<OAITimerEventInfo> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAITimerCancelledMessage();
        ~OAITimerCancelledMessage();
    };
    extern void to_json(json_t&, const OAITimerCancelledMessage&);
    extern void from_json(const json_t&, OAITimerCancelledMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITimerCancelledMessage);
