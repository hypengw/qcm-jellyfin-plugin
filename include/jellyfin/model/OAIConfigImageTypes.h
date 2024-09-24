#pragma once

/*
 * OAIConfigImageTypes.h
 * name: ConfigImageTypes
 * schemaName: ConfigImageTypes
 * classFilename: ConfigImageTypes
 * classVarName: ConfigImageTypes
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include <string>
#include <vector>



namespace jellyfin::model {


    class OAIConfigImageTypes {
    public:
    
        std::optional<std::vector<std::string>> BackdropSizes;

        std::optional<std::string> BaseUrl;

        std::optional<std::vector<std::string>> LogoSizes;

        std::optional<std::vector<std::string>> PosterSizes;

        std::optional<std::vector<std::string>> ProfileSizes;

        std::optional<std::string> SecureBaseUrl;

        std::optional<std::vector<std::string>> StillSizes;

        OAIConfigImageTypes();
        ~OAIConfigImageTypes();
    };
    extern void to_json(json_t&, const OAIConfigImageTypes&);
    extern void from_json(const json_t&, OAIConfigImageTypes&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIConfigImageTypes);
