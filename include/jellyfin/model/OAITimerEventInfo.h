#pragma once

/*
 * OAITimerEventInfo.h
 * name: TimerEventInfo
 * schemaName: TimerEventInfo
 * classFilename: TimerEventInfo
 * classVarName: TimerEventInfo
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


    class OAITimerEventInfo {
    public:
    
        std::string Id;

        std::optional<std::string> ProgramId;

        OAITimerEventInfo();
        ~OAITimerEventInfo();
    };
    extern void to_json(json_t&, const OAITimerEventInfo&);
    extern void from_json(const json_t&, OAITimerEventInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITimerEventInfo);
