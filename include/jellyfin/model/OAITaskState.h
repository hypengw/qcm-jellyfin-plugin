#pragma once

/*
 * OAITaskState.h
 * name: TaskState
 * schemaName: TaskState
 * classFilename: TaskState
 * classVarName: TaskState
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum TaskState.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAITaskState {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        IDLE, // Idle
        CANCELLING, // Cancelling
        RUNNING, // Running
    };
    extern void to_json(json_t&, const OAITaskState&);
    extern void from_json(const json_t&, OAITaskState&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITaskState);
