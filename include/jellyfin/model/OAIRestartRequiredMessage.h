#pragma once

/*
 * OAIRestartRequiredMessage.h
 * name: RestartRequiredMessage
 * schemaName: RestartRequiredMessage
 * classFilename: RestartRequiredMessage
 * classVarName: RestartRequiredMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Restart required.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"
#include <string>



namespace jellyfin::model {


    class OAIRestartRequiredMessage {
    public:
    
        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIRestartRequiredMessage();
        ~OAIRestartRequiredMessage();
    };
    extern void to_json(json_t&, const OAIRestartRequiredMessage&);
    extern void from_json(const json_t&, OAIRestartRequiredMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIRestartRequiredMessage);
