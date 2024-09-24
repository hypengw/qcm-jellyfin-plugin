#pragma once
/*
 * OAIDisplayPreferencesApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIDisplayPreferencesDto.h"
#include <string>

namespace jellyfin {
namespace model
{
using return_type_getDisplayPreferences = OAIDisplayPreferencesDto;
using return_type_updateDisplayPreferences = std::nullptr_t;
}

namespace api::param 
{
struct getDisplayPreferences {
    std::string displayPreferencesId; // Display preferences id.
    std::string client; // Client.
    std::optional<std::string> userId; // User id.
};
struct updateDisplayPreferences {
    std::string displayPreferencesId; // Display preferences id.
    std::string client; // Client.
    OAIDisplayPreferencesDto body; // New Display Preferences object.
    std::optional<std::string> userId; // User Id.
};
}

namespace api 
{
// Get Display Preferences.
struct getDisplayPreferences {
public:
    using in_type                      = param::getDisplayPreferences;
    using out_type                     = model::return_type_getDisplayPreferences;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/DisplayPreferences/{}"sv,
            input.displayPreferencesId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        p.set_param("client", convert_from<std::string>(input.client));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIDisplayPreferencesDto
 * returnFormat: 
 * returnBaseType: OAIDisplayPreferencesDto
 * returnContainer: 
 * baseName: DisplayPreferences
 * defaultResponse: OAIDisplayPreferencesDto()
 */
};
// Update Display Preferences.
struct updateDisplayPreferences {
public:
    using in_type                      = param::updateDisplayPreferences;
    using out_type                     = model::return_type_updateDisplayPreferences;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/DisplayPreferences/{}"sv,
            input.displayPreferencesId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        p.set_param("client", convert_from<std::string>(input.client));
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
 * baseName: DisplayPreferences
 * defaultResponse: 
 */
};
}
}
