#pragma once

/*
 * OAIActivityLogEntryQueryResult.h
 * name: ActivityLogEntryQueryResult
 * schemaName: ActivityLogEntryQueryResult
 * classFilename: ActivityLogEntryQueryResult
 * classVarName: ActivityLogEntryQueryResult
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIActivityLogEntry.h"
#include <cstdint>
#include <vector>



namespace jellyfin::model {
class OAIActivityLogEntry;


    class OAIActivityLogEntryQueryResult {
    public:
    
        // Gets or sets the items.
        std::optional<std::vector<OAIActivityLogEntry>> Items;

        // Gets or sets the total number of records available.
        std::int32_t TotalRecordCount;

        // Gets or sets the index of the first record in Items.
        std::int32_t StartIndex;

        OAIActivityLogEntryQueryResult();
        ~OAIActivityLogEntryQueryResult();
    };
    extern void to_json(json_t&, const OAIActivityLogEntryQueryResult&);
    extern void from_json(const json_t&, OAIActivityLogEntryQueryResult&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIActivityLogEntryQueryResult);
