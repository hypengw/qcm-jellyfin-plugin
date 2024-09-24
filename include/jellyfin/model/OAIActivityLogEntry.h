#pragma once

/*
 * OAIActivityLogEntry.h
 * name: ActivityLogEntry
 * schemaName: ActivityLogEntry
 * classFilename: ActivityLogEntry
 * classVarName: ActivityLogEntry
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * An activity log entry.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAILogLevel.h"
#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIActivityLogEntry {
    public:
    
        // Gets or sets the identifier.
        std::int64_t Id;

        // Gets or sets the name.
        std::string Name;

        // Gets or sets the overview.
        std::optional<std::string> Overview;

        // Gets or sets the short overview.
        std::optional<std::string> ShortOverview;

        // Gets or sets the type.
        std::string Type;

        // Gets or sets the item identifier.
        std::optional<std::string> ItemId;

        // Gets or sets the date.
        std::string Date;

        // Gets or sets the user identifier.
        std::string UserId;

        // Gets or sets the user primary image tag.
        [[deprecated]] std::optional<std::string> UserPrimaryImageTag;

        // Gets or sets the log severity.
        OAILogLevel Severity;

        OAIActivityLogEntry();
        ~OAIActivityLogEntry();
    };
    extern void to_json(json_t&, const OAIActivityLogEntry&);
    extern void from_json(const json_t&, OAIActivityLogEntry&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIActivityLogEntry);
