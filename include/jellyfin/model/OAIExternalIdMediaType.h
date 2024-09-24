#pragma once

/*
 * OAIExternalIdMediaType.h
 * name: ExternalIdMediaType
 * schemaName: ExternalIdMediaType
 * classFilename: ExternalIdMediaType
 * classVarName: ExternalIdMediaType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * The specific media type of an MediaBrowser.Model.Providers.ExternalIdInfo.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIExternalIdMediaType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        ALBUM, // Album
        ALBUMARTIST, // AlbumArtist
        ARTIST, // Artist
        BOXSET, // BoxSet
        EPISODE, // Episode
        MOVIE, // Movie
        OTHERARTIST, // OtherArtist
        PERSON, // Person
        RELEASEGROUP, // ReleaseGroup
        SEASON, // Season
        SERIES, // Series
        TRACK, // Track
        BOOK, // Book
    };
    extern void to_json(json_t&, const OAIExternalIdMediaType&);
    extern void from_json(const json_t&, OAIExternalIdMediaType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIExternalIdMediaType);
