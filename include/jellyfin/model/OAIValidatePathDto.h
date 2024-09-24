#pragma once

/*
 * OAIValidatePathDto.h
 * name: ValidatePathDto
 * schemaName: ValidatePathDto
 * classFilename: ValidatePathDto
 * classVarName: ValidatePathDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Validate path object.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIValidatePathDto {
    public:
    
        // Gets or sets a value indicating whether validate if path is writable.
        bool ValidateWritable;

        // Gets or sets the path.
        std::optional<std::string> Path;

        // Gets or sets is path file.
        std::optional<bool> IsFile;

        OAIValidatePathDto();
        ~OAIValidatePathDto();
    };
    extern void to_json(json_t&, const OAIValidatePathDto&);
    extern void from_json(const json_t&, OAIValidatePathDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIValidatePathDto);
