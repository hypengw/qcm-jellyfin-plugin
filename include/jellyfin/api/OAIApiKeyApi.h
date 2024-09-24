#pragma once
/*
 * OAIApiKeyApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIAuthenticationInfoQueryResult.h"
#include <string>

namespace jellyfin {
namespace model
{
using return_type_createKey = std::nullptr_t;
using return_type_getKeys = OAIAuthenticationInfoQueryResult;
using return_type_revokeKey = std::nullptr_t;
}

namespace api::param 
{
struct createKey {
    std::string app; // Name of the app using the authentication key.
};
struct getKeys {
};
struct revokeKey {
    std::string key; // The access token to delete.
};
}

namespace api 
{
// Create a new api key.
struct createKey {
public:
    using in_type                      = param::createKey;
    using out_type                     = model::return_type_createKey;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Auth/Keys"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("app", convert_from<std::string>(input.app));
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
 * baseName: ApiKey
 * defaultResponse: 
 */
};
// Get all keys.
struct getKeys {
public:
    using in_type                      = param::getKeys;
    using out_type                     = model::return_type_getKeys;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Auth/Keys"sv; 
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
 * returnType: OAIAuthenticationInfoQueryResult
 * returnFormat: 
 * returnBaseType: OAIAuthenticationInfoQueryResult
 * returnContainer: 
 * baseName: ApiKey
 * defaultResponse: OAIAuthenticationInfoQueryResult()
 */
};
// Remove an api key.
struct revokeKey {
public:
    using in_type                      = param::revokeKey;
    using out_type                     = model::return_type_revokeKey;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/Auth/Keys/{}"sv,
            input.key
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
 * baseName: ApiKey
 * defaultResponse: 
 */
};
}
}
