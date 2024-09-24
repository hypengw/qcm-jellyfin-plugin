#pragma once

/*
 * OAILiveTvServiceInfo.h
 * name: LiveTvServiceInfo
 * schemaName: LiveTvServiceInfo
 * classFilename: LiveTvServiceInfo
 * classVarName: LiveTvServiceInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class ServiceInfo.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAILiveTvServiceStatus.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {


    class OAILiveTvServiceInfo {
    public:
    
        // Gets or sets the name.
        std::optional<std::string> Name;

        // Gets or sets the home page URL.
        std::optional<std::string> HomePageUrl;

        // Gets or sets the status.
        OAILiveTvServiceStatus Status;

        // Gets or sets the status message.
        std::optional<std::string> StatusMessage;

        // Gets or sets the version.
        std::optional<std::string> Version;

        // Gets or sets a value indicating whether this instance has update available.
        bool HasUpdateAvailable;

        // Gets or sets a value indicating whether this instance is visible.
        bool IsVisible;

        std::optional<std::vector<std::string>> Tuners;

        OAILiveTvServiceInfo();
        ~OAILiveTvServiceInfo();
    };
    extern void to_json(json_t&, const OAILiveTvServiceInfo&);
    extern void from_json(const json_t&, OAILiveTvServiceInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAILiveTvServiceInfo);
