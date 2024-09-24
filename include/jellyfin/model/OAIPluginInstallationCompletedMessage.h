#pragma once

/*
 * OAIPluginInstallationCompletedMessage.h
 * name: PluginInstallationCompletedMessage
 * schemaName: PluginInstallationCompletedMessage
 * classFilename: PluginInstallationCompletedMessage
 * classVarName: PluginInstallationCompletedMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Plugin installation completed message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIInstallationInfo.h"
#include "jellyfin/model/OAISessionMessageType.h"
#include <string>



namespace jellyfin::model {
class OAIInstallationInfo;


    class OAIPluginInstallationCompletedMessage {
    public:
    
        // Gets or sets the data.
        std::optional<OAIInstallationInfo> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIPluginInstallationCompletedMessage();
        ~OAIPluginInstallationCompletedMessage();
    };
    extern void to_json(json_t&, const OAIPluginInstallationCompletedMessage&);
    extern void from_json(const json_t&, OAIPluginInstallationCompletedMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPluginInstallationCompletedMessage);
