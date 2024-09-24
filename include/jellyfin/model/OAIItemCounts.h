#pragma once

/*
 * OAIItemCounts.h
 * name: ItemCounts
 * schemaName: ItemCounts
 * classFilename: ItemCounts
 * classVarName: ItemCounts
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class LibrarySummary.
 */


#include "jellyfin/type.h"


#include <cstdint>



namespace jellyfin::model {


    class OAIItemCounts {
    public:
    
        // Gets or sets the movie count.
        std::int32_t MovieCount;

        // Gets or sets the series count.
        std::int32_t SeriesCount;

        // Gets or sets the episode count.
        std::int32_t EpisodeCount;

        // Gets or sets the artist count.
        std::int32_t ArtistCount;

        // Gets or sets the program count.
        std::int32_t ProgramCount;

        // Gets or sets the trailer count.
        std::int32_t TrailerCount;

        // Gets or sets the song count.
        std::int32_t SongCount;

        // Gets or sets the album count.
        std::int32_t AlbumCount;

        // Gets or sets the music video count.
        std::int32_t MusicVideoCount;

        // Gets or sets the box set count.
        std::int32_t BoxSetCount;

        // Gets or sets the book count.
        std::int32_t BookCount;

        // Gets or sets the item count.
        std::int32_t ItemCount;

        OAIItemCounts();
        ~OAIItemCounts();
    };
    extern void to_json(json_t&, const OAIItemCounts&);
    extern void from_json(const json_t&, OAIItemCounts&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIItemCounts);
