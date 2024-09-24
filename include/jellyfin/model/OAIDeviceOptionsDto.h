#pragma once

/*
 * OAIDeviceOptionsDto.h
 * name: DeviceOptionsDto
 * schemaName: DeviceOptionsDto
 * classFilename: DeviceOptionsDto
 * classVarName: DeviceOptionsDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * A dto representing custom options for a device.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIDeviceOptionsDto {
    public:
    
        // Gets or sets the id.
        std::int32_t Id;

        // Gets or sets the device id.
        std::optional<std::string> DeviceId;

        // Gets or sets the custom name.
        std::optional<std::string> CustomName;

        OAIDeviceOptionsDto();
        ~OAIDeviceOptionsDto();
    };
    extern void to_json(json_t&, const OAIDeviceOptionsDto&);
    extern void from_json(const json_t&, OAIDeviceOptionsDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIDeviceOptionsDto);
