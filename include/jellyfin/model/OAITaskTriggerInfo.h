#pragma once

/*
 * OAITaskTriggerInfo.h
 * name: TaskTriggerInfo
 * schemaName: TaskTriggerInfo
 * classFilename: TaskTriggerInfo
 * classVarName: TaskTriggerInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class TaskTriggerInfo.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIDayOfWeek.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAITaskTriggerInfo {
    public:
    
        // Gets or sets the type.
        std::optional<std::string> Type;

        // Gets or sets the time of day.
        std::optional<std::int64_t> TimeOfDayTicks;

        // Gets or sets the interval.
        std::optional<std::int64_t> IntervalTicks;

        // Gets or sets the day of week.
        std::optional<OAIDayOfWeek> DayOfWeek;

        // Gets or sets the maximum runtime ticks.
        std::optional<std::int64_t> MaxRuntimeTicks;

        OAITaskTriggerInfo();
        ~OAITaskTriggerInfo();
    };
    extern void to_json(json_t&, const OAITaskTriggerInfo&);
    extern void from_json(const json_t&, OAITaskTriggerInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITaskTriggerInfo);
