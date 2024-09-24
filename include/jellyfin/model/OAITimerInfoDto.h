#pragma once

/*
 * OAITimerInfoDto.h
 * name: TimerInfoDto
 * schemaName: TimerInfoDto
 * classFilename: TimerInfoDto
 * classVarName: TimerInfoDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIBaseItemDto.h"
#include "jellyfin/model/OAIKeepUntil.h"
#include "jellyfin/model/OAIRecordingStatus.h"
#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIBaseItemDto;


    class OAITimerInfoDto {
    public:
    
        // Gets or sets the Id of the recording.
        std::optional<std::string> Id;

        std::optional<std::string> Type;

        // Gets or sets the server identifier.
        std::optional<std::string> ServerId;

        // Gets or sets the external identifier.
        std::optional<std::string> ExternalId;

        // Gets or sets the channel id of the recording.
        std::string ChannelId;

        // Gets or sets the external channel identifier.
        std::optional<std::string> ExternalChannelId;

        // Gets or sets the channel name of the recording.
        std::optional<std::string> ChannelName;

        std::optional<std::string> ChannelPrimaryImageTag;

        // Gets or sets the program identifier.
        std::optional<std::string> ProgramId;

        // Gets or sets the external program identifier.
        std::optional<std::string> ExternalProgramId;

        // Gets or sets the name of the recording.
        std::optional<std::string> Name;

        // Gets or sets the description of the recording.
        std::optional<std::string> Overview;

        // Gets or sets the start date of the recording, in UTC.
        std::string StartDate;

        // Gets or sets the end date of the recording, in UTC.
        std::string EndDate;

        // Gets or sets the name of the service.
        std::optional<std::string> ServiceName;

        // Gets or sets the priority.
        std::int32_t Priority;

        // Gets or sets the pre padding seconds.
        std::int32_t PrePaddingSeconds;

        // Gets or sets the post padding seconds.
        std::int32_t PostPaddingSeconds;

        // Gets or sets a value indicating whether this instance is pre padding required.
        bool IsPrePaddingRequired;

        // Gets or sets the Id of the Parent that has a backdrop if the item does not have one.
        std::optional<std::string> ParentBackdropItemId;

        // Gets or sets the parent backdrop image tags.
        std::optional<std::vector<std::string>> ParentBackdropImageTags;

        // Gets or sets a value indicating whether this instance is post padding required.
        bool IsPostPaddingRequired;

        OAIKeepUntil KeepUntil;

        // Gets or sets the status.
        OAIRecordingStatus Status;

        // Gets or sets the series timer identifier.
        std::optional<std::string> SeriesTimerId;

        // Gets or sets the external series timer identifier.
        std::optional<std::string> ExternalSeriesTimerId;

        // Gets or sets the run time ticks.
        std::optional<std::int64_t> RunTimeTicks;

        // Gets or sets the program information.
        std::optional<OAIBaseItemDto> ProgramInfo;

        OAITimerInfoDto();
        ~OAITimerInfoDto();
    };
    extern void to_json(json_t&, const OAITimerInfoDto&);
    extern void from_json(const json_t&, OAITimerInfoDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAITimerInfoDto);
