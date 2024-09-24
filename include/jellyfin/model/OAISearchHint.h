#pragma once

/*
 * OAISearchHint.h
 * name: SearchHint
 * schemaName: SearchHint
 * classFilename: SearchHint
 * classVarName: SearchHint
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class SearchHintResult.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIBaseItemKind.h"
#include "jellyfin/model/OAIMediaType.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {


    class OAISearchHint {
    public:
    
        // Gets or sets the item id.
        [[deprecated]] std::string ItemId;

        // Gets or sets the item id.
        std::string Id;

        // Gets or sets the name.
        std::string Name;

        // Gets or sets the matched term.
        std::optional<std::string> MatchedTerm;

        // Gets or sets the index number.
        std::optional<std::int32_t> IndexNumber;

        // Gets or sets the production year.
        std::optional<std::int32_t> ProductionYear;

        // Gets or sets the parent index number.
        std::optional<std::int32_t> ParentIndexNumber;

        // Gets or sets the image tag.
        std::optional<std::string> PrimaryImageTag;

        // Gets or sets the thumb image tag.
        std::optional<std::string> ThumbImageTag;

        // Gets or sets the thumb image item identifier.
        std::optional<std::string> ThumbImageItemId;

        // Gets or sets the backdrop image tag.
        std::optional<std::string> BackdropImageTag;

        // Gets or sets the backdrop image item identifier.
        std::optional<std::string> BackdropImageItemId;

        // Gets or sets the type.
        OAIBaseItemKind Type;

        // Gets or sets a value indicating whether this instance is folder.
        std::optional<bool> IsFolder;

        // Gets or sets the run time ticks.
        std::optional<std::int64_t> RunTimeTicks;

        // Gets or sets the type of the media.
        OAIMediaType MediaType;

        // Gets or sets the start date.
        std::optional<std::string> StartDate;

        // Gets or sets the end date.
        std::optional<std::string> EndDate;

        // Gets or sets the series.
        std::optional<std::string> Series;

        // Gets or sets the status.
        std::optional<std::string> Status;

        // Gets or sets the album.
        std::optional<std::string> Album;

        // Gets or sets the album id.
        std::optional<std::string> AlbumId;

        // Gets or sets the album artist.
        std::optional<std::string> AlbumArtist;

        // Gets or sets the artists.
        std::vector<std::string> Artists;

        // Gets or sets the song count.
        std::optional<std::int32_t> SongCount;

        // Gets or sets the episode count.
        std::optional<std::int32_t> EpisodeCount;

        // Gets or sets the channel identifier.
        std::optional<std::string> ChannelId;

        // Gets or sets the name of the channel.
        std::optional<std::string> ChannelName;

        // Gets or sets the primary image aspect ratio.
        std::optional<double> PrimaryImageAspectRatio;

        OAISearchHint();
        ~OAISearchHint();
    };
    extern void to_json(json_t&, const OAISearchHint&);
    extern void from_json(const json_t&, OAISearchHint&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISearchHint);
