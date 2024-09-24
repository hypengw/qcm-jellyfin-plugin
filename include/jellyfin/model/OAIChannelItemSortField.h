#pragma once

/*
 * OAIChannelItemSortField.h
 * name: ChannelItemSortField
 * schemaName: ChannelItemSortField
 * classFilename: ChannelItemSortField
 * classVarName: ChannelItemSortField
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

    enum class OAIChannelItemSortField {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        NAME, // Name
        COMMUNITYRATING, // CommunityRating
        PREMIEREDATE, // PremiereDate
        DATECREATED, // DateCreated
        RUNTIME, // Runtime
        PLAYCOUNT, // PlayCount
        COMMUNITYPLAYCOUNT, // CommunityPlayCount
    };
    extern void to_json(json_t&, const OAIChannelItemSortField&);
    extern void from_json(const json_t&, OAIChannelItemSortField&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIChannelItemSortField);
