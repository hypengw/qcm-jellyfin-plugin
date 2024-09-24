#pragma once

/*
 * OAISongInfo.h
 * name: SongInfo
 * schemaName: SongInfo
 * classFilename: SongInfo
 * classVarName: SongInfo
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


    class OAISongInfo {
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

        std::optional<std::vector<std::string>> AlbumArtists;

        std::optional<std::string> Album;

        std::optional<std::vector<std::string>> Artists;

        OAISongInfo();
        ~OAISongInfo();
    };
    extern void to_json(json_t&, const OAISongInfo&);
    extern void from_json(const json_t&, OAISongInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISongInfo);
