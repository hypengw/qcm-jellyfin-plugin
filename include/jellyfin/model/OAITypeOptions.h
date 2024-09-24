#pragma once

/*
 * OAITypeOptions.h
 * name: TypeOptions
 * schemaName: TypeOptions
 * classFilename: TypeOptions
 * classVarName: TypeOptions
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIImageOption.h"
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIImageOption;


    class OAITypeOptions {
    public:
    
        std::optional<std::string> Type;

        std::optional<std::vector<std::string>> MetadataFetchers;

        std::optional<std::vector<std::string>> MetadataFetcherOrder;

        std::optional<std::vector<std::string>> ImageFetchers;

        std::optional<std::vector<std::string>> ImageFetcherOrder;

        std::optional<std::vector<OAIImageOption>> ImageOptions;

        OAITypeOptions();
        ~OAITypeOptions();
    };
    extern void to_json(json_t&, const OAITypeOptions&);
    extern void from_json(const json_t&, OAITypeOptions&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITypeOptions);
