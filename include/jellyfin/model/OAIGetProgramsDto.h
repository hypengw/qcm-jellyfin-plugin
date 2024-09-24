#pragma once

/*
 * OAIGetProgramsDto.h
 * name: GetProgramsDto
 * schemaName: GetProgramsDto
 * classFilename: GetProgramsDto
 * classVarName: GetProgramsDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Get programs dto.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIImageType.h"
#include "jellyfin/model/OAIItemFields.h"
#include "jellyfin/model/OAIItemSortBy.h"
#include "jellyfin/model/OAISortOrder.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {


    class OAIGetProgramsDto {
    public:
    
        // Gets or sets the channels to return guide information for.
        std::vector<std::string> ChannelIds;

        // Gets or sets optional. Filter by user id.
        std::optional<std::string> UserId;

        // Gets or sets the minimum premiere start date.  Optional.
        std::optional<std::string> MinStartDate;

        // Gets or sets filter by programs that have completed airing, or not.  Optional.
        std::optional<bool> HasAired;

        // Gets or sets filter by programs that are currently airing, or not.  Optional.
        std::optional<bool> IsAiring;

        // Gets or sets the maximum premiere start date.  Optional.
        std::optional<std::string> MaxStartDate;

        // Gets or sets the minimum premiere end date.  Optional.
        std::optional<std::string> MinEndDate;

        // Gets or sets the maximum premiere end date.  Optional.
        std::optional<std::string> MaxEndDate;

        // Gets or sets filter for movies.  Optional.
        std::optional<bool> IsMovie;

        // Gets or sets filter for series.  Optional.
        std::optional<bool> IsSeries;

        // Gets or sets filter for news.  Optional.
        std::optional<bool> IsNews;

        // Gets or sets filter for kids.  Optional.
        std::optional<bool> IsKids;

        // Gets or sets filter for sports.  Optional.
        std::optional<bool> IsSports;

        // Gets or sets the record index to start at. All items with a lower index will be dropped from the results.  Optional.
        std::optional<std::int32_t> StartIndex;

        // Gets or sets the maximum number of records to return.  Optional.
        std::optional<std::int32_t> Limit;

        // Gets or sets specify one or more sort orders, comma delimited. Options: Name, StartDate.  Optional.
        std::vector<OAIItemSortBy> SortBy;

        // Gets or sets sort Order - Ascending,Descending.
        std::vector<OAISortOrder> SortOrder;

        // Gets or sets the genres to return guide information for.
        std::vector<std::string> Genres;

        // Gets or sets the genre ids to return guide information for.
        std::vector<std::string> GenreIds;

        // Gets or sets include image information in output.  Optional.
        std::optional<bool> EnableImages;

        // Gets or sets a value indicating whether retrieve total record count.
        bool EnableTotalRecordCount;

        // Gets or sets the max number of images to return, per image type.  Optional.
        std::optional<std::int32_t> ImageTypeLimit;

        // Gets or sets the image types to include in the output.  Optional.
        std::vector<OAIImageType> EnableImageTypes;

        // Gets or sets include user data.  Optional.
        std::optional<bool> EnableUserData;

        // Gets or sets filter by series timer id.  Optional.
        std::optional<std::string> SeriesTimerId;

        // Gets or sets filter by library series id.  Optional.
        std::string LibrarySeriesId;

        // Gets or sets specify additional fields of information to return in the output. This allows multiple, comma delimited. Options: Budget, Chapters, DateCreated, Genres, HomePageUrl, IndexOptions, MediaStreams, Overview, ParentId, Path, People, ProviderIds, PrimaryImageAspectRatio, Revenue, SortName, Studios, Taglines.  Optional.
        std::vector<OAIItemFields> Fields;

        OAIGetProgramsDto();
        ~OAIGetProgramsDto();
    };
    extern void to_json(json_t&, const OAIGetProgramsDto&);
    extern void from_json(const json_t&, OAIGetProgramsDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIGetProgramsDto);
