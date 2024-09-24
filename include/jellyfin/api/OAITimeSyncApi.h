#pragma once
/*
 * OAITimeSyncApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIUtcTimeResponse.h"

namespace jellyfin {
namespace model
{
using return_type_getUtcTime = OAIUtcTimeResponse;
}

namespace api::param 
{
struct getUtcTime {
};
}

namespace api 
{
// Gets the current UTC time.
struct getUtcTime {
public:
    using in_type                      = param::getUtcTime;
    using out_type                     = model::return_type_getUtcTime;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/GetUtcTime"sv; 
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
 * returnType: OAIUtcTimeResponse
 * returnFormat: 
 * returnBaseType: OAIUtcTimeResponse
 * returnContainer: 
 * baseName: TimeSync
 * defaultResponse: OAIUtcTimeResponse()
 */
};
}
}
