#pragma once

/*
 * OAIBaseItemKind.h
 * name: BaseItemKind
 * schemaName: BaseItemKind
 * classFilename: BaseItemKind
 * classVarName: BaseItemKind
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * The base item kind.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIBaseItemKind {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        AGGREGATEFOLDER, // AggregateFolder
        AUDIO, // Audio
        AUDIOBOOK, // AudioBook
        BASEPLUGINFOLDER, // BasePluginFolder
        BOOK, // Book
        BOXSET, // BoxSet
        CHANNEL, // Channel
        CHANNELFOLDERITEM, // ChannelFolderItem
        COLLECTIONFOLDER, // CollectionFolder
        EPISODE, // Episode
        FOLDER, // Folder
        GENRE, // Genre
        MANUALPLAYLISTSFOLDER, // ManualPlaylistsFolder
        MOVIE, // Movie
        LIVETVCHANNEL, // LiveTvChannel
        LIVETVPROGRAM, // LiveTvProgram
        MUSICALBUM, // MusicAlbum
        MUSICARTIST, // MusicArtist
        MUSICGENRE, // MusicGenre
        MUSICVIDEO, // MusicVideo
        PERSON, // Person
        PHOTO, // Photo
        PHOTOALBUM, // PhotoAlbum
        PLAYLIST, // Playlist
        PLAYLISTSFOLDER, // PlaylistsFolder
        PROGRAM, // Program
        RECORDING, // Recording
        SEASON, // Season
        SERIES, // Series
        STUDIO, // Studio
        TRAILER, // Trailer
        TVCHANNEL, // TvChannel
        TVPROGRAM, // TvProgram
        USERROOTFOLDER, // UserRootFolder
        USERVIEW, // UserView
        VIDEO, // Video
        YEAR, // Year
    };
    extern void to_json(json_t&, const OAIBaseItemKind&);
    extern void from_json(const json_t&, OAIBaseItemKind&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIBaseItemKind);
