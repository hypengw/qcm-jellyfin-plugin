#pragma once

/*
 * OAITaskInfo.h
 * name: TaskInfo
 * schemaName: TaskInfo
 * classFilename: TaskInfo
 * classVarName: TaskInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class TaskInfo.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAITaskResult.h"
#include "jellyfin/model/OAITaskState.h"
#include "jellyfin/model/OAITaskTriggerInfo.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAITaskResult;
class OAITaskTriggerInfo;


    class OAITaskInfo {
    public:
    
        // Gets or sets the name.
        std::optional<std::string> Name;

        // Gets or sets the state of the task.
        OAITaskState State;

        // Gets or sets the progress.
        std::optional<double> CurrentProgressPercentage;

        // Gets or sets the id.
        std::optional<std::string> Id;

        // Gets or sets the last execution result.
        std::optional<OAITaskResult> LastExecutionResult;

        // Gets or sets the triggers.
        std::optional<std::vector<OAITaskTriggerInfo>> Triggers;

        // Gets or sets the description.
        std::optional<std::string> Description;

        // Gets or sets the category.
        std::optional<std::string> Category;

        // Gets or sets a value indicating whether this instance is hidden.
        bool IsHidden;

        // Gets or sets the key.
        std::optional<std::string> Key;

        OAITaskInfo();
        ~OAITaskInfo();
    };
    extern void to_json(json_t&, const OAITaskInfo&);
    extern void from_json(const json_t&, OAITaskInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITaskInfo);
