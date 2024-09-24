#pragma once

/*
 * OAIClientCapabilitiesDto.h
 * name: ClientCapabilitiesDto
 * schemaName: ClientCapabilitiesDto
 * classFilename: ClientCapabilitiesDto
 * classVarName: ClientCapabilitiesDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Client capabilities dto.
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


    class OAIClientCapabilitiesDto {
    public:
    
        // Gets or sets the list of playable media types.
        std::vector<OAIMediaType> PlayableMediaTypes;

        // Gets or sets the list of supported commands.
        std::vector<OAIGeneralCommandType> SupportedCommands;

        // Gets or sets a value indicating whether session supports media control.
        bool SupportsMediaControl;

        // Gets or sets a value indicating whether session supports a persistent identifier.
        bool SupportsPersistentIdentifier;

        // Gets or sets the device profile.
        std::optional<OAIDeviceProfile> DeviceProfile;

        // Gets or sets the app store url.
        std::optional<std::string> AppStoreUrl;

        // Gets or sets the icon url.
        std::optional<std::string> IconUrl;

        [[deprecated]] std::optional<bool> SupportsContentUploading;

        [[deprecated]] std::optional<bool> SupportsSync;

        OAIClientCapabilitiesDto();
        ~OAIClientCapabilitiesDto();
    };
    extern void to_json(json_t&, const OAIClientCapabilitiesDto&);
    extern void from_json(const json_t&, OAIClientCapabilitiesDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIClientCapabilitiesDto);
