#pragma once

/*
 * OAIDeviceProfile.h
 * name: DeviceProfile
 * schemaName: DeviceProfile
 * classFilename: DeviceProfile
 * classVarName: DeviceProfile
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * A MediaBrowser.Model.Dlna.DeviceProfile represents a set of metadata which determines which content a certain device is able to play.  &lt;br /&gt;  Specifically, it defines the supported &lt;see cref&#x3D;\&quot;P:MediaBrowser.Model.Dlna.DeviceProfile.ContainerProfiles\&quot;&gt;containers&lt;/see&gt; and  &lt;see cref&#x3D;\&quot;P:MediaBrowser.Model.Dlna.DeviceProfile.CodecProfiles\&quot;&gt;codecs&lt;/see&gt; (video and/or audio, including codec profiles and levels)  the device is able to direct play (without transcoding or remuxing),  as well as which &lt;see cref&#x3D;\&quot;P:MediaBrowser.Model.Dlna.DeviceProfile.TranscodingProfiles\&quot;&gt;containers/codecs to transcode to&lt;/see&gt; in case it isn&#39;t.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAICodecProfile.h"
#include "jellyfin/model/OAIContainerProfile.h"
#include "jellyfin/model/OAIDirectPlayProfile.h"
#include "jellyfin/model/OAISubtitleProfile.h"
#include "jellyfin/model/OAITranscodingProfile.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIDirectPlayProfile;
class OAITranscodingProfile;
class OAIContainerProfile;
class OAICodecProfile;
class OAISubtitleProfile;


    class OAIDeviceProfile {
    public:
    
        // Gets or sets the name of this device profile.
        std::optional<std::string> Name;

        // Gets or sets the Id.
        std::optional<std::string> Id;

        // Gets or sets the maximum allowed bitrate for all streamed content.
        std::optional<std::int32_t> MaxStreamingBitrate;

        // Gets or sets the maximum allowed bitrate for statically streamed content (&#x3D; direct played files).
        std::optional<std::int32_t> MaxStaticBitrate;

        // Gets or sets the maximum allowed bitrate for transcoded music streams.
        std::optional<std::int32_t> MusicStreamingTranscodingBitrate;

        // Gets or sets the maximum allowed bitrate for statically streamed (&#x3D; direct played) music files.
        std::optional<std::int32_t> MaxStaticMusicBitrate;

        // Gets or sets the direct play profiles.
        std::vector<OAIDirectPlayProfile> DirectPlayProfiles;

        // Gets or sets the transcoding profiles.
        std::vector<OAITranscodingProfile> TranscodingProfiles;

        // Gets or sets the container profiles.
        std::vector<OAIContainerProfile> ContainerProfiles;

        // Gets or sets the codec profiles.
        std::vector<OAICodecProfile> CodecProfiles;

        // Gets or sets the subtitle profiles.
        std::vector<OAISubtitleProfile> SubtitleProfiles;

        OAIDeviceProfile();
        ~OAIDeviceProfile();
    };
    extern void to_json(json_t&, const OAIDeviceProfile&);
    extern void from_json(const json_t&, OAIDeviceProfile&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIDeviceProfile);
