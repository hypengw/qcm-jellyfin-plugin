#pragma once

/*
 * OAIProcessPriorityClass.h
 * name: ProcessPriorityClass
 * schemaName: ProcessPriorityClass
 * classFilename: ProcessPriorityClass
 * classVarName: ProcessPriorityClass
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

    enum class OAIProcessPriorityClass {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        NORMAL, // Normal
        IDLE, // Idle
        HIGH, // High
        REALTIME, // RealTime
        BELOWNORMAL, // BelowNormal
        ABOVENORMAL, // AboveNormal
    };
    extern void to_json(json_t&, const OAIProcessPriorityClass&);
    extern void from_json(const json_t&, OAIProcessPriorityClass&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIProcessPriorityClass);
