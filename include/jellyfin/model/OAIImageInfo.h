#pragma once

/*
 * OAIImageInfo.h
 * name: ImageInfo
 * schemaName: ImageInfo
 * classFilename: ImageInfo
 * classVarName: ImageInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class ImageInfo.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIImageType.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIImageInfo {
    public:
    
        // Gets or sets the type of the image.
        OAIImageType ImageType;

        // Gets or sets the index of the image.
        std::optional<std::int32_t> ImageIndex;

        // Gets or sets the image tag.
        std::optional<std::string> ImageTag;

        // Gets or sets the path.
        std::optional<std::string> Path;

        // Gets or sets the blurhash.
        std::optional<std::string> BlurHash;

        // Gets or sets the height.
        std::optional<std::int32_t> Height;

        // Gets or sets the width.
        std::optional<std::int32_t> Width;

        // Gets or sets the size.
        std::int64_t Size;

        OAIImageInfo();
        ~OAIImageInfo();
    };
    extern void to_json(json_t&, const OAIImageInfo&);
    extern void from_json(const json_t&, OAIImageInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIImageInfo);
