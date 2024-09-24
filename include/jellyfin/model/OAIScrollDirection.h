#pragma once

/*
 * OAIScrollDirection.h
 * name: ScrollDirection
 * schemaName: ScrollDirection
 * classFilename: ScrollDirection
 * classVarName: ScrollDirection
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * An enum representing the axis that should be scrolled.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIScrollDirection {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        HORIZONTAL, // Horizontal
        VERTICAL, // Vertical
    };
    extern void to_json(json_t&, const OAIScrollDirection&);
    extern void from_json(const json_t&, OAIScrollDirection&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIScrollDirection);
