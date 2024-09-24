#pragma once

/*
 * OAIDirectPlayProfile.h
 * name: DirectPlayProfile
 * schemaName: DirectPlayProfile
 * classFilename: DirectPlayProfile
 * classVarName: DirectPlayProfile
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIDlnaProfileType.h"
#include <string>



namespace jellyfin::model {


    class OAIDirectPlayProfile {
    public:
    
        std::optional<std::string> Container;

        std::optional<std::string> AudioCodec;

        std::optional<std::string> VideoCodec;

        OAIDlnaProfileType Type;

        OAIDirectPlayProfile();
        ~OAIDirectPlayProfile();
    };
    extern void to_json(json_t&, const OAIDirectPlayProfile&);
    extern void from_json(const json_t&, OAIDirectPlayProfile&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIDirectPlayProfile);
