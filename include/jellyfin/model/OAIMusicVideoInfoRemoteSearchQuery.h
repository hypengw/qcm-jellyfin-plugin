#pragma once

/*
 * OAIMusicVideoInfoRemoteSearchQuery.h
 * name: MusicVideoInfoRemoteSearchQuery
 * schemaName: MusicVideoInfoRemoteSearchQuery
 * classFilename: MusicVideoInfoRemoteSearchQuery
 * classVarName: MusicVideoInfoRemoteSearchQuery
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIMusicVideoInfo.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {
class OAIMusicVideoInfo;


    class OAIMusicVideoInfoRemoteSearchQuery {
    public:
    
        std::optional<OAIMusicVideoInfo> SearchInfo;

        std::string ItemId;

        // Gets or sets the provider name to search within if set.
        std::optional<std::string> SearchProviderName;

        // Gets or sets a value indicating whether disabled providers should be included.
        bool IncludeDisabledProviders;

        OAIMusicVideoInfoRemoteSearchQuery();
        ~OAIMusicVideoInfoRemoteSearchQuery();
    };
    extern void to_json(json_t&, const OAIMusicVideoInfoRemoteSearchQuery&);
    extern void from_json(const json_t&, OAIMusicVideoInfoRemoteSearchQuery&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMusicVideoInfoRemoteSearchQuery);
