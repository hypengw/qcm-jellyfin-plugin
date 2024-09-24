#pragma once

/*
 * OAIOpenLiveStreamDto.h
 * name: OpenLiveStreamDto
 * schemaName: OpenLiveStreamDto
 * classFilename: OpenLiveStreamDto
 * classVarName: OpenLiveStreamDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Open live stream dto.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIDeviceProfile.h"
#include "jellyfin/model/OAIMediaProtocol.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIDeviceProfile;


    class OAIOpenLiveStreamDto {
    public:
    
        // Gets or sets the open token.
        std::optional<std::string> OpenToken;

        // Gets or sets the user id.
        std::optional<std::string> UserId;

        // Gets or sets the play session id.
        std::optional<std::string> PlaySessionId;

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

        // Gets or sets the item id.
        std::optional<std::string> ItemId;

        // Gets or sets a value indicating whether to enable direct play.
        std::optional<bool> EnableDirectPlay;

        // Gets or sets a value indicating whether to enale direct stream.
        std::optional<bool> EnableDirectStream;

        // Gets or sets the device profile.
        std::optional<OAIDeviceProfile> DeviceProfile;

        // Gets or sets the device play protocols.
        std::vector<OAIMediaProtocol> DirectPlayProtocols;

        OAIOpenLiveStreamDto();
        ~OAIOpenLiveStreamDto();
    };
    extern void to_json(json_t&, const OAIOpenLiveStreamDto&);
    extern void from_json(const json_t&, OAIOpenLiveStreamDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIOpenLiveStreamDto);
