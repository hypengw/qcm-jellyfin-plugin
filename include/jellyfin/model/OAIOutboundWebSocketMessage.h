#pragma once

/*
 * OAIOutboundWebSocketMessage.h
 * name: OutboundWebSocketMessage
 * schemaName: OutboundWebSocketMessage
 * classFilename: OutboundWebSocketMessage
 * classVarName: OutboundWebSocketMessage
 * dataType: OAIOneOfActivityLogEntryMessageForceKeepAliveMessageGeneralCommandMessageLibraryChangedMessageOutboundKeepAliveMessagePlayMessagePlaystateMessagePluginInstallationCancelledMessagePluginInstallationCompletedMessagePluginInstallationFailedMessagePluginInstallingMessagePluginUninstalledMessageRefreshProgressMessageRestartRequiredMessageScheduledTaskEndedMessageScheduledTasksInfoMessageSeriesTimerCancelledMessageSeriesTimerCreatedMessageServerRestartingMessageServerShuttingDownMessageSessionsMessageSyncPlayCommandMessageSyncPlayGroupUpdateCommandMessageTimerCancelledMessageTimerCreatedMessageUserDataChangedMessageUserDeletedMessageUserUpdatedMessage
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Represents the list of possible outbound websocket types
 */

#include <variant>

#include "jellyfin/type.h"


#include "jellyfin/model/OAIActivityLogEntryMessage.h"
#include "jellyfin/model/OAIForceKeepAliveMessage.h"
#include "jellyfin/model/OAIGeneralCommandMessage.h"
#include "jellyfin/model/OAILibraryChangedMessage.h"
#include "jellyfin/model/OAIOutboundKeepAliveMessage.h"
#include "jellyfin/model/OAIPlayMessage.h"
#include "jellyfin/model/OAIPlaystateMessage.h"
#include "jellyfin/model/OAIPluginInstallationCancelledMessage.h"
#include "jellyfin/model/OAIPluginInstallationCompletedMessage.h"
#include "jellyfin/model/OAIPluginInstallationFailedMessage.h"
#include "jellyfin/model/OAIPluginInstallingMessage.h"
#include "jellyfin/model/OAIPluginUninstalledMessage.h"
#include "jellyfin/model/OAIRefreshProgressMessage.h"
#include "jellyfin/model/OAIRestartRequiredMessage.h"
#include "jellyfin/model/OAIScheduledTaskEndedMessage.h"
#include "jellyfin/model/OAIScheduledTasksInfoMessage.h"
#include "jellyfin/model/OAISeriesTimerCancelledMessage.h"
#include "jellyfin/model/OAISeriesTimerCreatedMessage.h"
#include "jellyfin/model/OAIServerRestartingMessage.h"
#include "jellyfin/model/OAIServerShuttingDownMessage.h"
#include "jellyfin/model/OAISessionMessageType.h"
#include "jellyfin/model/OAISessionsMessage.h"
#include "jellyfin/model/OAISyncPlayCommandMessage.h"
#include "jellyfin/model/OAISyncPlayGroupUpdateCommandMessage.h"
#include "jellyfin/model/OAITimerCancelledMessage.h"
#include "jellyfin/model/OAITimerCreatedMessage.h"
#include "jellyfin/model/OAIUserDataChangedMessage.h"
#include "jellyfin/model/OAIUserDeletedMessage.h"
#include "jellyfin/model/OAIUserDto.h"
#include "jellyfin/model/OAIUserUpdatedMessage.h"
#include <string>



namespace jellyfin::model {
class OAIUserDto;

    class OAIOutboundWebSocketMessage
    {
    public:
        OAIOutboundWebSocketMessage() = default;
        ~OAIOutboundWebSocketMessage() = default;

        /// OAIOutboundWebSocketMessage members
        using VariantType = std::variant<OAIActivityLogEntryMessage, OAIForceKeepAliveMessage, OAIGeneralCommandMessage, OAILibraryChangedMessage, OAIOutboundKeepAliveMessage, OAIPlayMessage, OAIPlaystateMessage, OAIPluginInstallationCancelledMessage, OAIPluginInstallationCompletedMessage, OAIPluginInstallationFailedMessage, OAIPluginInstallingMessage, OAIPluginUninstalledMessage, OAIRefreshProgressMessage, OAIRestartRequiredMessage, OAIScheduledTaskEndedMessage, OAIScheduledTasksInfoMessage, OAISeriesTimerCancelledMessage, OAISeriesTimerCreatedMessage, OAIServerRestartingMessage, OAIServerShuttingDownMessage, OAISessionsMessage, OAISyncPlayCommandMessage, OAISyncPlayGroupUpdateCommandMessage, OAITimerCancelledMessage, OAITimerCreatedMessage, OAIUserDataChangedMessage, OAIUserDeletedMessage, OAIUserUpdatedMessage>;

        const VariantType& getVariant() const;
        void setVariant(VariantType value);

    protected:
        VariantType m_variantValue;
    };
    extern void to_json(json_t&, const OAIOutboundWebSocketMessage&);
    extern void from_json(const json_t&, OAIOutboundWebSocketMessage&);

} // namespace jellyfin::model
