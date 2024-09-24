#pragma once

/*
 * OAILiveTvOptions.h
 * name: LiveTvOptions
 * schemaName: LiveTvOptions
 * classFilename: LiveTvOptions
 * classVarName: LiveTvOptions
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIListingsProviderInfo.h"
#include "jellyfin/model/OAITunerHostInfo.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAITunerHostInfo;
class OAIListingsProviderInfo;


    class OAILiveTvOptions {
    public:
    
        std::optional<std::int32_t> GuideDays;

        std::optional<std::string> RecordingPath;

        std::optional<std::string> MovieRecordingPath;

        std::optional<std::string> SeriesRecordingPath;

        bool EnableRecordingSubfolders;

        bool EnableOriginalAudioWithEncodedRecordings;

        std::optional<std::vector<OAITunerHostInfo>> TunerHosts;

        std::optional<std::vector<OAIListingsProviderInfo>> ListingProviders;

        std::int32_t PrePaddingSeconds;

        std::int32_t PostPaddingSeconds;

        std::optional<std::vector<std::string>> MediaLocationsCreated;

        std::optional<std::string> RecordingPostProcessor;

        std::optional<std::string> RecordingPostProcessorArguments;

        bool SaveRecordingNFO;

        bool SaveRecordingImages;

        OAILiveTvOptions();
        ~OAILiveTvOptions();
    };
    extern void to_json(json_t&, const OAILiveTvOptions&);
    extern void from_json(const json_t&, OAILiveTvOptions&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAILiveTvOptions);
