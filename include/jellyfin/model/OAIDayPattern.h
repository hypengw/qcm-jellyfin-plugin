#pragma once

/*
 * OAIDayPattern.h
 * name: DayPattern
 * schemaName: DayPattern
 * classFilename: DayPattern
 * classVarName: DayPattern
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

    enum class OAIDayPattern {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        DAILY, // Daily
        WEEKDAYS, // Weekdays
        WEEKENDS, // Weekends
    };
    extern void to_json(json_t&, const OAIDayPattern&);
    extern void from_json(const json_t&, OAIDayPattern&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIDayPattern);
