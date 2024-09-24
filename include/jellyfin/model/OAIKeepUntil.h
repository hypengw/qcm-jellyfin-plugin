#pragma once

/*
 * OAIKeepUntil.h
 * name: KeepUntil
 * schemaName: KeepUntil
 * classFilename: KeepUntil
 * classVarName: KeepUntil
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

    enum class OAIKeepUntil {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        UNTILDELETED, // UntilDeleted
        UNTILSPACENEEDED, // UntilSpaceNeeded
        UNTILWATCHED, // UntilWatched
        UNTILDATE, // UntilDate
    };
    extern void to_json(json_t&, const OAIKeepUntil&);
    extern void from_json(const json_t&, OAIKeepUntil&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIKeepUntil);
