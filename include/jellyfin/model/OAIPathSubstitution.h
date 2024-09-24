#pragma once

/*
 * OAIPathSubstitution.h
 * name: PathSubstitution
 * schemaName: PathSubstitution
 * classFilename: PathSubstitution
 * classVarName: PathSubstitution
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Defines the MediaBrowser.Model.Configuration.PathSubstitution.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAIPathSubstitution {
    public:
    
        // Gets or sets the value to substitute.
        std::string From;

        // Gets or sets the value to substitution with.
        std::string To;

        OAIPathSubstitution();
        ~OAIPathSubstitution();
    };
    extern void to_json(json_t&, const OAIPathSubstitution&);
    extern void from_json(const json_t&, OAIPathSubstitution&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPathSubstitution);
