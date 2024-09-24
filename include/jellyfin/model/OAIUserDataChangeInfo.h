#pragma once

/*
 * OAIUserDataChangeInfo.h
 * name: UserDataChangeInfo
 * schemaName: UserDataChangeInfo
 * classFilename: UserDataChangeInfo
 * classVarName: UserDataChangeInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class UserDataChangeInfo.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIUserItemDataDto.h"
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIUserItemDataDto;


    class OAIUserDataChangeInfo {
    public:
    
        // Gets or sets the user id.
        std::optional<std::string> UserId;

        // Gets or sets the user data list.
        std::optional<std::vector<OAIUserItemDataDto>> UserDataList;

        OAIUserDataChangeInfo();
        ~OAIUserDataChangeInfo();
    };
    extern void to_json(json_t&, const OAIUserDataChangeInfo&);
    extern void from_json(const json_t&, OAIUserDataChangeInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIUserDataChangeInfo);
