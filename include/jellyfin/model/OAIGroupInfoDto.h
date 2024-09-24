#pragma once

/*
 * OAIGroupInfoDto.h
 * name: GroupInfoDto
 * schemaName: GroupInfoDto
 * classFilename: GroupInfoDto
 * classVarName: GroupInfoDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class GroupInfoDto.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIGroupStateType.h"
#include <string>
#include <vector>



namespace jellyfin::model {


    class OAIGroupInfoDto {
    public:
    
        // Gets the group identifier.
        std::string GroupId;

        // Gets the group name.
        std::string GroupName;

        // Gets the group state.
        OAIGroupStateType State;

        // Gets the participants.
        std::vector<std::string> Participants;

        // Gets the date when this DTO has been created.
        std::string LastUpdatedAt;

        OAIGroupInfoDto();
        ~OAIGroupInfoDto();
    };
    extern void to_json(json_t&, const OAIGroupInfoDto&);
    extern void from_json(const json_t&, OAIGroupInfoDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIGroupInfoDto);
