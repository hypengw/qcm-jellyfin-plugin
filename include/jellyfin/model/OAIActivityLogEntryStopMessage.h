#pragma once

/*
 * OAIActivityLogEntryStopMessage.h
 * name: ActivityLogEntryStopMessage
 * schemaName: ActivityLogEntryStopMessage
 * classFilename: ActivityLogEntryStopMessage
 * classVarName: ActivityLogEntryStopMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Activity log entry stop message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"



namespace jellyfin::model {


    class OAIActivityLogEntryStopMessage {
    public:
    
        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIActivityLogEntryStopMessage();
        ~OAIActivityLogEntryStopMessage();
    };
    extern void to_json(json_t&, const OAIActivityLogEntryStopMessage&);
    extern void from_json(const json_t&, OAIActivityLogEntryStopMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIActivityLogEntryStopMessage);
