#pragma once

/*
 * OAIGroupStateUpdateGroupUpdate.h
 * name: GroupStateUpdateGroupUpdate
 * schemaName: GroupStateUpdateGroupUpdate
 * classFilename: GroupStateUpdateGroupUpdate
 * classVarName: GroupStateUpdateGroupUpdate
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class GroupUpdate.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIGroupStateUpdate.h"
#include "jellyfin/model/OAIGroupUpdateType.h"
#include <string>



namespace jellyfin::model {
class OAIGroupStateUpdate;


    class OAIGroupStateUpdateGroupUpdate {
    public:
    
        // Gets the group identifier.
        std::string GroupId;

        // Gets the update type.
        OAIGroupUpdateType Type;

        // Gets the update data.
        OAIGroupStateUpdate Data;

        OAIGroupStateUpdateGroupUpdate();
        ~OAIGroupStateUpdateGroupUpdate();
    };
    extern void to_json(json_t&, const OAIGroupStateUpdateGroupUpdate&);
    extern void from_json(const json_t&, OAIGroupStateUpdateGroupUpdate&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIGroupStateUpdateGroupUpdate);
