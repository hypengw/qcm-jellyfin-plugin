#pragma once

/*
 * OAIThemeMediaResult.h
 * name: ThemeMediaResult
 * schemaName: ThemeMediaResult
 * classFilename: ThemeMediaResult
 * classVarName: ThemeMediaResult
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class ThemeMediaResult.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIBaseItemDto.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIBaseItemDto;


    class OAIThemeMediaResult {
    public:
    
        // Gets or sets the items.
        std::optional<std::vector<OAIBaseItemDto>> Items;

        // Gets or sets the total number of records available.
        std::int32_t TotalRecordCount;

        // Gets or sets the index of the first record in Items.
        std::int32_t StartIndex;

        // Gets or sets the owner id.
        std::string OwnerId;

        OAIThemeMediaResult();
        ~OAIThemeMediaResult();
    };
    extern void to_json(json_t&, const OAIThemeMediaResult&);
    extern void from_json(const json_t&, OAIThemeMediaResult&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIThemeMediaResult);
