#pragma once

/*
 * OAIActivityLogEntryStartMessage.h
 * name: ActivityLogEntryStartMessage
 * schemaName: ActivityLogEntryStartMessage
 * classFilename: ActivityLogEntryStartMessage
 * classVarName: ActivityLogEntryStartMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Activity log entry start message.  Data is the timing data encoded as \&quot;$initialDelay,$interval\&quot; in ms.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"
#include <string>



namespace jellyfin::model {


    class OAIActivityLogEntryStartMessage {
    public:
    
        // Gets or sets the data.
        std::optional<std::string> Data;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIActivityLogEntryStartMessage();
        ~OAIActivityLogEntryStartMessage();
    };
    extern void to_json(json_t&, const OAIActivityLogEntryStartMessage&);
    extern void from_json(const json_t&, OAIActivityLogEntryStartMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIActivityLogEntryStartMessage);
