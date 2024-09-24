#pragma once

/*
 * OAISessionsStopMessage.h
 * name: SessionsStopMessage
 * schemaName: SessionsStopMessage
 * classFilename: SessionsStopMessage
 * classVarName: SessionsStopMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Sessions stop message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"



namespace jellyfin::model {


    class OAISessionsStopMessage {
    public:
    
        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAISessionsStopMessage();
        ~OAISessionsStopMessage();
    };
    extern void to_json(json_t&, const OAISessionsStopMessage&);
    extern void from_json(const json_t&, OAISessionsStopMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISessionsStopMessage);
