#pragma once

/*
 * OAIPluginInstallationCancelledMessage.h
 * name: PluginInstallationCancelledMessage
 * schemaName: PluginInstallationCancelledMessage
 * classFilename: PluginInstallationCancelledMessage
 * classVarName: PluginInstallationCancelledMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Plugin installation cancelled message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIInstallationInfo.h"
#include "jellyfin/model/OAISessionMessageType.h"
#include <string>



namespace jellyfin::model {
class OAIInstallationInfo;


    class OAIPluginInstallationCancelledMessage {
    public:
    
        // Gets or sets the data.
        std::optional<OAIInstallationInfo> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIPluginInstallationCancelledMessage();
        ~OAIPluginInstallationCancelledMessage();
    };
    extern void to_json(json_t&, const OAIPluginInstallationCancelledMessage&);
    extern void from_json(const json_t&, OAIPluginInstallationCancelledMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPluginInstallationCancelledMessage);
