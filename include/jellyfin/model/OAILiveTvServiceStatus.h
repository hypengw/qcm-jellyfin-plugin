#pragma once

/*
 * OAILiveTvServiceStatus.h
 * name: LiveTvServiceStatus
 * schemaName: LiveTvServiceStatus
 * classFilename: LiveTvServiceStatus
 * classVarName: LiveTvServiceStatus
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

    enum class OAILiveTvServiceStatus {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        OK, // Ok
        UNAVAILABLE, // Unavailable
    };
    extern void to_json(json_t&, const OAILiveTvServiceStatus&);
    extern void from_json(const json_t&, OAILiveTvServiceStatus&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAILiveTvServiceStatus);
