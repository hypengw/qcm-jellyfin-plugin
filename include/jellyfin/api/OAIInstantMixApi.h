#pragma once
/*
 * OAIInstantMixApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIBaseItemDtoQueryResult.h"
#include "jellyfin/model/OAIImageType.h"
#include "jellyfin/model/OAIItemFields.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getInstantMixFromAlbum = OAIBaseItemDtoQueryResult;
using return_type_getInstantMixFromArtists = OAIBaseItemDtoQueryResult;
using return_type_getInstantMixFromArtists2 = OAIBaseItemDtoQueryResult;
using return_type_getInstantMixFromItem = OAIBaseItemDtoQueryResult;
using return_type_getInstantMixFromMusicGenreById = OAIBaseItemDtoQueryResult;
using return_type_getInstantMixFromMusicGenreByName = OAIBaseItemDtoQueryResult;
using return_type_getInstantMixFromPlaylist = OAIBaseItemDtoQueryResult;
using return_type_getInstantMixFromSong = OAIBaseItemDtoQueryResult;
}

namespace api::param 
{
struct getInstantMixFromAlbum {
    std::string itemId; // The item id.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<bool> enableImages; // Optional. Include image information in output.
    std::optional<bool> enableUserData; // Optional. Include user data.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
};
struct getInstantMixFromArtists {
    std::string itemId; // The item id.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<bool> enableImages; // Optional. Include image information in output.
    std::optional<bool> enableUserData; // Optional. Include user data.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
};
struct getInstantMixFromArtists2 {
    std::string id; // The item id.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<bool> enableImages; // Optional. Include image information in output.
    std::optional<bool> enableUserData; // Optional. Include user data.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
};
struct getInstantMixFromItem {
    std::string itemId; // The item id.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<bool> enableImages; // Optional. Include image information in output.
    std::optional<bool> enableUserData; // Optional. Include user data.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
};
struct getInstantMixFromMusicGenreById {
    std::string id; // The item id.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<bool> enableImages; // Optional. Include image information in output.
    std::optional<bool> enableUserData; // Optional. Include user data.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
};
struct getInstantMixFromMusicGenreByName {
    std::string name; // The genre name.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<bool> enableImages; // Optional. Include image information in output.
    std::optional<bool> enableUserData; // Optional. Include user data.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
};
struct getInstantMixFromPlaylist {
    std::string itemId; // The item id.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<bool> enableImages; // Optional. Include image information in output.
    std::optional<bool> enableUserData; // Optional. Include user data.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
};
struct getInstantMixFromSong {
    std::string itemId; // The item id.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<bool> enableImages; // Optional. Include image information in output.
    std::optional<bool> enableUserData; // Optional. Include user data.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
};
}

namespace api 
{
// Creates an instant playlist based on a given album.
struct getInstantMixFromAlbum {
public:
    using in_type                      = param::getInstantMixFromAlbum;
    using out_type                     = model::return_type_getInstantMixFromAlbum;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Albums/{}/InstantMix"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
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
 * baseName: InstantMix
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Creates an instant playlist based on a given artist.
struct getInstantMixFromArtists {
public:
    using in_type                      = param::getInstantMixFromArtists;
    using out_type                     = model::return_type_getInstantMixFromArtists;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Artists/{}/InstantMix"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
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
 * baseName: InstantMix
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Creates an instant playlist based on a given artist.
struct getInstantMixFromArtists2 {
public:
    using in_type                      = param::getInstantMixFromArtists2;
    using out_type                     = model::return_type_getInstantMixFromArtists2;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Artists/InstantMix"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("id", convert_from<std::string>(input.id));
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
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
 * baseName: InstantMix
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Creates an instant playlist based on a given item.
struct getInstantMixFromItem {
public:
    using in_type                      = param::getInstantMixFromItem;
    using out_type                     = model::return_type_getInstantMixFromItem;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/InstantMix"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
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
 * baseName: InstantMix
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Creates an instant playlist based on a given genre.
struct getInstantMixFromMusicGenreById {
public:
    using in_type                      = param::getInstantMixFromMusicGenreById;
    using out_type                     = model::return_type_getInstantMixFromMusicGenreById;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/MusicGenres/InstantMix"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("id", convert_from<std::string>(input.id));
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
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
 * baseName: InstantMix
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Creates an instant playlist based on a given genre.
struct getInstantMixFromMusicGenreByName {
public:
    using in_type                      = param::getInstantMixFromMusicGenreByName;
    using out_type                     = model::return_type_getInstantMixFromMusicGenreByName;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/MusicGenres/{}/InstantMix"sv,
            input.name
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
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
 * baseName: InstantMix
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Creates an instant playlist based on a given playlist.
struct getInstantMixFromPlaylist {
public:
    using in_type                      = param::getInstantMixFromPlaylist;
    using out_type                     = model::return_type_getInstantMixFromPlaylist;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Playlists/{}/InstantMix"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
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
 * baseName: InstantMix
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Creates an instant playlist based on a given song.
struct getInstantMixFromSong {
public:
    using in_type                      = param::getInstantMixFromSong;
    using out_type                     = model::return_type_getInstantMixFromSong;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Songs/{}/InstantMix"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
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
 * baseName: InstantMix
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
}
}
