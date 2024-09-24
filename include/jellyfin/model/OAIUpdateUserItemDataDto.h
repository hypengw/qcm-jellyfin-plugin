#pragma once

/*
 * OAIUpdateUserItemDataDto.h
 * name: UpdateUserItemDataDto
 * schemaName: UpdateUserItemDataDto
 * classFilename: UpdateUserItemDataDto
 * classVarName: UpdateUserItemDataDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * This is used by the api to get information about a item user data.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIUpdateUserItemDataDto {
    public:
    
        // Gets or sets the rating.
        std::optional<double> Rating;

        // Gets or sets the played percentage.
        std::optional<double> PlayedPercentage;

        // Gets or sets the unplayed item count.
        std::optional<std::int32_t> UnplayedItemCount;

        // Gets or sets the playback position ticks.
        std::optional<std::int64_t> PlaybackPositionTicks;

        // Gets or sets the play count.
        std::optional<std::int32_t> PlayCount;

        // Gets or sets a value indicating whether this instance is favorite.
        std::optional<bool> IsFavorite;

        // Gets or sets a value indicating whether this MediaBrowser.Model.Dto.UpdateUserItemDataDto is likes.
        std::optional<bool> Likes;

        // Gets or sets the last played date.
        std::optional<std::string> LastPlayedDate;

        // Gets or sets a value indicating whether this MediaBrowser.Model.Dto.UserItemDataDto is played.
        std::optional<bool> Played;

        // Gets or sets the key.
        std::optional<std::string> Key;

        // Gets or sets the item identifier.
        std::optional<std::string> ItemId;

        OAIUpdateUserItemDataDto();
        ~OAIUpdateUserItemDataDto();
    };
    extern void to_json(json_t&, const OAIUpdateUserItemDataDto&);
    extern void from_json(const json_t&, OAIUpdateUserItemDataDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIUpdateUserItemDataDto);
