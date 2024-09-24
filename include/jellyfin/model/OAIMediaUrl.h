#pragma once

/*
 * OAIMediaUrl.h
 * name: MediaUrl
 * schemaName: MediaUrl
 * classFilename: MediaUrl
 * classVarName: MediaUrl
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


    class OAIMediaUrl {
    public:
    
        std::optional<std::string> Url;

        std::optional<std::string> Name;

        OAIMediaUrl();
        ~OAIMediaUrl();
    };
    extern void to_json(json_t&, const OAIMediaUrl&);
    extern void from_json(const json_t&, OAIMediaUrl&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMediaUrl);
