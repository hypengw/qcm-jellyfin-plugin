#pragma once

/*
 * OAIActivityLogEntryMessage.h
 * name: ActivityLogEntryMessage
 * schemaName: ActivityLogEntryMessage
 * classFilename: ActivityLogEntryMessage
 * classVarName: ActivityLogEntryMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Activity log created message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIActivityLogEntry.h"
#include "jellyfin/model/OAISessionMessageType.h"
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIActivityLogEntry;


    class OAIActivityLogEntryMessage {
    public:
    
        // Gets or sets the data.
        std::optional<std::vector<OAIActivityLogEntry>> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIActivityLogEntryMessage();
        ~OAIActivityLogEntryMessage();
    };
    extern void to_json(json_t&, const OAIActivityLogEntryMessage&);
    extern void from_json(const json_t&, OAIActivityLogEntryMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIActivityLogEntryMessage);
