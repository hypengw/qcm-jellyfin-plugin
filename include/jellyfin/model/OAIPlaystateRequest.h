#pragma once

/*
 * OAIPlaystateRequest.h
 * name: PlaystateRequest
 * schemaName: PlaystateRequest
 * classFilename: PlaystateRequest
 * classVarName: PlaystateRequest
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIPlaystateCommand.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIPlaystateRequest {
    public:
    
        // Enum PlaystateCommand.
        OAIPlaystateCommand Command;

        std::optional<std::int64_t> SeekPositionTicks;

        // Gets or sets the controlling user identifier.
        std::optional<std::string> ControllingUserId;

        OAIPlaystateRequest();
        ~OAIPlaystateRequest();
    };
    extern void to_json(json_t&, const OAIPlaystateRequest&);
    extern void from_json(const json_t&, OAIPlaystateRequest&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlaystateRequest);
