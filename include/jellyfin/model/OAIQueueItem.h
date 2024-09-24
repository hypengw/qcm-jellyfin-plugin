#pragma once

/*
 * OAIQueueItem.h
 * name: QueueItem
 * schemaName: QueueItem
 * classFilename: QueueItem
 * classVarName: QueueItem
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


    class OAIQueueItem {
    public:
    
        std::string Id;

        std::optional<std::string> PlaylistItemId;

        OAIQueueItem();
        ~OAIQueueItem();
    };
    extern void to_json(json_t&, const OAIQueueItem&);
    extern void from_json(const json_t&, OAIQueueItem&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIQueueItem);
