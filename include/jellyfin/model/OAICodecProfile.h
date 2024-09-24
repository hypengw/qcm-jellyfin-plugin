#pragma once

/*
 * OAICodecProfile.h
 * name: CodecProfile
 * schemaName: CodecProfile
 * classFilename: CodecProfile
 * classVarName: CodecProfile
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAICodecType.h"
#include "jellyfin/model/OAIProfileCondition.h"
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIProfileCondition;


    class OAICodecProfile {
    public:
    
        OAICodecType Type;

        std::optional<std::vector<OAIProfileCondition>> Conditions;

        std::optional<std::vector<OAIProfileCondition>> ApplyConditions;

        std::optional<std::string> Codec;

        std::optional<std::string> Container;

        OAICodecProfile();
        ~OAICodecProfile();
    };
    extern void to_json(json_t&, const OAICodecProfile&);
    extern void from_json(const json_t&, OAICodecProfile&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAICodecProfile);
