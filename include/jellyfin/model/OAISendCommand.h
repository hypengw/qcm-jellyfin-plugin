#pragma once

/*
 * OAISendCommand.h
 * name: SendCommand
 * schemaName: SendCommand
 * classFilename: SendCommand
 * classVarName: SendCommand
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class SendCommand.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISendCommandType.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAISendCommand {
    public:
    
        // Gets the group identifier.
        std::string GroupId;

        // Gets the playlist identifier of the playing item.
        std::string PlaylistItemId;

        // Gets or sets the UTC time when to execute the command.
        std::string When;

        // Gets the position ticks.
        std::optional<std::int64_t> PositionTicks;

        // Gets the command.
        OAISendCommandType Command;

        // Gets the UTC time when this command has been emitted.
        std::string EmittedAt;

        OAISendCommand();
        ~OAISendCommand();
    };
    extern void to_json(json_t&, const OAISendCommand&);
    extern void from_json(const json_t&, OAISendCommand&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISendCommand);
