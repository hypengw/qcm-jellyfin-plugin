#pragma once
/*
 * OAIUniversalAudioApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIMediaStreamProtocol.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getUniversalAudioStream = std::vector<std::byte>;
using return_type_headUniversalAudioStream = std::vector<std::byte>;
}

namespace api::param 
{
struct getUniversalAudioStream {
    std::string itemId; // The item id.
    std::optional<std::vector<std::string>> container; // Optional. The audio container.
    std::optional<std::string> mediaSourceId; // The media version id, if playing an alternate version.
    std::optional<std::string> deviceId; // The device id of the client requesting. Used to stop encoding processes when needed.
    std::optional<std::string> userId; // Optional. The user id.
    std::optional<std::string> audioCodec; // Optional. The audio codec to transcode to.
    std::optional<std::int32_t> maxAudioChannels; // Optional. The maximum number of audio channels.
    std::optional<std::int32_t> transcodingAudioChannels; // Optional. The number of how many audio channels to transcode to.
    std::optional<std::int32_t> maxStreamingBitrate; // Optional. The maximum streaming bitrate.
    std::optional<std::int32_t> audioBitRate; // Optional. Specify an audio bitrate to encode to, e.g. 128000. If omitted this will be left to encoder defaults.
    std::optional<std::int64_t> startTimeTicks; // Optional. Specify a starting offset, in ticks. 1 tick &#x3D; 10000 ms.
    std::optional<std::string> transcodingContainer; // Optional. The container to transcode to.
    std::optional<OAIMediaStreamProtocol> transcodingProtocol; // Optional. The transcoding protocol.
    std::optional<std::int32_t> maxAudioSampleRate; // Optional. The maximum audio sample rate.
    std::optional<std::int32_t> maxAudioBitDepth; // Optional. The maximum audio bit depth.
    std::optional<bool> enableRemoteMedia; // Optional. Whether to enable remote media.
    std::optional<bool> breakOnNonKeyFrames; // Optional. Whether to break on non key frames.
    std::optional<bool> enableRedirection; // Whether to enable redirection. Defaults to true.
};
struct headUniversalAudioStream {
    std::string itemId; // The item id.
    std::optional<std::vector<std::string>> container; // Optional. The audio container.
    std::optional<std::string> mediaSourceId; // The media version id, if playing an alternate version.
    std::optional<std::string> deviceId; // The device id of the client requesting. Used to stop encoding processes when needed.
    std::optional<std::string> userId; // Optional. The user id.
    std::optional<std::string> audioCodec; // Optional. The audio codec to transcode to.
    std::optional<std::int32_t> maxAudioChannels; // Optional. The maximum number of audio channels.
    std::optional<std::int32_t> transcodingAudioChannels; // Optional. The number of how many audio channels to transcode to.
    std::optional<std::int32_t> maxStreamingBitrate; // Optional. The maximum streaming bitrate.
    std::optional<std::int32_t> audioBitRate; // Optional. Specify an audio bitrate to encode to, e.g. 128000. If omitted this will be left to encoder defaults.
    std::optional<std::int64_t> startTimeTicks; // Optional. Specify a starting offset, in ticks. 1 tick &#x3D; 10000 ms.
    std::optional<std::string> transcodingContainer; // Optional. The container to transcode to.
    std::optional<OAIMediaStreamProtocol> transcodingProtocol; // Optional. The transcoding protocol.
    std::optional<std::int32_t> maxAudioSampleRate; // Optional. The maximum audio sample rate.
    std::optional<std::int32_t> maxAudioBitDepth; // Optional. The maximum audio bit depth.
    std::optional<bool> enableRemoteMedia; // Optional. Whether to enable remote media.
    std::optional<bool> breakOnNonKeyFrames; // Optional. Whether to break on non key frames.
    std::optional<bool> enableRedirection; // Whether to enable redirection. Defaults to true.
};
}

namespace api 
{
// Gets an audio stream.
struct getUniversalAudioStream {
public:
    using in_type                      = param::getUniversalAudioStream;
    using out_type                     = model::return_type_getUniversalAudioStream;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Audio/{}/universal"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.container)
            p.set_param("container", input.container.value());
        if(input.mediaSourceId)
            p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId.value()));
        if(input.deviceId)
            p.set_param("deviceId", convert_from<std::string>(input.deviceId.value()));
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.audioCodec)
            p.set_param("audioCodec", convert_from<std::string>(input.audioCodec.value()));
        if(input.maxAudioChannels)
            p.set_param("maxAudioChannels", convert_from<std::string>(input.maxAudioChannels.value()));
        if(input.transcodingAudioChannels)
            p.set_param("transcodingAudioChannels", convert_from<std::string>(input.transcodingAudioChannels.value()));
        if(input.maxStreamingBitrate)
            p.set_param("maxStreamingBitrate", convert_from<std::string>(input.maxStreamingBitrate.value()));
        if(input.audioBitRate)
            p.set_param("audioBitRate", convert_from<std::string>(input.audioBitRate.value()));
        if(input.startTimeTicks)
            p.set_param("startTimeTicks", convert_from<std::string>(input.startTimeTicks.value()));
        if(input.transcodingContainer)
            p.set_param("transcodingContainer", convert_from<std::string>(input.transcodingContainer.value()));
        if(input.transcodingProtocol)
            p.set_param("transcodingProtocol", convert_from<std::string>(input.transcodingProtocol.value()));
        if(input.maxAudioSampleRate)
            p.set_param("maxAudioSampleRate", convert_from<std::string>(input.maxAudioSampleRate.value()));
        if(input.maxAudioBitDepth)
            p.set_param("maxAudioBitDepth", convert_from<std::string>(input.maxAudioBitDepth.value()));
        if(input.enableRemoteMedia)
            p.set_param("enableRemoteMedia", convert_from<std::string>(input.enableRemoteMedia.value()));
        if(input.breakOnNonKeyFrames)
            p.set_param("breakOnNonKeyFrames", convert_from<std::string>(input.breakOnNonKeyFrames.value()));
        if(input.enableRedirection)
            p.set_param("enableRedirection", convert_from<std::string>(input.enableRedirection.value()));
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
 * baseName: UniversalAudio
 * defaultResponse: {}
 */
};
// Gets an audio stream.
struct headUniversalAudioStream {
public:
    using in_type                      = param::headUniversalAudioStream;
    using out_type                     = model::return_type_headUniversalAudioStream;
    constexpr static Operation  oper   = Operation::HEAD;
    auto path() const { 
        return fmt::format("/Audio/{}/universal"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.container)
            p.set_param("container", input.container.value());
        if(input.mediaSourceId)
            p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId.value()));
        if(input.deviceId)
            p.set_param("deviceId", convert_from<std::string>(input.deviceId.value()));
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.audioCodec)
            p.set_param("audioCodec", convert_from<std::string>(input.audioCodec.value()));
        if(input.maxAudioChannels)
            p.set_param("maxAudioChannels", convert_from<std::string>(input.maxAudioChannels.value()));
        if(input.transcodingAudioChannels)
            p.set_param("transcodingAudioChannels", convert_from<std::string>(input.transcodingAudioChannels.value()));
        if(input.maxStreamingBitrate)
            p.set_param("maxStreamingBitrate", convert_from<std::string>(input.maxStreamingBitrate.value()));
        if(input.audioBitRate)
            p.set_param("audioBitRate", convert_from<std::string>(input.audioBitRate.value()));
        if(input.startTimeTicks)
            p.set_param("startTimeTicks", convert_from<std::string>(input.startTimeTicks.value()));
        if(input.transcodingContainer)
            p.set_param("transcodingContainer", convert_from<std::string>(input.transcodingContainer.value()));
        if(input.transcodingProtocol)
            p.set_param("transcodingProtocol", convert_from<std::string>(input.transcodingProtocol.value()));
        if(input.maxAudioSampleRate)
            p.set_param("maxAudioSampleRate", convert_from<std::string>(input.maxAudioSampleRate.value()));
        if(input.maxAudioBitDepth)
            p.set_param("maxAudioBitDepth", convert_from<std::string>(input.maxAudioBitDepth.value()));
        if(input.enableRemoteMedia)
            p.set_param("enableRemoteMedia", convert_from<std::string>(input.enableRemoteMedia.value()));
        if(input.breakOnNonKeyFrames)
            p.set_param("breakOnNonKeyFrames", convert_from<std::string>(input.breakOnNonKeyFrames.value()));
        if(input.enableRedirection)
            p.set_param("enableRedirection", convert_from<std::string>(input.enableRedirection.value()));
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
 * baseName: UniversalAudio
 * defaultResponse: {}
 */
};
}
}
