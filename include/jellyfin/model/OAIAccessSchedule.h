#pragma once

/*
 * OAIAccessSchedule.h
 * name: AccessSchedule
 * schemaName: AccessSchedule
 * classFilename: AccessSchedule
 * classVarName: AccessSchedule
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * An entity representing a user&#39;s access schedule.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIDynamicDayOfWeek.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIAccessSchedule {
    public:
    
        // Gets the id of this instance.
        std::int32_t Id;

        // Gets the id of the associated user.
        std::string UserId;

        // Gets or sets the day of week.
        OAIDynamicDayOfWeek DayOfWeek;

        // Gets or sets the start hour.
        double StartHour;

        // Gets or sets the end hour.
        double EndHour;

        OAIAccessSchedule();
        ~OAIAccessSchedule();
    };
    extern void to_json(json_t&, const OAIAccessSchedule&);
    extern void from_json(const json_t&, OAIAccessSchedule&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIAccessSchedule);
