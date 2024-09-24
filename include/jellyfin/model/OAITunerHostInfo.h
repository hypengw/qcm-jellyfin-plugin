#pragma once

/*
 * OAITunerHostInfo.h
 * name: TunerHostInfo
 * schemaName: TunerHostInfo
 * classFilename: TunerHostInfo
 * classVarName: TunerHostInfo
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


    class OAITunerHostInfo {
    public:
    
        std::optional<std::string> Id;

        std::optional<std::string> Url;

        std::optional<std::string> Type;

        std::optional<std::string> DeviceId;

        std::optional<std::string> FriendlyName;

        bool ImportFavoritesOnly;

        bool AllowHWTranscoding;

        bool EnableStreamLooping;

        std::optional<std::string> Source;

        std::int32_t TunerCount;

        std::optional<std::string> UserAgent;

        bool IgnoreDts;

        OAITunerHostInfo();
        ~OAITunerHostInfo();
    };
    extern void to_json(json_t&, const OAITunerHostInfo&);
    extern void from_json(const json_t&, OAITunerHostInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITunerHostInfo);
