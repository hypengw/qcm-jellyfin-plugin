#pragma once

/*
 * OAIPlaybackInfoDto.h
 * name: PlaybackInfoDto
 * schemaName: PlaybackInfoDto
 * classFilename: PlaybackInfoDto
 * classVarName: PlaybackInfoDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Plabyback info dto.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIDeviceProfile.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {
class OAIDeviceProfile;


    class OAIPlaybackInfoDto {
    public:
    
        // Gets or sets the playback userId.
        std::optional<std::string> UserId;

        // Gets or sets the max streaming bitrate.
        std::optional<std::int32_t> MaxStreamingBitrate;

        // Gets or sets the start time in ticks.
        std::optional<std::int64_t> StartTimeTicks;

        // Gets or sets the audio stream index.
        std::optional<std::int32_t> AudioStreamIndex;

        // Gets or sets the subtitle stream index.
        std::optional<std::int32_t> SubtitleStreamIndex;

        // Gets or sets the max audio channels.
        std::optional<std::int32_t> MaxAudioChannels;

        // Gets or sets the media source id.
        std::optional<std::string> MediaSourceId;

        // Gets or sets the live stream id.
        std::optional<std::string> LiveStreamId;

        // Gets or sets the device profile.
        std::optional<OAIDeviceProfile> DeviceProfile;

        // Gets or sets a value indicating whether to enable direct play.
        std::optional<bool> EnableDirectPlay;

        // Gets or sets a value indicating whether to enable direct stream.
        std::optional<bool> EnableDirectStream;

        // Gets or sets a value indicating whether to enable transcoding.
        std::optional<bool> EnableTranscoding;

        // Gets or sets a value indicating whether to enable video stream copy.
        std::optional<bool> AllowVideoStreamCopy;

        // Gets or sets a value indicating whether to allow audio stream copy.
        std::optional<bool> AllowAudioStreamCopy;

        // Gets or sets a value indicating whether to auto open the live stream.
        std::optional<bool> AutoOpenLiveStream;

        OAIPlaybackInfoDto();
        ~OAIPlaybackInfoDto();
    };
    extern void to_json(json_t&, const OAIPlaybackInfoDto&);
    extern void from_json(const json_t&, OAIPlaybackInfoDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlaybackInfoDto);
