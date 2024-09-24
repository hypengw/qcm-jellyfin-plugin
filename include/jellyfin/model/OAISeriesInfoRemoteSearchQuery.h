#pragma once

/*
 * OAISeriesInfoRemoteSearchQuery.h
 * name: SeriesInfoRemoteSearchQuery
 * schemaName: SeriesInfoRemoteSearchQuery
 * classFilename: SeriesInfoRemoteSearchQuery
 * classVarName: SeriesInfoRemoteSearchQuery
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISeriesInfo.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {
class OAISeriesInfo;


    class OAISeriesInfoRemoteSearchQuery {
    public:
    
        std::optional<OAISeriesInfo> SearchInfo;

        std::string ItemId;

        // Gets or sets the provider name to search within if set.
        std::optional<std::string> SearchProviderName;

        // Gets or sets a value indicating whether disabled providers should be included.
        bool IncludeDisabledProviders;

        OAISeriesInfoRemoteSearchQuery();
        ~OAISeriesInfoRemoteSearchQuery();
    };
    extern void to_json(json_t&, const OAISeriesInfoRemoteSearchQuery&);
    extern void from_json(const json_t&, OAISeriesInfoRemoteSearchQuery&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISeriesInfoRemoteSearchQuery);
