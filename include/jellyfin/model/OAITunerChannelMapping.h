#pragma once

/*
 * OAITunerChannelMapping.h
 * name: TunerChannelMapping
 * schemaName: TunerChannelMapping
 * classFilename: TunerChannelMapping
 * classVarName: TunerChannelMapping
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAITunerChannelMapping {
    public:
    
        std::optional<std::string> Name;

        std::optional<std::string> ProviderChannelName;

        std::optional<std::string> ProviderChannelId;

        std::optional<std::string> Id;

        OAITunerChannelMapping();
        ~OAITunerChannelMapping();
    };
    extern void to_json(json_t&, const OAITunerChannelMapping&);
    extern void from_json(const json_t&, OAITunerChannelMapping&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITunerChannelMapping);
