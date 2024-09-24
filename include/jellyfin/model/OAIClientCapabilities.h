#pragma once

/*
 * OAIClientCapabilities.h
 * name: ClientCapabilities
 * schemaName: ClientCapabilities
 * classFilename: ClientCapabilities
 * classVarName: ClientCapabilities
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIDeviceProfile.h"
#include "jellyfin/model/OAIGeneralCommandType.h"
#include "jellyfin/model/OAIMediaType.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIDeviceProfile;


    class OAIClientCapabilities {
    public:
    
        std::optional<std::vector<OAIMediaType>> PlayableMediaTypes;

        std::optional<std::vector<OAIGeneralCommandType>> SupportedCommands;

        bool SupportsMediaControl;

        bool SupportsPersistentIdentifier;

        // A MediaBrowser.Model.Dlna.DeviceProfile represents a set of metadata which determines which content a certain device is able to play.  &lt;br /&gt;  Specifically, it defines the supported &lt;see cref&#x3D;\&quot;P:MediaBrowser.Model.Dlna.DeviceProfile.ContainerProfiles\&quot;&gt;containers&lt;/see&gt; and  &lt;see cref&#x3D;\&quot;P:MediaBrowser.Model.Dlna.DeviceProfile.CodecProfiles\&quot;&gt;codecs&lt;/see&gt; (video and/or audio, including codec profiles and levels)  the device is able to direct play (without transcoding or remuxing),  as well as which &lt;see cref&#x3D;\&quot;P:MediaBrowser.Model.Dlna.DeviceProfile.TranscodingProfiles\&quot;&gt;containers/codecs to transcode to&lt;/see&gt; in case it isn&#39;t.
        std::optional<OAIDeviceProfile> DeviceProfile;

        std::optional<std::string> AppStoreUrl;

        std::optional<std::string> IconUrl;

        [[deprecated]] std::optional<bool> SupportsContentUploading;

        [[deprecated]] std::optional<bool> SupportsSync;

        OAIClientCapabilities();
        ~OAIClientCapabilities();
    };
    extern void to_json(json_t&, const OAIClientCapabilities&);
    extern void from_json(const json_t&, OAIClientCapabilities&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIClientCapabilities);
