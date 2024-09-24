#pragma once

/*
 * OAIWebSocketMessage.h
 * name: WebSocketMessage
 * schemaName: WebSocketMessage
 * classFilename: WebSocketMessage
 * classVarName: WebSocketMessage
 * dataType: OAIOneOfInboundWebSocketMessageOutboundWebSocketMessage
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Represents the possible websocket types
 */

#include <variant>

#include "jellyfin/type.h"


#include "jellyfin/model/OAIInboundWebSocketMessage.h"
#include "jellyfin/model/OAIOutboundWebSocketMessage.h"
#include "jellyfin/model/OAISessionMessageType.h"
#include "jellyfin/model/OAIUserDto.h"
#include <string>



namespace jellyfin::model {
class OAIUserDto;

    class OAIWebSocketMessage
    {
    public:
        OAIWebSocketMessage() = default;
        ~OAIWebSocketMessage() = default;

        /// OAIWebSocketMessage members
        using VariantType = std::variant<OAIInboundWebSocketMessage, OAIOutboundWebSocketMessage>;

        const VariantType& getVariant() const;
        void setVariant(VariantType value);

    protected:
        VariantType m_variantValue;
    };
    extern void to_json(json_t&, const OAIWebSocketMessage&);
    extern void from_json(const json_t&, OAIWebSocketMessage&);

} // namespace jellyfin::model
