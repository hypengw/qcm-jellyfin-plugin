#pragma once

/*
 * OAIPersonKind.h
 * name: PersonKind
 * schemaName: PersonKind
 * classFilename: PersonKind
 * classVarName: PersonKind
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * The person kind.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIPersonKind {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        UNKNOWN, // Unknown
        ACTOR, // Actor
        DIRECTOR, // Director
        COMPOSER, // Composer
        WRITER, // Writer
        GUESTSTAR, // GuestStar
        PRODUCER, // Producer
        CONDUCTOR, // Conductor
        LYRICIST, // Lyricist
        ARRANGER, // Arranger
        ENGINEER, // Engineer
        MIXER, // Mixer
        REMIXER, // Remixer
        CREATOR, // Creator
        ARTIST, // Artist
        ALBUMARTIST, // AlbumArtist
        AUTHOR, // Author
        ILLUSTRATOR, // Illustrator
        PENCILLER, // Penciller
        INKER, // Inker
        COLORIST, // Colorist
        LETTERER, // Letterer
        COVERARTIST, // CoverArtist
        EDITOR, // Editor
        TRANSLATOR, // Translator
    };
    extern void to_json(json_t&, const OAIPersonKind&);
    extern void from_json(const json_t&, OAIPersonKind&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPersonKind);
