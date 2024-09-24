#pragma once

/*
 * OAIScheduledTasksInfoStartMessage.h
 * name: ScheduledTasksInfoStartMessage
 * schemaName: ScheduledTasksInfoStartMessage
 * classFilename: ScheduledTasksInfoStartMessage
 * classVarName: ScheduledTasksInfoStartMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Scheduled tasks info start message.  Data is the timing data encoded as \&quot;$initialDelay,$interval\&quot; in ms.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"
#include <string>



namespace jellyfin::model {


    class OAIScheduledTasksInfoStartMessage {
    public:
    
        // Gets or sets the data.
        std::optional<std::string> Data;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIScheduledTasksInfoStartMessage();
        ~OAIScheduledTasksInfoStartMessage();
    };
    extern void to_json(json_t&, const OAIScheduledTasksInfoStartMessage&);
    extern void from_json(const json_t&, OAIScheduledTasksInfoStartMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIScheduledTasksInfoStartMessage);
