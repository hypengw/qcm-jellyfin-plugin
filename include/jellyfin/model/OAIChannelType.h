#pragma once

/*
 * OAIChannelType.h
 * name: ChannelType
 * schemaName: ChannelType
 * classFilename: ChannelType
 * classVarName: ChannelType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum ChannelType.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIChannelType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        TV, // TV
        RADIO, // Radio
    };
    extern void to_json(json_t&, const OAIChannelType&);
    extern void from_json(const json_t&, OAIChannelType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIChannelType);
