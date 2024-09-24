#pragma once

/*
 * OAIBaseItemDto.h
 * name: BaseItemDto
 * schemaName: BaseItemDto
 * classFilename: BaseItemDto
 * classVarName: BaseItemDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * This is strictly used as a data transfer object from the api layer.  This holds information about a BaseItem in a format that is convenient for the client.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIBaseItemDto.h"
#include "jellyfin/model/OAIBaseItemDtoImageBlurHashes.h"
#include "jellyfin/model/OAIBaseItemKind.h"
#include "jellyfin/model/OAIBaseItemPerson.h"
#include "jellyfin/model/OAIChannelType.h"
#include "jellyfin/model/OAIChapterInfo.h"
#include "jellyfin/model/OAICollectionType.h"
#include "jellyfin/model/OAIDayOfWeek.h"
#include "jellyfin/model/OAIExternalUrl.h"
#include "jellyfin/model/OAIExtraType.h"
#include "jellyfin/model/OAIImageOrientation.h"
#include "jellyfin/model/OAIIsoType.h"
#include "jellyfin/model/OAILocationType.h"
#include "jellyfin/model/OAIMediaSourceInfo.h"
#include "jellyfin/model/OAIMediaStream.h"
#include "jellyfin/model/OAIMediaType.h"
#include "jellyfin/model/OAIMediaUrl.h"
#include "jellyfin/model/OAIMetadataField.h"
#include "jellyfin/model/OAINameGuidPair.h"
#include "jellyfin/model/OAIPlayAccess.h"
#include "jellyfin/model/OAIProgramAudio.h"
#include "jellyfin/model/OAITrickplayInfo.h"
#include "jellyfin/model/OAIUserItemDataDto.h"
#include "jellyfin/model/OAIVideo3DFormat.h"
#include "jellyfin/model/OAIVideoType.h"
#include <cstdint>
#include <map>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIExternalUrl;
class OAIMediaSourceInfo;
class OAIMediaUrl;
class OAIBaseItemPerson;
class OAINameGuidPair;
class OAIUserItemDataDto;
class OAIMediaStream;
class OAIBaseItemDtoImageBlurHashes;
class OAIChapterInfo;
class OAITrickplayInfo;


    class OAIBaseItemDto {
    public:
    
        // Gets or sets the name.
        std::optional<std::string> Name;

        std::optional<std::string> OriginalTitle;

        // Gets or sets the server identifier.
        std::optional<std::string> ServerId;

        // Gets or sets the id.
        std::string Id;

        // Gets or sets the etag.
        std::optional<std::string> Etag;

        // Gets or sets the type of the source.
        std::optional<std::string> SourceType;

        // Gets or sets the playlist item identifier.
        std::optional<std::string> PlaylistItemId;

        // Gets or sets the date created.
        std::optional<std::string> DateCreated;

        std::optional<std::string> DateLastMediaAdded;

        std::optional<OAIExtraType> ExtraType;

        std::optional<std::int32_t> AirsBeforeSeasonNumber;

        std::optional<std::int32_t> AirsAfterSeasonNumber;

        std::optional<std::int32_t> AirsBeforeEpisodeNumber;

        std::optional<bool> CanDelete;

        std::optional<bool> CanDownload;

        std::optional<bool> HasLyrics;

        std::optional<bool> HasSubtitles;

        std::optional<std::string> PreferredMetadataLanguage;

        std::optional<std::string> PreferredMetadataCountryCode;

        std::optional<std::string> Container;

        // Gets or sets the name of the sort.
        std::optional<std::string> SortName;

        std::optional<std::string> ForcedSortName;

        // Gets or sets the video3 D format.
        std::optional<OAIVideo3DFormat> Video3DFormat;

        // Gets or sets the premiere date.
        std::optional<std::string> PremiereDate;

        // Gets or sets the external urls.
        std::optional<std::vector<OAIExternalUrl>> ExternalUrls;

        // Gets or sets the media versions.
        std::optional<std::vector<OAIMediaSourceInfo>> MediaSources;

        // Gets or sets the critic rating.
        std::optional<float> CriticRating;

        std::optional<std::vector<std::string>> ProductionLocations;

        // Gets or sets the path.
        std::optional<std::string> Path;

        std::optional<bool> EnableMediaSourceDisplay;

        // Gets or sets the official rating.
        std::optional<std::string> OfficialRating;

        // Gets or sets the custom rating.
        std::optional<std::string> CustomRating;

        // Gets or sets the channel identifier.
        std::optional<std::string> ChannelId;

        std::optional<std::string> ChannelName;

        // Gets or sets the overview.
        std::optional<std::string> Overview;

        // Gets or sets the taglines.
        std::optional<std::vector<std::string>> Taglines;

        // Gets or sets the genres.
        std::optional<std::vector<std::string>> Genres;

        // Gets or sets the community rating.
        std::optional<float> CommunityRating;

        // Gets or sets the cumulative run time ticks.
        std::optional<std::int64_t> CumulativeRunTimeTicks;

        // Gets or sets the run time ticks.
        std::optional<std::int64_t> RunTimeTicks;

        // Gets or sets the play access.
        std::optional<OAIPlayAccess> PlayAccess;

        // Gets or sets the aspect ratio.
        std::optional<std::string> AspectRatio;

        // Gets or sets the production year.
        std::optional<std::int32_t> ProductionYear;

        // Gets or sets a value indicating whether this instance is place holder.
        std::optional<bool> IsPlaceHolder;

        // Gets or sets the number.
        std::optional<std::string> Number;

        std::optional<std::string> ChannelNumber;

        // Gets or sets the index number.
        std::optional<std::int32_t> IndexNumber;

        // Gets or sets the index number end.
        std::optional<std::int32_t> IndexNumberEnd;

        // Gets or sets the parent index number.
        std::optional<std::int32_t> ParentIndexNumber;

        // Gets or sets the trailer urls.
        std::optional<std::vector<OAIMediaUrl>> RemoteTrailers;

        // Gets or sets the provider ids.
        std::optional<std::map<std::string, std::string>> ProviderIds;

        // Gets or sets a value indicating whether this instance is HD.
        std::optional<bool> IsHD;

        // Gets or sets a value indicating whether this instance is folder.
        std::optional<bool> IsFolder;

        // Gets or sets the parent id.
        std::optional<std::string> ParentId;

        // Gets or sets the type.
        OAIBaseItemKind Type;

        // Gets or sets the people.
        std::optional<std::vector<OAIBaseItemPerson>> People;

        // Gets or sets the studios.
        std::optional<std::vector<OAINameGuidPair>> Studios;

        std::optional<std::vector<OAINameGuidPair>> GenreItems;

        // Gets or sets whether the item has a logo, this will hold the Id of the Parent that has one.
        std::optional<std::string> ParentLogoItemId;

        // Gets or sets whether the item has any backdrops, this will hold the Id of the Parent that has one.
        std::optional<std::string> ParentBackdropItemId;

        // Gets or sets the parent backdrop image tags.
        std::optional<std::vector<std::string>> ParentBackdropImageTags;

        // Gets or sets the local trailer count.
        std::optional<std::int32_t> LocalTrailerCount;

        // Gets or sets the user data for this item based on the user it&#39;s being requested for.
        std::optional<OAIUserItemDataDto> UserData;

        // Gets or sets the recursive item count.
        std::optional<std::int32_t> RecursiveItemCount;

        // Gets or sets the child count.
        std::optional<std::int32_t> ChildCount;

        // Gets or sets the name of the series.
        std::optional<std::string> SeriesName;

        // Gets or sets the series id.
        std::optional<std::string> SeriesId;

        // Gets or sets the season identifier.
        std::optional<std::string> SeasonId;

        // Gets or sets the special feature count.
        std::optional<std::int32_t> SpecialFeatureCount;

        // Gets or sets the display preferences id.
        std::optional<std::string> DisplayPreferencesId;

        // Gets or sets the status.
        std::optional<std::string> Status;

        // Gets or sets the air time.
        std::optional<std::string> AirTime;

        // Gets or sets the air days.
        std::optional<std::vector<OAIDayOfWeek>> AirDays;

        // Gets or sets the tags.
        std::optional<std::vector<std::string>> Tags;

        // Gets or sets the primary image aspect ratio, after image enhancements.
        std::optional<double> PrimaryImageAspectRatio;

        // Gets or sets the artists.
        std::optional<std::vector<std::string>> Artists;

        // Gets or sets the artist items.
        std::optional<std::vector<OAINameGuidPair>> ArtistItems;

        // Gets or sets the album.
        std::optional<std::string> Album;

        // Gets or sets the type of the collection.
        std::optional<OAICollectionType> CollectionType;

        // Gets or sets the display order.
        std::optional<std::string> DisplayOrder;

        // Gets or sets the album id.
        std::optional<std::string> AlbumId;

        // Gets or sets the album image tag.
        std::optional<std::string> AlbumPrimaryImageTag;

        // Gets or sets the series primary image tag.
        std::optional<std::string> SeriesPrimaryImageTag;

        // Gets or sets the album artist.
        std::optional<std::string> AlbumArtist;

        // Gets or sets the album artists.
        std::optional<std::vector<OAINameGuidPair>> AlbumArtists;

        // Gets or sets the name of the season.
        std::optional<std::string> SeasonName;

        // Gets or sets the media streams.
        std::optional<std::vector<OAIMediaStream>> MediaStreams;

        // Gets or sets the type of the video.
        std::optional<OAIVideoType> VideoType;

        // Gets or sets the part count.
        std::optional<std::int32_t> PartCount;

        std::optional<std::int32_t> MediaSourceCount;

        // Gets or sets the image tags.
        std::optional<std::map<std::string, std::string>> ImageTags;

        // Gets or sets the backdrop image tags.
        std::optional<std::vector<std::string>> BackdropImageTags;

        // Gets or sets the screenshot image tags.
        std::optional<std::vector<std::string>> ScreenshotImageTags;

        // Gets or sets the parent logo image tag.
        std::optional<std::string> ParentLogoImageTag;

        // Gets or sets whether the item has fan art, this will hold the Id of the Parent that has one.
        std::optional<std::string> ParentArtItemId;

        // Gets or sets the parent art image tag.
        std::optional<std::string> ParentArtImageTag;

        // Gets or sets the series thumb image tag.
        std::optional<std::string> SeriesThumbImageTag;

        std::optional<OAIBaseItemDtoImageBlurHashes> ImageBlurHashes;

        // Gets or sets the series studio.
        std::optional<std::string> SeriesStudio;

        // Gets or sets the parent thumb item id.
        std::optional<std::string> ParentThumbItemId;

        // Gets or sets the parent thumb image tag.
        std::optional<std::string> ParentThumbImageTag;

        // Gets or sets the parent primary image item identifier.
        std::optional<std::string> ParentPrimaryImageItemId;

        // Gets or sets the parent primary image tag.
        std::optional<std::string> ParentPrimaryImageTag;

        // Gets or sets the chapters.
        std::optional<std::vector<OAIChapterInfo>> Chapters;

        // Gets or sets the trickplay manifest.
        std::optional<std::map<std::string, std::map<std::string, OAITrickplayInfo>>> Trickplay;

        // Gets or sets the type of the location.
        std::optional<OAILocationType> LocationType;

        // Gets or sets the type of the iso.
        std::optional<OAIIsoType> IsoType;

        // Gets or sets the type of the media.
        OAIMediaType MediaType;

        // Gets or sets the end date.
        std::optional<std::string> EndDate;

        // Gets or sets the locked fields.
        std::optional<std::vector<OAIMetadataField>> LockedFields;

        // Gets or sets the trailer count.
        std::optional<std::int32_t> TrailerCount;

        // Gets or sets the movie count.
        std::optional<std::int32_t> MovieCount;

        // Gets or sets the series count.
        std::optional<std::int32_t> SeriesCount;

        std::optional<std::int32_t> ProgramCount;

        // Gets or sets the episode count.
        std::optional<std::int32_t> EpisodeCount;

        // Gets or sets the song count.
        std::optional<std::int32_t> SongCount;

        // Gets or sets the album count.
        std::optional<std::int32_t> AlbumCount;

        std::optional<std::int32_t> ArtistCount;

        // Gets or sets the music video count.
        std::optional<std::int32_t> MusicVideoCount;

        // Gets or sets a value indicating whether [enable internet providers].
        std::optional<bool> LockData;

        std::optional<std::int32_t> Width;

        std::optional<std::int32_t> Height;

        std::optional<std::string> CameraMake;

        std::optional<std::string> CameraModel;

        std::optional<std::string> Software;

        std::optional<double> ExposureTime;

        std::optional<double> FocalLength;

        std::optional<OAIImageOrientation> ImageOrientation;

        std::optional<double> Aperture;

        std::optional<double> ShutterSpeed;

        std::optional<double> Latitude;

        std::optional<double> Longitude;

        std::optional<double> Altitude;

        std::optional<std::int32_t> IsoSpeedRating;

        // Gets or sets the series timer identifier.
        std::optional<std::string> SeriesTimerId;

        // Gets or sets the program identifier.
        std::optional<std::string> ProgramId;

        // Gets or sets the channel primary image tag.
        std::optional<std::string> ChannelPrimaryImageTag;

        // Gets or sets the start date of the recording, in UTC.
        std::optional<std::string> StartDate;

        // Gets or sets the completion percentage.
        std::optional<double> CompletionPercentage;

        // Gets or sets a value indicating whether this instance is repeat.
        std::optional<bool> IsRepeat;

        // Gets or sets the episode title.
        std::optional<std::string> EpisodeTitle;

        // Gets or sets the type of the channel.
        std::optional<OAIChannelType> ChannelType;

        // Gets or sets the audio.
        std::optional<OAIProgramAudio> Audio;

        // Gets or sets a value indicating whether this instance is movie.
        std::optional<bool> IsMovie;

        // Gets or sets a value indicating whether this instance is sports.
        std::optional<bool> IsSports;

        // Gets or sets a value indicating whether this instance is series.
        std::optional<bool> IsSeries;

        // Gets or sets a value indicating whether this instance is live.
        std::optional<bool> IsLive;

        // Gets or sets a value indicating whether this instance is news.
        std::optional<bool> IsNews;

        // Gets or sets a value indicating whether this instance is kids.
        std::optional<bool> IsKids;

        // Gets or sets a value indicating whether this instance is premiere.
        std::optional<bool> IsPremiere;

        // Gets or sets the timer identifier.
        std::optional<std::string> TimerId;

        // Gets or sets the gain required for audio normalization.
        std::optional<float> NormalizationGain;

        // Gets or sets the current program.
        std::optional<rc<OAIBaseItemDto>> CurrentProgram;

        OAIBaseItemDto();
        ~OAIBaseItemDto();
    };
    extern void to_json(json_t&, const OAIBaseItemDto&);
    extern void from_json(const json_t&, OAIBaseItemDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIBaseItemDto);
