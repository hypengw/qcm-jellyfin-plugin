#pragma once

/*
 * OAIInstallationInfo.h
 * name: InstallationInfo
 * schemaName: InstallationInfo
 * classFilename: InstallationInfo
 * classVarName: InstallationInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class InstallationInfo.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIPackageInfo.h"
#include <string>



namespace jellyfin::model {
class OAIPackageInfo;


    class OAIInstallationInfo {
    public:
    
        // Gets or sets the Id.
        std::string Guid;

        // Gets or sets the name.
        std::optional<std::string> Name;

        // Gets or sets the version.
        std::optional<std::string> Version;

        // Gets or sets the changelog for this version.
        std::optional<std::string> Changelog;

        // Gets or sets the source URL.
        std::optional<std::string> SourceUrl;

        // Gets or sets a checksum for the binary.
        std::optional<std::string> Checksum;

        // Gets or sets package information for the installation.
        std::optional<OAIPackageInfo> PackageInfo;

        OAIInstallationInfo();
        ~OAIInstallationInfo();
    };
    extern void to_json(json_t&, const OAIInstallationInfo&);
    extern void from_json(const json_t&, OAIInstallationInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIInstallationInfo);
