#pragma once

/*
 * OAIListingsProviderInfo.h
 * name: ListingsProviderInfo
 * schemaName: ListingsProviderInfo
 * classFilename: ListingsProviderInfo
 * classVarName: ListingsProviderInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAINameValuePair.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAINameValuePair;


    class OAIListingsProviderInfo {
    public:
    
        std::optional<std::string> Id;

        std::optional<std::string> Type;

        std::optional<std::string> Username;

        std::optional<std::string> Password;

        std::optional<std::string> ListingsId;

        std::optional<std::string> ZipCode;

        std::optional<std::string> Country;

        std::optional<std::string> Path;

        std::optional<std::vector<std::string>> EnabledTuners;

        bool EnableAllTuners;

        std::optional<std::vector<std::string>> NewsCategories;

        std::optional<std::vector<std::string>> SportsCategories;

        std::optional<std::vector<std::string>> KidsCategories;

        std::optional<std::vector<std::string>> MovieCategories;

        std::optional<std::vector<OAINameValuePair>> ChannelMappings;

        std::optional<std::string> MoviePrefix;

        std::optional<std::string> PreferredLanguage;

        std::optional<std::string> UserAgent;

        OAIListingsProviderInfo();
        ~OAIListingsProviderInfo();
    };
    extern void to_json(json_t&, const OAIListingsProviderInfo&);
    extern void from_json(const json_t&, OAIListingsProviderInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIListingsProviderInfo);
