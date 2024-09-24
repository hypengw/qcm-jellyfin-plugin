#pragma once

/*
 * OAIMediaStream.h
 * name: MediaStream
 * schemaName: MediaStream
 * classFilename: MediaStream
 * classVarName: MediaStream
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class MediaStream.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIAudioSpatialFormat.h"
#include "jellyfin/model/OAIMediaStreamType.h"
#include "jellyfin/model/OAISubtitleDeliveryMethod.h"
#include "jellyfin/model/OAIVideoRange.h"
#include "jellyfin/model/OAIVideoRangeType.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIMediaStream {
    public:
    
        // Gets or sets the codec.
        std::optional<std::string> Codec;

        // Gets or sets the codec tag.
        std::optional<std::string> CodecTag;

        // Gets or sets the language.
        std::optional<std::string> Language;

        // Gets or sets the color range.
        std::optional<std::string> ColorRange;

        // Gets or sets the color space.
        std::optional<std::string> ColorSpace;

        // Gets or sets the color transfer.
        std::optional<std::string> ColorTransfer;

        // Gets or sets the color primaries.
        std::optional<std::string> ColorPrimaries;

        // Gets or sets the Dolby Vision version major.
        std::optional<std::int32_t> DvVersionMajor;

        // Gets or sets the Dolby Vision version minor.
        std::optional<std::int32_t> DvVersionMinor;

        // Gets or sets the Dolby Vision profile.
        std::optional<std::int32_t> DvProfile;

        // Gets or sets the Dolby Vision level.
        std::optional<std::int32_t> DvLevel;

        // Gets or sets the Dolby Vision rpu present flag.
        std::optional<std::int32_t> RpuPresentFlag;

        // Gets or sets the Dolby Vision el present flag.
        std::optional<std::int32_t> ElPresentFlag;

        // Gets or sets the Dolby Vision bl present flag.
        std::optional<std::int32_t> BlPresentFlag;

        // Gets or sets the Dolby Vision bl signal compatibility id.
        std::optional<std::int32_t> DvBlSignalCompatibilityId;

        // Gets or sets the comment.
        std::optional<std::string> Comment;

        // Gets or sets the time base.
        std::optional<std::string> TimeBase;

        // Gets or sets the codec time base.
        std::optional<std::string> CodecTimeBase;

        // Gets or sets the title.
        std::optional<std::string> Title;

        // Gets the video range.
        OAIVideoRange VideoRange;

        // Gets the video range type.
        OAIVideoRangeType VideoRangeType;

        // Gets the video dovi title.
        std::optional<std::string> VideoDoViTitle;

        // Gets the audio spatial format.
        OAIAudioSpatialFormat AudioSpatialFormat;

        std::optional<std::string> LocalizedUndefined;

        std::optional<std::string> LocalizedDefault;

        std::optional<std::string> LocalizedForced;

        std::optional<std::string> LocalizedExternal;

        std::optional<std::string> LocalizedHearingImpaired;

        std::optional<std::string> DisplayTitle;

        std::optional<std::string> NalLengthSize;

        // Gets or sets a value indicating whether this instance is interlaced.
        bool IsInterlaced;

        std::optional<bool> IsAVC;

        // Gets or sets the channel layout.
        std::optional<std::string> ChannelLayout;

        // Gets or sets the bit rate.
        std::optional<std::int32_t> BitRate;

        // Gets or sets the bit depth.
        std::optional<std::int32_t> BitDepth;

        // Gets or sets the reference frames.
        std::optional<std::int32_t> RefFrames;

        // Gets or sets the length of the packet.
        std::optional<std::int32_t> PacketLength;

        // Gets or sets the channels.
        std::optional<std::int32_t> Channels;

        // Gets or sets the sample rate.
        std::optional<std::int32_t> SampleRate;

        // Gets or sets a value indicating whether this instance is default.
        bool IsDefault;

        // Gets or sets a value indicating whether this instance is forced.
        bool IsForced;

        // Gets or sets a value indicating whether this instance is for the hearing impaired.
        bool IsHearingImpaired;

        // Gets or sets the height.
        std::optional<std::int32_t> Height;

        // Gets or sets the width.
        std::optional<std::int32_t> Width;

        // Gets or sets the average frame rate.
        std::optional<float> AverageFrameRate;

        // Gets or sets the real frame rate.
        std::optional<float> RealFrameRate;

        // Gets or sets the profile.
        std::optional<std::string> Profile;

        // Gets or sets the type.
        OAIMediaStreamType Type;

        // Gets or sets the aspect ratio.
        std::optional<std::string> AspectRatio;

        // Gets or sets the index.
        std::int32_t Index;

        // Gets or sets the score.
        std::optional<std::int32_t> Score;

        // Gets or sets a value indicating whether this instance is external.
        bool IsExternal;

        // Gets or sets the method.
        std::optional<OAISubtitleDeliveryMethod> DeliveryMethod;

        // Gets or sets the delivery URL.
        std::optional<std::string> DeliveryUrl;

        // Gets or sets a value indicating whether this instance is external URL.
        std::optional<bool> IsExternalUrl;

        bool IsTextSubtitleStream;

        // Gets or sets a value indicating whether [supports external stream].
        bool SupportsExternalStream;

        // Gets or sets the filename.
        std::optional<std::string> Path;

        // Gets or sets the pixel format.
        std::optional<std::string> PixelFormat;

        // Gets or sets the level.
        std::optional<double> Level;

        // Gets or sets whether this instance is anamorphic.
        std::optional<bool> IsAnamorphic;

        OAIMediaStream();
        ~OAIMediaStream();
    };
    extern void to_json(json_t&, const OAIMediaStream&);
    extern void from_json(const json_t&, OAIMediaStream&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMediaStream);
