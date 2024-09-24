#pragma once

/*
 * OAIRefreshProgressMessage.h
 * name: RefreshProgressMessage
 * schemaName: RefreshProgressMessage
 * classFilename: RefreshProgressMessage
 * classVarName: RefreshProgressMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Refresh progress message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"
#include <map>
#include <string>



namespace jellyfin::model {


    class OAIRefreshProgressMessage {
    public:
    
        // Gets or sets the data.
        std::optional<std::map<std::string, std::string>> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIRefreshProgressMessage();
        ~OAIRefreshProgressMessage();
    };
    extern void to_json(json_t&, const OAIRefreshProgressMessage&);
    extern void from_json(const json_t&, OAIRefreshProgressMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIRefreshProgressMessage);
