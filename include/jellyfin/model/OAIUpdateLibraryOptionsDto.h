#pragma once

/*
 * OAIUpdateLibraryOptionsDto.h
 * name: UpdateLibraryOptionsDto
 * schemaName: UpdateLibraryOptionsDto
 * classFilename: UpdateLibraryOptionsDto
 * classVarName: UpdateLibraryOptionsDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Update library options dto.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAILibraryOptions.h"
#include <string>



namespace jellyfin::model {
class OAILibraryOptions;


    class OAIUpdateLibraryOptionsDto {
    public:
    
        // Gets or sets the library item id.
        std::string Id;

        // Gets or sets library options.
        std::optional<OAILibraryOptions> LibraryOptions;

        OAIUpdateLibraryOptionsDto();
        ~OAIUpdateLibraryOptionsDto();
    };
    extern void to_json(json_t&, const OAIUpdateLibraryOptionsDto&);
    extern void from_json(const json_t&, OAIUpdateLibraryOptionsDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIUpdateLibraryOptionsDto);
