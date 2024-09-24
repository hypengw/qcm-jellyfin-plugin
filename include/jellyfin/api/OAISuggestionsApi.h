#pragma once
/*
 * OAISuggestionsApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIBaseItemDtoQueryResult.h"
#include "jellyfin/model/OAIBaseItemKind.h"
#include "jellyfin/model/OAIMediaType.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getSuggestions = OAIBaseItemDtoQueryResult;
}

namespace api::param 
{
struct getSuggestions {
    std::optional<std::string> userId; // The user id.
    std::optional<std::vector<OAIMediaType>> mediaType; // The media types.
    std::optional<std::vector<OAIBaseItemKind>> type; // The type.
    std::optional<std::int32_t> startIndex; // Optional. The start index.
    std::optional<std::int32_t> limit; // Optional. The limit.
    std::optional<bool> enableTotalRecordCount; // Whether to enable the total record count.
};
}

namespace api 
{
// Gets suggestions.
struct getSuggestions {
public:
    using in_type                      = param::getSuggestions;
    using out_type                     = model::return_type_getSuggestions;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Items/Suggestions"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.mediaType)
            p.set_param("mediaType", input.mediaType.value());
        if(input.type)
            p.set_param("type", input.type.value());
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.enableTotalRecordCount)
            p.set_param("enableTotalRecordCount", convert_from<std::string>(input.enableTotalRecordCount.value()));
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
 * baseName: Suggestions
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
}
}
