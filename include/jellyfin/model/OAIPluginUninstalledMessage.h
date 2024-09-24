#pragma once

/*
 * OAIPluginUninstalledMessage.h
 * name: PluginUninstalledMessage
 * schemaName: PluginUninstalledMessage
 * classFilename: PluginUninstalledMessage
 * classVarName: PluginUninstalledMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Plugin uninstalled message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIPluginInfo.h"
#include "jellyfin/model/OAISessionMessageType.h"
#include <string>



namespace jellyfin::model {
class OAIPluginInfo;


    class OAIPluginUninstalledMessage {
    public:
    
        // Gets or sets the data.
        std::optional<OAIPluginInfo> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAIPluginUninstalledMessage();
        ~OAIPluginUninstalledMessage();
    };
    extern void to_json(json_t&, const OAIPluginUninstalledMessage&);
    extern void from_json(const json_t&, OAIPluginUninstalledMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPluginUninstalledMessage);
