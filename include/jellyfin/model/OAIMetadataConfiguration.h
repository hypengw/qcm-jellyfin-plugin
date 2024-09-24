#pragma once

/*
 * OAIMetadataConfiguration.h
 * name: MetadataConfiguration
 * schemaName: MetadataConfiguration
 * classFilename: MetadataConfiguration
 * classVarName: MetadataConfiguration
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



namespace jellyfin::model {


    class OAIMetadataConfiguration {
    public:
    
        bool UseFileCreationTimeForDateAdded;

        OAIMetadataConfiguration();
        ~OAIMetadataConfiguration();
    };
    extern void to_json(json_t&, const OAIMetadataConfiguration&);
    extern void from_json(const json_t&, OAIMetadataConfiguration&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMetadataConfiguration);
