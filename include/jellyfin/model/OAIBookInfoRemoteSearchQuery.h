#pragma once

/*
 * OAIBookInfoRemoteSearchQuery.h
 * name: BookInfoRemoteSearchQuery
 * schemaName: BookInfoRemoteSearchQuery
 * classFilename: BookInfoRemoteSearchQuery
 * classVarName: BookInfoRemoteSearchQuery
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIBookInfo.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {
class OAIBookInfo;


    class OAIBookInfoRemoteSearchQuery {
    public:
    
        std::optional<OAIBookInfo> SearchInfo;

        std::string ItemId;

        // Gets or sets the provider name to search within if set.
        std::optional<std::string> SearchProviderName;

        // Gets or sets a value indicating whether disabled providers should be included.
        bool IncludeDisabledProviders;

        OAIBookInfoRemoteSearchQuery();
        ~OAIBookInfoRemoteSearchQuery();
    };
    extern void to_json(json_t&, const OAIBookInfoRemoteSearchQuery&);
    extern void from_json(const json_t&, OAIBookInfoRemoteSearchQuery&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIBookInfoRemoteSearchQuery);
