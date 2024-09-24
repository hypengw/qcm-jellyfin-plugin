#pragma once

/*
 * OAIMessageCommand.h
 * name: MessageCommand
 * schemaName: MessageCommand
 * classFilename: MessageCommand
 * classVarName: MessageCommand
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIMessageCommand {
    public:
    
        std::optional<std::string> Header;

        std::string Text;

        std::optional<std::int64_t> TimeoutMs;

        OAIMessageCommand();
        ~OAIMessageCommand();
    };
    extern void to_json(json_t&, const OAIMessageCommand&);
    extern void from_json(const json_t&, OAIMessageCommand&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMessageCommand);
