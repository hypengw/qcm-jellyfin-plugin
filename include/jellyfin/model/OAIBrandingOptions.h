#pragma once

/*
 * OAIBrandingOptions.h
 * name: BrandingOptions
 * schemaName: BrandingOptions
 * classFilename: BrandingOptions
 * classVarName: BrandingOptions
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * The branding options.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIBrandingOptions {
    public:
    
        // Gets or sets the login disclaimer.
        std::optional<std::string> LoginDisclaimer;

        // Gets or sets the custom CSS.
        std::optional<std::string> CustomCss;

        // Gets or sets a value indicating whether to enable the splashscreen.
        bool SplashscreenEnabled;

        OAIBrandingOptions();
        ~OAIBrandingOptions();
    };
    extern void to_json(json_t&, const OAIBrandingOptions&);
    extern void from_json(const json_t&, OAIBrandingOptions&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIBrandingOptions);
