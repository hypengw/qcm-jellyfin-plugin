#pragma once

/*
 * OAIContainerProfile.h
 * name: ContainerProfile
 * schemaName: ContainerProfile
 * classFilename: ContainerProfile
 * classVarName: ContainerProfile
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
#include "jellyfin/model/OAIProfileCondition.h"
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIProfileCondition;


    class OAIContainerProfile {
    public:
    
        OAIDlnaProfileType Type;

        std::vector<OAIProfileCondition> Conditions;

        std::string Container;

        OAIContainerProfile();
        ~OAIContainerProfile();
    };
    extern void to_json(json_t&, const OAIContainerProfile&);
    extern void from_json(const json_t&, OAIContainerProfile&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIContainerProfile);
