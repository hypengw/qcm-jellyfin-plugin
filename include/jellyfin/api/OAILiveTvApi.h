#pragma once
/*
 * OAILiveTvApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIBaseItemDto.h"
#include "jellyfin/model/OAIBaseItemDtoQueryResult.h"
#include "jellyfin/model/OAIChannelMappingOptionsDto.h"
#include "jellyfin/model/OAIChannelType.h"
#include "jellyfin/model/OAIGetProgramsDto.h"
#include "jellyfin/model/OAIGuideInfo.h"
#include "jellyfin/model/OAIImageType.h"
#include "jellyfin/model/OAIItemFields.h"
#include "jellyfin/model/OAIItemSortBy.h"
#include "jellyfin/model/OAIListingsProviderInfo.h"
#include "jellyfin/model/OAILiveTvInfo.h"
#include "jellyfin/model/OAINameIdPair.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAIRecordingStatus.h"
#include "jellyfin/model/OAISeriesTimerInfoDto.h"
#include "jellyfin/model/OAISeriesTimerInfoDtoQueryResult.h"
#include "jellyfin/model/OAISetChannelMappingDto.h"
#include "jellyfin/model/OAISortOrder.h"
#include "jellyfin/model/OAITimerInfoDto.h"
#include "jellyfin/model/OAITimerInfoDtoQueryResult.h"
#include "jellyfin/model/OAITunerChannelMapping.h"
#include "jellyfin/model/OAITunerHostInfo.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_addListingProvider = OAIListingsProviderInfo;
using return_type_addTunerHost = OAITunerHostInfo;
using return_type_cancelSeriesTimer = std::nullptr_t;
using return_type_cancelTimer = std::nullptr_t;
using return_type_createSeriesTimer = std::nullptr_t;
using return_type_createTimer = std::nullptr_t;
using return_type_deleteListingProvider = std::nullptr_t;
using return_type_deleteRecording = std::nullptr_t;
using return_type_deleteTunerHost = std::nullptr_t;
using return_type_discoverTuners = std::vector<OAITunerHostInfo>;
using return_type_discvoverTuners = std::vector<OAITunerHostInfo>;
using return_type_getChannel = OAIBaseItemDto;
using return_type_getChannelMappingOptions = OAIChannelMappingOptionsDto;
using return_type_getDefaultListingProvider = OAIListingsProviderInfo;
using return_type_getDefaultTimer = OAISeriesTimerInfoDto;
using return_type_getGuideInfo = OAIGuideInfo;
using return_type_getLineups = std::vector<OAINameIdPair>;
using return_type_getLiveRecordingFile = std::vector<std::byte>;
using return_type_getLiveStreamFile = std::vector<std::byte>;
using return_type_getLiveTvChannels = OAIBaseItemDtoQueryResult;
using return_type_getLiveTvInfo = OAILiveTvInfo;
using return_type_getLiveTvPrograms = OAIBaseItemDtoQueryResult;
using return_type_getProgram = OAIBaseItemDto;
using return_type_getPrograms = OAIBaseItemDtoQueryResult;
using return_type_getRecommendedPrograms = OAIBaseItemDtoQueryResult;
using return_type_getRecording = OAIBaseItemDto;
using return_type_getRecordingFolders = OAIBaseItemDtoQueryResult;
using return_type_getRecordingGroup = std::nullptr_t;
using return_type_getRecordingGroups = OAIBaseItemDtoQueryResult;
using return_type_getRecordings = OAIBaseItemDtoQueryResult;
using return_type_getRecordingsSeries = OAIBaseItemDtoQueryResult;
using return_type_getSchedulesDirectCountries = std::vector<std::byte>;
using return_type_getSeriesTimer = OAISeriesTimerInfoDto;
using return_type_getSeriesTimers = OAISeriesTimerInfoDtoQueryResult;
using return_type_getTimer = OAITimerInfoDto;
using return_type_getTimers = OAITimerInfoDtoQueryResult;
using return_type_getTunerHostTypes = std::vector<OAINameIdPair>;
using return_type_resetTuner = std::nullptr_t;
using return_type_setChannelMapping = OAITunerChannelMapping;
using return_type_updateSeriesTimer = std::nullptr_t;
using return_type_updateTimer = std::nullptr_t;
}

namespace api::param 
{
struct addListingProvider {
    std::optional<std::string> pw; // Password.
    std::optional<bool> validateListings; // Validate listings.
    std::optional<bool> validateLogin; // Validate login.
    std::optional<OAIListingsProviderInfo> body; // New listings info.
};
struct addTunerHost {
    std::optional<OAITunerHostInfo> body; // New tuner host.
};
struct cancelSeriesTimer {
    std::string timerId; // Timer id.
};
struct cancelTimer {
    std::string timerId; // Timer id.
};
struct createSeriesTimer {
    std::optional<OAISeriesTimerInfoDto> body; // New series timer info.
};
struct createTimer {
    std::optional<OAITimerInfoDto> body; // New timer info.
};
struct deleteListingProvider {
    std::optional<std::string> id; // Listing provider id.
};
struct deleteRecording {
    std::string recordingId; // Recording id.
};
struct deleteTunerHost {
    std::optional<std::string> id; // Tuner host id.
};
struct discoverTuners {
    std::optional<bool> newDevicesOnly; // Only discover new tuners.
};
struct discvoverTuners {
    std::optional<bool> newDevicesOnly; // Only discover new tuners.
};
struct getChannel {
    std::string channelId; // Channel id.
    std::optional<std::string> userId; // Optional. Attach user data.
};
struct getChannelMappingOptions {
    std::optional<std::string> providerId; // Provider id.
};
struct getDefaultListingProvider {
};
struct getDefaultTimer {
    std::optional<std::string> programId; // Optional. To attach default values based on a program.
};
struct getGuideInfo {
};
struct getLineups {
    std::optional<std::string> id; // Provider id.
    std::optional<std::string> type; // Provider type.
    std::optional<std::string> location; // Location.
    std::optional<std::string> country; // Country.
};
struct getLiveRecordingFile {
    std::string recordingId; // Recording id.
};
struct getLiveStreamFile {
    std::string streamId; // Stream id.
    std::string container; // Container type.
};
struct getLiveTvChannels {
    std::optional<OAIChannelType> type; // Optional. Filter by channel type.
    std::optional<std::string> userId; // Optional. Filter by user and attach user data.
    std::optional<std::int32_t> startIndex; // Optional. The record index to start at. All items with a lower index will be dropped from the results.
    std::optional<bool> isMovie; // Optional. Filter for movies.
    std::optional<bool> isSeries; // Optional. Filter for series.
    std::optional<bool> isNews; // Optional. Filter for news.
    std::optional<bool> isKids; // Optional. Filter for kids.
    std::optional<bool> isSports; // Optional. Filter for sports.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<bool> isFavorite; // Optional. Filter by channels that are favorites, or not.
    std::optional<bool> isLiked; // Optional. Filter by channels that are liked, or not.
    std::optional<bool> isDisliked; // Optional. Filter by channels that are disliked, or not.
    std::optional<bool> enableImages; // Optional. Include image information in output.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // \&quot;Optional. The image types to include in the output.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<bool> enableUserData; // Optional. Include user data.
    std::optional<std::vector<OAIItemSortBy>> sortBy; // Optional. Key to sort by.
    std::optional<OAISortOrder> sortOrder; // Optional. Sort order.
    std::optional<bool> enableFavoriteSorting; // Optional. Incorporate favorite and like status into channel sorting.
    std::optional<bool> addCurrentProgram; // Optional. Adds current program info to each channel.
};
struct getLiveTvInfo {
};
struct getLiveTvPrograms {
    std::optional<std::vector<std::string>> channelIds; // The channels to return guide information for.
    std::optional<std::string> userId; // Optional. Filter by user id.
    std::optional<std::string> minStartDate; // Optional. The minimum premiere start date.
    std::optional<bool> hasAired; // Optional. Filter by programs that have completed airing, or not.
    std::optional<bool> isAiring; // Optional. Filter by programs that are currently airing, or not.
    std::optional<std::string> maxStartDate; // Optional. The maximum premiere start date.
    std::optional<std::string> minEndDate; // Optional. The minimum premiere end date.
    std::optional<std::string> maxEndDate; // Optional. The maximum premiere end date.
    std::optional<bool> isMovie; // Optional. Filter for movies.
    std::optional<bool> isSeries; // Optional. Filter for series.
    std::optional<bool> isNews; // Optional. Filter for news.
    std::optional<bool> isKids; // Optional. Filter for kids.
    std::optional<bool> isSports; // Optional. Filter for sports.
    std::optional<std::int32_t> startIndex; // Optional. The record index to start at. All items with a lower index will be dropped from the results.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::vector<OAIItemSortBy>> sortBy; // Optional. Specify one or more sort orders, comma delimited. Options: Name, StartDate.
    std::optional<std::vector<OAISortOrder>> sortOrder; // Sort Order - Ascending,Descending.
    std::optional<std::vector<std::string>> genres; // The genres to return guide information for.
    std::optional<std::vector<std::string>> genreIds; // The genre ids to return guide information for.
    std::optional<bool> enableImages; // Optional. Include image information in output.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
    std::optional<bool> enableUserData; // Optional. Include user data.
    std::optional<std::string> seriesTimerId; // Optional. Filter by series timer id.
    std::optional<std::string> librarySeriesId; // Optional. Filter by library series id.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<bool> enableTotalRecordCount; // Retrieve total record count.
};
struct getProgram {
    std::string programId; // Program id.
    std::optional<std::string> userId; // Optional. Attach user data.
};
struct getPrograms {
    std::optional<OAIGetProgramsDto> body; // Request body.
};
struct getRecommendedPrograms {
    std::optional<std::string> userId; // Optional. filter by user id.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<bool> isAiring; // Optional. Filter by programs that are currently airing, or not.
    std::optional<bool> hasAired; // Optional. Filter by programs that have completed airing, or not.
    std::optional<bool> isSeries; // Optional. Filter for series.
    std::optional<bool> isMovie; // Optional. Filter for movies.
    std::optional<bool> isNews; // Optional. Filter for news.
    std::optional<bool> isKids; // Optional. Filter for kids.
    std::optional<bool> isSports; // Optional. Filter for sports.
    std::optional<bool> enableImages; // Optional. Include image information in output.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
    std::optional<std::vector<std::string>> genreIds; // The genres to return guide information for.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<bool> enableUserData; // Optional. include user data.
    std::optional<bool> enableTotalRecordCount; // Retrieve total record count.
};
struct getRecording {
    std::string recordingId; // Recording id.
    std::optional<std::string> userId; // Optional. Attach user data.
};
struct getRecordingFolders {
    std::optional<std::string> userId; // Optional. Filter by user and attach user data.
};
struct getRecordingGroup {
    std::string groupId; // Group id.
};
struct getRecordingGroups {
    std::optional<std::string> userId; // Optional. Filter by user and attach user data.
};
struct getRecordings {
    std::optional<std::string> channelId; // Optional. Filter by channel id.
    std::optional<std::string> userId; // Optional. Filter by user and attach user data.
    std::optional<std::int32_t> startIndex; // Optional. The record index to start at. All items with a lower index will be dropped from the results.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<OAIRecordingStatus> status; // Optional. Filter by recording status.
    std::optional<bool> isInProgress; // Optional. Filter by recordings that are in progress, or not.
    std::optional<std::string> seriesTimerId; // Optional. Filter by recordings belonging to a series timer.
    std::optional<bool> enableImages; // Optional. Include image information in output.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<bool> enableUserData; // Optional. Include user data.
    std::optional<bool> isMovie; // Optional. Filter for movies.
    std::optional<bool> isSeries; // Optional. Filter for series.
    std::optional<bool> isKids; // Optional. Filter for kids.
    std::optional<bool> isSports; // Optional. Filter for sports.
    std::optional<bool> isNews; // Optional. Filter for news.
    std::optional<bool> isLibraryItem; // Optional. Filter for is library item.
    std::optional<bool> enableTotalRecordCount; // Optional. Return total record count.
};
struct getRecordingsSeries {
    std::optional<std::string> channelId; // Optional. Filter by channel id.
    std::optional<std::string> userId; // Optional. Filter by user and attach user data.
    std::optional<std::string> groupId; // Optional. Filter by recording group.
    std::optional<std::int32_t> startIndex; // Optional. The record index to start at. All items with a lower index will be dropped from the results.
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<OAIRecordingStatus> status; // Optional. Filter by recording status.
    std::optional<bool> isInProgress; // Optional. Filter by recordings that are in progress, or not.
    std::optional<std::string> seriesTimerId; // Optional. Filter by recordings belonging to a series timer.
    std::optional<bool> enableImages; // Optional. Include image information in output.
    std::optional<std::int32_t> imageTypeLimit; // Optional. The max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<bool> enableUserData; // Optional. Include user data.
    std::optional<bool> enableTotalRecordCount; // Optional. Return total record count.
};
struct getSchedulesDirectCountries {
};
struct getSeriesTimer {
    std::string timerId; // Timer id.
};
struct getSeriesTimers {
    std::optional<std::string> sortBy; // Optional. Sort by SortName or Priority.
    std::optional<OAISortOrder> sortOrder; // Optional. Sort in Ascending or Descending order.
};
struct getTimer {
    std::string timerId; // Timer id.
};
struct getTimers {
    std::optional<std::string> channelId; // Optional. Filter by channel id.
    std::optional<std::string> seriesTimerId; // Optional. Filter by timers belonging to a series timer.
    std::optional<bool> isActive; // Optional. Filter by timers that are active.
    std::optional<bool> isScheduled; // Optional. Filter by timers that are scheduled.
};
struct getTunerHostTypes {
};
struct resetTuner {
    std::string tunerId; // Tuner id.
};
struct setChannelMapping {
    OAISetChannelMappingDto body; // The set channel mapping dto.
};
struct updateSeriesTimer {
    std::string timerId; // Timer id.
    std::optional<OAISeriesTimerInfoDto> body; // New series timer info.
};
struct updateTimer {
    std::string timerId; // Timer id.
    std::optional<OAITimerInfoDto> body; // New timer info.
};
}

namespace api 
{
// Adds a listings provider.
struct addListingProvider {
public:
    using in_type                      = param::addListingProvider;
    using out_type                     = model::return_type_addListingProvider;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/LiveTv/ListingProviders"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.pw)
            p.set_param("pw", convert_from<std::string>(input.pw.value()));
        if(input.validateListings)
            p.set_param("validateListings", convert_from<std::string>(input.validateListings.value()));
        if(input.validateLogin)
            p.set_param("validateLogin", convert_from<std::string>(input.validateLogin.value()));
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
 * returnType: OAIListingsProviderInfo
 * returnFormat: 
 * returnBaseType: OAIListingsProviderInfo
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: OAIListingsProviderInfo()
 */
};
// Adds a tuner host.
struct addTunerHost {
public:
    using in_type                      = param::addTunerHost;
    using out_type                     = model::return_type_addTunerHost;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/LiveTv/TunerHosts"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
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
 * returnType: OAITunerHostInfo
 * returnFormat: 
 * returnBaseType: OAITunerHostInfo
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: OAITunerHostInfo()
 */
};
// Cancels a live tv series timer.
struct cancelSeriesTimer {
public:
    using in_type                      = param::cancelSeriesTimer;
    using out_type                     = model::return_type_cancelSeriesTimer;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/LiveTv/SeriesTimers/{}"sv,
            input.timerId
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
 * baseName: LiveTv
 * defaultResponse: 
 */
};
// Cancels a live tv timer.
struct cancelTimer {
public:
    using in_type                      = param::cancelTimer;
    using out_type                     = model::return_type_cancelTimer;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/LiveTv/Timers/{}"sv,
            input.timerId
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
 * baseName: LiveTv
 * defaultResponse: 
 */
};
// Creates a live tv series timer.
struct createSeriesTimer {
public:
    using in_type                      = param::createSeriesTimer;
    using out_type                     = model::return_type_createSeriesTimer;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/LiveTv/SeriesTimers"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
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
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: 
 */
};
// Creates a live tv timer.
struct createTimer {
public:
    using in_type                      = param::createTimer;
    using out_type                     = model::return_type_createTimer;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/LiveTv/Timers"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
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
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: 
 */
};
// Delete listing provider.
struct deleteListingProvider {
public:
    using in_type                      = param::deleteListingProvider;
    using out_type                     = model::return_type_deleteListingProvider;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return "/LiveTv/ListingProviders"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.id)
            p.set_param("id", convert_from<std::string>(input.id.value()));
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
 * baseName: LiveTv
 * defaultResponse: 
 */
};
// Deletes a live tv recording.
struct deleteRecording {
public:
    using in_type                      = param::deleteRecording;
    using out_type                     = model::return_type_deleteRecording;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/LiveTv/Recordings/{}"sv,
            input.recordingId
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
 * baseName: LiveTv
 * defaultResponse: 
 */
};
// Deletes a tuner host.
struct deleteTunerHost {
public:
    using in_type                      = param::deleteTunerHost;
    using out_type                     = model::return_type_deleteTunerHost;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return "/LiveTv/TunerHosts"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.id)
            p.set_param("id", convert_from<std::string>(input.id.value()));
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
 * baseName: LiveTv
 * defaultResponse: 
 */
};
// Discover tuners.
struct discoverTuners {
public:
    using in_type                      = param::discoverTuners;
    using out_type                     = model::return_type_discoverTuners;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/Tuners/Discover"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.newDevicesOnly)
            p.set_param("newDevicesOnly", convert_from<std::string>(input.newDevicesOnly.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;OAITunerHostInfo&gt;
 * returnFormat: 
 * returnBaseType: OAITunerHostInfo
 * returnContainer: array
 * baseName: LiveTv
 * defaultResponse: {}
 */
};
// Discover tuners.
struct discvoverTuners {
public:
    using in_type                      = param::discvoverTuners;
    using out_type                     = model::return_type_discvoverTuners;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/Tuners/Discvover"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.newDevicesOnly)
            p.set_param("newDevicesOnly", convert_from<std::string>(input.newDevicesOnly.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;OAITunerHostInfo&gt;
 * returnFormat: 
 * returnBaseType: OAITunerHostInfo
 * returnContainer: array
 * baseName: LiveTv
 * defaultResponse: {}
 */
};
// Gets a live tv channel.
struct getChannel {
public:
    using in_type                      = param::getChannel;
    using out_type                     = model::return_type_getChannel;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/LiveTv/Channels/{}"sv,
            input.channelId
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
 * returnType: OAIBaseItemDto
 * returnFormat: 
 * returnBaseType: OAIBaseItemDto
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: OAIBaseItemDto()
 */
};
// Get channel mapping options.
struct getChannelMappingOptions {
public:
    using in_type                      = param::getChannelMappingOptions;
    using out_type                     = model::return_type_getChannelMappingOptions;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/ChannelMappingOptions"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.providerId)
            p.set_param("providerId", convert_from<std::string>(input.providerId.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIChannelMappingOptionsDto
 * returnFormat: 
 * returnBaseType: OAIChannelMappingOptionsDto
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: OAIChannelMappingOptionsDto()
 */
};
// Gets default listings provider info.
struct getDefaultListingProvider {
public:
    using in_type                      = param::getDefaultListingProvider;
    using out_type                     = model::return_type_getDefaultListingProvider;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/ListingProviders/Default"sv; 
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
 * returnType: OAIListingsProviderInfo
 * returnFormat: 
 * returnBaseType: OAIListingsProviderInfo
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: OAIListingsProviderInfo()
 */
};
// Gets the default values for a new timer.
struct getDefaultTimer {
public:
    using in_type                      = param::getDefaultTimer;
    using out_type                     = model::return_type_getDefaultTimer;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/Timers/Defaults"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.programId)
            p.set_param("programId", convert_from<std::string>(input.programId.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAISeriesTimerInfoDto
 * returnFormat: 
 * returnBaseType: OAISeriesTimerInfoDto
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: OAISeriesTimerInfoDto()
 */
};
// Get guid info.
struct getGuideInfo {
public:
    using in_type                      = param::getGuideInfo;
    using out_type                     = model::return_type_getGuideInfo;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/GuideInfo"sv; 
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
 * returnType: OAIGuideInfo
 * returnFormat: 
 * returnBaseType: OAIGuideInfo
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: OAIGuideInfo()
 */
};
// Gets available lineups.
struct getLineups {
public:
    using in_type                      = param::getLineups;
    using out_type                     = model::return_type_getLineups;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/ListingProviders/Lineups"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.id)
            p.set_param("id", convert_from<std::string>(input.id.value()));
        if(input.type)
            p.set_param("type", convert_from<std::string>(input.type.value()));
        if(input.location)
            p.set_param("location", convert_from<std::string>(input.location.value()));
        if(input.country)
            p.set_param("country", convert_from<std::string>(input.country.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;OAINameIdPair&gt;
 * returnFormat: 
 * returnBaseType: OAINameIdPair
 * returnContainer: array
 * baseName: LiveTv
 * defaultResponse: {}
 */
};
// Gets a live tv recording stream.
struct getLiveRecordingFile {
public:
    using in_type                      = param::getLiveRecordingFile;
    using out_type                     = model::return_type_getLiveRecordingFile;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/LiveTv/LiveRecordings/{}/stream"sv,
            input.recordingId
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
 * baseName: LiveTv
 * defaultResponse: {}
 */
};
// Gets a live tv channel stream.
struct getLiveStreamFile {
public:
    using in_type                      = param::getLiveStreamFile;
    using out_type                     = model::return_type_getLiveStreamFile;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/LiveTv/LiveStreamFiles/{}/stream.{}"sv,
            input.streamId,
            input.container
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
 * baseName: LiveTv
 * defaultResponse: {}
 */
};
// Gets available live tv channels.
struct getLiveTvChannels {
public:
    using in_type                      = param::getLiveTvChannels;
    using out_type                     = model::return_type_getLiveTvChannels;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/Channels"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.type)
            p.set_param("type", convert_from<std::string>(input.type.value()));
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
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
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.isFavorite)
            p.set_param("isFavorite", convert_from<std::string>(input.isFavorite.value()));
        if(input.isLiked)
            p.set_param("isLiked", convert_from<std::string>(input.isLiked.value()));
        if(input.isDisliked)
            p.set_param("isDisliked", convert_from<std::string>(input.isDisliked.value()));
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.sortBy)
            p.set_param("sortBy", input.sortBy.value());
        if(input.sortOrder)
            p.set_param("sortOrder", convert_from<std::string>(input.sortOrder.value()));
        if(input.enableFavoriteSorting)
            p.set_param("enableFavoriteSorting", convert_from<std::string>(input.enableFavoriteSorting.value()));
        if(input.addCurrentProgram)
            p.set_param("addCurrentProgram", convert_from<std::string>(input.addCurrentProgram.value()));
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
 * baseName: LiveTv
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets available live tv services.
struct getLiveTvInfo {
public:
    using in_type                      = param::getLiveTvInfo;
    using out_type                     = model::return_type_getLiveTvInfo;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/Info"sv; 
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
 * returnType: OAILiveTvInfo
 * returnFormat: 
 * returnBaseType: OAILiveTvInfo
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: OAILiveTvInfo()
 */
};
// Gets available live tv epgs.
struct getLiveTvPrograms {
public:
    using in_type                      = param::getLiveTvPrograms;
    using out_type                     = model::return_type_getLiveTvPrograms;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/Programs"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.channelIds)
            p.set_param("channelIds", input.channelIds.value());
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.minStartDate)
            p.set_param("minStartDate", convert_from<std::string>(input.minStartDate.value()));
        if(input.hasAired)
            p.set_param("hasAired", convert_from<std::string>(input.hasAired.value()));
        if(input.isAiring)
            p.set_param("isAiring", convert_from<std::string>(input.isAiring.value()));
        if(input.maxStartDate)
            p.set_param("maxStartDate", convert_from<std::string>(input.maxStartDate.value()));
        if(input.minEndDate)
            p.set_param("minEndDate", convert_from<std::string>(input.minEndDate.value()));
        if(input.maxEndDate)
            p.set_param("maxEndDate", convert_from<std::string>(input.maxEndDate.value()));
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
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.sortBy)
            p.set_param("sortBy", input.sortBy.value());
        if(input.sortOrder)
            p.set_param("sortOrder", input.sortOrder.value());
        if(input.genres)
            p.set_param("genres", input.genres.value());
        if(input.genreIds)
            p.set_param("genreIds", input.genreIds.value());
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.seriesTimerId)
            p.set_param("seriesTimerId", convert_from<std::string>(input.seriesTimerId.value()));
        if(input.librarySeriesId)
            p.set_param("librarySeriesId", convert_from<std::string>(input.librarySeriesId.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.enableTotalRecordCount)
            p.set_param("enableTotalRecordCount", convert_from<std::string>(input.enableTotalRecordCount.value()));
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
 * baseName: LiveTv
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets a live tv program.
struct getProgram {
public:
    using in_type                      = param::getProgram;
    using out_type                     = model::return_type_getProgram;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/LiveTv/Programs/{}"sv,
            input.programId
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
 * returnType: OAIBaseItemDto
 * returnFormat: 
 * returnBaseType: OAIBaseItemDto
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: OAIBaseItemDto()
 */
};
// Gets available live tv epgs.
struct getPrograms {
public:
    using in_type                      = param::getPrograms;
    using out_type                     = model::return_type_getPrograms;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/LiveTv/Programs"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
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
 * returnType: OAIBaseItemDtoQueryResult
 * returnFormat: 
 * returnBaseType: OAIBaseItemDtoQueryResult
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets recommended live tv epgs.
struct getRecommendedPrograms {
public:
    using in_type                      = param::getRecommendedPrograms;
    using out_type                     = model::return_type_getRecommendedPrograms;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/Programs/Recommended"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.isAiring)
            p.set_param("isAiring", convert_from<std::string>(input.isAiring.value()));
        if(input.hasAired)
            p.set_param("hasAired", convert_from<std::string>(input.hasAired.value()));
        if(input.isSeries)
            p.set_param("isSeries", convert_from<std::string>(input.isSeries.value()));
        if(input.isMovie)
            p.set_param("isMovie", convert_from<std::string>(input.isMovie.value()));
        if(input.isNews)
            p.set_param("isNews", convert_from<std::string>(input.isNews.value()));
        if(input.isKids)
            p.set_param("isKids", convert_from<std::string>(input.isKids.value()));
        if(input.isSports)
            p.set_param("isSports", convert_from<std::string>(input.isSports.value()));
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
        if(input.genreIds)
            p.set_param("genreIds", input.genreIds.value());
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.enableTotalRecordCount)
            p.set_param("enableTotalRecordCount", convert_from<std::string>(input.enableTotalRecordCount.value()));
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
 * baseName: LiveTv
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets a live tv recording.
struct getRecording {
public:
    using in_type                      = param::getRecording;
    using out_type                     = model::return_type_getRecording;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/LiveTv/Recordings/{}"sv,
            input.recordingId
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
 * returnType: OAIBaseItemDto
 * returnFormat: 
 * returnBaseType: OAIBaseItemDto
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: OAIBaseItemDto()
 */
};
// Gets recording folders.
struct getRecordingFolders {
public:
    using in_type                      = param::getRecordingFolders;
    using out_type                     = model::return_type_getRecordingFolders;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/Recordings/Folders"sv; 
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
 * returnType: OAIBaseItemDtoQueryResult
 * returnFormat: 
 * returnBaseType: OAIBaseItemDtoQueryResult
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Get recording group.
struct getRecordingGroup {
public:
    using in_type                      = param::getRecordingGroup;
    using out_type                     = model::return_type_getRecordingGroup;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/LiveTv/Recordings/Groups/{}"sv,
            input.groupId
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
 * baseName: LiveTv
 * defaultResponse: 
 */
};
// Gets live tv recording groups.
struct getRecordingGroups {
public:
    using in_type                      = param::getRecordingGroups;
    using out_type                     = model::return_type_getRecordingGroups;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/Recordings/Groups"sv; 
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
 * returnType: OAIBaseItemDtoQueryResult
 * returnFormat: 
 * returnBaseType: OAIBaseItemDtoQueryResult
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets live tv recordings.
struct getRecordings {
public:
    using in_type                      = param::getRecordings;
    using out_type                     = model::return_type_getRecordings;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/Recordings"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.channelId)
            p.set_param("channelId", convert_from<std::string>(input.channelId.value()));
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.status)
            p.set_param("status", convert_from<std::string>(input.status.value()));
        if(input.isInProgress)
            p.set_param("isInProgress", convert_from<std::string>(input.isInProgress.value()));
        if(input.seriesTimerId)
            p.set_param("seriesTimerId", convert_from<std::string>(input.seriesTimerId.value()));
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.isMovie)
            p.set_param("isMovie", convert_from<std::string>(input.isMovie.value()));
        if(input.isSeries)
            p.set_param("isSeries", convert_from<std::string>(input.isSeries.value()));
        if(input.isKids)
            p.set_param("isKids", convert_from<std::string>(input.isKids.value()));
        if(input.isSports)
            p.set_param("isSports", convert_from<std::string>(input.isSports.value()));
        if(input.isNews)
            p.set_param("isNews", convert_from<std::string>(input.isNews.value()));
        if(input.isLibraryItem)
            p.set_param("isLibraryItem", convert_from<std::string>(input.isLibraryItem.value()));
        if(input.enableTotalRecordCount)
            p.set_param("enableTotalRecordCount", convert_from<std::string>(input.enableTotalRecordCount.value()));
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
 * baseName: LiveTv
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets live tv recording series.
struct getRecordingsSeries {
public:
    using in_type                      = param::getRecordingsSeries;
    using out_type                     = model::return_type_getRecordingsSeries;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/Recordings/Series"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.channelId)
            p.set_param("channelId", convert_from<std::string>(input.channelId.value()));
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.groupId)
            p.set_param("groupId", convert_from<std::string>(input.groupId.value()));
        if(input.startIndex)
            p.set_param("startIndex", convert_from<std::string>(input.startIndex.value()));
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.status)
            p.set_param("status", convert_from<std::string>(input.status.value()));
        if(input.isInProgress)
            p.set_param("isInProgress", convert_from<std::string>(input.isInProgress.value()));
        if(input.seriesTimerId)
            p.set_param("seriesTimerId", convert_from<std::string>(input.seriesTimerId.value()));
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.enableTotalRecordCount)
            p.set_param("enableTotalRecordCount", convert_from<std::string>(input.enableTotalRecordCount.value()));
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
 * baseName: LiveTv
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
// Gets available countries.
struct getSchedulesDirectCountries {
public:
    using in_type                      = param::getSchedulesDirectCountries;
    using out_type                     = model::return_type_getSchedulesDirectCountries;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/ListingProviders/SchedulesDirect/Countries"sv; 
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
 * baseName: LiveTv
 * defaultResponse: {}
 */
};
// Gets a live tv series timer.
struct getSeriesTimer {
public:
    using in_type                      = param::getSeriesTimer;
    using out_type                     = model::return_type_getSeriesTimer;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/LiveTv/SeriesTimers/{}"sv,
            input.timerId
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
 * returnType: OAISeriesTimerInfoDto
 * returnFormat: 
 * returnBaseType: OAISeriesTimerInfoDto
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: OAISeriesTimerInfoDto()
 */
};
// Gets live tv series timers.
struct getSeriesTimers {
public:
    using in_type                      = param::getSeriesTimers;
    using out_type                     = model::return_type_getSeriesTimers;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/SeriesTimers"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.sortBy)
            p.set_param("sortBy", convert_from<std::string>(input.sortBy.value()));
        if(input.sortOrder)
            p.set_param("sortOrder", convert_from<std::string>(input.sortOrder.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAISeriesTimerInfoDtoQueryResult
 * returnFormat: 
 * returnBaseType: OAISeriesTimerInfoDtoQueryResult
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: OAISeriesTimerInfoDtoQueryResult()
 */
};
// Gets a timer.
struct getTimer {
public:
    using in_type                      = param::getTimer;
    using out_type                     = model::return_type_getTimer;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/LiveTv/Timers/{}"sv,
            input.timerId
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
 * returnType: OAITimerInfoDto
 * returnFormat: 
 * returnBaseType: OAITimerInfoDto
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: OAITimerInfoDto()
 */
};
// Gets the live tv timers.
struct getTimers {
public:
    using in_type                      = param::getTimers;
    using out_type                     = model::return_type_getTimers;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/Timers"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.channelId)
            p.set_param("channelId", convert_from<std::string>(input.channelId.value()));
        if(input.seriesTimerId)
            p.set_param("seriesTimerId", convert_from<std::string>(input.seriesTimerId.value()));
        if(input.isActive)
            p.set_param("isActive", convert_from<std::string>(input.isActive.value()));
        if(input.isScheduled)
            p.set_param("isScheduled", convert_from<std::string>(input.isScheduled.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAITimerInfoDtoQueryResult
 * returnFormat: 
 * returnBaseType: OAITimerInfoDtoQueryResult
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: OAITimerInfoDtoQueryResult()
 */
};
// Get tuner host types.
struct getTunerHostTypes {
public:
    using in_type                      = param::getTunerHostTypes;
    using out_type                     = model::return_type_getTunerHostTypes;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/LiveTv/TunerHosts/Types"sv; 
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
 * returnType: std::vector&lt;OAINameIdPair&gt;
 * returnFormat: 
 * returnBaseType: OAINameIdPair
 * returnContainer: array
 * baseName: LiveTv
 * defaultResponse: {}
 */
};
// Resets a tv tuner.
struct resetTuner {
public:
    using in_type                      = param::resetTuner;
    using out_type                     = model::return_type_resetTuner;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/LiveTv/Tuners/{}/Reset"sv,
            input.tunerId
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
 * baseName: LiveTv
 * defaultResponse: 
 */
};
// Set channel mappings.
struct setChannelMapping {
public:
    using in_type                      = param::setChannelMapping;
    using out_type                     = model::return_type_setChannelMapping;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/LiveTv/ChannelMappings"sv; 
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
 * returnType: OAITunerChannelMapping
 * returnFormat: 
 * returnBaseType: OAITunerChannelMapping
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: OAITunerChannelMapping()
 */
};
// Updates a live tv series timer.
struct updateSeriesTimer {
public:
    using in_type                      = param::updateSeriesTimer;
    using out_type                     = model::return_type_updateSeriesTimer;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/LiveTv/SeriesTimers/{}"sv,
            input.timerId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
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
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: 
 */
};
// Updates a live tv timer.
struct updateTimer {
public:
    using in_type                      = param::updateTimer;
    using out_type                     = model::return_type_updateTimer;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/LiveTv/Timers/{}"sv,
            input.timerId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
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
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: LiveTv
 * defaultResponse: 
 */
};
}
}
