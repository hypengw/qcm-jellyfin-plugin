#pragma once
/*
 * OAIItemRefreshApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIMetadataRefreshMode.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include <cstdint>
#include <string>

namespace jellyfin {
namespace model
{
using return_type_refreshItem = std::nullptr_t;
}

namespace api::param 
{
struct refreshItem {
    std::string itemId; // Item id.
    std::optional<OAIMetadataRefreshMode> metadataRefreshMode; // (Optional) Specifies the metadata refresh mode.
    std::optional<OAIMetadataRefreshMode> imageRefreshMode; // (Optional) Specifies the image refresh mode.
    std::optional<bool> replaceAllMetadata; // (Optional) Determines if metadata should be replaced. Only applicable if mode is FullRefresh.
    std::optional<bool> replaceAllImages; // (Optional) Determines if images should be replaced. Only applicable if mode is FullRefresh.
};
}

namespace api 
{
// Refreshes metadata for an item.
struct refreshItem {
public:
    using in_type                      = param::refreshItem;
    using out_type                     = model::return_type_refreshItem;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Items/{}/Refresh"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.metadataRefreshMode)
            p.set_param("metadataRefreshMode", convert_from<std::string>(input.metadataRefreshMode.value()));
        if(input.imageRefreshMode)
            p.set_param("imageRefreshMode", convert_from<std::string>(input.imageRefreshMode.value()));
        if(input.replaceAllMetadata)
            p.set_param("replaceAllMetadata", convert_from<std::string>(input.replaceAllMetadata.value()));
        if(input.replaceAllImages)
            p.set_param("replaceAllImages", convert_from<std::string>(input.replaceAllImages.value()));
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
 * baseName: ItemRefresh
 * defaultResponse: 
 */
};
}
}
