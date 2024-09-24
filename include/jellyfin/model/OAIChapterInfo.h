#pragma once

/*
 * OAIChapterInfo.h
 * name: ChapterInfo
 * schemaName: ChapterInfo
 * classFilename: ChapterInfo
 * classVarName: ChapterInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class ChapterInfo.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIChapterInfo {
    public:
    
        // Gets or sets the start position ticks.
        std::int64_t StartPositionTicks;

        // Gets or sets the name.
        std::optional<std::string> Name;

        // Gets or sets the image path.
        std::optional<std::string> ImagePath;

        std::string ImageDateModified;

        std::optional<std::string> ImageTag;

        OAIChapterInfo();
        ~OAIChapterInfo();
    };
    extern void to_json(json_t&, const OAIChapterInfo&);
    extern void from_json(const json_t&, OAIChapterInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIChapterInfo);
