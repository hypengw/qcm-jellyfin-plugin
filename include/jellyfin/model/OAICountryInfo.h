#pragma once

/*
 * OAICountryInfo.h
 * name: CountryInfo
 * schemaName: CountryInfo
 * classFilename: CountryInfo
 * classVarName: CountryInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class CountryInfo.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAICountryInfo {
    public:
    
        // Gets or sets the name.
        std::optional<std::string> Name;

        // Gets or sets the display name.
        std::optional<std::string> DisplayName;

        // Gets or sets the name of the two letter ISO region.
        std::optional<std::string> TwoLetterISORegionName;

        // Gets or sets the name of the three letter ISO region.
        std::optional<std::string> ThreeLetterISORegionName;

        OAICountryInfo();
        ~OAICountryInfo();
    };
    extern void to_json(json_t&, const OAICountryInfo&);
    extern void from_json(const json_t&, OAICountryInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAICountryInfo);
