#pragma once

/*
 * OAIMetadataOptions.h
 * name: MetadataOptions
 * schemaName: MetadataOptions
 * classFilename: MetadataOptions
 * classVarName: MetadataOptions
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class MetadataOptions.
 */


#include "jellyfin/type.h"


#include <string>
#include <vector>



namespace jellyfin::model {


    class OAIMetadataOptions {
    public:
    
        std::optional<std::string> ItemType;

        std::optional<std::vector<std::string>> DisabledMetadataSavers;

        std::optional<std::vector<std::string>> LocalMetadataReaderOrder;

        std::optional<std::vector<std::string>> DisabledMetadataFetchers;

        std::optional<std::vector<std::string>> MetadataFetcherOrder;

        std::optional<std::vector<std::string>> DisabledImageFetchers;

        std::optional<std::vector<std::string>> ImageFetcherOrder;

        OAIMetadataOptions();
        ~OAIMetadataOptions();
    };
    extern void to_json(json_t&, const OAIMetadataOptions&);
    extern void from_json(const json_t&, OAIMetadataOptions&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMetadataOptions);
