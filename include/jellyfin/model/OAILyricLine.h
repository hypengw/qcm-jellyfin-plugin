#pragma once

/*
 * OAILyricLine.h
 * name: LyricLine
 * schemaName: LyricLine
 * classFilename: LyricLine
 * classVarName: LyricLine
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Lyric model.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAILyricLine {
    public:
    
        // Gets the text of this lyric line.
        std::string Text;

        // Gets the start time in ticks.
        std::optional<std::int64_t> Start;

        OAILyricLine();
        ~OAILyricLine();
    };
    extern void to_json(json_t&, const OAILyricLine&);
    extern void from_json(const json_t&, OAILyricLine&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAILyricLine);
