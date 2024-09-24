#pragma once

/*
 * OAIExternalIdInfo.h
 * name: ExternalIdInfo
 * schemaName: ExternalIdInfo
 * classFilename: ExternalIdInfo
 * classVarName: ExternalIdInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Represents the external id information for serialization to the client.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIExternalIdMediaType.h"
#include <string>



namespace jellyfin::model {


    class OAIExternalIdInfo {
    public:
    
        // Gets or sets the display name of the external id provider (IE: IMDB, MusicBrainz, etc).
        std::string Name;

        // Gets or sets the unique key for this id. This key should be unique across all providers.
        std::string Key;

        // Gets or sets the specific media type for this id. This is used to distinguish between the different  external id types for providers with multiple ids.  A null value indicates there is no specific media type associated with the external id, or this is the  default id for the external provider so there is no need to specify a type.
        std::optional<OAIExternalIdMediaType> Type;

        // Gets or sets the URL format string.
        std::optional<std::string> UrlFormatString;

        OAIExternalIdInfo();
        ~OAIExternalIdInfo();
    };
    extern void to_json(json_t&, const OAIExternalIdInfo&);
    extern void from_json(const json_t&, OAIExternalIdInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIExternalIdInfo);
