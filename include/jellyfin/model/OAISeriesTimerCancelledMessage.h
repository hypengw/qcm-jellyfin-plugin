#pragma once

/*
 * OAISeriesTimerCancelledMessage.h
 * name: SeriesTimerCancelledMessage
 * schemaName: SeriesTimerCancelledMessage
 * classFilename: SeriesTimerCancelledMessage
 * classVarName: SeriesTimerCancelledMessage
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Series timer cancelled message.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISessionMessageType.h"
#include "jellyfin/model/OAITimerEventInfo.h"
#include <string>



namespace jellyfin::model {
class OAITimerEventInfo;


    class OAISeriesTimerCancelledMessage {
    public:
    
        // Gets or sets the data.
        std::optional<OAITimerEventInfo> Data;

        // Gets or sets the message id.
        std::string MessageId;

        // The different kinds of messages that are used in the WebSocket api.
        OAISessionMessageType MessageType;

        OAISeriesTimerCancelledMessage();
        ~OAISeriesTimerCancelledMessage();
    };
    extern void to_json(json_t&, const OAISeriesTimerCancelledMessage&);
    extern void from_json(const json_t&, OAISeriesTimerCancelledMessage&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISeriesTimerCancelledMessage);
