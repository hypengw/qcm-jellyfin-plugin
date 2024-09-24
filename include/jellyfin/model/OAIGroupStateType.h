#pragma once

/*
 * OAIGroupStateType.h
 * name: GroupStateType
 * schemaName: GroupStateType
 * classFilename: GroupStateType
 * classVarName: GroupStateType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum GroupState.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIGroupStateType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        IDLE, // Idle
        WAITING, // Waiting
        PAUSED, // Paused
        PLAYING, // Playing
    };
    extern void to_json(json_t&, const OAIGroupStateType&);
    extern void from_json(const json_t&, OAIGroupStateType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIGroupStateType);
