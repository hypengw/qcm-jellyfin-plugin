#pragma once

/*
 * OAIUserPolicy.h
 * name: UserPolicy
 * schemaName: UserPolicy
 * classFilename: UserPolicy
 * classVarName: UserPolicy
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIAccessSchedule.h"
#include "jellyfin/model/OAISyncPlayUserAccessType.h"
#include "jellyfin/model/OAIUnratedItem.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIAccessSchedule;


    class OAIUserPolicy {
    public:
    
        // Gets or sets a value indicating whether this instance is administrator.
        bool IsAdministrator;

        // Gets or sets a value indicating whether this instance is hidden.
        bool IsHidden;

        // Gets or sets a value indicating whether this instance can manage collections.
        bool EnableCollectionManagement;

        // Gets or sets a value indicating whether this instance can manage subtitles.
        bool EnableSubtitleManagement;

        // Gets or sets a value indicating whether this user can manage lyrics.
        bool EnableLyricManagement;

        // Gets or sets a value indicating whether this instance is disabled.
        bool IsDisabled;

        // Gets or sets the max parental rating.
        std::optional<std::int32_t> MaxParentalRating;

        std::optional<std::vector<std::string>> BlockedTags;

        std::optional<std::vector<std::string>> AllowedTags;

        bool EnableUserPreferenceAccess;

        std::optional<std::vector<OAIAccessSchedule>> AccessSchedules;

        std::optional<std::vector<OAIUnratedItem>> BlockUnratedItems;

        bool EnableRemoteControlOfOtherUsers;

        bool EnableSharedDeviceControl;

        bool EnableRemoteAccess;

        bool EnableLiveTvManagement;

        bool EnableLiveTvAccess;

        bool EnableMediaPlayback;

        bool EnableAudioPlaybackTranscoding;

        bool EnableVideoPlaybackTranscoding;

        bool EnablePlaybackRemuxing;

        bool ForceRemoteSourceTranscoding;

        bool EnableContentDeletion;

        std::optional<std::vector<std::string>> EnableContentDeletionFromFolders;

        bool EnableContentDownloading;

        // Gets or sets a value indicating whether [enable synchronize].
        bool EnableSyncTranscoding;

        bool EnableMediaConversion;

        std::optional<std::vector<std::string>> EnabledDevices;

        bool EnableAllDevices;

        std::optional<std::vector<std::string>> EnabledChannels;

        bool EnableAllChannels;

        std::optional<std::vector<std::string>> EnabledFolders;

        bool EnableAllFolders;

        std::int32_t InvalidLoginAttemptCount;

        std::int32_t LoginAttemptsBeforeLockout;

        std::int32_t MaxActiveSessions;

        bool EnablePublicSharing;

        std::optional<std::vector<std::string>> BlockedMediaFolders;

        std::optional<std::vector<std::string>> BlockedChannels;

        std::int32_t RemoteClientBitrateLimit;

        std::string AuthenticationProviderId;

        std::string PasswordResetProviderId;

        // Gets or sets a value indicating what SyncPlay features the user can access.
        OAISyncPlayUserAccessType SyncPlayAccess;

        OAIUserPolicy();
        ~OAIUserPolicy();
    };
    extern void to_json(json_t&, const OAIUserPolicy&);
    extern void from_json(const json_t&, OAIUserPolicy&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIUserPolicy);
