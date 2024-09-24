#pragma once

/*
 * OAIAuthenticationInfoQueryResult.h
 * name: AuthenticationInfoQueryResult
 * schemaName: AuthenticationInfoQueryResult
 * classFilename: AuthenticationInfoQueryResult
 * classVarName: AuthenticationInfoQueryResult
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIAuthenticationInfo.h"
#include <cstdint>
#include <vector>



namespace jellyfin::model {
class OAIAuthenticationInfo;


    class OAIAuthenticationInfoQueryResult {
    public:
    
        // Gets or sets the items.
        std::optional<std::vector<OAIAuthenticationInfo>> Items;

        // Gets or sets the total number of records available.
        std::int32_t TotalRecordCount;

        // Gets or sets the index of the first record in Items.
        std::int32_t StartIndex;

        OAIAuthenticationInfoQueryResult();
        ~OAIAuthenticationInfoQueryResult();
    };
    extern void to_json(json_t&, const OAIAuthenticationInfoQueryResult&);
    extern void from_json(const json_t&, OAIAuthenticationInfoQueryResult&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIAuthenticationInfoQueryResult);
