#pragma once

/*
 * OAISearchHintResult.h
 * name: SearchHintResult
 * schemaName: SearchHintResult
 * classFilename: SearchHintResult
 * classVarName: SearchHintResult
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class SearchHintResult.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISearchHint.h"
#include <cstdint>
#include <vector>



namespace jellyfin::model {
class OAISearchHint;


    class OAISearchHintResult {
    public:
    
        // Gets the search hints.
        std::vector<OAISearchHint> SearchHints;

        // Gets the total record count.
        std::int32_t TotalRecordCount;

        OAISearchHintResult();
        ~OAISearchHintResult();
    };
    extern void to_json(json_t&, const OAISearchHintResult&);
    extern void from_json(const json_t&, OAISearchHintResult&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISearchHintResult);
