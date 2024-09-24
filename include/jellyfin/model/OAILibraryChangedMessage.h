#pragma once

/*
 * OAILibraryChangedMessage.h
 * name: LibraryChangedMessage
 * schemaName: LibraryChangedMessage
 * classFilename: LibraryChangedMessage
 * classVarName: LibraryChangedMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Library changed message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAILibraryUpdateInfo.h"
#include "jellyfin/model/OAISessionMessageType.h"
#include <string>



namespace jellyfin::model {
class OAILibraryUpdateInfo;


    class OAILibraryChangedMessage {
    public:
    
        // Gets or sets the data.
        std::optional<OAILibraryUpdateInfo> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAILibraryChangedMessage();
        ~OAILibraryChangedMessage();
    };
    extern void to_json(json_t&, const OAILibraryChangedMessage&);
    extern void from_json(const json_t&, OAILibraryChangedMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAILibraryChangedMessage);
