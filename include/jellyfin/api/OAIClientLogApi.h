#pragma once
/*
 * OAIClientLogApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIClientLogDocumentResponseDto.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_logFile = OAIClientLogDocumentResponseDto;
}

namespace api::param 
{
struct logFile {
    std::optional<std::vector<std::byte>> body; // 
};
}

namespace api 
{
// Upload a document.
struct logFile {
public:
    using in_type                      = param::logFile;
    using out_type                     = model::return_type_logFile;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/ClientLog/Document"sv; 
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
 * returnType: OAIClientLogDocumentResponseDto
 * returnFormat: 
 * returnBaseType: OAIClientLogDocumentResponseDto
 * returnContainer: 
 * baseName: ClientLog
 * defaultResponse: OAIClientLogDocumentResponseDto()
 */
};
}
}
