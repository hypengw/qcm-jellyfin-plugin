#pragma once

/*
 * OAIMediaPathInfo.h
 * name: MediaPathInfo
 * schemaName: MediaPathInfo
 * classFilename: MediaPathInfo
 * classVarName: MediaPathInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAIMediaPathInfo {
    public:
    
        std::string Path;

        std::optional<std::string> NetworkPath;

        OAIMediaPathInfo();
        ~OAIMediaPathInfo();
    };
    extern void to_json(json_t&, const OAIMediaPathInfo&);
    extern void from_json(const json_t&, OAIMediaPathInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMediaPathInfo);
