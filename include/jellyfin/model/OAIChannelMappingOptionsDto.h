#pragma once

/*
 * OAIChannelMappingOptionsDto.h
 * name: ChannelMappingOptionsDto
 * schemaName: ChannelMappingOptionsDto
 * classFilename: ChannelMappingOptionsDto
 * classVarName: ChannelMappingOptionsDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Channel mapping options dto.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAINameIdPair.h"
#include "jellyfin/model/OAINameValuePair.h"
#include "jellyfin/model/OAITunerChannelMapping.h"
#include <string>
#include <vector>



namespace jellyfin::model {
class OAITunerChannelMapping;
class OAINameIdPair;
class OAINameValuePair;


    class OAIChannelMappingOptionsDto {
    public:
    
        // Gets or sets list of tuner channels.
        std::vector<OAITunerChannelMapping> TunerChannels;

        // Gets or sets list of provider channels.
        std::vector<OAINameIdPair> ProviderChannels;

        // Gets or sets list of mappings.
        std::vector<OAINameValuePair> Mappings;

        // Gets or sets provider name.
        std::optional<std::string> ProviderName;

        OAIChannelMappingOptionsDto();
        ~OAIChannelMappingOptionsDto();
    };
    extern void to_json(json_t&, const OAIChannelMappingOptionsDto&);
    extern void from_json(const json_t&, OAIChannelMappingOptionsDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIChannelMappingOptionsDto);
