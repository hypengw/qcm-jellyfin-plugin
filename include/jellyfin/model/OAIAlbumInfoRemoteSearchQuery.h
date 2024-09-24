#pragma once

/*
 * OAIAlbumInfoRemoteSearchQuery.h
 * name: AlbumInfoRemoteSearchQuery
 * schemaName: AlbumInfoRemoteSearchQuery
 * classFilename: AlbumInfoRemoteSearchQuery
 * classVarName: AlbumInfoRemoteSearchQuery
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIAlbumInfo.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {
class OAIAlbumInfo;


    class OAIAlbumInfoRemoteSearchQuery {
    public:
    
        std::optional<OAIAlbumInfo> SearchInfo;

        std::string ItemId;

        // Gets or sets the provider name to search within if set.
        std::optional<std::string> SearchProviderName;

        // Gets or sets a value indicating whether disabled providers should be included.
        bool IncludeDisabledProviders;

        OAIAlbumInfoRemoteSearchQuery();
        ~OAIAlbumInfoRemoteSearchQuery();
    };
    extern void to_json(json_t&, const OAIAlbumInfoRemoteSearchQuery&);
    extern void from_json(const json_t&, OAIAlbumInfoRemoteSearchQuery&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIAlbumInfoRemoteSearchQuery);
