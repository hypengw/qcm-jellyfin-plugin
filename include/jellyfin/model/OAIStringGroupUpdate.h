#pragma once

/*
 * OAIStringGroupUpdate.h
 * name: StringGroupUpdate
 * schemaName: StringGroupUpdate
 * classFilename: StringGroupUpdate
 * classVarName: StringGroupUpdate
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
#include <string>



namespace jellyfin::model {


    class OAIStringGroupUpdate {
    public:
    
        // Gets the group identifier.
        std::string GroupId;

        // Gets the update type.
        OAIGroupUpdateType Type;

        // Gets the update data.
        std::string Data;

        OAIStringGroupUpdate();
        ~OAIStringGroupUpdate();
    };
    extern void to_json(json_t&, const OAIStringGroupUpdate&);
    extern void from_json(const json_t&, OAIStringGroupUpdate&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIStringGroupUpdate);
