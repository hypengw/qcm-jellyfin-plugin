#pragma once

/*
 * OAIQueueRequestDto.h
 * name: QueueRequestDto
 * schemaName: QueueRequestDto
 * classFilename: QueueRequestDto
 * classVarName: QueueRequestDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class QueueRequestDto.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIGroupQueueMode.h"
#include <string>
#include <vector>



namespace jellyfin::model {


    class OAIQueueRequestDto {
    public:
    
        // Gets or sets the items to enqueue.
        std::vector<std::string> ItemIds;

        // Gets or sets the mode in which to add the new items.
        OAIGroupQueueMode Mode;

        OAIQueueRequestDto();
        ~OAIQueueRequestDto();
    };
    extern void to_json(json_t&, const OAIQueueRequestDto&);
    extern void from_json(const json_t&, OAIQueueRequestDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIQueueRequestDto);
