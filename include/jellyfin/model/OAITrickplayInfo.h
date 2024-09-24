#pragma once

/*
 * OAITrickplayInfo.h
 * name: TrickplayInfo
 * schemaName: TrickplayInfo
 * classFilename: TrickplayInfo
 * classVarName: TrickplayInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * An entity representing the metadata for a group of trickplay tiles.
 */


#include "jellyfin/type.h"


#include <cstdint>



namespace jellyfin::model {


    class OAITrickplayInfo {
    public:
    
        // Gets or sets width of an individual thumbnail.
        std::int32_t Width;

        // Gets or sets height of an individual thumbnail.
        std::int32_t Height;

        // Gets or sets amount of thumbnails per row.
        std::int32_t TileWidth;

        // Gets or sets amount of thumbnails per column.
        std::int32_t TileHeight;

        // Gets or sets total amount of non-black thumbnails.
        std::int32_t ThumbnailCount;

        // Gets or sets interval in milliseconds between each trickplay thumbnail.
        std::int32_t Interval;

        // Gets or sets peak bandwith usage in bits per second.
        std::int32_t Bandwidth;

        OAITrickplayInfo();
        ~OAITrickplayInfo();
    };
    extern void to_json(json_t&, const OAITrickplayInfo&);
    extern void from_json(const json_t&, OAITrickplayInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITrickplayInfo);
