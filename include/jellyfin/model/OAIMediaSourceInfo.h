#pragma once

/*
 * OAIMediaSourceInfo.h
 * name: MediaSourceInfo
 * schemaName: MediaSourceInfo
 * classFilename: MediaSourceInfo
 * classVarName: MediaSourceInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIIsoType.h"
#include "jellyfin/model/OAIMediaAttachment.h"
#include "jellyfin/model/OAIMediaProtocol.h"
#include "jellyfin/model/OAIMediaSourceType.h"
#include "jellyfin/model/OAIMediaStream.h"
#include "jellyfin/model/OAIMediaStreamProtocol.h"
#include "jellyfin/model/OAITransportStreamTimestamp.h"
#include "jellyfin/model/OAIVideo3DFormat.h"
#include "jellyfin/model/OAIVideoType.h"
#include <cstdint>
#include <map>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIMediaStream;
class OAIMediaAttachment;


    class OAIMediaSourceInfo {
    public:
    
        OAIMediaProtocol Protocol;

        std::optional<std::string> Id;

        std::optional<std::string> Path;

        std::optional<std::string> EncoderPath;

        std::optional<OAIMediaProtocol> EncoderProtocol;

        OAIMediaSourceType Type;

        std::optional<std::string> Container;

        std::optional<std::int64_t> Size;

        std::optional<std::string> Name;

        // Gets or sets a value indicating whether the media is remote.  Differentiate internet url vs local network.
        bool IsRemote;

        std::optional<std::string> ETag;

        std::optional<std::int64_t> RunTimeTicks;

        bool ReadAtNativeFramerate;

        bool IgnoreDts;

        bool IgnoreIndex;

        bool GenPtsInput;

        bool SupportsTranscoding;

        bool SupportsDirectStream;

        bool SupportsDirectPlay;

        bool IsInfiniteStream;

        bool RequiresOpening;

        std::optional<std::string> OpenToken;

        bool RequiresClosing;

        std::optional<std::string> LiveStreamId;

        std::optional<std::int32_t> BufferMs;

        bool RequiresLooping;

        bool SupportsProbing;

        std::optional<OAIVideoType> VideoType;

        std::optional<OAIIsoType> IsoType;

        std::optional<OAIVideo3DFormat> Video3DFormat;

        std::optional<std::vector<OAIMediaStream>> MediaStreams;

        std::optional<std::vector<OAIMediaAttachment>> MediaAttachments;

        std::optional<std::vector<std::string>> Formats;

        std::optional<std::int32_t> Bitrate;

        std::optional<OAITransportStreamTimestamp> Timestamp;

        std::optional<std::map<std::string, std::string>> RequiredHttpHeaders;

        std::optional<std::string> TranscodingUrl;

        // Media streaming protocol.  Lowercase for backwards compatibility.
        OAIMediaStreamProtocol TranscodingSubProtocol;

        std::optional<std::string> TranscodingContainer;

        std::optional<std::int32_t> AnalyzeDurationMs;

        std::optional<std::int32_t> DefaultAudioStreamIndex;

        std::optional<std::int32_t> DefaultSubtitleStreamIndex;

        OAIMediaSourceInfo();
        ~OAIMediaSourceInfo();
    };
    extern void to_json(json_t&, const OAIMediaSourceInfo&);
    extern void from_json(const json_t&, OAIMediaSourceInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMediaSourceInfo);
