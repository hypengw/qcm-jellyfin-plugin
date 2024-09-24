#pragma once

/*
 * OAICultureDto.h
 * name: CultureDto
 * schemaName: CultureDto
 * classFilename: CultureDto
 * classVarName: CultureDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class CultureDto.
 */


#include "jellyfin/type.h"


#include <string>
#include <vector>



namespace jellyfin::model {


    class OAICultureDto {
    public:
    
        // Gets the name.
        std::string Name;

        // Gets the display name.
        std::string DisplayName;

        // Gets the name of the two letter ISO language.
        std::string TwoLetterISOLanguageName;

        // Gets the name of the three letter ISO language.
        std::optional<std::string> ThreeLetterISOLanguageName;

        std::vector<std::string> ThreeLetterISOLanguageNames;

        OAICultureDto();
        ~OAICultureDto();
    };
    extern void to_json(json_t&, const OAICultureDto&);
    extern void from_json(const json_t&, OAICultureDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAICultureDto);
