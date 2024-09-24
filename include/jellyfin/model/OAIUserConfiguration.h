#pragma once

/*
 * OAIUserConfiguration.h
 * name: UserConfiguration
 * schemaName: UserConfiguration
 * classFilename: UserConfiguration
 * classVarName: UserConfiguration
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class UserConfiguration.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISubtitlePlaybackMode.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {


    class OAIUserConfiguration {
    public:
    
        // Gets or sets the audio language preference.
        std::optional<std::string> AudioLanguagePreference;

        // Gets or sets a value indicating whether [play default audio track].
        bool PlayDefaultAudioTrack;

        // Gets or sets the subtitle language preference.
        std::optional<std::string> SubtitleLanguagePreference;

        bool DisplayMissingEpisodes;

        std::vector<std::string> GroupedFolders;

        // An enum representing a subtitle playback mode.
        OAISubtitlePlaybackMode SubtitleMode;

        bool DisplayCollectionsView;

        bool EnableLocalPassword;

        std::vector<std::string> OrderedViews;

        std::vector<std::string> LatestItemsExcludes;

        std::vector<std::string> MyMediaExcludes;

        bool HidePlayedInLatest;

        bool RememberAudioSelections;

        bool RememberSubtitleSelections;

        bool EnableNextEpisodeAutoPlay;

        // Gets or sets the id of the selected cast receiver.
        std::optional<std::string> CastReceiverId;

        OAIUserConfiguration();
        ~OAIUserConfiguration();
    };
    extern void to_json(json_t&, const OAIUserConfiguration&);
    extern void from_json(const json_t&, OAIUserConfiguration&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIUserConfiguration);
