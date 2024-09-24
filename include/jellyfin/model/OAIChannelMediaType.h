#pragma once

/*
 * OAIChannelMediaType.h
 * name: ChannelMediaType
 * schemaName: ChannelMediaType
 * classFilename: ChannelMediaType
 * classVarName: ChannelMediaType
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

    enum class OAIChannelMediaType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        AUDIO, // Audio
        VIDEO, // Video
        PHOTO, // Photo
    };
    extern void to_json(json_t&, const OAIChannelMediaType&);
    extern void from_json(const json_t&, OAIChannelMediaType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIChannelMediaType);
