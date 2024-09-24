#pragma once

/*
 * OAICastReceiverApplication.h
 * name: CastReceiverApplication
 * schemaName: CastReceiverApplication
 * classFilename: CastReceiverApplication
 * classVarName: CastReceiverApplication
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * The cast receiver application model.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAICastReceiverApplication {
    public:
    
        // Gets or sets the cast receiver application id.
        std::string Id;

        // Gets or sets the cast receiver application name.
        std::string Name;

        OAICastReceiverApplication();
        ~OAICastReceiverApplication();
    };
    extern void to_json(json_t&, const OAICastReceiverApplication&);
    extern void from_json(const json_t&, OAICastReceiverApplication&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAICastReceiverApplication);
