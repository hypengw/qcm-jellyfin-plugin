#pragma once

/*
 * OAIPluginInstallationFailedMessage.h
 * name: PluginInstallationFailedMessage
 * schemaName: PluginInstallationFailedMessage
 * classFilename: PluginInstallationFailedMessage
 * classVarName: PluginInstallationFailedMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Plugin installation failed message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIInstallationInfo.h"
#include "jellyfin/model/OAISessionMessageType.h"
#include <string>



namespace jellyfin::model {
class OAIInstallationInfo;


    class OAIPluginInstallationFailedMessage {
    public:
    
        // Gets or sets the data.
        std::optional<OAIInstallationInfo> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIPluginInstallationFailedMessage();
        ~OAIPluginInstallationFailedMessage();
    };
    extern void to_json(json_t&, const OAIPluginInstallationFailedMessage&);
    extern void from_json(const json_t&, OAIPluginInstallationFailedMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPluginInstallationFailedMessage);
