#pragma once

/*
 * OAIScheduledTasksInfoMessage.h
 * name: ScheduledTasksInfoMessage
 * schemaName: ScheduledTasksInfoMessage
 * classFilename: ScheduledTasksInfoMessage
 * classVarName: ScheduledTasksInfoMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Scheduled tasks info message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"
#include "jellyfin/model/OAITaskInfo.h"
#include <string>
#include <vector>



namespace jellyfin::model {
class OAITaskInfo;


    class OAIScheduledTasksInfoMessage {
    public:
    
        // Gets or sets the data.
        std::optional<std::vector<OAITaskInfo>> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIScheduledTasksInfoMessage();
        ~OAIScheduledTasksInfoMessage();
    };
    extern void to_json(json_t&, const OAIScheduledTasksInfoMessage&);
    extern void from_json(const json_t&, OAIScheduledTasksInfoMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIScheduledTasksInfoMessage);
