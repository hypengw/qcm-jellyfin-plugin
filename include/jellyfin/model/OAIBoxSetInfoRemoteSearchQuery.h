#pragma once

/*
 * OAIBoxSetInfoRemoteSearchQuery.h
 * name: BoxSetInfoRemoteSearchQuery
 * schemaName: BoxSetInfoRemoteSearchQuery
 * classFilename: BoxSetInfoRemoteSearchQuery
 * classVarName: BoxSetInfoRemoteSearchQuery
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIBoxSetInfo.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {
class OAIBoxSetInfo;


    class OAIBoxSetInfoRemoteSearchQuery {
    public:
    
        std::optional<OAIBoxSetInfo> SearchInfo;

        std::string ItemId;

        // Gets or sets the provider name to search within if set.
        std::optional<std::string> SearchProviderName;

        // Gets or sets a value indicating whether disabled providers should be included.
        bool IncludeDisabledProviders;

        OAIBoxSetInfoRemoteSearchQuery();
        ~OAIBoxSetInfoRemoteSearchQuery();
    };
    extern void to_json(json_t&, const OAIBoxSetInfoRemoteSearchQuery&);
    extern void from_json(const json_t&, OAIBoxSetInfoRemoteSearchQuery&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIBoxSetInfoRemoteSearchQuery);
