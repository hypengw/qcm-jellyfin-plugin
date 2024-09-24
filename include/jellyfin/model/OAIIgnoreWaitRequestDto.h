#pragma once

/*
 * OAIIgnoreWaitRequestDto.h
 * name: IgnoreWaitRequestDto
 * schemaName: IgnoreWaitRequestDto
 * classFilename: IgnoreWaitRequestDto
 * classVarName: IgnoreWaitRequestDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class IgnoreWaitRequestDto.
 */


#include "jellyfin/type.h"


#include <cstdint>



namespace jellyfin::model {


    class OAIIgnoreWaitRequestDto {
    public:
    
        // Gets or sets a value indicating whether the client should be ignored.
        bool IgnoreWait;

        OAIIgnoreWaitRequestDto();
        ~OAIIgnoreWaitRequestDto();
    };
    extern void to_json(json_t&, const OAIIgnoreWaitRequestDto&);
    extern void from_json(const json_t&, OAIIgnoreWaitRequestDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIIgnoreWaitRequestDto);
