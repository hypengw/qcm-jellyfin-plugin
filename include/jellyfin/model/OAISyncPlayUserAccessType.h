#pragma once

/*
 * OAISyncPlayUserAccessType.h
 * name: SyncPlayUserAccessType
 * schemaName: SyncPlayUserAccessType
 * classFilename: SyncPlayUserAccessType
 * classVarName: SyncPlayUserAccessType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum SyncPlayUserAccessType.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAISyncPlayUserAccessType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        CREATEANDJOINGROUPS, // CreateAndJoinGroups
        JOINGROUPS, // JoinGroups
        NONE, // None
    };
    extern void to_json(json_t&, const OAISyncPlayUserAccessType&);
    extern void from_json(const json_t&, OAISyncPlayUserAccessType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISyncPlayUserAccessType);
