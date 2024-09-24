#pragma once

/*
 * OAIGeneralCommand.h
 * name: GeneralCommand
 * schemaName: GeneralCommand
 * classFilename: GeneralCommand
 * classVarName: GeneralCommand
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIGeneralCommandType.h"
#include <map>
#include <string>



namespace jellyfin::model {


    class OAIGeneralCommand {
    public:
    
        // This exists simply to identify a set of known commands.
        OAIGeneralCommandType Name;

        std::string ControllingUserId;

        std::map<std::string, std::string> Arguments;

        OAIGeneralCommand();
        ~OAIGeneralCommand();
    };
    extern void to_json(json_t&, const OAIGeneralCommand&);
    extern void from_json(const json_t&, OAIGeneralCommand&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIGeneralCommand);
