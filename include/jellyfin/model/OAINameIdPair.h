#pragma once

/*
 * OAINameIdPair.h
 * name: NameIdPair
 * schemaName: NameIdPair
 * classFilename: NameIdPair
 * classVarName: NameIdPair
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


    class OAINameIdPair {
    public:
    
        // Gets or sets the name.
        std::optional<std::string> Name;

        // Gets or sets the identifier.
        std::optional<std::string> Id;

        OAINameIdPair();
        ~OAINameIdPair();
    };
    extern void to_json(json_t&, const OAINameIdPair&);
    extern void from_json(const json_t&, OAINameIdPair&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAINameIdPair);
