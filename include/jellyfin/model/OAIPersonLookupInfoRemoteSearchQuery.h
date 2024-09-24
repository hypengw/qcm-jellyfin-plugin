#pragma once

/*
 * OAIPersonLookupInfoRemoteSearchQuery.h
 * name: PersonLookupInfoRemoteSearchQuery
 * schemaName: PersonLookupInfoRemoteSearchQuery
 * classFilename: PersonLookupInfoRemoteSearchQuery
 * classVarName: PersonLookupInfoRemoteSearchQuery
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIPersonLookupInfo.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {
class OAIPersonLookupInfo;


    class OAIPersonLookupInfoRemoteSearchQuery {
    public:
    
        std::optional<OAIPersonLookupInfo> SearchInfo;

        std::string ItemId;

        // Gets or sets the provider name to search within if set.
        std::optional<std::string> SearchProviderName;

        // Gets or sets a value indicating whether disabled providers should be included.
        bool IncludeDisabledProviders;

        OAIPersonLookupInfoRemoteSearchQuery();
        ~OAIPersonLookupInfoRemoteSearchQuery();
    };
    extern void to_json(json_t&, const OAIPersonLookupInfoRemoteSearchQuery&);
    extern void from_json(const json_t&, OAIPersonLookupInfoRemoteSearchQuery&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPersonLookupInfoRemoteSearchQuery);
