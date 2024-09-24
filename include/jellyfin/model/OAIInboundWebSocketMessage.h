#pragma once

/*
 * OAIInboundWebSocketMessage.h
 * name: InboundWebSocketMessage
 * schemaName: InboundWebSocketMessage
 * classFilename: InboundWebSocketMessage
 * classVarName: InboundWebSocketMessage
 * dataType: OAIOneOfActivityLogEntryStartMessageActivityLogEntryStopMessageInboundKeepAliveMessageScheduledTasksInfoStartMessageScheduledTasksInfoStopMessageSessionsStartMessageSessionsStopMessage
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Represents the list of possible inbound websocket types
 */

#include <variant>

#include "jellyfin/type.h"


#include "jellyfin/model/OAIActivityLogEntryStartMessage.h"
#include "jellyfin/model/OAIActivityLogEntryStopMessage.h"
#include "jellyfin/model/OAIInboundKeepAliveMessage.h"
#include "jellyfin/model/OAIScheduledTasksInfoStartMessage.h"
#include "jellyfin/model/OAIScheduledTasksInfoStopMessage.h"
#include "jellyfin/model/OAISessionMessageType.h"
#include "jellyfin/model/OAISessionsStartMessage.h"
#include "jellyfin/model/OAISessionsStopMessage.h"
#include <string>



namespace jellyfin::model {

    class OAIInboundWebSocketMessage
    {
    public:
        OAIInboundWebSocketMessage() = default;
        ~OAIInboundWebSocketMessage() = default;

        /// OAIInboundWebSocketMessage members
        using VariantType = std::variant<OAIActivityLogEntryStartMessage, OAIActivityLogEntryStopMessage, OAIInboundKeepAliveMessage, OAIScheduledTasksInfoStartMessage, OAIScheduledTasksInfoStopMessage, OAISessionsStartMessage, OAISessionsStopMessage>;

        const VariantType& getVariant() const;
        void setVariant(VariantType value);

    protected:
        VariantType m_variantValue;
    };
    extern void to_json(json_t&, const OAIInboundWebSocketMessage&);
    extern void from_json(const json_t&, OAIInboundWebSocketMessage&);

} // namespace jellyfin::model
