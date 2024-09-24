#pragma once
/*
 * OAITrickplayApi.h
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
using return_type_getTrickplayHlsPlaylist = std::vector<std::byte>;
using return_type_getTrickplayTileImage = std::vector<std::byte>;
}

namespace api::param 
{
struct getTrickplayHlsPlaylist {
    std::string itemId; // The item id.
    std::int32_t width; // The width of a single tile.
    std::optional<std::string> mediaSourceId; // The media version id, if using an alternate version.
};
struct getTrickplayTileImage {
    std::string itemId; // The item id.
    std::int32_t width; // The width of a single tile.
    std::int32_t index; // The index of the desired tile.
    std::optional<std::string> mediaSourceId; // The media version id, if using an alternate version.
};
}

namespace api 
{
// Gets an image tiles playlist for trickplay.
struct getTrickplayHlsPlaylist {
public:
    using in_type                      = param::getTrickplayHlsPlaylist;
    using out_type                     = model::return_type_getTrickplayHlsPlaylist;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Videos/{}/Trickplay/{}/tiles.m3u8"sv,
            input.itemId,
            input.width
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.mediaSourceId)
            p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId.value()));
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
 * baseName: Trickplay
 * defaultResponse: {}
 */
};
// Gets a trickplay tile image.
struct getTrickplayTileImage {
public:
    using in_type                      = param::getTrickplayTileImage;
    using out_type                     = model::return_type_getTrickplayTileImage;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Videos/{}/Trickplay/{}/{}.jpg"sv,
            input.itemId,
            input.width,
            input.index
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.mediaSourceId)
            p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId.value()));
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
 * baseName: Trickplay
 * defaultResponse: {}
 */
};
}
}
