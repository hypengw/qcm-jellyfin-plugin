#pragma once

/*
 * OAIXbmcMetadataOptions.h
 * name: XbmcMetadataOptions
 * schemaName: XbmcMetadataOptions
 * classFilename: XbmcMetadataOptions
 * classVarName: XbmcMetadataOptions
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIXbmcMetadataOptions {
    public:
    
        std::optional<std::string> UserId;

        std::string ReleaseDateFormat;

        bool SaveImagePathsInNfo;

        bool EnablePathSubstitution;

        bool EnableExtraThumbsDuplication;

        OAIXbmcMetadataOptions();
        ~OAIXbmcMetadataOptions();
    };
    extern void to_json(json_t&, const OAIXbmcMetadataOptions&);
    extern void from_json(const json_t&, OAIXbmcMetadataOptions&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIXbmcMetadataOptions);
