#pragma once

/*
 * OAIRemoteLyricInfoDto.h
 * name: RemoteLyricInfoDto
 * schemaName: RemoteLyricInfoDto
 * classFilename: RemoteLyricInfoDto
 * classVarName: RemoteLyricInfoDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * The remote lyric info dto.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAILyricDto.h"
#include <string>



namespace jellyfin::model {
class OAILyricDto;


    class OAIRemoteLyricInfoDto {
    public:
    
        // Gets or sets the id for the lyric.
        std::string Id;

        // Gets the provider name.
        std::string ProviderName;

        // Gets the lyrics.
        OAILyricDto Lyrics;

        OAIRemoteLyricInfoDto();
        ~OAIRemoteLyricInfoDto();
    };
    extern void to_json(json_t&, const OAIRemoteLyricInfoDto&);
    extern void from_json(const json_t&, OAIRemoteLyricInfoDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIRemoteLyricInfoDto);
