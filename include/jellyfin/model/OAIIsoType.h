#pragma once

/*
 * OAIIsoType.h
 * name: IsoType
 * schemaName: IsoType
 * classFilename: IsoType
 * classVarName: IsoType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum IsoType.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIIsoType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        DVD, // Dvd
        BLURAY, // BluRay
    };
    extern void to_json(json_t&, const OAIIsoType&);
    extern void from_json(const json_t&, OAIIsoType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIIsoType);
