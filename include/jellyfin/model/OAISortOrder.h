#pragma once

/*
 * OAISortOrder.h
 * name: SortOrder
 * schemaName: SortOrder
 * classFilename: SortOrder
 * classVarName: SortOrder
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * An enum representing the sorting order.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAISortOrder {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        ASCENDING, // Ascending
        DESCENDING, // Descending
    };
    extern void to_json(json_t&, const OAISortOrder&);
    extern void from_json(const json_t&, OAISortOrder&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISortOrder);
