#pragma once

/*
 * OAIExternalUrl.h
 * name: ExternalUrl
 * schemaName: ExternalUrl
 * classFilename: ExternalUrl
 * classVarName: ExternalUrl
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


    class OAIExternalUrl {
    public:
    
        // Gets or sets the name.
        std::optional<std::string> Name;

        // Gets or sets the type of the item.
        std::optional<std::string> Url;

        OAIExternalUrl();
        ~OAIExternalUrl();
    };
    extern void to_json(json_t&, const OAIExternalUrl&);
    extern void from_json(const json_t&, OAIExternalUrl&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIExternalUrl);
