#pragma once

/*
 * OAIRepositoryInfo.h
 * name: RepositoryInfo
 * schemaName: RepositoryInfo
 * classFilename: RepositoryInfo
 * classVarName: RepositoryInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class RepositoryInfo.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIRepositoryInfo {
    public:
    
        // Gets or sets the name.
        std::optional<std::string> Name;

        // Gets or sets the URL.
        std::optional<std::string> Url;

        // Gets or sets a value indicating whether the repository is enabled.
        bool Enabled;

        OAIRepositoryInfo();
        ~OAIRepositoryInfo();
    };
    extern void to_json(json_t&, const OAIRepositoryInfo&);
    extern void from_json(const json_t&, OAIRepositoryInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIRepositoryInfo);
