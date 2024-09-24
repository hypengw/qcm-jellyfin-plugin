#pragma once

/*
 * OAIPluginInstallingMessage.h
 * name: PluginInstallingMessage
 * schemaName: PluginInstallingMessage
 * classFilename: PluginInstallingMessage
 * classVarName: PluginInstallingMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Package installing message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIInstallationInfo.h"
#include "jellyfin/model/OAISessionMessageType.h"
#include <string>



namespace jellyfin::model {
class OAIInstallationInfo;


    class OAIPluginInstallingMessage {
    public:
    
        // Gets or sets the data.
        std::optional<OAIInstallationInfo> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIPluginInstallingMessage();
        ~OAIPluginInstallingMessage();
    };
    extern void to_json(json_t&, const OAIPluginInstallingMessage&);
    extern void from_json(const json_t&, OAIPluginInstallingMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPluginInstallingMessage);
