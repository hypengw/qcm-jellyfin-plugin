#pragma once

/*
 * OAIChannelMediaContentType.h
 * name: ChannelMediaContentType
 * schemaName: ChannelMediaContentType
 * classFilename: ChannelMediaContentType
 * classVarName: ChannelMediaContentType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIChannelMediaContentType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        CLIP, // Clip
        PODCAST, // Podcast
        TRAILER, // Trailer
        MOVIE, // Movie
        EPISODE, // Episode
        SONG, // Song
        MOVIEEXTRA, // MovieExtra
        TVEXTRA, // TvExtra
    };
    extern void to_json(json_t&, const OAIChannelMediaContentType&);
    extern void from_json(const json_t&, OAIChannelMediaContentType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIChannelMediaContentType);
