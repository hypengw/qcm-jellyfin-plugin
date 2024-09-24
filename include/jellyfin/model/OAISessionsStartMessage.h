#pragma once

/*
 * OAISessionsStartMessage.h
 * name: SessionsStartMessage
 * schemaName: SessionsStartMessage
 * classFilename: SessionsStartMessage
 * classVarName: SessionsStartMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Sessions start message.  Data is the timing data encoded as \&quot;$initialDelay,$interval\&quot; in ms.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"
#include <string>



namespace jellyfin::model {


    class OAISessionsStartMessage {
    public:
    
        // Gets or sets the data.
        std::optional<std::string> Data;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAISessionsStartMessage();
        ~OAISessionsStartMessage();
    };
    extern void to_json(json_t&, const OAISessionsStartMessage&);
    extern void from_json(const json_t&, OAISessionsStartMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISessionsStartMessage);
