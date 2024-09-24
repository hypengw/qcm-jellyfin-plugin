#pragma once
/*
 * OAIConfigurationApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIMetadataOptions.h"
#include "jellyfin/model/OAIServerConfiguration.h"
#include <memory>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getConfiguration = OAIServerConfiguration;
using return_type_getDefaultMetadataOptions = OAIMetadataOptions;
using return_type_getNamedConfiguration = std::vector<std::byte>;
using return_type_updateConfiguration = std::nullptr_t;
using return_type_updateNamedConfiguration = std::nullptr_t;
}

namespace api::param 
{
struct getConfiguration {
};
struct getDefaultMetadataOptions {
};
struct getNamedConfiguration {
    std::string key; // Configuration key.
};
struct updateConfiguration {
    OAIServerConfiguration body; // Configuration.
};
struct updateNamedConfiguration {
    std::string key; // Configuration key.
    rc<json_t> body; // Configuration.
};
}

namespace api 
{
// Gets application configuration.
struct getConfiguration {
public:
    using in_type                      = param::getConfiguration;
    using out_type                     = model::return_type_getConfiguration;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/System/Configuration"sv; 
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
 * returnType: OAIServerConfiguration
 * returnFormat: 
 * returnBaseType: OAIServerConfiguration
 * returnContainer: 
 * baseName: Configuration
 * defaultResponse: OAIServerConfiguration()
 */
};
// Gets a default MetadataOptions object.
struct getDefaultMetadataOptions {
public:
    using in_type                      = param::getDefaultMetadataOptions;
    using out_type                     = model::return_type_getDefaultMetadataOptions;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/System/Configuration/MetadataOptions/Default"sv; 
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
 * returnType: OAIMetadataOptions
 * returnFormat: 
 * returnBaseType: OAIMetadataOptions
 * returnContainer: 
 * baseName: Configuration
 * defaultResponse: OAIMetadataOptions()
 */
};
// Gets a named configuration.
struct getNamedConfiguration {
public:
    using in_type                      = param::getNamedConfiguration;
    using out_type                     = model::return_type_getNamedConfiguration;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/System/Configuration/{}"sv,
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
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Configuration
 * defaultResponse: {}
 */
};
// Updates application configuration.
struct updateConfiguration {
public:
    using in_type                      = param::updateConfiguration;
    using out_type                     = model::return_type_updateConfiguration;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/System/Configuration"sv; 
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
 * baseName: Configuration
 * defaultResponse: 
 */
};
// Updates named configuration.
struct updateNamedConfiguration {
public:
    using in_type                      = param::updateNamedConfiguration;
    using out_type                     = model::return_type_updateNamedConfiguration;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/System/Configuration/{}"sv,
            input.key
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
 * baseName: Configuration
 * defaultResponse: 
 */
};
}
}
