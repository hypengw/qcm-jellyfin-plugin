#pragma once

/*
 * OAITranscodingInfo.h
 * name: TranscodingInfo
 * schemaName: TranscodingInfo
 * classFilename: TranscodingInfo
 * classVarName: TranscodingInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIHardwareEncodingType.h"
#include "jellyfin/model/OAITranscodeReason.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {


    class OAITranscodingInfo {
    public:
    
        std::optional<std::string> AudioCodec;

        std::optional<std::string> VideoCodec;

        std::optional<std::string> Container;

        bool IsVideoDirect;

        bool IsAudioDirect;

        std::optional<std::int32_t> Bitrate;

        std::optional<float> Framerate;

        std::optional<double> CompletionPercentage;

        std::optional<std::int32_t> Width;

        std::optional<std::int32_t> Height;

        std::optional<std::int32_t> AudioChannels;

        std::optional<OAIHardwareEncodingType> HardwareAccelerationType;

        std::vector<OAITranscodeReason> TranscodeReasons;

        OAITranscodingInfo();
        ~OAITranscodingInfo();
    };
    extern void to_json(json_t&, const OAITranscodingInfo&);
    extern void from_json(const json_t&, OAITranscodingInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITranscodingInfo);
