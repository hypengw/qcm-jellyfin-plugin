#pragma once

/*
 * OAISessionInfo.h
 * name: SessionInfo
 * schemaName: SessionInfo
 * classFilename: SessionInfo
 * classVarName: SessionInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class SessionInfo.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIBaseItemDto.h"
#include "jellyfin/model/OAIClientCapabilities.h"
#include "jellyfin/model/OAIGeneralCommandType.h"
#include "jellyfin/model/OAIMediaType.h"
#include "jellyfin/model/OAIPlayerStateInfo.h"
#include "jellyfin/model/OAIQueueItem.h"
#include "jellyfin/model/OAISessionUserInfo.h"
#include "jellyfin/model/OAITranscodingInfo.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIPlayerStateInfo;
class OAISessionUserInfo;
class OAIClientCapabilities;
class OAIBaseItemDto;
class OAITranscodingInfo;
class OAIQueueItem;


    class OAISessionInfo {
    public:
    
        std::optional<OAIPlayerStateInfo> PlayState;

        std::optional<std::vector<OAISessionUserInfo>> AdditionalUsers;

        std::optional<OAIClientCapabilities> Capabilities;

        // Gets or sets the remote end point.
        std::optional<std::string> RemoteEndPoint;

        // Gets the playable media types.
        std::optional<std::vector<OAIMediaType>> PlayableMediaTypes;

        // Gets or sets the id.
        std::optional<std::string> Id;

        // Gets or sets the user id.
        std::string UserId;

        // Gets or sets the username.
        std::optional<std::string> UserName;

        // Gets or sets the type of the client.
        std::optional<std::string> Client;

        // Gets or sets the last activity date.
        std::string LastActivityDate;

        // Gets or sets the last playback check in.
        std::string LastPlaybackCheckIn;

        // Gets or sets the last paused date.
        std::optional<std::string> LastPausedDate;

        // Gets or sets the name of the device.
        std::optional<std::string> DeviceName;

        // Gets or sets the type of the device.
        std::optional<std::string> DeviceType;

        // Gets or sets the now playing item.
        std::optional<OAIBaseItemDto> NowPlayingItem;

        // This is strictly used as a data transfer object from the api layer.  This holds information about a BaseItem in a format that is convenient for the client.
        std::optional<OAIBaseItemDto> NowViewingItem;

        // Gets or sets the device id.
        std::optional<std::string> DeviceId;

        // Gets or sets the application version.
        std::optional<std::string> ApplicationVersion;

        std::optional<OAITranscodingInfo> TranscodingInfo;

        // Gets a value indicating whether this instance is active.
        bool IsActive;

        bool SupportsMediaControl;

        bool SupportsRemoteControl;

        std::optional<std::vector<OAIQueueItem>> NowPlayingQueue;

        std::optional<std::vector<OAIBaseItemDto>> NowPlayingQueueFullItems;

        bool HasCustomDeviceName;

        std::optional<std::string> PlaylistItemId;

        std::optional<std::string> ServerId;

        std::optional<std::string> UserPrimaryImageTag;

        // Gets the supported commands.
        std::optional<std::vector<OAIGeneralCommandType>> SupportedCommands;

        OAISessionInfo();
        ~OAISessionInfo();
    };
    extern void to_json(json_t&, const OAISessionInfo&);
    extern void from_json(const json_t&, OAISessionInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISessionInfo);
