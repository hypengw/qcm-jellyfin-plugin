#pragma once

/*
 * OAIEncodingOptions.h
 * name: EncodingOptions
 * schemaName: EncodingOptions
 * classFilename: EncodingOptions
 * classVarName: EncodingOptions
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class EncodingOptions.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIDownMixStereoAlgorithms.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {


    class OAIEncodingOptions {
    public:
    
        // Gets or sets the thread count used for encoding.
        std::int32_t EncodingThreadCount;

        // Gets or sets the temporary transcoding path.
        std::optional<std::string> TranscodingTempPath;

        // Gets or sets the path to the fallback font.
        std::optional<std::string> FallbackFontPath;

        // Gets or sets a value indicating whether to use the fallback font.
        bool EnableFallbackFont;

        // Gets or sets a value indicating whether audio VBR is enabled.
        bool EnableAudioVbr;

        // Gets or sets the audio boost applied when downmixing audio.
        double DownMixAudioBoost;

        // Gets or sets the algorithm used for downmixing audio to stereo.
        OAIDownMixStereoAlgorithms DownMixStereoAlgorithm;

        // Gets or sets the maximum size of the muxing queue.
        std::int32_t MaxMuxingQueueSize;

        // Gets or sets a value indicating whether throttling is enabled.
        bool EnableThrottling;

        // Gets or sets the delay after which throttling happens.
        std::int32_t ThrottleDelaySeconds;

        // Gets or sets a value indicating whether segment deletion is enabled.
        bool EnableSegmentDeletion;

        // Gets or sets seconds for which segments should be kept before being deleted.
        std::int32_t SegmentKeepSeconds;

        // Gets or sets the hardware acceleration type.
        std::optional<std::string> HardwareAccelerationType;

        // Gets or sets the FFmpeg path as set by the user via the UI.
        std::optional<std::string> EncoderAppPath;

        // Gets or sets the current FFmpeg path being used by the system and displayed on the transcode page.
        std::optional<std::string> EncoderAppPathDisplay;

        // Gets or sets the VA-API device.
        std::optional<std::string> VaapiDevice;

        // Gets or sets a value indicating whether tonemapping is enabled.
        bool EnableTonemapping;

        // Gets or sets a value indicating whether VPP tonemapping is enabled.
        bool EnableVppTonemapping;

        // Gets or sets a value indicating whether videotoolbox tonemapping is enabled.
        bool EnableVideoToolboxTonemapping;

        // Gets or sets the tone-mapping algorithm.
        std::optional<std::string> TonemappingAlgorithm;

        // Gets or sets the tone-mapping mode.
        std::optional<std::string> TonemappingMode;

        // Gets or sets the tone-mapping range.
        std::optional<std::string> TonemappingRange;

        // Gets or sets the tone-mapping desaturation.
        double TonemappingDesat;

        // Gets or sets the tone-mapping peak.
        double TonemappingPeak;

        // Gets or sets the tone-mapping parameters.
        double TonemappingParam;

        // Gets or sets the VPP tone-mapping brightness.
        double VppTonemappingBrightness;

        // Gets or sets the VPP tone-mapping contrast.
        double VppTonemappingContrast;

        // Gets or sets the H264 CRF.
        std::int32_t H264Crf;

        // Gets or sets the H265 CRF.
        std::int32_t H265Crf;

        // Gets or sets the encoder preset.
        std::optional<std::string> EncoderPreset;

        // Gets or sets a value indicating whether the framerate is doubled when deinterlacing.
        bool DeinterlaceDoubleRate;

        // Gets or sets the deinterlace method.
        std::optional<std::string> DeinterlaceMethod;

        // Gets or sets a value indicating whether 10bit HEVC decoding is enabled.
        bool EnableDecodingColorDepth10Hevc;

        // Gets or sets a value indicating whether 10bit VP9 decoding is enabled.
        bool EnableDecodingColorDepth10Vp9;

        // Gets or sets a value indicating whether the enhanced NVDEC is enabled.
        bool EnableEnhancedNvdecDecoder;

        // Gets or sets a value indicating whether the system native hardware decoder should be used.
        bool PreferSystemNativeHwDecoder;

        // Gets or sets a value indicating whether the Intel H264 low-power hardware encoder should be used.
        bool EnableIntelLowPowerH264HwEncoder;

        // Gets or sets a value indicating whether the Intel HEVC low-power hardware encoder should be used.
        bool EnableIntelLowPowerHevcHwEncoder;

        // Gets or sets a value indicating whether hardware encoding is enabled.
        bool EnableHardwareEncoding;

        // Gets or sets a value indicating whether HEVC encoding is enabled.
        bool AllowHevcEncoding;

        // Gets or sets a value indicating whether AV1 encoding is enabled.
        bool AllowAv1Encoding;

        // Gets or sets a value indicating whether subtitle extraction is enabled.
        bool EnableSubtitleExtraction;

        // Gets or sets the codecs hardware encoding is used for.
        std::optional<std::vector<std::string>> HardwareDecodingCodecs;

        // Gets or sets the file extensions on-demand metadata based keyframe extraction is enabled for.
        std::optional<std::vector<std::string>> AllowOnDemandMetadataBasedKeyframeExtractionForExtensions;

        OAIEncodingOptions();
        ~OAIEncodingOptions();
    };
    extern void to_json(json_t&, const OAIEncodingOptions&);
    extern void from_json(const json_t&, OAIEncodingOptions&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIEncodingOptions);
