#pragma once
/*
 * OAILibraryApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIAllThemeMediaResult.h"
#include "jellyfin/model/OAIBaseItemDto.h"
#include "jellyfin/model/OAIBaseItemDtoQueryResult.h"
#include "jellyfin/model/OAICollectionType.h"
#include "jellyfin/model/OAIItemCounts.h"
#include "jellyfin/model/OAIItemFields.h"
#include "jellyfin/model/OAILibraryOptionsResultDto.h"
#include "jellyfin/model/OAIMediaUpdateInfoDto.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAIThemeMediaResult.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_deleteItem = std::nullptr_t;
using return_type_deleteItems = std::nullptr_t;
using return_type_getAncestors = std::vector<OAIBaseItemDto>;
using return_type_getCriticReviews = OAIBaseItemDtoQueryResult;
using return_type_getDownload = std::vector<std::byte>;
using return_type_getFile = std::vector<std::byte>;
using return_type_getItemCounts = OAIItemCounts;
using return_type_getLibraryOptionsInfo = OAILibraryOptionsResultDto;
using return_type_getMediaFolders = OAIBaseItemDtoQueryResult;
using return_type_getPhysicalPaths = std::vector<std::string>;
using return_type_getSimilarAlbums = OAIBaseItemDtoQueryResult;
using return_type_getSimilarArtists = OAIBaseItemDtoQueryResult;
using return_type_getSimilarItems = OAIBaseItemDtoQueryResult;
using return_type_getSimilarMovies = OAIBaseItemDtoQueryResult;
using return_type_getSimilarShows = OAIBaseItemDtoQueryResult;
using return_type_getSimilarTrailers = OAIBaseItemDtoQueryResult;
using return_type_getThemeMedia = OAIAllThemeMediaResult;
using return_type_getThemeSongs = OAIThemeMediaResult;
using return_type_getThemeVideos = OAIThemeMediaResult;
using return_type_postAddedMovies = std::nullptr_t;
using return_type_postAddedSeries = std::nullptr_t;
using return_type_postUpdatedMedia = std::nullptr_t;
using return_type_postUpdatedMovies = std::nullptr_t;
using return_type_postUpdatedSeries = std::nullptr_t;
using return_type_refreshLibrary = std::nullptr_t;
}

namespace api::param 
{
struct deleteItem {
    std::string itemId; // The item id.
};
struct deleteItems {
    std::optional<std::vector<std::string>> ids; // The item ids.
};
struct getAncestors {
    std::string itemId; // The item id.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
};
struct getCriticReviews {
    std::string itemId; // 
};
struct getDownload {
    std::string itemId; // The item id.
};
struct getFile {
    std::string itemId; // The item id.
};
struct getItemCounts {
    std::optional<std::string> userId; // Optional. Get counts from a specific user&#39;s library.
    std::optional<bool> isFavorite; // Optional. Get counts of favorite items.
};
struct getLibraryOptionsInfo {
    std::optional<OAICollectionType> libraryContentType; // Library content type.
    std::optional<bool> isNewLibrary; // Whether this is a new library.
};
struct getMediaFolders {
    std::optional<bool> isHidden; // Optional. Filter by folders that are marked hidden, or not.
};
struct getPhysicalPaths {
};
struct getSimilarAlbums {
    std::string itemId; // The item id.
    std::optional<std::vector<std::string>> excludeArtistIds; // Exclude artist ids.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output. This allows multiple, comma delimited. Options: Budget, Chapters, DateCreated, Genres, HomePageUrl, IndexOptions, MediaStreams, Overview, ParentId, Path, People, ProviderIds, PrimaryImageAspectRatio, Revenue, SortName, Studios, Taglines, TrailerUrls.
};
struct getSimilarArtists {
    std::string itemId; // The item id.
    std::optional<std::vector<std::string>> excludeArtistIds; // Exclude artist ids.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output. This allows multiple, comma delimited. Options: Budget, Chapters, DateCreated, Genres, HomePageUrl, IndexOptions, MediaStreams, Overview, ParentId, Path, People, ProviderIds, PrimaryImageAspectRatio, Revenue, SortName, Studios, Taglines, TrailerUrls.
};
struct getSimilarItems {
    std::string itemId; // The item id.
    std::optional<std::vector<std::string>> excludeArtistIds; // Exclude artist ids.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output. This allows multiple, comma delimited. Options: Budget, Chapters, DateCreated, Genres, HomePageUrl, IndexOptions, MediaStreams, Overview, ParentId, Path, People, ProviderIds, PrimaryImageAspectRatio, Revenue, SortName, Studios, Taglines, TrailerUrls.
};
struct getSimilarMovies {
    std::string itemId; // The item id.
    std::optional<std::vector<std::string>> excludeArtistIds; // Exclude artist ids.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output. This allows multiple, comma delimited. Options: Budget, Chapters, DateCreated, Genres, HomePageUrl, IndexOptions, MediaStreams, Overview, ParentId, Path, People, ProviderIds, PrimaryImageAspectRatio, Revenue, SortName, Studios, Taglines, TrailerUrls.
};
struct getSimilarShows {
    std::string itemId; // The item id.
    std::optional<std::vector<std::string>> excludeArtistIds; // Exclude artist ids.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output. This allows multiple, comma delimited. Options: Budget, Chapters, DateCreated, Genres, HomePageUrl, IndexOptions, MediaStreams, Overview, ParentId, Path, People, ProviderIds, PrimaryImageAspectRatio, Revenue, SortName, Studios, Taglines, TrailerUrls.
};
struct getSimilarTrailers {
    std::string itemId; // The item id.
    std::optional<std::vector<std::string>> excludeArtistIds; // Exclude artist ids.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output. This allows multiple, comma delimited. Options: Budget, Chapters, DateCreated, Genres, HomePageUrl, IndexOptions, MediaStreams, Overview, ParentId, Path, People, ProviderIds, PrimaryImageAspectRatio, Revenue, SortName, Studios, Taglines, TrailerUrls.
};
struct getThemeMedia {
    std::string itemId; // The item id.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
    std::optional<bool> inheritFromParent; // Optional. Determines whether or not parent items should be searched for theme media.
};
struct getThemeSongs {
    std::string itemId; // The item id.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
    std::optional<bool> inheritFromParent; // Optional. Determines whether or not parent items should be searched for theme media.
};
struct getThemeVideos {
    std::string itemId; // The item id.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
    std::optional<bool> inheritFromParent; // Optional. Determines whether or not parent items should be searched for theme media.
};
struct postAddedMovies {
    std::optional<std::string> tmdbId; // The tmdbId.
    std::optional<std::string> imdbId; // The imdbId.
};
struct postAddedSeries {
    std::optional<std::string> tvdbId; // The tvdbId.
};
struct postUpdatedMedia {
    OAIMediaUpdateInfoDto body; // The update paths.
};
struct postUpdatedMovies {
    std::optional<std::string> tmdbId; // The tmdbId.
    std::optional<std::string> imdbId; // The imdbId.
};
struct postUpdatedSeries {
    std::optional<std::string> tvdbId; // The tvdbId.
};
struct refreshLibrary {
};
}

namespace api 
{
// Deletes an item from the library and filesystem.
struct deleteItem {
public:
    using in_type                      = param::deleteItem;
    using out_type                     = model::return_type_deleteItem;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/Items/{}"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Library
 * defaultResponse: 
 */
};
// Deletes items from the library and filesystem.
struct deleteItems {
public:
    using in_type                      = param::deleteItems;
    using out_type                     = model::return_type_deleteItems;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return "/Items"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.ids)
            p.set_param("ids", input.ids.value());
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Library
 * defaultResponse: 
 */
};
// Gets all parents of an item.
struct getAncestors {
public:
    using in_type                      = param::getAncestors;
    using out_type                     = model::return_type_getAncestors;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/Ancestors"sv,
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
 * returnType: std::vector&lt;OAIBaseItemDto&gt;
 * returnFormat: 
 * returnBaseType: OAIBaseItemDto
 * returnContainer: array
 * baseName: Library
 * defaultResponse: {}
 */
};
// Gets critic review for an item.
struct getCriticReviews {
public:
    using in_type                      = param::getCriticReviews;
    using out_type                     = model::return_type_getCriticReviews;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/CriticReviews"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
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
 * baseName: Library
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Downloads item media.
struct getDownload {
public:
    using in_type                      = param::getDownload;
    using out_type                     = model::return_type_getDownload;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/Download"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Library
 * defaultResponse: {}
 */
};
// Get the original file of an item.
struct getFile {
public:
    using in_type                      = param::getFile;
    using out_type                     = model::return_type_getFile;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/File"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Library
 * defaultResponse: {}
 */
};
// Get item counts.
struct getItemCounts {
public:
    using in_type                      = param::getItemCounts;
    using out_type                     = model::return_type_getItemCounts;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Items/Counts"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.isFavorite)
            p.set_param("isFavorite", convert_from<std::string>(input.isFavorite.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIItemCounts
 * returnFormat: 
 * returnBaseType: OAIItemCounts
 * returnContainer: 
 * baseName: Library
 * defaultResponse: OAIItemCounts()
 */
};
// Gets the library options info.
struct getLibraryOptionsInfo {
public:
    using in_type                      = param::getLibraryOptionsInfo;
    using out_type                     = model::return_type_getLibraryOptionsInfo;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Libraries/AvailableOptions"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.libraryContentType)
            p.set_param("libraryContentType", convert_from<std::string>(input.libraryContentType.value()));
        if(input.isNewLibrary)
            p.set_param("isNewLibrary", convert_from<std::string>(input.isNewLibrary.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAILibraryOptionsResultDto
 * returnFormat: 
 * returnBaseType: OAILibraryOptionsResultDto
 * returnContainer: 
 * baseName: Library
 * defaultResponse: OAILibraryOptionsResultDto()
 */
};
// Gets all user media folders.
struct getMediaFolders {
public:
    using in_type                      = param::getMediaFolders;
    using out_type                     = model::return_type_getMediaFolders;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Library/MediaFolders"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.isHidden)
            p.set_param("isHidden", convert_from<std::string>(input.isHidden.value()));
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
 * baseName: Library
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets a list of physical paths from virtual folders.
struct getPhysicalPaths {
public:
    using in_type                      = param::getPhysicalPaths;
    using out_type                     = model::return_type_getPhysicalPaths;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Library/PhysicalPaths"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::string&gt;
 * returnFormat: 
 * returnBaseType: std::string
 * returnContainer: array
 * baseName: Library
 * defaultResponse: {}
 */
};
// Gets similar items.
struct getSimilarAlbums {
public:
    using in_type                      = param::getSimilarAlbums;
    using out_type                     = model::return_type_getSimilarAlbums;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Albums/{}/Similar"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.excludeArtistIds)
            p.set_param("excludeArtistIds", input.excludeArtistIds.value());
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
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
 * baseName: Library
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets similar items.
struct getSimilarArtists {
public:
    using in_type                      = param::getSimilarArtists;
    using out_type                     = model::return_type_getSimilarArtists;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Artists/{}/Similar"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.excludeArtistIds)
            p.set_param("excludeArtistIds", input.excludeArtistIds.value());
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
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
 * baseName: Library
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets similar items.
struct getSimilarItems {
public:
    using in_type                      = param::getSimilarItems;
    using out_type                     = model::return_type_getSimilarItems;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/Similar"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.excludeArtistIds)
            p.set_param("excludeArtistIds", input.excludeArtistIds.value());
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
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
 * baseName: Library
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets similar items.
struct getSimilarMovies {
public:
    using in_type                      = param::getSimilarMovies;
    using out_type                     = model::return_type_getSimilarMovies;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Movies/{}/Similar"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.excludeArtistIds)
            p.set_param("excludeArtistIds", input.excludeArtistIds.value());
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
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
 * baseName: Library
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets similar items.
struct getSimilarShows {
public:
    using in_type                      = param::getSimilarShows;
    using out_type                     = model::return_type_getSimilarShows;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Shows/{}/Similar"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.excludeArtistIds)
            p.set_param("excludeArtistIds", input.excludeArtistIds.value());
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
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
 * baseName: Library
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets similar items.
struct getSimilarTrailers {
public:
    using in_type                      = param::getSimilarTrailers;
    using out_type                     = model::return_type_getSimilarTrailers;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Trailers/{}/Similar"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.excludeArtistIds)
            p.set_param("excludeArtistIds", input.excludeArtistIds.value());
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
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
 * baseName: Library
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Get theme songs and videos for an item.
struct getThemeMedia {
public:
    using in_type                      = param::getThemeMedia;
    using out_type                     = model::return_type_getThemeMedia;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/ThemeMedia"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.inheritFromParent)
            p.set_param("inheritFromParent", convert_from<std::string>(input.inheritFromParent.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIAllThemeMediaResult
 * returnFormat: 
 * returnBaseType: OAIAllThemeMediaResult
 * returnContainer: 
 * baseName: Library
 * defaultResponse: OAIAllThemeMediaResult()
 */
};
// Get theme songs for an item.
struct getThemeSongs {
public:
    using in_type                      = param::getThemeSongs;
    using out_type                     = model::return_type_getThemeSongs;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/ThemeSongs"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.inheritFromParent)
            p.set_param("inheritFromParent", convert_from<std::string>(input.inheritFromParent.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIThemeMediaResult
 * returnFormat: 
 * returnBaseType: OAIThemeMediaResult
 * returnContainer: 
 * baseName: Library
 * defaultResponse: OAIThemeMediaResult()
 */
};
// Get theme videos for an item.
struct getThemeVideos {
public:
    using in_type                      = param::getThemeVideos;
    using out_type                     = model::return_type_getThemeVideos;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/ThemeVideos"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.inheritFromParent)
            p.set_param("inheritFromParent", convert_from<std::string>(input.inheritFromParent.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIThemeMediaResult
 * returnFormat: 
 * returnBaseType: OAIThemeMediaResult
 * returnContainer: 
 * baseName: Library
 * defaultResponse: OAIThemeMediaResult()
 */
};
// Reports that new movies have been added by an external source.
struct postAddedMovies {
public:
    using in_type                      = param::postAddedMovies;
    using out_type                     = model::return_type_postAddedMovies;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Library/Movies/Added"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tmdbId)
            p.set_param("tmdbId", convert_from<std::string>(input.tmdbId.value()));
        if(input.imdbId)
            p.set_param("imdbId", convert_from<std::string>(input.imdbId.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Library
 * defaultResponse: 
 */
};
// Reports that new episodes of a series have been added by an external source.
struct postAddedSeries {
public:
    using in_type                      = param::postAddedSeries;
    using out_type                     = model::return_type_postAddedSeries;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Library/Series/Added"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tvdbId)
            p.set_param("tvdbId", convert_from<std::string>(input.tvdbId.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Library
 * defaultResponse: 
 */
};
// Reports that new movies have been added by an external source.
struct postUpdatedMedia {
public:
    using in_type                      = param::postUpdatedMedia;
    using out_type                     = model::return_type_postUpdatedMedia;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Library/Media/Updated"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Library
 * defaultResponse: 
 */
};
// Reports that new movies have been added by an external source.
struct postUpdatedMovies {
public:
    using in_type                      = param::postUpdatedMovies;
    using out_type                     = model::return_type_postUpdatedMovies;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Library/Movies/Updated"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tmdbId)
            p.set_param("tmdbId", convert_from<std::string>(input.tmdbId.value()));
        if(input.imdbId)
            p.set_param("imdbId", convert_from<std::string>(input.imdbId.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Library
 * defaultResponse: 
 */
};
// Reports that new episodes of a series have been added by an external source.
struct postUpdatedSeries {
public:
    using in_type                      = param::postUpdatedSeries;
    using out_type                     = model::return_type_postUpdatedSeries;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Library/Series/Updated"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tvdbId)
            p.set_param("tvdbId", convert_from<std::string>(input.tvdbId.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Library
 * defaultResponse: 
 */
};
// Starts a library scan.
struct refreshLibrary {
public:
    using in_type                      = param::refreshLibrary;
    using out_type                     = model::return_type_refreshLibrary;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Library/Refresh"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Library
 * defaultResponse: 
 */
};
}
}
