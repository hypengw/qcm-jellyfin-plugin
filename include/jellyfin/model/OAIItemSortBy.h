#pragma once

/*
 * OAIItemSortBy.h
 * name: ItemSortBy
 * schemaName: ItemSortBy
 * classFilename: ItemSortBy
 * classVarName: ItemSortBy
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * These represent sort orders.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIItemSortBy {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        DEFAULT, // Default
        AIREDEPISODEORDER, // AiredEpisodeOrder
        ALBUM, // Album
        ALBUMARTIST, // AlbumArtist
        ARTIST, // Artist
        DATECREATED, // DateCreated
        OFFICIALRATING, // OfficialRating
        DATEPLAYED, // DatePlayed
        PREMIEREDATE, // PremiereDate
        STARTDATE, // StartDate
        SORTNAME, // SortName
        NAME, // Name
        RANDOM, // Random
        RUNTIME, // Runtime
        COMMUNITYRATING, // CommunityRating
        PRODUCTIONYEAR, // ProductionYear
        PLAYCOUNT, // PlayCount
        CRITICRATING, // CriticRating
        ISFOLDER, // IsFolder
        ISUNPLAYED, // IsUnplayed
        ISPLAYED, // IsPlayed
        SERIESSORTNAME, // SeriesSortName
        VIDEOBITRATE, // VideoBitRate
        AIRTIME, // AirTime
        STUDIO, // Studio
        ISFAVORITEORLIKED, // IsFavoriteOrLiked
        DATELASTCONTENTADDED, // DateLastContentAdded
        SERIESDATEPLAYED, // SeriesDatePlayed
        PARENTINDEXNUMBER, // ParentIndexNumber
        INDEXNUMBER, // IndexNumber
        SIMILARITYSCORE, // SimilarityScore
        SEARCHSCORE, // SearchScore
    };
    extern void to_json(json_t&, const OAIItemSortBy&);
    extern void from_json(const json_t&, OAIItemSortBy&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIItemSortBy);
