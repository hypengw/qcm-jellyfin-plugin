#pragma once

/*
 * OAIQueryFilters.h
 * name: QueryFilters
 * schemaName: QueryFilters
 * classFilename: QueryFilters
 * classVarName: QueryFilters
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAINameGuidPair.h"
#include <string>
#include <vector>



namespace jellyfin::model {
class OAINameGuidPair;


    class OAIQueryFilters {
    public:
    
        std::optional<std::vector<OAINameGuidPair>> Genres;

        std::optional<std::vector<std::string>> Tags;

        OAIQueryFilters();
        ~OAIQueryFilters();
    };
    extern void to_json(json_t&, const OAIQueryFilters&);
    extern void from_json(const json_t&, OAIQueryFilters&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIQueryFilters);
