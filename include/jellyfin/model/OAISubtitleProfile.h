#pragma once

/*
 * OAISubtitleProfile.h
 * name: SubtitleProfile
 * schemaName: SubtitleProfile
 * classFilename: SubtitleProfile
 * classVarName: SubtitleProfile
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAISubtitleDeliveryMethod.h"
#include <string>



namespace jellyfin::model {


    class OAISubtitleProfile {
    public:
    
        std::optional<std::string> Format;

        // Delivery method to use during playback of a specific subtitle format.
        OAISubtitleDeliveryMethod Method;

        std::optional<std::string> DidlMode;

        std::optional<std::string> Language;

        std::optional<std::string> Container;

        OAISubtitleProfile();
        ~OAISubtitleProfile();
    };
    extern void to_json(json_t&, const OAISubtitleProfile&);
    extern void from_json(const json_t&, OAISubtitleProfile&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISubtitleProfile);
