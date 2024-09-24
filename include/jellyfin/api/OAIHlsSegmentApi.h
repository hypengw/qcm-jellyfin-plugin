#pragma once
/*
 * OAIHlsSegmentApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getHlsAudioSegmentLegacyAac = std::vector<std::byte>;
using return_type_getHlsAudioSegmentLegacyMp3 = std::vector<std::byte>;
using return_type_getHlsPlaylistLegacy = std::vector<std::byte>;
using return_type_getHlsVideoSegmentLegacy = std::vector<std::byte>;
using return_type_stopEncodingProcess = std::nullptr_t;
}

namespace api::param 
{
struct getHlsAudioSegmentLegacyAac {
    std::string itemId; // The item id.
    std::string segmentId; // The segment id.
};
struct getHlsAudioSegmentLegacyMp3 {
    std::string itemId; // The item id.
    std::string segmentId; // The segment id.
};
struct getHlsPlaylistLegacy {
    std::string itemId; // The video id.
    std::string playlistId; // The playlist id.
};
struct getHlsVideoSegmentLegacy {
    std::string itemId; // The item id.
    std::string playlistId; // The playlist id.
    std::string segmentId; // The segment id.
    std::string segmentContainer; // The segment container.
};
struct stopEncodingProcess {
    std::string deviceId; // The device id of the client requesting. Used to stop encoding processes when needed.
    std::string playSessionId; // The play session id.
};
}

namespace api 
{
// Gets the specified audio segment for an audio item.
struct getHlsAudioSegmentLegacyAac {
public:
    using in_type                      = param::getHlsAudioSegmentLegacyAac;
    using out_type                     = model::return_type_getHlsAudioSegmentLegacyAac;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Audio/{}/hls/{}/stream.aac"sv,
            input.itemId,
            input.segmentId
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
 * baseName: HlsSegment
 * defaultResponse: {}
 */
};
// Gets the specified audio segment for an audio item.
struct getHlsAudioSegmentLegacyMp3 {
public:
    using in_type                      = param::getHlsAudioSegmentLegacyMp3;
    using out_type                     = model::return_type_getHlsAudioSegmentLegacyMp3;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Audio/{}/hls/{}/stream.mp3"sv,
            input.itemId,
            input.segmentId
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
 * baseName: HlsSegment
 * defaultResponse: {}
 */
};
// Gets a hls video playlist.
struct getHlsPlaylistLegacy {
public:
    using in_type                      = param::getHlsPlaylistLegacy;
    using out_type                     = model::return_type_getHlsPlaylistLegacy;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Videos/{}/hls/{}/stream.m3u8"sv,
            input.itemId,
            input.playlistId
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
 * baseName: HlsSegment
 * defaultResponse: {}
 */
};
// Gets a hls video segment.
struct getHlsVideoSegmentLegacy {
public:
    using in_type                      = param::getHlsVideoSegmentLegacy;
    using out_type                     = model::return_type_getHlsVideoSegmentLegacy;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Videos/{}/hls/{}/{}.{}"sv,
            input.itemId,
            input.playlistId,
            input.segmentId,
            input.segmentContainer
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
 * baseName: HlsSegment
 * defaultResponse: {}
 */
};
// Stops an active encoding.
struct stopEncodingProcess {
public:
    using in_type                      = param::stopEncodingProcess;
    using out_type                     = model::return_type_stopEncodingProcess;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return "/Videos/ActiveEncodings"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("deviceId", convert_from<std::string>(input.deviceId));
        p.set_param("playSessionId", convert_from<std::string>(input.playSessionId));
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
 * baseName: HlsSegment
 * defaultResponse: 
 */
};
}
}
