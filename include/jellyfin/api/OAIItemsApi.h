#pragma once
/*
 * OAIItemsApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIBaseItemDtoQueryResult.h"
#include "jellyfin/model/OAIBaseItemKind.h"
#include "jellyfin/model/OAIImageType.h"
#include "jellyfin/model/OAIItemFields.h"
#include "jellyfin/model/OAIItemFilter.h"
#include "jellyfin/model/OAIItemSortBy.h"
#include "jellyfin/model/OAILocationType.h"
#include "jellyfin/model/OAIMediaType.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAISeriesStatus.h"
#include "jellyfin/model/OAISortOrder.h"
#include "jellyfin/model/OAIUpdateUserItemDataDto.h"
#include "jellyfin/model/OAIUserItemDataDto.h"
#include "jellyfin/model/OAIVideoType.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getItemUserData = OAIUserItemDataDto;
using return_type_getItems = OAIBaseItemDtoQueryResult;
using return_type_getResumeItems = OAIBaseItemDtoQueryResult;
using return_type_updateItemUserData = OAIUserItemDataDto;
}

namespace api::param 
{
struct getItemUserData {
    std::string itemId; // The item id.
    std::optional<std::string> userId; // The user id.
};
struct getItems {
    std::optional<std::string> userId; // The user id supplied as query parameter; this is required when not using an API key.
    std::optional<std::string> maxOfficialRating; // Optional filter by maximum official rating (PG, PG-13, TV-MA, etc).
    std::optional<bool> hasThemeSong; // Optional filter by items with theme songs.
    std::optional<bool> hasThemeVideo; // Optional filter by items with theme videos.
    std::optional<bool> hasSubtitles; // Optional filter by items with subtitles.
    std::optional<bool> hasSpecialFeature; // Optional filter by items with special features.
    std::optional<bool> hasTrailer; // Optional filter by items with trailers.
    std::optional<std::string> adjacentTo; // Optional. Return items that are siblings of a supplied item.
    std::optional<std::int32_t> parentIndexNumber; // Optional filter by parent index number.
    std::optional<bool> hasParentalRating; // Optional filter by items that have or do not have a parental rating.
    std::optional<bool> isHd; // Optional filter by items that are HD or not.
    std::optional<bool> is4K; // Optional filter by items that are 4K or not.
    std::optional<std::vector<OAILocationType>> locationTypes; // Optional. If specified, results will be filtered based on LocationType. This allows multiple, comma delimited.
    std::optional<std::vector<OAILocationType>> excludeLocationTypes; // Optional. If specified, results will be filtered based on the LocationType. This allows multiple, comma delimited.
    std::optional<bool> isMissing; // Optional filter by items that are missing episodes or not.
    std::optional<bool> isUnaired; // Optional filter by items that are unaired episodes or not.
    std::optional<double> minCommunityRating; // Optional filter by minimum community rating.
    std::optional<double> minCriticRating; // Optional filter by minimum critic rating.
    std::optional<std::string> minPremiereDate; // Optional. The minimum premiere date. Format &#x3D; ISO.
    std::optional<std::string> minDateLastSaved; // Optional. The minimum last saved date. Format &#x3D; ISO.
    std::optional<std::string> minDateLastSavedForUser; // Optional. The minimum last saved date for the current user. Format &#x3D; ISO.
    std::optional<std::string> maxPremiereDate; // Optional. The maximum premiere date. Format &#x3D; ISO.
    std::optional<bool> hasOverview; // Optional filter by items that have an overview or not.
    std::optional<bool> hasImdbId; // Optional filter by items that have an IMDb id or not.
    std::optional<bool> hasTmdbId; // Optional filter by items that have a TMDb id or not.
    std::optional<bool> hasTvdbId; // Optional filter by items that have a TVDb id or not.
    std::optional<bool> isMovie; // Optional filter for live tv movies.
    std::optional<bool> isSeries; // Optional filter for live tv series.
    std::optional<bool> isNews; // Optional filter for live tv news.
    std::optional<bool> isKids; // Optional filter for live tv kids.
    std::optional<bool> isSports; // Optional filter for live tv sports.
    std::optional<std::vector<std::string>> excludeItemIds; // Optional. If specified, results will be filtered by excluding item ids. This allows multiple, comma delimited.
    std::optional<std::int32_t> startIndex; // Optional. The record index to start at. All items with a lower index will be dropped from the results.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<bool> recursive; // When searching within folders, this determines whether or not the search will be recursive. true/false.
    std::optional<std::string> searchTerm; // Optional. Filter based on a search term.
    std::optional<std::vector<OAISortOrder>> sortOrder; // Sort Order - Ascending, Descending.
    std::optional<std::string> parentId; // Specify this to localize the search to a specific item or folder. Omit to use the root.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output. This allows multiple, comma delimited. Options: Budget, Chapters, DateCreated, Genres, HomePageUrl, IndexOptions, MediaStreams, Overview, ParentId, Path, People, ProviderIds, PrimaryImageAspectRatio, Revenue, SortName, Studios, Taglines.
    std::optional<std::vector<OAIBaseItemKind>> excludeItemTypes; // Optional. If specified, results will be filtered based on item type. This allows multiple, comma delimited.
    std::optional<std::vector<OAIBaseItemKind>> includeItemTypes; // Optional. If specified, results will be filtered based on the item type. This allows multiple, comma delimited.
    std::optional<std::vector<OAIItemFilter>> filters; // Optional. Specify additional filters to apply. This allows multiple, comma delimited. Options: IsFolder, IsNotFolder, IsUnplayed, IsPlayed, IsFavorite, IsResumable, Likes, Dislikes.
    std::optional<bool> isFavorite; // Optional filter by items that are marked as favorite, or not.
    std::optional<std::vector<OAIMediaType>> mediaTypes; // Optional filter by MediaType. Allows multiple, comma delimited.
    std::optional<std::vector<OAIImageType>> imageTypes; // Optional. If specified, results will be filtered based on those containing image types. This allows multiple, comma delimited.
    std::optional<std::vector<OAIItemSortBy>> sortBy; // Optional. Specify one or more sort orders, comma delimited. Options: Album, AlbumArtist, Artist, Budget, CommunityRating, CriticRating, DateCreated, DatePlayed, PlayCount, PremiereDate, ProductionYear, SortName, Random, Revenue, Runtime.
    std::optional<bool> isPlayed; // Optional filter by items that are played, or not.
    std::optional<std::vector<std::string>> genres; // Optional. If specified, results will be filtered based on genre. This allows multiple, pipe delimited.
    std::optional<std::vector<std::string>> officialRatings; // Optional. If specified, results will be filtered based on OfficialRating. This allows multiple, pipe delimited.
    std::optional<std::vector<std::string>> tags; // Optional. If specified, results will be filtered based on tag. This allows multiple, pipe delimited.
    std::optional<std::vector<std::int32_t>> years; // Optional. If specified, results will be filtered based on production year. This allows multiple, comma delimited.
    std::optional<bool> enableUserData; // Optional, include user data.
    std::optional<std::int32_t> imageTypeLimit; // Optional, the max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
    std::optional<std::string> person; // Optional. If specified, results will be filtered to include only those containing the specified person.
    std::optional<std::vector<std::string>> personIds; // Optional. If specified, results will be filtered to include only those containing the specified person id.
    std::optional<std::vector<std::string>> personTypes; // Optional. If specified, along with Person, results will be filtered to include only those containing the specified person and PersonType. Allows multiple, comma-delimited.
    std::optional<std::vector<std::string>> studios; // Optional. If specified, results will be filtered based on studio. This allows multiple, pipe delimited.
    std::optional<std::vector<std::string>> artists; // Optional. If specified, results will be filtered based on artists. This allows multiple, pipe delimited.
    std::optional<std::vector<std::string>> excludeArtistIds; // Optional. If specified, results will be filtered based on artist id. This allows multiple, pipe delimited.
    std::optional<std::vector<std::string>> artistIds; // Optional. If specified, results will be filtered to include only those containing the specified artist id.
    std::optional<std::vector<std::string>> albumArtistIds; // Optional. If specified, results will be filtered to include only those containing the specified album artist id.
    std::optional<std::vector<std::string>> contributingArtistIds; // Optional. If specified, results will be filtered to include only those containing the specified contributing artist id.
    std::optional<std::vector<std::string>> albums; // Optional. If specified, results will be filtered based on album. This allows multiple, pipe delimited.
    std::optional<std::vector<std::string>> albumIds; // Optional. If specified, results will be filtered based on album id. This allows multiple, pipe delimited.
    std::optional<std::vector<std::string>> ids; // Optional. If specific items are needed, specify a list of item id&#39;s to retrieve. This allows multiple, comma delimited.
    std::optional<std::vector<OAIVideoType>> videoTypes; // Optional filter by VideoType (videofile, dvd, bluray, iso). Allows multiple, comma delimited.
    std::optional<std::string> minOfficialRating; // Optional filter by minimum official rating (PG, PG-13, TV-MA, etc).
    std::optional<bool> isLocked; // Optional filter by items that are locked.
    std::optional<bool> isPlaceHolder; // Optional filter by items that are placeholders.
    std::optional<bool> hasOfficialRating; // Optional filter by items that have official ratings.
    std::optional<bool> collapseBoxSetItems; // Whether or not to hide items behind their boxsets.
    std::optional<std::int32_t> minWidth; // Optional. Filter by the minimum width of the item.
    std::optional<std::int32_t> minHeight; // Optional. Filter by the minimum height of the item.
    std::optional<std::int32_t> maxWidth; // Optional. Filter by the maximum width of the item.
    std::optional<std::int32_t> maxHeight; // Optional. Filter by the maximum height of the item.
    std::optional<bool> is3D; // Optional filter by items that are 3D, or not.
    std::optional<std::vector<OAISeriesStatus>> seriesStatus; // Optional filter by Series Status. Allows multiple, comma delimited.
    std::optional<std::string> nameStartsWithOrGreater; // Optional filter by items whose name is sorted equally or greater than a given input string.
    std::optional<std::string> nameStartsWith; // Optional filter by items whose name is sorted equally than a given input string.
    std::optional<std::string> nameLessThan; // Optional filter by items whose name is equally or lesser than a given input string.
    std::optional<std::vector<std::string>> studioIds; // Optional. If specified, results will be filtered based on studio id. This allows multiple, pipe delimited.
    std::optional<std::vector<std::string>> genreIds; // Optional. If specified, results will be filtered based on genre id. This allows multiple, pipe delimited.
    std::optional<bool> enableTotalRecordCount; // Optional. Enable the total record count.
    std::optional<bool> enableImages; // Optional, include image information in output.
};
struct getResumeItems {
    std::optional<std::string> userId; // The user id.
    std::optional<std::int32_t> startIndex; // The start index.
    std::optional<std::int32_t> limit; // The item limit.
    std::optional<std::string> searchTerm; // The search term.
    std::optional<std::string> parentId; // Specify this to localize the search to a specific item or folder. Omit to use the root.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output. This allows multiple, comma delimited. Options: Budget, Chapters, DateCreated, Genres, HomePageUrl, IndexOptions, MediaStreams, Overview, ParentId, Path, People, ProviderIds, PrimaryImageAspectRatio, Revenue, SortName, Studios, Taglines.
    std::optional<std::vector<OAIMediaType>> mediaTypes; // Optional. Filter by MediaType. Allows multiple, comma delimited.
    std::optional<bool> enableUserData; // Optional. Include user data.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
    std::optional<std::vector<OAIBaseItemKind>> excludeItemTypes; // Optional. If specified, results will be filtered based on item type. This allows multiple, comma delimited.
    std::optional<std::vector<OAIBaseItemKind>> includeItemTypes; // Optional. If specified, results will be filtered based on the item type. This allows multiple, comma delimited.
    std::optional<bool> enableTotalRecordCount; // Optional. Enable the total record count.
    std::optional<bool> enableImages; // Optional. Include image information in output.
    std::optional<bool> excludeActiveSessions; // Optional. Whether to exclude the currently active sessions.
};
struct updateItemUserData {
    std::string itemId; // The item id.
    OAIUpdateUserItemDataDto body; // New user data object.
    std::optional<std::string> userId; // The user id.
};
}

namespace api 
{
// Get Item User Data.
struct getItemUserData {
public:
    using in_type                      = param::getItemUserData;
    using out_type                     = model::return_type_getItemUserData;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/UserItems/{}/UserData"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIUserItemDataDto
 * returnFormat: 
 * returnBaseType: OAIUserItemDataDto
 * returnContainer: 
 * baseName: Items
 * defaultResponse: OAIUserItemDataDto()
 */
};
// Gets items based on a query.
struct getItems {
public:
    using in_type                      = param::getItems;
    using out_type                     = model::return_type_getItems;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Items"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.maxOfficialRating)
            p.set_param("maxOfficialRating", convert_from<std::string>(input.maxOfficialRating.value()));
        if(input.hasThemeSong)
            p.set_param("hasThemeSong", convert_from<std::string>(input.hasThemeSong.value()));
        if(input.hasThemeVideo)
            p.set_param("hasThemeVideo", convert_from<std::string>(input.hasThemeVideo.value()));
        if(input.hasSubtitles)
            p.set_param("hasSubtitles", convert_from<std::string>(input.hasSubtitles.value()));
        if(input.hasSpecialFeature)
            p.set_param("hasSpecialFeature", convert_from<std::string>(input.hasSpecialFeature.value()));
        if(input.hasTrailer)
            p.set_param("hasTrailer", convert_from<std::string>(input.hasTrailer.value()));
        if(input.adjacentTo)
            p.set_param("adjacentTo", convert_from<std::string>(input.adjacentTo.value()));
        if(input.parentIndexNumber)
            p.set_param("parentIndexNumber", convert_from<std::string>(input.parentIndexNumber.value()));
        if(input.hasParentalRating)
            p.set_param("hasParentalRating", convert_from<std::string>(input.hasParentalRating.value()));
        if(input.isHd)
            p.set_param("isHd", convert_from<std::string>(input.isHd.value()));
        if(input.is4K)
            p.set_param("is4K", convert_from<std::string>(input.is4K.value()));
        if(input.locationTypes)
            p.set_param("locationTypes", input.locationTypes.value());
        if(input.excludeLocationTypes)
            p.set_param("excludeLocationTypes", input.excludeLocationTypes.value());
        if(input.isMissing)
            p.set_param("isMissing", convert_from<std::string>(input.isMissing.value()));
        if(input.isUnaired)
            p.set_param("isUnaired", convert_from<std::string>(input.isUnaired.value()));
        if(input.minCommunityRating)
            p.set_param("minCommunityRating", convert_from<std::string>(input.minCommunityRating.value()));
        if(input.minCriticRating)
            p.set_param("minCriticRating", convert_from<std::string>(input.minCriticRating.value()));
        if(input.minPremiereDate)
            p.set_param("minPremiereDate", convert_from<std::string>(input.minPremiereDate.value()));
        if(input.minDateLastSaved)
            p.set_param("minDateLastSaved", convert_from<std::string>(input.minDateLastSaved.value()));
        if(input.minDateLastSavedForUser)
            p.set_param("minDateLastSavedForUser", convert_from<std::string>(input.minDateLastSavedForUser.value()));
        if(input.maxPremiereDate)
            p.set_param("maxPremiereDate", convert_from<std::string>(input.maxPremiereDate.value()));
        if(input.hasOverview)
            p.set_param("hasOverview", convert_from<std::string>(input.hasOverview.value()));
        if(input.hasImdbId)
            p.set_param("hasImdbId", convert_from<std::string>(input.hasImdbId.value()));
        if(input.hasTmdbId)
            p.set_param("hasTmdbId", convert_from<std::string>(input.hasTmdbId.value()));
        if(input.hasTvdbId)
            p.set_param("hasTvdbId", convert_from<std::string>(input.hasTvdbId.value()));
        if(input.isMovie)
            p.set_param("isMovie", convert_from<std::string>(input.isMovie.value()));
        if(input.isSeries)
            p.set_param("isSeries", convert_from<std::string>(input.isSeries.value()));
        if(input.isNews)
            p.set_param("isNews", convert_from<std::string>(input.isNews.value()));
        if(input.isKids)
            p.set_param("isKids", convert_from<std::string>(input.isKids.value()));
        if(input.isSports)
            p.set_param("isSports", convert_from<std::string>(input.isSports.value()));
        if(input.excludeItemIds)
            p.set_param("excludeItemIds", input.excludeItemIds.value());
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.recursive)
            p.set_param("recursive", convert_from<std::string>(input.recursive.value()));
        if(input.searchTerm)
            p.set_param("searchTerm", convert_from<std::string>(input.searchTerm.value()));
        if(input.sortOrder)
            p.set_param("sortOrder", input.sortOrder.value());
        if(input.parentId)
            p.set_param("parentId", convert_from<std::string>(input.parentId.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.excludeItemTypes)
            p.set_param("excludeItemTypes", input.excludeItemTypes.value());
        if(input.includeItemTypes)
            p.set_param("includeItemTypes", input.includeItemTypes.value());
        if(input.filters)
            p.set_param("filters", input.filters.value());
        if(input.isFavorite)
            p.set_param("isFavorite", convert_from<std::string>(input.isFavorite.value()));
        if(input.mediaTypes)
            p.set_param("mediaTypes", input.mediaTypes.value());
        if(input.imageTypes)
            p.set_param("imageTypes", input.imageTypes.value());
        if(input.sortBy)
            p.set_param("sortBy", input.sortBy.value());
        if(input.isPlayed)
            p.set_param("isPlayed", convert_from<std::string>(input.isPlayed.value()));
        if(input.genres)
            p.set_param("genres", input.genres.value());
        if(input.officialRatings)
            p.set_param("officialRatings", input.officialRatings.value());
        if(input.tags)
            p.set_param("tags", input.tags.value());
        if(input.years)
            p.set_param("years", input.years.value());
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
        if(input.person)
            p.set_param("person", convert_from<std::string>(input.person.value()));
        if(input.personIds)
            p.set_param("personIds", input.personIds.value());
        if(input.personTypes)
            p.set_param("personTypes", input.personTypes.value());
        if(input.studios)
            p.set_param("studios", input.studios.value());
        if(input.artists)
            p.set_param("artists", input.artists.value());
        if(input.excludeArtistIds)
            p.set_param("excludeArtistIds", input.excludeArtistIds.value());
        if(input.artistIds)
            p.set_param("artistIds", input.artistIds.value());
        if(input.albumArtistIds)
            p.set_param("albumArtistIds", input.albumArtistIds.value());
        if(input.contributingArtistIds)
            p.set_param("contributingArtistIds", input.contributingArtistIds.value());
        if(input.albums)
            p.set_param("albums", input.albums.value());
        if(input.albumIds)
            p.set_param("albumIds", input.albumIds.value());
        if(input.ids)
            p.set_param("ids", input.ids.value());
        if(input.videoTypes)
            p.set_param("videoTypes", input.videoTypes.value());
        if(input.minOfficialRating)
            p.set_param("minOfficialRating", convert_from<std::string>(input.minOfficialRating.value()));
        if(input.isLocked)
            p.set_param("isLocked", convert_from<std::string>(input.isLocked.value()));
        if(input.isPlaceHolder)
            p.set_param("isPlaceHolder", convert_from<std::string>(input.isPlaceHolder.value()));
        if(input.hasOfficialRating)
            p.set_param("hasOfficialRating", convert_from<std::string>(input.hasOfficialRating.value()));
        if(input.collapseBoxSetItems)
            p.set_param("collapseBoxSetItems", convert_from<std::string>(input.collapseBoxSetItems.value()));
        if(input.minWidth)
            p.set_param("minWidth", convert_from<std::string>(input.minWidth.value()));
        if(input.minHeight)
            p.set_param("minHeight", convert_from<std::string>(input.minHeight.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.is3D)
            p.set_param("is3D", convert_from<std::string>(input.is3D.value()));
        if(input.seriesStatus)
            p.set_param("seriesStatus", input.seriesStatus.value());
        if(input.nameStartsWithOrGreater)
            p.set_param("nameStartsWithOrGreater", convert_from<std::string>(input.nameStartsWithOrGreater.value()));
        if(input.nameStartsWith)
            p.set_param("nameStartsWith", convert_from<std::string>(input.nameStartsWith.value()));
        if(input.nameLessThan)
            p.set_param("nameLessThan", convert_from<std::string>(input.nameLessThan.value()));
        if(input.studioIds)
            p.set_param("studioIds", input.studioIds.value());
        if(input.genreIds)
            p.set_param("genreIds", input.genreIds.value());
        if(input.enableTotalRecordCount)
            p.set_param("enableTotalRecordCount", convert_from<std::string>(input.enableTotalRecordCount.value()));
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIBaseItemDtoQueryResult
 * returnFormat: 
 * returnBaseType: OAIBaseItemDtoQueryResult
 * returnContainer: 
 * baseName: Items
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets items based on a query.
struct getResumeItems {
public:
    using in_type                      = param::getResumeItems;
    using out_type                     = model::return_type_getResumeItems;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/UserItems/Resume"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.searchTerm)
            p.set_param("searchTerm", convert_from<std::string>(input.searchTerm.value()));
        if(input.parentId)
            p.set_param("parentId", convert_from<std::string>(input.parentId.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.mediaTypes)
            p.set_param("mediaTypes", input.mediaTypes.value());
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
        if(input.excludeItemTypes)
            p.set_param("excludeItemTypes", input.excludeItemTypes.value());
        if(input.includeItemTypes)
            p.set_param("includeItemTypes", input.includeItemTypes.value());
        if(input.enableTotalRecordCount)
            p.set_param("enableTotalRecordCount", convert_from<std::string>(input.enableTotalRecordCount.value()));
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.excludeActiveSessions)
            p.set_param("excludeActiveSessions", convert_from<std::string>(input.excludeActiveSessions.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIBaseItemDtoQueryResult
 * returnFormat: 
 * returnBaseType: OAIBaseItemDtoQueryResult
 * returnContainer: 
 * baseName: Items
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Update Item User Data.
struct updateItemUserData {
public:
    using in_type                      = param::updateItemUserData;
    using out_type                     = model::return_type_updateItemUserData;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/UserItems/{}/UserData"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: OAIUserItemDataDto
 * returnFormat: 
 * returnBaseType: OAIUserItemDataDto
 * returnContainer: 
 * baseName: Items
 * defaultResponse: OAIUserItemDataDto()
 */
};
}
}
