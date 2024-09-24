#pragma once
/*
 * OAIRemoteImageApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIImageProviderInfo.h"
#include "jellyfin/model/OAIImageType.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAIRemoteImageResult.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_downloadRemoteImage = std::nullptr_t;
using return_type_getRemoteImageProviders = std::vector<OAIImageProviderInfo>;
using return_type_getRemoteImages = OAIRemoteImageResult;
}

namespace api::param 
{
struct downloadRemoteImage {
    std::string itemId; // Item Id.
    OAIImageType type; // The image type.
    std::optional<std::string> imageUrl; // The image url.
};
struct getRemoteImageProviders {
    std::string itemId; // Item Id.
};
struct getRemoteImages {
    std::string itemId; // Item Id.
    std::optional<OAIImageType> type; // The image type.
    std::optional<std::int32_t> startIndex; // Optional. The record index to start at. All items with a lower index will be dropped from the results.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::string> providerName; // Optional. The image provider to use.
    std::optional<bool> includeAllLanguages; // Optional. Include all languages.
};
}

namespace api 
{
// Downloads a remote image for an item.
struct downloadRemoteImage {
public:
    using in_type                      = param::downloadRemoteImage;
    using out_type                     = model::return_type_downloadRemoteImage;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Items/{}/RemoteImages/Download"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("type", convert_from<std::string>(input.type));
        if(input.imageUrl)
            p.set_param("imageUrl", convert_from<std::string>(input.imageUrl.value()));
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
 * baseName: RemoteImage
 * defaultResponse: 
 */
};
// Gets available remote image providers for an item.
struct getRemoteImageProviders {
public:
    using in_type                      = param::getRemoteImageProviders;
    using out_type                     = model::return_type_getRemoteImageProviders;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/RemoteImages/Providers"sv,
            input.itemId
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
 * returnType: std::vector&lt;OAIImageProviderInfo&gt;
 * returnFormat: 
 * returnBaseType: OAIImageProviderInfo
 * returnContainer: array
 * baseName: RemoteImage
 * defaultResponse: {}
 */
};
// Gets available remote images for an item.
struct getRemoteImages {
public:
    using in_type                      = param::getRemoteImages;
    using out_type                     = model::return_type_getRemoteImages;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/RemoteImages"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.type)
            p.set_param("type", convert_from<std::string>(input.type.value()));
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.providerName)
            p.set_param("providerName", convert_from<std::string>(input.providerName.value()));
        if(input.includeAllLanguages)
            p.set_param("includeAllLanguages", convert_from<std::string>(input.includeAllLanguages.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIRemoteImageResult
 * returnFormat: 
 * returnBaseType: OAIRemoteImageResult
 * returnContainer: 
 * baseName: RemoteImage
 * defaultResponse: OAIRemoteImageResult()
 */
};
}
}
