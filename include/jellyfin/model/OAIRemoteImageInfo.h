#pragma once

/*
 * OAIRemoteImageInfo.h
 * name: RemoteImageInfo
 * schemaName: RemoteImageInfo
 * classFilename: RemoteImageInfo
 * classVarName: RemoteImageInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class RemoteImageInfo.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIImageType.h"
#include "jellyfin/model/OAIRatingType.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIRemoteImageInfo {
    public:
    
        // Gets or sets the name of the provider.
        std::optional<std::string> ProviderName;

        // Gets or sets the URL.
        std::optional<std::string> Url;

        // Gets or sets a url used for previewing a smaller version.
        std::optional<std::string> ThumbnailUrl;

        // Gets or sets the height.
        std::optional<std::int32_t> Height;

        // Gets or sets the width.
        std::optional<std::int32_t> Width;

        // Gets or sets the community rating.
        std::optional<double> CommunityRating;

        // Gets or sets the vote count.
        std::optional<std::int32_t> VoteCount;

        // Gets or sets the language.
        std::optional<std::string> Language;

        // Gets or sets the type.
        OAIImageType Type;

        // Gets or sets the type of the rating.
        OAIRatingType RatingType;

        OAIRemoteImageInfo();
        ~OAIRemoteImageInfo();
    };
    extern void to_json(json_t&, const OAIRemoteImageInfo&);
    extern void from_json(const json_t&, OAIRemoteImageInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIRemoteImageInfo);
