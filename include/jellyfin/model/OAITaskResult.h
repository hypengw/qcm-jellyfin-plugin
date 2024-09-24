#pragma once

/*
 * OAITaskResult.h
 * name: TaskResult
 * schemaName: TaskResult
 * classFilename: TaskResult
 * classVarName: TaskResult
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class TaskExecutionInfo.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAITaskCompletionStatus.h"
#include <string>



namespace jellyfin::model {


    class OAITaskResult {
    public:
    
        // Gets or sets the start time UTC.
        std::string StartTimeUtc;

        // Gets or sets the end time UTC.
        std::string EndTimeUtc;

        // Gets or sets the status.
        OAITaskCompletionStatus Status;

        // Gets or sets the name.
        std::optional<std::string> Name;

        // Gets or sets the key.
        std::optional<std::string> Key;

        // Gets or sets the id.
        std::optional<std::string> Id;

        // Gets or sets the error message.
        std::optional<std::string> ErrorMessage;

        // Gets or sets the long error message.
        std::optional<std::string> LongErrorMessage;

        OAITaskResult();
        ~OAITaskResult();
    };
    extern void to_json(json_t&, const OAITaskResult&);
    extern void from_json(const json_t&, OAITaskResult&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITaskResult);
