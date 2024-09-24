#pragma once

/*
 * OAILyricDto.h
 * name: LyricDto
 * schemaName: LyricDto
 * classFilename: LyricDto
 * classVarName: LyricDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * LyricResponse model.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAILyricLine.h"
#include "jellyfin/model/OAILyricMetadata.h"
#include <vector>



namespace jellyfin::model {
class OAILyricMetadata;
class OAILyricLine;


    class OAILyricDto {
    public:
    
        // Gets or sets Metadata for the lyrics.
        OAILyricMetadata Metadata;

        // Gets or sets a collection of individual lyric lines.
        std::vector<OAILyricLine> Lyrics;

        OAILyricDto();
        ~OAILyricDto();
    };
    extern void to_json(json_t&, const OAILyricDto&);
    extern void from_json(const json_t&, OAILyricDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAILyricDto);
