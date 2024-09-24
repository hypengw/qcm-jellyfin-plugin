#pragma once

/*
 * OAIMusicVideoInfo.h
 * name: MusicVideoInfo
 * schemaName: MusicVideoInfo
 * classFilename: MusicVideoInfo
 * classVarName: MusicVideoInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <map>
#include <string>
#include <vector>



namespace jellyfin::model {


    class OAIMusicVideoInfo {
    public:
    
        // Gets or sets the name.
        std::optional<std::string> Name;

        // Gets or sets the original title.
        std::optional<std::string> OriginalTitle;

        // Gets or sets the path.
        std::optional<std::string> Path;

        // Gets or sets the metadata language.
        std::optional<std::string> MetadataLanguage;

        // Gets or sets the metadata country code.
        std::optional<std::string> MetadataCountryCode;

        // Gets or sets the provider ids.
        std::optional<std::map<std::string, std::string>> ProviderIds;

        // Gets or sets the year.
        std::optional<std::int32_t> Year;

        std::optional<std::int32_t> IndexNumber;

        std::optional<std::int32_t> ParentIndexNumber;

        std::optional<std::string> PremiereDate;

        bool IsAutomated;

        std::optional<std::vector<std::string>> Artists;

        OAIMusicVideoInfo();
        ~OAIMusicVideoInfo();
    };
    extern void to_json(json_t&, const OAIMusicVideoInfo&);
    extern void from_json(const json_t&, OAIMusicVideoInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMusicVideoInfo);
