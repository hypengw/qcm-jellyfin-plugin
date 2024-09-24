#pragma once
/*
 * OAIQuickConnectApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAIQuickConnectResult.h"
#include <cstdint>
#include <string>

namespace jellyfin {
namespace model
{
using return_type_authorizeQuickConnect = bool;
using return_type_getQuickConnectEnabled = bool;
using return_type_getQuickConnectState = OAIQuickConnectResult;
using return_type_initiateQuickConnect = OAIQuickConnectResult;
}

namespace api::param 
{
struct authorizeQuickConnect {
    std::string code; // Quick connect code to authorize.
    std::optional<std::string> userId; // The user the authorize. Access to the requested user is required.
};
struct getQuickConnectEnabled {
};
struct getQuickConnectState {
    std::string secret; // Secret previously returned from the Initiate endpoint.
};
struct initiateQuickConnect {
};
}

namespace api 
{
// Authorizes a pending quick connect request.
struct authorizeQuickConnect {
public:
    using in_type                      = param::authorizeQuickConnect;
    using out_type                     = model::return_type_authorizeQuickConnect;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/QuickConnect/Authorize"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("code", convert_from<std::string>(input.code));
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
 * returnType: bool
 * returnFormat: 
 * returnBaseType: bool
 * returnContainer: 
 * baseName: QuickConnect
 * defaultResponse: false
 */
};
// Gets the current quick connect state.
struct getQuickConnectEnabled {
public:
    using in_type                      = param::getQuickConnectEnabled;
    using out_type                     = model::return_type_getQuickConnectEnabled;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/QuickConnect/Enabled"sv; 
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
 * returnType: bool
 * returnFormat: 
 * returnBaseType: bool
 * returnContainer: 
 * baseName: QuickConnect
 * defaultResponse: false
 */
};
// Attempts to retrieve authentication information.
struct getQuickConnectState {
public:
    using in_type                      = param::getQuickConnectState;
    using out_type                     = model::return_type_getQuickConnectState;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/QuickConnect/Connect"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("secret", convert_from<std::string>(input.secret));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIQuickConnectResult
 * returnFormat: 
 * returnBaseType: OAIQuickConnectResult
 * returnContainer: 
 * baseName: QuickConnect
 * defaultResponse: OAIQuickConnectResult()
 */
};
// Initiate a new quick connect request.
struct initiateQuickConnect {
public:
    using in_type                      = param::initiateQuickConnect;
    using out_type                     = model::return_type_initiateQuickConnect;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/QuickConnect/Initiate"sv; 
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
 * returnType: OAIQuickConnectResult
 * returnFormat: 
 * returnBaseType: OAIQuickConnectResult
 * returnContainer: 
 * baseName: QuickConnect
 * defaultResponse: OAIQuickConnectResult()
 */
};
}
}
