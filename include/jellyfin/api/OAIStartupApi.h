#pragma once
/*
 * OAIStartupApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIStartupConfigurationDto.h"
#include "jellyfin/model/OAIStartupRemoteAccessDto.h"
#include "jellyfin/model/OAIStartupUserDto.h"

namespace jellyfin {
namespace model
{
using return_type_completeWizard = std::nullptr_t;
using return_type_getFirstUser = OAIStartupUserDto;
using return_type_getFirstUser2 = OAIStartupUserDto;
using return_type_getStartupConfiguration = OAIStartupConfigurationDto;
using return_type_setRemoteAccess = std::nullptr_t;
using return_type_updateInitialConfiguration = std::nullptr_t;
using return_type_updateStartupUser = std::nullptr_t;
}

namespace api::param 
{
struct completeWizard {
};
struct getFirstUser {
};
struct getFirstUser2 {
};
struct getStartupConfiguration {
};
struct setRemoteAccess {
    OAIStartupRemoteAccessDto body; // The startup remote access dto.
};
struct updateInitialConfiguration {
    OAIStartupConfigurationDto body; // The updated startup configuration.
};
struct updateStartupUser {
    std::optional<OAIStartupUserDto> body; // The DTO containing username and password.
};
}

namespace api 
{
// Completes the startup wizard.
struct completeWizard {
public:
    using in_type                      = param::completeWizard;
    using out_type                     = model::return_type_completeWizard;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Startup/Complete"sv; 
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
 * baseName: Startup
 * defaultResponse: 
 */
};
// Gets the first user.
struct getFirstUser {
public:
    using in_type                      = param::getFirstUser;
    using out_type                     = model::return_type_getFirstUser;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Startup/User"sv; 
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
 * returnType: OAIStartupUserDto
 * returnFormat: 
 * returnBaseType: OAIStartupUserDto
 * returnContainer: 
 * baseName: Startup
 * defaultResponse: OAIStartupUserDto()
 */
};
// Gets the first user.
struct getFirstUser2 {
public:
    using in_type                      = param::getFirstUser2;
    using out_type                     = model::return_type_getFirstUser2;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Startup/FirstUser"sv; 
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
 * returnType: OAIStartupUserDto
 * returnFormat: 
 * returnBaseType: OAIStartupUserDto
 * returnContainer: 
 * baseName: Startup
 * defaultResponse: OAIStartupUserDto()
 */
};
// Gets the initial startup wizard configuration.
struct getStartupConfiguration {
public:
    using in_type                      = param::getStartupConfiguration;
    using out_type                     = model::return_type_getStartupConfiguration;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Startup/Configuration"sv; 
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
 * returnType: OAIStartupConfigurationDto
 * returnFormat: 
 * returnBaseType: OAIStartupConfigurationDto
 * returnContainer: 
 * baseName: Startup
 * defaultResponse: OAIStartupConfigurationDto()
 */
};
// Sets remote access and UPnP.
struct setRemoteAccess {
public:
    using in_type                      = param::setRemoteAccess;
    using out_type                     = model::return_type_setRemoteAccess;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Startup/RemoteAccess"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
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
 * baseName: Startup
 * defaultResponse: 
 */
};
// Sets the initial startup wizard configuration.
struct updateInitialConfiguration {
public:
    using in_type                      = param::updateInitialConfiguration;
    using out_type                     = model::return_type_updateInitialConfiguration;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Startup/Configuration"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
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
 * baseName: Startup
 * defaultResponse: 
 */
};
// Sets the user name and password.
struct updateStartupUser {
public:
    using in_type                      = param::updateStartupUser;
    using out_type                     = model::return_type_updateStartupUser;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Startup/User"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        if(input.body)
            out = format_param(input.body.value());
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Startup
 * defaultResponse: 
 */
};
}
}
