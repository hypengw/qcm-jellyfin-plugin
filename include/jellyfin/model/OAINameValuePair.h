#pragma once

/*
 * OAINameValuePair.h
 * name: NameValuePair
 * schemaName: NameValuePair
 * classFilename: NameValuePair
 * classVarName: NameValuePair
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


    class OAINameValuePair {
    public:
    
        // Gets or sets the name.
        std::optional<std::string> Name;

        // Gets or sets the value.
        std::optional<std::string> Value;

        OAINameValuePair();
        ~OAINameValuePair();
    };
    extern void to_json(json_t&, const OAINameValuePair&);
    extern void from_json(const json_t&, OAINameValuePair&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAINameValuePair);
