#pragma once

/*
 * OAIServerDiscoveryInfo.h
 * name: ServerDiscoveryInfo
 * schemaName: ServerDiscoveryInfo
 * classFilename: ServerDiscoveryInfo
 * classVarName: ServerDiscoveryInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * The server discovery info model.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAIServerDiscoveryInfo {
    public:
    
        // Gets the address.
        std::string Address;

        // Gets the server identifier.
        std::string Id;

        // Gets the name.
        std::string Name;

        // Gets the endpoint address.
        std::optional<std::string> EndpointAddress;

        OAIServerDiscoveryInfo();
        ~OAIServerDiscoveryInfo();
    };
    extern void to_json(json_t&, const OAIServerDiscoveryInfo&);
    extern void from_json(const json_t&, OAIServerDiscoveryInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIServerDiscoveryInfo);
