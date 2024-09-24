#pragma once

/*
 * OAILibraryOptions.h
 * name: LibraryOptions
 * schemaName: LibraryOptions
 * classFilename: LibraryOptions
 * classVarName: LibraryOptions
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIEmbeddedSubtitleOptions.h"
#include "jellyfin/model/OAIMediaPathInfo.h"
#include "jellyfin/model/OAITypeOptions.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIMediaPathInfo;
class OAITypeOptions;


    class OAILibraryOptions {
    public:
    
        bool Enabled;

        bool EnablePhotos;

        bool EnableRealtimeMonitor;

        bool EnableLUFSScan;

        bool EnableChapterImageExtraction;

        bool ExtractChapterImagesDuringLibraryScan;

        bool EnableTrickplayImageExtraction;

        bool ExtractTrickplayImagesDuringLibraryScan;

        std::vector<OAIMediaPathInfo> PathInfos;

        bool SaveLocalMetadata;

        [[deprecated]] bool EnableInternetProviders;

        bool EnableAutomaticSeriesGrouping;

        bool EnableEmbeddedTitles;

        bool EnableEmbeddedExtrasTitles;

        bool EnableEmbeddedEpisodeInfos;

        std::int32_t AutomaticRefreshIntervalDays;

        // Gets or sets the preferred metadata language.
        std::optional<std::string> PreferredMetadataLanguage;

        // Gets or sets the metadata country code.
        std::optional<std::string> MetadataCountryCode;

        std::string SeasonZeroDisplayName;

        std::optional<std::vector<std::string>> MetadataSavers;

        std::vector<std::string> DisabledLocalMetadataReaders;

        std::optional<std::vector<std::string>> LocalMetadataReaderOrder;

        std::vector<std::string> DisabledSubtitleFetchers;

        std::vector<std::string> SubtitleFetcherOrder;

        bool SkipSubtitlesIfEmbeddedSubtitlesPresent;

        bool SkipSubtitlesIfAudioTrackMatches;

        std::optional<std::vector<std::string>> SubtitleDownloadLanguages;

        bool RequirePerfectSubtitleMatch;

        bool SaveSubtitlesWithMedia;

        bool SaveLyricsWithMedia;

        bool AutomaticallyAddToCollection;

        // An enum representing the options to disable embedded subs.
        OAIEmbeddedSubtitleOptions AllowEmbeddedSubtitles;

        std::vector<OAITypeOptions> TypeOptions;

        OAILibraryOptions();
        ~OAILibraryOptions();
    };
    extern void to_json(json_t&, const OAILibraryOptions&);
    extern void from_json(const json_t&, OAILibraryOptions&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAILibraryOptions);
