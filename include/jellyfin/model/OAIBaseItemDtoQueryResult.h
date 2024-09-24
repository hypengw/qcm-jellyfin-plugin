#pragma once

/*
 * OAIBaseItemDtoQueryResult.h
 * name: BaseItemDtoQueryResult
 * schemaName: BaseItemDtoQueryResult
 * classFilename: BaseItemDtoQueryResult
 * classVarName: BaseItemDtoQueryResult
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIBaseItemDto.h"
#include <cstdint>
#include <vector>



namespace jellyfin::model {
class OAIBaseItemDto;


    class OAIBaseItemDtoQueryResult {
    public:
    
        // Gets or sets the items.
        std::optional<std::vector<OAIBaseItemDto>> Items;

        // Gets or sets the total number of records available.
        std::int32_t TotalRecordCount;

        // Gets or sets the index of the first record in Items.
        std::int32_t StartIndex;

        OAIBaseItemDtoQueryResult();
        ~OAIBaseItemDtoQueryResult();
    };
    extern void to_json(json_t&, const OAIBaseItemDtoQueryResult&);
    extern void from_json(const json_t&, OAIBaseItemDtoQueryResult&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIBaseItemDtoQueryResult);
