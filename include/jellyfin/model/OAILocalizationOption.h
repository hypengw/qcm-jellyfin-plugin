#pragma once

/*
 * OAILocalizationOption.h
 * name: LocalizationOption
 * schemaName: LocalizationOption
 * classFilename: LocalizationOption
 * classVarName: LocalizationOption
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



namespace jellyfin::model {


    class OAILocalizationOption {
    public:
    
        std::optional<std::string> Name;

        std::optional<std::string> Value;

        OAILocalizationOption();
        ~OAILocalizationOption();
    };
    extern void to_json(json_t&, const OAILocalizationOption&);
    extern void from_json(const json_t&, OAILocalizationOption&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAILocalizationOption);
