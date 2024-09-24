#pragma once

/*
 * OAIPlayRequest.h
 * name: PlayRequest
 * schemaName: PlayRequest
 * classFilename: PlayRequest
 * classVarName: PlayRequest
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class PlayRequest.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIPlayCommand.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {


    class OAIPlayRequest {
    public:
    
        // Gets or sets the item ids.
        std::optional<std::vector<std::string>> ItemIds;

        // Gets or sets the start position ticks that the first item should be played at.
        std::optional<std::int64_t> StartPositionTicks;

        // Gets or sets the play command.
        OAIPlayCommand PlayCommand;

        // Gets or sets the controlling user identifier.
        std::string ControllingUserId;

        std::optional<std::int32_t> SubtitleStreamIndex;

        std::optional<std::int32_t> AudioStreamIndex;

        std::optional<std::string> MediaSourceId;

        std::optional<std::int32_t> StartIndex;

        OAIPlayRequest();
        ~OAIPlayRequest();
    };
    extern void to_json(json_t&, const OAIPlayRequest&);
    extern void from_json(const json_t&, OAIPlayRequest&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlayRequest);
