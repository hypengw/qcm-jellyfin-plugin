#pragma once

/*
 * OAITimerInfoDtoQueryResult.h
 * name: TimerInfoDtoQueryResult
 * schemaName: TimerInfoDtoQueryResult
 * classFilename: TimerInfoDtoQueryResult
 * classVarName: TimerInfoDtoQueryResult
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAITimerInfoDto.h"
#include <cstdint>
#include <vector>



namespace jellyfin::model {
class OAITimerInfoDto;


    class OAITimerInfoDtoQueryResult {
    public:
    
        // Gets or sets the items.
        std::optional<std::vector<OAITimerInfoDto>> Items;

        // Gets or sets the total number of records available.
        std::int32_t TotalRecordCount;

        // Gets or sets the index of the first record in Items.
        std::int32_t StartIndex;

        OAITimerInfoDtoQueryResult();
        ~OAITimerInfoDtoQueryResult();
    };
    extern void to_json(json_t&, const OAITimerInfoDtoQueryResult&);
    extern void from_json(const json_t&, OAITimerInfoDtoQueryResult&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITimerInfoDtoQueryResult);
