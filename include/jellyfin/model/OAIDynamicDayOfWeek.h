#pragma once

/*
 * OAIDynamicDayOfWeek.h
 * name: DynamicDayOfWeek
 * schemaName: DynamicDayOfWeek
 * classFilename: DynamicDayOfWeek
 * classVarName: DynamicDayOfWeek
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * An enum that represents a day of the week, weekdays, weekends, or all days.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIDynamicDayOfWeek {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        SUNDAY, // Sunday
        MONDAY, // Monday
        TUESDAY, // Tuesday
        WEDNESDAY, // Wednesday
        THURSDAY, // Thursday
        FRIDAY, // Friday
        SATURDAY, // Saturday
        EVERYDAY, // Everyday
        WEEKDAY, // Weekday
        WEEKEND, // Weekend
    };
    extern void to_json(json_t&, const OAIDynamicDayOfWeek&);
    extern void from_json(const json_t&, OAIDynamicDayOfWeek&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIDynamicDayOfWeek);
