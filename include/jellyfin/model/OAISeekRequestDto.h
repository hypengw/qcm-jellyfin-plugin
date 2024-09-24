#pragma once

/*
 * OAISeekRequestDto.h
 * name: SeekRequestDto
 * schemaName: SeekRequestDto
 * classFilename: SeekRequestDto
 * classVarName: SeekRequestDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class SeekRequestDto.
 */


#include "jellyfin/type.h"


#include <cstdint>



namespace jellyfin::model {


    class OAISeekRequestDto {
    public:
    
        // Gets or sets the position ticks.
        std::int64_t PositionTicks;

        OAISeekRequestDto();
        ~OAISeekRequestDto();
    };
    extern void to_json(json_t&, const OAISeekRequestDto&);
    extern void from_json(const json_t&, OAISeekRequestDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISeekRequestDto);
