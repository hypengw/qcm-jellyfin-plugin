#pragma once

/*
 * OAISyncPlayQueueItem.h
 * name: SyncPlayQueueItem
 * schemaName: SyncPlayQueueItem
 * classFilename: SyncPlayQueueItem
 * classVarName: SyncPlayQueueItem
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class QueueItem.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAISyncPlayQueueItem {
    public:
    
        // Gets the item identifier.
        std::string ItemId;

        // Gets the playlist identifier of the item.
        std::string PlaylistItemId;

        OAISyncPlayQueueItem();
        ~OAISyncPlayQueueItem();
    };
    extern void to_json(json_t&, const OAISyncPlayQueueItem&);
    extern void from_json(const json_t&, OAISyncPlayQueueItem&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISyncPlayQueueItem);
