#pragma once
/*
 * OAILyricsApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAILyricDto.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAIRemoteLyricInfoDto.h"
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_deleteLyrics = std::nullptr_t;
using return_type_downloadRemoteLyrics = OAILyricDto;
using return_type_getLyrics = OAILyricDto;
using return_type_getRemoteLyrics = OAILyricDto;
using return_type_searchRemoteLyrics = std::vector<OAIRemoteLyricInfoDto>;
using return_type_uploadLyrics = OAILyricDto;
}

namespace api::param 
{
struct deleteLyrics {
    std::string itemId; // The item id.
};
struct downloadRemoteLyrics {
    std::string itemId; // The item id.
    std::string lyricId; // The lyric id.
};
struct getLyrics {
    std::string itemId; // Item id.
};
struct getRemoteLyrics {
    std::string lyricId; // The remote provider item id.
};
struct searchRemoteLyrics {
    std::string itemId; // The item id.
};
struct uploadLyrics {
    std::string itemId; // The item the lyric belongs to.
    std::string fileName; // Name of the file being uploaded.
    std::optional<std::vector<std::byte>> body; // 
};
}

namespace api 
{
// Deletes an external lyric file.
struct deleteLyrics {
public:
    using in_type                      = param::deleteLyrics;
    using out_type                     = model::return_type_deleteLyrics;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/Audio/{}/Lyrics"sv,
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
 * baseName: Lyrics
 * defaultResponse: 
 */
};
// Downloads a remote lyric.
struct downloadRemoteLyrics {
public:
    using in_type                      = param::downloadRemoteLyrics;
    using out_type                     = model::return_type_downloadRemoteLyrics;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Audio/{}/RemoteSearch/Lyrics/{}"sv,
            input.itemId,
            input.lyricId
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
 * returnType: OAILyricDto
 * returnFormat: 
 * returnBaseType: OAILyricDto
 * returnContainer: 
 * baseName: Lyrics
 * defaultResponse: OAILyricDto()
 */
};
// Gets an item&#39;s lyrics.
struct getLyrics {
public:
    using in_type                      = param::getLyrics;
    using out_type                     = model::return_type_getLyrics;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Audio/{}/Lyrics"sv,
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
 * returnType: OAILyricDto
 * returnFormat: 
 * returnBaseType: OAILyricDto
 * returnContainer: 
 * baseName: Lyrics
 * defaultResponse: OAILyricDto()
 */
};
// Gets the remote lyrics.
struct getRemoteLyrics {
public:
    using in_type                      = param::getRemoteLyrics;
    using out_type                     = model::return_type_getRemoteLyrics;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Providers/Lyrics/{}"sv,
            input.lyricId
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
 * returnType: OAILyricDto
 * returnFormat: 
 * returnBaseType: OAILyricDto
 * returnContainer: 
 * baseName: Lyrics
 * defaultResponse: OAILyricDto()
 */
};
// Search remote lyrics.
struct searchRemoteLyrics {
public:
    using in_type                      = param::searchRemoteLyrics;
    using out_type                     = model::return_type_searchRemoteLyrics;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Audio/{}/RemoteSearch/Lyrics"sv,
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
 * returnType: std::vector&lt;OAIRemoteLyricInfoDto&gt;
 * returnFormat: 
 * returnBaseType: OAIRemoteLyricInfoDto
 * returnContainer: array
 * baseName: Lyrics
 * defaultResponse: {}
 */
};
// Upload an external lyric file.
struct uploadLyrics {
public:
    using in_type                      = param::uploadLyrics;
    using out_type                     = model::return_type_uploadLyrics;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Audio/{}/Lyrics"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("fileName", convert_from<std::string>(input.fileName));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        if(input.body)
            out = format_param(input.body.value());
        return out; 
    }
    in_type input;

/*
 * returnType: OAILyricDto
 * returnFormat: 
 * returnBaseType: OAILyricDto
 * returnContainer: 
 * baseName: Lyrics
 * defaultResponse: OAILyricDto()
 */
};
}
}
