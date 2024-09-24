#pragma once
/*
 * OAIDynamicHlsApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIEncodingContext.h"
#include "jellyfin/model/OAISubtitleDeliveryMethod.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getHlsAudioSegment = std::vector<std::byte>;
using return_type_getHlsVideoSegment = std::vector<std::byte>;
using return_type_getLiveHlsStream = std::vector<std::byte>;
using return_type_getMasterHlsAudioPlaylist = std::vector<std::byte>;
using return_type_getMasterHlsVideoPlaylist = std::vector<std::byte>;
using return_type_getVariantHlsAudioPlaylist = std::vector<std::byte>;
using return_type_getVariantHlsVideoPlaylist = std::vector<std::byte>;
using return_type_headMasterHlsAudioPlaylist = std::vector<std::byte>;
using return_type_headMasterHlsVideoPlaylist = std::vector<std::byte>;
}

namespace api::param 
{
struct getHlsAudioSegment {
    std::string itemId; // The item id.
    std::string playlistId; // The playlist id.
    std::int32_t segmentId; // The segment id.
    std::string container; // The video container. Possible values are: ts, webm, asf, wmv, ogv, mp4, m4v, mkv, mpeg, mpg, avi, 3gp, wmv, wtv, m2ts, mov, iso, flv.
    std::int64_t runtimeTicks; // The position of the requested segment in ticks.
    std::int64_t actualSegmentLengthTicks; // The length of the requested segment in ticks.
    std::optional<bool> _static; // Optional. If true, the original file will be streamed statically without any encoding. Use either no url extension or the original file extension. true/false.
    std::optional<std::string> params; // The streaming parameters.
    std::optional<std::string> tag; // The tag.
    std::optional<std::string> deviceProfileId; // Optional. The dlna device profile id to utilize.
    std::optional<std::string> playSessionId; // The play session id.
    std::optional<std::string> segmentContainer; // The segment container.
    std::optional<std::int32_t> segmentLength; // The segment length.
    std::optional<std::int32_t> minSegments; // The minimum number of segments.
    std::optional<std::string> mediaSourceId; // The media version id, if playing an alternate version.
    std::optional<std::string> deviceId; // The device id of the client requesting. Used to stop encoding processes when needed.
    std::optional<std::string> audioCodec; // Optional. Specify a audio codec to encode to, e.g. mp3. If omitted the server will auto-select using the url&#39;s extension. Options: aac, mp3, vorbis, wma.
    std::optional<bool> enableAutoStreamCopy; // Whether or not to allow automatic stream copy if requested values match the original source. Defaults to true.
    std::optional<bool> allowVideoStreamCopy; // Whether or not to allow copying of the video stream url.
    std::optional<bool> allowAudioStreamCopy; // Whether or not to allow copying of the audio stream url.
    std::optional<bool> breakOnNonKeyFrames; // Optional. Whether to break on non key frames.
    std::optional<std::int32_t> audioSampleRate; // Optional. Specify a specific audio sample rate, e.g. 44100.
    std::optional<std::int32_t> maxAudioBitDepth; // Optional. The maximum audio bit depth.
    std::optional<std::int32_t> maxStreamingBitrate; // Optional. The maximum streaming bitrate.
    std::optional<std::int32_t> audioBitRate; // Optional. Specify an audio bitrate to encode to, e.g. 128000. If omitted this will be left to encoder defaults.
    std::optional<std::int32_t> audioChannels; // Optional. Specify a specific number of audio channels to encode to, e.g. 2.
    std::optional<std::int32_t> maxAudioChannels; // Optional. Specify a maximum number of audio channels to encode to, e.g. 2.
    std::optional<std::string> profile; // Optional. Specify a specific an encoder profile (varies by encoder), e.g. main, baseline, high.
    std::optional<std::string> level; // Optional. Specify a level for the encoder profile (varies by encoder), e.g. 3, 3.1.
    std::optional<float> framerate; // Optional. A specific video framerate to encode to, e.g. 23.976. Generally this should be omitted unless the device has specific requirements.
    std::optional<float> maxFramerate; // Optional. A specific maximum video framerate to encode to, e.g. 23.976. Generally this should be omitted unless the device has specific requirements.
    std::optional<bool> copyTimestamps; // Whether or not to copy timestamps when transcoding with an offset. Defaults to false.
    std::optional<std::int64_t> startTimeTicks; // Optional. Specify a starting offset, in ticks. 1 tick &#x3D; 10000 ms.
    std::optional<std::int32_t> width; // Optional. The fixed horizontal resolution of the encoded video.
    std::optional<std::int32_t> height; // Optional. The fixed vertical resolution of the encoded video.
    std::optional<std::int32_t> videoBitRate; // Optional. Specify a video bitrate to encode to, e.g. 500000. If omitted this will be left to encoder defaults.
    std::optional<std::int32_t> subtitleStreamIndex; // Optional. The index of the subtitle stream to use. If omitted no subtitles will be used.
    std::optional<OAISubtitleDeliveryMethod> subtitleMethod; // Optional. Specify the subtitle delivery method.
    std::optional<std::int32_t> maxRefFrames; // Optional.
    std::optional<std::int32_t> maxVideoBitDepth; // Optional. The maximum video bit depth.
    std::optional<bool> requireAvc; // Optional. Whether to require avc.
    std::optional<bool> deInterlace; // Optional. Whether to deinterlace the video.
    std::optional<bool> requireNonAnamorphic; // Optional. Whether to require a non anamorphic stream.
    std::optional<std::int32_t> transcodingMaxAudioChannels; // Optional. The maximum number of audio channels to transcode.
    std::optional<std::int32_t> cpuCoreLimit; // Optional. The limit of how many cpu cores to use.
    std::optional<std::string> liveStreamId; // The live stream id.
    std::optional<bool> enableMpegtsM2TsMode; // Optional. Whether to enable the MpegtsM2Ts mode.
    std::optional<std::string> videoCodec; // Optional. Specify a video codec to encode to, e.g. h264. If omitted the server will auto-select using the url&#39;s extension. Options: h265, h264, mpeg4, theora, vpx, wmv.
    std::optional<std::string> subtitleCodec; // Optional. Specify a subtitle codec to encode to.
    std::optional<std::string> transcodeReasons; // Optional. The transcoding reason.
    std::optional<std::int32_t> audioStreamIndex; // Optional. The index of the audio stream to use. If omitted the first audio stream will be used.
    std::optional<std::int32_t> videoStreamIndex; // Optional. The index of the video stream to use. If omitted the first video stream will be used.
    std::optional<OAIEncodingContext> context; // Optional. The MediaBrowser.Model.Dlna.EncodingContext.
    std::optional<std::map<std::string, std::string>> streamOptions; // Optional. The streaming options.
};
struct getHlsVideoSegment {
    std::string itemId; // The item id.
    std::string playlistId; // The playlist id.
    std::int32_t segmentId; // The segment id.
    std::string container; // The video container. Possible values are: ts, webm, asf, wmv, ogv, mp4, m4v, mkv, mpeg, mpg, avi, 3gp, wmv, wtv, m2ts, mov, iso, flv.
    std::int64_t runtimeTicks; // The position of the requested segment in ticks.
    std::int64_t actualSegmentLengthTicks; // The length of the requested segment in ticks.
    std::optional<bool> _static; // Optional. If true, the original file will be streamed statically without any encoding. Use either no url extension or the original file extension. true/false.
    std::optional<std::string> params; // The streaming parameters.
    std::optional<std::string> tag; // The tag.
    std::optional<std::string> deviceProfileId; // Optional. The dlna device profile id to utilize.
    std::optional<std::string> playSessionId; // The play session id.
    std::optional<std::string> segmentContainer; // The segment container.
    std::optional<std::int32_t> segmentLength; // The desired segment length.
    std::optional<std::int32_t> minSegments; // The minimum number of segments.
    std::optional<std::string> mediaSourceId; // The media version id, if playing an alternate version.
    std::optional<std::string> deviceId; // The device id of the client requesting. Used to stop encoding processes when needed.
    std::optional<std::string> audioCodec; // Optional. Specify a audio codec to encode to, e.g. mp3. If omitted the server will auto-select using the url&#39;s extension. Options: aac, mp3, vorbis, wma.
    std::optional<bool> enableAutoStreamCopy; // Whether or not to allow automatic stream copy if requested values match the original source. Defaults to true.
    std::optional<bool> allowVideoStreamCopy; // Whether or not to allow copying of the video stream url.
    std::optional<bool> allowAudioStreamCopy; // Whether or not to allow copying of the audio stream url.
    std::optional<bool> breakOnNonKeyFrames; // Optional. Whether to break on non key frames.
    std::optional<std::int32_t> audioSampleRate; // Optional. Specify a specific audio sample rate, e.g. 44100.
    std::optional<std::int32_t> maxAudioBitDepth; // Optional. The maximum audio bit depth.
    std::optional<std::int32_t> audioBitRate; // Optional. Specify an audio bitrate to encode to, e.g. 128000. If omitted this will be left to encoder defaults.
    std::optional<std::int32_t> audioChannels; // Optional. Specify a specific number of audio channels to encode to, e.g. 2.
    std::optional<std::int32_t> maxAudioChannels; // Optional. Specify a maximum number of audio channels to encode to, e.g. 2.
    std::optional<std::string> profile; // Optional. Specify a specific an encoder profile (varies by encoder), e.g. main, baseline, high.
    std::optional<std::string> level; // Optional. Specify a level for the encoder profile (varies by encoder), e.g. 3, 3.1.
    std::optional<float> framerate; // Optional. A specific video framerate to encode to, e.g. 23.976. Generally this should be omitted unless the device has specific requirements.
    std::optional<float> maxFramerate; // Optional. A specific maximum video framerate to encode to, e.g. 23.976. Generally this should be omitted unless the device has specific requirements.
    std::optional<bool> copyTimestamps; // Whether or not to copy timestamps when transcoding with an offset. Defaults to false.
    std::optional<std::int64_t> startTimeTicks; // Optional. Specify a starting offset, in ticks. 1 tick &#x3D; 10000 ms.
    std::optional<std::int32_t> width; // Optional. The fixed horizontal resolution of the encoded video.
    std::optional<std::int32_t> height; // Optional. The fixed vertical resolution of the encoded video.
    std::optional<std::int32_t> maxWidth; // Optional. The maximum horizontal resolution of the encoded video.
    std::optional<std::int32_t> maxHeight; // Optional. The maximum vertical resolution of the encoded video.
    std::optional<std::int32_t> videoBitRate; // Optional. Specify a video bitrate to encode to, e.g. 500000. If omitted this will be left to encoder defaults.
    std::optional<std::int32_t> subtitleStreamIndex; // Optional. The index of the subtitle stream to use. If omitted no subtitles will be used.
    std::optional<OAISubtitleDeliveryMethod> subtitleMethod; // Optional. Specify the subtitle delivery method.
    std::optional<std::int32_t> maxRefFrames; // Optional.
    std::optional<std::int32_t> maxVideoBitDepth; // Optional. The maximum video bit depth.
    std::optional<bool> requireAvc; // Optional. Whether to require avc.
    std::optional<bool> deInterlace; // Optional. Whether to deinterlace the video.
    std::optional<bool> requireNonAnamorphic; // Optional. Whether to require a non anamorphic stream.
    std::optional<std::int32_t> transcodingMaxAudioChannels; // Optional. The maximum number of audio channels to transcode.
    std::optional<std::int32_t> cpuCoreLimit; // Optional. The limit of how many cpu cores to use.
    std::optional<std::string> liveStreamId; // The live stream id.
    std::optional<bool> enableMpegtsM2TsMode; // Optional. Whether to enable the MpegtsM2Ts mode.
    std::optional<std::string> videoCodec; // Optional. Specify a video codec to encode to, e.g. h264. If omitted the server will auto-select using the url&#39;s extension. Options: h265, h264, mpeg4, theora, vp8, vp9, vpx (deprecated), wmv.
    std::optional<std::string> subtitleCodec; // Optional. Specify a subtitle codec to encode to.
    std::optional<std::string> transcodeReasons; // Optional. The transcoding reason.
    std::optional<std::int32_t> audioStreamIndex; // Optional. The index of the audio stream to use. If omitted the first audio stream will be used.
    std::optional<std::int32_t> videoStreamIndex; // Optional. The index of the video stream to use. If omitted the first video stream will be used.
    std::optional<OAIEncodingContext> context; // Optional. The MediaBrowser.Model.Dlna.EncodingContext.
    std::optional<std::map<std::string, std::string>> streamOptions; // Optional. The streaming options.
};
struct getLiveHlsStream {
    std::string itemId; // The item id.
    std::optional<std::string> container; // The audio container.
    std::optional<bool> _static; // Optional. If true, the original file will be streamed statically without any encoding. Use either no url extension or the original file extension. true/false.
    std::optional<std::string> params; // The streaming parameters.
    std::optional<std::string> tag; // The tag.
    std::optional<std::string> deviceProfileId; // Optional. The dlna device profile id to utilize.
    std::optional<std::string> playSessionId; // The play session id.
    std::optional<std::string> segmentContainer; // The segment container.
    std::optional<std::int32_t> segmentLength; // The segment length.
    std::optional<std::int32_t> minSegments; // The minimum number of segments.
    std::optional<std::string> mediaSourceId; // The media version id, if playing an alternate version.
    std::optional<std::string> deviceId; // The device id of the client requesting. Used to stop encoding processes when needed.
    std::optional<std::string> audioCodec; // Optional. Specify a audio codec to encode to, e.g. mp3. If omitted the server will auto-select using the url&#39;s extension. Options: aac, mp3, vorbis, wma.
    std::optional<bool> enableAutoStreamCopy; // Whether or not to allow automatic stream copy if requested values match the original source. Defaults to true.
    std::optional<bool> allowVideoStreamCopy; // Whether or not to allow copying of the video stream url.
    std::optional<bool> allowAudioStreamCopy; // Whether or not to allow copying of the audio stream url.
    std::optional<bool> breakOnNonKeyFrames; // Optional. Whether to break on non key frames.
    std::optional<std::int32_t> audioSampleRate; // Optional. Specify a specific audio sample rate, e.g. 44100.
    std::optional<std::int32_t> maxAudioBitDepth; // Optional. The maximum audio bit depth.
    std::optional<std::int32_t> audioBitRate; // Optional. Specify an audio bitrate to encode to, e.g. 128000. If omitted this will be left to encoder defaults.
    std::optional<std::int32_t> audioChannels; // Optional. Specify a specific number of audio channels to encode to, e.g. 2.
    std::optional<std::int32_t> maxAudioChannels; // Optional. Specify a maximum number of audio channels to encode to, e.g. 2.
    std::optional<std::string> profile; // Optional. Specify a specific an encoder profile (varies by encoder), e.g. main, baseline, high.
    std::optional<std::string> level; // Optional. Specify a level for the encoder profile (varies by encoder), e.g. 3, 3.1.
    std::optional<float> framerate; // Optional. A specific video framerate to encode to, e.g. 23.976. Generally this should be omitted unless the device has specific requirements.
    std::optional<float> maxFramerate; // Optional. A specific maximum video framerate to encode to, e.g. 23.976. Generally this should be omitted unless the device has specific requirements.
    std::optional<bool> copyTimestamps; // Whether or not to copy timestamps when transcoding with an offset. Defaults to false.
    std::optional<std::int64_t> startTimeTicks; // Optional. Specify a starting offset, in ticks. 1 tick &#x3D; 10000 ms.
    std::optional<std::int32_t> width; // Optional. The fixed horizontal resolution of the encoded video.
    std::optional<std::int32_t> height; // Optional. The fixed vertical resolution of the encoded video.
    std::optional<std::int32_t> videoBitRate; // Optional. Specify a video bitrate to encode to, e.g. 500000. If omitted this will be left to encoder defaults.
    std::optional<std::int32_t> subtitleStreamIndex; // Optional. The index of the subtitle stream to use. If omitted no subtitles will be used.
    std::optional<OAISubtitleDeliveryMethod> subtitleMethod; // Optional. Specify the subtitle delivery method.
    std::optional<std::int32_t> maxRefFrames; // Optional.
    std::optional<std::int32_t> maxVideoBitDepth; // Optional. The maximum video bit depth.
    std::optional<bool> requireAvc; // Optional. Whether to require avc.
    std::optional<bool> deInterlace; // Optional. Whether to deinterlace the video.
    std::optional<bool> requireNonAnamorphic; // Optional. Whether to require a non anamorphic stream.
    std::optional<std::int32_t> transcodingMaxAudioChannels; // Optional. The maximum number of audio channels to transcode.
    std::optional<std::int32_t> cpuCoreLimit; // Optional. The limit of how many cpu cores to use.
    std::optional<std::string> liveStreamId; // The live stream id.
    std::optional<bool> enableMpegtsM2TsMode; // Optional. Whether to enable the MpegtsM2Ts mode.
    std::optional<std::string> videoCodec; // Optional. Specify a video codec to encode to, e.g. h264. If omitted the server will auto-select using the url&#39;s extension. Options: h265, h264, mpeg4, theora, vp8, vp9, vpx (deprecated), wmv.
    std::optional<std::string> subtitleCodec; // Optional. Specify a subtitle codec to encode to.
    std::optional<std::string> transcodeReasons; // Optional. The transcoding reason.
    std::optional<std::int32_t> audioStreamIndex; // Optional. The index of the audio stream to use. If omitted the first audio stream will be used.
    std::optional<std::int32_t> videoStreamIndex; // Optional. The index of the video stream to use. If omitted the first video stream will be used.
    std::optional<OAIEncodingContext> context; // Optional. The MediaBrowser.Model.Dlna.EncodingContext.
    std::optional<std::map<std::string, std::string>> streamOptions; // Optional. The streaming options.
    std::optional<std::int32_t> maxWidth; // Optional. The max width.
    std::optional<std::int32_t> maxHeight; // Optional. The max height.
    std::optional<bool> enableSubtitlesInManifest; // Optional. Whether to enable subtitles in the manifest.
};
struct getMasterHlsAudioPlaylist {
    std::string itemId; // The item id.
    std::string mediaSourceId; // The media version id, if playing an alternate version.
    std::optional<bool> _static; // Optional. If true, the original file will be streamed statically without any encoding. Use either no url extension or the original file extension. true/false.
    std::optional<std::string> params; // The streaming parameters.
    std::optional<std::string> tag; // The tag.
    std::optional<std::string> deviceProfileId; // Optional. The dlna device profile id to utilize.
    std::optional<std::string> playSessionId; // The play session id.
    std::optional<std::string> segmentContainer; // The segment container.
    std::optional<std::int32_t> segmentLength; // The segment length.
    std::optional<std::int32_t> minSegments; // The minimum number of segments.
    std::optional<std::string> deviceId; // The device id of the client requesting. Used to stop encoding processes when needed.
    std::optional<std::string> audioCodec; // Optional. Specify a audio codec to encode to, e.g. mp3. If omitted the server will auto-select using the url&#39;s extension. Options: aac, mp3, vorbis, wma.
    std::optional<bool> enableAutoStreamCopy; // Whether or not to allow automatic stream copy if requested values match the original source. Defaults to true.
    std::optional<bool> allowVideoStreamCopy; // Whether or not to allow copying of the video stream url.
    std::optional<bool> allowAudioStreamCopy; // Whether or not to allow copying of the audio stream url.
    std::optional<bool> breakOnNonKeyFrames; // Optional. Whether to break on non key frames.
    std::optional<std::int32_t> audioSampleRate; // Optional. Specify a specific audio sample rate, e.g. 44100.
    std::optional<std::int32_t> maxAudioBitDepth; // Optional. The maximum audio bit depth.
    std::optional<std::int32_t> maxStreamingBitrate; // Optional. The maximum streaming bitrate.
    std::optional<std::int32_t> audioBitRate; // Optional. Specify an audio bitrate to encode to, e.g. 128000. If omitted this will be left to encoder defaults.
    std::optional<std::int32_t> audioChannels; // Optional. Specify a specific number of audio channels to encode to, e.g. 2.
    std::optional<std::int32_t> maxAudioChannels; // Optional. Specify a maximum number of audio channels to encode to, e.g. 2.
    std::optional<std::string> profile; // Optional. Specify a specific an encoder profile (varies by encoder), e.g. main, baseline, high.
    std::optional<std::string> level; // Optional. Specify a level for the encoder profile (varies by encoder), e.g. 3, 3.1.
    std::optional<float> framerate; // Optional. A specific video framerate to encode to, e.g. 23.976. Generally this should be omitted unless the device has specific requirements.
    std::optional<float> maxFramerate; // Optional. A specific maximum video framerate to encode to, e.g. 23.976. Generally this should be omitted unless the device has specific requirements.
    std::optional<bool> copyTimestamps; // Whether or not to copy timestamps when transcoding with an offset. Defaults to false.
    std::optional<std::int64_t> startTimeTicks; // Optional. Specify a starting offset, in ticks. 1 tick &#x3D; 10000 ms.
    std::optional<std::int32_t> width; // Optional. The fixed horizontal resolution of the encoded video.
    std::optional<std::int32_t> height; // Optional. The fixed vertical resolution of the encoded video.
    std::optional<std::int32_t> videoBitRate; // Optional. Specify a video bitrate to encode to, e.g. 500000. If omitted this will be left to encoder defaults.
    std::optional<std::int32_t> subtitleStreamIndex; // Optional. The index of the subtitle stream to use. If omitted no subtitles will be used.
    std::optional<OAISubtitleDeliveryMethod> subtitleMethod; // Optional. Specify the subtitle delivery method.
    std::optional<std::int32_t> maxRefFrames; // Optional.
    std::optional<std::int32_t> maxVideoBitDepth; // Optional. The maximum video bit depth.
    std::optional<bool> requireAvc; // Optional. Whether to require avc.
    std::optional<bool> deInterlace; // Optional. Whether to deinterlace the video.
    std::optional<bool> requireNonAnamorphic; // Optional. Whether to require a non anamorphic stream.
    std::optional<std::int32_t> transcodingMaxAudioChannels; // Optional. The maximum number of audio channels to transcode.
    std::optional<std::int32_t> cpuCoreLimit; // Optional. The limit of how many cpu cores to use.
    std::optional<std::string> liveStreamId; // The live stream id.
    std::optional<bool> enableMpegtsM2TsMode; // Optional. Whether to enable the MpegtsM2Ts mode.
    std::optional<std::string> videoCodec; // Optional. Specify a video codec to encode to, e.g. h264. If omitted the server will auto-select using the url&#39;s extension. Options: h265, h264, mpeg4, theora, vp8, vp9, vpx (deprecated), wmv.
    std::optional<std::string> subtitleCodec; // Optional. Specify a subtitle codec to encode to.
    std::optional<std::string> transcodeReasons; // Optional. The transcoding reason.
    std::optional<std::int32_t> audioStreamIndex; // Optional. The index of the audio stream to use. If omitted the first audio stream will be used.
    std::optional<std::int32_t> videoStreamIndex; // Optional. The index of the video stream to use. If omitted the first video stream will be used.
    std::optional<OAIEncodingContext> context; // Optional. The MediaBrowser.Model.Dlna.EncodingContext.
    std::optional<std::map<std::string, std::string>> streamOptions; // Optional. The streaming options.
    std::optional<bool> enableAdaptiveBitrateStreaming; // Enable adaptive bitrate streaming.
};
struct getMasterHlsVideoPlaylist {
    std::string itemId; // The item id.
    std::string mediaSourceId; // The media version id, if playing an alternate version.
    std::optional<bool> _static; // Optional. If true, the original file will be streamed statically without any encoding. Use either no url extension or the original file extension. true/false.
    std::optional<std::string> params; // The streaming parameters.
    std::optional<std::string> tag; // The tag.
    std::optional<std::string> deviceProfileId; // Optional. The dlna device profile id to utilize.
    std::optional<std::string> playSessionId; // The play session id.
    std::optional<std::string> segmentContainer; // The segment container.
    std::optional<std::int32_t> segmentLength; // The segment length.
    std::optional<std::int32_t> minSegments; // The minimum number of segments.
    std::optional<std::string> deviceId; // The device id of the client requesting. Used to stop encoding processes when needed.
    std::optional<std::string> audioCodec; // Optional. Specify a audio codec to encode to, e.g. mp3. If omitted the server will auto-select using the url&#39;s extension. Options: aac, mp3, vorbis, wma.
    std::optional<bool> enableAutoStreamCopy; // Whether or not to allow automatic stream copy if requested values match the original source. Defaults to true.
    std::optional<bool> allowVideoStreamCopy; // Whether or not to allow copying of the video stream url.
    std::optional<bool> allowAudioStreamCopy; // Whether or not to allow copying of the audio stream url.
    std::optional<bool> breakOnNonKeyFrames; // Optional. Whether to break on non key frames.
    std::optional<std::int32_t> audioSampleRate; // Optional. Specify a specific audio sample rate, e.g. 44100.
    std::optional<std::int32_t> maxAudioBitDepth; // Optional. The maximum audio bit depth.
    std::optional<std::int32_t> audioBitRate; // Optional. Specify an audio bitrate to encode to, e.g. 128000. If omitted this will be left to encoder defaults.
    std::optional<std::int32_t> audioChannels; // Optional. Specify a specific number of audio channels to encode to, e.g. 2.
    std::optional<std::int32_t> maxAudioChannels; // Optional. Specify a maximum number of audio channels to encode to, e.g. 2.
    std::optional<std::string> profile; // Optional. Specify a specific an encoder profile (varies by encoder), e.g. main, baseline, high.
    std::optional<std::string> level; // Optional. Specify a level for the encoder profile (varies by encoder), e.g. 3, 3.1.
    std::optional<float> framerate; // Optional. A specific video framerate to encode to, e.g. 23.976. Generally this should be omitted unless the device has specific requirements.
    std::optional<float> maxFramerate; // Optional. A specific maximum video framerate to encode to, e.g. 23.976. Generally this should be omitted unless the device has specific requirements.
    std::optional<bool> copyTimestamps; // Whether or not to copy timestamps when transcoding with an offset. Defaults to false.
    std::optional<std::int64_t> startTimeTicks; // Optional. Specify a starting offset, in ticks. 1 tick &#x3D; 10000 ms.
    std::optional<std::int32_t> width; // Optional. The fixed horizontal resolution of the encoded video.
    std::optional<std::int32_t> height; // Optional. The fixed vertical resolution of the encoded video.
    std::optional<std::int32_t> maxWidth; // Optional. The maximum horizontal resolution of the encoded video.
    std::optional<std::int32_t> maxHeight; // Optional. The maximum vertical resolution of the encoded video.
    std::optional<std::int32_t> videoBitRate; // Optional. Specify a video bitrate to encode to, e.g. 500000. If omitted this will be left to encoder defaults.
    std::optional<std::int32_t> subtitleStreamIndex; // Optional. The index of the subtitle stream to use. If omitted no subtitles will be used.
    std::optional<OAISubtitleDeliveryMethod> subtitleMethod; // Optional. Specify the subtitle delivery method.
    std::optional<std::int32_t> maxRefFrames; // Optional.
    std::optional<std::int32_t> maxVideoBitDepth; // Optional. The maximum video bit depth.
    std::optional<bool> requireAvc; // Optional. Whether to require avc.
    std::optional<bool> deInterlace; // Optional. Whether to deinterlace the video.
    std::optional<bool> requireNonAnamorphic; // Optional. Whether to require a non anamorphic stream.
    std::optional<std::int32_t> transcodingMaxAudioChannels; // Optional. The maximum number of audio channels to transcode.
    std::optional<std::int32_t> cpuCoreLimit; // Optional. The limit of how many cpu cores to use.
    std::optional<std::string> liveStreamId; // The live stream id.
    std::optional<bool> enableMpegtsM2TsMode; // Optional. Whether to enable the MpegtsM2Ts mode.
    std::optional<std::string> videoCodec; // Optional. Specify a video codec to encode to, e.g. h264. If omitted the server will auto-select using the url&#39;s extension. Options: h265, h264, mpeg4, theora, vp8, vp9, vpx (deprecated), wmv.
    std::optional<std::string> subtitleCodec; // Optional. Specify a subtitle codec to encode to.
    std::optional<std::string> transcodeReasons; // Optional. The transcoding reason.
    std::optional<std::int32_t> audioStreamIndex; // Optional. The index of the audio stream to use. If omitted the first audio stream will be used.
    std::optional<std::int32_t> videoStreamIndex; // Optional. The index of the video stream to use. If omitted the first video stream will be used.
    std::optional<OAIEncodingContext> context; // Optional. The MediaBrowser.Model.Dlna.EncodingContext.
    std::optional<std::map<std::string, std::string>> streamOptions; // Optional. The streaming options.
    std::optional<bool> enableAdaptiveBitrateStreaming; // Enable adaptive bitrate streaming.
    std::optional<bool> enableTrickplay; // Enable trickplay image playlists being added to master playlist.
};
struct getVariantHlsAudioPlaylist {
    std::string itemId; // The item id.
    std::optional<bool> _static; // Optional. If true, the original file will be streamed statically without any encoding. Use either no url extension or the original file extension. true/false.
    std::optional<std::string> params; // The streaming parameters.
    std::optional<std::string> tag; // The tag.
    std::optional<std::string> deviceProfileId; // Optional. The dlna device profile id to utilize.
    std::optional<std::string> playSessionId; // The play session id.
    std::optional<std::string> segmentContainer; // The segment container.
    std::optional<std::int32_t> segmentLength; // The segment length.
    std::optional<std::int32_t> minSegments; // The minimum number of segments.
    std::optional<std::string> mediaSourceId; // The media version id, if playing an alternate version.
    std::optional<std::string> deviceId; // The device id of the client requesting. Used to stop encoding processes when needed.
    std::optional<std::string> audioCodec; // Optional. Specify a audio codec to encode to, e.g. mp3. If omitted the server will auto-select using the url&#39;s extension. Options: aac, mp3, vorbis, wma.
    std::optional<bool> enableAutoStreamCopy; // Whether or not to allow automatic stream copy if requested values match the original source. Defaults to true.
    std::optional<bool> allowVideoStreamCopy; // Whether or not to allow copying of the video stream url.
    std::optional<bool> allowAudioStreamCopy; // Whether or not to allow copying of the audio stream url.
    std::optional<bool> breakOnNonKeyFrames; // Optional. Whether to break on non key frames.
    std::optional<std::int32_t> audioSampleRate; // Optional. Specify a specific audio sample rate, e.g. 44100.
    std::optional<std::int32_t> maxAudioBitDepth; // Optional. The maximum audio bit depth.
    std::optional<std::int32_t> maxStreamingBitrate; // Optional. The maximum streaming bitrate.
    std::optional<std::int32_t> audioBitRate; // Optional. Specify an audio bitrate to encode to, e.g. 128000. If omitted this will be left to encoder defaults.
    std::optional<std::int32_t> audioChannels; // Optional. Specify a specific number of audio channels to encode to, e.g. 2.
    std::optional<std::int32_t> maxAudioChannels; // Optional. Specify a maximum number of audio channels to encode to, e.g. 2.
    std::optional<std::string> profile; // Optional. Specify a specific an encoder profile (varies by encoder), e.g. main, baseline, high.
    std::optional<std::string> level; // Optional. Specify a level for the encoder profile (varies by encoder), e.g. 3, 3.1.
    std::optional<float> framerate; // Optional. A specific video framerate to encode to, e.g. 23.976. Generally this should be omitted unless the device has specific requirements.
    std::optional<float> maxFramerate; // Optional. A specific maximum video framerate to encode to, e.g. 23.976. Generally this should be omitted unless the device has specific requirements.
    std::optional<bool> copyTimestamps; // Whether or not to copy timestamps when transcoding with an offset. Defaults to false.
    std::optional<std::int64_t> startTimeTicks; // Optional. Specify a starting offset, in ticks. 1 tick &#x3D; 10000 ms.
    std::optional<std::int32_t> width; // Optional. The fixed horizontal resolution of the encoded video.
    std::optional<std::int32_t> height; // Optional. The fixed vertical resolution of the encoded video.
    std::optional<std::int32_t> videoBitRate; // Optional. Specify a video bitrate to encode to, e.g. 500000. If omitted this will be left to encoder defaults.
    std::optional<std::int32_t> subtitleStreamIndex; // Optional. The index of the subtitle stream to use. If omitted no subtitles will be used.
    std::optional<OAISubtitleDeliveryMethod> subtitleMethod; // Optional. Specify the subtitle delivery method.
    std::optional<std::int32_t> maxRefFrames; // Optional.
    std::optional<std::int32_t> maxVideoBitDepth; // Optional. The maximum video bit depth.
    std::optional<bool> requireAvc; // Optional. Whether to require avc.
    std::optional<bool> deInterlace; // Optional. Whether to deinterlace the video.
    std::optional<bool> requireNonAnamorphic; // Optional. Whether to require a non anamorphic stream.
    std::optional<std::int32_t> transcodingMaxAudioChannels; // Optional. The maximum number of audio channels to transcode.
    std::optional<std::int32_t> cpuCoreLimit; // Optional. The limit of how many cpu cores to use.
    std::optional<std::string> liveStreamId; // The live stream id.
    std::optional<bool> enableMpegtsM2TsMode; // Optional. Whether to enable the MpegtsM2Ts mode.
    std::optional<std::string> videoCodec; // Optional. Specify a video codec to encode to, e.g. h264. If omitted the server will auto-select using the url&#39;s extension. Options: h265, h264, mpeg4, theora, vpx, wmv.
    std::optional<std::string> subtitleCodec; // Optional. Specify a subtitle codec to encode to.
    std::optional<std::string> transcodeReasons; // Optional. The transcoding reason.
    std::optional<std::int32_t> audioStreamIndex; // Optional. The index of the audio stream to use. If omitted the first audio stream will be used.
    std::optional<std::int32_t> videoStreamIndex; // Optional. The index of the video stream to use. If omitted the first video stream will be used.
    std::optional<OAIEncodingContext> context; // Optional. The MediaBrowser.Model.Dlna.EncodingContext.
    std::optional<std::map<std::string, std::string>> streamOptions; // Optional. The streaming options.
};
struct getVariantHlsVideoPlaylist {
    std::string itemId; // The item id.
    std::optional<bool> _static; // Optional. If true, the original file will be streamed statically without any encoding. Use either no url extension or the original file extension. true/false.
    std::optional<std::string> params; // The streaming parameters.
    std::optional<std::string> tag; // The tag.
    std::optional<std::string> deviceProfileId; // Optional. The dlna device profile id to utilize.
    std::optional<std::string> playSessionId; // The play session id.
    std::optional<std::string> segmentContainer; // The segment container.
    std::optional<std::int32_t> segmentLength; // The segment length.
    std::optional<std::int32_t> minSegments; // The minimum number of segments.
    std::optional<std::string> mediaSourceId; // The media version id, if playing an alternate version.
    std::optional<std::string> deviceId; // The device id of the client requesting. Used to stop encoding processes when needed.
    std::optional<std::string> audioCodec; // Optional. Specify a audio codec to encode to, e.g. mp3. If omitted the server will auto-select using the url&#39;s extension. Options: aac, mp3, vorbis, wma.
    std::optional<bool> enableAutoStreamCopy; // Whether or not to allow automatic stream copy if requested values match the original source. Defaults to true.
    std::optional<bool> allowVideoStreamCopy; // Whether or not to allow copying of the video stream url.
    std::optional<bool> allowAudioStreamCopy; // Whether or not to allow copying of the audio stream url.
    std::optional<bool> breakOnNonKeyFrames; // Optional. Whether to break on non key frames.
    std::optional<std::int32_t> audioSampleRate; // Optional. Specify a specific audio sample rate, e.g. 44100.
    std::optional<std::int32_t> maxAudioBitDepth; // Optional. The maximum audio bit depth.
    std::optional<std::int32_t> audioBitRate; // Optional. Specify an audio bitrate to encode to, e.g. 128000. If omitted this will be left to encoder defaults.
    std::optional<std::int32_t> audioChannels; // Optional. Specify a specific number of audio channels to encode to, e.g. 2.
    std::optional<std::int32_t> maxAudioChannels; // Optional. Specify a maximum number of audio channels to encode to, e.g. 2.
    std::optional<std::string> profile; // Optional. Specify a specific an encoder profile (varies by encoder), e.g. main, baseline, high.
    std::optional<std::string> level; // Optional. Specify a level for the encoder profile (varies by encoder), e.g. 3, 3.1.
    std::optional<float> framerate; // Optional. A specific video framerate to encode to, e.g. 23.976. Generally this should be omitted unless the device has specific requirements.
    std::optional<float> maxFramerate; // Optional. A specific maximum video framerate to encode to, e.g. 23.976. Generally this should be omitted unless the device has specific requirements.
    std::optional<bool> copyTimestamps; // Whether or not to copy timestamps when transcoding with an offset. Defaults to false.
    std::optional<std::int64_t> startTimeTicks; // Optional. Specify a starting offset, in ticks. 1 tick &#x3D; 10000 ms.
    std::optional<std::int32_t> width; // Optional. The fixed horizontal resolution of the encoded video.
    std::optional<std::int32_t> height; // Optional. The fixed vertical resolution of the encoded video.
    std::optional<std::int32_t> maxWidth; // Optional. The maximum horizontal resolution of the encoded video.
    std::optional<std::int32_t> maxHeight; // Optional. The maximum vertical resolution of the encoded video.
    std::optional<std::int32_t> videoBitRate; // Optional. Specify a video bitrate to encode to, e.g. 500000. If omitted this will be left to encoder defaults.
    std::optional<std::int32_t> subtitleStreamIndex; // Optional. The index of the subtitle stream to use. If omitted no subtitles will be used.
    std::optional<OAISubtitleDeliveryMethod> subtitleMethod; // Optional. Specify the subtitle delivery method.
    std::optional<std::int32_t> maxRefFrames; // Optional.
    std::optional<std::int32_t> maxVideoBitDepth; // Optional. The maximum video bit depth.
    std::optional<bool> requireAvc; // Optional. Whether to require avc.
    std::optional<bool> deInterlace; // Optional. Whether to deinterlace the video.
    std::optional<bool> requireNonAnamorphic; // Optional. Whether to require a non anamorphic stream.
    std::optional<std::int32_t> transcodingMaxAudioChannels; // Optional. The maximum number of audio channels to transcode.
    std::optional<std::int32_t> cpuCoreLimit; // Optional. The limit of how many cpu cores to use.
    std::optional<std::string> liveStreamId; // The live stream id.
    std::optional<bool> enableMpegtsM2TsMode; // Optional. Whether to enable the MpegtsM2Ts mode.
    std::optional<std::string> videoCodec; // Optional. Specify a video codec to encode to, e.g. h264. If omitted the server will auto-select using the url&#39;s extension. Options: h265, h264, mpeg4, theora, vp8, vp9, vpx (deprecated), wmv.
    std::optional<std::string> subtitleCodec; // Optional. Specify a subtitle codec to encode to.
    std::optional<std::string> transcodeReasons; // Optional. The transcoding reason.
    std::optional<std::int32_t> audioStreamIndex; // Optional. The index of the audio stream to use. If omitted the first audio stream will be used.
    std::optional<std::int32_t> videoStreamIndex; // Optional. The index of the video stream to use. If omitted the first video stream will be used.
    std::optional<OAIEncodingContext> context; // Optional. The MediaBrowser.Model.Dlna.EncodingContext.
    std::optional<std::map<std::string, std::string>> streamOptions; // Optional. The streaming options.
};
struct headMasterHlsAudioPlaylist {
    std::string itemId; // The item id.
    std::string mediaSourceId; // The media version id, if playing an alternate version.
    std::optional<bool> _static; // Optional. If true, the original file will be streamed statically without any encoding. Use either no url extension or the original file extension. true/false.
    std::optional<std::string> params; // The streaming parameters.
    std::optional<std::string> tag; // The tag.
    std::optional<std::string> deviceProfileId; // Optional. The dlna device profile id to utilize.
    std::optional<std::string> playSessionId; // The play session id.
    std::optional<std::string> segmentContainer; // The segment container.
    std::optional<std::int32_t> segmentLength; // The segment length.
    std::optional<std::int32_t> minSegments; // The minimum number of segments.
    std::optional<std::string> deviceId; // The device id of the client requesting. Used to stop encoding processes when needed.
    std::optional<std::string> audioCodec; // Optional. Specify a audio codec to encode to, e.g. mp3. If omitted the server will auto-select using the url&#39;s extension. Options: aac, mp3, vorbis, wma.
    std::optional<bool> enableAutoStreamCopy; // Whether or not to allow automatic stream copy if requested values match the original source. Defaults to true.
    std::optional<bool> allowVideoStreamCopy; // Whether or not to allow copying of the video stream url.
    std::optional<bool> allowAudioStreamCopy; // Whether or not to allow copying of the audio stream url.
    std::optional<bool> breakOnNonKeyFrames; // Optional. Whether to break on non key frames.
    std::optional<std::int32_t> audioSampleRate; // Optional. Specify a specific audio sample rate, e.g. 44100.
    std::optional<std::int32_t> maxAudioBitDepth; // Optional. The maximum audio bit depth.
    std::optional<std::int32_t> maxStreamingBitrate; // Optional. The maximum streaming bitrate.
    std::optional<std::int32_t> audioBitRate; // Optional. Specify an audio bitrate to encode to, e.g. 128000. If omitted this will be left to encoder defaults.
    std::optional<std::int32_t> audioChannels; // Optional. Specify a specific number of audio channels to encode to, e.g. 2.
    std::optional<std::int32_t> maxAudioChannels; // Optional. Specify a maximum number of audio channels to encode to, e.g. 2.
    std::optional<std::string> profile; // Optional. Specify a specific an encoder profile (varies by encoder), e.g. main, baseline, high.
    std::optional<std::string> level; // Optional. Specify a level for the encoder profile (varies by encoder), e.g. 3, 3.1.
    std::optional<float> framerate; // Optional. A specific video framerate to encode to, e.g. 23.976. Generally this should be omitted unless the device has specific requirements.
    std::optional<float> maxFramerate; // Optional. A specific maximum video framerate to encode to, e.g. 23.976. Generally this should be omitted unless the device has specific requirements.
    std::optional<bool> copyTimestamps; // Whether or not to copy timestamps when transcoding with an offset. Defaults to false.
    std::optional<std::int64_t> startTimeTicks; // Optional. Specify a starting offset, in ticks. 1 tick &#x3D; 10000 ms.
    std::optional<std::int32_t> width; // Optional. The fixed horizontal resolution of the encoded video.
    std::optional<std::int32_t> height; // Optional. The fixed vertical resolution of the encoded video.
    std::optional<std::int32_t> videoBitRate; // Optional. Specify a video bitrate to encode to, e.g. 500000. If omitted this will be left to encoder defaults.
    std::optional<std::int32_t> subtitleStreamIndex; // Optional. The index of the subtitle stream to use. If omitted no subtitles will be used.
    std::optional<OAISubtitleDeliveryMethod> subtitleMethod; // Optional. Specify the subtitle delivery method.
    std::optional<std::int32_t> maxRefFrames; // Optional.
    std::optional<std::int32_t> maxVideoBitDepth; // Optional. The maximum video bit depth.
    std::optional<bool> requireAvc; // Optional. Whether to require avc.
    std::optional<bool> deInterlace; // Optional. Whether to deinterlace the video.
    std::optional<bool> requireNonAnamorphic; // Optional. Whether to require a non anamorphic stream.
    std::optional<std::int32_t> transcodingMaxAudioChannels; // Optional. The maximum number of audio channels to transcode.
    std::optional<std::int32_t> cpuCoreLimit; // Optional. The limit of how many cpu cores to use.
    std::optional<std::string> liveStreamId; // The live stream id.
    std::optional<bool> enableMpegtsM2TsMode; // Optional. Whether to enable the MpegtsM2Ts mode.
    std::optional<std::string> videoCodec; // Optional. Specify a video codec to encode to, e.g. h264. If omitted the server will auto-select using the url&#39;s extension. Options: h265, h264, mpeg4, theora, vp8, vp9, vpx (deprecated), wmv.
    std::optional<std::string> subtitleCodec; // Optional. Specify a subtitle codec to encode to.
    std::optional<std::string> transcodeReasons; // Optional. The transcoding reason.
    std::optional<std::int32_t> audioStreamIndex; // Optional. The index of the audio stream to use. If omitted the first audio stream will be used.
    std::optional<std::int32_t> videoStreamIndex; // Optional. The index of the video stream to use. If omitted the first video stream will be used.
    std::optional<OAIEncodingContext> context; // Optional. The MediaBrowser.Model.Dlna.EncodingContext.
    std::optional<std::map<std::string, std::string>> streamOptions; // Optional. The streaming options.
    std::optional<bool> enableAdaptiveBitrateStreaming; // Enable adaptive bitrate streaming.
};
struct headMasterHlsVideoPlaylist {
    std::string itemId; // The item id.
    std::string mediaSourceId; // The media version id, if playing an alternate version.
    std::optional<bool> _static; // Optional. If true, the original file will be streamed statically without any encoding. Use either no url extension or the original file extension. true/false.
    std::optional<std::string> params; // The streaming parameters.
    std::optional<std::string> tag; // The tag.
    std::optional<std::string> deviceProfileId; // Optional. The dlna device profile id to utilize.
    std::optional<std::string> playSessionId; // The play session id.
    std::optional<std::string> segmentContainer; // The segment container.
    std::optional<std::int32_t> segmentLength; // The segment length.
    std::optional<std::int32_t> minSegments; // The minimum number of segments.
    std::optional<std::string> deviceId; // The device id of the client requesting. Used to stop encoding processes when needed.
    std::optional<std::string> audioCodec; // Optional. Specify a audio codec to encode to, e.g. mp3. If omitted the server will auto-select using the url&#39;s extension. Options: aac, mp3, vorbis, wma.
    std::optional<bool> enableAutoStreamCopy; // Whether or not to allow automatic stream copy if requested values match the original source. Defaults to true.
    std::optional<bool> allowVideoStreamCopy; // Whether or not to allow copying of the video stream url.
    std::optional<bool> allowAudioStreamCopy; // Whether or not to allow copying of the audio stream url.
    std::optional<bool> breakOnNonKeyFrames; // Optional. Whether to break on non key frames.
    std::optional<std::int32_t> audioSampleRate; // Optional. Specify a specific audio sample rate, e.g. 44100.
    std::optional<std::int32_t> maxAudioBitDepth; // Optional. The maximum audio bit depth.
    std::optional<std::int32_t> audioBitRate; // Optional. Specify an audio bitrate to encode to, e.g. 128000. If omitted this will be left to encoder defaults.
    std::optional<std::int32_t> audioChannels; // Optional. Specify a specific number of audio channels to encode to, e.g. 2.
    std::optional<std::int32_t> maxAudioChannels; // Optional. Specify a maximum number of audio channels to encode to, e.g. 2.
    std::optional<std::string> profile; // Optional. Specify a specific an encoder profile (varies by encoder), e.g. main, baseline, high.
    std::optional<std::string> level; // Optional. Specify a level for the encoder profile (varies by encoder), e.g. 3, 3.1.
    std::optional<float> framerate; // Optional. A specific video framerate to encode to, e.g. 23.976. Generally this should be omitted unless the device has specific requirements.
    std::optional<float> maxFramerate; // Optional. A specific maximum video framerate to encode to, e.g. 23.976. Generally this should be omitted unless the device has specific requirements.
    std::optional<bool> copyTimestamps; // Whether or not to copy timestamps when transcoding with an offset. Defaults to false.
    std::optional<std::int64_t> startTimeTicks; // Optional. Specify a starting offset, in ticks. 1 tick &#x3D; 10000 ms.
    std::optional<std::int32_t> width; // Optional. The fixed horizontal resolution of the encoded video.
    std::optional<std::int32_t> height; // Optional. The fixed vertical resolution of the encoded video.
    std::optional<std::int32_t> maxWidth; // Optional. The maximum horizontal resolution of the encoded video.
    std::optional<std::int32_t> maxHeight; // Optional. The maximum vertical resolution of the encoded video.
    std::optional<std::int32_t> videoBitRate; // Optional. Specify a video bitrate to encode to, e.g. 500000. If omitted this will be left to encoder defaults.
    std::optional<std::int32_t> subtitleStreamIndex; // Optional. The index of the subtitle stream to use. If omitted no subtitles will be used.
    std::optional<OAISubtitleDeliveryMethod> subtitleMethod; // Optional. Specify the subtitle delivery method.
    std::optional<std::int32_t> maxRefFrames; // Optional.
    std::optional<std::int32_t> maxVideoBitDepth; // Optional. The maximum video bit depth.
    std::optional<bool> requireAvc; // Optional. Whether to require avc.
    std::optional<bool> deInterlace; // Optional. Whether to deinterlace the video.
    std::optional<bool> requireNonAnamorphic; // Optional. Whether to require a non anamorphic stream.
    std::optional<std::int32_t> transcodingMaxAudioChannels; // Optional. The maximum number of audio channels to transcode.
    std::optional<std::int32_t> cpuCoreLimit; // Optional. The limit of how many cpu cores to use.
    std::optional<std::string> liveStreamId; // The live stream id.
    std::optional<bool> enableMpegtsM2TsMode; // Optional. Whether to enable the MpegtsM2Ts mode.
    std::optional<std::string> videoCodec; // Optional. Specify a video codec to encode to, e.g. h264. If omitted the server will auto-select using the url&#39;s extension. Options: h265, h264, mpeg4, theora, vp8, vp9, vpx (deprecated), wmv.
    std::optional<std::string> subtitleCodec; // Optional. Specify a subtitle codec to encode to.
    std::optional<std::string> transcodeReasons; // Optional. The transcoding reason.
    std::optional<std::int32_t> audioStreamIndex; // Optional. The index of the audio stream to use. If omitted the first audio stream will be used.
    std::optional<std::int32_t> videoStreamIndex; // Optional. The index of the video stream to use. If omitted the first video stream will be used.
    std::optional<OAIEncodingContext> context; // Optional. The MediaBrowser.Model.Dlna.EncodingContext.
    std::optional<std::map<std::string, std::string>> streamOptions; // Optional. The streaming options.
    std::optional<bool> enableAdaptiveBitrateStreaming; // Enable adaptive bitrate streaming.
    std::optional<bool> enableTrickplay; // Enable trickplay image playlists being added to master playlist.
};
}

namespace api 
{
// Gets a video stream using HTTP live streaming.
struct getHlsAudioSegment {
public:
    using in_type                      = param::getHlsAudioSegment;
    using out_type                     = model::return_type_getHlsAudioSegment;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Audio/{}/hls1/{}/{}.{}"sv,
            input.itemId,
            input.playlistId,
            input.segmentId,
            input.container
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("runtimeTicks", convert_from<std::string>(input.runtimeTicks));
        p.set_param("actualSegmentLengthTicks", convert_from<std::string>(input.actualSegmentLengthTicks));
        if(input._static)
            p.set_param("_static", convert_from<std::string>(input._static.value()));
        if(input.params)
            p.set_param("params", convert_from<std::string>(input.params.value()));
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.deviceProfileId)
            p.set_param("deviceProfileId", convert_from<std::string>(input.deviceProfileId.value()));
        if(input.playSessionId)
            p.set_param("playSessionId", convert_from<std::string>(input.playSessionId.value()));
        if(input.segmentContainer)
            p.set_param("segmentContainer", convert_from<std::string>(input.segmentContainer.value()));
        if(input.segmentLength)
            p.set_param("segmentLength", convert_from<std::string>(input.segmentLength.value()));
        if(input.minSegments)
            p.set_param("minSegments", convert_from<std::string>(input.minSegments.value()));
        if(input.mediaSourceId)
            p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId.value()));
        if(input.deviceId)
            p.set_param("deviceId", convert_from<std::string>(input.deviceId.value()));
        if(input.audioCodec)
            p.set_param("audioCodec", convert_from<std::string>(input.audioCodec.value()));
        if(input.enableAutoStreamCopy)
            p.set_param("enableAutoStreamCopy", convert_from<std::string>(input.enableAutoStreamCopy.value()));
        if(input.allowVideoStreamCopy)
            p.set_param("allowVideoStreamCopy", convert_from<std::string>(input.allowVideoStreamCopy.value()));
        if(input.allowAudioStreamCopy)
            p.set_param("allowAudioStreamCopy", convert_from<std::string>(input.allowAudioStreamCopy.value()));
        if(input.breakOnNonKeyFrames)
            p.set_param("breakOnNonKeyFrames", convert_from<std::string>(input.breakOnNonKeyFrames.value()));
        if(input.audioSampleRate)
            p.set_param("audioSampleRate", convert_from<std::string>(input.audioSampleRate.value()));
        if(input.maxAudioBitDepth)
            p.set_param("maxAudioBitDepth", convert_from<std::string>(input.maxAudioBitDepth.value()));
        if(input.maxStreamingBitrate)
            p.set_param("maxStreamingBitrate", convert_from<std::string>(input.maxStreamingBitrate.value()));
        if(input.audioBitRate)
            p.set_param("audioBitRate", convert_from<std::string>(input.audioBitRate.value()));
        if(input.audioChannels)
            p.set_param("audioChannels", convert_from<std::string>(input.audioChannels.value()));
        if(input.maxAudioChannels)
            p.set_param("maxAudioChannels", convert_from<std::string>(input.maxAudioChannels.value()));
        if(input.profile)
            p.set_param("profile", convert_from<std::string>(input.profile.value()));
        if(input.level)
            p.set_param("level", convert_from<std::string>(input.level.value()));
        if(input.framerate)
            p.set_param("framerate", convert_from<std::string>(input.framerate.value()));
        if(input.maxFramerate)
            p.set_param("maxFramerate", convert_from<std::string>(input.maxFramerate.value()));
        if(input.copyTimestamps)
            p.set_param("copyTimestamps", convert_from<std::string>(input.copyTimestamps.value()));
        if(input.startTimeTicks)
            p.set_param("startTimeTicks", convert_from<std::string>(input.startTimeTicks.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.videoBitRate)
            p.set_param("videoBitRate", convert_from<std::string>(input.videoBitRate.value()));
        if(input.subtitleStreamIndex)
            p.set_param("subtitleStreamIndex", convert_from<std::string>(input.subtitleStreamIndex.value()));
        if(input.subtitleMethod)
            p.set_param("subtitleMethod", convert_from<std::string>(input.subtitleMethod.value()));
        if(input.maxRefFrames)
            p.set_param("maxRefFrames", convert_from<std::string>(input.maxRefFrames.value()));
        if(input.maxVideoBitDepth)
            p.set_param("maxVideoBitDepth", convert_from<std::string>(input.maxVideoBitDepth.value()));
        if(input.requireAvc)
            p.set_param("requireAvc", convert_from<std::string>(input.requireAvc.value()));
        if(input.deInterlace)
            p.set_param("deInterlace", convert_from<std::string>(input.deInterlace.value()));
        if(input.requireNonAnamorphic)
            p.set_param("requireNonAnamorphic", convert_from<std::string>(input.requireNonAnamorphic.value()));
        if(input.transcodingMaxAudioChannels)
            p.set_param("transcodingMaxAudioChannels", convert_from<std::string>(input.transcodingMaxAudioChannels.value()));
        if(input.cpuCoreLimit)
            p.set_param("cpuCoreLimit", convert_from<std::string>(input.cpuCoreLimit.value()));
        if(input.liveStreamId)
            p.set_param("liveStreamId", convert_from<std::string>(input.liveStreamId.value()));
        if(input.enableMpegtsM2TsMode)
            p.set_param("enableMpegtsM2TsMode", convert_from<std::string>(input.enableMpegtsM2TsMode.value()));
        if(input.videoCodec)
            p.set_param("videoCodec", convert_from<std::string>(input.videoCodec.value()));
        if(input.subtitleCodec)
            p.set_param("subtitleCodec", convert_from<std::string>(input.subtitleCodec.value()));
        if(input.transcodeReasons)
            p.set_param("transcodeReasons", convert_from<std::string>(input.transcodeReasons.value()));
        if(input.audioStreamIndex)
            p.set_param("audioStreamIndex", convert_from<std::string>(input.audioStreamIndex.value()));
        if(input.videoStreamIndex)
            p.set_param("videoStreamIndex", convert_from<std::string>(input.videoStreamIndex.value()));
        if(input.context)
            p.set_param("context", convert_from<std::string>(input.context.value()));
        if(input.streamOptions)
            p.set_param("streamOptions", input.streamOptions.value());
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
 * baseName: DynamicHls
 * defaultResponse: {}
 */
};
// Gets a video stream using HTTP live streaming.
struct getHlsVideoSegment {
public:
    using in_type                      = param::getHlsVideoSegment;
    using out_type                     = model::return_type_getHlsVideoSegment;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Videos/{}/hls1/{}/{}.{}"sv,
            input.itemId,
            input.playlistId,
            input.segmentId,
            input.container
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("runtimeTicks", convert_from<std::string>(input.runtimeTicks));
        p.set_param("actualSegmentLengthTicks", convert_from<std::string>(input.actualSegmentLengthTicks));
        if(input._static)
            p.set_param("_static", convert_from<std::string>(input._static.value()));
        if(input.params)
            p.set_param("params", convert_from<std::string>(input.params.value()));
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.deviceProfileId)
            p.set_param("deviceProfileId", convert_from<std::string>(input.deviceProfileId.value()));
        if(input.playSessionId)
            p.set_param("playSessionId", convert_from<std::string>(input.playSessionId.value()));
        if(input.segmentContainer)
            p.set_param("segmentContainer", convert_from<std::string>(input.segmentContainer.value()));
        if(input.segmentLength)
            p.set_param("segmentLength", convert_from<std::string>(input.segmentLength.value()));
        if(input.minSegments)
            p.set_param("minSegments", convert_from<std::string>(input.minSegments.value()));
        if(input.mediaSourceId)
            p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId.value()));
        if(input.deviceId)
            p.set_param("deviceId", convert_from<std::string>(input.deviceId.value()));
        if(input.audioCodec)
            p.set_param("audioCodec", convert_from<std::string>(input.audioCodec.value()));
        if(input.enableAutoStreamCopy)
            p.set_param("enableAutoStreamCopy", convert_from<std::string>(input.enableAutoStreamCopy.value()));
        if(input.allowVideoStreamCopy)
            p.set_param("allowVideoStreamCopy", convert_from<std::string>(input.allowVideoStreamCopy.value()));
        if(input.allowAudioStreamCopy)
            p.set_param("allowAudioStreamCopy", convert_from<std::string>(input.allowAudioStreamCopy.value()));
        if(input.breakOnNonKeyFrames)
            p.set_param("breakOnNonKeyFrames", convert_from<std::string>(input.breakOnNonKeyFrames.value()));
        if(input.audioSampleRate)
            p.set_param("audioSampleRate", convert_from<std::string>(input.audioSampleRate.value()));
        if(input.maxAudioBitDepth)
            p.set_param("maxAudioBitDepth", convert_from<std::string>(input.maxAudioBitDepth.value()));
        if(input.audioBitRate)
            p.set_param("audioBitRate", convert_from<std::string>(input.audioBitRate.value()));
        if(input.audioChannels)
            p.set_param("audioChannels", convert_from<std::string>(input.audioChannels.value()));
        if(input.maxAudioChannels)
            p.set_param("maxAudioChannels", convert_from<std::string>(input.maxAudioChannels.value()));
        if(input.profile)
            p.set_param("profile", convert_from<std::string>(input.profile.value()));
        if(input.level)
            p.set_param("level", convert_from<std::string>(input.level.value()));
        if(input.framerate)
            p.set_param("framerate", convert_from<std::string>(input.framerate.value()));
        if(input.maxFramerate)
            p.set_param("maxFramerate", convert_from<std::string>(input.maxFramerate.value()));
        if(input.copyTimestamps)
            p.set_param("copyTimestamps", convert_from<std::string>(input.copyTimestamps.value()));
        if(input.startTimeTicks)
            p.set_param("startTimeTicks", convert_from<std::string>(input.startTimeTicks.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.videoBitRate)
            p.set_param("videoBitRate", convert_from<std::string>(input.videoBitRate.value()));
        if(input.subtitleStreamIndex)
            p.set_param("subtitleStreamIndex", convert_from<std::string>(input.subtitleStreamIndex.value()));
        if(input.subtitleMethod)
            p.set_param("subtitleMethod", convert_from<std::string>(input.subtitleMethod.value()));
        if(input.maxRefFrames)
            p.set_param("maxRefFrames", convert_from<std::string>(input.maxRefFrames.value()));
        if(input.maxVideoBitDepth)
            p.set_param("maxVideoBitDepth", convert_from<std::string>(input.maxVideoBitDepth.value()));
        if(input.requireAvc)
            p.set_param("requireAvc", convert_from<std::string>(input.requireAvc.value()));
        if(input.deInterlace)
            p.set_param("deInterlace", convert_from<std::string>(input.deInterlace.value()));
        if(input.requireNonAnamorphic)
            p.set_param("requireNonAnamorphic", convert_from<std::string>(input.requireNonAnamorphic.value()));
        if(input.transcodingMaxAudioChannels)
            p.set_param("transcodingMaxAudioChannels", convert_from<std::string>(input.transcodingMaxAudioChannels.value()));
        if(input.cpuCoreLimit)
            p.set_param("cpuCoreLimit", convert_from<std::string>(input.cpuCoreLimit.value()));
        if(input.liveStreamId)
            p.set_param("liveStreamId", convert_from<std::string>(input.liveStreamId.value()));
        if(input.enableMpegtsM2TsMode)
            p.set_param("enableMpegtsM2TsMode", convert_from<std::string>(input.enableMpegtsM2TsMode.value()));
        if(input.videoCodec)
            p.set_param("videoCodec", convert_from<std::string>(input.videoCodec.value()));
        if(input.subtitleCodec)
            p.set_param("subtitleCodec", convert_from<std::string>(input.subtitleCodec.value()));
        if(input.transcodeReasons)
            p.set_param("transcodeReasons", convert_from<std::string>(input.transcodeReasons.value()));
        if(input.audioStreamIndex)
            p.set_param("audioStreamIndex", convert_from<std::string>(input.audioStreamIndex.value()));
        if(input.videoStreamIndex)
            p.set_param("videoStreamIndex", convert_from<std::string>(input.videoStreamIndex.value()));
        if(input.context)
            p.set_param("context", convert_from<std::string>(input.context.value()));
        if(input.streamOptions)
            p.set_param("streamOptions", input.streamOptions.value());
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
 * baseName: DynamicHls
 * defaultResponse: {}
 */
};
// Gets a hls live stream.
struct getLiveHlsStream {
public:
    using in_type                      = param::getLiveHlsStream;
    using out_type                     = model::return_type_getLiveHlsStream;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Videos/{}/live.m3u8"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.container)
            p.set_param("container", convert_from<std::string>(input.container.value()));
        if(input._static)
            p.set_param("_static", convert_from<std::string>(input._static.value()));
        if(input.params)
            p.set_param("params", convert_from<std::string>(input.params.value()));
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.deviceProfileId)
            p.set_param("deviceProfileId", convert_from<std::string>(input.deviceProfileId.value()));
        if(input.playSessionId)
            p.set_param("playSessionId", convert_from<std::string>(input.playSessionId.value()));
        if(input.segmentContainer)
            p.set_param("segmentContainer", convert_from<std::string>(input.segmentContainer.value()));
        if(input.segmentLength)
            p.set_param("segmentLength", convert_from<std::string>(input.segmentLength.value()));
        if(input.minSegments)
            p.set_param("minSegments", convert_from<std::string>(input.minSegments.value()));
        if(input.mediaSourceId)
            p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId.value()));
        if(input.deviceId)
            p.set_param("deviceId", convert_from<std::string>(input.deviceId.value()));
        if(input.audioCodec)
            p.set_param("audioCodec", convert_from<std::string>(input.audioCodec.value()));
        if(input.enableAutoStreamCopy)
            p.set_param("enableAutoStreamCopy", convert_from<std::string>(input.enableAutoStreamCopy.value()));
        if(input.allowVideoStreamCopy)
            p.set_param("allowVideoStreamCopy", convert_from<std::string>(input.allowVideoStreamCopy.value()));
        if(input.allowAudioStreamCopy)
            p.set_param("allowAudioStreamCopy", convert_from<std::string>(input.allowAudioStreamCopy.value()));
        if(input.breakOnNonKeyFrames)
            p.set_param("breakOnNonKeyFrames", convert_from<std::string>(input.breakOnNonKeyFrames.value()));
        if(input.audioSampleRate)
            p.set_param("audioSampleRate", convert_from<std::string>(input.audioSampleRate.value()));
        if(input.maxAudioBitDepth)
            p.set_param("maxAudioBitDepth", convert_from<std::string>(input.maxAudioBitDepth.value()));
        if(input.audioBitRate)
            p.set_param("audioBitRate", convert_from<std::string>(input.audioBitRate.value()));
        if(input.audioChannels)
            p.set_param("audioChannels", convert_from<std::string>(input.audioChannels.value()));
        if(input.maxAudioChannels)
            p.set_param("maxAudioChannels", convert_from<std::string>(input.maxAudioChannels.value()));
        if(input.profile)
            p.set_param("profile", convert_from<std::string>(input.profile.value()));
        if(input.level)
            p.set_param("level", convert_from<std::string>(input.level.value()));
        if(input.framerate)
            p.set_param("framerate", convert_from<std::string>(input.framerate.value()));
        if(input.maxFramerate)
            p.set_param("maxFramerate", convert_from<std::string>(input.maxFramerate.value()));
        if(input.copyTimestamps)
            p.set_param("copyTimestamps", convert_from<std::string>(input.copyTimestamps.value()));
        if(input.startTimeTicks)
            p.set_param("startTimeTicks", convert_from<std::string>(input.startTimeTicks.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.videoBitRate)
            p.set_param("videoBitRate", convert_from<std::string>(input.videoBitRate.value()));
        if(input.subtitleStreamIndex)
            p.set_param("subtitleStreamIndex", convert_from<std::string>(input.subtitleStreamIndex.value()));
        if(input.subtitleMethod)
            p.set_param("subtitleMethod", convert_from<std::string>(input.subtitleMethod.value()));
        if(input.maxRefFrames)
            p.set_param("maxRefFrames", convert_from<std::string>(input.maxRefFrames.value()));
        if(input.maxVideoBitDepth)
            p.set_param("maxVideoBitDepth", convert_from<std::string>(input.maxVideoBitDepth.value()));
        if(input.requireAvc)
            p.set_param("requireAvc", convert_from<std::string>(input.requireAvc.value()));
        if(input.deInterlace)
            p.set_param("deInterlace", convert_from<std::string>(input.deInterlace.value()));
        if(input.requireNonAnamorphic)
            p.set_param("requireNonAnamorphic", convert_from<std::string>(input.requireNonAnamorphic.value()));
        if(input.transcodingMaxAudioChannels)
            p.set_param("transcodingMaxAudioChannels", convert_from<std::string>(input.transcodingMaxAudioChannels.value()));
        if(input.cpuCoreLimit)
            p.set_param("cpuCoreLimit", convert_from<std::string>(input.cpuCoreLimit.value()));
        if(input.liveStreamId)
            p.set_param("liveStreamId", convert_from<std::string>(input.liveStreamId.value()));
        if(input.enableMpegtsM2TsMode)
            p.set_param("enableMpegtsM2TsMode", convert_from<std::string>(input.enableMpegtsM2TsMode.value()));
        if(input.videoCodec)
            p.set_param("videoCodec", convert_from<std::string>(input.videoCodec.value()));
        if(input.subtitleCodec)
            p.set_param("subtitleCodec", convert_from<std::string>(input.subtitleCodec.value()));
        if(input.transcodeReasons)
            p.set_param("transcodeReasons", convert_from<std::string>(input.transcodeReasons.value()));
        if(input.audioStreamIndex)
            p.set_param("audioStreamIndex", convert_from<std::string>(input.audioStreamIndex.value()));
        if(input.videoStreamIndex)
            p.set_param("videoStreamIndex", convert_from<std::string>(input.videoStreamIndex.value()));
        if(input.context)
            p.set_param("context", convert_from<std::string>(input.context.value()));
        if(input.streamOptions)
            p.set_param("streamOptions", input.streamOptions.value());
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.enableSubtitlesInManifest)
            p.set_param("enableSubtitlesInManifest", convert_from<std::string>(input.enableSubtitlesInManifest.value()));
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
 * baseName: DynamicHls
 * defaultResponse: {}
 */
};
// Gets an audio hls playlist stream.
struct getMasterHlsAudioPlaylist {
public:
    using in_type                      = param::getMasterHlsAudioPlaylist;
    using out_type                     = model::return_type_getMasterHlsAudioPlaylist;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Audio/{}/master.m3u8"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input._static)
            p.set_param("_static", convert_from<std::string>(input._static.value()));
        if(input.params)
            p.set_param("params", convert_from<std::string>(input.params.value()));
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.deviceProfileId)
            p.set_param("deviceProfileId", convert_from<std::string>(input.deviceProfileId.value()));
        if(input.playSessionId)
            p.set_param("playSessionId", convert_from<std::string>(input.playSessionId.value()));
        if(input.segmentContainer)
            p.set_param("segmentContainer", convert_from<std::string>(input.segmentContainer.value()));
        if(input.segmentLength)
            p.set_param("segmentLength", convert_from<std::string>(input.segmentLength.value()));
        if(input.minSegments)
            p.set_param("minSegments", convert_from<std::string>(input.minSegments.value()));
        p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId));
        if(input.deviceId)
            p.set_param("deviceId", convert_from<std::string>(input.deviceId.value()));
        if(input.audioCodec)
            p.set_param("audioCodec", convert_from<std::string>(input.audioCodec.value()));
        if(input.enableAutoStreamCopy)
            p.set_param("enableAutoStreamCopy", convert_from<std::string>(input.enableAutoStreamCopy.value()));
        if(input.allowVideoStreamCopy)
            p.set_param("allowVideoStreamCopy", convert_from<std::string>(input.allowVideoStreamCopy.value()));
        if(input.allowAudioStreamCopy)
            p.set_param("allowAudioStreamCopy", convert_from<std::string>(input.allowAudioStreamCopy.value()));
        if(input.breakOnNonKeyFrames)
            p.set_param("breakOnNonKeyFrames", convert_from<std::string>(input.breakOnNonKeyFrames.value()));
        if(input.audioSampleRate)
            p.set_param("audioSampleRate", convert_from<std::string>(input.audioSampleRate.value()));
        if(input.maxAudioBitDepth)
            p.set_param("maxAudioBitDepth", convert_from<std::string>(input.maxAudioBitDepth.value()));
        if(input.maxStreamingBitrate)
            p.set_param("maxStreamingBitrate", convert_from<std::string>(input.maxStreamingBitrate.value()));
        if(input.audioBitRate)
            p.set_param("audioBitRate", convert_from<std::string>(input.audioBitRate.value()));
        if(input.audioChannels)
            p.set_param("audioChannels", convert_from<std::string>(input.audioChannels.value()));
        if(input.maxAudioChannels)
            p.set_param("maxAudioChannels", convert_from<std::string>(input.maxAudioChannels.value()));
        if(input.profile)
            p.set_param("profile", convert_from<std::string>(input.profile.value()));
        if(input.level)
            p.set_param("level", convert_from<std::string>(input.level.value()));
        if(input.framerate)
            p.set_param("framerate", convert_from<std::string>(input.framerate.value()));
        if(input.maxFramerate)
            p.set_param("maxFramerate", convert_from<std::string>(input.maxFramerate.value()));
        if(input.copyTimestamps)
            p.set_param("copyTimestamps", convert_from<std::string>(input.copyTimestamps.value()));
        if(input.startTimeTicks)
            p.set_param("startTimeTicks", convert_from<std::string>(input.startTimeTicks.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.videoBitRate)
            p.set_param("videoBitRate", convert_from<std::string>(input.videoBitRate.value()));
        if(input.subtitleStreamIndex)
            p.set_param("subtitleStreamIndex", convert_from<std::string>(input.subtitleStreamIndex.value()));
        if(input.subtitleMethod)
            p.set_param("subtitleMethod", convert_from<std::string>(input.subtitleMethod.value()));
        if(input.maxRefFrames)
            p.set_param("maxRefFrames", convert_from<std::string>(input.maxRefFrames.value()));
        if(input.maxVideoBitDepth)
            p.set_param("maxVideoBitDepth", convert_from<std::string>(input.maxVideoBitDepth.value()));
        if(input.requireAvc)
            p.set_param("requireAvc", convert_from<std::string>(input.requireAvc.value()));
        if(input.deInterlace)
            p.set_param("deInterlace", convert_from<std::string>(input.deInterlace.value()));
        if(input.requireNonAnamorphic)
            p.set_param("requireNonAnamorphic", convert_from<std::string>(input.requireNonAnamorphic.value()));
        if(input.transcodingMaxAudioChannels)
            p.set_param("transcodingMaxAudioChannels", convert_from<std::string>(input.transcodingMaxAudioChannels.value()));
        if(input.cpuCoreLimit)
            p.set_param("cpuCoreLimit", convert_from<std::string>(input.cpuCoreLimit.value()));
        if(input.liveStreamId)
            p.set_param("liveStreamId", convert_from<std::string>(input.liveStreamId.value()));
        if(input.enableMpegtsM2TsMode)
            p.set_param("enableMpegtsM2TsMode", convert_from<std::string>(input.enableMpegtsM2TsMode.value()));
        if(input.videoCodec)
            p.set_param("videoCodec", convert_from<std::string>(input.videoCodec.value()));
        if(input.subtitleCodec)
            p.set_param("subtitleCodec", convert_from<std::string>(input.subtitleCodec.value()));
        if(input.transcodeReasons)
            p.set_param("transcodeReasons", convert_from<std::string>(input.transcodeReasons.value()));
        if(input.audioStreamIndex)
            p.set_param("audioStreamIndex", convert_from<std::string>(input.audioStreamIndex.value()));
        if(input.videoStreamIndex)
            p.set_param("videoStreamIndex", convert_from<std::string>(input.videoStreamIndex.value()));
        if(input.context)
            p.set_param("context", convert_from<std::string>(input.context.value()));
        if(input.streamOptions)
            p.set_param("streamOptions", input.streamOptions.value());
        if(input.enableAdaptiveBitrateStreaming)
            p.set_param("enableAdaptiveBitrateStreaming", convert_from<std::string>(input.enableAdaptiveBitrateStreaming.value()));
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
 * baseName: DynamicHls
 * defaultResponse: {}
 */
};
// Gets a video hls playlist stream.
struct getMasterHlsVideoPlaylist {
public:
    using in_type                      = param::getMasterHlsVideoPlaylist;
    using out_type                     = model::return_type_getMasterHlsVideoPlaylist;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Videos/{}/master.m3u8"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input._static)
            p.set_param("_static", convert_from<std::string>(input._static.value()));
        if(input.params)
            p.set_param("params", convert_from<std::string>(input.params.value()));
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.deviceProfileId)
            p.set_param("deviceProfileId", convert_from<std::string>(input.deviceProfileId.value()));
        if(input.playSessionId)
            p.set_param("playSessionId", convert_from<std::string>(input.playSessionId.value()));
        if(input.segmentContainer)
            p.set_param("segmentContainer", convert_from<std::string>(input.segmentContainer.value()));
        if(input.segmentLength)
            p.set_param("segmentLength", convert_from<std::string>(input.segmentLength.value()));
        if(input.minSegments)
            p.set_param("minSegments", convert_from<std::string>(input.minSegments.value()));
        p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId));
        if(input.deviceId)
            p.set_param("deviceId", convert_from<std::string>(input.deviceId.value()));
        if(input.audioCodec)
            p.set_param("audioCodec", convert_from<std::string>(input.audioCodec.value()));
        if(input.enableAutoStreamCopy)
            p.set_param("enableAutoStreamCopy", convert_from<std::string>(input.enableAutoStreamCopy.value()));
        if(input.allowVideoStreamCopy)
            p.set_param("allowVideoStreamCopy", convert_from<std::string>(input.allowVideoStreamCopy.value()));
        if(input.allowAudioStreamCopy)
            p.set_param("allowAudioStreamCopy", convert_from<std::string>(input.allowAudioStreamCopy.value()));
        if(input.breakOnNonKeyFrames)
            p.set_param("breakOnNonKeyFrames", convert_from<std::string>(input.breakOnNonKeyFrames.value()));
        if(input.audioSampleRate)
            p.set_param("audioSampleRate", convert_from<std::string>(input.audioSampleRate.value()));
        if(input.maxAudioBitDepth)
            p.set_param("maxAudioBitDepth", convert_from<std::string>(input.maxAudioBitDepth.value()));
        if(input.audioBitRate)
            p.set_param("audioBitRate", convert_from<std::string>(input.audioBitRate.value()));
        if(input.audioChannels)
            p.set_param("audioChannels", convert_from<std::string>(input.audioChannels.value()));
        if(input.maxAudioChannels)
            p.set_param("maxAudioChannels", convert_from<std::string>(input.maxAudioChannels.value()));
        if(input.profile)
            p.set_param("profile", convert_from<std::string>(input.profile.value()));
        if(input.level)
            p.set_param("level", convert_from<std::string>(input.level.value()));
        if(input.framerate)
            p.set_param("framerate", convert_from<std::string>(input.framerate.value()));
        if(input.maxFramerate)
            p.set_param("maxFramerate", convert_from<std::string>(input.maxFramerate.value()));
        if(input.copyTimestamps)
            p.set_param("copyTimestamps", convert_from<std::string>(input.copyTimestamps.value()));
        if(input.startTimeTicks)
            p.set_param("startTimeTicks", convert_from<std::string>(input.startTimeTicks.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.videoBitRate)
            p.set_param("videoBitRate", convert_from<std::string>(input.videoBitRate.value()));
        if(input.subtitleStreamIndex)
            p.set_param("subtitleStreamIndex", convert_from<std::string>(input.subtitleStreamIndex.value()));
        if(input.subtitleMethod)
            p.set_param("subtitleMethod", convert_from<std::string>(input.subtitleMethod.value()));
        if(input.maxRefFrames)
            p.set_param("maxRefFrames", convert_from<std::string>(input.maxRefFrames.value()));
        if(input.maxVideoBitDepth)
            p.set_param("maxVideoBitDepth", convert_from<std::string>(input.maxVideoBitDepth.value()));
        if(input.requireAvc)
            p.set_param("requireAvc", convert_from<std::string>(input.requireAvc.value()));
        if(input.deInterlace)
            p.set_param("deInterlace", convert_from<std::string>(input.deInterlace.value()));
        if(input.requireNonAnamorphic)
            p.set_param("requireNonAnamorphic", convert_from<std::string>(input.requireNonAnamorphic.value()));
        if(input.transcodingMaxAudioChannels)
            p.set_param("transcodingMaxAudioChannels", convert_from<std::string>(input.transcodingMaxAudioChannels.value()));
        if(input.cpuCoreLimit)
            p.set_param("cpuCoreLimit", convert_from<std::string>(input.cpuCoreLimit.value()));
        if(input.liveStreamId)
            p.set_param("liveStreamId", convert_from<std::string>(input.liveStreamId.value()));
        if(input.enableMpegtsM2TsMode)
            p.set_param("enableMpegtsM2TsMode", convert_from<std::string>(input.enableMpegtsM2TsMode.value()));
        if(input.videoCodec)
            p.set_param("videoCodec", convert_from<std::string>(input.videoCodec.value()));
        if(input.subtitleCodec)
            p.set_param("subtitleCodec", convert_from<std::string>(input.subtitleCodec.value()));
        if(input.transcodeReasons)
            p.set_param("transcodeReasons", convert_from<std::string>(input.transcodeReasons.value()));
        if(input.audioStreamIndex)
            p.set_param("audioStreamIndex", convert_from<std::string>(input.audioStreamIndex.value()));
        if(input.videoStreamIndex)
            p.set_param("videoStreamIndex", convert_from<std::string>(input.videoStreamIndex.value()));
        if(input.context)
            p.set_param("context", convert_from<std::string>(input.context.value()));
        if(input.streamOptions)
            p.set_param("streamOptions", input.streamOptions.value());
        if(input.enableAdaptiveBitrateStreaming)
            p.set_param("enableAdaptiveBitrateStreaming", convert_from<std::string>(input.enableAdaptiveBitrateStreaming.value()));
        if(input.enableTrickplay)
            p.set_param("enableTrickplay", convert_from<std::string>(input.enableTrickplay.value()));
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
 * baseName: DynamicHls
 * defaultResponse: {}
 */
};
// Gets an audio stream using HTTP live streaming.
struct getVariantHlsAudioPlaylist {
public:
    using in_type                      = param::getVariantHlsAudioPlaylist;
    using out_type                     = model::return_type_getVariantHlsAudioPlaylist;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Audio/{}/main.m3u8"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input._static)
            p.set_param("_static", convert_from<std::string>(input._static.value()));
        if(input.params)
            p.set_param("params", convert_from<std::string>(input.params.value()));
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.deviceProfileId)
            p.set_param("deviceProfileId", convert_from<std::string>(input.deviceProfileId.value()));
        if(input.playSessionId)
            p.set_param("playSessionId", convert_from<std::string>(input.playSessionId.value()));
        if(input.segmentContainer)
            p.set_param("segmentContainer", convert_from<std::string>(input.segmentContainer.value()));
        if(input.segmentLength)
            p.set_param("segmentLength", convert_from<std::string>(input.segmentLength.value()));
        if(input.minSegments)
            p.set_param("minSegments", convert_from<std::string>(input.minSegments.value()));
        if(input.mediaSourceId)
            p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId.value()));
        if(input.deviceId)
            p.set_param("deviceId", convert_from<std::string>(input.deviceId.value()));
        if(input.audioCodec)
            p.set_param("audioCodec", convert_from<std::string>(input.audioCodec.value()));
        if(input.enableAutoStreamCopy)
            p.set_param("enableAutoStreamCopy", convert_from<std::string>(input.enableAutoStreamCopy.value()));
        if(input.allowVideoStreamCopy)
            p.set_param("allowVideoStreamCopy", convert_from<std::string>(input.allowVideoStreamCopy.value()));
        if(input.allowAudioStreamCopy)
            p.set_param("allowAudioStreamCopy", convert_from<std::string>(input.allowAudioStreamCopy.value()));
        if(input.breakOnNonKeyFrames)
            p.set_param("breakOnNonKeyFrames", convert_from<std::string>(input.breakOnNonKeyFrames.value()));
        if(input.audioSampleRate)
            p.set_param("audioSampleRate", convert_from<std::string>(input.audioSampleRate.value()));
        if(input.maxAudioBitDepth)
            p.set_param("maxAudioBitDepth", convert_from<std::string>(input.maxAudioBitDepth.value()));
        if(input.maxStreamingBitrate)
            p.set_param("maxStreamingBitrate", convert_from<std::string>(input.maxStreamingBitrate.value()));
        if(input.audioBitRate)
            p.set_param("audioBitRate", convert_from<std::string>(input.audioBitRate.value()));
        if(input.audioChannels)
            p.set_param("audioChannels", convert_from<std::string>(input.audioChannels.value()));
        if(input.maxAudioChannels)
            p.set_param("maxAudioChannels", convert_from<std::string>(input.maxAudioChannels.value()));
        if(input.profile)
            p.set_param("profile", convert_from<std::string>(input.profile.value()));
        if(input.level)
            p.set_param("level", convert_from<std::string>(input.level.value()));
        if(input.framerate)
            p.set_param("framerate", convert_from<std::string>(input.framerate.value()));
        if(input.maxFramerate)
            p.set_param("maxFramerate", convert_from<std::string>(input.maxFramerate.value()));
        if(input.copyTimestamps)
            p.set_param("copyTimestamps", convert_from<std::string>(input.copyTimestamps.value()));
        if(input.startTimeTicks)
            p.set_param("startTimeTicks", convert_from<std::string>(input.startTimeTicks.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.videoBitRate)
            p.set_param("videoBitRate", convert_from<std::string>(input.videoBitRate.value()));
        if(input.subtitleStreamIndex)
            p.set_param("subtitleStreamIndex", convert_from<std::string>(input.subtitleStreamIndex.value()));
        if(input.subtitleMethod)
            p.set_param("subtitleMethod", convert_from<std::string>(input.subtitleMethod.value()));
        if(input.maxRefFrames)
            p.set_param("maxRefFrames", convert_from<std::string>(input.maxRefFrames.value()));
        if(input.maxVideoBitDepth)
            p.set_param("maxVideoBitDepth", convert_from<std::string>(input.maxVideoBitDepth.value()));
        if(input.requireAvc)
            p.set_param("requireAvc", convert_from<std::string>(input.requireAvc.value()));
        if(input.deInterlace)
            p.set_param("deInterlace", convert_from<std::string>(input.deInterlace.value()));
        if(input.requireNonAnamorphic)
            p.set_param("requireNonAnamorphic", convert_from<std::string>(input.requireNonAnamorphic.value()));
        if(input.transcodingMaxAudioChannels)
            p.set_param("transcodingMaxAudioChannels", convert_from<std::string>(input.transcodingMaxAudioChannels.value()));
        if(input.cpuCoreLimit)
            p.set_param("cpuCoreLimit", convert_from<std::string>(input.cpuCoreLimit.value()));
        if(input.liveStreamId)
            p.set_param("liveStreamId", convert_from<std::string>(input.liveStreamId.value()));
        if(input.enableMpegtsM2TsMode)
            p.set_param("enableMpegtsM2TsMode", convert_from<std::string>(input.enableMpegtsM2TsMode.value()));
        if(input.videoCodec)
            p.set_param("videoCodec", convert_from<std::string>(input.videoCodec.value()));
        if(input.subtitleCodec)
            p.set_param("subtitleCodec", convert_from<std::string>(input.subtitleCodec.value()));
        if(input.transcodeReasons)
            p.set_param("transcodeReasons", convert_from<std::string>(input.transcodeReasons.value()));
        if(input.audioStreamIndex)
            p.set_param("audioStreamIndex", convert_from<std::string>(input.audioStreamIndex.value()));
        if(input.videoStreamIndex)
            p.set_param("videoStreamIndex", convert_from<std::string>(input.videoStreamIndex.value()));
        if(input.context)
            p.set_param("context", convert_from<std::string>(input.context.value()));
        if(input.streamOptions)
            p.set_param("streamOptions", input.streamOptions.value());
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
 * baseName: DynamicHls
 * defaultResponse: {}
 */
};
// Gets a video stream using HTTP live streaming.
struct getVariantHlsVideoPlaylist {
public:
    using in_type                      = param::getVariantHlsVideoPlaylist;
    using out_type                     = model::return_type_getVariantHlsVideoPlaylist;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Videos/{}/main.m3u8"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input._static)
            p.set_param("_static", convert_from<std::string>(input._static.value()));
        if(input.params)
            p.set_param("params", convert_from<std::string>(input.params.value()));
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.deviceProfileId)
            p.set_param("deviceProfileId", convert_from<std::string>(input.deviceProfileId.value()));
        if(input.playSessionId)
            p.set_param("playSessionId", convert_from<std::string>(input.playSessionId.value()));
        if(input.segmentContainer)
            p.set_param("segmentContainer", convert_from<std::string>(input.segmentContainer.value()));
        if(input.segmentLength)
            p.set_param("segmentLength", convert_from<std::string>(input.segmentLength.value()));
        if(input.minSegments)
            p.set_param("minSegments", convert_from<std::string>(input.minSegments.value()));
        if(input.mediaSourceId)
            p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId.value()));
        if(input.deviceId)
            p.set_param("deviceId", convert_from<std::string>(input.deviceId.value()));
        if(input.audioCodec)
            p.set_param("audioCodec", convert_from<std::string>(input.audioCodec.value()));
        if(input.enableAutoStreamCopy)
            p.set_param("enableAutoStreamCopy", convert_from<std::string>(input.enableAutoStreamCopy.value()));
        if(input.allowVideoStreamCopy)
            p.set_param("allowVideoStreamCopy", convert_from<std::string>(input.allowVideoStreamCopy.value()));
        if(input.allowAudioStreamCopy)
            p.set_param("allowAudioStreamCopy", convert_from<std::string>(input.allowAudioStreamCopy.value()));
        if(input.breakOnNonKeyFrames)
            p.set_param("breakOnNonKeyFrames", convert_from<std::string>(input.breakOnNonKeyFrames.value()));
        if(input.audioSampleRate)
            p.set_param("audioSampleRate", convert_from<std::string>(input.audioSampleRate.value()));
        if(input.maxAudioBitDepth)
            p.set_param("maxAudioBitDepth", convert_from<std::string>(input.maxAudioBitDepth.value()));
        if(input.audioBitRate)
            p.set_param("audioBitRate", convert_from<std::string>(input.audioBitRate.value()));
        if(input.audioChannels)
            p.set_param("audioChannels", convert_from<std::string>(input.audioChannels.value()));
        if(input.maxAudioChannels)
            p.set_param("maxAudioChannels", convert_from<std::string>(input.maxAudioChannels.value()));
        if(input.profile)
            p.set_param("profile", convert_from<std::string>(input.profile.value()));
        if(input.level)
            p.set_param("level", convert_from<std::string>(input.level.value()));
        if(input.framerate)
            p.set_param("framerate", convert_from<std::string>(input.framerate.value()));
        if(input.maxFramerate)
            p.set_param("maxFramerate", convert_from<std::string>(input.maxFramerate.value()));
        if(input.copyTimestamps)
            p.set_param("copyTimestamps", convert_from<std::string>(input.copyTimestamps.value()));
        if(input.startTimeTicks)
            p.set_param("startTimeTicks", convert_from<std::string>(input.startTimeTicks.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.videoBitRate)
            p.set_param("videoBitRate", convert_from<std::string>(input.videoBitRate.value()));
        if(input.subtitleStreamIndex)
            p.set_param("subtitleStreamIndex", convert_from<std::string>(input.subtitleStreamIndex.value()));
        if(input.subtitleMethod)
            p.set_param("subtitleMethod", convert_from<std::string>(input.subtitleMethod.value()));
        if(input.maxRefFrames)
            p.set_param("maxRefFrames", convert_from<std::string>(input.maxRefFrames.value()));
        if(input.maxVideoBitDepth)
            p.set_param("maxVideoBitDepth", convert_from<std::string>(input.maxVideoBitDepth.value()));
        if(input.requireAvc)
            p.set_param("requireAvc", convert_from<std::string>(input.requireAvc.value()));
        if(input.deInterlace)
            p.set_param("deInterlace", convert_from<std::string>(input.deInterlace.value()));
        if(input.requireNonAnamorphic)
            p.set_param("requireNonAnamorphic", convert_from<std::string>(input.requireNonAnamorphic.value()));
        if(input.transcodingMaxAudioChannels)
            p.set_param("transcodingMaxAudioChannels", convert_from<std::string>(input.transcodingMaxAudioChannels.value()));
        if(input.cpuCoreLimit)
            p.set_param("cpuCoreLimit", convert_from<std::string>(input.cpuCoreLimit.value()));
        if(input.liveStreamId)
            p.set_param("liveStreamId", convert_from<std::string>(input.liveStreamId.value()));
        if(input.enableMpegtsM2TsMode)
            p.set_param("enableMpegtsM2TsMode", convert_from<std::string>(input.enableMpegtsM2TsMode.value()));
        if(input.videoCodec)
            p.set_param("videoCodec", convert_from<std::string>(input.videoCodec.value()));
        if(input.subtitleCodec)
            p.set_param("subtitleCodec", convert_from<std::string>(input.subtitleCodec.value()));
        if(input.transcodeReasons)
            p.set_param("transcodeReasons", convert_from<std::string>(input.transcodeReasons.value()));
        if(input.audioStreamIndex)
            p.set_param("audioStreamIndex", convert_from<std::string>(input.audioStreamIndex.value()));
        if(input.videoStreamIndex)
            p.set_param("videoStreamIndex", convert_from<std::string>(input.videoStreamIndex.value()));
        if(input.context)
            p.set_param("context", convert_from<std::string>(input.context.value()));
        if(input.streamOptions)
            p.set_param("streamOptions", input.streamOptions.value());
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
 * baseName: DynamicHls
 * defaultResponse: {}
 */
};
// Gets an audio hls playlist stream.
struct headMasterHlsAudioPlaylist {
public:
    using in_type                      = param::headMasterHlsAudioPlaylist;
    using out_type                     = model::return_type_headMasterHlsAudioPlaylist;
    constexpr static Operation  oper   = Operation::HEAD;
    auto path() const { 
        return fmt::format("/Audio/{}/master.m3u8"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input._static)
            p.set_param("_static", convert_from<std::string>(input._static.value()));
        if(input.params)
            p.set_param("params", convert_from<std::string>(input.params.value()));
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.deviceProfileId)
            p.set_param("deviceProfileId", convert_from<std::string>(input.deviceProfileId.value()));
        if(input.playSessionId)
            p.set_param("playSessionId", convert_from<std::string>(input.playSessionId.value()));
        if(input.segmentContainer)
            p.set_param("segmentContainer", convert_from<std::string>(input.segmentContainer.value()));
        if(input.segmentLength)
            p.set_param("segmentLength", convert_from<std::string>(input.segmentLength.value()));
        if(input.minSegments)
            p.set_param("minSegments", convert_from<std::string>(input.minSegments.value()));
        p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId));
        if(input.deviceId)
            p.set_param("deviceId", convert_from<std::string>(input.deviceId.value()));
        if(input.audioCodec)
            p.set_param("audioCodec", convert_from<std::string>(input.audioCodec.value()));
        if(input.enableAutoStreamCopy)
            p.set_param("enableAutoStreamCopy", convert_from<std::string>(input.enableAutoStreamCopy.value()));
        if(input.allowVideoStreamCopy)
            p.set_param("allowVideoStreamCopy", convert_from<std::string>(input.allowVideoStreamCopy.value()));
        if(input.allowAudioStreamCopy)
            p.set_param("allowAudioStreamCopy", convert_from<std::string>(input.allowAudioStreamCopy.value()));
        if(input.breakOnNonKeyFrames)
            p.set_param("breakOnNonKeyFrames", convert_from<std::string>(input.breakOnNonKeyFrames.value()));
        if(input.audioSampleRate)
            p.set_param("audioSampleRate", convert_from<std::string>(input.audioSampleRate.value()));
        if(input.maxAudioBitDepth)
            p.set_param("maxAudioBitDepth", convert_from<std::string>(input.maxAudioBitDepth.value()));
        if(input.maxStreamingBitrate)
            p.set_param("maxStreamingBitrate", convert_from<std::string>(input.maxStreamingBitrate.value()));
        if(input.audioBitRate)
            p.set_param("audioBitRate", convert_from<std::string>(input.audioBitRate.value()));
        if(input.audioChannels)
            p.set_param("audioChannels", convert_from<std::string>(input.audioChannels.value()));
        if(input.maxAudioChannels)
            p.set_param("maxAudioChannels", convert_from<std::string>(input.maxAudioChannels.value()));
        if(input.profile)
            p.set_param("profile", convert_from<std::string>(input.profile.value()));
        if(input.level)
            p.set_param("level", convert_from<std::string>(input.level.value()));
        if(input.framerate)
            p.set_param("framerate", convert_from<std::string>(input.framerate.value()));
        if(input.maxFramerate)
            p.set_param("maxFramerate", convert_from<std::string>(input.maxFramerate.value()));
        if(input.copyTimestamps)
            p.set_param("copyTimestamps", convert_from<std::string>(input.copyTimestamps.value()));
        if(input.startTimeTicks)
            p.set_param("startTimeTicks", convert_from<std::string>(input.startTimeTicks.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.videoBitRate)
            p.set_param("videoBitRate", convert_from<std::string>(input.videoBitRate.value()));
        if(input.subtitleStreamIndex)
            p.set_param("subtitleStreamIndex", convert_from<std::string>(input.subtitleStreamIndex.value()));
        if(input.subtitleMethod)
            p.set_param("subtitleMethod", convert_from<std::string>(input.subtitleMethod.value()));
        if(input.maxRefFrames)
            p.set_param("maxRefFrames", convert_from<std::string>(input.maxRefFrames.value()));
        if(input.maxVideoBitDepth)
            p.set_param("maxVideoBitDepth", convert_from<std::string>(input.maxVideoBitDepth.value()));
        if(input.requireAvc)
            p.set_param("requireAvc", convert_from<std::string>(input.requireAvc.value()));
        if(input.deInterlace)
            p.set_param("deInterlace", convert_from<std::string>(input.deInterlace.value()));
        if(input.requireNonAnamorphic)
            p.set_param("requireNonAnamorphic", convert_from<std::string>(input.requireNonAnamorphic.value()));
        if(input.transcodingMaxAudioChannels)
            p.set_param("transcodingMaxAudioChannels", convert_from<std::string>(input.transcodingMaxAudioChannels.value()));
        if(input.cpuCoreLimit)
            p.set_param("cpuCoreLimit", convert_from<std::string>(input.cpuCoreLimit.value()));
        if(input.liveStreamId)
            p.set_param("liveStreamId", convert_from<std::string>(input.liveStreamId.value()));
        if(input.enableMpegtsM2TsMode)
            p.set_param("enableMpegtsM2TsMode", convert_from<std::string>(input.enableMpegtsM2TsMode.value()));
        if(input.videoCodec)
            p.set_param("videoCodec", convert_from<std::string>(input.videoCodec.value()));
        if(input.subtitleCodec)
            p.set_param("subtitleCodec", convert_from<std::string>(input.subtitleCodec.value()));
        if(input.transcodeReasons)
            p.set_param("transcodeReasons", convert_from<std::string>(input.transcodeReasons.value()));
        if(input.audioStreamIndex)
            p.set_param("audioStreamIndex", convert_from<std::string>(input.audioStreamIndex.value()));
        if(input.videoStreamIndex)
            p.set_param("videoStreamIndex", convert_from<std::string>(input.videoStreamIndex.value()));
        if(input.context)
            p.set_param("context", convert_from<std::string>(input.context.value()));
        if(input.streamOptions)
            p.set_param("streamOptions", input.streamOptions.value());
        if(input.enableAdaptiveBitrateStreaming)
            p.set_param("enableAdaptiveBitrateStreaming", convert_from<std::string>(input.enableAdaptiveBitrateStreaming.value()));
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
 * baseName: DynamicHls
 * defaultResponse: {}
 */
};
// Gets a video hls playlist stream.
struct headMasterHlsVideoPlaylist {
public:
    using in_type                      = param::headMasterHlsVideoPlaylist;
    using out_type                     = model::return_type_headMasterHlsVideoPlaylist;
    constexpr static Operation  oper   = Operation::HEAD;
    auto path() const { 
        return fmt::format("/Videos/{}/master.m3u8"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input._static)
            p.set_param("_static", convert_from<std::string>(input._static.value()));
        if(input.params)
            p.set_param("params", convert_from<std::string>(input.params.value()));
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.deviceProfileId)
            p.set_param("deviceProfileId", convert_from<std::string>(input.deviceProfileId.value()));
        if(input.playSessionId)
            p.set_param("playSessionId", convert_from<std::string>(input.playSessionId.value()));
        if(input.segmentContainer)
            p.set_param("segmentContainer", convert_from<std::string>(input.segmentContainer.value()));
        if(input.segmentLength)
            p.set_param("segmentLength", convert_from<std::string>(input.segmentLength.value()));
        if(input.minSegments)
            p.set_param("minSegments", convert_from<std::string>(input.minSegments.value()));
        p.set_param("mediaSourceId", convert_from<std::string>(input.mediaSourceId));
        if(input.deviceId)
            p.set_param("deviceId", convert_from<std::string>(input.deviceId.value()));
        if(input.audioCodec)
            p.set_param("audioCodec", convert_from<std::string>(input.audioCodec.value()));
        if(input.enableAutoStreamCopy)
            p.set_param("enableAutoStreamCopy", convert_from<std::string>(input.enableAutoStreamCopy.value()));
        if(input.allowVideoStreamCopy)
            p.set_param("allowVideoStreamCopy", convert_from<std::string>(input.allowVideoStreamCopy.value()));
        if(input.allowAudioStreamCopy)
            p.set_param("allowAudioStreamCopy", convert_from<std::string>(input.allowAudioStreamCopy.value()));
        if(input.breakOnNonKeyFrames)
            p.set_param("breakOnNonKeyFrames", convert_from<std::string>(input.breakOnNonKeyFrames.value()));
        if(input.audioSampleRate)
            p.set_param("audioSampleRate", convert_from<std::string>(input.audioSampleRate.value()));
        if(input.maxAudioBitDepth)
            p.set_param("maxAudioBitDepth", convert_from<std::string>(input.maxAudioBitDepth.value()));
        if(input.audioBitRate)
            p.set_param("audioBitRate", convert_from<std::string>(input.audioBitRate.value()));
        if(input.audioChannels)
            p.set_param("audioChannels", convert_from<std::string>(input.audioChannels.value()));
        if(input.maxAudioChannels)
            p.set_param("maxAudioChannels", convert_from<std::string>(input.maxAudioChannels.value()));
        if(input.profile)
            p.set_param("profile", convert_from<std::string>(input.profile.value()));
        if(input.level)
            p.set_param("level", convert_from<std::string>(input.level.value()));
        if(input.framerate)
            p.set_param("framerate", convert_from<std::string>(input.framerate.value()));
        if(input.maxFramerate)
            p.set_param("maxFramerate", convert_from<std::string>(input.maxFramerate.value()));
        if(input.copyTimestamps)
            p.set_param("copyTimestamps", convert_from<std::string>(input.copyTimestamps.value()));
        if(input.startTimeTicks)
            p.set_param("startTimeTicks", convert_from<std::string>(input.startTimeTicks.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.videoBitRate)
            p.set_param("videoBitRate", convert_from<std::string>(input.videoBitRate.value()));
        if(input.subtitleStreamIndex)
            p.set_param("subtitleStreamIndex", convert_from<std::string>(input.subtitleStreamIndex.value()));
        if(input.subtitleMethod)
            p.set_param("subtitleMethod", convert_from<std::string>(input.subtitleMethod.value()));
        if(input.maxRefFrames)
            p.set_param("maxRefFrames", convert_from<std::string>(input.maxRefFrames.value()));
        if(input.maxVideoBitDepth)
            p.set_param("maxVideoBitDepth", convert_from<std::string>(input.maxVideoBitDepth.value()));
        if(input.requireAvc)
            p.set_param("requireAvc", convert_from<std::string>(input.requireAvc.value()));
        if(input.deInterlace)
            p.set_param("deInterlace", convert_from<std::string>(input.deInterlace.value()));
        if(input.requireNonAnamorphic)
            p.set_param("requireNonAnamorphic", convert_from<std::string>(input.requireNonAnamorphic.value()));
        if(input.transcodingMaxAudioChannels)
            p.set_param("transcodingMaxAudioChannels", convert_from<std::string>(input.transcodingMaxAudioChannels.value()));
        if(input.cpuCoreLimit)
            p.set_param("cpuCoreLimit", convert_from<std::string>(input.cpuCoreLimit.value()));
        if(input.liveStreamId)
            p.set_param("liveStreamId", convert_from<std::string>(input.liveStreamId.value()));
        if(input.enableMpegtsM2TsMode)
            p.set_param("enableMpegtsM2TsMode", convert_from<std::string>(input.enableMpegtsM2TsMode.value()));
        if(input.videoCodec)
            p.set_param("videoCodec", convert_from<std::string>(input.videoCodec.value()));
        if(input.subtitleCodec)
            p.set_param("subtitleCodec", convert_from<std::string>(input.subtitleCodec.value()));
        if(input.transcodeReasons)
            p.set_param("transcodeReasons", convert_from<std::string>(input.transcodeReasons.value()));
        if(input.audioStreamIndex)
            p.set_param("audioStreamIndex", convert_from<std::string>(input.audioStreamIndex.value()));
        if(input.videoStreamIndex)
            p.set_param("videoStreamIndex", convert_from<std::string>(input.videoStreamIndex.value()));
        if(input.context)
            p.set_param("context", convert_from<std::string>(input.context.value()));
        if(input.streamOptions)
            p.set_param("streamOptions", input.streamOptions.value());
        if(input.enableAdaptiveBitrateStreaming)
            p.set_param("enableAdaptiveBitrateStreaming", convert_from<std::string>(input.enableAdaptiveBitrateStreaming.value()));
        if(input.enableTrickplay)
            p.set_param("enableTrickplay", convert_from<std::string>(input.enableTrickplay.value()));
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
 * baseName: DynamicHls
 * defaultResponse: {}
 */
};
}
}
