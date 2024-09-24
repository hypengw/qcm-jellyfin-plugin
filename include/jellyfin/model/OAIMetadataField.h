#pragma once

/*
 * OAIMetadataField.h
 * name: MetadataField
 * schemaName: MetadataField
 * classFilename: MetadataField
 * classVarName: MetadataField
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum MetadataFields.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIMetadataField {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        CAST, // Cast
        GENRES, // Genres
        PRODUCTIONLOCATIONS, // ProductionLocations
        STUDIOS, // Studios
        TAGS, // Tags
        NAME, // Name
        OVERVIEW, // Overview
        RUNTIME, // Runtime
        OFFICIALRATING, // OfficialRating
    };
    extern void to_json(json_t&, const OAIMetadataField&);
    extern void from_json(const json_t&, OAIMetadataField&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMetadataField);
