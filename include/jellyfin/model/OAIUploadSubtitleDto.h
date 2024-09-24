#pragma once

/*
 * OAIUploadSubtitleDto.h
 * name: UploadSubtitleDto
 * schemaName: UploadSubtitleDto
 * classFilename: UploadSubtitleDto
 * classVarName: UploadSubtitleDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Upload subtitles dto.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIUploadSubtitleDto {
    public:
    
        // Gets or sets the subtitle language.
        std::string Language;

        // Gets or sets the subtitle format.
        std::string Format;

        // Gets or sets a value indicating whether the subtitle is forced.
        bool IsForced;

        // Gets or sets a value indicating whether the subtitle is for hearing impaired.
        bool IsHearingImpaired;

        // Gets or sets the subtitle data.
        std::string Data;

        OAIUploadSubtitleDto();
        ~OAIUploadSubtitleDto();
    };
    extern void to_json(json_t&, const OAIUploadSubtitleDto&);
    extern void from_json(const json_t&, OAIUploadSubtitleDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIUploadSubtitleDto);
