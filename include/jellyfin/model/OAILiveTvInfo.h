#pragma once

/*
 * OAILiveTvInfo.h
 * name: LiveTvInfo
 * schemaName: LiveTvInfo
 * classFilename: LiveTvInfo
 * classVarName: LiveTvInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAILiveTvServiceInfo.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAILiveTvServiceInfo;


    class OAILiveTvInfo {
    public:
    
        // Gets or sets the services.
        std::vector<OAILiveTvServiceInfo> Services;

        // Gets or sets a value indicating whether this instance is enabled.
        bool IsEnabled;

        // Gets or sets the enabled users.
        std::vector<std::string> EnabledUsers;

        OAILiveTvInfo();
        ~OAILiveTvInfo();
    };
    extern void to_json(json_t&, const OAILiveTvInfo&);
    extern void from_json(const json_t&, OAILiveTvInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAILiveTvInfo);
