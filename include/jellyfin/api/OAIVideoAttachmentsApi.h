#pragma once
/*
 * OAIVideoAttachmentsApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getAttachment = std::vector<std::byte>;
}

namespace api::param 
{
struct getAttachment {
    std::string videoId; // Video ID.
    std::string mediaSourceId; // Media Source ID.
    std::int32_t index; // Attachment Index.
};
}

namespace api 
{
// Get video attachment.
struct getAttachment {
public:
    using in_type                      = param::getAttachment;
    using out_type                     = model::return_type_getAttachment;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Videos/{}/{}/Attachments/{}"sv,
            input.videoId,
            input.mediaSourceId,
            input.index
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
 * baseName: VideoAttachments
 * defaultResponse: {}
 */
};
}
}
