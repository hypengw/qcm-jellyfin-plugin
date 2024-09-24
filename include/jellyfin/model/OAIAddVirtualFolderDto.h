#pragma once

/*
 * OAIAddVirtualFolderDto.h
 * name: AddVirtualFolderDto
 * schemaName: AddVirtualFolderDto
 * classFilename: AddVirtualFolderDto
 * classVarName: AddVirtualFolderDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Add virtual folder dto.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAILibraryOptions.h"



namespace jellyfin::model {
class OAILibraryOptions;


    class OAIAddVirtualFolderDto {
    public:
    
        // Gets or sets library options.
        std::optional<OAILibraryOptions> LibraryOptions;

        OAIAddVirtualFolderDto();
        ~OAIAddVirtualFolderDto();
    };
    extern void to_json(json_t&, const OAIAddVirtualFolderDto&);
    extern void from_json(const json_t&, OAIAddVirtualFolderDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIAddVirtualFolderDto);
