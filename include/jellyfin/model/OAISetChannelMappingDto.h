#pragma once

/*
 * OAISetChannelMappingDto.h
 * name: SetChannelMappingDto
 * schemaName: SetChannelMappingDto
 * classFilename: SetChannelMappingDto
 * classVarName: SetChannelMappingDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Set channel mapping dto.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAISetChannelMappingDto {
    public:
    
        // Gets or sets the provider id.
        std::string ProviderId;

        // Gets or sets the tuner channel id.
        std::string TunerChannelId;

        // Gets or sets the provider channel id.
        std::string ProviderChannelId;

        OAISetChannelMappingDto();
        ~OAISetChannelMappingDto();
    };
    extern void to_json(json_t&, const OAISetChannelMappingDto&);
    extern void from_json(const json_t&, OAISetChannelMappingDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISetChannelMappingDto);
