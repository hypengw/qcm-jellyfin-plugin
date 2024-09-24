#pragma once

/*
 * OAIServerConfiguration.h
 * name: ServerConfiguration
 * schemaName: ServerConfiguration
 * classFilename: ServerConfiguration
 * classVarName: ServerConfiguration
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Represents the server configuration.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAICastReceiverApplication.h"
#include "jellyfin/model/OAIImageResolution.h"
#include "jellyfin/model/OAIImageSavingConvention.h"
#include "jellyfin/model/OAIMetadataOptions.h"
#include "jellyfin/model/OAINameValuePair.h"
#include "jellyfin/model/OAIPathSubstitution.h"
#include "jellyfin/model/OAIRepositoryInfo.h"
#include "jellyfin/model/OAITrickplayOptions.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIMetadataOptions;
class OAINameValuePair;
class OAIRepositoryInfo;
class OAIPathSubstitution;
class OAICastReceiverApplication;
class OAITrickplayOptions;


    class OAIServerConfiguration {
    public:
    
        // Gets or sets the number of days we should retain log files.
        std::int32_t LogFileRetentionDays;

        // Gets or sets a value indicating whether this instance is first run.
        bool IsStartupWizardCompleted;

        // Gets or sets the cache path.
        std::optional<std::string> CachePath;

        // Gets or sets the last known version that was ran using the configuration.
        std::optional<std::string> PreviousVersion;

        // Gets or sets the stringified PreviousVersion to be stored/loaded,  because System.Version itself isn&#39;t xml-serializable.
        std::optional<std::string> PreviousVersionStr;

        // Gets or sets a value indicating whether to enable prometheus metrics exporting.
        bool EnableMetrics;

        bool EnableNormalizedItemByNameIds;

        // Gets or sets a value indicating whether this instance is port authorized.
        bool IsPortAuthorized;

        // Gets or sets a value indicating whether quick connect is available for use on this server.
        bool QuickConnectAvailable;

        // Gets or sets a value indicating whether [enable case sensitive item ids].
        bool EnableCaseSensitiveItemIds;

        bool DisableLiveTvChannelUserDataName;

        // Gets or sets the metadata path.
        std::string MetadataPath;

        std::string MetadataNetworkPath;

        // Gets or sets the preferred metadata language.
        std::string PreferredMetadataLanguage;

        // Gets or sets the metadata country code.
        std::string MetadataCountryCode;

        // Gets or sets characters to be replaced with a &#39; &#39; in strings to create a sort name.
        std::vector<std::string> SortReplaceCharacters;

        // Gets or sets characters to be removed from strings to create a sort name.
        std::vector<std::string> SortRemoveCharacters;

        // Gets or sets words to be removed from strings to create a sort name.
        std::vector<std::string> SortRemoveWords;

        // Gets or sets the minimum percentage of an item that must be played in order for playstate to be updated.
        std::int32_t MinResumePct;

        // Gets or sets the maximum percentage of an item that can be played while still saving playstate. If this percentage is crossed playstate will be reset to the beginning and the item will be marked watched.
        std::int32_t MaxResumePct;

        // Gets or sets the minimum duration that an item must have in order to be eligible for playstate updates..
        std::int32_t MinResumeDurationSeconds;

        // Gets or sets the minimum minutes of a book that must be played in order for playstate to be updated.
        std::int32_t MinAudiobookResume;

        // Gets or sets the remaining minutes of a book that can be played while still saving playstate. If this percentage is crossed playstate will be reset to the beginning and the item will be marked watched.
        std::int32_t MaxAudiobookResume;

        // Gets or sets the threshold in minutes after a inactive session gets closed automatically.  If set to 0 the check for inactive sessions gets disabled.
        std::int32_t InactiveSessionThreshold;

        // Gets or sets the delay in seconds that we will wait after a file system change to try and discover what has been added/removed  Some delay is necessary with some items because their creation is not atomic.  It involves the creation of several  different directories and files.
        std::int32_t LibraryMonitorDelay;

        // Gets or sets the duration in seconds that we will wait after a library updated event before executing the library changed notification.
        std::int32_t LibraryUpdateDuration;

        // Gets or sets the image saving convention.
        OAIImageSavingConvention ImageSavingConvention;

        std::vector<OAIMetadataOptions> MetadataOptions;

        bool SkipDeserializationForBasicTypes;

        std::string ServerName;

        std::string UICulture;

        bool SaveMetadataHidden;

        std::vector<OAINameValuePair> ContentTypes;

        std::int32_t RemoteClientBitrateLimit;

        bool EnableFolderView;

        bool EnableGroupingIntoCollections;

        bool DisplaySpecialsWithinSeasons;

        std::vector<std::string> CodecsUsed;

        std::vector<OAIRepositoryInfo> PluginRepositories;

        bool EnableExternalContentInSuggestions;

        std::int32_t ImageExtractionTimeoutMs;

        std::vector<OAIPathSubstitution> PathSubstitutions;

        // Gets or sets a value indicating whether slow server responses should be logged as a warning.
        bool EnableSlowResponseWarning;

        // Gets or sets the threshold for the slow response time warning in ms.
        std::int64_t SlowResponseThresholdMs;

        // Gets or sets the cors hosts.
        std::vector<std::string> CorsHosts;

        // Gets or sets the number of days we should retain activity logs.
        std::optional<std::int32_t> ActivityLogRetentionDays;

        // Gets or sets the how the library scan fans out.
        std::int32_t LibraryScanFanoutConcurrency;

        // Gets or sets the how many metadata refreshes can run concurrently.
        std::int32_t LibraryMetadataRefreshConcurrency;

        // Gets or sets a value indicating whether older plugins should automatically be deleted from the plugin folder.
        bool RemoveOldPlugins;

        // Gets or sets a value indicating whether clients should be allowed to upload logs.
        bool AllowClientLogUpload;

        // Gets or sets the dummy chapter duration in seconds, use 0 (zero) or less to disable generation alltogether.
        std::int32_t DummyChapterDuration;

        // Gets or sets the chapter image resolution.
        OAIImageResolution ChapterImageResolution;

        // Gets or sets the limit for parallel image encoding.
        std::int32_t ParallelImageEncodingLimit;

        // Gets or sets the list of cast receiver applications.
        std::vector<OAICastReceiverApplication> CastReceiverApplications;

        // Gets or sets the trickplay options.
        OAITrickplayOptions TrickplayOptions;

        OAIServerConfiguration();
        ~OAIServerConfiguration();
    };
    extern void to_json(json_t&, const OAIServerConfiguration&);
    extern void from_json(const json_t&, OAIServerConfiguration&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIServerConfiguration);
