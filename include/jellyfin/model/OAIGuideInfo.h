#pragma once

/*
 * OAIGuideInfo.h
 * name: GuideInfo
 * schemaName: GuideInfo
 * classFilename: GuideInfo
 * classVarName: GuideInfo
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


    class OAIGuideInfo {
    public:
    
        // Gets or sets the start date.
        std::string StartDate;

        // Gets or sets the end date.
        std::string EndDate;

        OAIGuideInfo();
        ~OAIGuideInfo();
    };
    extern void to_json(json_t&, const OAIGuideInfo&);
    extern void from_json(const json_t&, OAIGuideInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIGuideInfo);
