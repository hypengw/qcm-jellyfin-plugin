#pragma once

/*
 * OAIMediaUpdateInfoPathDto.h
 * name: MediaUpdateInfoPathDto
 * schemaName: MediaUpdateInfoPathDto
 * classFilename: MediaUpdateInfoPathDto
 * classVarName: MediaUpdateInfoPathDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * The media update info path.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAIMediaUpdateInfoPathDto {
    public:
    
        // Gets or sets media path.
        std::optional<std::string> Path;

        // Gets or sets media update type.  Created, Modified, Deleted.
        std::optional<std::string> UpdateType;

        OAIMediaUpdateInfoPathDto();
        ~OAIMediaUpdateInfoPathDto();
    };
    extern void to_json(json_t&, const OAIMediaUpdateInfoPathDto&);
    extern void from_json(const json_t&, OAIMediaUpdateInfoPathDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMediaUpdateInfoPathDto);
