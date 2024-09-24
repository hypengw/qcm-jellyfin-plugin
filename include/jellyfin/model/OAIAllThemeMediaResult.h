#pragma once

/*
 * OAIAllThemeMediaResult.h
 * name: AllThemeMediaResult
 * schemaName: AllThemeMediaResult
 * classFilename: AllThemeMediaResult
 * classVarName: AllThemeMediaResult
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIThemeMediaResult.h"



namespace jellyfin::model {
class OAIThemeMediaResult;


    class OAIAllThemeMediaResult {
    public:
    
        // Class ThemeMediaResult.
        std::optional<OAIThemeMediaResult> ThemeVideosResult;

        // Class ThemeMediaResult.
        std::optional<OAIThemeMediaResult> ThemeSongsResult;

        // Class ThemeMediaResult.
        std::optional<OAIThemeMediaResult> SoundtrackSongsResult;

        OAIAllThemeMediaResult();
        ~OAIAllThemeMediaResult();
    };
    extern void to_json(json_t&, const OAIAllThemeMediaResult&);
    extern void from_json(const json_t&, OAIAllThemeMediaResult&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIAllThemeMediaResult);
