#pragma once

/*
 * OAISeriesStatus.h
 * name: SeriesStatus
 * schemaName: SeriesStatus
 * classFilename: SeriesStatus
 * classVarName: SeriesStatus
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * The status of a series.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAISeriesStatus {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        CONTINUING, // Continuing
        ENDED, // Ended
        UNRELEASED, // Unreleased
    };
    extern void to_json(json_t&, const OAISeriesStatus&);
    extern void from_json(const json_t&, OAISeriesStatus&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISeriesStatus);
