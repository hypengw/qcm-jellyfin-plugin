#pragma once
/*
 * OAISubtitleApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIFontFile.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAIRemoteSubtitleInfo.h"
#include "jellyfin/model/OAIUploadSubtitleDto.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_deleteSubtitle = std::nullptr_t;
using return_type_downloadRemoteSubtitles = std::nullptr_t;
using return_type_getFallbackFont = std::vector<std::byte>;
using return_type_getFallbackFontList = std::vector<OAIFontFile>;
using return_type_getRemoteSubtitles = std::vector<std::byte>;
using return_type_getSubtitle = std::vector<std::byte>;
using return_type_getSubtitlePlaylist = std::vector<std::byte>;
using return_type_getSubtitleWithTicks = std::vector<std::byte>;
using return_type_searchRemoteSubtitles = std::vector<OAIRemoteSubtitleInfo>;
using return_type_uploadSubtitle = std::nullptr_t;
}

namespace api::param 
{
struct deleteSubtitle {
    std::string itemId; // The item id.
    std::int32_t index; // The index of the subtitle file.
};
struct downloadRemoteSubtitles {
    std::string itemId; // The item id.
    std::string subtitleId; // The subtitle id.
};
struct getFallbackFont {
    std::string name; // The name of the fallback font file to get.
};
struct getFallbackFontList {
};
struct getRemoteSubtitles {
    std::string subtitleId; // The item id.
};
struct getSubtitle {
    std::string routeItemId; // The (route) item id.
    std::string routeMediaSourceId; // The (route) media source id.
    std::int32_t routeIndex; // The (route) subtitle stream index.
    std::string routeFormat; // The (route) format of the returned subtitle.
    std::optional<std::string> itemId; // The item id.
    std::optional<std::string> mediaSourceId; // The media source id.
    std::optional<std::int32_t> index; // The subtitle stream index.
    std::optional<std::string> format; // The format of the returned subtitle.
    std::optional<std::int64_t> endPositionTicks; // Optional. The end position of the subtitle in ticks.
    std::optional<bool> copyTimestamps; // Optional. Whether to copy the timestamps.
    std::optional<bool> addVttTimeMap; // Optional. Whether to add a VTT time map.
    std::optional<std::int64_t> startPositionTicks; // The start position of the subtitle in ticks.
};
struct getSubtitlePlaylist {
    std::string itemId; // The item id.
    std::int32_t index; // The subtitle stream index.
    std::string mediaSourceId; // The media source id.
    std::int32_t segmentLength; // The subtitle segment length.
};
struct getSubtitleWithTicks {
    std::string routeItemId; // The (route) item id.
    std::string routeMediaSourceId; // The (route) media source id.
    std::int32_t routeIndex; // The (route) subtitle stream index.
    std::int64_t routeStartPositionTicks; // The (route) start position of the subtitle in ticks.
    std::string routeFormat; // The (route) format of the returned subtitle.
    std::optional<std::string> itemId; // The item id.
    std::optional<std::string> mediaSourceId; // The media source id.
    std::optional<std::int32_t> index; // The subtitle stream index.
    std::optional<std::int64_t> startPositionTicks; // The start position of the subtitle in ticks.
    std::optional<std::string> format; // The format of the returned subtitle.
    std::optional<std::int64_t> endPositionTicks; // Optional. The end position of the subtitle in ticks.
    std::optional<bool> copyTimestamps; // Optional. Whether to copy the timestamps.
    std::optional<bool> addVttTimeMap; // Optional. Whether to add a VTT time map.
};
struct searchRemoteSubtitles {
    std::string itemId; // The item id.
    std::string language; // The language of the subtitles.
    std::optional<bool> isPerfectMatch; // Optional. Only show subtitles which are a perfect match.
};
struct uploadSubtitle {
    std::string itemId; // The item the subtitle belongs to.
    OAIUploadSubtitleDto body; // The request body.
};
}

namespace api 
{
// Deletes an external subtitle file.
struct deleteSubtitle {
public:
    using in_type                      = param::deleteSubtitle;
    using out_type                     = model::return_type_deleteSubtitle;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/Videos/{}/Subtitles/{}"sv,
            input.itemId,
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
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Subtitle
 * defaultResponse: 
 */
};
// Downloads a remote subtitle.
struct downloadRemoteSubtitles {
public:
    using in_type                      = param::downloadRemoteSubtitles;
    using out_type                     = model::return_type_downloadRemoteSubtitles;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Items/{}/RemoteSearch/Subtitles/{}"sv,
            input.itemId,
            input.subtitleId
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
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Subtitle
 * defaultResponse: 
 */
};
// Gets a fallback font file.
struct getFallbackFont {
public:
    using in_type                      = param::getFallbackFont;
    using out_type                     = model::return_type_getFallbackFont;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/FallbackFont/Fonts/{}"sv,
            input.name
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
 * baseName: Subtitle
 * defaultResponse: {}
 */
};
// Gets a list of available fallback font files.
struct getFallbackFontList {
public:
    using in_type                      = param::getFallbackFontList;
    using out_type                     = model::return_type_getFallbackFontList;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/FallbackFont/Fonts"sv; 
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
 * returnType: std::vector&lt;OAIFontFile&gt;
 * returnFormat: 
 * returnBaseType: OAIFontFile
 * returnContainer: array
 * baseName: Subtitle
 * defaultResponse: {}
 */
};
// Gets the remote subtitles.
struct getRemoteSubtitles {
public:
    using in_type                      = param::getRemoteSubtitles;
    using out_type                     = model::return_type_getRemoteSubtitles;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Providers/Subtitles/Subtitles/{}"sv,
            input.subtitleId
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
 * baseName: Subtitle
 * defaultResponse: {}
 */
};
// Gets subtitles in a specified format.
struct getSubtitle {
public:
    using in_type                      = param::getSubtitle;
    using out_type                     = model::return_type_getSubtitle;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Videos/{}/{}/Subtitles/{}/Stream.{}"sv,
            input.routeItemId,
            input.routeMediaSourceId,
            input.routeIndex,
            input.routeFormat
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.itemId)
            p.set_param("itemId", convert_from<std::string>(input.itemId.value()));
        if(input.mediaSourceId)
            p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId.value()));
        if(input.index)
            p.set_param("index", convert_from<std::string>(input.index.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.endPositionTicks)
            p.set_param("endPositionTicks", convert_from<std::string>(input.endPositionTicks.value()));
        if(input.copyTimestamps)
            p.set_param("copyTimestamps", convert_from<std::string>(input.copyTimestamps.value()));
        if(input.addVttTimeMap)
            p.set_param("addVttTimeMap", convert_from<std::string>(input.addVttTimeMap.value()));
        if(input.startPositionTicks)
            p.set_param("startPositionTicks", convert_from<std::string>(input.startPositionTicks.value()));
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
 * baseName: Subtitle
 * defaultResponse: {}
 */
};
// Gets an HLS subtitle playlist.
struct getSubtitlePlaylist {
public:
    using in_type                      = param::getSubtitlePlaylist;
    using out_type                     = model::return_type_getSubtitlePlaylist;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Videos/{}/{}/Subtitles/{}/subtitles.m3u8"sv,
            input.itemId,
            input.index,
            input.mediaSourceId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("segmentLength", convert_from<std::string>(input.segmentLength));
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
 * baseName: Subtitle
 * defaultResponse: {}
 */
};
// Gets subtitles in a specified format.
struct getSubtitleWithTicks {
public:
    using in_type                      = param::getSubtitleWithTicks;
    using out_type                     = model::return_type_getSubtitleWithTicks;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Videos/{}/{}/Subtitles/{}/{}/Stream.{}"sv,
            input.routeItemId,
            input.routeMediaSourceId,
            input.routeIndex,
            input.routeStartPositionTicks,
            input.routeFormat
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.itemId)
            p.set_param("itemId", convert_from<std::string>(input.itemId.value()));
        if(input.mediaSourceId)
            p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId.value()));
        if(input.index)
            p.set_param("index", convert_from<std::string>(input.index.value()));
        if(input.startPositionTicks)
            p.set_param("startPositionTicks", convert_from<std::string>(input.startPositionTicks.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.endPositionTicks)
            p.set_param("endPositionTicks", convert_from<std::string>(input.endPositionTicks.value()));
        if(input.copyTimestamps)
            p.set_param("copyTimestamps", convert_from<std::string>(input.copyTimestamps.value()));
        if(input.addVttTimeMap)
            p.set_param("addVttTimeMap", convert_from<std::string>(input.addVttTimeMap.value()));
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
 * baseName: Subtitle
 * defaultResponse: {}
 */
};
// Search remote subtitles.
struct searchRemoteSubtitles {
public:
    using in_type                      = param::searchRemoteSubtitles;
    using out_type                     = model::return_type_searchRemoteSubtitles;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/RemoteSearch/Subtitles/{}"sv,
            input.itemId,
            input.language
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.isPerfectMatch)
            p.set_param("isPerfectMatch", convert_from<std::string>(input.isPerfectMatch.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;OAIRemoteSubtitleInfo&gt;
 * returnFormat: 
 * returnBaseType: OAIRemoteSubtitleInfo
 * returnContainer: array
 * baseName: Subtitle
 * defaultResponse: {}
 */
};
// Upload an external subtitle file.
struct uploadSubtitle {
public:
    using in_type                      = param::uploadSubtitle;
    using out_type                     = model::return_type_uploadSubtitle;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Videos/{}/Subtitles"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
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
 * baseName: Subtitle
 * defaultResponse: 
 */
};
}
}
