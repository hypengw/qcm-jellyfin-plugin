#pragma once

/*
 * OAIUnratedItem.h
 * name: UnratedItem
 * schemaName: UnratedItem
 * classFilename: UnratedItem
 * classVarName: UnratedItem
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * An enum representing an unrated item.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIUnratedItem {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        MOVIE, // Movie
        TRAILER, // Trailer
        SERIES, // Series
        MUSIC, // Music
        BOOK, // Book
        LIVETVCHANNEL, // LiveTvChannel
        LIVETVPROGRAM, // LiveTvProgram
        CHANNELCONTENT, // ChannelContent
        OTHER, // Other
    };
    extern void to_json(json_t&, const OAIUnratedItem&);
    extern void from_json(const json_t&, OAIUnratedItem&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIUnratedItem);
