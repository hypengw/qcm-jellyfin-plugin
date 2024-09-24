#pragma once

/*
 * OAIQueryFiltersLegacy.h
 * name: QueryFiltersLegacy
 * schemaName: QueryFiltersLegacy
 * classFilename: QueryFiltersLegacy
 * classVarName: QueryFiltersLegacy
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {


    class OAIQueryFiltersLegacy {
    public:
    
        std::optional<std::vector<std::string>> Genres;

        std::optional<std::vector<std::string>> Tags;

        std::optional<std::vector<std::string>> OfficialRatings;

        std::optional<std::vector<std::int32_t>> Years;

        OAIQueryFiltersLegacy();
        ~OAIQueryFiltersLegacy();
    };
    extern void to_json(json_t&, const OAIQueryFiltersLegacy&);
    extern void from_json(const json_t&, OAIQueryFiltersLegacy&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIQueryFiltersLegacy);
