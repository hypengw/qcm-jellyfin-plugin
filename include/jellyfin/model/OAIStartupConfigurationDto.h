#pragma once

/*
 * OAIStartupConfigurationDto.h
 * name: StartupConfigurationDto
 * schemaName: StartupConfigurationDto
 * classFilename: StartupConfigurationDto
 * classVarName: StartupConfigurationDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * The startup configuration DTO.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAIStartupConfigurationDto {
    public:
    
        // Gets or sets UI language culture.
        std::optional<std::string> UICulture;

        // Gets or sets the metadata country code.
        std::optional<std::string> MetadataCountryCode;

        // Gets or sets the preferred language for the metadata.
        std::optional<std::string> PreferredMetadataLanguage;

        OAIStartupConfigurationDto();
        ~OAIStartupConfigurationDto();
    };
    extern void to_json(json_t&, const OAIStartupConfigurationDto&);
    extern void from_json(const json_t&, OAIStartupConfigurationDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIStartupConfigurationDto);
