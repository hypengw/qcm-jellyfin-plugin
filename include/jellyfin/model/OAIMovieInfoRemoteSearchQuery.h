#pragma once

/*
 * OAIMovieInfoRemoteSearchQuery.h
 * name: MovieInfoRemoteSearchQuery
 * schemaName: MovieInfoRemoteSearchQuery
 * classFilename: MovieInfoRemoteSearchQuery
 * classVarName: MovieInfoRemoteSearchQuery
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIMovieInfo.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {
class OAIMovieInfo;


    class OAIMovieInfoRemoteSearchQuery {
    public:
    
        std::optional<OAIMovieInfo> SearchInfo;

        std::string ItemId;

        // Gets or sets the provider name to search within if set.
        std::optional<std::string> SearchProviderName;

        // Gets or sets a value indicating whether disabled providers should be included.
        bool IncludeDisabledProviders;

        OAIMovieInfoRemoteSearchQuery();
        ~OAIMovieInfoRemoteSearchQuery();
    };
    extern void to_json(json_t&, const OAIMovieInfoRemoteSearchQuery&);
    extern void from_json(const json_t&, OAIMovieInfoRemoteSearchQuery&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMovieInfoRemoteSearchQuery);
