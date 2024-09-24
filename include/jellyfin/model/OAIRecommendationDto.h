#pragma once

/*
 * OAIRecommendationDto.h
 * name: RecommendationDto
 * schemaName: RecommendationDto
 * classFilename: RecommendationDto
 * classVarName: RecommendationDto
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
#include "jellyfin/model/OAIRecommendationType.h"
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIBaseItemDto;


    class OAIRecommendationDto {
    public:
    
        std::optional<std::vector<OAIBaseItemDto>> Items;

        OAIRecommendationType RecommendationType;

        std::optional<std::string> BaselineItemName;

        std::string CategoryId;

        OAIRecommendationDto();
        ~OAIRecommendationDto();
    };
    extern void to_json(json_t&, const OAIRecommendationDto&);
    extern void from_json(const json_t&, OAIRecommendationDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIRecommendationDto);
