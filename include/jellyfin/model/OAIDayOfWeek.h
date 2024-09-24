#pragma once

/*
 * OAIDayOfWeek.h
 * name: DayOfWeek
 * schemaName: DayOfWeek
 * classFilename: DayOfWeek
 * classVarName: DayOfWeek
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

    enum class OAIDayOfWeek {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        SUNDAY, // Sunday
        MONDAY, // Monday
        TUESDAY, // Tuesday
        WEDNESDAY, // Wednesday
        THURSDAY, // Thursday
        FRIDAY, // Friday
        SATURDAY, // Saturday
    };
    extern void to_json(json_t&, const OAIDayOfWeek&);
    extern void from_json(const json_t&, OAIDayOfWeek&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIDayOfWeek);
