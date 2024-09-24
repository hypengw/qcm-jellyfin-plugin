#pragma once

/*
 * OAISeriesTimerInfoDtoQueryResult.h
 * name: SeriesTimerInfoDtoQueryResult
 * schemaName: SeriesTimerInfoDtoQueryResult
 * classFilename: SeriesTimerInfoDtoQueryResult
 * classVarName: SeriesTimerInfoDtoQueryResult
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISeriesTimerInfoDto.h"
#include <cstdint>
#include <vector>



namespace jellyfin::model {
class OAISeriesTimerInfoDto;


    class OAISeriesTimerInfoDtoQueryResult {
    public:
    
        // Gets or sets the items.
        std::optional<std::vector<OAISeriesTimerInfoDto>> Items;

        // Gets or sets the total number of records available.
        std::int32_t TotalRecordCount;

        // Gets or sets the index of the first record in Items.
        std::int32_t StartIndex;

        OAISeriesTimerInfoDtoQueryResult();
        ~OAISeriesTimerInfoDtoQueryResult();
    };
    extern void to_json(json_t&, const OAISeriesTimerInfoDtoQueryResult&);
    extern void from_json(const json_t&, OAISeriesTimerInfoDtoQueryResult&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISeriesTimerInfoDtoQueryResult);
