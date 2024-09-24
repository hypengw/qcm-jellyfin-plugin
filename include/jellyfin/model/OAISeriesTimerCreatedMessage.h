#pragma once

/*
 * OAISeriesTimerCreatedMessage.h
 * name: SeriesTimerCreatedMessage
 * schemaName: SeriesTimerCreatedMessage
 * classFilename: SeriesTimerCreatedMessage
 * classVarName: SeriesTimerCreatedMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Series timer created message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"
#include "jellyfin/model/OAITimerEventInfo.h"
#include <string>



namespace jellyfin::model {
class OAITimerEventInfo;


    class OAISeriesTimerCreatedMessage {
    public:
    
        // Gets or sets the data.
        std::optional<OAITimerEventInfo> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAISeriesTimerCreatedMessage();
        ~OAISeriesTimerCreatedMessage();
    };
    extern void to_json(json_t&, const OAISeriesTimerCreatedMessage&);
    extern void from_json(const json_t&, OAISeriesTimerCreatedMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISeriesTimerCreatedMessage);
