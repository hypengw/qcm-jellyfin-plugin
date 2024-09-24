#pragma once

/*
 * OAILiveStreamResponse.h
 * name: LiveStreamResponse
 * schemaName: LiveStreamResponse
 * classFilename: LiveStreamResponse
 * classVarName: LiveStreamResponse
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIMediaSourceInfo.h"



namespace jellyfin::model {
class OAIMediaSourceInfo;


    class OAILiveStreamResponse {
    public:
    
        OAIMediaSourceInfo MediaSource;

        OAILiveStreamResponse();
        ~OAILiveStreamResponse();
    };
    extern void to_json(json_t&, const OAILiveStreamResponse&);
    extern void from_json(const json_t&, OAILiveStreamResponse&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAILiveStreamResponse);
