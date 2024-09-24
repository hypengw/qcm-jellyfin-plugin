#pragma once

/*
 * OAIVersionInfo.h
 * name: VersionInfo
 * schemaName: VersionInfo
 * classFilename: VersionInfo
 * classVarName: VersionInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Defines the MediaBrowser.Model.Updates.VersionInfo class.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAIVersionInfo {
    public:
    
        // Gets or sets the version.
        std::string version;

        // Gets the version as a System.Version.
        std::string VersionNumber;

        // Gets or sets the changelog for this version.
        std::optional<std::string> changelog;

        // Gets or sets the ABI that this version was built against.
        std::optional<std::string> targetAbi;

        // Gets or sets the source URL.
        std::optional<std::string> sourceUrl;

        // Gets or sets a checksum for the binary.
        std::optional<std::string> checksum;

        // Gets or sets a timestamp of when the binary was built.
        std::optional<std::string> timestamp;

        // Gets or sets the repository name.
        std::string repositoryName;

        // Gets or sets the repository url.
        std::string repositoryUrl;

        OAIVersionInfo();
        ~OAIVersionInfo();
    };
    extern void to_json(json_t&, const OAIVersionInfo&);
    extern void from_json(const json_t&, OAIVersionInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIVersionInfo);
