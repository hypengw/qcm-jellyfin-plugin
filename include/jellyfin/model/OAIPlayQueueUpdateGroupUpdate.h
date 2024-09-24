#pragma once

/*
 * OAIPlayQueueUpdateGroupUpdate.h
 * name: PlayQueueUpdateGroupUpdate
 * schemaName: PlayQueueUpdateGroupUpdate
 * classFilename: PlayQueueUpdateGroupUpdate
 * classVarName: PlayQueueUpdateGroupUpdate
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class GroupUpdate.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIGroupUpdateType.h"
#include "jellyfin/model/OAIPlayQueueUpdate.h"
#include <string>



namespace jellyfin::model {
class OAIPlayQueueUpdate;


    class OAIPlayQueueUpdateGroupUpdate {
    public:
    
        // Gets the group identifier.
        std::string GroupId;

        // Gets the update type.
        OAIGroupUpdateType Type;

        // Gets the update data.
        OAIPlayQueueUpdate Data;

        OAIPlayQueueUpdateGroupUpdate();
        ~OAIPlayQueueUpdateGroupUpdate();
    };
    extern void to_json(json_t&, const OAIPlayQueueUpdateGroupUpdate&);
    extern void from_json(const json_t&, OAIPlayQueueUpdateGroupUpdate&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlayQueueUpdateGroupUpdate);
