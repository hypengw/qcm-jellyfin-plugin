#pragma once

/*
 * OAITimerCreatedMessage.h
 * name: TimerCreatedMessage
 * schemaName: TimerCreatedMessage
 * classFilename: TimerCreatedMessage
 * classVarName: TimerCreatedMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Timer created message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"
#include "jellyfin/model/OAITimerEventInfo.h"
#include <string>



namespace jellyfin::model {
class OAITimerEventInfo;


    class OAITimerCreatedMessage {
    public:
    
        // Gets or sets the data.
        std::optional<OAITimerEventInfo> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAITimerCreatedMessage();
        ~OAITimerCreatedMessage();
    };
    extern void to_json(json_t&, const OAITimerCreatedMessage&);
    extern void from_json(const json_t&, OAITimerCreatedMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITimerCreatedMessage);
