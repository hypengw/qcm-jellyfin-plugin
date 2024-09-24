#pragma once
/*
 * OAISessionApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIBaseItemKind.h"
#include "jellyfin/model/OAIClientCapabilitiesDto.h"
#include "jellyfin/model/OAIGeneralCommand.h"
#include "jellyfin/model/OAIGeneralCommandType.h"
#include "jellyfin/model/OAIMediaType.h"
#include "jellyfin/model/OAIMessageCommand.h"
#include "jellyfin/model/OAINameIdPair.h"
#include "jellyfin/model/OAIPlayCommand.h"
#include "jellyfin/model/OAIPlaystateCommand.h"
#include "jellyfin/model/OAISessionInfo.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_addUserToSession = std::nullptr_t;
using return_type_displayContent = std::nullptr_t;
using return_type_getAuthProviders = std::vector<OAINameIdPair>;
using return_type_getPasswordResetProviders = std::vector<OAINameIdPair>;
using return_type_getSessions = std::vector<OAISessionInfo>;
using return_type_play = std::nullptr_t;
using return_type_postCapabilities = std::nullptr_t;
using return_type_postFullCapabilities = std::nullptr_t;
using return_type_removeUserFromSession = std::nullptr_t;
using return_type_reportSessionEnded = std::nullptr_t;
using return_type_reportViewing = std::nullptr_t;
using return_type_sendFullGeneralCommand = std::nullptr_t;
using return_type_sendGeneralCommand = std::nullptr_t;
using return_type_sendMessageCommand = std::nullptr_t;
using return_type_sendPlaystateCommand = std::nullptr_t;
using return_type_sendSystemCommand = std::nullptr_t;
}

namespace api::param 
{
struct addUserToSession {
    std::string sessionId; // The session id.
    std::string userId; // The user id.
};
struct displayContent {
    std::string sessionId; // The session Id.
    OAIBaseItemKind itemType; // The type of item to browse to.
    std::string itemId; // The Id of the item.
    std::string itemName; // The name of the item.
};
struct getAuthProviders {
};
struct getPasswordResetProviders {
};
struct getSessions {
    std::optional<std::string> controllableByUserId; // Filter by sessions that a given user is allowed to remote control.
    std::optional<std::string> deviceId; // Filter by device Id.
    std::optional<std::int32_t> activeWithinSeconds; // Optional. Filter by sessions that were active in the last n seconds.
};
struct play {
    std::string sessionId; // The session id.
    OAIPlayCommand playCommand; // The type of play command to issue (PlayNow, PlayNext, PlayLast). Clients who have not yet implemented play next and play last may play now.
    std::vector<std::string> itemIds; // The ids of the items to play, comma delimited.
    std::optional<std::int64_t> startPositionTicks; // The starting position of the first item.
    std::optional<std::string> mediaSourceId; // Optional. The media source id.
    std::optional<std::int32_t> audioStreamIndex; // Optional. The index of the audio stream to play.
    std::optional<std::int32_t> subtitleStreamIndex; // Optional. The index of the subtitle stream to play.
    std::optional<std::int32_t> startIndex; // Optional. The start index.
};
struct postCapabilities {
    std::optional<std::string> id; // The session id.
    std::optional<std::vector<OAIMediaType>> playableMediaTypes; // A list of playable media types, comma delimited. Audio, Video, Book, Photo.
    std::optional<std::vector<OAIGeneralCommandType>> supportedCommands; // A list of supported remote control commands, comma delimited.
    std::optional<bool> supportsMediaControl; // Determines whether media can be played remotely..
    std::optional<bool> supportsPersistentIdentifier; // Determines whether the device supports a unique identifier.
};
struct postFullCapabilities {
    OAIClientCapabilitiesDto body; // The MediaBrowser.Model.Session.ClientCapabilities.
    std::optional<std::string> id; // The session id.
};
struct removeUserFromSession {
    std::string sessionId; // The session id.
    std::string userId; // The user id.
};
struct reportSessionEnded {
};
struct reportViewing {
    std::string itemId; // The item id.
    std::optional<std::string> sessionId; // The session id.
};
struct sendFullGeneralCommand {
    std::string sessionId; // The session id.
    OAIGeneralCommand body; // The MediaBrowser.Model.Session.GeneralCommand.
};
struct sendGeneralCommand {
    std::string sessionId; // The session id.
    OAIGeneralCommandType command; // The command to send.
};
struct sendMessageCommand {
    std::string sessionId; // The session id.
    OAIMessageCommand body; // The MediaBrowser.Model.Session.MessageCommand object containing Header, Message Text, and TimeoutMs.
};
struct sendPlaystateCommand {
    std::string sessionId; // The session id.
    OAIPlaystateCommand command; // The MediaBrowser.Model.Session.PlaystateCommand.
    std::optional<std::int64_t> seekPositionTicks; // The optional position ticks.
    std::optional<std::string> controllingUserId; // The optional controlling user id.
};
struct sendSystemCommand {
    std::string sessionId; // The session id.
    OAIGeneralCommandType command; // The command to send.
};
}

namespace api 
{
// Adds an additional user to a session.
struct addUserToSession {
public:
    using in_type                      = param::addUserToSession;
    using out_type                     = model::return_type_addUserToSession;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Sessions/{}/User/{}"sv,
            input.sessionId,
            input.userId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Session
 * defaultResponse: 
 */
};
// Instructs a session to browse to an item or view.
struct displayContent {
public:
    using in_type                      = param::displayContent;
    using out_type                     = model::return_type_displayContent;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Sessions/{}/Viewing"sv,
            input.sessionId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("itemType", convert_from<std::string>(input.itemType));
        p.set_param("itemId", convert_from<std::string>(input.itemId));
        p.set_param("itemName", convert_from<std::string>(input.itemName));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Session
 * defaultResponse: 
 */
};
// Get all auth providers.
struct getAuthProviders {
public:
    using in_type                      = param::getAuthProviders;
    using out_type                     = model::return_type_getAuthProviders;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Auth/Providers"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;OAINameIdPair&gt;
 * returnFormat: 
 * returnBaseType: OAINameIdPair
 * returnContainer: array
 * baseName: Session
 * defaultResponse: {}
 */
};
// Get all password reset providers.
struct getPasswordResetProviders {
public:
    using in_type                      = param::getPasswordResetProviders;
    using out_type                     = model::return_type_getPasswordResetProviders;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Auth/PasswordResetProviders"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;OAINameIdPair&gt;
 * returnFormat: 
 * returnBaseType: OAINameIdPair
 * returnContainer: array
 * baseName: Session
 * defaultResponse: {}
 */
};
// Gets a list of sessions.
struct getSessions {
public:
    using in_type                      = param::getSessions;
    using out_type                     = model::return_type_getSessions;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Sessions"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.controllableByUserId)
            p.set_param("controllableByUserId", convert_from<std::string>(input.controllableByUserId.value()));
        if(input.deviceId)
            p.set_param("deviceId", convert_from<std::string>(input.deviceId.value()));
        if(input.activeWithinSeconds)
            p.set_param("activeWithinSeconds", convert_from<std::string>(input.activeWithinSeconds.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;OAISessionInfo&gt;
 * returnFormat: 
 * returnBaseType: OAISessionInfo
 * returnContainer: array
 * baseName: Session
 * defaultResponse: {}
 */
};
// Instructs a session to play an item.
struct play {
public:
    using in_type                      = param::play;
    using out_type                     = model::return_type_play;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Sessions/{}/Playing"sv,
            input.sessionId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("playCommand", convert_from<std::string>(input.playCommand));
        p.set_param("itemIds", input.itemIds);
        if(input.startPositionTicks)
            p.set_param("startPositionTicks", convert_from<std::string>(input.startPositionTicks.value()));
        if(input.mediaSourceId)
            p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId.value()));
        if(input.audioStreamIndex)
            p.set_param("audioStreamIndex", convert_from<std::string>(input.audioStreamIndex.value()));
        if(input.subtitleStreamIndex)
            p.set_param("subtitleStreamIndex", convert_from<std::string>(input.subtitleStreamIndex.value()));
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Session
 * defaultResponse: 
 */
};
// Updates capabilities for a device.
struct postCapabilities {
public:
    using in_type                      = param::postCapabilities;
    using out_type                     = model::return_type_postCapabilities;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Sessions/Capabilities"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.id)
            p.set_param("id", convert_from<std::string>(input.id.value()));
        if(input.playableMediaTypes)
            p.set_param("playableMediaTypes", input.playableMediaTypes.value());
        if(input.supportedCommands)
            p.set_param("supportedCommands", input.supportedCommands.value());
        if(input.supportsMediaControl)
            p.set_param("supportsMediaControl", convert_from<std::string>(input.supportsMediaControl.value()));
        if(input.supportsPersistentIdentifier)
            p.set_param("supportsPersistentIdentifier", convert_from<std::string>(input.supportsPersistentIdentifier.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Session
 * defaultResponse: 
 */
};
// Updates capabilities for a device.
struct postFullCapabilities {
public:
    using in_type                      = param::postFullCapabilities;
    using out_type                     = model::return_type_postFullCapabilities;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Sessions/Capabilities/Full"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.id)
            p.set_param("id", convert_from<std::string>(input.id.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Session
 * defaultResponse: 
 */
};
// Removes an additional user from a session.
struct removeUserFromSession {
public:
    using in_type                      = param::removeUserFromSession;
    using out_type                     = model::return_type_removeUserFromSession;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/Sessions/{}/User/{}"sv,
            input.sessionId,
            input.userId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Session
 * defaultResponse: 
 */
};
// Reports that a session has ended.
struct reportSessionEnded {
public:
    using in_type                      = param::reportSessionEnded;
    using out_type                     = model::return_type_reportSessionEnded;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Sessions/Logout"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Session
 * defaultResponse: 
 */
};
// Reports that a session is viewing an item.
struct reportViewing {
public:
    using in_type                      = param::reportViewing;
    using out_type                     = model::return_type_reportViewing;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Sessions/Viewing"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.sessionId)
            p.set_param("sessionId", convert_from<std::string>(input.sessionId.value()));
        p.set_param("itemId", convert_from<std::string>(input.itemId));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Session
 * defaultResponse: 
 */
};
// Issues a full general command to a client.
struct sendFullGeneralCommand {
public:
    using in_type                      = param::sendFullGeneralCommand;
    using out_type                     = model::return_type_sendFullGeneralCommand;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Sessions/{}/Command"sv,
            input.sessionId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Session
 * defaultResponse: 
 */
};
// Issues a general command to a client.
struct sendGeneralCommand {
public:
    using in_type                      = param::sendGeneralCommand;
    using out_type                     = model::return_type_sendGeneralCommand;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Sessions/{}/Command/{}"sv,
            input.sessionId,
            input.command
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Session
 * defaultResponse: 
 */
};
// Issues a command to a client to display a message to the user.
struct sendMessageCommand {
public:
    using in_type                      = param::sendMessageCommand;
    using out_type                     = model::return_type_sendMessageCommand;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Sessions/{}/Message"sv,
            input.sessionId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Session
 * defaultResponse: 
 */
};
// Issues a playstate command to a client.
struct sendPlaystateCommand {
public:
    using in_type                      = param::sendPlaystateCommand;
    using out_type                     = model::return_type_sendPlaystateCommand;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Sessions/{}/Playing/{}"sv,
            input.sessionId,
            input.command
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.seekPositionTicks)
            p.set_param("seekPositionTicks", convert_from<std::string>(input.seekPositionTicks.value()));
        if(input.controllingUserId)
            p.set_param("controllingUserId", convert_from<std::string>(input.controllingUserId.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Session
 * defaultResponse: 
 */
};
// Issues a system command to a client.
struct sendSystemCommand {
public:
    using in_type                      = param::sendSystemCommand;
    using out_type                     = model::return_type_sendSystemCommand;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Sessions/{}/System/{}"sv,
            input.sessionId,
            input.command
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Session
 * defaultResponse: 
 */
};
}
}
