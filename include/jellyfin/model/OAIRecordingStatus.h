#pragma once

/*
 * OAIRecordingStatus.h
 * name: RecordingStatus
 * schemaName: RecordingStatus
 * classFilename: RecordingStatus
 * classVarName: RecordingStatus
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

    enum class OAIRecordingStatus {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        NEW, // New
        INPROGRESS, // InProgress
        COMPLETED, // Completed
        CANCELLED, // Cancelled
        CONFLICTEDOK, // ConflictedOk
        CONFLICTEDNOTOK, // ConflictedNotOk
        ERROR, // Error
    };
    extern void to_json(json_t&, const OAIRecordingStatus&);
    extern void from_json(const json_t&, OAIRecordingStatus&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIRecordingStatus);
