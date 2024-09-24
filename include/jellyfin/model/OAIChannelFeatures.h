#pragma once

/*
 * OAIChannelFeatures.h
 * name: ChannelFeatures
 * schemaName: ChannelFeatures
 * classFilename: ChannelFeatures
 * classVarName: ChannelFeatures
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIChannelItemSortField.h"
#include "jellyfin/model/OAIChannelMediaContentType.h"
#include "jellyfin/model/OAIChannelMediaType.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {


    class OAIChannelFeatures {
    public:
    
        // Gets or sets the name.
        std::string Name;

        // Gets or sets the identifier.
        std::string Id;

        // Gets or sets a value indicating whether this instance can search.
        bool CanSearch;

        // Gets or sets the media types.
        std::vector<OAIChannelMediaType> MediaTypes;

        // Gets or sets the content types.
        std::vector<OAIChannelMediaContentType> ContentTypes;

        // Gets or sets the maximum number of records the channel allows retrieving at a time.
        std::optional<std::int32_t> MaxPageSize;

        // Gets or sets the automatic refresh levels.
        std::optional<std::int32_t> AutoRefreshLevels;

        // Gets or sets the default sort orders.
        std::vector<OAIChannelItemSortField> DefaultSortFields;

        // Gets or sets a value indicating whether a sort ascending/descending toggle is supported.
        bool SupportsSortOrderToggle;

        // Gets or sets a value indicating whether [supports latest media].
        bool SupportsLatestMedia;

        // Gets or sets a value indicating whether this instance can filter.
        bool CanFilter;

        // Gets or sets a value indicating whether [supports content downloading].
        bool SupportsContentDownloading;

        OAIChannelFeatures();
        ~OAIChannelFeatures();
    };
    extern void to_json(json_t&, const OAIChannelFeatures&);
    extern void from_json(const json_t&, OAIChannelFeatures&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIChannelFeatures);
