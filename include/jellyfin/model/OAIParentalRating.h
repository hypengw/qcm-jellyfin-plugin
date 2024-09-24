#pragma once

/*
 * OAIParentalRating.h
 * name: ParentalRating
 * schemaName: ParentalRating
 * classFilename: ParentalRating
 * classVarName: ParentalRating
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class ParentalRating.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIParentalRating {
    public:
    
        // Gets or sets the name.
        std::optional<std::string> Name;

        // Gets or sets the value.
        std::optional<std::int32_t> Value;

        OAIParentalRating();
        ~OAIParentalRating();
    };
    extern void to_json(json_t&, const OAIParentalRating&);
    extern void from_json(const json_t&, OAIParentalRating&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIParentalRating);
