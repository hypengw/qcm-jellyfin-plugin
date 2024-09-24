#pragma once

/*
 * OAIMediaPathDto.h
 * name: MediaPathDto
 * schemaName: MediaPathDto
 * classFilename: MediaPathDto
 * classVarName: MediaPathDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Media Path dto.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIMediaPathInfo.h"
#include <string>



namespace jellyfin::model {
class OAIMediaPathInfo;


    class OAIMediaPathDto {
    public:
    
        // Gets or sets the name of the library.
        std::string Name;

        // Gets or sets the path to add.
        std::optional<std::string> Path;

        // Gets or sets the path info.
        std::optional<OAIMediaPathInfo> PathInfo;

        OAIMediaPathDto();
        ~OAIMediaPathDto();
    };
    extern void to_json(json_t&, const OAIMediaPathDto&);
    extern void from_json(const json_t&, OAIMediaPathDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMediaPathDto);
