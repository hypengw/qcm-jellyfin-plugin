#pragma once

/*
 * OAITrickplayScanBehavior.h
 * name: TrickplayScanBehavior
 * schemaName: TrickplayScanBehavior
 * classFilename: TrickplayScanBehavior
 * classVarName: TrickplayScanBehavior
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum TrickplayScanBehavior.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAITrickplayScanBehavior {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        BLOCKING, // Blocking
        NONBLOCKING, // NonBlocking
    };
    extern void to_json(json_t&, const OAITrickplayScanBehavior&);
    extern void from_json(const json_t&, OAITrickplayScanBehavior&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITrickplayScanBehavior);
