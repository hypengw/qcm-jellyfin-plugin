#pragma once

/*
 * OAIGroupInfoDtoGroupUpdate.h
 * name: GroupInfoDtoGroupUpdate
 * schemaName: GroupInfoDtoGroupUpdate
 * classFilename: GroupInfoDtoGroupUpdate
 * classVarName: GroupInfoDtoGroupUpdate
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class GroupUpdate.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIGroupInfoDto.h"
#include "jellyfin/model/OAIGroupUpdateType.h"
#include <string>



namespace jellyfin::model {
class OAIGroupInfoDto;


    class OAIGroupInfoDtoGroupUpdate {
    public:
    
        // Gets the group identifier.
        std::string GroupId;

        // Gets the update type.
        OAIGroupUpdateType Type;

        // Gets the update data.
        OAIGroupInfoDto Data;

        OAIGroupInfoDtoGroupUpdate();
        ~OAIGroupInfoDtoGroupUpdate();
    };
    extern void to_json(json_t&, const OAIGroupInfoDtoGroupUpdate&);
    extern void from_json(const json_t&, OAIGroupInfoDtoGroupUpdate&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIGroupInfoDtoGroupUpdate);
