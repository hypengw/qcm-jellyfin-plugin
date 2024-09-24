#pragma once

/*
 * OAIProfileConditionType.h
 * name: ProfileConditionType
 * schemaName: ProfileConditionType
 * classFilename: ProfileConditionType
 * classVarName: ProfileConditionType
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

    enum class OAIProfileConditionType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        EQUALS, // Equals
        NOTEQUALS, // NotEquals
        LESSTHANEQUAL, // LessThanEqual
        GREATERTHANEQUAL, // GreaterThanEqual
        EQUALSANY, // EqualsAny
    };
    extern void to_json(json_t&, const OAIProfileConditionType&);
    extern void from_json(const json_t&, OAIProfileConditionType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIProfileConditionType);
