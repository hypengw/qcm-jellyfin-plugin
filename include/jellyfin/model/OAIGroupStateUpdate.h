#pragma once

/*
 * OAIGroupStateUpdate.h
 * name: GroupStateUpdate
 * schemaName: GroupStateUpdate
 * classFilename: GroupStateUpdate
 * classVarName: GroupStateUpdate
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class GroupStateUpdate.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIGroupStateType.h"
#include "jellyfin/model/OAIPlaybackRequestType.h"



namespace jellyfin::model {


    class OAIGroupStateUpdate {
    public:
    
        // Gets the state of the group.
        OAIGroupStateType State;

        // Gets the reason of the state change.
        OAIPlaybackRequestType Reason;

        OAIGroupStateUpdate();
        ~OAIGroupStateUpdate();
    };
    extern void to_json(json_t&, const OAIGroupStateUpdate&);
    extern void from_json(const json_t&, OAIGroupStateUpdate&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIGroupStateUpdate);
