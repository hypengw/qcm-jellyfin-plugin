#pragma once

/*
 * OAIMetadataRefreshMode.h
 * name: MetadataRefreshMode
 * schemaName: MetadataRefreshMode
 * classFilename: MetadataRefreshMode
 * classVarName: MetadataRefreshMode
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

    enum class OAIMetadataRefreshMode {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        NONE, // None
        VALIDATIONONLY, // ValidationOnly
        DEFAULT, // Default
        FULLREFRESH, // FullRefresh
    };
    extern void to_json(json_t&, const OAIMetadataRefreshMode&);
    extern void from_json(const json_t&, OAIMetadataRefreshMode&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMetadataRefreshMode);
