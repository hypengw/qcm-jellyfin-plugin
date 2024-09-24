#pragma once
/*
 * OAIUserApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIAuthenticateUserByName.h"
#include "jellyfin/model/OAIAuthenticationResult.h"
#include "jellyfin/model/OAICreateUserByName.h"
#include "jellyfin/model/OAIForgotPasswordDto.h"
#include "jellyfin/model/OAIForgotPasswordPinDto.h"
#include "jellyfin/model/OAIForgotPasswordResult.h"
#include "jellyfin/model/OAIPinRedeemResult.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAIQuickConnectDto.h"
#include "jellyfin/model/OAIUpdateUserPassword.h"
#include "jellyfin/model/OAIUserConfiguration.h"
#include "jellyfin/model/OAIUserDto.h"
#include "jellyfin/model/OAIUserPolicy.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_authenticateUserByName = OAIAuthenticationResult;
using return_type_authenticateWithQuickConnect = OAIAuthenticationResult;
using return_type_createUserByName = OAIUserDto;
using return_type_deleteUser = std::nullptr_t;
using return_type_forgotPassword = OAIForgotPasswordResult;
using return_type_forgotPasswordPin = OAIPinRedeemResult;
using return_type_getCurrentUser = OAIUserDto;
using return_type_getPublicUsers = std::vector<OAIUserDto>;
using return_type_getUserById = OAIUserDto;
using return_type_getUsers = std::vector<OAIUserDto>;
using return_type_updateUser = std::nullptr_t;
using return_type_updateUserConfiguration = std::nullptr_t;
using return_type_updateUserPassword = std::nullptr_t;
using return_type_updateUserPolicy = std::nullptr_t;
}

namespace api::param 
{
struct authenticateUserByName {
    OAIAuthenticateUserByName body; // The M:Jellyfin.Api.Controllers.UserController.AuthenticateUserByName(Jellyfin.Api.Models.UserDtos.AuthenticateUserByName) request.
};
struct authenticateWithQuickConnect {
    OAIQuickConnectDto body; // The Jellyfin.Api.Models.UserDtos.QuickConnectDto request.
};
struct createUserByName {
    OAICreateUserByName body; // The create user by name request body.
};
struct deleteUser {
    std::string userId; // The user id.
};
struct forgotPassword {
    OAIForgotPasswordDto body; // The forgot password request containing the entered username.
};
struct forgotPasswordPin {
    OAIForgotPasswordPinDto body; // The forgot password pin request containing the entered pin.
};
struct getCurrentUser {
};
struct getPublicUsers {
};
struct getUserById {
    std::string userId; // The user id.
};
struct getUsers {
    std::optional<bool> isHidden; // Optional filter by IsHidden&#x3D;true or false.
    std::optional<bool> isDisabled; // Optional filter by IsDisabled&#x3D;true or false.
};
struct updateUser {
    OAIUserDto body; // The updated user model.
    std::optional<std::string> userId; // The user id.
};
struct updateUserConfiguration {
    OAIUserConfiguration body; // The new user configuration.
    std::optional<std::string> userId; // The user id.
};
struct updateUserPassword {
    OAIUpdateUserPassword body; // The M:Jellyfin.Api.Controllers.UserController.UpdateUserPassword(System.Nullable{System.Guid},Jellyfin.Api.Models.UserDtos.UpdateUserPassword) request.
    std::optional<std::string> userId; // The user id.
};
struct updateUserPolicy {
    std::string userId; // The user id.
    OAIUserPolicy body; // The new user policy.
};
}

namespace api 
{
// Authenticates a user by name.
struct authenticateUserByName {
public:
    using in_type                      = param::authenticateUserByName;
    using out_type                     = model::return_type_authenticateUserByName;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Users/AuthenticateByName"sv; 
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
 * returnType: OAIAuthenticationResult
 * returnFormat: 
 * returnBaseType: OAIAuthenticationResult
 * returnContainer: 
 * baseName: User
 * defaultResponse: OAIAuthenticationResult()
 */
};
// Authenticates a user with quick connect.
struct authenticateWithQuickConnect {
public:
    using in_type                      = param::authenticateWithQuickConnect;
    using out_type                     = model::return_type_authenticateWithQuickConnect;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Users/AuthenticateWithQuickConnect"sv; 
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
 * returnType: OAIAuthenticationResult
 * returnFormat: 
 * returnBaseType: OAIAuthenticationResult
 * returnContainer: 
 * baseName: User
 * defaultResponse: OAIAuthenticationResult()
 */
};
// Creates a user.
struct createUserByName {
public:
    using in_type                      = param::createUserByName;
    using out_type                     = model::return_type_createUserByName;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Users/New"sv; 
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
 * returnType: OAIUserDto
 * returnFormat: 
 * returnBaseType: OAIUserDto
 * returnContainer: 
 * baseName: User
 * defaultResponse: OAIUserDto()
 */
};
// Deletes a user.
struct deleteUser {
public:
    using in_type                      = param::deleteUser;
    using out_type                     = model::return_type_deleteUser;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/Users/{}"sv,
            input.userId
        );
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
 * baseName: User
 * defaultResponse: 
 */
};
// Initiates the forgot password process for a local user.
struct forgotPassword {
public:
    using in_type                      = param::forgotPassword;
    using out_type                     = model::return_type_forgotPassword;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Users/ForgotPassword"sv; 
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
 * returnType: OAIForgotPasswordResult
 * returnFormat: 
 * returnBaseType: OAIForgotPasswordResult
 * returnContainer: 
 * baseName: User
 * defaultResponse: OAIForgotPasswordResult()
 */
};
// Redeems a forgot password pin.
struct forgotPasswordPin {
public:
    using in_type                      = param::forgotPasswordPin;
    using out_type                     = model::return_type_forgotPasswordPin;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Users/ForgotPassword/Pin"sv; 
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
 * returnType: OAIPinRedeemResult
 * returnFormat: 
 * returnBaseType: OAIPinRedeemResult
 * returnContainer: 
 * baseName: User
 * defaultResponse: OAIPinRedeemResult()
 */
};
// Gets the user based on auth token.
struct getCurrentUser {
public:
    using in_type                      = param::getCurrentUser;
    using out_type                     = model::return_type_getCurrentUser;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Users/Me"sv; 
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
 * returnType: OAIUserDto
 * returnFormat: 
 * returnBaseType: OAIUserDto
 * returnContainer: 
 * baseName: User
 * defaultResponse: OAIUserDto()
 */
};
// Gets a list of publicly visible users for display on a login screen.
struct getPublicUsers {
public:
    using in_type                      = param::getPublicUsers;
    using out_type                     = model::return_type_getPublicUsers;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Users/Public"sv; 
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
 * returnType: std::vector&lt;OAIUserDto&gt;
 * returnFormat: 
 * returnBaseType: OAIUserDto
 * returnContainer: array
 * baseName: User
 * defaultResponse: {}
 */
};
// Gets a user by Id.
struct getUserById {
public:
    using in_type                      = param::getUserById;
    using out_type                     = model::return_type_getUserById;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Users/{}"sv,
            input.userId
        );
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
 * returnType: OAIUserDto
 * returnFormat: 
 * returnBaseType: OAIUserDto
 * returnContainer: 
 * baseName: User
 * defaultResponse: OAIUserDto()
 */
};
// Gets a list of users.
struct getUsers {
public:
    using in_type                      = param::getUsers;
    using out_type                     = model::return_type_getUsers;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Users"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.isHidden)
            p.set_param("isHidden", convert_from<std::string>(input.isHidden.value()));
        if(input.isDisabled)
            p.set_param("isDisabled", convert_from<std::string>(input.isDisabled.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;OAIUserDto&gt;
 * returnFormat: 
 * returnBaseType: OAIUserDto
 * returnContainer: array
 * baseName: User
 * defaultResponse: {}
 */
};
// Updates a user.
struct updateUser {
public:
    using in_type                      = param::updateUser;
    using out_type                     = model::return_type_updateUser;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Users"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
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
 * baseName: User
 * defaultResponse: 
 */
};
// Updates a user configuration.
struct updateUserConfiguration {
public:
    using in_type                      = param::updateUserConfiguration;
    using out_type                     = model::return_type_updateUserConfiguration;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Users/Configuration"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
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
 * baseName: User
 * defaultResponse: 
 */
};
// Updates a user&#39;s password.
struct updateUserPassword {
public:
    using in_type                      = param::updateUserPassword;
    using out_type                     = model::return_type_updateUserPassword;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Users/Password"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
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
 * baseName: User
 * defaultResponse: 
 */
};
// Updates a user policy.
struct updateUserPolicy {
public:
    using in_type                      = param::updateUserPolicy;
    using out_type                     = model::return_type_updateUserPolicy;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Users/{}/Policy"sv,
            input.userId
        );
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
 * baseName: User
 * defaultResponse: 
 */
};
}
}
