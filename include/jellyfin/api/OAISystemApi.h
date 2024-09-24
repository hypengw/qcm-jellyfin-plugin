#pragma once
/*
 * OAISystemApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIEndPointInfo.h"
#include "jellyfin/model/OAILogFile.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAIPublicSystemInfo.h"
#include "jellyfin/model/OAISystemInfo.h"
#include "jellyfin/model/OAIWakeOnLanInfo.h"
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getEndpointInfo = OAIEndPointInfo;
using return_type_getLogFile = std::vector<std::byte>;
using return_type_getPingSystem = std::string;
using return_type_getPublicSystemInfo = OAIPublicSystemInfo;
using return_type_getServerLogs = std::vector<OAILogFile>;
using return_type_getSystemInfo = OAISystemInfo;
using return_type_getWakeOnLanInfo = std::vector<OAIWakeOnLanInfo>;
using return_type_postPingSystem = std::string;
using return_type_restartApplication = std::nullptr_t;
using return_type_shutdownApplication = std::nullptr_t;
}

namespace api::param 
{
struct getEndpointInfo {
};
struct getLogFile {
    std::string name; // The name of the log file to get.
};
struct getPingSystem {
};
struct getPublicSystemInfo {
};
struct getServerLogs {
};
struct getSystemInfo {
};
struct getWakeOnLanInfo {
};
struct postPingSystem {
};
struct restartApplication {
};
struct shutdownApplication {
};
}

namespace api 
{
// Gets information about the request endpoint.
struct getEndpointInfo {
public:
    using in_type                      = param::getEndpointInfo;
    using out_type                     = model::return_type_getEndpointInfo;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/System/Endpoint"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIEndPointInfo
 * returnFormat: 
 * returnBaseType: OAIEndPointInfo
 * returnContainer: 
 * baseName: System
 * defaultResponse: OAIEndPointInfo()
 */
};
// Gets a log file.
struct getLogFile {
public:
    using in_type                      = param::getLogFile;
    using out_type                     = model::return_type_getLogFile;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/System/Logs/Log"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("name", convert_from<std::string>(input.name));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: System
 * defaultResponse: {}
 */
};
// Pings the system.
struct getPingSystem {
public:
    using in_type                      = param::getPingSystem;
    using out_type                     = model::return_type_getPingSystem;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/System/Ping"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::string
 * returnFormat: 
 * returnBaseType: std::string
 * returnContainer: 
 * baseName: System
 * defaultResponse: {}
 */
};
// Gets public information about the server.
struct getPublicSystemInfo {
public:
    using in_type                      = param::getPublicSystemInfo;
    using out_type                     = model::return_type_getPublicSystemInfo;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/System/Info/Public"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIPublicSystemInfo
 * returnFormat: 
 * returnBaseType: OAIPublicSystemInfo
 * returnContainer: 
 * baseName: System
 * defaultResponse: OAIPublicSystemInfo()
 */
};
// Gets a list of available server log files.
struct getServerLogs {
public:
    using in_type                      = param::getServerLogs;
    using out_type                     = model::return_type_getServerLogs;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/System/Logs"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;OAILogFile&gt;
 * returnFormat: 
 * returnBaseType: OAILogFile
 * returnContainer: array
 * baseName: System
 * defaultResponse: {}
 */
};
// Gets information about the server.
struct getSystemInfo {
public:
    using in_type                      = param::getSystemInfo;
    using out_type                     = model::return_type_getSystemInfo;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/System/Info"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAISystemInfo
 * returnFormat: 
 * returnBaseType: OAISystemInfo
 * returnContainer: 
 * baseName: System
 * defaultResponse: OAISystemInfo()
 */
};
// Gets wake on lan information.
struct getWakeOnLanInfo {
public:
    using in_type                      = param::getWakeOnLanInfo;
    using out_type                     = model::return_type_getWakeOnLanInfo;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/System/WakeOnLanInfo"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;OAIWakeOnLanInfo&gt;
 * returnFormat: 
 * returnBaseType: OAIWakeOnLanInfo
 * returnContainer: array
 * baseName: System
 * defaultResponse: {}
 */
};
// Pings the system.
struct postPingSystem {
public:
    using in_type                      = param::postPingSystem;
    using out_type                     = model::return_type_postPingSystem;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/System/Ping"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::string
 * returnFormat: 
 * returnBaseType: std::string
 * returnContainer: 
 * baseName: System
 * defaultResponse: {}
 */
};
// Restarts the application.
struct restartApplication {
public:
    using in_type                      = param::restartApplication;
    using out_type                     = model::return_type_restartApplication;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/System/Restart"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
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
 * baseName: System
 * defaultResponse: 
 */
};
// Shuts down the application.
struct shutdownApplication {
public:
    using in_type                      = param::shutdownApplication;
    using out_type                     = model::return_type_shutdownApplication;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/System/Shutdown"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
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
 * baseName: System
 * defaultResponse: 
 */
};
}
}
