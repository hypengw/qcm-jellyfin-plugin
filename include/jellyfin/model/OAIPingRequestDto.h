#pragma once

/*
 * OAIPingRequestDto.h
 * name: PingRequestDto
 * schemaName: PingRequestDto
 * classFilename: PingRequestDto
 * classVarName: PingRequestDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class PingRequestDto.
 */


#include "jellyfin/type.h"


#include <cstdint>



namespace jellyfin::model {


    class OAIPingRequestDto {
    public:
    
        // Gets or sets the ping time.
        std::int64_t Ping;

        OAIPingRequestDto();
        ~OAIPingRequestDto();
    };
    extern void to_json(json_t&, const OAIPingRequestDto&);
    extern void from_json(const json_t&, OAIPingRequestDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPingRequestDto);
