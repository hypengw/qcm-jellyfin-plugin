#pragma once

/*
 * OAIDeviceInfoQueryResult.h
 * name: DeviceInfoQueryResult
 * schemaName: DeviceInfoQueryResult
 * classFilename: DeviceInfoQueryResult
 * classVarName: DeviceInfoQueryResult
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIDeviceInfo.h"
#include <cstdint>
#include <vector>



namespace jellyfin::model {
class OAIDeviceInfo;


    class OAIDeviceInfoQueryResult {
    public:
    
        // Gets or sets the items.
        std::optional<std::vector<OAIDeviceInfo>> Items;

        // Gets or sets the total number of records available.
        std::int32_t TotalRecordCount;

        // Gets or sets the index of the first record in Items.
        std::int32_t StartIndex;

        OAIDeviceInfoQueryResult();
        ~OAIDeviceInfoQueryResult();
    };
    extern void to_json(json_t&, const OAIDeviceInfoQueryResult&);
    extern void from_json(const json_t&, OAIDeviceInfoQueryResult&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIDeviceInfoQueryResult);
