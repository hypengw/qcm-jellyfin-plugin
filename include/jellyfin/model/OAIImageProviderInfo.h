#pragma once

/*
 * OAIImageProviderInfo.h
 * name: ImageProviderInfo
 * schemaName: ImageProviderInfo
 * classFilename: ImageProviderInfo
 * classVarName: ImageProviderInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class ImageProviderInfo.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIImageType.h"
#include <string>
#include <vector>



namespace jellyfin::model {


    class OAIImageProviderInfo {
    public:
    
        // Gets the name.
        std::string Name;

        // Gets the supported image types.
        std::vector<OAIImageType> SupportedImages;

        OAIImageProviderInfo();
        ~OAIImageProviderInfo();
    };
    extern void to_json(json_t&, const OAIImageProviderInfo&);
    extern void from_json(const json_t&, OAIImageProviderInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIImageProviderInfo);
