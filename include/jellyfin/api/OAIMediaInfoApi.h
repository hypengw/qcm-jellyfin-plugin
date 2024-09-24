#pragma once
/*
 * OAIMediaInfoApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAILiveStreamResponse.h"
#include "jellyfin/model/OAIOpenLiveStreamDto.h"
#include "jellyfin/model/OAIPlaybackInfoDto.h"
#include "jellyfin/model/OAIPlaybackInfoResponse.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_closeLiveStream = std::nullptr_t;
using return_type_getBitrateTestBytes = std::vector<std::byte>;
using return_type_getPlaybackInfo = OAIPlaybackInfoResponse;
using return_type_getPostedPlaybackInfo = OAIPlaybackInfoResponse;
using return_type_openLiveStream = OAILiveStreamResponse;
}

namespace api::param 
{
struct closeLiveStream {
    std::string liveStreamId; // The livestream id.
};
struct getBitrateTestBytes {
    std::optional<std::int32_t> size; // The bitrate. Defaults to 102400.
};
struct getPlaybackInfo {
    std::string itemId; // The item id.
    std::optional<std::string> userId; // The user id.
};
struct getPostedPlaybackInfo {
    std::string itemId; // The item id.
    std::optional<std::string> userId; // The user id.
    std::optional<std::int32_t> maxStreamingBitrate; // The maximum streaming bitrate.
    std::optional<std::int64_t> startTimeTicks; // The start time in ticks.
    std::optional<std::int32_t> audioStreamIndex; // The audio stream index.
    std::optional<std::int32_t> subtitleStreamIndex; // The subtitle stream index.
    std::optional<std::int32_t> maxAudioChannels; // The maximum number of audio channels.
    std::optional<std::string> mediaSourceId; // The media source id.
    std::optional<std::string> liveStreamId; // The livestream id.
    std::optional<bool> autoOpenLiveStream; // Whether to auto open the livestream.
    std::optional<bool> enableDirectPlay; // Whether to enable direct play. Default: true.
    std::optional<bool> enableDirectStream; // Whether to enable direct stream. Default: true.
    std::optional<bool> enableTranscoding; // Whether to enable transcoding. Default: true.
    std::optional<bool> allowVideoStreamCopy; // Whether to allow to copy the video stream. Default: true.
    std::optional<bool> allowAudioStreamCopy; // Whether to allow to copy the audio stream. Default: true.
    std::optional<OAIPlaybackInfoDto> body; // The playback info.
};
struct openLiveStream {
    std::optional<std::string> openToken; // The open token.
    std::optional<std::string> userId; // The user id.
    std::optional<std::string> playSessionId; // The play session id.
    std::optional<std::int32_t> maxStreamingBitrate; // The maximum streaming bitrate.
    std::optional<std::int64_t> startTimeTicks; // The start time in ticks.
    std::optional<std::int32_t> audioStreamIndex; // The audio stream index.
    std::optional<std::int32_t> subtitleStreamIndex; // The subtitle stream index.
    std::optional<std::int32_t> maxAudioChannels; // The maximum number of audio channels.
    std::optional<std::string> itemId; // The item id.
    std::optional<bool> enableDirectPlay; // Whether to enable direct play. Default: true.
    std::optional<bool> enableDirectStream; // Whether to enable direct stream. Default: true.
    std::optional<OAIOpenLiveStreamDto> body; // The open live stream dto.
};
}

namespace api 
{
// Closes a media source.
struct closeLiveStream {
public:
    using in_type                      = param::closeLiveStream;
    using out_type                     = model::return_type_closeLiveStream;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/LiveStreams/Close"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("liveStreamId", convert_from<std::string>(input.liveStreamId));
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
 * baseName: MediaInfo
 * defaultResponse: 
 */
};
// Tests the network with a request with the size of the bitrate.
struct getBitrateTestBytes {
public:
    using in_type                      = param::getBitrateTestBytes;
    using out_type                     = model::return_type_getBitrateTestBytes;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Playback/BitrateTest"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.size)
            p.set_param("size", convert_from<std::string>(input.size.value()));
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
 * baseName: MediaInfo
 * defaultResponse: {}
 */
};
// Gets live playback media info for an item.
struct getPlaybackInfo {
public:
    using in_type                      = param::getPlaybackInfo;
    using out_type                     = model::return_type_getPlaybackInfo;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/PlaybackInfo"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIPlaybackInfoResponse
 * returnFormat: 
 * returnBaseType: OAIPlaybackInfoResponse
 * returnContainer: 
 * baseName: MediaInfo
 * defaultResponse: OAIPlaybackInfoResponse()
 */
};
// Gets live playback media info for an item.
struct getPostedPlaybackInfo {
public:
    using in_type                      = param::getPostedPlaybackInfo;
    using out_type                     = model::return_type_getPostedPlaybackInfo;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Items/{}/PlaybackInfo"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.maxStreamingBitrate)
            p.set_param("maxStreamingBitrate", convert_from<std::string>(input.maxStreamingBitrate.value()));
        if(input.startTimeTicks)
            p.set_param("startTimeTicks", convert_from<std::string>(input.startTimeTicks.value()));
        if(input.audioStreamIndex)
            p.set_param("audioStreamIndex", convert_from<std::string>(input.audioStreamIndex.value()));
        if(input.subtitleStreamIndex)
            p.set_param("subtitleStreamIndex", convert_from<std::string>(input.subtitleStreamIndex.value()));
        if(input.maxAudioChannels)
            p.set_param("maxAudioChannels", convert_from<std::string>(input.maxAudioChannels.value()));
        if(input.mediaSourceId)
            p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId.value()));
        if(input.liveStreamId)
            p.set_param("liveStreamId", convert_from<std::string>(input.liveStreamId.value()));
        if(input.autoOpenLiveStream)
            p.set_param("autoOpenLiveStream", convert_from<std::string>(input.autoOpenLiveStream.value()));
        if(input.enableDirectPlay)
            p.set_param("enableDirectPlay", convert_from<std::string>(input.enableDirectPlay.value()));
        if(input.enableDirectStream)
            p.set_param("enableDirectStream", convert_from<std::string>(input.enableDirectStream.value()));
        if(input.enableTranscoding)
            p.set_param("enableTranscoding", convert_from<std::string>(input.enableTranscoding.value()));
        if(input.allowVideoStreamCopy)
            p.set_param("allowVideoStreamCopy", convert_from<std::string>(input.allowVideoStreamCopy.value()));
        if(input.allowAudioStreamCopy)
            p.set_param("allowAudioStreamCopy", convert_from<std::string>(input.allowAudioStreamCopy.value()));
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
 * returnType: OAIPlaybackInfoResponse
 * returnFormat: 
 * returnBaseType: OAIPlaybackInfoResponse
 * returnContainer: 
 * baseName: MediaInfo
 * defaultResponse: OAIPlaybackInfoResponse()
 */
};
// Opens a media source.
struct openLiveStream {
public:
    using in_type                      = param::openLiveStream;
    using out_type                     = model::return_type_openLiveStream;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/LiveStreams/Open"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.openToken)
            p.set_param("openToken", convert_from<std::string>(input.openToken.value()));
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.playSessionId)
            p.set_param("playSessionId", convert_from<std::string>(input.playSessionId.value()));
        if(input.maxStreamingBitrate)
            p.set_param("maxStreamingBitrate", convert_from<std::string>(input.maxStreamingBitrate.value()));
        if(input.startTimeTicks)
            p.set_param("startTimeTicks", convert_from<std::string>(input.startTimeTicks.value()));
        if(input.audioStreamIndex)
            p.set_param("audioStreamIndex", convert_from<std::string>(input.audioStreamIndex.value()));
        if(input.subtitleStreamIndex)
            p.set_param("subtitleStreamIndex", convert_from<std::string>(input.subtitleStreamIndex.value()));
        if(input.maxAudioChannels)
            p.set_param("maxAudioChannels", convert_from<std::string>(input.maxAudioChannels.value()));
        if(input.itemId)
            p.set_param("itemId", convert_from<std::string>(input.itemId.value()));
        if(input.enableDirectPlay)
            p.set_param("enableDirectPlay", convert_from<std::string>(input.enableDirectPlay.value()));
        if(input.enableDirectStream)
            p.set_param("enableDirectStream", convert_from<std::string>(input.enableDirectStream.value()));
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
 * returnType: OAILiveStreamResponse
 * returnFormat: 
 * returnBaseType: OAILiveStreamResponse
 * returnContainer: 
 * baseName: MediaInfo
 * defaultResponse: OAILiveStreamResponse()
 */
};
}
}
