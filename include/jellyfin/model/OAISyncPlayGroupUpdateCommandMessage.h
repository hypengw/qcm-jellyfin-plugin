#pragma once

/*
 * OAISyncPlayGroupUpdateCommandMessage.h
 * name: SyncPlayGroupUpdateCommandMessage
 * schemaName: SyncPlayGroupUpdateCommandMessage
 * classFilename: SyncPlayGroupUpdateCommandMessage
 * classVarName: SyncPlayGroupUpdateCommandMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Untyped sync play command.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIGroupUpdate.h"
#include "jellyfin/model/OAISessionMessageType.h"
#include <string>



namespace jellyfin::model {
class OAIGroupUpdate;


    class OAISyncPlayGroupUpdateCommandMessage {
    public:
    
        // Gets or sets the data.
        std::optional<OAIGroupUpdate> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAISyncPlayGroupUpdateCommandMessage();
        ~OAISyncPlayGroupUpdateCommandMessage();
    };
    extern void to_json(json_t&, const OAISyncPlayGroupUpdateCommandMessage&);
    extern void from_json(const json_t&, OAISyncPlayGroupUpdateCommandMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISyncPlayGroupUpdateCommandMessage);
