#pragma once
/*
 * OAIItemLookupApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIAlbumInfoRemoteSearchQuery.h"
#include "jellyfin/model/OAIArtistInfoRemoteSearchQuery.h"
#include "jellyfin/model/OAIBookInfoRemoteSearchQuery.h"
#include "jellyfin/model/OAIBoxSetInfoRemoteSearchQuery.h"
#include "jellyfin/model/OAIExternalIdInfo.h"
#include "jellyfin/model/OAIMovieInfoRemoteSearchQuery.h"
#include "jellyfin/model/OAIMusicVideoInfoRemoteSearchQuery.h"
#include "jellyfin/model/OAIPersonLookupInfoRemoteSearchQuery.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAIRemoteSearchResult.h"
#include "jellyfin/model/OAISeriesInfoRemoteSearchQuery.h"
#include "jellyfin/model/OAITrailerInfoRemoteSearchQuery.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_applySearchCriteria = std::nullptr_t;
using return_type_getBookRemoteSearchResults = std::vector<OAIRemoteSearchResult>;
using return_type_getBoxSetRemoteSearchResults = std::vector<OAIRemoteSearchResult>;
using return_type_getExternalIdInfos = std::vector<OAIExternalIdInfo>;
using return_type_getMovieRemoteSearchResults = std::vector<OAIRemoteSearchResult>;
using return_type_getMusicAlbumRemoteSearchResults = std::vector<OAIRemoteSearchResult>;
using return_type_getMusicArtistRemoteSearchResults = std::vector<OAIRemoteSearchResult>;
using return_type_getMusicVideoRemoteSearchResults = std::vector<OAIRemoteSearchResult>;
using return_type_getPersonRemoteSearchResults = std::vector<OAIRemoteSearchResult>;
using return_type_getSeriesRemoteSearchResults = std::vector<OAIRemoteSearchResult>;
using return_type_getTrailerRemoteSearchResults = std::vector<OAIRemoteSearchResult>;
}

namespace api::param 
{
struct applySearchCriteria {
    std::string itemId; // Item id.
    OAIRemoteSearchResult body; // The remote search result.
    std::optional<bool> replaceAllImages; // Optional. Whether or not to replace all images. Default: True.
};
struct getBookRemoteSearchResults {
    OAIBookInfoRemoteSearchQuery body; // Remote search query.
};
struct getBoxSetRemoteSearchResults {
    OAIBoxSetInfoRemoteSearchQuery body; // Remote search query.
};
struct getExternalIdInfos {
    std::string itemId; // Item id.
};
struct getMovieRemoteSearchResults {
    OAIMovieInfoRemoteSearchQuery body; // Remote search query.
};
struct getMusicAlbumRemoteSearchResults {
    OAIAlbumInfoRemoteSearchQuery body; // Remote search query.
};
struct getMusicArtistRemoteSearchResults {
    OAIArtistInfoRemoteSearchQuery body; // Remote search query.
};
struct getMusicVideoRemoteSearchResults {
    OAIMusicVideoInfoRemoteSearchQuery body; // Remote search query.
};
struct getPersonRemoteSearchResults {
    OAIPersonLookupInfoRemoteSearchQuery body; // Remote search query.
};
struct getSeriesRemoteSearchResults {
    OAISeriesInfoRemoteSearchQuery body; // Remote search query.
};
struct getTrailerRemoteSearchResults {
    OAITrailerInfoRemoteSearchQuery body; // Remote search query.
};
}

namespace api 
{
// Applies search criteria to an item and refreshes metadata.
struct applySearchCriteria {
public:
    using in_type                      = param::applySearchCriteria;
    using out_type                     = model::return_type_applySearchCriteria;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Items/RemoteSearch/Apply/{}"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.replaceAllImages)
            p.set_param("replaceAllImages", convert_from<std::string>(input.replaceAllImages.value()));
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
 * baseName: ItemLookup
 * defaultResponse: 
 */
};
// Get book remote search.
struct getBookRemoteSearchResults {
public:
    using in_type                      = param::getBookRemoteSearchResults;
    using out_type                     = model::return_type_getBookRemoteSearchResults;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Items/RemoteSearch/Book"sv; 
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
 * returnType: std::vector&lt;OAIRemoteSearchResult&gt;
 * returnFormat: 
 * returnBaseType: OAIRemoteSearchResult
 * returnContainer: array
 * baseName: ItemLookup
 * defaultResponse: {}
 */
};
// Get box set remote search.
struct getBoxSetRemoteSearchResults {
public:
    using in_type                      = param::getBoxSetRemoteSearchResults;
    using out_type                     = model::return_type_getBoxSetRemoteSearchResults;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Items/RemoteSearch/BoxSet"sv; 
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
 * returnType: std::vector&lt;OAIRemoteSearchResult&gt;
 * returnFormat: 
 * returnBaseType: OAIRemoteSearchResult
 * returnContainer: array
 * baseName: ItemLookup
 * defaultResponse: {}
 */
};
// Get the item&#39;s external id info.
struct getExternalIdInfos {
public:
    using in_type                      = param::getExternalIdInfos;
    using out_type                     = model::return_type_getExternalIdInfos;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/ExternalIdInfos"sv,
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
 * returnType: std::vector&lt;OAIExternalIdInfo&gt;
 * returnFormat: 
 * returnBaseType: OAIExternalIdInfo
 * returnContainer: array
 * baseName: ItemLookup
 * defaultResponse: {}
 */
};
// Get movie remote search.
struct getMovieRemoteSearchResults {
public:
    using in_type                      = param::getMovieRemoteSearchResults;
    using out_type                     = model::return_type_getMovieRemoteSearchResults;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Items/RemoteSearch/Movie"sv; 
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
 * returnType: std::vector&lt;OAIRemoteSearchResult&gt;
 * returnFormat: 
 * returnBaseType: OAIRemoteSearchResult
 * returnContainer: array
 * baseName: ItemLookup
 * defaultResponse: {}
 */
};
// Get music album remote search.
struct getMusicAlbumRemoteSearchResults {
public:
    using in_type                      = param::getMusicAlbumRemoteSearchResults;
    using out_type                     = model::return_type_getMusicAlbumRemoteSearchResults;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Items/RemoteSearch/MusicAlbum"sv; 
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
 * returnType: std::vector&lt;OAIRemoteSearchResult&gt;
 * returnFormat: 
 * returnBaseType: OAIRemoteSearchResult
 * returnContainer: array
 * baseName: ItemLookup
 * defaultResponse: {}
 */
};
// Get music artist remote search.
struct getMusicArtistRemoteSearchResults {
public:
    using in_type                      = param::getMusicArtistRemoteSearchResults;
    using out_type                     = model::return_type_getMusicArtistRemoteSearchResults;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Items/RemoteSearch/MusicArtist"sv; 
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
 * returnType: std::vector&lt;OAIRemoteSearchResult&gt;
 * returnFormat: 
 * returnBaseType: OAIRemoteSearchResult
 * returnContainer: array
 * baseName: ItemLookup
 * defaultResponse: {}
 */
};
// Get music video remote search.
struct getMusicVideoRemoteSearchResults {
public:
    using in_type                      = param::getMusicVideoRemoteSearchResults;
    using out_type                     = model::return_type_getMusicVideoRemoteSearchResults;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Items/RemoteSearch/MusicVideo"sv; 
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
 * returnType: std::vector&lt;OAIRemoteSearchResult&gt;
 * returnFormat: 
 * returnBaseType: OAIRemoteSearchResult
 * returnContainer: array
 * baseName: ItemLookup
 * defaultResponse: {}
 */
};
// Get person remote search.
struct getPersonRemoteSearchResults {
public:
    using in_type                      = param::getPersonRemoteSearchResults;
    using out_type                     = model::return_type_getPersonRemoteSearchResults;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Items/RemoteSearch/Person"sv; 
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
 * returnType: std::vector&lt;OAIRemoteSearchResult&gt;
 * returnFormat: 
 * returnBaseType: OAIRemoteSearchResult
 * returnContainer: array
 * baseName: ItemLookup
 * defaultResponse: {}
 */
};
// Get series remote search.
struct getSeriesRemoteSearchResults {
public:
    using in_type                      = param::getSeriesRemoteSearchResults;
    using out_type                     = model::return_type_getSeriesRemoteSearchResults;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Items/RemoteSearch/Series"sv; 
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
 * returnType: std::vector&lt;OAIRemoteSearchResult&gt;
 * returnFormat: 
 * returnBaseType: OAIRemoteSearchResult
 * returnContainer: array
 * baseName: ItemLookup
 * defaultResponse: {}
 */
};
// Get trailer remote search.
struct getTrailerRemoteSearchResults {
public:
    using in_type                      = param::getTrailerRemoteSearchResults;
    using out_type                     = model::return_type_getTrailerRemoteSearchResults;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Items/RemoteSearch/Trailer"sv; 
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
 * returnType: std::vector&lt;OAIRemoteSearchResult&gt;
 * returnFormat: 
 * returnBaseType: OAIRemoteSearchResult
 * returnContainer: array
 * baseName: ItemLookup
 * defaultResponse: {}
 */
};
}
}
