#pragma once

/*
 * OAISystemInfo.h
 * name: SystemInfo
 * schemaName: SystemInfo
 * classFilename: SystemInfo
 * classVarName: SystemInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class SystemInfo.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAICastReceiverApplication.h"
#include "jellyfin/model/OAIInstallationInfo.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIInstallationInfo;
class OAICastReceiverApplication;


    class OAISystemInfo {
    public:
    
        // Gets or sets the local address.
        std::optional<std::string> LocalAddress;

        // Gets or sets the name of the server.
        std::optional<std::string> ServerName;

        // Gets or sets the server version.
        std::optional<std::string> Version;

        // Gets or sets the product name. This is the AssemblyProduct name.
        std::optional<std::string> ProductName;

        // Gets or sets the operating system.
        [[deprecated]] std::optional<std::string> OperatingSystem;

        // Gets or sets the id.
        std::optional<std::string> Id;

        // Gets or sets a value indicating whether the startup wizard is completed.
        std::optional<bool> StartupWizardCompleted;

        // Gets or sets the display name of the operating system.
        [[deprecated]] std::optional<std::string> OperatingSystemDisplayName;

        // Gets or sets the package name.
        std::optional<std::string> PackageName;

        // Gets or sets a value indicating whether this instance has pending restart.
        bool HasPendingRestart;

        bool IsShuttingDown;

        // Gets or sets a value indicating whether [supports library monitor].
        bool SupportsLibraryMonitor;

        // Gets or sets the web socket port number.
        std::int32_t WebSocketPortNumber;

        // Gets or sets the completed installations.
        std::optional<std::vector<OAIInstallationInfo>> CompletedInstallations;

        // Gets or sets a value indicating whether this instance can self restart.
        [[deprecated]] bool CanSelfRestart;

        [[deprecated]] bool CanLaunchWebBrowser;

        // Gets or sets the program data path.
        std::optional<std::string> ProgramDataPath;

        // Gets or sets the web UI resources path.
        std::optional<std::string> WebPath;

        // Gets or sets the items by name path.
        std::optional<std::string> ItemsByNamePath;

        // Gets or sets the cache path.
        std::optional<std::string> CachePath;

        // Gets or sets the log path.
        std::optional<std::string> LogPath;

        // Gets or sets the internal metadata path.
        std::optional<std::string> InternalMetadataPath;

        // Gets or sets the transcode path.
        std::optional<std::string> TranscodingTempPath;

        // Gets or sets the list of cast receiver applications.
        std::optional<std::vector<OAICastReceiverApplication>> CastReceiverApplications;

        // Gets or sets a value indicating whether this instance has update available.
        [[deprecated]] bool HasUpdateAvailable;

        [[deprecated]] std::optional<std::string> EncoderLocation;

        [[deprecated]] std::optional<std::string> SystemArchitecture;

        OAISystemInfo();
        ~OAISystemInfo();
    };
    extern void to_json(json_t&, const OAISystemInfo&);
    extern void from_json(const json_t&, OAISystemInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISystemInfo);
