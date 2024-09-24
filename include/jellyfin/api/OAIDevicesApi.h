#pragma once
/*
 * OAIDevicesApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIDeviceInfo.h"
#include "jellyfin/model/OAIDeviceInfoQueryResult.h"
#include "jellyfin/model/OAIDeviceOptions.h"
#include "jellyfin/model/OAIDeviceOptionsDto.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include <string>

namespace jellyfin {
namespace model
{
using return_type_deleteDevice = std::nullptr_t;
using return_type_getDeviceInfo = OAIDeviceInfo;
using return_type_getDeviceOptions = OAIDeviceOptions;
using return_type_getDevices = OAIDeviceInfoQueryResult;
using return_type_updateDeviceOptions = std::nullptr_t;
}

namespace api::param 
{
struct deleteDevice {
    std::string id; // Device Id.
};
struct getDeviceInfo {
    std::string id; // Device Id.
};
struct getDeviceOptions {
    std::string id; // Device Id.
};
struct getDevices {
    std::optional<std::string> userId; // Gets or sets the user identifier.
};
struct updateDeviceOptions {
    std::string id; // Device Id.
    OAIDeviceOptionsDto body; // Device Options.
};
}

namespace api 
{
// Deletes a device.
struct deleteDevice {
public:
    using in_type                      = param::deleteDevice;
    using out_type                     = model::return_type_deleteDevice;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return "/Devices"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("id", convert_from<std::string>(input.id));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Devices
 * defaultResponse: 
 */
};
// Get info for a device.
struct getDeviceInfo {
public:
    using in_type                      = param::getDeviceInfo;
    using out_type                     = model::return_type_getDeviceInfo;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Devices/Info"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("id", convert_from<std::string>(input.id));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIDeviceInfo
 * returnFormat: 
 * returnBaseType: OAIDeviceInfo
 * returnContainer: 
 * baseName: Devices
 * defaultResponse: OAIDeviceInfo()
 */
};
// Get options for a device.
struct getDeviceOptions {
public:
    using in_type                      = param::getDeviceOptions;
    using out_type                     = model::return_type_getDeviceOptions;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Devices/Options"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("id", convert_from<std::string>(input.id));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIDeviceOptions
 * returnFormat: 
 * returnBaseType: OAIDeviceOptions
 * returnContainer: 
 * baseName: Devices
 * defaultResponse: OAIDeviceOptions()
 */
};
// Get Devices.
struct getDevices {
public:
    using in_type                      = param::getDevices;
    using out_type                     = model::return_type_getDevices;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Devices"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIDeviceInfoQueryResult
 * returnFormat: 
 * returnBaseType: OAIDeviceInfoQueryResult
 * returnContainer: 
 * baseName: Devices
 * defaultResponse: OAIDeviceInfoQueryResult()
 */
};
// Update device options.
struct updateDeviceOptions {
public:
    using in_type                      = param::updateDeviceOptions;
    using out_type                     = model::return_type_updateDeviceOptions;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Devices/Options"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("id", convert_from<std::string>(input.id));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Devices
 * defaultResponse: 
 */
};
}
}
