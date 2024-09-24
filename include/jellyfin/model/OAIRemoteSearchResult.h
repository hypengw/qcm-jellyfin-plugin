#pragma once

/*
 * OAIRemoteSearchResult.h
 * name: RemoteSearchResult
 * schemaName: RemoteSearchResult
 * classFilename: RemoteSearchResult
 * classVarName: RemoteSearchResult
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


    class OAIRemoteSearchResult {
    public:
    
        // Gets or sets the name.
        std::optional<std::string> Name;

        // Gets or sets the provider ids.
        std::optional<std::map<std::string, std::string>> ProviderIds;

        // Gets or sets the year.
        std::optional<std::int32_t> ProductionYear;

        std::optional<std::int32_t> IndexNumber;

        std::optional<std::int32_t> IndexNumberEnd;

        std::optional<std::int32_t> ParentIndexNumber;

        std::optional<std::string> PremiereDate;

        std::optional<std::string> ImageUrl;

        std::optional<std::string> SearchProviderName;

        std::optional<std::string> Overview;

        std::optional<rc<OAIRemoteSearchResult>> AlbumArtist;

        std::optional<std::vector<OAIRemoteSearchResult>> Artists;

        OAIRemoteSearchResult();
        ~OAIRemoteSearchResult();
    };
    extern void to_json(json_t&, const OAIRemoteSearchResult&);
    extern void from_json(const json_t&, OAIRemoteSearchResult&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIRemoteSearchResult);
