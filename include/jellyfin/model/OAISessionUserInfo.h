#pragma once

/*
 * OAISessionUserInfo.h
 * name: SessionUserInfo
 * schemaName: SessionUserInfo
 * classFilename: SessionUserInfo
 * classVarName: SessionUserInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class SessionUserInfo.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAISessionUserInfo {
    public:
    
        // Gets or sets the user identifier.
        std::string UserId;

        // Gets or sets the name of the user.
        std::optional<std::string> UserName;

        OAISessionUserInfo();
        ~OAISessionUserInfo();
    };
    extern void to_json(json_t&, const OAISessionUserInfo&);
    extern void from_json(const json_t&, OAISessionUserInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISessionUserInfo);
