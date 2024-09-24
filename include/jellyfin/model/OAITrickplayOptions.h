#pragma once

/*
 * OAITrickplayOptions.h
 * name: TrickplayOptions
 * schemaName: TrickplayOptions
 * classFilename: TrickplayOptions
 * classVarName: TrickplayOptions
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class TrickplayOptions.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIProcessPriorityClass.h"
#include "jellyfin/model/OAITrickplayScanBehavior.h"
#include <cstdint>
#include <vector>



namespace jellyfin::model {


    class OAITrickplayOptions {
    public:
    
        // Gets or sets a value indicating whether or not to use HW acceleration.
        bool EnableHwAcceleration;

        // Gets or sets a value indicating whether or not to use HW accelerated MJPEG encoding.
        bool EnableHwEncoding;

        // Gets or sets the behavior used by trickplay provider on library scan/update.
        OAITrickplayScanBehavior ScanBehavior;

        // Gets or sets the process priority for the ffmpeg process.
        OAIProcessPriorityClass ProcessPriority;

        // Gets or sets the interval, in ms, between each new trickplay image.
        std::int32_t Interval;

        // Gets or sets the target width resolutions, in px, to generates preview images for.
        std::vector<std::int32_t> WidthResolutions;

        // Gets or sets number of tile images to allow in X dimension.
        std::int32_t TileWidth;

        // Gets or sets number of tile images to allow in Y dimension.
        std::int32_t TileHeight;

        // Gets or sets the ffmpeg output quality level.
        std::int32_t Qscale;

        // Gets or sets the jpeg quality to use for image tiles.
        std::int32_t JpegQuality;

        // Gets or sets the number of threads to be used by ffmpeg.
        std::int32_t ProcessThreads;

        OAITrickplayOptions();
        ~OAITrickplayOptions();
    };
    extern void to_json(json_t&, const OAITrickplayOptions&);
    extern void from_json(const json_t&, OAITrickplayOptions&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITrickplayOptions);
