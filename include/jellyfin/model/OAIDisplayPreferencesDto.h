#pragma once

/*
 * OAIDisplayPreferencesDto.h
 * name: DisplayPreferencesDto
 * schemaName: DisplayPreferencesDto
 * classFilename: DisplayPreferencesDto
 * classVarName: DisplayPreferencesDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Defines the display preferences for any item that supports them (usually Folders).
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIScrollDirection.h"
#include "jellyfin/model/OAISortOrder.h"
#include <cstdint>
#include <map>
#include <string>



namespace jellyfin::model {


    class OAIDisplayPreferencesDto {
    public:
    
        // Gets or sets the user id.
        std::optional<std::string> Id;

        // Gets or sets the type of the view.
        std::optional<std::string> ViewType;

        // Gets or sets the sort by.
        std::optional<std::string> SortBy;

        // Gets or sets the index by.
        std::optional<std::string> IndexBy;

        // Gets or sets a value indicating whether [remember indexing].
        bool RememberIndexing;

        // Gets or sets the height of the primary image.
        std::int32_t PrimaryImageHeight;

        // Gets or sets the width of the primary image.
        std::int32_t PrimaryImageWidth;

        // Gets or sets the custom prefs.
        std::map<std::string, std::string> CustomPrefs;

        // Gets or sets the scroll direction.
        OAIScrollDirection ScrollDirection;

        // Gets or sets a value indicating whether to show backdrops on this item.
        bool ShowBackdrop;

        // Gets or sets a value indicating whether [remember sorting].
        bool RememberSorting;

        // Gets or sets the sort order.
        OAISortOrder SortOrder;

        // Gets or sets a value indicating whether [show sidebar].
        bool ShowSidebar;

        // Gets or sets the client.
        std::optional<std::string> Client;

        OAIDisplayPreferencesDto();
        ~OAIDisplayPreferencesDto();
    };
    extern void to_json(json_t&, const OAIDisplayPreferencesDto&);
    extern void from_json(const json_t&, OAIDisplayPreferencesDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIDisplayPreferencesDto);
