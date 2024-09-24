#pragma once

/*
 * OAIDeviceOptions.h
 * name: DeviceOptions
 * schemaName: DeviceOptions
 * classFilename: DeviceOptions
 * classVarName: DeviceOptions
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * An entity representing custom options for a device.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIDeviceOptions {
    public:
    
        // Gets the id.
        std::int32_t Id;

        // Gets the device id.
        std::string DeviceId;

        // Gets or sets the custom name.
        std::optional<std::string> CustomName;

        OAIDeviceOptions();
        ~OAIDeviceOptions();
    };
    extern void to_json(json_t&, const OAIDeviceOptions&);
    extern void from_json(const json_t&, OAIDeviceOptions&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIDeviceOptions);
