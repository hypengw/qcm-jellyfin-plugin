#pragma once

/*
 * OAIItemFields.h
 * name: ItemFields
 * schemaName: ItemFields
 * classFilename: ItemFields
 * classVarName: ItemFields
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Used to control the data that gets attached to DtoBaseItems.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIItemFields {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        AIRTIME, // AirTime
        CANDELETE, // CanDelete
        CANDOWNLOAD, // CanDownload
        CHANNELINFO, // ChannelInfo
        CHAPTERS, // Chapters
        TRICKPLAY, // Trickplay
        CHILDCOUNT, // ChildCount
        CUMULATIVERUNTIMETICKS, // CumulativeRunTimeTicks
        CUSTOMRATING, // CustomRating
        DATECREATED, // DateCreated
        DATELASTMEDIAADDED, // DateLastMediaAdded
        DISPLAYPREFERENCESID, // DisplayPreferencesId
        ETAG, // Etag
        EXTERNALURLS, // ExternalUrls
        GENRES, // Genres
        HOMEPAGEURL, // HomePageUrl
        ITEMCOUNTS, // ItemCounts
        MEDIASOURCECOUNT, // MediaSourceCount
        MEDIASOURCES, // MediaSources
        ORIGINALTITLE, // OriginalTitle
        OVERVIEW, // Overview
        PARENTID, // ParentId
        PATH, // Path
        PEOPLE, // People
        PLAYACCESS, // PlayAccess
        PRODUCTIONLOCATIONS, // ProductionLocations
        PROVIDERIDS, // ProviderIds
        PRIMARYIMAGEASPECTRATIO, // PrimaryImageAspectRatio
        RECURSIVEITEMCOUNT, // RecursiveItemCount
        SETTINGS, // Settings
        SCREENSHOTIMAGETAGS, // ScreenshotImageTags
        SERIESPRIMARYIMAGE, // SeriesPrimaryImage
        SERIESSTUDIO, // SeriesStudio
        SORTNAME, // SortName
        SPECIALEPISODENUMBERS, // SpecialEpisodeNumbers
        STUDIOS, // Studios
        TAGLINES, // Taglines
        TAGS, // Tags
        REMOTETRAILERS, // RemoteTrailers
        MEDIASTREAMS, // MediaStreams
        SEASONUSERDATA, // SeasonUserData
        SERVICENAME, // ServiceName
        THEMESONGIDS, // ThemeSongIds
        THEMEVIDEOIDS, // ThemeVideoIds
        EXTERNALETAG, // ExternalEtag
        PRESENTATIONUNIQUEKEY, // PresentationUniqueKey
        INHERITEDPARENTALRATINGVALUE, // InheritedParentalRatingValue
        EXTERNALSERIESID, // ExternalSeriesId
        SERIESPRESENTATIONUNIQUEKEY, // SeriesPresentationUniqueKey
        DATELASTREFRESHED, // DateLastRefreshed
        DATELASTSAVED, // DateLastSaved
        REFRESHSTATE, // RefreshState
        CHANNELIMAGE, // ChannelImage
        ENABLEMEDIASOURCEDISPLAY, // EnableMediaSourceDisplay
        WIDTH, // Width
        HEIGHT, // Height
        EXTRAIDS, // ExtraIds
        LOCALTRAILERCOUNT, // LocalTrailerCount
        ISHD, // IsHD
        SPECIALFEATURECOUNT, // SpecialFeatureCount
    };
    extern void to_json(json_t&, const OAIItemFields&);
    extern void from_json(const json_t&, OAIItemFields&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIItemFields);
