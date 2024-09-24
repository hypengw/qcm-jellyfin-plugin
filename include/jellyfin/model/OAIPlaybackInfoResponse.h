#pragma once

/*
 * OAIPlaybackInfoResponse.h
 * name: PlaybackInfoResponse
 * schemaName: PlaybackInfoResponse
 * classFilename: PlaybackInfoResponse
 * classVarName: PlaybackInfoResponse
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class PlaybackInfoResponse.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIMediaSourceInfo.h"
#include "jellyfin/model/OAIPlaybackErrorCode.h"
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIMediaSourceInfo;


    class OAIPlaybackInfoResponse {
    public:
    
        // Gets or sets the media sources.
        std::vector<OAIMediaSourceInfo> MediaSources;

        // Gets or sets the play session identifier.
        std::optional<std::string> PlaySessionId;

        // Gets or sets the error code.
        std::optional<OAIPlaybackErrorCode> ErrorCode;

        OAIPlaybackInfoResponse();
        ~OAIPlaybackInfoResponse();
    };
    extern void to_json(json_t&, const OAIPlaybackInfoResponse&);
    extern void from_json(const json_t&, OAIPlaybackInfoResponse&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlaybackInfoResponse);
