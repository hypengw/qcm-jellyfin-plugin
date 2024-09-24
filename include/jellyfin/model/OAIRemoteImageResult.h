#pragma once

/*
 * OAIRemoteImageResult.h
 * name: RemoteImageResult
 * schemaName: RemoteImageResult
 * classFilename: RemoteImageResult
 * classVarName: RemoteImageResult
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class RemoteImageResult.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIRemoteImageInfo.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIRemoteImageInfo;


    class OAIRemoteImageResult {
    public:
    
        // Gets or sets the images.
        std::optional<std::vector<OAIRemoteImageInfo>> Images;

        // Gets or sets the total record count.
        std::int32_t TotalRecordCount;

        // Gets or sets the providers.
        std::optional<std::vector<std::string>> Providers;

        OAIRemoteImageResult();
        ~OAIRemoteImageResult();
    };
    extern void to_json(json_t&, const OAIRemoteImageResult&);
    extern void from_json(const json_t&, OAIRemoteImageResult&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIRemoteImageResult);
