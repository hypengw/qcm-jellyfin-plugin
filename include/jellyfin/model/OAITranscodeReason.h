#pragma once

/*
 * OAITranscodeReason.h
 * name: TranscodeReason
 * schemaName: TranscodeReason
 * classFilename: TranscodeReason
 * classVarName: TranscodeReason
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAITranscodeReason {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        CONTAINERNOTSUPPORTED, // ContainerNotSupported
        VIDEOCODECNOTSUPPORTED, // VideoCodecNotSupported
        AUDIOCODECNOTSUPPORTED, // AudioCodecNotSupported
        SUBTITLECODECNOTSUPPORTED, // SubtitleCodecNotSupported
        AUDIOISEXTERNAL, // AudioIsExternal
        SECONDARYAUDIONOTSUPPORTED, // SecondaryAudioNotSupported
        VIDEOPROFILENOTSUPPORTED, // VideoProfileNotSupported
        VIDEOLEVELNOTSUPPORTED, // VideoLevelNotSupported
        VIDEORESOLUTIONNOTSUPPORTED, // VideoResolutionNotSupported
        VIDEOBITDEPTHNOTSUPPORTED, // VideoBitDepthNotSupported
        VIDEOFRAMERATENOTSUPPORTED, // VideoFramerateNotSupported
        REFFRAMESNOTSUPPORTED, // RefFramesNotSupported
        ANAMORPHICVIDEONOTSUPPORTED, // AnamorphicVideoNotSupported
        INTERLACEDVIDEONOTSUPPORTED, // InterlacedVideoNotSupported
        AUDIOCHANNELSNOTSUPPORTED, // AudioChannelsNotSupported
        AUDIOPROFILENOTSUPPORTED, // AudioProfileNotSupported
        AUDIOSAMPLERATENOTSUPPORTED, // AudioSampleRateNotSupported
        AUDIOBITDEPTHNOTSUPPORTED, // AudioBitDepthNotSupported
        CONTAINERBITRATEEXCEEDSLIMIT, // ContainerBitrateExceedsLimit
        VIDEOBITRATENOTSUPPORTED, // VideoBitrateNotSupported
        AUDIOBITRATENOTSUPPORTED, // AudioBitrateNotSupported
        UNKNOWNVIDEOSTREAMINFO, // UnknownVideoStreamInfo
        UNKNOWNAUDIOSTREAMINFO, // UnknownAudioStreamInfo
        DIRECTPLAYERROR, // DirectPlayError
        VIDEORANGETYPENOTSUPPORTED, // VideoRangeTypeNotSupported
    };
    extern void to_json(json_t&, const OAITranscodeReason&);
    extern void from_json(const json_t&, OAITranscodeReason&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITranscodeReason);
