#pragma once

/*
 * OAIReadyRequestDto.h
 * name: ReadyRequestDto
 * schemaName: ReadyRequestDto
 * classFilename: ReadyRequestDto
 * classVarName: ReadyRequestDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class ReadyRequest.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIReadyRequestDto {
    public:
    
        // Gets or sets when the request has been made by the client.
        std::string When;

        // Gets or sets the position ticks.
        std::int64_t PositionTicks;

        // Gets or sets a value indicating whether the client playback is unpaused.
        bool IsPlaying;

        // Gets or sets the playlist item identifier of the playing item.
        std::string PlaylistItemId;

        OAIReadyRequestDto();
        ~OAIReadyRequestDto();
    };
    extern void to_json(json_t&, const OAIReadyRequestDto&);
    extern void from_json(const json_t&, OAIReadyRequestDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIReadyRequestDto);
