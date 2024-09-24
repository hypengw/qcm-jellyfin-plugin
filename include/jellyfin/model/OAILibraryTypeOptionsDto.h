#pragma once

/*
 * OAILibraryTypeOptionsDto.h
 * name: LibraryTypeOptionsDto
 * schemaName: LibraryTypeOptionsDto
 * classFilename: LibraryTypeOptionsDto
 * classVarName: LibraryTypeOptionsDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Library type options dto.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIImageOption.h"
#include "jellyfin/model/OAIImageType.h"
#include "jellyfin/model/OAILibraryOptionInfoDto.h"
#include <string>
#include <vector>



namespace jellyfin::model {
class OAILibraryOptionInfoDto;
class OAIImageOption;


    class OAILibraryTypeOptionsDto {
    public:
    
        // Gets or sets the type.
        std::optional<std::string> Type;

        // Gets or sets the metadata fetchers.
        std::vector<OAILibraryOptionInfoDto> MetadataFetchers;

        // Gets or sets the image fetchers.
        std::vector<OAILibraryOptionInfoDto> ImageFetchers;

        // Gets or sets the supported image types.
        std::vector<OAIImageType> SupportedImageTypes;

        // Gets or sets the default image options.
        std::vector<OAIImageOption> DefaultImageOptions;

        OAILibraryTypeOptionsDto();
        ~OAILibraryTypeOptionsDto();
    };
    extern void to_json(json_t&, const OAILibraryTypeOptionsDto&);
    extern void from_json(const json_t&, OAILibraryTypeOptionsDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAILibraryTypeOptionsDto);
