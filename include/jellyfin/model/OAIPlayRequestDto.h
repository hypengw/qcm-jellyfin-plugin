#pragma once

/*
 * OAIPlayRequestDto.h
 * name: PlayRequestDto
 * schemaName: PlayRequestDto
 * classFilename: PlayRequestDto
 * classVarName: PlayRequestDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class PlayRequestDto.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {


    class OAIPlayRequestDto {
    public:
    
        // Gets or sets the playing queue.
        std::vector<std::string> PlayingQueue;

        // Gets or sets the position of the playing item in the queue.
        std::int32_t PlayingItemPosition;

        // Gets or sets the start position ticks.
        std::int64_t StartPositionTicks;

        OAIPlayRequestDto();
        ~OAIPlayRequestDto();
    };
    extern void to_json(json_t&, const OAIPlayRequestDto&);
    extern void from_json(const json_t&, OAIPlayRequestDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlayRequestDto);
