#pragma once

/*
 * OAITrailerInfoRemoteSearchQuery.h
 * name: TrailerInfoRemoteSearchQuery
 * schemaName: TrailerInfoRemoteSearchQuery
 * classFilename: TrailerInfoRemoteSearchQuery
 * classVarName: TrailerInfoRemoteSearchQuery
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAITrailerInfo.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {
class OAITrailerInfo;


    class OAITrailerInfoRemoteSearchQuery {
    public:
    
        std::optional<OAITrailerInfo> SearchInfo;

        std::string ItemId;

        // Gets or sets the provider name to search within if set.
        std::optional<std::string> SearchProviderName;

        // Gets or sets a value indicating whether disabled providers should be included.
        bool IncludeDisabledProviders;

        OAITrailerInfoRemoteSearchQuery();
        ~OAITrailerInfoRemoteSearchQuery();
    };
    extern void to_json(json_t&, const OAITrailerInfoRemoteSearchQuery&);
    extern void from_json(const json_t&, OAITrailerInfoRemoteSearchQuery&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITrailerInfoRemoteSearchQuery);
