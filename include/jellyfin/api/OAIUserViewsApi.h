#pragma once
/*
 * OAIUserViewsApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIBaseItemDtoQueryResult.h"
#include "jellyfin/model/OAICollectionType.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAISpecialViewOptionDto.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getGroupingOptions = std::vector<OAISpecialViewOptionDto>;
using return_type_getUserViews = OAIBaseItemDtoQueryResult;
}

namespace api::param 
{
struct getGroupingOptions {
    std::optional<std::string> userId; // User id.
};
struct getUserViews {
    std::optional<std::string> userId; // User id.
    std::optional<bool> includeExternalContent; // Whether or not to include external views such as channels or live tv.
    std::optional<std::vector<OAICollectionType>> presetViews; // Preset views.
    std::optional<bool> includeHidden; // Whether or not to include hidden content.
};
}

namespace api 
{
// Get user view grouping options.
struct getGroupingOptions {
public:
    using in_type                      = param::getGroupingOptions;
    using out_type                     = model::return_type_getGroupingOptions;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/UserViews/GroupingOptions"sv; 
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
 * returnType: std::vector&lt;OAISpecialViewOptionDto&gt;
 * returnFormat: 
 * returnBaseType: OAISpecialViewOptionDto
 * returnContainer: array
 * baseName: UserViews
 * defaultResponse: {}
 */
};
// Get user views.
struct getUserViews {
public:
    using in_type                      = param::getUserViews;
    using out_type                     = model::return_type_getUserViews;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/UserViews"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.includeExternalContent)
            p.set_param("includeExternalContent", convert_from<std::string>(input.includeExternalContent.value()));
        if(input.presetViews)
            p.set_param("presetViews", input.presetViews.value());
        if(input.includeHidden)
            p.set_param("includeHidden", convert_from<std::string>(input.includeHidden.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIBaseItemDtoQueryResult
 * returnFormat: 
 * returnBaseType: OAIBaseItemDtoQueryResult
 * returnContainer: 
 * baseName: UserViews
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
}
}
