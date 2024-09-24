#pragma once
/*
 * OAIScheduledTasksApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAITaskInfo.h"
#include "jellyfin/model/OAITaskTriggerInfo.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getTask = OAITaskInfo;
using return_type_getTasks = std::vector<OAITaskInfo>;
using return_type_startTask = std::nullptr_t;
using return_type_stopTask = std::nullptr_t;
using return_type_updateTask = std::nullptr_t;
}

namespace api::param 
{
struct getTask {
    std::string taskId; // Task Id.
};
struct getTasks {
    std::optional<bool> isHidden; // Optional filter tasks that are hidden, or not.
    std::optional<bool> isEnabled; // Optional filter tasks that are enabled, or not.
};
struct startTask {
    std::string taskId; // Task Id.
};
struct stopTask {
    std::string taskId; // Task Id.
};
struct updateTask {
    std::string taskId; // Task Id.
    std::vector<OAITaskTriggerInfo> body; // Triggers.
};
}

namespace api 
{
// Get task by id.
struct getTask {
public:
    using in_type                      = param::getTask;
    using out_type                     = model::return_type_getTask;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/ScheduledTasks/{}"sv,
            input.taskId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAITaskInfo
 * returnFormat: 
 * returnBaseType: OAITaskInfo
 * returnContainer: 
 * baseName: ScheduledTasks
 * defaultResponse: OAITaskInfo()
 */
};
// Get tasks.
struct getTasks {
public:
    using in_type                      = param::getTasks;
    using out_type                     = model::return_type_getTasks;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/ScheduledTasks"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.isHidden)
            p.set_param("isHidden", convert_from<std::string>(input.isHidden.value()));
        if(input.isEnabled)
            p.set_param("isEnabled", convert_from<std::string>(input.isEnabled.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;OAITaskInfo&gt;
 * returnFormat: 
 * returnBaseType: OAITaskInfo
 * returnContainer: array
 * baseName: ScheduledTasks
 * defaultResponse: {}
 */
};
// Start specified task.
struct startTask {
public:
    using in_type                      = param::startTask;
    using out_type                     = model::return_type_startTask;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/ScheduledTasks/Running/{}"sv,
            input.taskId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: ScheduledTasks
 * defaultResponse: 
 */
};
// Stop specified task.
struct stopTask {
public:
    using in_type                      = param::stopTask;
    using out_type                     = model::return_type_stopTask;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/ScheduledTasks/Running/{}"sv,
            input.taskId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: ScheduledTasks
 * defaultResponse: 
 */
};
// Update specified task triggers.
struct updateTask {
public:
    using in_type                      = param::updateTask;
    using out_type                     = model::return_type_updateTask;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/ScheduledTasks/{}/Triggers"sv,
            input.taskId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: ScheduledTasks
 * defaultResponse: 
 */
};
}
}
