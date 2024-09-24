#pragma once

/*
 * OAIArtistInfoRemoteSearchQuery.h
 * name: ArtistInfoRemoteSearchQuery
 * schemaName: ArtistInfoRemoteSearchQuery
 * classFilename: ArtistInfoRemoteSearchQuery
 * classVarName: ArtistInfoRemoteSearchQuery
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIArtistInfo.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {
class OAIArtistInfo;


    class OAIArtistInfoRemoteSearchQuery {
    public:
    
        std::optional<OAIArtistInfo> SearchInfo;

        std::string ItemId;

        // Gets or sets the provider name to search within if set.
        std::optional<std::string> SearchProviderName;

        // Gets or sets a value indicating whether disabled providers should be included.
        bool IncludeDisabledProviders;

        OAIArtistInfoRemoteSearchQuery();
        ~OAIArtistInfoRemoteSearchQuery();
    };
    extern void to_json(json_t&, const OAIArtistInfoRemoteSearchQuery&);
    extern void from_json(const json_t&, OAIArtistInfoRemoteSearchQuery&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIArtistInfoRemoteSearchQuery);
