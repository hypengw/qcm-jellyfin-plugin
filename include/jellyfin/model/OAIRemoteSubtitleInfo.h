#pragma once

/*
 * OAIRemoteSubtitleInfo.h
 * name: RemoteSubtitleInfo
 * schemaName: RemoteSubtitleInfo
 * classFilename: RemoteSubtitleInfo
 * classVarName: RemoteSubtitleInfo
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



namespace jellyfin::model {


    class OAIRemoteSubtitleInfo {
    public:
    
        std::optional<std::string> ThreeLetterISOLanguageName;

        std::optional<std::string> Id;

        std::optional<std::string> ProviderName;

        std::optional<std::string> Name;

        std::optional<std::string> Format;

        std::optional<std::string> Author;

        std::optional<std::string> Comment;

        std::optional<std::string> DateCreated;

        std::optional<float> CommunityRating;

        std::optional<float> FrameRate;

        std::optional<std::int32_t> DownloadCount;

        std::optional<bool> IsHashMatch;

        std::optional<bool> AiTranslated;

        std::optional<bool> MachineTranslated;

        std::optional<bool> Forced;

        std::optional<bool> HearingImpaired;

        OAIRemoteSubtitleInfo();
        ~OAIRemoteSubtitleInfo();
    };
    extern void to_json(json_t&, const OAIRemoteSubtitleInfo&);
    extern void from_json(const json_t&, OAIRemoteSubtitleInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIRemoteSubtitleInfo);
