#pragma once

/*
 * OAIPlayQueueUpdateReason.h
 * name: PlayQueueUpdateReason
 * schemaName: PlayQueueUpdateReason
 * classFilename: PlayQueueUpdateReason
 * classVarName: PlayQueueUpdateReason
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum PlayQueueUpdateReason.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIPlayQueueUpdateReason {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        NEWPLAYLIST, // NewPlaylist
        SETCURRENTITEM, // SetCurrentItem
        REMOVEITEMS, // RemoveItems
        MOVEITEM, // MoveItem
        QUEUE, // Queue
        QUEUENEXT, // QueueNext
        NEXTITEM, // NextItem
        PREVIOUSITEM, // PreviousItem
        REPEATMODE, // RepeatMode
        SHUFFLEMODE, // ShuffleMode
    };
    extern void to_json(json_t&, const OAIPlayQueueUpdateReason&);
    extern void from_json(const json_t&, OAIPlayQueueUpdateReason&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPlayQueueUpdateReason);
