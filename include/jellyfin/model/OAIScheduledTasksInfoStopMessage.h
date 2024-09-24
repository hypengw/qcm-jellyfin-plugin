#pragma once

/*
 * OAIScheduledTasksInfoStopMessage.h
 * name: ScheduledTasksInfoStopMessage
 * schemaName: ScheduledTasksInfoStopMessage
 * classFilename: ScheduledTasksInfoStopMessage
 * classVarName: ScheduledTasksInfoStopMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Scheduled tasks info stop message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"



namespace jellyfin::model {


    class OAIScheduledTasksInfoStopMessage {
    public:
    
        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIScheduledTasksInfoStopMessage();
        ~OAIScheduledTasksInfoStopMessage();
    };
    extern void to_json(json_t&, const OAIScheduledTasksInfoStopMessage&);
    extern void from_json(const json_t&, OAIScheduledTasksInfoStopMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIScheduledTasksInfoStopMessage);
