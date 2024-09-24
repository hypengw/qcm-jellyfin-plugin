#pragma once

/*
 * OAIWakeOnLanInfo.h
 * name: WakeOnLanInfo
 * schemaName: WakeOnLanInfo
 * classFilename: WakeOnLanInfo
 * classVarName: WakeOnLanInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Provides the MAC address and port for wake-on-LAN functionality.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIWakeOnLanInfo {
    public:
    
        // Gets the MAC address of the device.
        std::optional<std::string> MacAddress;

        // Gets or sets the wake-on-LAN port.
        std::int32_t Port;

        OAIWakeOnLanInfo();
        ~OAIWakeOnLanInfo();
    };
    extern void to_json(json_t&, const OAIWakeOnLanInfo&);
    extern void from_json(const json_t&, OAIWakeOnLanInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIWakeOnLanInfo);
