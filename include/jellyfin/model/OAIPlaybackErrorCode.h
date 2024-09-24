#pragma once

/*
 * OAIPlaybackErrorCode.h
 * name: PlaybackErrorCode
 * schemaName: PlaybackErrorCode
 * classFilename: PlaybackErrorCode
 * classVarName: PlaybackErrorCode
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

    enum class OAIPlaybackErrorCode {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        NOTALLOWED, // NotAllowed
        NOCOMPATIBLESTREAM, // NoCompatibleStream
        RATELIMITEXCEEDED, // RateLimitExceeded
    };
    extern void to_json(json_t&, const OAIPlaybackErrorCode&);
    extern void from_json(const json_t&, OAIPlaybackErrorCode&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlaybackErrorCode);
