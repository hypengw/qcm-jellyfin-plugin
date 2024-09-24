#pragma once

/*
 * OAITaskCompletionStatus.h
 * name: TaskCompletionStatus
 * schemaName: TaskCompletionStatus
 * classFilename: TaskCompletionStatus
 * classVarName: TaskCompletionStatus
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum TaskCompletionStatus.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAITaskCompletionStatus {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        COMPLETED, // Completed
        FAILED, // Failed
        CANCELLED, // Cancelled
        ABORTED, // Aborted
    };
    extern void to_json(json_t&, const OAITaskCompletionStatus&);
    extern void from_json(const json_t&, OAITaskCompletionStatus&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITaskCompletionStatus);
