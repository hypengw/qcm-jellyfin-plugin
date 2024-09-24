#pragma once

/*
 * OAITranscodingProfile.h
 * name: TranscodingProfile
 * schemaName: TranscodingProfile
 * classFilename: TranscodingProfile
 * classVarName: TranscodingProfile
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIDlnaProfileType.h"
#include "jellyfin/model/OAIEncodingContext.h"
#include "jellyfin/model/OAIMediaStreamProtocol.h"
#include "jellyfin/model/OAIProfileCondition.h"
#include "jellyfin/model/OAITranscodeSeekInfo.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIProfileCondition;


    class OAITranscodingProfile {
    public:
    
        std::string Container;

        OAIDlnaProfileType Type;

        std::string VideoCodec;

        std::string AudioCodec;

        // Media streaming protocol.  Lowercase for backwards compatibility.
        OAIMediaStreamProtocol Protocol;

        bool EstimateContentLength;

        bool EnableMpegtsM2TsMode;

        OAITranscodeSeekInfo TranscodeSeekInfo;

        bool CopyTimestamps;

        OAIEncodingContext Context;

        bool EnableSubtitlesInManifest;

        std::optional<std::string> MaxAudioChannels;

        std::int32_t MinSegments;

        std::int32_t SegmentLength;

        bool BreakOnNonKeyFrames;

        std::vector<OAIProfileCondition> Conditions;

        OAITranscodingProfile();
        ~OAITranscodingProfile();
    };
    extern void to_json(json_t&, const OAITranscodingProfile&);
    extern void from_json(const json_t&, OAITranscodingProfile&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITranscodingProfile);
