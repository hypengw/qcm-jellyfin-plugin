#pragma once

/*
 * OAIImageOption.h
 * name: ImageOption
 * schemaName: ImageOption
 * classFilename: ImageOption
 * classVarName: ImageOption
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIImageType.h"
#include <cstdint>



namespace jellyfin::model {


    class OAIImageOption {
    public:
    
        // Gets or sets the type.
        OAIImageType Type;

        // Gets or sets the limit.
        std::int32_t Limit;

        // Gets or sets the minimum width.
        std::int32_t MinWidth;

        OAIImageOption();
        ~OAIImageOption();
    };
    extern void to_json(json_t&, const OAIImageOption&);
    extern void from_json(const json_t&, OAIImageOption&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIImageOption);
