#pragma once

/*
 * OAISyncPlayCommandMessage.h
 * name: SyncPlayCommandMessage
 * schemaName: SyncPlayCommandMessage
 * classFilename: SyncPlayCommandMessage
 * classVarName: SyncPlayCommandMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Sync play command.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISendCommand.h"
#include "jellyfin/model/OAISessionMessageType.h"
#include <string>



namespace jellyfin::model {
class OAISendCommand;


    class OAISyncPlayCommandMessage {
    public:
    
        // Gets or sets the data.
        std::optional<OAISendCommand> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAISyncPlayCommandMessage();
        ~OAISyncPlayCommandMessage();
    };
    extern void to_json(json_t&, const OAISyncPlayCommandMessage&);
    extern void from_json(const json_t&, OAISyncPlayCommandMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISyncPlayCommandMessage);
