#pragma once

/*
 * OAISubtitleOptions.h
 * name: SubtitleOptions
 * schemaName: SubtitleOptions
 * classFilename: SubtitleOptions
 * classVarName: SubtitleOptions
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {


    class OAISubtitleOptions {
    public:
    
        bool SkipIfEmbeddedSubtitlesPresent;

        bool SkipIfAudioTrackMatches;

        std::optional<std::vector<std::string>> DownloadLanguages;

        bool DownloadMovieSubtitles;

        bool DownloadEpisodeSubtitles;

        std::optional<std::string> OpenSubtitlesUsername;

        std::optional<std::string> OpenSubtitlesPasswordHash;

        bool IsOpenSubtitleVipAccount;

        bool RequirePerfectMatch;

        OAISubtitleOptions();
        ~OAISubtitleOptions();
    };
    extern void to_json(json_t&, const OAISubtitleOptions&);
    extern void from_json(const json_t&, OAISubtitleOptions&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISubtitleOptions);
