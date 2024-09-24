#pragma once

/*
 * OAIProfileCondition.h
 * name: ProfileCondition
 * schemaName: ProfileCondition
 * classFilename: ProfileCondition
 * classVarName: ProfileCondition
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIProfileConditionType.h"
#include "jellyfin/model/OAIProfileConditionValue.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIProfileCondition {
    public:
    
        OAIProfileConditionType Condition;

        OAIProfileConditionValue Property;

        std::optional<std::string> Value;

        bool IsRequired;

        OAIProfileCondition();
        ~OAIProfileCondition();
    };
    extern void to_json(json_t&, const OAIProfileCondition&);
    extern void from_json(const json_t&, OAIProfileCondition&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIProfileCondition);
