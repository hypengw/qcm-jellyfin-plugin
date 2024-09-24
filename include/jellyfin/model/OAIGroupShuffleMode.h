#pragma once

/*
 * OAIGroupShuffleMode.h
 * name: GroupShuffleMode
 * schemaName: GroupShuffleMode
 * classFilename: GroupShuffleMode
 * classVarName: GroupShuffleMode
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum GroupShuffleMode.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIGroupShuffleMode {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        SORTED, // Sorted
        SHUFFLE, // Shuffle
    };
    extern void to_json(json_t&, const OAIGroupShuffleMode&);
    extern void from_json(const json_t&, OAIGroupShuffleMode&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIGroupShuffleMode);
