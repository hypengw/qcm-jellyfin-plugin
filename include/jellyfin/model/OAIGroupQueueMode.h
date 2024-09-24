#pragma once

/*
 * OAIGroupQueueMode.h
 * name: GroupQueueMode
 * schemaName: GroupQueueMode
 * classFilename: GroupQueueMode
 * classVarName: GroupQueueMode
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum GroupQueueMode.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIGroupQueueMode {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        QUEUE, // Queue
        QUEUENEXT, // QueueNext
    };
    extern void to_json(json_t&, const OAIGroupQueueMode&);
    extern void from_json(const json_t&, OAIGroupQueueMode&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIGroupQueueMode);
