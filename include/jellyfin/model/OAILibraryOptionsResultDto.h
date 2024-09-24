#pragma once

/*
 * OAILibraryOptionsResultDto.h
 * name: LibraryOptionsResultDto
 * schemaName: LibraryOptionsResultDto
 * classFilename: LibraryOptionsResultDto
 * classVarName: LibraryOptionsResultDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Library options result dto.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAILibraryOptionInfoDto.h"
#include "jellyfin/model/OAILibraryTypeOptionsDto.h"
#include <vector>



namespace jellyfin::model {
class OAILibraryOptionInfoDto;
class OAILibraryTypeOptionsDto;


    class OAILibraryOptionsResultDto {
    public:
    
        // Gets or sets the metadata savers.
        std::vector<OAILibraryOptionInfoDto> MetadataSavers;

        // Gets or sets the metadata readers.
        std::vector<OAILibraryOptionInfoDto> MetadataReaders;

        // Gets or sets the subtitle fetchers.
        std::vector<OAILibraryOptionInfoDto> SubtitleFetchers;

        // Gets or sets the type options.
        std::vector<OAILibraryTypeOptionsDto> TypeOptions;

        OAILibraryOptionsResultDto();
        ~OAILibraryOptionsResultDto();
    };
    extern void to_json(json_t&, const OAILibraryOptionsResultDto&);
    extern void from_json(const json_t&, OAILibraryOptionsResultDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAILibraryOptionsResultDto);
