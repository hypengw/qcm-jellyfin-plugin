#pragma once

/*
 * OAILyricMetadata.h
 * name: LyricMetadata
 * schemaName: LyricMetadata
 * classFilename: LyricMetadata
 * classVarName: LyricMetadata
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * LyricMetadata model.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAILyricMetadata {
    public:
    
        // Gets or sets the song artist.
        std::optional<std::string> Artist;

        // Gets or sets the album this song is on.
        std::optional<std::string> Album;

        // Gets or sets the title of the song.
        std::optional<std::string> Title;

        // Gets or sets the author of the lyric data.
        std::optional<std::string> Author;

        // Gets or sets the length of the song in ticks.
        std::optional<std::int64_t> Length;

        // Gets or sets who the LRC file was created by.
        std::optional<std::string> By;

        // Gets or sets the lyric offset compared to audio in ticks.
        std::optional<std::int64_t> Offset;

        // Gets or sets the software used to create the LRC file.
        std::optional<std::string> Creator;

        // Gets or sets the version of the creator used.
        std::optional<std::string> Version;

        // Gets or sets a value indicating whether this lyric is synced.
        std::optional<bool> IsSynced;

        OAILyricMetadata();
        ~OAILyricMetadata();
    };
    extern void to_json(json_t&, const OAILyricMetadata&);
    extern void from_json(const json_t&, OAILyricMetadata&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAILyricMetadata);
