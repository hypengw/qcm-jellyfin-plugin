#pragma once
/*
 * OAIActivityLogApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIActivityLogEntryQueryResult.h"
#include <cstdint>
#include <string>

namespace jellyfin {
namespace model
{
using return_type_getLogEntries = OAIActivityLogEntryQueryResult;
}

namespace api::param 
{
struct getLogEntries {
    std::optional<std::int32_t> startIndex; // Optional. The record index to start at. All items with a lower index will be dropped from the results.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::string> minDate; // Optional. The minimum date. Format &#x3D; ISO.
    std::optional<bool> hasUserId; // Optional. Filter log entries if it has user id, or not.
};
}

namespace api 
{
// Gets activity log entries.
struct getLogEntries {
public:
    using in_type                      = param::getLogEntries;
    using out_type                     = model::return_type_getLogEntries;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/System/ActivityLog/Entries"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.minDate)
            p.set_param("minDate", convert_from<std::string>(input.minDate.value()));
        if(input.hasUserId)
            p.set_param("hasUserId", convert_from<std::string>(input.hasUserId.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIActivityLogEntryQueryResult
 * returnFormat: 
 * returnBaseType: OAIActivityLogEntryQueryResult
 * returnContainer: 
 * baseName: ActivityLog
 * defaultResponse: OAIActivityLogEntryQueryResult()
 */
};
}
}
