#pragma once

/*
 * OAINameGuidPair.h
 * name: NameGuidPair
 * schemaName: NameGuidPair
 * classFilename: NameGuidPair
 * classVarName: NameGuidPair
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


    class OAINameGuidPair {
    public:
    
        std::optional<std::string> Name;

        std::string Id;

        OAINameGuidPair();
        ~OAINameGuidPair();
    };
    extern void to_json(json_t&, const OAINameGuidPair&);
    extern void from_json(const json_t&, OAINameGuidPair&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAINameGuidPair);
