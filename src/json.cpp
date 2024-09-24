#include <sstream>

#include "jellyfin/model/OAIAccessSchedule.h"
#include "jellyfin/model/OAIActivityLogEntry.h"
#include "jellyfin/model/OAIActivityLogEntryMessage.h"
#include "jellyfin/model/OAIActivityLogEntryQueryResult.h"
#include "jellyfin/model/OAIActivityLogEntryStartMessage.h"
#include "jellyfin/model/OAIActivityLogEntryStopMessage.h"
#include "jellyfin/model/OAIAddVirtualFolderDto.h"
#include "jellyfin/model/OAIAlbumInfo.h"
#include "jellyfin/model/OAIAlbumInfoRemoteSearchQuery.h"
#include "jellyfin/model/OAIAllThemeMediaResult.h"
#include "jellyfin/model/OAIArtistInfo.h"
#include "jellyfin/model/OAIArtistInfoRemoteSearchQuery.h"
#include "jellyfin/model/OAIAudioSpatialFormat.h"
#include "jellyfin/model/OAIAuthenticateUserByName.h"
#include "jellyfin/model/OAIAuthenticationInfo.h"
#include "jellyfin/model/OAIAuthenticationInfoQueryResult.h"
#include "jellyfin/model/OAIAuthenticationResult.h"
#include "jellyfin/model/OAIBaseItemDto.h"
#include "jellyfin/model/OAIBaseItemDtoImageBlurHashes.h"
#include "jellyfin/model/OAIBaseItemDtoQueryResult.h"
#include "jellyfin/model/OAIBaseItemKind.h"
#include "jellyfin/model/OAIBaseItemPerson.h"
#include "jellyfin/model/OAIBaseItemPersonImageBlurHashes.h"
#include "jellyfin/model/OAIBookInfo.h"
#include "jellyfin/model/OAIBookInfoRemoteSearchQuery.h"
#include "jellyfin/model/OAIBoxSetInfo.h"
#include "jellyfin/model/OAIBoxSetInfoRemoteSearchQuery.h"
#include "jellyfin/model/OAIBrandingOptions.h"
#include "jellyfin/model/OAIBufferRequestDto.h"
#include "jellyfin/model/OAICastReceiverApplication.h"
#include "jellyfin/model/OAIChannelFeatures.h"
#include "jellyfin/model/OAIChannelItemSortField.h"
#include "jellyfin/model/OAIChannelMappingOptionsDto.h"
#include "jellyfin/model/OAIChannelMediaContentType.h"
#include "jellyfin/model/OAIChannelMediaType.h"
#include "jellyfin/model/OAIChannelType.h"
#include "jellyfin/model/OAIChapterInfo.h"
#include "jellyfin/model/OAIClientCapabilities.h"
#include "jellyfin/model/OAIClientCapabilitiesDto.h"
#include "jellyfin/model/OAIClientLogDocumentResponseDto.h"
#include "jellyfin/model/OAICodecProfile.h"
#include "jellyfin/model/OAICodecType.h"
#include "jellyfin/model/OAICollectionCreationResult.h"
#include "jellyfin/model/OAICollectionType.h"
#include "jellyfin/model/OAICollectionTypeOptions.h"
#include "jellyfin/model/OAIConfigImageTypes.h"
#include "jellyfin/model/OAIConfigurationPageInfo.h"
#include "jellyfin/model/OAIContainerProfile.h"
#include "jellyfin/model/OAICountryInfo.h"
#include "jellyfin/model/OAICreatePlaylistDto.h"
#include "jellyfin/model/OAICreateUserByName.h"
#include "jellyfin/model/OAICultureDto.h"
#include "jellyfin/model/OAIDayOfWeek.h"
#include "jellyfin/model/OAIDayPattern.h"
#include "jellyfin/model/OAIDefaultDirectoryBrowserInfoDto.h"
#include "jellyfin/model/OAIDeviceInfo.h"
#include "jellyfin/model/OAIDeviceInfoQueryResult.h"
#include "jellyfin/model/OAIDeviceOptions.h"
#include "jellyfin/model/OAIDeviceOptionsDto.h"
#include "jellyfin/model/OAIDeviceProfile.h"
#include "jellyfin/model/OAIDirectPlayProfile.h"
#include "jellyfin/model/OAIDisplayPreferencesDto.h"
#include "jellyfin/model/OAIDlnaProfileType.h"
#include "jellyfin/model/OAIDownMixStereoAlgorithms.h"
#include "jellyfin/model/OAIDynamicDayOfWeek.h"
#include "jellyfin/model/OAIEmbeddedSubtitleOptions.h"
#include "jellyfin/model/OAIEncodingContext.h"
#include "jellyfin/model/OAIEncodingOptions.h"
#include "jellyfin/model/OAIEndPointInfo.h"
#include "jellyfin/model/OAIExternalIdInfo.h"
#include "jellyfin/model/OAIExternalIdMediaType.h"
#include "jellyfin/model/OAIExternalUrl.h"
#include "jellyfin/model/OAIExtraType.h"
#include "jellyfin/model/OAIFileSystemEntryInfo.h"
#include "jellyfin/model/OAIFileSystemEntryType.h"
#include "jellyfin/model/OAIFontFile.h"
#include "jellyfin/model/OAIForceKeepAliveMessage.h"
#include "jellyfin/model/OAIForgotPasswordAction.h"
#include "jellyfin/model/OAIForgotPasswordDto.h"
#include "jellyfin/model/OAIForgotPasswordPinDto.h"
#include "jellyfin/model/OAIForgotPasswordResult.h"
#include "jellyfin/model/OAIGeneralCommand.h"
#include "jellyfin/model/OAIGeneralCommandMessage.h"
#include "jellyfin/model/OAIGeneralCommandType.h"
#include "jellyfin/model/OAIGetProgramsDto.h"
#include "jellyfin/model/OAIGroupInfoDto.h"
#include "jellyfin/model/OAIGroupInfoDtoGroupUpdate.h"
#include "jellyfin/model/OAIGroupQueueMode.h"
#include "jellyfin/model/OAIGroupRepeatMode.h"
#include "jellyfin/model/OAIGroupShuffleMode.h"
#include "jellyfin/model/OAIGroupStateType.h"
#include "jellyfin/model/OAIGroupStateUpdate.h"
#include "jellyfin/model/OAIGroupStateUpdateGroupUpdate.h"
#include "jellyfin/model/OAIGroupUpdate.h"
#include "jellyfin/model/OAIGroupUpdateType.h"
#include "jellyfin/model/OAIGuideInfo.h"
#include "jellyfin/model/OAIHardwareEncodingType.h"
#include "jellyfin/model/OAIIPlugin.h"
#include "jellyfin/model/OAIIgnoreWaitRequestDto.h"
#include "jellyfin/model/OAIImageFormat.h"
#include "jellyfin/model/OAIImageInfo.h"
#include "jellyfin/model/OAIImageOption.h"
#include "jellyfin/model/OAIImageOrientation.h"
#include "jellyfin/model/OAIImageProviderInfo.h"
#include "jellyfin/model/OAIImageResolution.h"
#include "jellyfin/model/OAIImageSavingConvention.h"
#include "jellyfin/model/OAIImageType.h"
#include "jellyfin/model/OAIInboundKeepAliveMessage.h"
#include "jellyfin/model/OAIInboundWebSocketMessage.h"
#include "jellyfin/model/OAIInstallationInfo.h"
#include "jellyfin/model/OAIIsoType.h"
#include "jellyfin/model/OAIItemCounts.h"
#include "jellyfin/model/OAIItemFields.h"
#include "jellyfin/model/OAIItemFilter.h"
#include "jellyfin/model/OAIItemSortBy.h"
#include "jellyfin/model/OAIJoinGroupRequestDto.h"
#include "jellyfin/model/OAIKeepUntil.h"
#include "jellyfin/model/OAILibraryChangedMessage.h"
#include "jellyfin/model/OAILibraryOptionInfoDto.h"
#include "jellyfin/model/OAILibraryOptions.h"
#include "jellyfin/model/OAILibraryOptionsResultDto.h"
#include "jellyfin/model/OAILibraryTypeOptionsDto.h"
#include "jellyfin/model/OAILibraryUpdateInfo.h"
#include "jellyfin/model/OAIListingsProviderInfo.h"
#include "jellyfin/model/OAILiveStreamResponse.h"
#include "jellyfin/model/OAILiveTvInfo.h"
#include "jellyfin/model/OAILiveTvOptions.h"
#include "jellyfin/model/OAILiveTvServiceInfo.h"
#include "jellyfin/model/OAILiveTvServiceStatus.h"
#include "jellyfin/model/OAILocalizationOption.h"
#include "jellyfin/model/OAILocationType.h"
#include "jellyfin/model/OAILogFile.h"
#include "jellyfin/model/OAILogLevel.h"
#include "jellyfin/model/OAILyricDto.h"
#include "jellyfin/model/OAILyricLine.h"
#include "jellyfin/model/OAILyricMetadata.h"
#include "jellyfin/model/OAIMediaAttachment.h"
#include "jellyfin/model/OAIMediaPathDto.h"
#include "jellyfin/model/OAIMediaPathInfo.h"
#include "jellyfin/model/OAIMediaProtocol.h"
#include "jellyfin/model/OAIMediaSourceInfo.h"
#include "jellyfin/model/OAIMediaSourceType.h"
#include "jellyfin/model/OAIMediaStream.h"
#include "jellyfin/model/OAIMediaStreamProtocol.h"
#include "jellyfin/model/OAIMediaStreamType.h"
#include "jellyfin/model/OAIMediaType.h"
#include "jellyfin/model/OAIMediaUpdateInfoDto.h"
#include "jellyfin/model/OAIMediaUpdateInfoPathDto.h"
#include "jellyfin/model/OAIMediaUrl.h"
#include "jellyfin/model/OAIMessageCommand.h"
#include "jellyfin/model/OAIMetadataConfiguration.h"
#include "jellyfin/model/OAIMetadataEditorInfo.h"
#include "jellyfin/model/OAIMetadataField.h"
#include "jellyfin/model/OAIMetadataOptions.h"
#include "jellyfin/model/OAIMetadataRefreshMode.h"
#include "jellyfin/model/OAIMovePlaylistItemRequestDto.h"
#include "jellyfin/model/OAIMovieInfo.h"
#include "jellyfin/model/OAIMovieInfoRemoteSearchQuery.h"
#include "jellyfin/model/OAIMusicVideoInfo.h"
#include "jellyfin/model/OAIMusicVideoInfoRemoteSearchQuery.h"
#include "jellyfin/model/OAINameGuidPair.h"
#include "jellyfin/model/OAINameIdPair.h"
#include "jellyfin/model/OAINameValuePair.h"
#include "jellyfin/model/OAINetworkConfiguration.h"
#include "jellyfin/model/OAINewGroupRequestDto.h"
#include "jellyfin/model/OAINextItemRequestDto.h"
#include "jellyfin/model/OAIOpenLiveStreamDto.h"
#include "jellyfin/model/OAIOutboundKeepAliveMessage.h"
#include "jellyfin/model/OAIOutboundWebSocketMessage.h"
#include "jellyfin/model/OAIPackageInfo.h"
#include "jellyfin/model/OAIParentalRating.h"
#include "jellyfin/model/OAIPathSubstitution.h"
#include "jellyfin/model/OAIPersonKind.h"
#include "jellyfin/model/OAIPersonLookupInfo.h"
#include "jellyfin/model/OAIPersonLookupInfoRemoteSearchQuery.h"
#include "jellyfin/model/OAIPinRedeemResult.h"
#include "jellyfin/model/OAIPingRequestDto.h"
#include "jellyfin/model/OAIPlayAccess.h"
#include "jellyfin/model/OAIPlayCommand.h"
#include "jellyfin/model/OAIPlayMessage.h"
#include "jellyfin/model/OAIPlayMethod.h"
#include "jellyfin/model/OAIPlayQueueUpdate.h"
#include "jellyfin/model/OAIPlayQueueUpdateGroupUpdate.h"
#include "jellyfin/model/OAIPlayQueueUpdateReason.h"
#include "jellyfin/model/OAIPlayRequest.h"
#include "jellyfin/model/OAIPlayRequestDto.h"
#include "jellyfin/model/OAIPlaybackErrorCode.h"
#include "jellyfin/model/OAIPlaybackInfoDto.h"
#include "jellyfin/model/OAIPlaybackInfoResponse.h"
#include "jellyfin/model/OAIPlaybackOrder.h"
#include "jellyfin/model/OAIPlaybackProgressInfo.h"
#include "jellyfin/model/OAIPlaybackRequestType.h"
#include "jellyfin/model/OAIPlaybackStartInfo.h"
#include "jellyfin/model/OAIPlaybackStopInfo.h"
#include "jellyfin/model/OAIPlayerStateInfo.h"
#include "jellyfin/model/OAIPlaylistCreationResult.h"
#include "jellyfin/model/OAIPlaylistUserPermissions.h"
#include "jellyfin/model/OAIPlaystateCommand.h"
#include "jellyfin/model/OAIPlaystateMessage.h"
#include "jellyfin/model/OAIPlaystateRequest.h"
#include "jellyfin/model/OAIPluginInfo.h"
#include "jellyfin/model/OAIPluginInstallationCancelledMessage.h"
#include "jellyfin/model/OAIPluginInstallationCompletedMessage.h"
#include "jellyfin/model/OAIPluginInstallationFailedMessage.h"
#include "jellyfin/model/OAIPluginInstallingMessage.h"
#include "jellyfin/model/OAIPluginStatus.h"
#include "jellyfin/model/OAIPluginUninstalledMessage.h"
#include "jellyfin/model/OAIPreviousItemRequestDto.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAIProcessPriorityClass.h"
#include "jellyfin/model/OAIProfileCondition.h"
#include "jellyfin/model/OAIProfileConditionType.h"
#include "jellyfin/model/OAIProfileConditionValue.h"
#include "jellyfin/model/OAIProgramAudio.h"
#include "jellyfin/model/OAIPublicSystemInfo.h"
#include "jellyfin/model/OAIQueryFilters.h"
#include "jellyfin/model/OAIQueryFiltersLegacy.h"
#include "jellyfin/model/OAIQueueItem.h"
#include "jellyfin/model/OAIQueueRequestDto.h"
#include "jellyfin/model/OAIQuickConnectDto.h"
#include "jellyfin/model/OAIQuickConnectResult.h"
#include "jellyfin/model/OAIRatingType.h"
#include "jellyfin/model/OAIReadyRequestDto.h"
#include "jellyfin/model/OAIRecommendationDto.h"
#include "jellyfin/model/OAIRecommendationType.h"
#include "jellyfin/model/OAIRecordingStatus.h"
#include "jellyfin/model/OAIRefreshProgressMessage.h"
#include "jellyfin/model/OAIRemoteImageInfo.h"
#include "jellyfin/model/OAIRemoteImageResult.h"
#include "jellyfin/model/OAIRemoteLyricInfoDto.h"
#include "jellyfin/model/OAIRemoteSearchResult.h"
#include "jellyfin/model/OAIRemoteSubtitleInfo.h"
#include "jellyfin/model/OAIRemoveFromPlaylistRequestDto.h"
#include "jellyfin/model/OAIRepeatMode.h"
#include "jellyfin/model/OAIRepositoryInfo.h"
#include "jellyfin/model/OAIRestartRequiredMessage.h"
#include "jellyfin/model/OAIScheduledTaskEndedMessage.h"
#include "jellyfin/model/OAIScheduledTasksInfoMessage.h"
#include "jellyfin/model/OAIScheduledTasksInfoStartMessage.h"
#include "jellyfin/model/OAIScheduledTasksInfoStopMessage.h"
#include "jellyfin/model/OAIScrollDirection.h"
#include "jellyfin/model/OAISearchHint.h"
#include "jellyfin/model/OAISearchHintResult.h"
#include "jellyfin/model/OAISeekRequestDto.h"
#include "jellyfin/model/OAISendCommand.h"
#include "jellyfin/model/OAISendCommandType.h"
#include "jellyfin/model/OAISeriesInfo.h"
#include "jellyfin/model/OAISeriesInfoRemoteSearchQuery.h"
#include "jellyfin/model/OAISeriesStatus.h"
#include "jellyfin/model/OAISeriesTimerCancelledMessage.h"
#include "jellyfin/model/OAISeriesTimerCreatedMessage.h"
#include "jellyfin/model/OAISeriesTimerInfoDto.h"
#include "jellyfin/model/OAISeriesTimerInfoDtoQueryResult.h"
#include "jellyfin/model/OAIServerConfiguration.h"
#include "jellyfin/model/OAIServerDiscoveryInfo.h"
#include "jellyfin/model/OAIServerRestartingMessage.h"
#include "jellyfin/model/OAIServerShuttingDownMessage.h"
#include "jellyfin/model/OAISessionInfo.h"
#include "jellyfin/model/OAISessionMessageType.h"
#include "jellyfin/model/OAISessionUserInfo.h"
#include "jellyfin/model/OAISessionsMessage.h"
#include "jellyfin/model/OAISessionsStartMessage.h"
#include "jellyfin/model/OAISessionsStopMessage.h"
#include "jellyfin/model/OAISetChannelMappingDto.h"
#include "jellyfin/model/OAISetPlaylistItemRequestDto.h"
#include "jellyfin/model/OAISetRepeatModeRequestDto.h"
#include "jellyfin/model/OAISetShuffleModeRequestDto.h"
#include "jellyfin/model/OAISongInfo.h"
#include "jellyfin/model/OAISortOrder.h"
#include "jellyfin/model/OAISpecialViewOptionDto.h"
#include "jellyfin/model/OAIStartupConfigurationDto.h"
#include "jellyfin/model/OAIStartupRemoteAccessDto.h"
#include "jellyfin/model/OAIStartupUserDto.h"
#include "jellyfin/model/OAIStringGroupUpdate.h"
#include "jellyfin/model/OAISubtitleDeliveryMethod.h"
#include "jellyfin/model/OAISubtitleOptions.h"
#include "jellyfin/model/OAISubtitlePlaybackMode.h"
#include "jellyfin/model/OAISubtitleProfile.h"
#include "jellyfin/model/OAISyncPlayCommandMessage.h"
#include "jellyfin/model/OAISyncPlayGroupUpdateCommandMessage.h"
#include "jellyfin/model/OAISyncPlayQueueItem.h"
#include "jellyfin/model/OAISyncPlayUserAccessType.h"
#include "jellyfin/model/OAISystemInfo.h"
#include "jellyfin/model/OAITaskCompletionStatus.h"
#include "jellyfin/model/OAITaskInfo.h"
#include "jellyfin/model/OAITaskResult.h"
#include "jellyfin/model/OAITaskState.h"
#include "jellyfin/model/OAITaskTriggerInfo.h"
#include "jellyfin/model/OAIThemeMediaResult.h"
#include "jellyfin/model/OAITimerCancelledMessage.h"
#include "jellyfin/model/OAITimerCreatedMessage.h"
#include "jellyfin/model/OAITimerEventInfo.h"
#include "jellyfin/model/OAITimerInfoDto.h"
#include "jellyfin/model/OAITimerInfoDtoQueryResult.h"
#include "jellyfin/model/OAITrailerInfo.h"
#include "jellyfin/model/OAITrailerInfoRemoteSearchQuery.h"
#include "jellyfin/model/OAITranscodeReason.h"
#include "jellyfin/model/OAITranscodeSeekInfo.h"
#include "jellyfin/model/OAITranscodingInfo.h"
#include "jellyfin/model/OAITranscodingProfile.h"
#include "jellyfin/model/OAITransportStreamTimestamp.h"
#include "jellyfin/model/OAITrickplayInfo.h"
#include "jellyfin/model/OAITrickplayOptions.h"
#include "jellyfin/model/OAITrickplayScanBehavior.h"
#include "jellyfin/model/OAITunerChannelMapping.h"
#include "jellyfin/model/OAITunerHostInfo.h"
#include "jellyfin/model/OAITypeOptions.h"
#include "jellyfin/model/OAIUnratedItem.h"
#include "jellyfin/model/OAIUpdateLibraryOptionsDto.h"
#include "jellyfin/model/OAIUpdateMediaPathRequestDto.h"
#include "jellyfin/model/OAIUpdatePlaylistDto.h"
#include "jellyfin/model/OAIUpdatePlaylistUserDto.h"
#include "jellyfin/model/OAIUpdateUserItemDataDto.h"
#include "jellyfin/model/OAIUpdateUserPassword.h"
#include "jellyfin/model/OAIUploadSubtitleDto.h"
#include "jellyfin/model/OAIUserConfiguration.h"
#include "jellyfin/model/OAIUserDataChangeInfo.h"
#include "jellyfin/model/OAIUserDataChangedMessage.h"
#include "jellyfin/model/OAIUserDeletedMessage.h"
#include "jellyfin/model/OAIUserDto.h"
#include "jellyfin/model/OAIUserItemDataDto.h"
#include "jellyfin/model/OAIUserPolicy.h"
#include "jellyfin/model/OAIUserUpdatedMessage.h"
#include "jellyfin/model/OAIUtcTimeResponse.h"
#include "jellyfin/model/OAIValidatePathDto.h"
#include "jellyfin/model/OAIVersionInfo.h"
#include "jellyfin/model/OAIVideo3DFormat.h"
#include "jellyfin/model/OAIVideoRange.h"
#include "jellyfin/model/OAIVideoRangeType.h"
#include "jellyfin/model/OAIVideoType.h"
#include "jellyfin/model/OAIVirtualFolderInfo.h"
#include "jellyfin/model/OAIWakeOnLanInfo.h"
#include "jellyfin/model/OAIWebSocketMessage.h"
#include "jellyfin/model/OAIXbmcMetadataOptions.h"
#include "json_helper/helper.inl"

using namespace std::literals::string_view_literals;

namespace jellyfin::model {




void to_json(json_t& j, const OAIAccessSchedule& o) {
        j["Id"sv] = o.Id;
        j["UserId"sv] = o.UserId;
        j["DayOfWeek"sv] = o.DayOfWeek;
        j["StartHour"sv] = o.StartHour;
        j["EndHour"sv] = o.EndHour;
}
void from_json(const json_t& j, OAIAccessSchedule& o) {
    
    j.at("Id"sv).get_to(o.Id);
    
    j.at("UserId"sv).get_to(o.UserId);
    
    j.at("DayOfWeek"sv).get_to(o.DayOfWeek);
    
    j.at("StartHour"sv).get_to(o.StartHour);
    
    j.at("EndHour"sv).get_to(o.EndHour);
}




void to_json(json_t& j, const OAIActivityLogEntry& o) {
        j["Id"sv] = o.Id;
        j["Name"sv] = o.Name;
        j["Overview"sv] = o.Overview;
        j["ShortOverview"sv] = o.ShortOverview;
        j["Type"sv] = o.Type;
        j["ItemId"sv] = o.ItemId;
        j["Date"sv] = o.Date;
        j["UserId"sv] = o.UserId;
        j["UserPrimaryImageTag"sv] = o.UserPrimaryImageTag;
        j["Severity"sv] = o.Severity;
}
void from_json(const json_t& j, OAIActivityLogEntry& o) {
    
    j.at("Id"sv).get_to(o.Id);
    
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Overview"sv))
    j.at("Overview"sv).get_to(o.Overview);
    if(j.contains("ShortOverview"sv))
    j.at("ShortOverview"sv).get_to(o.ShortOverview);
    
    j.at("Type"sv).get_to(o.Type);
    if(j.contains("ItemId"sv))
    j.at("ItemId"sv).get_to(o.ItemId);
    
    j.at("Date"sv).get_to(o.Date);
    
    j.at("UserId"sv).get_to(o.UserId);
    if(j.contains("UserPrimaryImageTag"sv))
    j.at("UserPrimaryImageTag"sv).get_to(o.UserPrimaryImageTag);
    
    j.at("Severity"sv).get_to(o.Severity);
}




void to_json(json_t& j, const OAIActivityLogEntryMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIActivityLogEntryMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAIActivityLogEntryQueryResult& o) {
        j["Items"sv] = o.Items;
        j["TotalRecordCount"sv] = o.TotalRecordCount;
        j["StartIndex"sv] = o.StartIndex;
}
void from_json(const json_t& j, OAIActivityLogEntryQueryResult& o) {
    if(j.contains("Items"sv))
    j.at("Items"sv).get_to(o.Items);
    
    j.at("TotalRecordCount"sv).get_to(o.TotalRecordCount);
    
    j.at("StartIndex"sv).get_to(o.StartIndex);
}




void to_json(json_t& j, const OAIActivityLogEntryStartMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIActivityLogEntryStartMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAIActivityLogEntryStopMessage& o) {
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIActivityLogEntryStopMessage& o) {
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAIAddVirtualFolderDto& o) {
        j["LibraryOptions"sv] = o.LibraryOptions;
}
void from_json(const json_t& j, OAIAddVirtualFolderDto& o) {
    if(j.contains("LibraryOptions"sv))
    j.at("LibraryOptions"sv).get_to(o.LibraryOptions);
}




void to_json(json_t& j, const OAIAlbumInfo& o) {
        j["Name"sv] = o.Name;
        j["OriginalTitle"sv] = o.OriginalTitle;
        j["Path"sv] = o.Path;
        j["MetadataLanguage"sv] = o.MetadataLanguage;
        j["MetadataCountryCode"sv] = o.MetadataCountryCode;
        j["ProviderIds"sv] = o.ProviderIds;
        j["Year"sv] = o.Year;
        j["IndexNumber"sv] = o.IndexNumber;
        j["ParentIndexNumber"sv] = o.ParentIndexNumber;
        j["PremiereDate"sv] = o.PremiereDate;
        j["IsAutomated"sv] = o.IsAutomated;
        j["AlbumArtists"sv] = o.AlbumArtists;
        j["ArtistProviderIds"sv] = o.ArtistProviderIds;
        j["SongInfos"sv] = o.SongInfos;
}
void from_json(const json_t& j, OAIAlbumInfo& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("OriginalTitle"sv))
    j.at("OriginalTitle"sv).get_to(o.OriginalTitle);
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("MetadataLanguage"sv))
    j.at("MetadataLanguage"sv).get_to(o.MetadataLanguage);
    if(j.contains("MetadataCountryCode"sv))
    j.at("MetadataCountryCode"sv).get_to(o.MetadataCountryCode);
    if(j.contains("ProviderIds"sv))
    j.at("ProviderIds"sv).get_to(o.ProviderIds);
    if(j.contains("Year"sv))
    j.at("Year"sv).get_to(o.Year);
    if(j.contains("IndexNumber"sv))
    j.at("IndexNumber"sv).get_to(o.IndexNumber);
    if(j.contains("ParentIndexNumber"sv))
    j.at("ParentIndexNumber"sv).get_to(o.ParentIndexNumber);
    if(j.contains("PremiereDate"sv))
    j.at("PremiereDate"sv).get_to(o.PremiereDate);
    
    j.at("IsAutomated"sv).get_to(o.IsAutomated);
    
    j.at("AlbumArtists"sv).get_to(o.AlbumArtists);
    
    j.at("ArtistProviderIds"sv).get_to(o.ArtistProviderIds);
    
    j.at("SongInfos"sv).get_to(o.SongInfos);
}




void to_json(json_t& j, const OAIAlbumInfoRemoteSearchQuery& o) {
        j["SearchInfo"sv] = o.SearchInfo;
        j["ItemId"sv] = o.ItemId;
        j["SearchProviderName"sv] = o.SearchProviderName;
        j["IncludeDisabledProviders"sv] = o.IncludeDisabledProviders;
}
void from_json(const json_t& j, OAIAlbumInfoRemoteSearchQuery& o) {
    if(j.contains("SearchInfo"sv))
    j.at("SearchInfo"sv).get_to(o.SearchInfo);
    
    j.at("ItemId"sv).get_to(o.ItemId);
    if(j.contains("SearchProviderName"sv))
    j.at("SearchProviderName"sv).get_to(o.SearchProviderName);
    
    j.at("IncludeDisabledProviders"sv).get_to(o.IncludeDisabledProviders);
}




void to_json(json_t& j, const OAIAllThemeMediaResult& o) {
        j["ThemeVideosResult"sv] = o.ThemeVideosResult;
        j["ThemeSongsResult"sv] = o.ThemeSongsResult;
        j["SoundtrackSongsResult"sv] = o.SoundtrackSongsResult;
}
void from_json(const json_t& j, OAIAllThemeMediaResult& o) {
    if(j.contains("ThemeVideosResult"sv))
    j.at("ThemeVideosResult"sv).get_to(o.ThemeVideosResult);
    if(j.contains("ThemeSongsResult"sv))
    j.at("ThemeSongsResult"sv).get_to(o.ThemeSongsResult);
    if(j.contains("SoundtrackSongsResult"sv))
    j.at("SoundtrackSongsResult"sv).get_to(o.SoundtrackSongsResult);
}




void to_json(json_t& j, const OAIArtistInfo& o) {
        j["Name"sv] = o.Name;
        j["OriginalTitle"sv] = o.OriginalTitle;
        j["Path"sv] = o.Path;
        j["MetadataLanguage"sv] = o.MetadataLanguage;
        j["MetadataCountryCode"sv] = o.MetadataCountryCode;
        j["ProviderIds"sv] = o.ProviderIds;
        j["Year"sv] = o.Year;
        j["IndexNumber"sv] = o.IndexNumber;
        j["ParentIndexNumber"sv] = o.ParentIndexNumber;
        j["PremiereDate"sv] = o.PremiereDate;
        j["IsAutomated"sv] = o.IsAutomated;
        j["SongInfos"sv] = o.SongInfos;
}
void from_json(const json_t& j, OAIArtistInfo& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("OriginalTitle"sv))
    j.at("OriginalTitle"sv).get_to(o.OriginalTitle);
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("MetadataLanguage"sv))
    j.at("MetadataLanguage"sv).get_to(o.MetadataLanguage);
    if(j.contains("MetadataCountryCode"sv))
    j.at("MetadataCountryCode"sv).get_to(o.MetadataCountryCode);
    if(j.contains("ProviderIds"sv))
    j.at("ProviderIds"sv).get_to(o.ProviderIds);
    if(j.contains("Year"sv))
    j.at("Year"sv).get_to(o.Year);
    if(j.contains("IndexNumber"sv))
    j.at("IndexNumber"sv).get_to(o.IndexNumber);
    if(j.contains("ParentIndexNumber"sv))
    j.at("ParentIndexNumber"sv).get_to(o.ParentIndexNumber);
    if(j.contains("PremiereDate"sv))
    j.at("PremiereDate"sv).get_to(o.PremiereDate);
    
    j.at("IsAutomated"sv).get_to(o.IsAutomated);
    
    j.at("SongInfos"sv).get_to(o.SongInfos);
}




void to_json(json_t& j, const OAIArtistInfoRemoteSearchQuery& o) {
        j["SearchInfo"sv] = o.SearchInfo;
        j["ItemId"sv] = o.ItemId;
        j["SearchProviderName"sv] = o.SearchProviderName;
        j["IncludeDisabledProviders"sv] = o.IncludeDisabledProviders;
}
void from_json(const json_t& j, OAIArtistInfoRemoteSearchQuery& o) {
    if(j.contains("SearchInfo"sv))
    j.at("SearchInfo"sv).get_to(o.SearchInfo);
    
    j.at("ItemId"sv).get_to(o.ItemId);
    if(j.contains("SearchProviderName"sv))
    j.at("SearchProviderName"sv).get_to(o.SearchProviderName);
    
    j.at("IncludeDisabledProviders"sv).get_to(o.IncludeDisabledProviders);
}



void to_json(json_t& j, const OAIAudioSpatialFormat& e) {
    switch (e)
    {
    
        case OAIAudioSpatialFormat::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIAudioSpatialFormat::NONE:
            j = "None";
            break;
    
        case OAIAudioSpatialFormat::DOLBYATMOS:
            j = "DolbyAtmos";
            break;
    
        case OAIAudioSpatialFormat::DTSX:
            j = "DTSX";
            break;
    
    }
}
void from_json(const json_t& j, OAIAudioSpatialFormat& e) {
    auto s = j.get<std::string>();
    
    if (s == "None"sv) {
        e = (OAIAudioSpatialFormat::NONE);
    } 
    
    else if (s == "DolbyAtmos"sv) {
        e = (OAIAudioSpatialFormat::DOLBYATMOS);
    } 
    
    else if (s == "DTSX"sv) {
        e = (OAIAudioSpatialFormat::DTSX);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIAudioSpatialFormat";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIAuthenticateUserByName& o) {
        j["Username"sv] = o.Username;
        j["Pw"sv] = o.Pw;
}
void from_json(const json_t& j, OAIAuthenticateUserByName& o) {
    if(j.contains("Username"sv))
    j.at("Username"sv).get_to(o.Username);
    if(j.contains("Pw"sv))
    j.at("Pw"sv).get_to(o.Pw);
}




void to_json(json_t& j, const OAIAuthenticationInfo& o) {
        j["Id"sv] = o.Id;
        j["AccessToken"sv] = o.AccessToken;
        j["DeviceId"sv] = o.DeviceId;
        j["AppName"sv] = o.AppName;
        j["AppVersion"sv] = o.AppVersion;
        j["DeviceName"sv] = o.DeviceName;
        j["UserId"sv] = o.UserId;
        j["IsActive"sv] = o.IsActive;
        j["DateCreated"sv] = o.DateCreated;
        j["DateRevoked"sv] = o.DateRevoked;
        j["DateLastActivity"sv] = o.DateLastActivity;
        j["UserName"sv] = o.UserName;
}
void from_json(const json_t& j, OAIAuthenticationInfo& o) {
    
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("AccessToken"sv))
    j.at("AccessToken"sv).get_to(o.AccessToken);
    if(j.contains("DeviceId"sv))
    j.at("DeviceId"sv).get_to(o.DeviceId);
    if(j.contains("AppName"sv))
    j.at("AppName"sv).get_to(o.AppName);
    if(j.contains("AppVersion"sv))
    j.at("AppVersion"sv).get_to(o.AppVersion);
    if(j.contains("DeviceName"sv))
    j.at("DeviceName"sv).get_to(o.DeviceName);
    
    j.at("UserId"sv).get_to(o.UserId);
    
    j.at("IsActive"sv).get_to(o.IsActive);
    
    j.at("DateCreated"sv).get_to(o.DateCreated);
    if(j.contains("DateRevoked"sv))
    j.at("DateRevoked"sv).get_to(o.DateRevoked);
    
    j.at("DateLastActivity"sv).get_to(o.DateLastActivity);
    if(j.contains("UserName"sv))
    j.at("UserName"sv).get_to(o.UserName);
}




void to_json(json_t& j, const OAIAuthenticationInfoQueryResult& o) {
        j["Items"sv] = o.Items;
        j["TotalRecordCount"sv] = o.TotalRecordCount;
        j["StartIndex"sv] = o.StartIndex;
}
void from_json(const json_t& j, OAIAuthenticationInfoQueryResult& o) {
    if(j.contains("Items"sv))
    j.at("Items"sv).get_to(o.Items);
    
    j.at("TotalRecordCount"sv).get_to(o.TotalRecordCount);
    
    j.at("StartIndex"sv).get_to(o.StartIndex);
}




void to_json(json_t& j, const OAIAuthenticationResult& o) {
        j["User"sv] = o.User;
        j["SessionInfo"sv] = o.SessionInfo;
        j["AccessToken"sv] = o.AccessToken;
        j["ServerId"sv] = o.ServerId;
}
void from_json(const json_t& j, OAIAuthenticationResult& o) {
    if(j.contains("User"sv))
    j.at("User"sv).get_to(o.User);
    if(j.contains("SessionInfo"sv))
    j.at("SessionInfo"sv).get_to(o.SessionInfo);
    if(j.contains("AccessToken"sv))
    j.at("AccessToken"sv).get_to(o.AccessToken);
    if(j.contains("ServerId"sv))
    j.at("ServerId"sv).get_to(o.ServerId);
}




void to_json(json_t& j, const OAIBaseItemDto& o) {
        j["Name"sv] = o.Name;
        j["OriginalTitle"sv] = o.OriginalTitle;
        j["ServerId"sv] = o.ServerId;
        j["Id"sv] = o.Id;
        j["Etag"sv] = o.Etag;
        j["SourceType"sv] = o.SourceType;
        j["PlaylistItemId"sv] = o.PlaylistItemId;
        j["DateCreated"sv] = o.DateCreated;
        j["DateLastMediaAdded"sv] = o.DateLastMediaAdded;
        j["ExtraType"sv] = o.ExtraType;
        j["AirsBeforeSeasonNumber"sv] = o.AirsBeforeSeasonNumber;
        j["AirsAfterSeasonNumber"sv] = o.AirsAfterSeasonNumber;
        j["AirsBeforeEpisodeNumber"sv] = o.AirsBeforeEpisodeNumber;
        j["CanDelete"sv] = o.CanDelete;
        j["CanDownload"sv] = o.CanDownload;
        j["HasLyrics"sv] = o.HasLyrics;
        j["HasSubtitles"sv] = o.HasSubtitles;
        j["PreferredMetadataLanguage"sv] = o.PreferredMetadataLanguage;
        j["PreferredMetadataCountryCode"sv] = o.PreferredMetadataCountryCode;
        j["Container"sv] = o.Container;
        j["SortName"sv] = o.SortName;
        j["ForcedSortName"sv] = o.ForcedSortName;
        j["Video3DFormat"sv] = o.Video3DFormat;
        j["PremiereDate"sv] = o.PremiereDate;
        j["ExternalUrls"sv] = o.ExternalUrls;
        j["MediaSources"sv] = o.MediaSources;
        j["CriticRating"sv] = o.CriticRating;
        j["ProductionLocations"sv] = o.ProductionLocations;
        j["Path"sv] = o.Path;
        j["EnableMediaSourceDisplay"sv] = o.EnableMediaSourceDisplay;
        j["OfficialRating"sv] = o.OfficialRating;
        j["CustomRating"sv] = o.CustomRating;
        j["ChannelId"sv] = o.ChannelId;
        j["ChannelName"sv] = o.ChannelName;
        j["Overview"sv] = o.Overview;
        j["Taglines"sv] = o.Taglines;
        j["Genres"sv] = o.Genres;
        j["CommunityRating"sv] = o.CommunityRating;
        j["CumulativeRunTimeTicks"sv] = o.CumulativeRunTimeTicks;
        j["RunTimeTicks"sv] = o.RunTimeTicks;
        j["PlayAccess"sv] = o.PlayAccess;
        j["AspectRatio"sv] = o.AspectRatio;
        j["ProductionYear"sv] = o.ProductionYear;
        j["IsPlaceHolder"sv] = o.IsPlaceHolder;
        j["Number"sv] = o.Number;
        j["ChannelNumber"sv] = o.ChannelNumber;
        j["IndexNumber"sv] = o.IndexNumber;
        j["IndexNumberEnd"sv] = o.IndexNumberEnd;
        j["ParentIndexNumber"sv] = o.ParentIndexNumber;
        j["RemoteTrailers"sv] = o.RemoteTrailers;
        j["ProviderIds"sv] = o.ProviderIds;
        j["IsHD"sv] = o.IsHD;
        j["IsFolder"sv] = o.IsFolder;
        j["ParentId"sv] = o.ParentId;
        j["Type"sv] = o.Type;
        j["People"sv] = o.People;
        j["Studios"sv] = o.Studios;
        j["GenreItems"sv] = o.GenreItems;
        j["ParentLogoItemId"sv] = o.ParentLogoItemId;
        j["ParentBackdropItemId"sv] = o.ParentBackdropItemId;
        j["ParentBackdropImageTags"sv] = o.ParentBackdropImageTags;
        j["LocalTrailerCount"sv] = o.LocalTrailerCount;
        j["UserData"sv] = o.UserData;
        j["RecursiveItemCount"sv] = o.RecursiveItemCount;
        j["ChildCount"sv] = o.ChildCount;
        j["SeriesName"sv] = o.SeriesName;
        j["SeriesId"sv] = o.SeriesId;
        j["SeasonId"sv] = o.SeasonId;
        j["SpecialFeatureCount"sv] = o.SpecialFeatureCount;
        j["DisplayPreferencesId"sv] = o.DisplayPreferencesId;
        j["Status"sv] = o.Status;
        j["AirTime"sv] = o.AirTime;
        j["AirDays"sv] = o.AirDays;
        j["Tags"sv] = o.Tags;
        j["PrimaryImageAspectRatio"sv] = o.PrimaryImageAspectRatio;
        j["Artists"sv] = o.Artists;
        j["ArtistItems"sv] = o.ArtistItems;
        j["Album"sv] = o.Album;
        j["CollectionType"sv] = o.CollectionType;
        j["DisplayOrder"sv] = o.DisplayOrder;
        j["AlbumId"sv] = o.AlbumId;
        j["AlbumPrimaryImageTag"sv] = o.AlbumPrimaryImageTag;
        j["SeriesPrimaryImageTag"sv] = o.SeriesPrimaryImageTag;
        j["AlbumArtist"sv] = o.AlbumArtist;
        j["AlbumArtists"sv] = o.AlbumArtists;
        j["SeasonName"sv] = o.SeasonName;
        j["MediaStreams"sv] = o.MediaStreams;
        j["VideoType"sv] = o.VideoType;
        j["PartCount"sv] = o.PartCount;
        j["MediaSourceCount"sv] = o.MediaSourceCount;
        j["ImageTags"sv] = o.ImageTags;
        j["BackdropImageTags"sv] = o.BackdropImageTags;
        j["ScreenshotImageTags"sv] = o.ScreenshotImageTags;
        j["ParentLogoImageTag"sv] = o.ParentLogoImageTag;
        j["ParentArtItemId"sv] = o.ParentArtItemId;
        j["ParentArtImageTag"sv] = o.ParentArtImageTag;
        j["SeriesThumbImageTag"sv] = o.SeriesThumbImageTag;
        j["ImageBlurHashes"sv] = o.ImageBlurHashes;
        j["SeriesStudio"sv] = o.SeriesStudio;
        j["ParentThumbItemId"sv] = o.ParentThumbItemId;
        j["ParentThumbImageTag"sv] = o.ParentThumbImageTag;
        j["ParentPrimaryImageItemId"sv] = o.ParentPrimaryImageItemId;
        j["ParentPrimaryImageTag"sv] = o.ParentPrimaryImageTag;
        j["Chapters"sv] = o.Chapters;
        j["Trickplay"sv] = o.Trickplay;
        j["LocationType"sv] = o.LocationType;
        j["IsoType"sv] = o.IsoType;
        j["MediaType"sv] = o.MediaType;
        j["EndDate"sv] = o.EndDate;
        j["LockedFields"sv] = o.LockedFields;
        j["TrailerCount"sv] = o.TrailerCount;
        j["MovieCount"sv] = o.MovieCount;
        j["SeriesCount"sv] = o.SeriesCount;
        j["ProgramCount"sv] = o.ProgramCount;
        j["EpisodeCount"sv] = o.EpisodeCount;
        j["SongCount"sv] = o.SongCount;
        j["AlbumCount"sv] = o.AlbumCount;
        j["ArtistCount"sv] = o.ArtistCount;
        j["MusicVideoCount"sv] = o.MusicVideoCount;
        j["LockData"sv] = o.LockData;
        j["Width"sv] = o.Width;
        j["Height"sv] = o.Height;
        j["CameraMake"sv] = o.CameraMake;
        j["CameraModel"sv] = o.CameraModel;
        j["Software"sv] = o.Software;
        j["ExposureTime"sv] = o.ExposureTime;
        j["FocalLength"sv] = o.FocalLength;
        j["ImageOrientation"sv] = o.ImageOrientation;
        j["Aperture"sv] = o.Aperture;
        j["ShutterSpeed"sv] = o.ShutterSpeed;
        j["Latitude"sv] = o.Latitude;
        j["Longitude"sv] = o.Longitude;
        j["Altitude"sv] = o.Altitude;
        j["IsoSpeedRating"sv] = o.IsoSpeedRating;
        j["SeriesTimerId"sv] = o.SeriesTimerId;
        j["ProgramId"sv] = o.ProgramId;
        j["ChannelPrimaryImageTag"sv] = o.ChannelPrimaryImageTag;
        j["StartDate"sv] = o.StartDate;
        j["CompletionPercentage"sv] = o.CompletionPercentage;
        j["IsRepeat"sv] = o.IsRepeat;
        j["EpisodeTitle"sv] = o.EpisodeTitle;
        j["ChannelType"sv] = o.ChannelType;
        j["Audio"sv] = o.Audio;
        j["IsMovie"sv] = o.IsMovie;
        j["IsSports"sv] = o.IsSports;
        j["IsSeries"sv] = o.IsSeries;
        j["IsLive"sv] = o.IsLive;
        j["IsNews"sv] = o.IsNews;
        j["IsKids"sv] = o.IsKids;
        j["IsPremiere"sv] = o.IsPremiere;
        j["TimerId"sv] = o.TimerId;
        j["NormalizationGain"sv] = o.NormalizationGain;
        j["CurrentProgram"sv] = o.CurrentProgram;
}
void from_json(const json_t& j, OAIBaseItemDto& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("OriginalTitle"sv))
    j.at("OriginalTitle"sv).get_to(o.OriginalTitle);
    if(j.contains("ServerId"sv))
    j.at("ServerId"sv).get_to(o.ServerId);
    
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("Etag"sv))
    j.at("Etag"sv).get_to(o.Etag);
    if(j.contains("SourceType"sv))
    j.at("SourceType"sv).get_to(o.SourceType);
    if(j.contains("PlaylistItemId"sv))
    j.at("PlaylistItemId"sv).get_to(o.PlaylistItemId);
    if(j.contains("DateCreated"sv))
    j.at("DateCreated"sv).get_to(o.DateCreated);
    if(j.contains("DateLastMediaAdded"sv))
    j.at("DateLastMediaAdded"sv).get_to(o.DateLastMediaAdded);
    if(j.contains("ExtraType"sv))
    j.at("ExtraType"sv).get_to(o.ExtraType);
    if(j.contains("AirsBeforeSeasonNumber"sv))
    j.at("AirsBeforeSeasonNumber"sv).get_to(o.AirsBeforeSeasonNumber);
    if(j.contains("AirsAfterSeasonNumber"sv))
    j.at("AirsAfterSeasonNumber"sv).get_to(o.AirsAfterSeasonNumber);
    if(j.contains("AirsBeforeEpisodeNumber"sv))
    j.at("AirsBeforeEpisodeNumber"sv).get_to(o.AirsBeforeEpisodeNumber);
    if(j.contains("CanDelete"sv))
    j.at("CanDelete"sv).get_to(o.CanDelete);
    if(j.contains("CanDownload"sv))
    j.at("CanDownload"sv).get_to(o.CanDownload);
    if(j.contains("HasLyrics"sv))
    j.at("HasLyrics"sv).get_to(o.HasLyrics);
    if(j.contains("HasSubtitles"sv))
    j.at("HasSubtitles"sv).get_to(o.HasSubtitles);
    if(j.contains("PreferredMetadataLanguage"sv))
    j.at("PreferredMetadataLanguage"sv).get_to(o.PreferredMetadataLanguage);
    if(j.contains("PreferredMetadataCountryCode"sv))
    j.at("PreferredMetadataCountryCode"sv).get_to(o.PreferredMetadataCountryCode);
    if(j.contains("Container"sv))
    j.at("Container"sv).get_to(o.Container);
    if(j.contains("SortName"sv))
    j.at("SortName"sv).get_to(o.SortName);
    if(j.contains("ForcedSortName"sv))
    j.at("ForcedSortName"sv).get_to(o.ForcedSortName);
    if(j.contains("Video3DFormat"sv))
    j.at("Video3DFormat"sv).get_to(o.Video3DFormat);
    if(j.contains("PremiereDate"sv))
    j.at("PremiereDate"sv).get_to(o.PremiereDate);
    if(j.contains("ExternalUrls"sv))
    j.at("ExternalUrls"sv).get_to(o.ExternalUrls);
    if(j.contains("MediaSources"sv))
    j.at("MediaSources"sv).get_to(o.MediaSources);
    if(j.contains("CriticRating"sv))
    j.at("CriticRating"sv).get_to(o.CriticRating);
    if(j.contains("ProductionLocations"sv))
    j.at("ProductionLocations"sv).get_to(o.ProductionLocations);
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("EnableMediaSourceDisplay"sv))
    j.at("EnableMediaSourceDisplay"sv).get_to(o.EnableMediaSourceDisplay);
    if(j.contains("OfficialRating"sv))
    j.at("OfficialRating"sv).get_to(o.OfficialRating);
    if(j.contains("CustomRating"sv))
    j.at("CustomRating"sv).get_to(o.CustomRating);
    if(j.contains("ChannelId"sv))
    j.at("ChannelId"sv).get_to(o.ChannelId);
    if(j.contains("ChannelName"sv))
    j.at("ChannelName"sv).get_to(o.ChannelName);
    if(j.contains("Overview"sv))
    j.at("Overview"sv).get_to(o.Overview);
    if(j.contains("Taglines"sv))
    j.at("Taglines"sv).get_to(o.Taglines);
    if(j.contains("Genres"sv))
    j.at("Genres"sv).get_to(o.Genres);
    if(j.contains("CommunityRating"sv))
    j.at("CommunityRating"sv).get_to(o.CommunityRating);
    if(j.contains("CumulativeRunTimeTicks"sv))
    j.at("CumulativeRunTimeTicks"sv).get_to(o.CumulativeRunTimeTicks);
    if(j.contains("RunTimeTicks"sv))
    j.at("RunTimeTicks"sv).get_to(o.RunTimeTicks);
    if(j.contains("PlayAccess"sv))
    j.at("PlayAccess"sv).get_to(o.PlayAccess);
    if(j.contains("AspectRatio"sv))
    j.at("AspectRatio"sv).get_to(o.AspectRatio);
    if(j.contains("ProductionYear"sv))
    j.at("ProductionYear"sv).get_to(o.ProductionYear);
    if(j.contains("IsPlaceHolder"sv))
    j.at("IsPlaceHolder"sv).get_to(o.IsPlaceHolder);
    if(j.contains("Number"sv))
    j.at("Number"sv).get_to(o.Number);
    if(j.contains("ChannelNumber"sv))
    j.at("ChannelNumber"sv).get_to(o.ChannelNumber);
    if(j.contains("IndexNumber"sv))
    j.at("IndexNumber"sv).get_to(o.IndexNumber);
    if(j.contains("IndexNumberEnd"sv))
    j.at("IndexNumberEnd"sv).get_to(o.IndexNumberEnd);
    if(j.contains("ParentIndexNumber"sv))
    j.at("ParentIndexNumber"sv).get_to(o.ParentIndexNumber);
    if(j.contains("RemoteTrailers"sv))
    j.at("RemoteTrailers"sv).get_to(o.RemoteTrailers);
    if(j.contains("ProviderIds"sv))
    j.at("ProviderIds"sv).get_to(o.ProviderIds);
    if(j.contains("IsHD"sv))
    j.at("IsHD"sv).get_to(o.IsHD);
    if(j.contains("IsFolder"sv))
    j.at("IsFolder"sv).get_to(o.IsFolder);
    if(j.contains("ParentId"sv))
    j.at("ParentId"sv).get_to(o.ParentId);
    
    j.at("Type"sv).get_to(o.Type);
    if(j.contains("People"sv))
    j.at("People"sv).get_to(o.People);
    if(j.contains("Studios"sv))
    j.at("Studios"sv).get_to(o.Studios);
    if(j.contains("GenreItems"sv))
    j.at("GenreItems"sv).get_to(o.GenreItems);
    if(j.contains("ParentLogoItemId"sv))
    j.at("ParentLogoItemId"sv).get_to(o.ParentLogoItemId);
    if(j.contains("ParentBackdropItemId"sv))
    j.at("ParentBackdropItemId"sv).get_to(o.ParentBackdropItemId);
    if(j.contains("ParentBackdropImageTags"sv))
    j.at("ParentBackdropImageTags"sv).get_to(o.ParentBackdropImageTags);
    if(j.contains("LocalTrailerCount"sv))
    j.at("LocalTrailerCount"sv).get_to(o.LocalTrailerCount);
    if(j.contains("UserData"sv))
    j.at("UserData"sv).get_to(o.UserData);
    if(j.contains("RecursiveItemCount"sv))
    j.at("RecursiveItemCount"sv).get_to(o.RecursiveItemCount);
    if(j.contains("ChildCount"sv))
    j.at("ChildCount"sv).get_to(o.ChildCount);
    if(j.contains("SeriesName"sv))
    j.at("SeriesName"sv).get_to(o.SeriesName);
    if(j.contains("SeriesId"sv))
    j.at("SeriesId"sv).get_to(o.SeriesId);
    if(j.contains("SeasonId"sv))
    j.at("SeasonId"sv).get_to(o.SeasonId);
    if(j.contains("SpecialFeatureCount"sv))
    j.at("SpecialFeatureCount"sv).get_to(o.SpecialFeatureCount);
    if(j.contains("DisplayPreferencesId"sv))
    j.at("DisplayPreferencesId"sv).get_to(o.DisplayPreferencesId);
    if(j.contains("Status"sv))
    j.at("Status"sv).get_to(o.Status);
    if(j.contains("AirTime"sv))
    j.at("AirTime"sv).get_to(o.AirTime);
    if(j.contains("AirDays"sv))
    j.at("AirDays"sv).get_to(o.AirDays);
    if(j.contains("Tags"sv))
    j.at("Tags"sv).get_to(o.Tags);
    if(j.contains("PrimaryImageAspectRatio"sv))
    j.at("PrimaryImageAspectRatio"sv).get_to(o.PrimaryImageAspectRatio);
    if(j.contains("Artists"sv))
    j.at("Artists"sv).get_to(o.Artists);
    if(j.contains("ArtistItems"sv))
    j.at("ArtistItems"sv).get_to(o.ArtistItems);
    if(j.contains("Album"sv))
    j.at("Album"sv).get_to(o.Album);
    if(j.contains("CollectionType"sv))
    j.at("CollectionType"sv).get_to(o.CollectionType);
    if(j.contains("DisplayOrder"sv))
    j.at("DisplayOrder"sv).get_to(o.DisplayOrder);
    if(j.contains("AlbumId"sv))
    j.at("AlbumId"sv).get_to(o.AlbumId);
    if(j.contains("AlbumPrimaryImageTag"sv))
    j.at("AlbumPrimaryImageTag"sv).get_to(o.AlbumPrimaryImageTag);
    if(j.contains("SeriesPrimaryImageTag"sv))
    j.at("SeriesPrimaryImageTag"sv).get_to(o.SeriesPrimaryImageTag);
    if(j.contains("AlbumArtist"sv))
    j.at("AlbumArtist"sv).get_to(o.AlbumArtist);
    if(j.contains("AlbumArtists"sv))
    j.at("AlbumArtists"sv).get_to(o.AlbumArtists);
    if(j.contains("SeasonName"sv))
    j.at("SeasonName"sv).get_to(o.SeasonName);
    if(j.contains("MediaStreams"sv))
    j.at("MediaStreams"sv).get_to(o.MediaStreams);
    if(j.contains("VideoType"sv))
    j.at("VideoType"sv).get_to(o.VideoType);
    if(j.contains("PartCount"sv))
    j.at("PartCount"sv).get_to(o.PartCount);
    if(j.contains("MediaSourceCount"sv))
    j.at("MediaSourceCount"sv).get_to(o.MediaSourceCount);
    if(j.contains("ImageTags"sv))
    j.at("ImageTags"sv).get_to(o.ImageTags);
    if(j.contains("BackdropImageTags"sv))
    j.at("BackdropImageTags"sv).get_to(o.BackdropImageTags);
    if(j.contains("ScreenshotImageTags"sv))
    j.at("ScreenshotImageTags"sv).get_to(o.ScreenshotImageTags);
    if(j.contains("ParentLogoImageTag"sv))
    j.at("ParentLogoImageTag"sv).get_to(o.ParentLogoImageTag);
    if(j.contains("ParentArtItemId"sv))
    j.at("ParentArtItemId"sv).get_to(o.ParentArtItemId);
    if(j.contains("ParentArtImageTag"sv))
    j.at("ParentArtImageTag"sv).get_to(o.ParentArtImageTag);
    if(j.contains("SeriesThumbImageTag"sv))
    j.at("SeriesThumbImageTag"sv).get_to(o.SeriesThumbImageTag);
    if(j.contains("ImageBlurHashes"sv))
    j.at("ImageBlurHashes"sv).get_to(o.ImageBlurHashes);
    if(j.contains("SeriesStudio"sv))
    j.at("SeriesStudio"sv).get_to(o.SeriesStudio);
    if(j.contains("ParentThumbItemId"sv))
    j.at("ParentThumbItemId"sv).get_to(o.ParentThumbItemId);
    if(j.contains("ParentThumbImageTag"sv))
    j.at("ParentThumbImageTag"sv).get_to(o.ParentThumbImageTag);
    if(j.contains("ParentPrimaryImageItemId"sv))
    j.at("ParentPrimaryImageItemId"sv).get_to(o.ParentPrimaryImageItemId);
    if(j.contains("ParentPrimaryImageTag"sv))
    j.at("ParentPrimaryImageTag"sv).get_to(o.ParentPrimaryImageTag);
    if(j.contains("Chapters"sv))
    j.at("Chapters"sv).get_to(o.Chapters);
    if(j.contains("Trickplay"sv))
    j.at("Trickplay"sv).get_to(o.Trickplay);
    if(j.contains("LocationType"sv))
    j.at("LocationType"sv).get_to(o.LocationType);
    if(j.contains("IsoType"sv))
    j.at("IsoType"sv).get_to(o.IsoType);
    
    j.at("MediaType"sv).get_to(o.MediaType);
    if(j.contains("EndDate"sv))
    j.at("EndDate"sv).get_to(o.EndDate);
    if(j.contains("LockedFields"sv))
    j.at("LockedFields"sv).get_to(o.LockedFields);
    if(j.contains("TrailerCount"sv))
    j.at("TrailerCount"sv).get_to(o.TrailerCount);
    if(j.contains("MovieCount"sv))
    j.at("MovieCount"sv).get_to(o.MovieCount);
    if(j.contains("SeriesCount"sv))
    j.at("SeriesCount"sv).get_to(o.SeriesCount);
    if(j.contains("ProgramCount"sv))
    j.at("ProgramCount"sv).get_to(o.ProgramCount);
    if(j.contains("EpisodeCount"sv))
    j.at("EpisodeCount"sv).get_to(o.EpisodeCount);
    if(j.contains("SongCount"sv))
    j.at("SongCount"sv).get_to(o.SongCount);
    if(j.contains("AlbumCount"sv))
    j.at("AlbumCount"sv).get_to(o.AlbumCount);
    if(j.contains("ArtistCount"sv))
    j.at("ArtistCount"sv).get_to(o.ArtistCount);
    if(j.contains("MusicVideoCount"sv))
    j.at("MusicVideoCount"sv).get_to(o.MusicVideoCount);
    if(j.contains("LockData"sv))
    j.at("LockData"sv).get_to(o.LockData);
    if(j.contains("Width"sv))
    j.at("Width"sv).get_to(o.Width);
    if(j.contains("Height"sv))
    j.at("Height"sv).get_to(o.Height);
    if(j.contains("CameraMake"sv))
    j.at("CameraMake"sv).get_to(o.CameraMake);
    if(j.contains("CameraModel"sv))
    j.at("CameraModel"sv).get_to(o.CameraModel);
    if(j.contains("Software"sv))
    j.at("Software"sv).get_to(o.Software);
    if(j.contains("ExposureTime"sv))
    j.at("ExposureTime"sv).get_to(o.ExposureTime);
    if(j.contains("FocalLength"sv))
    j.at("FocalLength"sv).get_to(o.FocalLength);
    if(j.contains("ImageOrientation"sv))
    j.at("ImageOrientation"sv).get_to(o.ImageOrientation);
    if(j.contains("Aperture"sv))
    j.at("Aperture"sv).get_to(o.Aperture);
    if(j.contains("ShutterSpeed"sv))
    j.at("ShutterSpeed"sv).get_to(o.ShutterSpeed);
    if(j.contains("Latitude"sv))
    j.at("Latitude"sv).get_to(o.Latitude);
    if(j.contains("Longitude"sv))
    j.at("Longitude"sv).get_to(o.Longitude);
    if(j.contains("Altitude"sv))
    j.at("Altitude"sv).get_to(o.Altitude);
    if(j.contains("IsoSpeedRating"sv))
    j.at("IsoSpeedRating"sv).get_to(o.IsoSpeedRating);
    if(j.contains("SeriesTimerId"sv))
    j.at("SeriesTimerId"sv).get_to(o.SeriesTimerId);
    if(j.contains("ProgramId"sv))
    j.at("ProgramId"sv).get_to(o.ProgramId);
    if(j.contains("ChannelPrimaryImageTag"sv))
    j.at("ChannelPrimaryImageTag"sv).get_to(o.ChannelPrimaryImageTag);
    if(j.contains("StartDate"sv))
    j.at("StartDate"sv).get_to(o.StartDate);
    if(j.contains("CompletionPercentage"sv))
    j.at("CompletionPercentage"sv).get_to(o.CompletionPercentage);
    if(j.contains("IsRepeat"sv))
    j.at("IsRepeat"sv).get_to(o.IsRepeat);
    if(j.contains("EpisodeTitle"sv))
    j.at("EpisodeTitle"sv).get_to(o.EpisodeTitle);
    if(j.contains("ChannelType"sv))
    j.at("ChannelType"sv).get_to(o.ChannelType);
    if(j.contains("Audio"sv))
    j.at("Audio"sv).get_to(o.Audio);
    if(j.contains("IsMovie"sv))
    j.at("IsMovie"sv).get_to(o.IsMovie);
    if(j.contains("IsSports"sv))
    j.at("IsSports"sv).get_to(o.IsSports);
    if(j.contains("IsSeries"sv))
    j.at("IsSeries"sv).get_to(o.IsSeries);
    if(j.contains("IsLive"sv))
    j.at("IsLive"sv).get_to(o.IsLive);
    if(j.contains("IsNews"sv))
    j.at("IsNews"sv).get_to(o.IsNews);
    if(j.contains("IsKids"sv))
    j.at("IsKids"sv).get_to(o.IsKids);
    if(j.contains("IsPremiere"sv))
    j.at("IsPremiere"sv).get_to(o.IsPremiere);
    if(j.contains("TimerId"sv))
    j.at("TimerId"sv).get_to(o.TimerId);
    if(j.contains("NormalizationGain"sv))
    j.at("NormalizationGain"sv).get_to(o.NormalizationGain);
    if(j.contains("CurrentProgram"sv))
    j.at("CurrentProgram"sv).get_to(o.CurrentProgram);
}




void to_json(json_t& j, const OAIBaseItemDtoImageBlurHashes& o) {
        j["Primary"sv] = o.Primary;
        j["Art"sv] = o.Art;
        j["Backdrop"sv] = o.Backdrop;
        j["Banner"sv] = o.Banner;
        j["Logo"sv] = o.Logo;
        j["Thumb"sv] = o.Thumb;
        j["Disc"sv] = o.Disc;
        j["Box"sv] = o.Box;
        j["Screenshot"sv] = o.Screenshot;
        j["Menu"sv] = o.Menu;
        j["Chapter"sv] = o.Chapter;
        j["BoxRear"sv] = o.BoxRear;
        j["Profile"sv] = o.Profile;
}
void from_json(const json_t& j, OAIBaseItemDtoImageBlurHashes& o) {
    
    j.at("Primary"sv).get_to(o.Primary);
    
    j.at("Art"sv).get_to(o.Art);
    
    j.at("Backdrop"sv).get_to(o.Backdrop);
    
    j.at("Banner"sv).get_to(o.Banner);
    
    j.at("Logo"sv).get_to(o.Logo);
    
    j.at("Thumb"sv).get_to(o.Thumb);
    
    j.at("Disc"sv).get_to(o.Disc);
    
    j.at("Box"sv).get_to(o.Box);
    
    j.at("Screenshot"sv).get_to(o.Screenshot);
    
    j.at("Menu"sv).get_to(o.Menu);
    
    j.at("Chapter"sv).get_to(o.Chapter);
    
    j.at("BoxRear"sv).get_to(o.BoxRear);
    
    j.at("Profile"sv).get_to(o.Profile);
}




void to_json(json_t& j, const OAIBaseItemDtoQueryResult& o) {
        j["Items"sv] = o.Items;
        j["TotalRecordCount"sv] = o.TotalRecordCount;
        j["StartIndex"sv] = o.StartIndex;
}
void from_json(const json_t& j, OAIBaseItemDtoQueryResult& o) {
    if(j.contains("Items"sv))
    j.at("Items"sv).get_to(o.Items);
    
    j.at("TotalRecordCount"sv).get_to(o.TotalRecordCount);
    
    j.at("StartIndex"sv).get_to(o.StartIndex);
}



void to_json(json_t& j, const OAIBaseItemKind& e) {
    switch (e)
    {
    
        case OAIBaseItemKind::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIBaseItemKind::AGGREGATEFOLDER:
            j = "AggregateFolder";
            break;
    
        case OAIBaseItemKind::AUDIO:
            j = "Audio";
            break;
    
        case OAIBaseItemKind::AUDIOBOOK:
            j = "AudioBook";
            break;
    
        case OAIBaseItemKind::BASEPLUGINFOLDER:
            j = "BasePluginFolder";
            break;
    
        case OAIBaseItemKind::BOOK:
            j = "Book";
            break;
    
        case OAIBaseItemKind::BOXSET:
            j = "BoxSet";
            break;
    
        case OAIBaseItemKind::CHANNEL:
            j = "Channel";
            break;
    
        case OAIBaseItemKind::CHANNELFOLDERITEM:
            j = "ChannelFolderItem";
            break;
    
        case OAIBaseItemKind::COLLECTIONFOLDER:
            j = "CollectionFolder";
            break;
    
        case OAIBaseItemKind::EPISODE:
            j = "Episode";
            break;
    
        case OAIBaseItemKind::FOLDER:
            j = "Folder";
            break;
    
        case OAIBaseItemKind::GENRE:
            j = "Genre";
            break;
    
        case OAIBaseItemKind::MANUALPLAYLISTSFOLDER:
            j = "ManualPlaylistsFolder";
            break;
    
        case OAIBaseItemKind::MOVIE:
            j = "Movie";
            break;
    
        case OAIBaseItemKind::LIVETVCHANNEL:
            j = "LiveTvChannel";
            break;
    
        case OAIBaseItemKind::LIVETVPROGRAM:
            j = "LiveTvProgram";
            break;
    
        case OAIBaseItemKind::MUSICALBUM:
            j = "MusicAlbum";
            break;
    
        case OAIBaseItemKind::MUSICARTIST:
            j = "MusicArtist";
            break;
    
        case OAIBaseItemKind::MUSICGENRE:
            j = "MusicGenre";
            break;
    
        case OAIBaseItemKind::MUSICVIDEO:
            j = "MusicVideo";
            break;
    
        case OAIBaseItemKind::PERSON:
            j = "Person";
            break;
    
        case OAIBaseItemKind::PHOTO:
            j = "Photo";
            break;
    
        case OAIBaseItemKind::PHOTOALBUM:
            j = "PhotoAlbum";
            break;
    
        case OAIBaseItemKind::PLAYLIST:
            j = "Playlist";
            break;
    
        case OAIBaseItemKind::PLAYLISTSFOLDER:
            j = "PlaylistsFolder";
            break;
    
        case OAIBaseItemKind::PROGRAM:
            j = "Program";
            break;
    
        case OAIBaseItemKind::RECORDING:
            j = "Recording";
            break;
    
        case OAIBaseItemKind::SEASON:
            j = "Season";
            break;
    
        case OAIBaseItemKind::SERIES:
            j = "Series";
            break;
    
        case OAIBaseItemKind::STUDIO:
            j = "Studio";
            break;
    
        case OAIBaseItemKind::TRAILER:
            j = "Trailer";
            break;
    
        case OAIBaseItemKind::TVCHANNEL:
            j = "TvChannel";
            break;
    
        case OAIBaseItemKind::TVPROGRAM:
            j = "TvProgram";
            break;
    
        case OAIBaseItemKind::USERROOTFOLDER:
            j = "UserRootFolder";
            break;
    
        case OAIBaseItemKind::USERVIEW:
            j = "UserView";
            break;
    
        case OAIBaseItemKind::VIDEO:
            j = "Video";
            break;
    
        case OAIBaseItemKind::YEAR:
            j = "Year";
            break;
    
    }
}
void from_json(const json_t& j, OAIBaseItemKind& e) {
    auto s = j.get<std::string>();
    
    if (s == "AggregateFolder"sv) {
        e = (OAIBaseItemKind::AGGREGATEFOLDER);
    } 
    
    else if (s == "Audio"sv) {
        e = (OAIBaseItemKind::AUDIO);
    } 
    
    else if (s == "AudioBook"sv) {
        e = (OAIBaseItemKind::AUDIOBOOK);
    } 
    
    else if (s == "BasePluginFolder"sv) {
        e = (OAIBaseItemKind::BASEPLUGINFOLDER);
    } 
    
    else if (s == "Book"sv) {
        e = (OAIBaseItemKind::BOOK);
    } 
    
    else if (s == "BoxSet"sv) {
        e = (OAIBaseItemKind::BOXSET);
    } 
    
    else if (s == "Channel"sv) {
        e = (OAIBaseItemKind::CHANNEL);
    } 
    
    else if (s == "ChannelFolderItem"sv) {
        e = (OAIBaseItemKind::CHANNELFOLDERITEM);
    } 
    
    else if (s == "CollectionFolder"sv) {
        e = (OAIBaseItemKind::COLLECTIONFOLDER);
    } 
    
    else if (s == "Episode"sv) {
        e = (OAIBaseItemKind::EPISODE);
    } 
    
    else if (s == "Folder"sv) {
        e = (OAIBaseItemKind::FOLDER);
    } 
    
    else if (s == "Genre"sv) {
        e = (OAIBaseItemKind::GENRE);
    } 
    
    else if (s == "ManualPlaylistsFolder"sv) {
        e = (OAIBaseItemKind::MANUALPLAYLISTSFOLDER);
    } 
    
    else if (s == "Movie"sv) {
        e = (OAIBaseItemKind::MOVIE);
    } 
    
    else if (s == "LiveTvChannel"sv) {
        e = (OAIBaseItemKind::LIVETVCHANNEL);
    } 
    
    else if (s == "LiveTvProgram"sv) {
        e = (OAIBaseItemKind::LIVETVPROGRAM);
    } 
    
    else if (s == "MusicAlbum"sv) {
        e = (OAIBaseItemKind::MUSICALBUM);
    } 
    
    else if (s == "MusicArtist"sv) {
        e = (OAIBaseItemKind::MUSICARTIST);
    } 
    
    else if (s == "MusicGenre"sv) {
        e = (OAIBaseItemKind::MUSICGENRE);
    } 
    
    else if (s == "MusicVideo"sv) {
        e = (OAIBaseItemKind::MUSICVIDEO);
    } 
    
    else if (s == "Person"sv) {
        e = (OAIBaseItemKind::PERSON);
    } 
    
    else if (s == "Photo"sv) {
        e = (OAIBaseItemKind::PHOTO);
    } 
    
    else if (s == "PhotoAlbum"sv) {
        e = (OAIBaseItemKind::PHOTOALBUM);
    } 
    
    else if (s == "Playlist"sv) {
        e = (OAIBaseItemKind::PLAYLIST);
    } 
    
    else if (s == "PlaylistsFolder"sv) {
        e = (OAIBaseItemKind::PLAYLISTSFOLDER);
    } 
    
    else if (s == "Program"sv) {
        e = (OAIBaseItemKind::PROGRAM);
    } 
    
    else if (s == "Recording"sv) {
        e = (OAIBaseItemKind::RECORDING);
    } 
    
    else if (s == "Season"sv) {
        e = (OAIBaseItemKind::SEASON);
    } 
    
    else if (s == "Series"sv) {
        e = (OAIBaseItemKind::SERIES);
    } 
    
    else if (s == "Studio"sv) {
        e = (OAIBaseItemKind::STUDIO);
    } 
    
    else if (s == "Trailer"sv) {
        e = (OAIBaseItemKind::TRAILER);
    } 
    
    else if (s == "TvChannel"sv) {
        e = (OAIBaseItemKind::TVCHANNEL);
    } 
    
    else if (s == "TvProgram"sv) {
        e = (OAIBaseItemKind::TVPROGRAM);
    } 
    
    else if (s == "UserRootFolder"sv) {
        e = (OAIBaseItemKind::USERROOTFOLDER);
    } 
    
    else if (s == "UserView"sv) {
        e = (OAIBaseItemKind::USERVIEW);
    } 
    
    else if (s == "Video"sv) {
        e = (OAIBaseItemKind::VIDEO);
    } 
    
    else if (s == "Year"sv) {
        e = (OAIBaseItemKind::YEAR);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIBaseItemKind";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIBaseItemPerson& o) {
        j["Name"sv] = o.Name;
        j["Id"sv] = o.Id;
        j["Role"sv] = o.Role;
        j["Type"sv] = o.Type;
        j["PrimaryImageTag"sv] = o.PrimaryImageTag;
        j["ImageBlurHashes"sv] = o.ImageBlurHashes;
}
void from_json(const json_t& j, OAIBaseItemPerson& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("Role"sv))
    j.at("Role"sv).get_to(o.Role);
    
    j.at("Type"sv).get_to(o.Type);
    if(j.contains("PrimaryImageTag"sv))
    j.at("PrimaryImageTag"sv).get_to(o.PrimaryImageTag);
    if(j.contains("ImageBlurHashes"sv))
    j.at("ImageBlurHashes"sv).get_to(o.ImageBlurHashes);
}




void to_json(json_t& j, const OAIBaseItemPersonImageBlurHashes& o) {
        j["Primary"sv] = o.Primary;
        j["Art"sv] = o.Art;
        j["Backdrop"sv] = o.Backdrop;
        j["Banner"sv] = o.Banner;
        j["Logo"sv] = o.Logo;
        j["Thumb"sv] = o.Thumb;
        j["Disc"sv] = o.Disc;
        j["Box"sv] = o.Box;
        j["Screenshot"sv] = o.Screenshot;
        j["Menu"sv] = o.Menu;
        j["Chapter"sv] = o.Chapter;
        j["BoxRear"sv] = o.BoxRear;
        j["Profile"sv] = o.Profile;
}
void from_json(const json_t& j, OAIBaseItemPersonImageBlurHashes& o) {
    
    j.at("Primary"sv).get_to(o.Primary);
    
    j.at("Art"sv).get_to(o.Art);
    
    j.at("Backdrop"sv).get_to(o.Backdrop);
    
    j.at("Banner"sv).get_to(o.Banner);
    
    j.at("Logo"sv).get_to(o.Logo);
    
    j.at("Thumb"sv).get_to(o.Thumb);
    
    j.at("Disc"sv).get_to(o.Disc);
    
    j.at("Box"sv).get_to(o.Box);
    
    j.at("Screenshot"sv).get_to(o.Screenshot);
    
    j.at("Menu"sv).get_to(o.Menu);
    
    j.at("Chapter"sv).get_to(o.Chapter);
    
    j.at("BoxRear"sv).get_to(o.BoxRear);
    
    j.at("Profile"sv).get_to(o.Profile);
}




void to_json(json_t& j, const OAIBookInfo& o) {
        j["Name"sv] = o.Name;
        j["OriginalTitle"sv] = o.OriginalTitle;
        j["Path"sv] = o.Path;
        j["MetadataLanguage"sv] = o.MetadataLanguage;
        j["MetadataCountryCode"sv] = o.MetadataCountryCode;
        j["ProviderIds"sv] = o.ProviderIds;
        j["Year"sv] = o.Year;
        j["IndexNumber"sv] = o.IndexNumber;
        j["ParentIndexNumber"sv] = o.ParentIndexNumber;
        j["PremiereDate"sv] = o.PremiereDate;
        j["IsAutomated"sv] = o.IsAutomated;
        j["SeriesName"sv] = o.SeriesName;
}
void from_json(const json_t& j, OAIBookInfo& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("OriginalTitle"sv))
    j.at("OriginalTitle"sv).get_to(o.OriginalTitle);
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("MetadataLanguage"sv))
    j.at("MetadataLanguage"sv).get_to(o.MetadataLanguage);
    if(j.contains("MetadataCountryCode"sv))
    j.at("MetadataCountryCode"sv).get_to(o.MetadataCountryCode);
    if(j.contains("ProviderIds"sv))
    j.at("ProviderIds"sv).get_to(o.ProviderIds);
    if(j.contains("Year"sv))
    j.at("Year"sv).get_to(o.Year);
    if(j.contains("IndexNumber"sv))
    j.at("IndexNumber"sv).get_to(o.IndexNumber);
    if(j.contains("ParentIndexNumber"sv))
    j.at("ParentIndexNumber"sv).get_to(o.ParentIndexNumber);
    if(j.contains("PremiereDate"sv))
    j.at("PremiereDate"sv).get_to(o.PremiereDate);
    
    j.at("IsAutomated"sv).get_to(o.IsAutomated);
    if(j.contains("SeriesName"sv))
    j.at("SeriesName"sv).get_to(o.SeriesName);
}




void to_json(json_t& j, const OAIBookInfoRemoteSearchQuery& o) {
        j["SearchInfo"sv] = o.SearchInfo;
        j["ItemId"sv] = o.ItemId;
        j["SearchProviderName"sv] = o.SearchProviderName;
        j["IncludeDisabledProviders"sv] = o.IncludeDisabledProviders;
}
void from_json(const json_t& j, OAIBookInfoRemoteSearchQuery& o) {
    if(j.contains("SearchInfo"sv))
    j.at("SearchInfo"sv).get_to(o.SearchInfo);
    
    j.at("ItemId"sv).get_to(o.ItemId);
    if(j.contains("SearchProviderName"sv))
    j.at("SearchProviderName"sv).get_to(o.SearchProviderName);
    
    j.at("IncludeDisabledProviders"sv).get_to(o.IncludeDisabledProviders);
}




void to_json(json_t& j, const OAIBoxSetInfo& o) {
        j["Name"sv] = o.Name;
        j["OriginalTitle"sv] = o.OriginalTitle;
        j["Path"sv] = o.Path;
        j["MetadataLanguage"sv] = o.MetadataLanguage;
        j["MetadataCountryCode"sv] = o.MetadataCountryCode;
        j["ProviderIds"sv] = o.ProviderIds;
        j["Year"sv] = o.Year;
        j["IndexNumber"sv] = o.IndexNumber;
        j["ParentIndexNumber"sv] = o.ParentIndexNumber;
        j["PremiereDate"sv] = o.PremiereDate;
        j["IsAutomated"sv] = o.IsAutomated;
}
void from_json(const json_t& j, OAIBoxSetInfo& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("OriginalTitle"sv))
    j.at("OriginalTitle"sv).get_to(o.OriginalTitle);
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("MetadataLanguage"sv))
    j.at("MetadataLanguage"sv).get_to(o.MetadataLanguage);
    if(j.contains("MetadataCountryCode"sv))
    j.at("MetadataCountryCode"sv).get_to(o.MetadataCountryCode);
    if(j.contains("ProviderIds"sv))
    j.at("ProviderIds"sv).get_to(o.ProviderIds);
    if(j.contains("Year"sv))
    j.at("Year"sv).get_to(o.Year);
    if(j.contains("IndexNumber"sv))
    j.at("IndexNumber"sv).get_to(o.IndexNumber);
    if(j.contains("ParentIndexNumber"sv))
    j.at("ParentIndexNumber"sv).get_to(o.ParentIndexNumber);
    if(j.contains("PremiereDate"sv))
    j.at("PremiereDate"sv).get_to(o.PremiereDate);
    
    j.at("IsAutomated"sv).get_to(o.IsAutomated);
}




void to_json(json_t& j, const OAIBoxSetInfoRemoteSearchQuery& o) {
        j["SearchInfo"sv] = o.SearchInfo;
        j["ItemId"sv] = o.ItemId;
        j["SearchProviderName"sv] = o.SearchProviderName;
        j["IncludeDisabledProviders"sv] = o.IncludeDisabledProviders;
}
void from_json(const json_t& j, OAIBoxSetInfoRemoteSearchQuery& o) {
    if(j.contains("SearchInfo"sv))
    j.at("SearchInfo"sv).get_to(o.SearchInfo);
    
    j.at("ItemId"sv).get_to(o.ItemId);
    if(j.contains("SearchProviderName"sv))
    j.at("SearchProviderName"sv).get_to(o.SearchProviderName);
    
    j.at("IncludeDisabledProviders"sv).get_to(o.IncludeDisabledProviders);
}




void to_json(json_t& j, const OAIBrandingOptions& o) {
        j["LoginDisclaimer"sv] = o.LoginDisclaimer;
        j["CustomCss"sv] = o.CustomCss;
        j["SplashscreenEnabled"sv] = o.SplashscreenEnabled;
}
void from_json(const json_t& j, OAIBrandingOptions& o) {
    if(j.contains("LoginDisclaimer"sv))
    j.at("LoginDisclaimer"sv).get_to(o.LoginDisclaimer);
    if(j.contains("CustomCss"sv))
    j.at("CustomCss"sv).get_to(o.CustomCss);
    
    j.at("SplashscreenEnabled"sv).get_to(o.SplashscreenEnabled);
}




void to_json(json_t& j, const OAIBufferRequestDto& o) {
        j["When"sv] = o.When;
        j["PositionTicks"sv] = o.PositionTicks;
        j["IsPlaying"sv] = o.IsPlaying;
        j["PlaylistItemId"sv] = o.PlaylistItemId;
}
void from_json(const json_t& j, OAIBufferRequestDto& o) {
    
    j.at("When"sv).get_to(o.When);
    
    j.at("PositionTicks"sv).get_to(o.PositionTicks);
    
    j.at("IsPlaying"sv).get_to(o.IsPlaying);
    
    j.at("PlaylistItemId"sv).get_to(o.PlaylistItemId);
}




void to_json(json_t& j, const OAICastReceiverApplication& o) {
        j["Id"sv] = o.Id;
        j["Name"sv] = o.Name;
}
void from_json(const json_t& j, OAICastReceiverApplication& o) {
    
    j.at("Id"sv).get_to(o.Id);
    
    j.at("Name"sv).get_to(o.Name);
}




void to_json(json_t& j, const OAIChannelFeatures& o) {
        j["Name"sv] = o.Name;
        j["Id"sv] = o.Id;
        j["CanSearch"sv] = o.CanSearch;
        j["MediaTypes"sv] = o.MediaTypes;
        j["ContentTypes"sv] = o.ContentTypes;
        j["MaxPageSize"sv] = o.MaxPageSize;
        j["AutoRefreshLevels"sv] = o.AutoRefreshLevels;
        j["DefaultSortFields"sv] = o.DefaultSortFields;
        j["SupportsSortOrderToggle"sv] = o.SupportsSortOrderToggle;
        j["SupportsLatestMedia"sv] = o.SupportsLatestMedia;
        j["CanFilter"sv] = o.CanFilter;
        j["SupportsContentDownloading"sv] = o.SupportsContentDownloading;
}
void from_json(const json_t& j, OAIChannelFeatures& o) {
    
    j.at("Name"sv).get_to(o.Name);
    
    j.at("Id"sv).get_to(o.Id);
    
    j.at("CanSearch"sv).get_to(o.CanSearch);
    
    j.at("MediaTypes"sv).get_to(o.MediaTypes);
    
    j.at("ContentTypes"sv).get_to(o.ContentTypes);
    if(j.contains("MaxPageSize"sv))
    j.at("MaxPageSize"sv).get_to(o.MaxPageSize);
    if(j.contains("AutoRefreshLevels"sv))
    j.at("AutoRefreshLevels"sv).get_to(o.AutoRefreshLevels);
    
    j.at("DefaultSortFields"sv).get_to(o.DefaultSortFields);
    
    j.at("SupportsSortOrderToggle"sv).get_to(o.SupportsSortOrderToggle);
    
    j.at("SupportsLatestMedia"sv).get_to(o.SupportsLatestMedia);
    
    j.at("CanFilter"sv).get_to(o.CanFilter);
    
    j.at("SupportsContentDownloading"sv).get_to(o.SupportsContentDownloading);
}



void to_json(json_t& j, const OAIChannelItemSortField& e) {
    switch (e)
    {
    
        case OAIChannelItemSortField::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIChannelItemSortField::NAME:
            j = "Name";
            break;
    
        case OAIChannelItemSortField::COMMUNITYRATING:
            j = "CommunityRating";
            break;
    
        case OAIChannelItemSortField::PREMIEREDATE:
            j = "PremiereDate";
            break;
    
        case OAIChannelItemSortField::DATECREATED:
            j = "DateCreated";
            break;
    
        case OAIChannelItemSortField::RUNTIME:
            j = "Runtime";
            break;
    
        case OAIChannelItemSortField::PLAYCOUNT:
            j = "PlayCount";
            break;
    
        case OAIChannelItemSortField::COMMUNITYPLAYCOUNT:
            j = "CommunityPlayCount";
            break;
    
    }
}
void from_json(const json_t& j, OAIChannelItemSortField& e) {
    auto s = j.get<std::string>();
    
    if (s == "Name"sv) {
        e = (OAIChannelItemSortField::NAME);
    } 
    
    else if (s == "CommunityRating"sv) {
        e = (OAIChannelItemSortField::COMMUNITYRATING);
    } 
    
    else if (s == "PremiereDate"sv) {
        e = (OAIChannelItemSortField::PREMIEREDATE);
    } 
    
    else if (s == "DateCreated"sv) {
        e = (OAIChannelItemSortField::DATECREATED);
    } 
    
    else if (s == "Runtime"sv) {
        e = (OAIChannelItemSortField::RUNTIME);
    } 
    
    else if (s == "PlayCount"sv) {
        e = (OAIChannelItemSortField::PLAYCOUNT);
    } 
    
    else if (s == "CommunityPlayCount"sv) {
        e = (OAIChannelItemSortField::COMMUNITYPLAYCOUNT);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIChannelItemSortField";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIChannelMappingOptionsDto& o) {
        j["TunerChannels"sv] = o.TunerChannels;
        j["ProviderChannels"sv] = o.ProviderChannels;
        j["Mappings"sv] = o.Mappings;
        j["ProviderName"sv] = o.ProviderName;
}
void from_json(const json_t& j, OAIChannelMappingOptionsDto& o) {
    
    j.at("TunerChannels"sv).get_to(o.TunerChannels);
    
    j.at("ProviderChannels"sv).get_to(o.ProviderChannels);
    
    j.at("Mappings"sv).get_to(o.Mappings);
    if(j.contains("ProviderName"sv))
    j.at("ProviderName"sv).get_to(o.ProviderName);
}



void to_json(json_t& j, const OAIChannelMediaContentType& e) {
    switch (e)
    {
    
        case OAIChannelMediaContentType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIChannelMediaContentType::CLIP:
            j = "Clip";
            break;
    
        case OAIChannelMediaContentType::PODCAST:
            j = "Podcast";
            break;
    
        case OAIChannelMediaContentType::TRAILER:
            j = "Trailer";
            break;
    
        case OAIChannelMediaContentType::MOVIE:
            j = "Movie";
            break;
    
        case OAIChannelMediaContentType::EPISODE:
            j = "Episode";
            break;
    
        case OAIChannelMediaContentType::SONG:
            j = "Song";
            break;
    
        case OAIChannelMediaContentType::MOVIEEXTRA:
            j = "MovieExtra";
            break;
    
        case OAIChannelMediaContentType::TVEXTRA:
            j = "TvExtra";
            break;
    
    }
}
void from_json(const json_t& j, OAIChannelMediaContentType& e) {
    auto s = j.get<std::string>();
    
    if (s == "Clip"sv) {
        e = (OAIChannelMediaContentType::CLIP);
    } 
    
    else if (s == "Podcast"sv) {
        e = (OAIChannelMediaContentType::PODCAST);
    } 
    
    else if (s == "Trailer"sv) {
        e = (OAIChannelMediaContentType::TRAILER);
    } 
    
    else if (s == "Movie"sv) {
        e = (OAIChannelMediaContentType::MOVIE);
    } 
    
    else if (s == "Episode"sv) {
        e = (OAIChannelMediaContentType::EPISODE);
    } 
    
    else if (s == "Song"sv) {
        e = (OAIChannelMediaContentType::SONG);
    } 
    
    else if (s == "MovieExtra"sv) {
        e = (OAIChannelMediaContentType::MOVIEEXTRA);
    } 
    
    else if (s == "TvExtra"sv) {
        e = (OAIChannelMediaContentType::TVEXTRA);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIChannelMediaContentType";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIChannelMediaType& e) {
    switch (e)
    {
    
        case OAIChannelMediaType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIChannelMediaType::AUDIO:
            j = "Audio";
            break;
    
        case OAIChannelMediaType::VIDEO:
            j = "Video";
            break;
    
        case OAIChannelMediaType::PHOTO:
            j = "Photo";
            break;
    
    }
}
void from_json(const json_t& j, OAIChannelMediaType& e) {
    auto s = j.get<std::string>();
    
    if (s == "Audio"sv) {
        e = (OAIChannelMediaType::AUDIO);
    } 
    
    else if (s == "Video"sv) {
        e = (OAIChannelMediaType::VIDEO);
    } 
    
    else if (s == "Photo"sv) {
        e = (OAIChannelMediaType::PHOTO);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIChannelMediaType";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIChannelType& e) {
    switch (e)
    {
    
        case OAIChannelType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIChannelType::TV:
            j = "TV";
            break;
    
        case OAIChannelType::RADIO:
            j = "Radio";
            break;
    
    }
}
void from_json(const json_t& j, OAIChannelType& e) {
    auto s = j.get<std::string>();
    
    if (s == "TV"sv) {
        e = (OAIChannelType::TV);
    } 
    
    else if (s == "Radio"sv) {
        e = (OAIChannelType::RADIO);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIChannelType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIChapterInfo& o) {
        j["StartPositionTicks"sv] = o.StartPositionTicks;
        j["Name"sv] = o.Name;
        j["ImagePath"sv] = o.ImagePath;
        j["ImageDateModified"sv] = o.ImageDateModified;
        j["ImageTag"sv] = o.ImageTag;
}
void from_json(const json_t& j, OAIChapterInfo& o) {
    
    j.at("StartPositionTicks"sv).get_to(o.StartPositionTicks);
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("ImagePath"sv))
    j.at("ImagePath"sv).get_to(o.ImagePath);
    
    j.at("ImageDateModified"sv).get_to(o.ImageDateModified);
    if(j.contains("ImageTag"sv))
    j.at("ImageTag"sv).get_to(o.ImageTag);
}




void to_json(json_t& j, const OAIClientCapabilities& o) {
        j["PlayableMediaTypes"sv] = o.PlayableMediaTypes;
        j["SupportedCommands"sv] = o.SupportedCommands;
        j["SupportsMediaControl"sv] = o.SupportsMediaControl;
        j["SupportsPersistentIdentifier"sv] = o.SupportsPersistentIdentifier;
        j["DeviceProfile"sv] = o.DeviceProfile;
        j["AppStoreUrl"sv] = o.AppStoreUrl;
        j["IconUrl"sv] = o.IconUrl;
        j["SupportsContentUploading"sv] = o.SupportsContentUploading;
        j["SupportsSync"sv] = o.SupportsSync;
}
void from_json(const json_t& j, OAIClientCapabilities& o) {
    if(j.contains("PlayableMediaTypes"sv))
    j.at("PlayableMediaTypes"sv).get_to(o.PlayableMediaTypes);
    if(j.contains("SupportedCommands"sv))
    j.at("SupportedCommands"sv).get_to(o.SupportedCommands);
    
    j.at("SupportsMediaControl"sv).get_to(o.SupportsMediaControl);
    
    j.at("SupportsPersistentIdentifier"sv).get_to(o.SupportsPersistentIdentifier);
    if(j.contains("DeviceProfile"sv))
    j.at("DeviceProfile"sv).get_to(o.DeviceProfile);
    if(j.contains("AppStoreUrl"sv))
    j.at("AppStoreUrl"sv).get_to(o.AppStoreUrl);
    if(j.contains("IconUrl"sv))
    j.at("IconUrl"sv).get_to(o.IconUrl);
    if(j.contains("SupportsContentUploading"sv))
    j.at("SupportsContentUploading"sv).get_to(o.SupportsContentUploading);
    if(j.contains("SupportsSync"sv))
    j.at("SupportsSync"sv).get_to(o.SupportsSync);
}




void to_json(json_t& j, const OAIClientCapabilitiesDto& o) {
        j["PlayableMediaTypes"sv] = o.PlayableMediaTypes;
        j["SupportedCommands"sv] = o.SupportedCommands;
        j["SupportsMediaControl"sv] = o.SupportsMediaControl;
        j["SupportsPersistentIdentifier"sv] = o.SupportsPersistentIdentifier;
        j["DeviceProfile"sv] = o.DeviceProfile;
        j["AppStoreUrl"sv] = o.AppStoreUrl;
        j["IconUrl"sv] = o.IconUrl;
        j["SupportsContentUploading"sv] = o.SupportsContentUploading;
        j["SupportsSync"sv] = o.SupportsSync;
}
void from_json(const json_t& j, OAIClientCapabilitiesDto& o) {
    
    j.at("PlayableMediaTypes"sv).get_to(o.PlayableMediaTypes);
    
    j.at("SupportedCommands"sv).get_to(o.SupportedCommands);
    
    j.at("SupportsMediaControl"sv).get_to(o.SupportsMediaControl);
    
    j.at("SupportsPersistentIdentifier"sv).get_to(o.SupportsPersistentIdentifier);
    if(j.contains("DeviceProfile"sv))
    j.at("DeviceProfile"sv).get_to(o.DeviceProfile);
    if(j.contains("AppStoreUrl"sv))
    j.at("AppStoreUrl"sv).get_to(o.AppStoreUrl);
    if(j.contains("IconUrl"sv))
    j.at("IconUrl"sv).get_to(o.IconUrl);
    if(j.contains("SupportsContentUploading"sv))
    j.at("SupportsContentUploading"sv).get_to(o.SupportsContentUploading);
    if(j.contains("SupportsSync"sv))
    j.at("SupportsSync"sv).get_to(o.SupportsSync);
}




void to_json(json_t& j, const OAIClientLogDocumentResponseDto& o) {
        j["FileName"sv] = o.FileName;
}
void from_json(const json_t& j, OAIClientLogDocumentResponseDto& o) {
    
    j.at("FileName"sv).get_to(o.FileName);
}




void to_json(json_t& j, const OAICodecProfile& o) {
        j["Type"sv] = o.Type;
        j["Conditions"sv] = o.Conditions;
        j["ApplyConditions"sv] = o.ApplyConditions;
        j["Codec"sv] = o.Codec;
        j["Container"sv] = o.Container;
}
void from_json(const json_t& j, OAICodecProfile& o) {
    
    j.at("Type"sv).get_to(o.Type);
    if(j.contains("Conditions"sv))
    j.at("Conditions"sv).get_to(o.Conditions);
    if(j.contains("ApplyConditions"sv))
    j.at("ApplyConditions"sv).get_to(o.ApplyConditions);
    if(j.contains("Codec"sv))
    j.at("Codec"sv).get_to(o.Codec);
    if(j.contains("Container"sv))
    j.at("Container"sv).get_to(o.Container);
}



void to_json(json_t& j, const OAICodecType& e) {
    switch (e)
    {
    
        case OAICodecType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAICodecType::VIDEO:
            j = "Video";
            break;
    
        case OAICodecType::VIDEOAUDIO:
            j = "VideoAudio";
            break;
    
        case OAICodecType::AUDIO:
            j = "Audio";
            break;
    
    }
}
void from_json(const json_t& j, OAICodecType& e) {
    auto s = j.get<std::string>();
    
    if (s == "Video"sv) {
        e = (OAICodecType::VIDEO);
    } 
    
    else if (s == "VideoAudio"sv) {
        e = (OAICodecType::VIDEOAUDIO);
    } 
    
    else if (s == "Audio"sv) {
        e = (OAICodecType::AUDIO);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAICodecType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAICollectionCreationResult& o) {
        j["Id"sv] = o.Id;
}
void from_json(const json_t& j, OAICollectionCreationResult& o) {
    
    j.at("Id"sv).get_to(o.Id);
}



void to_json(json_t& j, const OAICollectionType& e) {
    switch (e)
    {
    
        case OAICollectionType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAICollectionType::UNKNOWN:
            j = "unknown";
            break;
    
        case OAICollectionType::MOVIES:
            j = "movies";
            break;
    
        case OAICollectionType::TVSHOWS:
            j = "tvshows";
            break;
    
        case OAICollectionType::MUSIC:
            j = "music";
            break;
    
        case OAICollectionType::MUSICVIDEOS:
            j = "musicvideos";
            break;
    
        case OAICollectionType::TRAILERS:
            j = "trailers";
            break;
    
        case OAICollectionType::HOMEVIDEOS:
            j = "homevideos";
            break;
    
        case OAICollectionType::BOXSETS:
            j = "boxsets";
            break;
    
        case OAICollectionType::BOOKS:
            j = "books";
            break;
    
        case OAICollectionType::PHOTOS:
            j = "photos";
            break;
    
        case OAICollectionType::LIVETV:
            j = "livetv";
            break;
    
        case OAICollectionType::PLAYLISTS:
            j = "playlists";
            break;
    
        case OAICollectionType::FOLDERS:
            j = "folders";
            break;
    
    }
}
void from_json(const json_t& j, OAICollectionType& e) {
    auto s = j.get<std::string>();
    
    if (s == "unknown"sv) {
        e = (OAICollectionType::UNKNOWN);
    } 
    
    else if (s == "movies"sv) {
        e = (OAICollectionType::MOVIES);
    } 
    
    else if (s == "tvshows"sv) {
        e = (OAICollectionType::TVSHOWS);
    } 
    
    else if (s == "music"sv) {
        e = (OAICollectionType::MUSIC);
    } 
    
    else if (s == "musicvideos"sv) {
        e = (OAICollectionType::MUSICVIDEOS);
    } 
    
    else if (s == "trailers"sv) {
        e = (OAICollectionType::TRAILERS);
    } 
    
    else if (s == "homevideos"sv) {
        e = (OAICollectionType::HOMEVIDEOS);
    } 
    
    else if (s == "boxsets"sv) {
        e = (OAICollectionType::BOXSETS);
    } 
    
    else if (s == "books"sv) {
        e = (OAICollectionType::BOOKS);
    } 
    
    else if (s == "photos"sv) {
        e = (OAICollectionType::PHOTOS);
    } 
    
    else if (s == "livetv"sv) {
        e = (OAICollectionType::LIVETV);
    } 
    
    else if (s == "playlists"sv) {
        e = (OAICollectionType::PLAYLISTS);
    } 
    
    else if (s == "folders"sv) {
        e = (OAICollectionType::FOLDERS);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAICollectionType";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAICollectionTypeOptions& e) {
    switch (e)
    {
    
        case OAICollectionTypeOptions::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAICollectionTypeOptions::MOVIES:
            j = "movies";
            break;
    
        case OAICollectionTypeOptions::TVSHOWS:
            j = "tvshows";
            break;
    
        case OAICollectionTypeOptions::MUSIC:
            j = "music";
            break;
    
        case OAICollectionTypeOptions::MUSICVIDEOS:
            j = "musicvideos";
            break;
    
        case OAICollectionTypeOptions::HOMEVIDEOS:
            j = "homevideos";
            break;
    
        case OAICollectionTypeOptions::BOXSETS:
            j = "boxsets";
            break;
    
        case OAICollectionTypeOptions::BOOKS:
            j = "books";
            break;
    
        case OAICollectionTypeOptions::MIXED:
            j = "mixed";
            break;
    
    }
}
void from_json(const json_t& j, OAICollectionTypeOptions& e) {
    auto s = j.get<std::string>();
    
    if (s == "movies"sv) {
        e = (OAICollectionTypeOptions::MOVIES);
    } 
    
    else if (s == "tvshows"sv) {
        e = (OAICollectionTypeOptions::TVSHOWS);
    } 
    
    else if (s == "music"sv) {
        e = (OAICollectionTypeOptions::MUSIC);
    } 
    
    else if (s == "musicvideos"sv) {
        e = (OAICollectionTypeOptions::MUSICVIDEOS);
    } 
    
    else if (s == "homevideos"sv) {
        e = (OAICollectionTypeOptions::HOMEVIDEOS);
    } 
    
    else if (s == "boxsets"sv) {
        e = (OAICollectionTypeOptions::BOXSETS);
    } 
    
    else if (s == "books"sv) {
        e = (OAICollectionTypeOptions::BOOKS);
    } 
    
    else if (s == "mixed"sv) {
        e = (OAICollectionTypeOptions::MIXED);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAICollectionTypeOptions";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIConfigImageTypes& o) {
        j["BackdropSizes"sv] = o.BackdropSizes;
        j["BaseUrl"sv] = o.BaseUrl;
        j["LogoSizes"sv] = o.LogoSizes;
        j["PosterSizes"sv] = o.PosterSizes;
        j["ProfileSizes"sv] = o.ProfileSizes;
        j["SecureBaseUrl"sv] = o.SecureBaseUrl;
        j["StillSizes"sv] = o.StillSizes;
}
void from_json(const json_t& j, OAIConfigImageTypes& o) {
    if(j.contains("BackdropSizes"sv))
    j.at("BackdropSizes"sv).get_to(o.BackdropSizes);
    if(j.contains("BaseUrl"sv))
    j.at("BaseUrl"sv).get_to(o.BaseUrl);
    if(j.contains("LogoSizes"sv))
    j.at("LogoSizes"sv).get_to(o.LogoSizes);
    if(j.contains("PosterSizes"sv))
    j.at("PosterSizes"sv).get_to(o.PosterSizes);
    if(j.contains("ProfileSizes"sv))
    j.at("ProfileSizes"sv).get_to(o.ProfileSizes);
    if(j.contains("SecureBaseUrl"sv))
    j.at("SecureBaseUrl"sv).get_to(o.SecureBaseUrl);
    if(j.contains("StillSizes"sv))
    j.at("StillSizes"sv).get_to(o.StillSizes);
}




void to_json(json_t& j, const OAIConfigurationPageInfo& o) {
        j["Name"sv] = o.Name;
        j["EnableInMainMenu"sv] = o.EnableInMainMenu;
        j["MenuSection"sv] = o.MenuSection;
        j["MenuIcon"sv] = o.MenuIcon;
        j["DisplayName"sv] = o.DisplayName;
        j["PluginId"sv] = o.PluginId;
}
void from_json(const json_t& j, OAIConfigurationPageInfo& o) {
    
    j.at("Name"sv).get_to(o.Name);
    
    j.at("EnableInMainMenu"sv).get_to(o.EnableInMainMenu);
    if(j.contains("MenuSection"sv))
    j.at("MenuSection"sv).get_to(o.MenuSection);
    if(j.contains("MenuIcon"sv))
    j.at("MenuIcon"sv).get_to(o.MenuIcon);
    if(j.contains("DisplayName"sv))
    j.at("DisplayName"sv).get_to(o.DisplayName);
    if(j.contains("PluginId"sv))
    j.at("PluginId"sv).get_to(o.PluginId);
}




void to_json(json_t& j, const OAIContainerProfile& o) {
        j["Type"sv] = o.Type;
        j["Conditions"sv] = o.Conditions;
        j["Container"sv] = o.Container;
}
void from_json(const json_t& j, OAIContainerProfile& o) {
    
    j.at("Type"sv).get_to(o.Type);
    
    j.at("Conditions"sv).get_to(o.Conditions);
    
    j.at("Container"sv).get_to(o.Container);
}




void to_json(json_t& j, const OAICountryInfo& o) {
        j["Name"sv] = o.Name;
        j["DisplayName"sv] = o.DisplayName;
        j["TwoLetterISORegionName"sv] = o.TwoLetterISORegionName;
        j["ThreeLetterISORegionName"sv] = o.ThreeLetterISORegionName;
}
void from_json(const json_t& j, OAICountryInfo& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("DisplayName"sv))
    j.at("DisplayName"sv).get_to(o.DisplayName);
    if(j.contains("TwoLetterISORegionName"sv))
    j.at("TwoLetterISORegionName"sv).get_to(o.TwoLetterISORegionName);
    if(j.contains("ThreeLetterISORegionName"sv))
    j.at("ThreeLetterISORegionName"sv).get_to(o.ThreeLetterISORegionName);
}




void to_json(json_t& j, const OAICreatePlaylistDto& o) {
        j["Name"sv] = o.Name;
        j["Ids"sv] = o.Ids;
        j["UserId"sv] = o.UserId;
        j["MediaType"sv] = o.MediaType;
        j["Users"sv] = o.Users;
        j["IsPublic"sv] = o.IsPublic;
}
void from_json(const json_t& j, OAICreatePlaylistDto& o) {
    
    j.at("Name"sv).get_to(o.Name);
    
    j.at("Ids"sv).get_to(o.Ids);
    if(j.contains("UserId"sv))
    j.at("UserId"sv).get_to(o.UserId);
    if(j.contains("MediaType"sv))
    j.at("MediaType"sv).get_to(o.MediaType);
    
    j.at("Users"sv).get_to(o.Users);
    
    j.at("IsPublic"sv).get_to(o.IsPublic);
}




void to_json(json_t& j, const OAICreateUserByName& o) {
        j["Name"sv] = o.Name;
        j["Password"sv] = o.Password;
}
void from_json(const json_t& j, OAICreateUserByName& o) {
    
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Password"sv))
    j.at("Password"sv).get_to(o.Password);
}




void to_json(json_t& j, const OAICultureDto& o) {
        j["Name"sv] = o.Name;
        j["DisplayName"sv] = o.DisplayName;
        j["TwoLetterISOLanguageName"sv] = o.TwoLetterISOLanguageName;
        j["ThreeLetterISOLanguageName"sv] = o.ThreeLetterISOLanguageName;
        j["ThreeLetterISOLanguageNames"sv] = o.ThreeLetterISOLanguageNames;
}
void from_json(const json_t& j, OAICultureDto& o) {
    
    j.at("Name"sv).get_to(o.Name);
    
    j.at("DisplayName"sv).get_to(o.DisplayName);
    
    j.at("TwoLetterISOLanguageName"sv).get_to(o.TwoLetterISOLanguageName);
    if(j.contains("ThreeLetterISOLanguageName"sv))
    j.at("ThreeLetterISOLanguageName"sv).get_to(o.ThreeLetterISOLanguageName);
    
    j.at("ThreeLetterISOLanguageNames"sv).get_to(o.ThreeLetterISOLanguageNames);
}



void to_json(json_t& j, const OAIDayOfWeek& e) {
    switch (e)
    {
    
        case OAIDayOfWeek::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIDayOfWeek::SUNDAY:
            j = "Sunday";
            break;
    
        case OAIDayOfWeek::MONDAY:
            j = "Monday";
            break;
    
        case OAIDayOfWeek::TUESDAY:
            j = "Tuesday";
            break;
    
        case OAIDayOfWeek::WEDNESDAY:
            j = "Wednesday";
            break;
    
        case OAIDayOfWeek::THURSDAY:
            j = "Thursday";
            break;
    
        case OAIDayOfWeek::FRIDAY:
            j = "Friday";
            break;
    
        case OAIDayOfWeek::SATURDAY:
            j = "Saturday";
            break;
    
    }
}
void from_json(const json_t& j, OAIDayOfWeek& e) {
    auto s = j.get<std::string>();
    
    if (s == "Sunday"sv) {
        e = (OAIDayOfWeek::SUNDAY);
    } 
    
    else if (s == "Monday"sv) {
        e = (OAIDayOfWeek::MONDAY);
    } 
    
    else if (s == "Tuesday"sv) {
        e = (OAIDayOfWeek::TUESDAY);
    } 
    
    else if (s == "Wednesday"sv) {
        e = (OAIDayOfWeek::WEDNESDAY);
    } 
    
    else if (s == "Thursday"sv) {
        e = (OAIDayOfWeek::THURSDAY);
    } 
    
    else if (s == "Friday"sv) {
        e = (OAIDayOfWeek::FRIDAY);
    } 
    
    else if (s == "Saturday"sv) {
        e = (OAIDayOfWeek::SATURDAY);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIDayOfWeek";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIDayPattern& e) {
    switch (e)
    {
    
        case OAIDayPattern::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIDayPattern::DAILY:
            j = "Daily";
            break;
    
        case OAIDayPattern::WEEKDAYS:
            j = "Weekdays";
            break;
    
        case OAIDayPattern::WEEKENDS:
            j = "Weekends";
            break;
    
    }
}
void from_json(const json_t& j, OAIDayPattern& e) {
    auto s = j.get<std::string>();
    
    if (s == "Daily"sv) {
        e = (OAIDayPattern::DAILY);
    } 
    
    else if (s == "Weekdays"sv) {
        e = (OAIDayPattern::WEEKDAYS);
    } 
    
    else if (s == "Weekends"sv) {
        e = (OAIDayPattern::WEEKENDS);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIDayPattern";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIDefaultDirectoryBrowserInfoDto& o) {
        j["Path"sv] = o.Path;
}
void from_json(const json_t& j, OAIDefaultDirectoryBrowserInfoDto& o) {
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
}




void to_json(json_t& j, const OAIDeviceInfo& o) {
        j["Name"sv] = o.Name;
        j["CustomName"sv] = o.CustomName;
        j["AccessToken"sv] = o.AccessToken;
        j["Id"sv] = o.Id;
        j["LastUserName"sv] = o.LastUserName;
        j["AppName"sv] = o.AppName;
        j["AppVersion"sv] = o.AppVersion;
        j["LastUserId"sv] = o.LastUserId;
        j["DateLastActivity"sv] = o.DateLastActivity;
        j["Capabilities"sv] = o.Capabilities;
        j["IconUrl"sv] = o.IconUrl;
}
void from_json(const json_t& j, OAIDeviceInfo& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("CustomName"sv))
    j.at("CustomName"sv).get_to(o.CustomName);
    if(j.contains("AccessToken"sv))
    j.at("AccessToken"sv).get_to(o.AccessToken);
    if(j.contains("Id"sv))
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("LastUserName"sv))
    j.at("LastUserName"sv).get_to(o.LastUserName);
    if(j.contains("AppName"sv))
    j.at("AppName"sv).get_to(o.AppName);
    if(j.contains("AppVersion"sv))
    j.at("AppVersion"sv).get_to(o.AppVersion);
    
    j.at("LastUserId"sv).get_to(o.LastUserId);
    
    j.at("DateLastActivity"sv).get_to(o.DateLastActivity);
    if(j.contains("Capabilities"sv))
    j.at("Capabilities"sv).get_to(o.Capabilities);
    if(j.contains("IconUrl"sv))
    j.at("IconUrl"sv).get_to(o.IconUrl);
}




void to_json(json_t& j, const OAIDeviceInfoQueryResult& o) {
        j["Items"sv] = o.Items;
        j["TotalRecordCount"sv] = o.TotalRecordCount;
        j["StartIndex"sv] = o.StartIndex;
}
void from_json(const json_t& j, OAIDeviceInfoQueryResult& o) {
    if(j.contains("Items"sv))
    j.at("Items"sv).get_to(o.Items);
    
    j.at("TotalRecordCount"sv).get_to(o.TotalRecordCount);
    
    j.at("StartIndex"sv).get_to(o.StartIndex);
}




void to_json(json_t& j, const OAIDeviceOptions& o) {
        j["Id"sv] = o.Id;
        j["DeviceId"sv] = o.DeviceId;
        j["CustomName"sv] = o.CustomName;
}
void from_json(const json_t& j, OAIDeviceOptions& o) {
    
    j.at("Id"sv).get_to(o.Id);
    
    j.at("DeviceId"sv).get_to(o.DeviceId);
    if(j.contains("CustomName"sv))
    j.at("CustomName"sv).get_to(o.CustomName);
}




void to_json(json_t& j, const OAIDeviceOptionsDto& o) {
        j["Id"sv] = o.Id;
        j["DeviceId"sv] = o.DeviceId;
        j["CustomName"sv] = o.CustomName;
}
void from_json(const json_t& j, OAIDeviceOptionsDto& o) {
    
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("DeviceId"sv))
    j.at("DeviceId"sv).get_to(o.DeviceId);
    if(j.contains("CustomName"sv))
    j.at("CustomName"sv).get_to(o.CustomName);
}




void to_json(json_t& j, const OAIDeviceProfile& o) {
        j["Name"sv] = o.Name;
        j["Id"sv] = o.Id;
        j["MaxStreamingBitrate"sv] = o.MaxStreamingBitrate;
        j["MaxStaticBitrate"sv] = o.MaxStaticBitrate;
        j["MusicStreamingTranscodingBitrate"sv] = o.MusicStreamingTranscodingBitrate;
        j["MaxStaticMusicBitrate"sv] = o.MaxStaticMusicBitrate;
        j["DirectPlayProfiles"sv] = o.DirectPlayProfiles;
        j["TranscodingProfiles"sv] = o.TranscodingProfiles;
        j["ContainerProfiles"sv] = o.ContainerProfiles;
        j["CodecProfiles"sv] = o.CodecProfiles;
        j["SubtitleProfiles"sv] = o.SubtitleProfiles;
}
void from_json(const json_t& j, OAIDeviceProfile& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Id"sv))
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("MaxStreamingBitrate"sv))
    j.at("MaxStreamingBitrate"sv).get_to(o.MaxStreamingBitrate);
    if(j.contains("MaxStaticBitrate"sv))
    j.at("MaxStaticBitrate"sv).get_to(o.MaxStaticBitrate);
    if(j.contains("MusicStreamingTranscodingBitrate"sv))
    j.at("MusicStreamingTranscodingBitrate"sv).get_to(o.MusicStreamingTranscodingBitrate);
    if(j.contains("MaxStaticMusicBitrate"sv))
    j.at("MaxStaticMusicBitrate"sv).get_to(o.MaxStaticMusicBitrate);
    
    j.at("DirectPlayProfiles"sv).get_to(o.DirectPlayProfiles);
    
    j.at("TranscodingProfiles"sv).get_to(o.TranscodingProfiles);
    
    j.at("ContainerProfiles"sv).get_to(o.ContainerProfiles);
    
    j.at("CodecProfiles"sv).get_to(o.CodecProfiles);
    
    j.at("SubtitleProfiles"sv).get_to(o.SubtitleProfiles);
}




void to_json(json_t& j, const OAIDirectPlayProfile& o) {
        j["Container"sv] = o.Container;
        j["AudioCodec"sv] = o.AudioCodec;
        j["VideoCodec"sv] = o.VideoCodec;
        j["Type"sv] = o.Type;
}
void from_json(const json_t& j, OAIDirectPlayProfile& o) {
    if(j.contains("Container"sv))
    j.at("Container"sv).get_to(o.Container);
    if(j.contains("AudioCodec"sv))
    j.at("AudioCodec"sv).get_to(o.AudioCodec);
    if(j.contains("VideoCodec"sv))
    j.at("VideoCodec"sv).get_to(o.VideoCodec);
    
    j.at("Type"sv).get_to(o.Type);
}




void to_json(json_t& j, const OAIDisplayPreferencesDto& o) {
        j["Id"sv] = o.Id;
        j["ViewType"sv] = o.ViewType;
        j["SortBy"sv] = o.SortBy;
        j["IndexBy"sv] = o.IndexBy;
        j["RememberIndexing"sv] = o.RememberIndexing;
        j["PrimaryImageHeight"sv] = o.PrimaryImageHeight;
        j["PrimaryImageWidth"sv] = o.PrimaryImageWidth;
        j["CustomPrefs"sv] = o.CustomPrefs;
        j["ScrollDirection"sv] = o.ScrollDirection;
        j["ShowBackdrop"sv] = o.ShowBackdrop;
        j["RememberSorting"sv] = o.RememberSorting;
        j["SortOrder"sv] = o.SortOrder;
        j["ShowSidebar"sv] = o.ShowSidebar;
        j["Client"sv] = o.Client;
}
void from_json(const json_t& j, OAIDisplayPreferencesDto& o) {
    if(j.contains("Id"sv))
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("ViewType"sv))
    j.at("ViewType"sv).get_to(o.ViewType);
    if(j.contains("SortBy"sv))
    j.at("SortBy"sv).get_to(o.SortBy);
    if(j.contains("IndexBy"sv))
    j.at("IndexBy"sv).get_to(o.IndexBy);
    
    j.at("RememberIndexing"sv).get_to(o.RememberIndexing);
    
    j.at("PrimaryImageHeight"sv).get_to(o.PrimaryImageHeight);
    
    j.at("PrimaryImageWidth"sv).get_to(o.PrimaryImageWidth);
    
    j.at("CustomPrefs"sv).get_to(o.CustomPrefs);
    
    j.at("ScrollDirection"sv).get_to(o.ScrollDirection);
    
    j.at("ShowBackdrop"sv).get_to(o.ShowBackdrop);
    
    j.at("RememberSorting"sv).get_to(o.RememberSorting);
    
    j.at("SortOrder"sv).get_to(o.SortOrder);
    
    j.at("ShowSidebar"sv).get_to(o.ShowSidebar);
    if(j.contains("Client"sv))
    j.at("Client"sv).get_to(o.Client);
}



void to_json(json_t& j, const OAIDlnaProfileType& e) {
    switch (e)
    {
    
        case OAIDlnaProfileType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIDlnaProfileType::AUDIO:
            j = "Audio";
            break;
    
        case OAIDlnaProfileType::VIDEO:
            j = "Video";
            break;
    
        case OAIDlnaProfileType::PHOTO:
            j = "Photo";
            break;
    
        case OAIDlnaProfileType::SUBTITLE:
            j = "Subtitle";
            break;
    
        case OAIDlnaProfileType::LYRIC:
            j = "Lyric";
            break;
    
    }
}
void from_json(const json_t& j, OAIDlnaProfileType& e) {
    auto s = j.get<std::string>();
    
    if (s == "Audio"sv) {
        e = (OAIDlnaProfileType::AUDIO);
    } 
    
    else if (s == "Video"sv) {
        e = (OAIDlnaProfileType::VIDEO);
    } 
    
    else if (s == "Photo"sv) {
        e = (OAIDlnaProfileType::PHOTO);
    } 
    
    else if (s == "Subtitle"sv) {
        e = (OAIDlnaProfileType::SUBTITLE);
    } 
    
    else if (s == "Lyric"sv) {
        e = (OAIDlnaProfileType::LYRIC);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIDlnaProfileType";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIDownMixStereoAlgorithms& e) {
    switch (e)
    {
    
        case OAIDownMixStereoAlgorithms::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIDownMixStereoAlgorithms::NONE:
            j = "None";
            break;
    
        case OAIDownMixStereoAlgorithms::DAVE750:
            j = "Dave750";
            break;
    
        case OAIDownMixStereoAlgorithms::NIGHTMODEDIALOGUE:
            j = "NightmodeDialogue";
            break;
    
    }
}
void from_json(const json_t& j, OAIDownMixStereoAlgorithms& e) {
    auto s = j.get<std::string>();
    
    if (s == "None"sv) {
        e = (OAIDownMixStereoAlgorithms::NONE);
    } 
    
    else if (s == "Dave750"sv) {
        e = (OAIDownMixStereoAlgorithms::DAVE750);
    } 
    
    else if (s == "NightmodeDialogue"sv) {
        e = (OAIDownMixStereoAlgorithms::NIGHTMODEDIALOGUE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIDownMixStereoAlgorithms";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIDynamicDayOfWeek& e) {
    switch (e)
    {
    
        case OAIDynamicDayOfWeek::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIDynamicDayOfWeek::SUNDAY:
            j = "Sunday";
            break;
    
        case OAIDynamicDayOfWeek::MONDAY:
            j = "Monday";
            break;
    
        case OAIDynamicDayOfWeek::TUESDAY:
            j = "Tuesday";
            break;
    
        case OAIDynamicDayOfWeek::WEDNESDAY:
            j = "Wednesday";
            break;
    
        case OAIDynamicDayOfWeek::THURSDAY:
            j = "Thursday";
            break;
    
        case OAIDynamicDayOfWeek::FRIDAY:
            j = "Friday";
            break;
    
        case OAIDynamicDayOfWeek::SATURDAY:
            j = "Saturday";
            break;
    
        case OAIDynamicDayOfWeek::EVERYDAY:
            j = "Everyday";
            break;
    
        case OAIDynamicDayOfWeek::WEEKDAY:
            j = "Weekday";
            break;
    
        case OAIDynamicDayOfWeek::WEEKEND:
            j = "Weekend";
            break;
    
    }
}
void from_json(const json_t& j, OAIDynamicDayOfWeek& e) {
    auto s = j.get<std::string>();
    
    if (s == "Sunday"sv) {
        e = (OAIDynamicDayOfWeek::SUNDAY);
    } 
    
    else if (s == "Monday"sv) {
        e = (OAIDynamicDayOfWeek::MONDAY);
    } 
    
    else if (s == "Tuesday"sv) {
        e = (OAIDynamicDayOfWeek::TUESDAY);
    } 
    
    else if (s == "Wednesday"sv) {
        e = (OAIDynamicDayOfWeek::WEDNESDAY);
    } 
    
    else if (s == "Thursday"sv) {
        e = (OAIDynamicDayOfWeek::THURSDAY);
    } 
    
    else if (s == "Friday"sv) {
        e = (OAIDynamicDayOfWeek::FRIDAY);
    } 
    
    else if (s == "Saturday"sv) {
        e = (OAIDynamicDayOfWeek::SATURDAY);
    } 
    
    else if (s == "Everyday"sv) {
        e = (OAIDynamicDayOfWeek::EVERYDAY);
    } 
    
    else if (s == "Weekday"sv) {
        e = (OAIDynamicDayOfWeek::WEEKDAY);
    } 
    
    else if (s == "Weekend"sv) {
        e = (OAIDynamicDayOfWeek::WEEKEND);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIDynamicDayOfWeek";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIEmbeddedSubtitleOptions& e) {
    switch (e)
    {
    
        case OAIEmbeddedSubtitleOptions::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIEmbeddedSubtitleOptions::ALLOWALL:
            j = "AllowAll";
            break;
    
        case OAIEmbeddedSubtitleOptions::ALLOWTEXT:
            j = "AllowText";
            break;
    
        case OAIEmbeddedSubtitleOptions::ALLOWIMAGE:
            j = "AllowImage";
            break;
    
        case OAIEmbeddedSubtitleOptions::ALLOWNONE:
            j = "AllowNone";
            break;
    
    }
}
void from_json(const json_t& j, OAIEmbeddedSubtitleOptions& e) {
    auto s = j.get<std::string>();
    
    if (s == "AllowAll"sv) {
        e = (OAIEmbeddedSubtitleOptions::ALLOWALL);
    } 
    
    else if (s == "AllowText"sv) {
        e = (OAIEmbeddedSubtitleOptions::ALLOWTEXT);
    } 
    
    else if (s == "AllowImage"sv) {
        e = (OAIEmbeddedSubtitleOptions::ALLOWIMAGE);
    } 
    
    else if (s == "AllowNone"sv) {
        e = (OAIEmbeddedSubtitleOptions::ALLOWNONE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIEmbeddedSubtitleOptions";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIEncodingContext& e) {
    switch (e)
    {
    
        case OAIEncodingContext::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIEncodingContext::STREAMING:
            j = "Streaming";
            break;
    
        case OAIEncodingContext::STATIC:
            j = "Static";
            break;
    
    }
}
void from_json(const json_t& j, OAIEncodingContext& e) {
    auto s = j.get<std::string>();
    
    if (s == "Streaming"sv) {
        e = (OAIEncodingContext::STREAMING);
    } 
    
    else if (s == "Static"sv) {
        e = (OAIEncodingContext::STATIC);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIEncodingContext";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIEncodingOptions& o) {
        j["EncodingThreadCount"sv] = o.EncodingThreadCount;
        j["TranscodingTempPath"sv] = o.TranscodingTempPath;
        j["FallbackFontPath"sv] = o.FallbackFontPath;
        j["EnableFallbackFont"sv] = o.EnableFallbackFont;
        j["EnableAudioVbr"sv] = o.EnableAudioVbr;
        j["DownMixAudioBoost"sv] = o.DownMixAudioBoost;
        j["DownMixStereoAlgorithm"sv] = o.DownMixStereoAlgorithm;
        j["MaxMuxingQueueSize"sv] = o.MaxMuxingQueueSize;
        j["EnableThrottling"sv] = o.EnableThrottling;
        j["ThrottleDelaySeconds"sv] = o.ThrottleDelaySeconds;
        j["EnableSegmentDeletion"sv] = o.EnableSegmentDeletion;
        j["SegmentKeepSeconds"sv] = o.SegmentKeepSeconds;
        j["HardwareAccelerationType"sv] = o.HardwareAccelerationType;
        j["EncoderAppPath"sv] = o.EncoderAppPath;
        j["EncoderAppPathDisplay"sv] = o.EncoderAppPathDisplay;
        j["VaapiDevice"sv] = o.VaapiDevice;
        j["EnableTonemapping"sv] = o.EnableTonemapping;
        j["EnableVppTonemapping"sv] = o.EnableVppTonemapping;
        j["EnableVideoToolboxTonemapping"sv] = o.EnableVideoToolboxTonemapping;
        j["TonemappingAlgorithm"sv] = o.TonemappingAlgorithm;
        j["TonemappingMode"sv] = o.TonemappingMode;
        j["TonemappingRange"sv] = o.TonemappingRange;
        j["TonemappingDesat"sv] = o.TonemappingDesat;
        j["TonemappingPeak"sv] = o.TonemappingPeak;
        j["TonemappingParam"sv] = o.TonemappingParam;
        j["VppTonemappingBrightness"sv] = o.VppTonemappingBrightness;
        j["VppTonemappingContrast"sv] = o.VppTonemappingContrast;
        j["H264Crf"sv] = o.H264Crf;
        j["H265Crf"sv] = o.H265Crf;
        j["EncoderPreset"sv] = o.EncoderPreset;
        j["DeinterlaceDoubleRate"sv] = o.DeinterlaceDoubleRate;
        j["DeinterlaceMethod"sv] = o.DeinterlaceMethod;
        j["EnableDecodingColorDepth10Hevc"sv] = o.EnableDecodingColorDepth10Hevc;
        j["EnableDecodingColorDepth10Vp9"sv] = o.EnableDecodingColorDepth10Vp9;
        j["EnableEnhancedNvdecDecoder"sv] = o.EnableEnhancedNvdecDecoder;
        j["PreferSystemNativeHwDecoder"sv] = o.PreferSystemNativeHwDecoder;
        j["EnableIntelLowPowerH264HwEncoder"sv] = o.EnableIntelLowPowerH264HwEncoder;
        j["EnableIntelLowPowerHevcHwEncoder"sv] = o.EnableIntelLowPowerHevcHwEncoder;
        j["EnableHardwareEncoding"sv] = o.EnableHardwareEncoding;
        j["AllowHevcEncoding"sv] = o.AllowHevcEncoding;
        j["AllowAv1Encoding"sv] = o.AllowAv1Encoding;
        j["EnableSubtitleExtraction"sv] = o.EnableSubtitleExtraction;
        j["HardwareDecodingCodecs"sv] = o.HardwareDecodingCodecs;
        j["AllowOnDemandMetadataBasedKeyframeExtractionForExtensions"sv] = o.AllowOnDemandMetadataBasedKeyframeExtractionForExtensions;
}
void from_json(const json_t& j, OAIEncodingOptions& o) {
    
    j.at("EncodingThreadCount"sv).get_to(o.EncodingThreadCount);
    if(j.contains("TranscodingTempPath"sv))
    j.at("TranscodingTempPath"sv).get_to(o.TranscodingTempPath);
    if(j.contains("FallbackFontPath"sv))
    j.at("FallbackFontPath"sv).get_to(o.FallbackFontPath);
    
    j.at("EnableFallbackFont"sv).get_to(o.EnableFallbackFont);
    
    j.at("EnableAudioVbr"sv).get_to(o.EnableAudioVbr);
    
    j.at("DownMixAudioBoost"sv).get_to(o.DownMixAudioBoost);
    
    j.at("DownMixStereoAlgorithm"sv).get_to(o.DownMixStereoAlgorithm);
    
    j.at("MaxMuxingQueueSize"sv).get_to(o.MaxMuxingQueueSize);
    
    j.at("EnableThrottling"sv).get_to(o.EnableThrottling);
    
    j.at("ThrottleDelaySeconds"sv).get_to(o.ThrottleDelaySeconds);
    
    j.at("EnableSegmentDeletion"sv).get_to(o.EnableSegmentDeletion);
    
    j.at("SegmentKeepSeconds"sv).get_to(o.SegmentKeepSeconds);
    if(j.contains("HardwareAccelerationType"sv))
    j.at("HardwareAccelerationType"sv).get_to(o.HardwareAccelerationType);
    if(j.contains("EncoderAppPath"sv))
    j.at("EncoderAppPath"sv).get_to(o.EncoderAppPath);
    if(j.contains("EncoderAppPathDisplay"sv))
    j.at("EncoderAppPathDisplay"sv).get_to(o.EncoderAppPathDisplay);
    if(j.contains("VaapiDevice"sv))
    j.at("VaapiDevice"sv).get_to(o.VaapiDevice);
    
    j.at("EnableTonemapping"sv).get_to(o.EnableTonemapping);
    
    j.at("EnableVppTonemapping"sv).get_to(o.EnableVppTonemapping);
    
    j.at("EnableVideoToolboxTonemapping"sv).get_to(o.EnableVideoToolboxTonemapping);
    if(j.contains("TonemappingAlgorithm"sv))
    j.at("TonemappingAlgorithm"sv).get_to(o.TonemappingAlgorithm);
    if(j.contains("TonemappingMode"sv))
    j.at("TonemappingMode"sv).get_to(o.TonemappingMode);
    if(j.contains("TonemappingRange"sv))
    j.at("TonemappingRange"sv).get_to(o.TonemappingRange);
    
    j.at("TonemappingDesat"sv).get_to(o.TonemappingDesat);
    
    j.at("TonemappingPeak"sv).get_to(o.TonemappingPeak);
    
    j.at("TonemappingParam"sv).get_to(o.TonemappingParam);
    
    j.at("VppTonemappingBrightness"sv).get_to(o.VppTonemappingBrightness);
    
    j.at("VppTonemappingContrast"sv).get_to(o.VppTonemappingContrast);
    
    j.at("H264Crf"sv).get_to(o.H264Crf);
    
    j.at("H265Crf"sv).get_to(o.H265Crf);
    if(j.contains("EncoderPreset"sv))
    j.at("EncoderPreset"sv).get_to(o.EncoderPreset);
    
    j.at("DeinterlaceDoubleRate"sv).get_to(o.DeinterlaceDoubleRate);
    if(j.contains("DeinterlaceMethod"sv))
    j.at("DeinterlaceMethod"sv).get_to(o.DeinterlaceMethod);
    
    j.at("EnableDecodingColorDepth10Hevc"sv).get_to(o.EnableDecodingColorDepth10Hevc);
    
    j.at("EnableDecodingColorDepth10Vp9"sv).get_to(o.EnableDecodingColorDepth10Vp9);
    
    j.at("EnableEnhancedNvdecDecoder"sv).get_to(o.EnableEnhancedNvdecDecoder);
    
    j.at("PreferSystemNativeHwDecoder"sv).get_to(o.PreferSystemNativeHwDecoder);
    
    j.at("EnableIntelLowPowerH264HwEncoder"sv).get_to(o.EnableIntelLowPowerH264HwEncoder);
    
    j.at("EnableIntelLowPowerHevcHwEncoder"sv).get_to(o.EnableIntelLowPowerHevcHwEncoder);
    
    j.at("EnableHardwareEncoding"sv).get_to(o.EnableHardwareEncoding);
    
    j.at("AllowHevcEncoding"sv).get_to(o.AllowHevcEncoding);
    
    j.at("AllowAv1Encoding"sv).get_to(o.AllowAv1Encoding);
    
    j.at("EnableSubtitleExtraction"sv).get_to(o.EnableSubtitleExtraction);
    if(j.contains("HardwareDecodingCodecs"sv))
    j.at("HardwareDecodingCodecs"sv).get_to(o.HardwareDecodingCodecs);
    if(j.contains("AllowOnDemandMetadataBasedKeyframeExtractionForExtensions"sv))
    j.at("AllowOnDemandMetadataBasedKeyframeExtractionForExtensions"sv).get_to(o.AllowOnDemandMetadataBasedKeyframeExtractionForExtensions);
}




void to_json(json_t& j, const OAIEndPointInfo& o) {
        j["IsLocal"sv] = o.IsLocal;
        j["IsInNetwork"sv] = o.IsInNetwork;
}
void from_json(const json_t& j, OAIEndPointInfo& o) {
    
    j.at("IsLocal"sv).get_to(o.IsLocal);
    
    j.at("IsInNetwork"sv).get_to(o.IsInNetwork);
}




void to_json(json_t& j, const OAIExternalIdInfo& o) {
        j["Name"sv] = o.Name;
        j["Key"sv] = o.Key;
        j["Type"sv] = o.Type;
        j["UrlFormatString"sv] = o.UrlFormatString;
}
void from_json(const json_t& j, OAIExternalIdInfo& o) {
    
    j.at("Name"sv).get_to(o.Name);
    
    j.at("Key"sv).get_to(o.Key);
    if(j.contains("Type"sv))
    j.at("Type"sv).get_to(o.Type);
    if(j.contains("UrlFormatString"sv))
    j.at("UrlFormatString"sv).get_to(o.UrlFormatString);
}



void to_json(json_t& j, const OAIExternalIdMediaType& e) {
    switch (e)
    {
    
        case OAIExternalIdMediaType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIExternalIdMediaType::ALBUM:
            j = "Album";
            break;
    
        case OAIExternalIdMediaType::ALBUMARTIST:
            j = "AlbumArtist";
            break;
    
        case OAIExternalIdMediaType::ARTIST:
            j = "Artist";
            break;
    
        case OAIExternalIdMediaType::BOXSET:
            j = "BoxSet";
            break;
    
        case OAIExternalIdMediaType::EPISODE:
            j = "Episode";
            break;
    
        case OAIExternalIdMediaType::MOVIE:
            j = "Movie";
            break;
    
        case OAIExternalIdMediaType::OTHERARTIST:
            j = "OtherArtist";
            break;
    
        case OAIExternalIdMediaType::PERSON:
            j = "Person";
            break;
    
        case OAIExternalIdMediaType::RELEASEGROUP:
            j = "ReleaseGroup";
            break;
    
        case OAIExternalIdMediaType::SEASON:
            j = "Season";
            break;
    
        case OAIExternalIdMediaType::SERIES:
            j = "Series";
            break;
    
        case OAIExternalIdMediaType::TRACK:
            j = "Track";
            break;
    
        case OAIExternalIdMediaType::BOOK:
            j = "Book";
            break;
    
    }
}
void from_json(const json_t& j, OAIExternalIdMediaType& e) {
    auto s = j.get<std::string>();
    
    if (s == "Album"sv) {
        e = (OAIExternalIdMediaType::ALBUM);
    } 
    
    else if (s == "AlbumArtist"sv) {
        e = (OAIExternalIdMediaType::ALBUMARTIST);
    } 
    
    else if (s == "Artist"sv) {
        e = (OAIExternalIdMediaType::ARTIST);
    } 
    
    else if (s == "BoxSet"sv) {
        e = (OAIExternalIdMediaType::BOXSET);
    } 
    
    else if (s == "Episode"sv) {
        e = (OAIExternalIdMediaType::EPISODE);
    } 
    
    else if (s == "Movie"sv) {
        e = (OAIExternalIdMediaType::MOVIE);
    } 
    
    else if (s == "OtherArtist"sv) {
        e = (OAIExternalIdMediaType::OTHERARTIST);
    } 
    
    else if (s == "Person"sv) {
        e = (OAIExternalIdMediaType::PERSON);
    } 
    
    else if (s == "ReleaseGroup"sv) {
        e = (OAIExternalIdMediaType::RELEASEGROUP);
    } 
    
    else if (s == "Season"sv) {
        e = (OAIExternalIdMediaType::SEASON);
    } 
    
    else if (s == "Series"sv) {
        e = (OAIExternalIdMediaType::SERIES);
    } 
    
    else if (s == "Track"sv) {
        e = (OAIExternalIdMediaType::TRACK);
    } 
    
    else if (s == "Book"sv) {
        e = (OAIExternalIdMediaType::BOOK);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIExternalIdMediaType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIExternalUrl& o) {
        j["Name"sv] = o.Name;
        j["Url"sv] = o.Url;
}
void from_json(const json_t& j, OAIExternalUrl& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Url"sv))
    j.at("Url"sv).get_to(o.Url);
}



void to_json(json_t& j, const OAIExtraType& e) {
    switch (e)
    {
    
        case OAIExtraType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIExtraType::UNKNOWN:
            j = "Unknown";
            break;
    
        case OAIExtraType::CLIP:
            j = "Clip";
            break;
    
        case OAIExtraType::TRAILER:
            j = "Trailer";
            break;
    
        case OAIExtraType::BEHINDTHESCENES:
            j = "BehindTheScenes";
            break;
    
        case OAIExtraType::DELETEDSCENE:
            j = "DeletedScene";
            break;
    
        case OAIExtraType::INTERVIEW:
            j = "Interview";
            break;
    
        case OAIExtraType::SCENE:
            j = "Scene";
            break;
    
        case OAIExtraType::SAMPLE:
            j = "Sample";
            break;
    
        case OAIExtraType::THEMESONG:
            j = "ThemeSong";
            break;
    
        case OAIExtraType::THEMEVIDEO:
            j = "ThemeVideo";
            break;
    
        case OAIExtraType::FEATURETTE:
            j = "Featurette";
            break;
    
        case OAIExtraType::SHORT:
            j = "Short";
            break;
    
    }
}
void from_json(const json_t& j, OAIExtraType& e) {
    auto s = j.get<std::string>();
    
    if (s == "Unknown"sv) {
        e = (OAIExtraType::UNKNOWN);
    } 
    
    else if (s == "Clip"sv) {
        e = (OAIExtraType::CLIP);
    } 
    
    else if (s == "Trailer"sv) {
        e = (OAIExtraType::TRAILER);
    } 
    
    else if (s == "BehindTheScenes"sv) {
        e = (OAIExtraType::BEHINDTHESCENES);
    } 
    
    else if (s == "DeletedScene"sv) {
        e = (OAIExtraType::DELETEDSCENE);
    } 
    
    else if (s == "Interview"sv) {
        e = (OAIExtraType::INTERVIEW);
    } 
    
    else if (s == "Scene"sv) {
        e = (OAIExtraType::SCENE);
    } 
    
    else if (s == "Sample"sv) {
        e = (OAIExtraType::SAMPLE);
    } 
    
    else if (s == "ThemeSong"sv) {
        e = (OAIExtraType::THEMESONG);
    } 
    
    else if (s == "ThemeVideo"sv) {
        e = (OAIExtraType::THEMEVIDEO);
    } 
    
    else if (s == "Featurette"sv) {
        e = (OAIExtraType::FEATURETTE);
    } 
    
    else if (s == "Short"sv) {
        e = (OAIExtraType::SHORT);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIExtraType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIFileSystemEntryInfo& o) {
        j["Name"sv] = o.Name;
        j["Path"sv] = o.Path;
        j["Type"sv] = o.Type;
}
void from_json(const json_t& j, OAIFileSystemEntryInfo& o) {
    
    j.at("Name"sv).get_to(o.Name);
    
    j.at("Path"sv).get_to(o.Path);
    
    j.at("Type"sv).get_to(o.Type);
}



void to_json(json_t& j, const OAIFileSystemEntryType& e) {
    switch (e)
    {
    
        case OAIFileSystemEntryType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIFileSystemEntryType::FILE:
            j = "File";
            break;
    
        case OAIFileSystemEntryType::DIRECTORY:
            j = "Directory";
            break;
    
        case OAIFileSystemEntryType::NETWORKCOMPUTER:
            j = "NetworkComputer";
            break;
    
        case OAIFileSystemEntryType::NETWORKSHARE:
            j = "NetworkShare";
            break;
    
    }
}
void from_json(const json_t& j, OAIFileSystemEntryType& e) {
    auto s = j.get<std::string>();
    
    if (s == "File"sv) {
        e = (OAIFileSystemEntryType::FILE);
    } 
    
    else if (s == "Directory"sv) {
        e = (OAIFileSystemEntryType::DIRECTORY);
    } 
    
    else if (s == "NetworkComputer"sv) {
        e = (OAIFileSystemEntryType::NETWORKCOMPUTER);
    } 
    
    else if (s == "NetworkShare"sv) {
        e = (OAIFileSystemEntryType::NETWORKSHARE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIFileSystemEntryType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIFontFile& o) {
        j["Name"sv] = o.Name;
        j["Size"sv] = o.Size;
        j["DateCreated"sv] = o.DateCreated;
        j["DateModified"sv] = o.DateModified;
}
void from_json(const json_t& j, OAIFontFile& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    
    j.at("Size"sv).get_to(o.Size);
    
    j.at("DateCreated"sv).get_to(o.DateCreated);
    
    j.at("DateModified"sv).get_to(o.DateModified);
}




void to_json(json_t& j, const OAIForceKeepAliveMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIForceKeepAliveMessage& o) {
    
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}



void to_json(json_t& j, const OAIForgotPasswordAction& e) {
    switch (e)
    {
    
        case OAIForgotPasswordAction::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIForgotPasswordAction::CONTACTADMIN:
            j = "ContactAdmin";
            break;
    
        case OAIForgotPasswordAction::PINCODE:
            j = "PinCode";
            break;
    
        case OAIForgotPasswordAction::INNETWORKREQUIRED:
            j = "InNetworkRequired";
            break;
    
    }
}
void from_json(const json_t& j, OAIForgotPasswordAction& e) {
    auto s = j.get<std::string>();
    
    if (s == "ContactAdmin"sv) {
        e = (OAIForgotPasswordAction::CONTACTADMIN);
    } 
    
    else if (s == "PinCode"sv) {
        e = (OAIForgotPasswordAction::PINCODE);
    } 
    
    else if (s == "InNetworkRequired"sv) {
        e = (OAIForgotPasswordAction::INNETWORKREQUIRED);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIForgotPasswordAction";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIForgotPasswordDto& o) {
        j["EnteredUsername"sv] = o.EnteredUsername;
}
void from_json(const json_t& j, OAIForgotPasswordDto& o) {
    
    j.at("EnteredUsername"sv).get_to(o.EnteredUsername);
}




void to_json(json_t& j, const OAIForgotPasswordPinDto& o) {
        j["Pin"sv] = o.Pin;
}
void from_json(const json_t& j, OAIForgotPasswordPinDto& o) {
    
    j.at("Pin"sv).get_to(o.Pin);
}




void to_json(json_t& j, const OAIForgotPasswordResult& o) {
        j["Action"sv] = o.Action;
        j["PinFile"sv] = o.PinFile;
        j["PinExpirationDate"sv] = o.PinExpirationDate;
}
void from_json(const json_t& j, OAIForgotPasswordResult& o) {
    
    j.at("Action"sv).get_to(o.Action);
    if(j.contains("PinFile"sv))
    j.at("PinFile"sv).get_to(o.PinFile);
    if(j.contains("PinExpirationDate"sv))
    j.at("PinExpirationDate"sv).get_to(o.PinExpirationDate);
}




void to_json(json_t& j, const OAIGeneralCommand& o) {
        j["Name"sv] = o.Name;
        j["ControllingUserId"sv] = o.ControllingUserId;
        j["Arguments"sv] = o.Arguments;
}
void from_json(const json_t& j, OAIGeneralCommand& o) {
    
    j.at("Name"sv).get_to(o.Name);
    
    j.at("ControllingUserId"sv).get_to(o.ControllingUserId);
    
    j.at("Arguments"sv).get_to(o.Arguments);
}




void to_json(json_t& j, const OAIGeneralCommandMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIGeneralCommandMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}



void to_json(json_t& j, const OAIGeneralCommandType& e) {
    switch (e)
    {
    
        case OAIGeneralCommandType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIGeneralCommandType::MOVEUP:
            j = "MoveUp";
            break;
    
        case OAIGeneralCommandType::MOVEDOWN:
            j = "MoveDown";
            break;
    
        case OAIGeneralCommandType::MOVELEFT:
            j = "MoveLeft";
            break;
    
        case OAIGeneralCommandType::MOVERIGHT:
            j = "MoveRight";
            break;
    
        case OAIGeneralCommandType::PAGEUP:
            j = "PageUp";
            break;
    
        case OAIGeneralCommandType::PAGEDOWN:
            j = "PageDown";
            break;
    
        case OAIGeneralCommandType::PREVIOUSLETTER:
            j = "PreviousLetter";
            break;
    
        case OAIGeneralCommandType::NEXTLETTER:
            j = "NextLetter";
            break;
    
        case OAIGeneralCommandType::TOGGLEOSD:
            j = "ToggleOsd";
            break;
    
        case OAIGeneralCommandType::TOGGLECONTEXTMENU:
            j = "ToggleContextMenu";
            break;
    
        case OAIGeneralCommandType::SELECT:
            j = "Select";
            break;
    
        case OAIGeneralCommandType::BACK:
            j = "Back";
            break;
    
        case OAIGeneralCommandType::TAKESCREENSHOT:
            j = "TakeScreenshot";
            break;
    
        case OAIGeneralCommandType::SENDKEY:
            j = "SendKey";
            break;
    
        case OAIGeneralCommandType::SENDSTRING:
            j = "SendString";
            break;
    
        case OAIGeneralCommandType::GOHOME:
            j = "GoHome";
            break;
    
        case OAIGeneralCommandType::GOTOSETTINGS:
            j = "GoToSettings";
            break;
    
        case OAIGeneralCommandType::VOLUMEUP:
            j = "VolumeUp";
            break;
    
        case OAIGeneralCommandType::VOLUMEDOWN:
            j = "VolumeDown";
            break;
    
        case OAIGeneralCommandType::MUTE:
            j = "Mute";
            break;
    
        case OAIGeneralCommandType::UNMUTE:
            j = "Unmute";
            break;
    
        case OAIGeneralCommandType::TOGGLEMUTE:
            j = "ToggleMute";
            break;
    
        case OAIGeneralCommandType::SETVOLUME:
            j = "SetVolume";
            break;
    
        case OAIGeneralCommandType::SETAUDIOSTREAMINDEX:
            j = "SetAudioStreamIndex";
            break;
    
        case OAIGeneralCommandType::SETSUBTITLESTREAMINDEX:
            j = "SetSubtitleStreamIndex";
            break;
    
        case OAIGeneralCommandType::TOGGLEFULLSCREEN:
            j = "ToggleFullscreen";
            break;
    
        case OAIGeneralCommandType::DISPLAYCONTENT:
            j = "DisplayContent";
            break;
    
        case OAIGeneralCommandType::GOTOSEARCH:
            j = "GoToSearch";
            break;
    
        case OAIGeneralCommandType::DISPLAYMESSAGE:
            j = "DisplayMessage";
            break;
    
        case OAIGeneralCommandType::SETREPEATMODE:
            j = "SetRepeatMode";
            break;
    
        case OAIGeneralCommandType::CHANNELUP:
            j = "ChannelUp";
            break;
    
        case OAIGeneralCommandType::CHANNELDOWN:
            j = "ChannelDown";
            break;
    
        case OAIGeneralCommandType::GUIDE:
            j = "Guide";
            break;
    
        case OAIGeneralCommandType::TOGGLESTATS:
            j = "ToggleStats";
            break;
    
        case OAIGeneralCommandType::PLAYMEDIASOURCE:
            j = "PlayMediaSource";
            break;
    
        case OAIGeneralCommandType::PLAYTRAILERS:
            j = "PlayTrailers";
            break;
    
        case OAIGeneralCommandType::SETSHUFFLEQUEUE:
            j = "SetShuffleQueue";
            break;
    
        case OAIGeneralCommandType::PLAYSTATE:
            j = "PlayState";
            break;
    
        case OAIGeneralCommandType::PLAYNEXT:
            j = "PlayNext";
            break;
    
        case OAIGeneralCommandType::TOGGLEOSDMENU:
            j = "ToggleOsdMenu";
            break;
    
        case OAIGeneralCommandType::PLAY:
            j = "Play";
            break;
    
        case OAIGeneralCommandType::SETMAXSTREAMINGBITRATE:
            j = "SetMaxStreamingBitrate";
            break;
    
        case OAIGeneralCommandType::SETPLAYBACKORDER:
            j = "SetPlaybackOrder";
            break;
    
    }
}
void from_json(const json_t& j, OAIGeneralCommandType& e) {
    auto s = j.get<std::string>();
    
    if (s == "MoveUp"sv) {
        e = (OAIGeneralCommandType::MOVEUP);
    } 
    
    else if (s == "MoveDown"sv) {
        e = (OAIGeneralCommandType::MOVEDOWN);
    } 
    
    else if (s == "MoveLeft"sv) {
        e = (OAIGeneralCommandType::MOVELEFT);
    } 
    
    else if (s == "MoveRight"sv) {
        e = (OAIGeneralCommandType::MOVERIGHT);
    } 
    
    else if (s == "PageUp"sv) {
        e = (OAIGeneralCommandType::PAGEUP);
    } 
    
    else if (s == "PageDown"sv) {
        e = (OAIGeneralCommandType::PAGEDOWN);
    } 
    
    else if (s == "PreviousLetter"sv) {
        e = (OAIGeneralCommandType::PREVIOUSLETTER);
    } 
    
    else if (s == "NextLetter"sv) {
        e = (OAIGeneralCommandType::NEXTLETTER);
    } 
    
    else if (s == "ToggleOsd"sv) {
        e = (OAIGeneralCommandType::TOGGLEOSD);
    } 
    
    else if (s == "ToggleContextMenu"sv) {
        e = (OAIGeneralCommandType::TOGGLECONTEXTMENU);
    } 
    
    else if (s == "Select"sv) {
        e = (OAIGeneralCommandType::SELECT);
    } 
    
    else if (s == "Back"sv) {
        e = (OAIGeneralCommandType::BACK);
    } 
    
    else if (s == "TakeScreenshot"sv) {
        e = (OAIGeneralCommandType::TAKESCREENSHOT);
    } 
    
    else if (s == "SendKey"sv) {
        e = (OAIGeneralCommandType::SENDKEY);
    } 
    
    else if (s == "SendString"sv) {
        e = (OAIGeneralCommandType::SENDSTRING);
    } 
    
    else if (s == "GoHome"sv) {
        e = (OAIGeneralCommandType::GOHOME);
    } 
    
    else if (s == "GoToSettings"sv) {
        e = (OAIGeneralCommandType::GOTOSETTINGS);
    } 
    
    else if (s == "VolumeUp"sv) {
        e = (OAIGeneralCommandType::VOLUMEUP);
    } 
    
    else if (s == "VolumeDown"sv) {
        e = (OAIGeneralCommandType::VOLUMEDOWN);
    } 
    
    else if (s == "Mute"sv) {
        e = (OAIGeneralCommandType::MUTE);
    } 
    
    else if (s == "Unmute"sv) {
        e = (OAIGeneralCommandType::UNMUTE);
    } 
    
    else if (s == "ToggleMute"sv) {
        e = (OAIGeneralCommandType::TOGGLEMUTE);
    } 
    
    else if (s == "SetVolume"sv) {
        e = (OAIGeneralCommandType::SETVOLUME);
    } 
    
    else if (s == "SetAudioStreamIndex"sv) {
        e = (OAIGeneralCommandType::SETAUDIOSTREAMINDEX);
    } 
    
    else if (s == "SetSubtitleStreamIndex"sv) {
        e = (OAIGeneralCommandType::SETSUBTITLESTREAMINDEX);
    } 
    
    else if (s == "ToggleFullscreen"sv) {
        e = (OAIGeneralCommandType::TOGGLEFULLSCREEN);
    } 
    
    else if (s == "DisplayContent"sv) {
        e = (OAIGeneralCommandType::DISPLAYCONTENT);
    } 
    
    else if (s == "GoToSearch"sv) {
        e = (OAIGeneralCommandType::GOTOSEARCH);
    } 
    
    else if (s == "DisplayMessage"sv) {
        e = (OAIGeneralCommandType::DISPLAYMESSAGE);
    } 
    
    else if (s == "SetRepeatMode"sv) {
        e = (OAIGeneralCommandType::SETREPEATMODE);
    } 
    
    else if (s == "ChannelUp"sv) {
        e = (OAIGeneralCommandType::CHANNELUP);
    } 
    
    else if (s == "ChannelDown"sv) {
        e = (OAIGeneralCommandType::CHANNELDOWN);
    } 
    
    else if (s == "Guide"sv) {
        e = (OAIGeneralCommandType::GUIDE);
    } 
    
    else if (s == "ToggleStats"sv) {
        e = (OAIGeneralCommandType::TOGGLESTATS);
    } 
    
    else if (s == "PlayMediaSource"sv) {
        e = (OAIGeneralCommandType::PLAYMEDIASOURCE);
    } 
    
    else if (s == "PlayTrailers"sv) {
        e = (OAIGeneralCommandType::PLAYTRAILERS);
    } 
    
    else if (s == "SetShuffleQueue"sv) {
        e = (OAIGeneralCommandType::SETSHUFFLEQUEUE);
    } 
    
    else if (s == "PlayState"sv) {
        e = (OAIGeneralCommandType::PLAYSTATE);
    } 
    
    else if (s == "PlayNext"sv) {
        e = (OAIGeneralCommandType::PLAYNEXT);
    } 
    
    else if (s == "ToggleOsdMenu"sv) {
        e = (OAIGeneralCommandType::TOGGLEOSDMENU);
    } 
    
    else if (s == "Play"sv) {
        e = (OAIGeneralCommandType::PLAY);
    } 
    
    else if (s == "SetMaxStreamingBitrate"sv) {
        e = (OAIGeneralCommandType::SETMAXSTREAMINGBITRATE);
    } 
    
    else if (s == "SetPlaybackOrder"sv) {
        e = (OAIGeneralCommandType::SETPLAYBACKORDER);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIGeneralCommandType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIGetProgramsDto& o) {
        j["ChannelIds"sv] = o.ChannelIds;
        j["UserId"sv] = o.UserId;
        j["MinStartDate"sv] = o.MinStartDate;
        j["HasAired"sv] = o.HasAired;
        j["IsAiring"sv] = o.IsAiring;
        j["MaxStartDate"sv] = o.MaxStartDate;
        j["MinEndDate"sv] = o.MinEndDate;
        j["MaxEndDate"sv] = o.MaxEndDate;
        j["IsMovie"sv] = o.IsMovie;
        j["IsSeries"sv] = o.IsSeries;
        j["IsNews"sv] = o.IsNews;
        j["IsKids"sv] = o.IsKids;
        j["IsSports"sv] = o.IsSports;
        j["StartIndex"sv] = o.StartIndex;
        j["Limit"sv] = o.Limit;
        j["SortBy"sv] = o.SortBy;
        j["SortOrder"sv] = o.SortOrder;
        j["Genres"sv] = o.Genres;
        j["GenreIds"sv] = o.GenreIds;
        j["EnableImages"sv] = o.EnableImages;
        j["EnableTotalRecordCount"sv] = o.EnableTotalRecordCount;
        j["ImageTypeLimit"sv] = o.ImageTypeLimit;
        j["EnableImageTypes"sv] = o.EnableImageTypes;
        j["EnableUserData"sv] = o.EnableUserData;
        j["SeriesTimerId"sv] = o.SeriesTimerId;
        j["LibrarySeriesId"sv] = o.LibrarySeriesId;
        j["Fields"sv] = o.Fields;
}
void from_json(const json_t& j, OAIGetProgramsDto& o) {
    
    j.at("ChannelIds"sv).get_to(o.ChannelIds);
    if(j.contains("UserId"sv))
    j.at("UserId"sv).get_to(o.UserId);
    if(j.contains("MinStartDate"sv))
    j.at("MinStartDate"sv).get_to(o.MinStartDate);
    if(j.contains("HasAired"sv))
    j.at("HasAired"sv).get_to(o.HasAired);
    if(j.contains("IsAiring"sv))
    j.at("IsAiring"sv).get_to(o.IsAiring);
    if(j.contains("MaxStartDate"sv))
    j.at("MaxStartDate"sv).get_to(o.MaxStartDate);
    if(j.contains("MinEndDate"sv))
    j.at("MinEndDate"sv).get_to(o.MinEndDate);
    if(j.contains("MaxEndDate"sv))
    j.at("MaxEndDate"sv).get_to(o.MaxEndDate);
    if(j.contains("IsMovie"sv))
    j.at("IsMovie"sv).get_to(o.IsMovie);
    if(j.contains("IsSeries"sv))
    j.at("IsSeries"sv).get_to(o.IsSeries);
    if(j.contains("IsNews"sv))
    j.at("IsNews"sv).get_to(o.IsNews);
    if(j.contains("IsKids"sv))
    j.at("IsKids"sv).get_to(o.IsKids);
    if(j.contains("IsSports"sv))
    j.at("IsSports"sv).get_to(o.IsSports);
    if(j.contains("StartIndex"sv))
    j.at("StartIndex"sv).get_to(o.StartIndex);
    if(j.contains("Limit"sv))
    j.at("Limit"sv).get_to(o.Limit);
    
    j.at("SortBy"sv).get_to(o.SortBy);
    
    j.at("SortOrder"sv).get_to(o.SortOrder);
    
    j.at("Genres"sv).get_to(o.Genres);
    
    j.at("GenreIds"sv).get_to(o.GenreIds);
    if(j.contains("EnableImages"sv))
    j.at("EnableImages"sv).get_to(o.EnableImages);
    
    j.at("EnableTotalRecordCount"sv).get_to(o.EnableTotalRecordCount);
    if(j.contains("ImageTypeLimit"sv))
    j.at("ImageTypeLimit"sv).get_to(o.ImageTypeLimit);
    
    j.at("EnableImageTypes"sv).get_to(o.EnableImageTypes);
    if(j.contains("EnableUserData"sv))
    j.at("EnableUserData"sv).get_to(o.EnableUserData);
    if(j.contains("SeriesTimerId"sv))
    j.at("SeriesTimerId"sv).get_to(o.SeriesTimerId);
    
    j.at("LibrarySeriesId"sv).get_to(o.LibrarySeriesId);
    
    j.at("Fields"sv).get_to(o.Fields);
}




void to_json(json_t& j, const OAIGroupInfoDto& o) {
        j["GroupId"sv] = o.GroupId;
        j["GroupName"sv] = o.GroupName;
        j["State"sv] = o.State;
        j["Participants"sv] = o.Participants;
        j["LastUpdatedAt"sv] = o.LastUpdatedAt;
}
void from_json(const json_t& j, OAIGroupInfoDto& o) {
    
    j.at("GroupId"sv).get_to(o.GroupId);
    
    j.at("GroupName"sv).get_to(o.GroupName);
    
    j.at("State"sv).get_to(o.State);
    
    j.at("Participants"sv).get_to(o.Participants);
    
    j.at("LastUpdatedAt"sv).get_to(o.LastUpdatedAt);
}




void to_json(json_t& j, const OAIGroupInfoDtoGroupUpdate& o) {
        j["GroupId"sv] = o.GroupId;
        j["Type"sv] = o.Type;
        j["Data"sv] = o.Data;
}
void from_json(const json_t& j, OAIGroupInfoDtoGroupUpdate& o) {
    
    j.at("GroupId"sv).get_to(o.GroupId);
    
    j.at("Type"sv).get_to(o.Type);
    
    j.at("Data"sv).get_to(o.Data);
}



void to_json(json_t& j, const OAIGroupQueueMode& e) {
    switch (e)
    {
    
        case OAIGroupQueueMode::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIGroupQueueMode::QUEUE:
            j = "Queue";
            break;
    
        case OAIGroupQueueMode::QUEUENEXT:
            j = "QueueNext";
            break;
    
    }
}
void from_json(const json_t& j, OAIGroupQueueMode& e) {
    auto s = j.get<std::string>();
    
    if (s == "Queue"sv) {
        e = (OAIGroupQueueMode::QUEUE);
    } 
    
    else if (s == "QueueNext"sv) {
        e = (OAIGroupQueueMode::QUEUENEXT);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIGroupQueueMode";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIGroupRepeatMode& e) {
    switch (e)
    {
    
        case OAIGroupRepeatMode::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIGroupRepeatMode::REPEATONE:
            j = "RepeatOne";
            break;
    
        case OAIGroupRepeatMode::REPEATALL:
            j = "RepeatAll";
            break;
    
        case OAIGroupRepeatMode::REPEATNONE:
            j = "RepeatNone";
            break;
    
    }
}
void from_json(const json_t& j, OAIGroupRepeatMode& e) {
    auto s = j.get<std::string>();
    
    if (s == "RepeatOne"sv) {
        e = (OAIGroupRepeatMode::REPEATONE);
    } 
    
    else if (s == "RepeatAll"sv) {
        e = (OAIGroupRepeatMode::REPEATALL);
    } 
    
    else if (s == "RepeatNone"sv) {
        e = (OAIGroupRepeatMode::REPEATNONE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIGroupRepeatMode";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIGroupShuffleMode& e) {
    switch (e)
    {
    
        case OAIGroupShuffleMode::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIGroupShuffleMode::SORTED:
            j = "Sorted";
            break;
    
        case OAIGroupShuffleMode::SHUFFLE:
            j = "Shuffle";
            break;
    
    }
}
void from_json(const json_t& j, OAIGroupShuffleMode& e) {
    auto s = j.get<std::string>();
    
    if (s == "Sorted"sv) {
        e = (OAIGroupShuffleMode::SORTED);
    } 
    
    else if (s == "Shuffle"sv) {
        e = (OAIGroupShuffleMode::SHUFFLE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIGroupShuffleMode";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIGroupStateType& e) {
    switch (e)
    {
    
        case OAIGroupStateType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIGroupStateType::IDLE:
            j = "Idle";
            break;
    
        case OAIGroupStateType::WAITING:
            j = "Waiting";
            break;
    
        case OAIGroupStateType::PAUSED:
            j = "Paused";
            break;
    
        case OAIGroupStateType::PLAYING:
            j = "Playing";
            break;
    
    }
}
void from_json(const json_t& j, OAIGroupStateType& e) {
    auto s = j.get<std::string>();
    
    if (s == "Idle"sv) {
        e = (OAIGroupStateType::IDLE);
    } 
    
    else if (s == "Waiting"sv) {
        e = (OAIGroupStateType::WAITING);
    } 
    
    else if (s == "Paused"sv) {
        e = (OAIGroupStateType::PAUSED);
    } 
    
    else if (s == "Playing"sv) {
        e = (OAIGroupStateType::PLAYING);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIGroupStateType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIGroupStateUpdate& o) {
        j["State"sv] = o.State;
        j["Reason"sv] = o.Reason;
}
void from_json(const json_t& j, OAIGroupStateUpdate& o) {
    
    j.at("State"sv).get_to(o.State);
    
    j.at("Reason"sv).get_to(o.Reason);
}




void to_json(json_t& j, const OAIGroupStateUpdateGroupUpdate& o) {
        j["GroupId"sv] = o.GroupId;
        j["Type"sv] = o.Type;
        j["Data"sv] = o.Data;
}
void from_json(const json_t& j, OAIGroupStateUpdateGroupUpdate& o) {
    
    j.at("GroupId"sv).get_to(o.GroupId);
    
    j.at("Type"sv).get_to(o.Type);
    
    j.at("Data"sv).get_to(o.Data);
}


void to_json(json_t& j, const OAIGroupUpdate& o) {
}
void from_json(const json_t& j, OAIGroupUpdate& o) {
}




void to_json(json_t& j, const OAIGroupUpdateType& e) {
    switch (e)
    {
    
        case OAIGroupUpdateType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIGroupUpdateType::USERJOINED:
            j = "UserJoined";
            break;
    
        case OAIGroupUpdateType::USERLEFT:
            j = "UserLeft";
            break;
    
        case OAIGroupUpdateType::GROUPJOINED:
            j = "GroupJoined";
            break;
    
        case OAIGroupUpdateType::GROUPLEFT:
            j = "GroupLeft";
            break;
    
        case OAIGroupUpdateType::STATEUPDATE:
            j = "StateUpdate";
            break;
    
        case OAIGroupUpdateType::PLAYQUEUE:
            j = "PlayQueue";
            break;
    
        case OAIGroupUpdateType::NOTINGROUP:
            j = "NotInGroup";
            break;
    
        case OAIGroupUpdateType::GROUPDOESNOTEXIST:
            j = "GroupDoesNotExist";
            break;
    
        case OAIGroupUpdateType::CREATEGROUPDENIED:
            j = "CreateGroupDenied";
            break;
    
        case OAIGroupUpdateType::JOINGROUPDENIED:
            j = "JoinGroupDenied";
            break;
    
        case OAIGroupUpdateType::LIBRARYACCESSDENIED:
            j = "LibraryAccessDenied";
            break;
    
    }
}
void from_json(const json_t& j, OAIGroupUpdateType& e) {
    auto s = j.get<std::string>();
    
    if (s == "UserJoined"sv) {
        e = (OAIGroupUpdateType::USERJOINED);
    } 
    
    else if (s == "UserLeft"sv) {
        e = (OAIGroupUpdateType::USERLEFT);
    } 
    
    else if (s == "GroupJoined"sv) {
        e = (OAIGroupUpdateType::GROUPJOINED);
    } 
    
    else if (s == "GroupLeft"sv) {
        e = (OAIGroupUpdateType::GROUPLEFT);
    } 
    
    else if (s == "StateUpdate"sv) {
        e = (OAIGroupUpdateType::STATEUPDATE);
    } 
    
    else if (s == "PlayQueue"sv) {
        e = (OAIGroupUpdateType::PLAYQUEUE);
    } 
    
    else if (s == "NotInGroup"sv) {
        e = (OAIGroupUpdateType::NOTINGROUP);
    } 
    
    else if (s == "GroupDoesNotExist"sv) {
        e = (OAIGroupUpdateType::GROUPDOESNOTEXIST);
    } 
    
    else if (s == "CreateGroupDenied"sv) {
        e = (OAIGroupUpdateType::CREATEGROUPDENIED);
    } 
    
    else if (s == "JoinGroupDenied"sv) {
        e = (OAIGroupUpdateType::JOINGROUPDENIED);
    } 
    
    else if (s == "LibraryAccessDenied"sv) {
        e = (OAIGroupUpdateType::LIBRARYACCESSDENIED);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIGroupUpdateType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIGuideInfo& o) {
        j["StartDate"sv] = o.StartDate;
        j["EndDate"sv] = o.EndDate;
}
void from_json(const json_t& j, OAIGuideInfo& o) {
    
    j.at("StartDate"sv).get_to(o.StartDate);
    
    j.at("EndDate"sv).get_to(o.EndDate);
}



void to_json(json_t& j, const OAIHardwareEncodingType& e) {
    switch (e)
    {
    
        case OAIHardwareEncodingType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIHardwareEncodingType::AMF:
            j = "AMF";
            break;
    
        case OAIHardwareEncodingType::QSV:
            j = "QSV";
            break;
    
        case OAIHardwareEncodingType::NVENC:
            j = "NVENC";
            break;
    
        case OAIHardwareEncodingType::V4L2M2M:
            j = "V4L2M2M";
            break;
    
        case OAIHardwareEncodingType::VAAPI:
            j = "VAAPI";
            break;
    
        case OAIHardwareEncodingType::VIDEOTOOLBOX:
            j = "VideoToolBox";
            break;
    
        case OAIHardwareEncodingType::RKMPP:
            j = "RKMPP";
            break;
    
    }
}
void from_json(const json_t& j, OAIHardwareEncodingType& e) {
    auto s = j.get<std::string>();
    
    if (s == "AMF"sv) {
        e = (OAIHardwareEncodingType::AMF);
    } 
    
    else if (s == "QSV"sv) {
        e = (OAIHardwareEncodingType::QSV);
    } 
    
    else if (s == "NVENC"sv) {
        e = (OAIHardwareEncodingType::NVENC);
    } 
    
    else if (s == "V4L2M2M"sv) {
        e = (OAIHardwareEncodingType::V4L2M2M);
    } 
    
    else if (s == "VAAPI"sv) {
        e = (OAIHardwareEncodingType::VAAPI);
    } 
    
    else if (s == "VideoToolBox"sv) {
        e = (OAIHardwareEncodingType::VIDEOTOOLBOX);
    } 
    
    else if (s == "RKMPP"sv) {
        e = (OAIHardwareEncodingType::RKMPP);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIHardwareEncodingType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIIPlugin& o) {
        j["Name"sv] = o.Name;
        j["Description"sv] = o.Description;
        j["Id"sv] = o.Id;
        j["Version"sv] = o.Version;
        j["AssemblyFilePath"sv] = o.AssemblyFilePath;
        j["CanUninstall"sv] = o.CanUninstall;
        j["DataFolderPath"sv] = o.DataFolderPath;
}
void from_json(const json_t& j, OAIIPlugin& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Description"sv))
    j.at("Description"sv).get_to(o.Description);
    
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("Version"sv))
    j.at("Version"sv).get_to(o.Version);
    if(j.contains("AssemblyFilePath"sv))
    j.at("AssemblyFilePath"sv).get_to(o.AssemblyFilePath);
    
    j.at("CanUninstall"sv).get_to(o.CanUninstall);
    if(j.contains("DataFolderPath"sv))
    j.at("DataFolderPath"sv).get_to(o.DataFolderPath);
}




void to_json(json_t& j, const OAIIgnoreWaitRequestDto& o) {
        j["IgnoreWait"sv] = o.IgnoreWait;
}
void from_json(const json_t& j, OAIIgnoreWaitRequestDto& o) {
    
    j.at("IgnoreWait"sv).get_to(o.IgnoreWait);
}



void to_json(json_t& j, const OAIImageFormat& e) {
    switch (e)
    {
    
        case OAIImageFormat::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIImageFormat::BMP:
            j = "Bmp";
            break;
    
        case OAIImageFormat::GIF:
            j = "Gif";
            break;
    
        case OAIImageFormat::JPG:
            j = "Jpg";
            break;
    
        case OAIImageFormat::PNG:
            j = "Png";
            break;
    
        case OAIImageFormat::WEBP:
            j = "Webp";
            break;
    
        case OAIImageFormat::SVG:
            j = "Svg";
            break;
    
    }
}
void from_json(const json_t& j, OAIImageFormat& e) {
    auto s = j.get<std::string>();
    
    if (s == "Bmp"sv) {
        e = (OAIImageFormat::BMP);
    } 
    
    else if (s == "Gif"sv) {
        e = (OAIImageFormat::GIF);
    } 
    
    else if (s == "Jpg"sv) {
        e = (OAIImageFormat::JPG);
    } 
    
    else if (s == "Png"sv) {
        e = (OAIImageFormat::PNG);
    } 
    
    else if (s == "Webp"sv) {
        e = (OAIImageFormat::WEBP);
    } 
    
    else if (s == "Svg"sv) {
        e = (OAIImageFormat::SVG);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIImageFormat";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIImageInfo& o) {
        j["ImageType"sv] = o.ImageType;
        j["ImageIndex"sv] = o.ImageIndex;
        j["ImageTag"sv] = o.ImageTag;
        j["Path"sv] = o.Path;
        j["BlurHash"sv] = o.BlurHash;
        j["Height"sv] = o.Height;
        j["Width"sv] = o.Width;
        j["Size"sv] = o.Size;
}
void from_json(const json_t& j, OAIImageInfo& o) {
    
    j.at("ImageType"sv).get_to(o.ImageType);
    if(j.contains("ImageIndex"sv))
    j.at("ImageIndex"sv).get_to(o.ImageIndex);
    if(j.contains("ImageTag"sv))
    j.at("ImageTag"sv).get_to(o.ImageTag);
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("BlurHash"sv))
    j.at("BlurHash"sv).get_to(o.BlurHash);
    if(j.contains("Height"sv))
    j.at("Height"sv).get_to(o.Height);
    if(j.contains("Width"sv))
    j.at("Width"sv).get_to(o.Width);
    
    j.at("Size"sv).get_to(o.Size);
}




void to_json(json_t& j, const OAIImageOption& o) {
        j["Type"sv] = o.Type;
        j["Limit"sv] = o.Limit;
        j["MinWidth"sv] = o.MinWidth;
}
void from_json(const json_t& j, OAIImageOption& o) {
    
    j.at("Type"sv).get_to(o.Type);
    
    j.at("Limit"sv).get_to(o.Limit);
    
    j.at("MinWidth"sv).get_to(o.MinWidth);
}



void to_json(json_t& j, const OAIImageOrientation& e) {
    switch (e)
    {
    
        case OAIImageOrientation::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIImageOrientation::TOPLEFT:
            j = "TopLeft";
            break;
    
        case OAIImageOrientation::TOPRIGHT:
            j = "TopRight";
            break;
    
        case OAIImageOrientation::BOTTOMRIGHT:
            j = "BottomRight";
            break;
    
        case OAIImageOrientation::BOTTOMLEFT:
            j = "BottomLeft";
            break;
    
        case OAIImageOrientation::LEFTTOP:
            j = "LeftTop";
            break;
    
        case OAIImageOrientation::RIGHTTOP:
            j = "RightTop";
            break;
    
        case OAIImageOrientation::RIGHTBOTTOM:
            j = "RightBottom";
            break;
    
        case OAIImageOrientation::LEFTBOTTOM:
            j = "LeftBottom";
            break;
    
    }
}
void from_json(const json_t& j, OAIImageOrientation& e) {
    auto s = j.get<std::string>();
    
    if (s == "TopLeft"sv) {
        e = (OAIImageOrientation::TOPLEFT);
    } 
    
    else if (s == "TopRight"sv) {
        e = (OAIImageOrientation::TOPRIGHT);
    } 
    
    else if (s == "BottomRight"sv) {
        e = (OAIImageOrientation::BOTTOMRIGHT);
    } 
    
    else if (s == "BottomLeft"sv) {
        e = (OAIImageOrientation::BOTTOMLEFT);
    } 
    
    else if (s == "LeftTop"sv) {
        e = (OAIImageOrientation::LEFTTOP);
    } 
    
    else if (s == "RightTop"sv) {
        e = (OAIImageOrientation::RIGHTTOP);
    } 
    
    else if (s == "RightBottom"sv) {
        e = (OAIImageOrientation::RIGHTBOTTOM);
    } 
    
    else if (s == "LeftBottom"sv) {
        e = (OAIImageOrientation::LEFTBOTTOM);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIImageOrientation";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIImageProviderInfo& o) {
        j["Name"sv] = o.Name;
        j["SupportedImages"sv] = o.SupportedImages;
}
void from_json(const json_t& j, OAIImageProviderInfo& o) {
    
    j.at("Name"sv).get_to(o.Name);
    
    j.at("SupportedImages"sv).get_to(o.SupportedImages);
}



void to_json(json_t& j, const OAIImageResolution& e) {
    switch (e)
    {
    
        case OAIImageResolution::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIImageResolution::MATCHSOURCE:
            j = "MatchSource";
            break;
    
        case OAIImageResolution::P144:
            j = "P144";
            break;
    
        case OAIImageResolution::P240:
            j = "P240";
            break;
    
        case OAIImageResolution::P360:
            j = "P360";
            break;
    
        case OAIImageResolution::P480:
            j = "P480";
            break;
    
        case OAIImageResolution::P720:
            j = "P720";
            break;
    
        case OAIImageResolution::P1080:
            j = "P1080";
            break;
    
        case OAIImageResolution::P1440:
            j = "P1440";
            break;
    
        case OAIImageResolution::P2160:
            j = "P2160";
            break;
    
    }
}
void from_json(const json_t& j, OAIImageResolution& e) {
    auto s = j.get<std::string>();
    
    if (s == "MatchSource"sv) {
        e = (OAIImageResolution::MATCHSOURCE);
    } 
    
    else if (s == "P144"sv) {
        e = (OAIImageResolution::P144);
    } 
    
    else if (s == "P240"sv) {
        e = (OAIImageResolution::P240);
    } 
    
    else if (s == "P360"sv) {
        e = (OAIImageResolution::P360);
    } 
    
    else if (s == "P480"sv) {
        e = (OAIImageResolution::P480);
    } 
    
    else if (s == "P720"sv) {
        e = (OAIImageResolution::P720);
    } 
    
    else if (s == "P1080"sv) {
        e = (OAIImageResolution::P1080);
    } 
    
    else if (s == "P1440"sv) {
        e = (OAIImageResolution::P1440);
    } 
    
    else if (s == "P2160"sv) {
        e = (OAIImageResolution::P2160);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIImageResolution";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIImageSavingConvention& e) {
    switch (e)
    {
    
        case OAIImageSavingConvention::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIImageSavingConvention::LEGACY:
            j = "Legacy";
            break;
    
        case OAIImageSavingConvention::COMPATIBLE:
            j = "Compatible";
            break;
    
    }
}
void from_json(const json_t& j, OAIImageSavingConvention& e) {
    auto s = j.get<std::string>();
    
    if (s == "Legacy"sv) {
        e = (OAIImageSavingConvention::LEGACY);
    } 
    
    else if (s == "Compatible"sv) {
        e = (OAIImageSavingConvention::COMPATIBLE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIImageSavingConvention";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIImageType& e) {
    switch (e)
    {
    
        case OAIImageType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIImageType::PRIMARY:
            j = "Primary";
            break;
    
        case OAIImageType::ART:
            j = "Art";
            break;
    
        case OAIImageType::BACKDROP:
            j = "Backdrop";
            break;
    
        case OAIImageType::BANNER:
            j = "Banner";
            break;
    
        case OAIImageType::LOGO:
            j = "Logo";
            break;
    
        case OAIImageType::THUMB:
            j = "Thumb";
            break;
    
        case OAIImageType::DISC:
            j = "Disc";
            break;
    
        case OAIImageType::BOX:
            j = "Box";
            break;
    
        case OAIImageType::SCREENSHOT:
            j = "Screenshot";
            break;
    
        case OAIImageType::MENU:
            j = "Menu";
            break;
    
        case OAIImageType::CHAPTER:
            j = "Chapter";
            break;
    
        case OAIImageType::BOXREAR:
            j = "BoxRear";
            break;
    
        case OAIImageType::PROFILE:
            j = "Profile";
            break;
    
    }
}
void from_json(const json_t& j, OAIImageType& e) {
    auto s = j.get<std::string>();
    
    if (s == "Primary"sv) {
        e = (OAIImageType::PRIMARY);
    } 
    
    else if (s == "Art"sv) {
        e = (OAIImageType::ART);
    } 
    
    else if (s == "Backdrop"sv) {
        e = (OAIImageType::BACKDROP);
    } 
    
    else if (s == "Banner"sv) {
        e = (OAIImageType::BANNER);
    } 
    
    else if (s == "Logo"sv) {
        e = (OAIImageType::LOGO);
    } 
    
    else if (s == "Thumb"sv) {
        e = (OAIImageType::THUMB);
    } 
    
    else if (s == "Disc"sv) {
        e = (OAIImageType::DISC);
    } 
    
    else if (s == "Box"sv) {
        e = (OAIImageType::BOX);
    } 
    
    else if (s == "Screenshot"sv) {
        e = (OAIImageType::SCREENSHOT);
    } 
    
    else if (s == "Menu"sv) {
        e = (OAIImageType::MENU);
    } 
    
    else if (s == "Chapter"sv) {
        e = (OAIImageType::CHAPTER);
    } 
    
    else if (s == "BoxRear"sv) {
        e = (OAIImageType::BOXREAR);
    } 
    
    else if (s == "Profile"sv) {
        e = (OAIImageType::PROFILE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIImageType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIInboundKeepAliveMessage& o) {
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIInboundKeepAliveMessage& o) {
    
    j.at("MessageType"sv).get_to(o.MessageType);
}


void to_json(json_t& j, const OAIInboundWebSocketMessage& o) {
}
void from_json(const json_t& j, OAIInboundWebSocketMessage& o) {
}





void to_json(json_t& j, const OAIInstallationInfo& o) {
        j["Guid"sv] = o.Guid;
        j["Name"sv] = o.Name;
        j["Version"sv] = o.Version;
        j["Changelog"sv] = o.Changelog;
        j["SourceUrl"sv] = o.SourceUrl;
        j["Checksum"sv] = o.Checksum;
        j["PackageInfo"sv] = o.PackageInfo;
}
void from_json(const json_t& j, OAIInstallationInfo& o) {
    
    j.at("Guid"sv).get_to(o.Guid);
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Version"sv))
    j.at("Version"sv).get_to(o.Version);
    if(j.contains("Changelog"sv))
    j.at("Changelog"sv).get_to(o.Changelog);
    if(j.contains("SourceUrl"sv))
    j.at("SourceUrl"sv).get_to(o.SourceUrl);
    if(j.contains("Checksum"sv))
    j.at("Checksum"sv).get_to(o.Checksum);
    if(j.contains("PackageInfo"sv))
    j.at("PackageInfo"sv).get_to(o.PackageInfo);
}



void to_json(json_t& j, const OAIIsoType& e) {
    switch (e)
    {
    
        case OAIIsoType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIIsoType::DVD:
            j = "Dvd";
            break;
    
        case OAIIsoType::BLURAY:
            j = "BluRay";
            break;
    
    }
}
void from_json(const json_t& j, OAIIsoType& e) {
    auto s = j.get<std::string>();
    
    if (s == "Dvd"sv) {
        e = (OAIIsoType::DVD);
    } 
    
    else if (s == "BluRay"sv) {
        e = (OAIIsoType::BLURAY);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIIsoType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIItemCounts& o) {
        j["MovieCount"sv] = o.MovieCount;
        j["SeriesCount"sv] = o.SeriesCount;
        j["EpisodeCount"sv] = o.EpisodeCount;
        j["ArtistCount"sv] = o.ArtistCount;
        j["ProgramCount"sv] = o.ProgramCount;
        j["TrailerCount"sv] = o.TrailerCount;
        j["SongCount"sv] = o.SongCount;
        j["AlbumCount"sv] = o.AlbumCount;
        j["MusicVideoCount"sv] = o.MusicVideoCount;
        j["BoxSetCount"sv] = o.BoxSetCount;
        j["BookCount"sv] = o.BookCount;
        j["ItemCount"sv] = o.ItemCount;
}
void from_json(const json_t& j, OAIItemCounts& o) {
    
    j.at("MovieCount"sv).get_to(o.MovieCount);
    
    j.at("SeriesCount"sv).get_to(o.SeriesCount);
    
    j.at("EpisodeCount"sv).get_to(o.EpisodeCount);
    
    j.at("ArtistCount"sv).get_to(o.ArtistCount);
    
    j.at("ProgramCount"sv).get_to(o.ProgramCount);
    
    j.at("TrailerCount"sv).get_to(o.TrailerCount);
    
    j.at("SongCount"sv).get_to(o.SongCount);
    
    j.at("AlbumCount"sv).get_to(o.AlbumCount);
    
    j.at("MusicVideoCount"sv).get_to(o.MusicVideoCount);
    
    j.at("BoxSetCount"sv).get_to(o.BoxSetCount);
    
    j.at("BookCount"sv).get_to(o.BookCount);
    
    j.at("ItemCount"sv).get_to(o.ItemCount);
}



void to_json(json_t& j, const OAIItemFields& e) {
    switch (e)
    {
    
        case OAIItemFields::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIItemFields::AIRTIME:
            j = "AirTime";
            break;
    
        case OAIItemFields::CANDELETE:
            j = "CanDelete";
            break;
    
        case OAIItemFields::CANDOWNLOAD:
            j = "CanDownload";
            break;
    
        case OAIItemFields::CHANNELINFO:
            j = "ChannelInfo";
            break;
    
        case OAIItemFields::CHAPTERS:
            j = "Chapters";
            break;
    
        case OAIItemFields::TRICKPLAY:
            j = "Trickplay";
            break;
    
        case OAIItemFields::CHILDCOUNT:
            j = "ChildCount";
            break;
    
        case OAIItemFields::CUMULATIVERUNTIMETICKS:
            j = "CumulativeRunTimeTicks";
            break;
    
        case OAIItemFields::CUSTOMRATING:
            j = "CustomRating";
            break;
    
        case OAIItemFields::DATECREATED:
            j = "DateCreated";
            break;
    
        case OAIItemFields::DATELASTMEDIAADDED:
            j = "DateLastMediaAdded";
            break;
    
        case OAIItemFields::DISPLAYPREFERENCESID:
            j = "DisplayPreferencesId";
            break;
    
        case OAIItemFields::ETAG:
            j = "Etag";
            break;
    
        case OAIItemFields::EXTERNALURLS:
            j = "ExternalUrls";
            break;
    
        case OAIItemFields::GENRES:
            j = "Genres";
            break;
    
        case OAIItemFields::HOMEPAGEURL:
            j = "HomePageUrl";
            break;
    
        case OAIItemFields::ITEMCOUNTS:
            j = "ItemCounts";
            break;
    
        case OAIItemFields::MEDIASOURCECOUNT:
            j = "MediaSourceCount";
            break;
    
        case OAIItemFields::MEDIASOURCES:
            j = "MediaSources";
            break;
    
        case OAIItemFields::ORIGINALTITLE:
            j = "OriginalTitle";
            break;
    
        case OAIItemFields::OVERVIEW:
            j = "Overview";
            break;
    
        case OAIItemFields::PARENTID:
            j = "ParentId";
            break;
    
        case OAIItemFields::PATH:
            j = "Path";
            break;
    
        case OAIItemFields::PEOPLE:
            j = "People";
            break;
    
        case OAIItemFields::PLAYACCESS:
            j = "PlayAccess";
            break;
    
        case OAIItemFields::PRODUCTIONLOCATIONS:
            j = "ProductionLocations";
            break;
    
        case OAIItemFields::PROVIDERIDS:
            j = "ProviderIds";
            break;
    
        case OAIItemFields::PRIMARYIMAGEASPECTRATIO:
            j = "PrimaryImageAspectRatio";
            break;
    
        case OAIItemFields::RECURSIVEITEMCOUNT:
            j = "RecursiveItemCount";
            break;
    
        case OAIItemFields::SETTINGS:
            j = "Settings";
            break;
    
        case OAIItemFields::SCREENSHOTIMAGETAGS:
            j = "ScreenshotImageTags";
            break;
    
        case OAIItemFields::SERIESPRIMARYIMAGE:
            j = "SeriesPrimaryImage";
            break;
    
        case OAIItemFields::SERIESSTUDIO:
            j = "SeriesStudio";
            break;
    
        case OAIItemFields::SORTNAME:
            j = "SortName";
            break;
    
        case OAIItemFields::SPECIALEPISODENUMBERS:
            j = "SpecialEpisodeNumbers";
            break;
    
        case OAIItemFields::STUDIOS:
            j = "Studios";
            break;
    
        case OAIItemFields::TAGLINES:
            j = "Taglines";
            break;
    
        case OAIItemFields::TAGS:
            j = "Tags";
            break;
    
        case OAIItemFields::REMOTETRAILERS:
            j = "RemoteTrailers";
            break;
    
        case OAIItemFields::MEDIASTREAMS:
            j = "MediaStreams";
            break;
    
        case OAIItemFields::SEASONUSERDATA:
            j = "SeasonUserData";
            break;
    
        case OAIItemFields::SERVICENAME:
            j = "ServiceName";
            break;
    
        case OAIItemFields::THEMESONGIDS:
            j = "ThemeSongIds";
            break;
    
        case OAIItemFields::THEMEVIDEOIDS:
            j = "ThemeVideoIds";
            break;
    
        case OAIItemFields::EXTERNALETAG:
            j = "ExternalEtag";
            break;
    
        case OAIItemFields::PRESENTATIONUNIQUEKEY:
            j = "PresentationUniqueKey";
            break;
    
        case OAIItemFields::INHERITEDPARENTALRATINGVALUE:
            j = "InheritedParentalRatingValue";
            break;
    
        case OAIItemFields::EXTERNALSERIESID:
            j = "ExternalSeriesId";
            break;
    
        case OAIItemFields::SERIESPRESENTATIONUNIQUEKEY:
            j = "SeriesPresentationUniqueKey";
            break;
    
        case OAIItemFields::DATELASTREFRESHED:
            j = "DateLastRefreshed";
            break;
    
        case OAIItemFields::DATELASTSAVED:
            j = "DateLastSaved";
            break;
    
        case OAIItemFields::REFRESHSTATE:
            j = "RefreshState";
            break;
    
        case OAIItemFields::CHANNELIMAGE:
            j = "ChannelImage";
            break;
    
        case OAIItemFields::ENABLEMEDIASOURCEDISPLAY:
            j = "EnableMediaSourceDisplay";
            break;
    
        case OAIItemFields::WIDTH:
            j = "Width";
            break;
    
        case OAIItemFields::HEIGHT:
            j = "Height";
            break;
    
        case OAIItemFields::EXTRAIDS:
            j = "ExtraIds";
            break;
    
        case OAIItemFields::LOCALTRAILERCOUNT:
            j = "LocalTrailerCount";
            break;
    
        case OAIItemFields::ISHD:
            j = "IsHD";
            break;
    
        case OAIItemFields::SPECIALFEATURECOUNT:
            j = "SpecialFeatureCount";
            break;
    
    }
}
void from_json(const json_t& j, OAIItemFields& e) {
    auto s = j.get<std::string>();
    
    if (s == "AirTime"sv) {
        e = (OAIItemFields::AIRTIME);
    } 
    
    else if (s == "CanDelete"sv) {
        e = (OAIItemFields::CANDELETE);
    } 
    
    else if (s == "CanDownload"sv) {
        e = (OAIItemFields::CANDOWNLOAD);
    } 
    
    else if (s == "ChannelInfo"sv) {
        e = (OAIItemFields::CHANNELINFO);
    } 
    
    else if (s == "Chapters"sv) {
        e = (OAIItemFields::CHAPTERS);
    } 
    
    else if (s == "Trickplay"sv) {
        e = (OAIItemFields::TRICKPLAY);
    } 
    
    else if (s == "ChildCount"sv) {
        e = (OAIItemFields::CHILDCOUNT);
    } 
    
    else if (s == "CumulativeRunTimeTicks"sv) {
        e = (OAIItemFields::CUMULATIVERUNTIMETICKS);
    } 
    
    else if (s == "CustomRating"sv) {
        e = (OAIItemFields::CUSTOMRATING);
    } 
    
    else if (s == "DateCreated"sv) {
        e = (OAIItemFields::DATECREATED);
    } 
    
    else if (s == "DateLastMediaAdded"sv) {
        e = (OAIItemFields::DATELASTMEDIAADDED);
    } 
    
    else if (s == "DisplayPreferencesId"sv) {
        e = (OAIItemFields::DISPLAYPREFERENCESID);
    } 
    
    else if (s == "Etag"sv) {
        e = (OAIItemFields::ETAG);
    } 
    
    else if (s == "ExternalUrls"sv) {
        e = (OAIItemFields::EXTERNALURLS);
    } 
    
    else if (s == "Genres"sv) {
        e = (OAIItemFields::GENRES);
    } 
    
    else if (s == "HomePageUrl"sv) {
        e = (OAIItemFields::HOMEPAGEURL);
    } 
    
    else if (s == "ItemCounts"sv) {
        e = (OAIItemFields::ITEMCOUNTS);
    } 
    
    else if (s == "MediaSourceCount"sv) {
        e = (OAIItemFields::MEDIASOURCECOUNT);
    } 
    
    else if (s == "MediaSources"sv) {
        e = (OAIItemFields::MEDIASOURCES);
    } 
    
    else if (s == "OriginalTitle"sv) {
        e = (OAIItemFields::ORIGINALTITLE);
    } 
    
    else if (s == "Overview"sv) {
        e = (OAIItemFields::OVERVIEW);
    } 
    
    else if (s == "ParentId"sv) {
        e = (OAIItemFields::PARENTID);
    } 
    
    else if (s == "Path"sv) {
        e = (OAIItemFields::PATH);
    } 
    
    else if (s == "People"sv) {
        e = (OAIItemFields::PEOPLE);
    } 
    
    else if (s == "PlayAccess"sv) {
        e = (OAIItemFields::PLAYACCESS);
    } 
    
    else if (s == "ProductionLocations"sv) {
        e = (OAIItemFields::PRODUCTIONLOCATIONS);
    } 
    
    else if (s == "ProviderIds"sv) {
        e = (OAIItemFields::PROVIDERIDS);
    } 
    
    else if (s == "PrimaryImageAspectRatio"sv) {
        e = (OAIItemFields::PRIMARYIMAGEASPECTRATIO);
    } 
    
    else if (s == "RecursiveItemCount"sv) {
        e = (OAIItemFields::RECURSIVEITEMCOUNT);
    } 
    
    else if (s == "Settings"sv) {
        e = (OAIItemFields::SETTINGS);
    } 
    
    else if (s == "ScreenshotImageTags"sv) {
        e = (OAIItemFields::SCREENSHOTIMAGETAGS);
    } 
    
    else if (s == "SeriesPrimaryImage"sv) {
        e = (OAIItemFields::SERIESPRIMARYIMAGE);
    } 
    
    else if (s == "SeriesStudio"sv) {
        e = (OAIItemFields::SERIESSTUDIO);
    } 
    
    else if (s == "SortName"sv) {
        e = (OAIItemFields::SORTNAME);
    } 
    
    else if (s == "SpecialEpisodeNumbers"sv) {
        e = (OAIItemFields::SPECIALEPISODENUMBERS);
    } 
    
    else if (s == "Studios"sv) {
        e = (OAIItemFields::STUDIOS);
    } 
    
    else if (s == "Taglines"sv) {
        e = (OAIItemFields::TAGLINES);
    } 
    
    else if (s == "Tags"sv) {
        e = (OAIItemFields::TAGS);
    } 
    
    else if (s == "RemoteTrailers"sv) {
        e = (OAIItemFields::REMOTETRAILERS);
    } 
    
    else if (s == "MediaStreams"sv) {
        e = (OAIItemFields::MEDIASTREAMS);
    } 
    
    else if (s == "SeasonUserData"sv) {
        e = (OAIItemFields::SEASONUSERDATA);
    } 
    
    else if (s == "ServiceName"sv) {
        e = (OAIItemFields::SERVICENAME);
    } 
    
    else if (s == "ThemeSongIds"sv) {
        e = (OAIItemFields::THEMESONGIDS);
    } 
    
    else if (s == "ThemeVideoIds"sv) {
        e = (OAIItemFields::THEMEVIDEOIDS);
    } 
    
    else if (s == "ExternalEtag"sv) {
        e = (OAIItemFields::EXTERNALETAG);
    } 
    
    else if (s == "PresentationUniqueKey"sv) {
        e = (OAIItemFields::PRESENTATIONUNIQUEKEY);
    } 
    
    else if (s == "InheritedParentalRatingValue"sv) {
        e = (OAIItemFields::INHERITEDPARENTALRATINGVALUE);
    } 
    
    else if (s == "ExternalSeriesId"sv) {
        e = (OAIItemFields::EXTERNALSERIESID);
    } 
    
    else if (s == "SeriesPresentationUniqueKey"sv) {
        e = (OAIItemFields::SERIESPRESENTATIONUNIQUEKEY);
    } 
    
    else if (s == "DateLastRefreshed"sv) {
        e = (OAIItemFields::DATELASTREFRESHED);
    } 
    
    else if (s == "DateLastSaved"sv) {
        e = (OAIItemFields::DATELASTSAVED);
    } 
    
    else if (s == "RefreshState"sv) {
        e = (OAIItemFields::REFRESHSTATE);
    } 
    
    else if (s == "ChannelImage"sv) {
        e = (OAIItemFields::CHANNELIMAGE);
    } 
    
    else if (s == "EnableMediaSourceDisplay"sv) {
        e = (OAIItemFields::ENABLEMEDIASOURCEDISPLAY);
    } 
    
    else if (s == "Width"sv) {
        e = (OAIItemFields::WIDTH);
    } 
    
    else if (s == "Height"sv) {
        e = (OAIItemFields::HEIGHT);
    } 
    
    else if (s == "ExtraIds"sv) {
        e = (OAIItemFields::EXTRAIDS);
    } 
    
    else if (s == "LocalTrailerCount"sv) {
        e = (OAIItemFields::LOCALTRAILERCOUNT);
    } 
    
    else if (s == "IsHD"sv) {
        e = (OAIItemFields::ISHD);
    } 
    
    else if (s == "SpecialFeatureCount"sv) {
        e = (OAIItemFields::SPECIALFEATURECOUNT);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIItemFields";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIItemFilter& e) {
    switch (e)
    {
    
        case OAIItemFilter::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIItemFilter::ISFOLDER:
            j = "IsFolder";
            break;
    
        case OAIItemFilter::ISNOTFOLDER:
            j = "IsNotFolder";
            break;
    
        case OAIItemFilter::ISUNPLAYED:
            j = "IsUnplayed";
            break;
    
        case OAIItemFilter::ISPLAYED:
            j = "IsPlayed";
            break;
    
        case OAIItemFilter::ISFAVORITE:
            j = "IsFavorite";
            break;
    
        case OAIItemFilter::ISRESUMABLE:
            j = "IsResumable";
            break;
    
        case OAIItemFilter::LIKES:
            j = "Likes";
            break;
    
        case OAIItemFilter::DISLIKES:
            j = "Dislikes";
            break;
    
        case OAIItemFilter::ISFAVORITEORLIKES:
            j = "IsFavoriteOrLikes";
            break;
    
    }
}
void from_json(const json_t& j, OAIItemFilter& e) {
    auto s = j.get<std::string>();
    
    if (s == "IsFolder"sv) {
        e = (OAIItemFilter::ISFOLDER);
    } 
    
    else if (s == "IsNotFolder"sv) {
        e = (OAIItemFilter::ISNOTFOLDER);
    } 
    
    else if (s == "IsUnplayed"sv) {
        e = (OAIItemFilter::ISUNPLAYED);
    } 
    
    else if (s == "IsPlayed"sv) {
        e = (OAIItemFilter::ISPLAYED);
    } 
    
    else if (s == "IsFavorite"sv) {
        e = (OAIItemFilter::ISFAVORITE);
    } 
    
    else if (s == "IsResumable"sv) {
        e = (OAIItemFilter::ISRESUMABLE);
    } 
    
    else if (s == "Likes"sv) {
        e = (OAIItemFilter::LIKES);
    } 
    
    else if (s == "Dislikes"sv) {
        e = (OAIItemFilter::DISLIKES);
    } 
    
    else if (s == "IsFavoriteOrLikes"sv) {
        e = (OAIItemFilter::ISFAVORITEORLIKES);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIItemFilter";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIItemSortBy& e) {
    switch (e)
    {
    
        case OAIItemSortBy::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIItemSortBy::DEFAULT:
            j = "Default";
            break;
    
        case OAIItemSortBy::AIREDEPISODEORDER:
            j = "AiredEpisodeOrder";
            break;
    
        case OAIItemSortBy::ALBUM:
            j = "Album";
            break;
    
        case OAIItemSortBy::ALBUMARTIST:
            j = "AlbumArtist";
            break;
    
        case OAIItemSortBy::ARTIST:
            j = "Artist";
            break;
    
        case OAIItemSortBy::DATECREATED:
            j = "DateCreated";
            break;
    
        case OAIItemSortBy::OFFICIALRATING:
            j = "OfficialRating";
            break;
    
        case OAIItemSortBy::DATEPLAYED:
            j = "DatePlayed";
            break;
    
        case OAIItemSortBy::PREMIEREDATE:
            j = "PremiereDate";
            break;
    
        case OAIItemSortBy::STARTDATE:
            j = "StartDate";
            break;
    
        case OAIItemSortBy::SORTNAME:
            j = "SortName";
            break;
    
        case OAIItemSortBy::NAME:
            j = "Name";
            break;
    
        case OAIItemSortBy::RANDOM:
            j = "Random";
            break;
    
        case OAIItemSortBy::RUNTIME:
            j = "Runtime";
            break;
    
        case OAIItemSortBy::COMMUNITYRATING:
            j = "CommunityRating";
            break;
    
        case OAIItemSortBy::PRODUCTIONYEAR:
            j = "ProductionYear";
            break;
    
        case OAIItemSortBy::PLAYCOUNT:
            j = "PlayCount";
            break;
    
        case OAIItemSortBy::CRITICRATING:
            j = "CriticRating";
            break;
    
        case OAIItemSortBy::ISFOLDER:
            j = "IsFolder";
            break;
    
        case OAIItemSortBy::ISUNPLAYED:
            j = "IsUnplayed";
            break;
    
        case OAIItemSortBy::ISPLAYED:
            j = "IsPlayed";
            break;
    
        case OAIItemSortBy::SERIESSORTNAME:
            j = "SeriesSortName";
            break;
    
        case OAIItemSortBy::VIDEOBITRATE:
            j = "VideoBitRate";
            break;
    
        case OAIItemSortBy::AIRTIME:
            j = "AirTime";
            break;
    
        case OAIItemSortBy::STUDIO:
            j = "Studio";
            break;
    
        case OAIItemSortBy::ISFAVORITEORLIKED:
            j = "IsFavoriteOrLiked";
            break;
    
        case OAIItemSortBy::DATELASTCONTENTADDED:
            j = "DateLastContentAdded";
            break;
    
        case OAIItemSortBy::SERIESDATEPLAYED:
            j = "SeriesDatePlayed";
            break;
    
        case OAIItemSortBy::PARENTINDEXNUMBER:
            j = "ParentIndexNumber";
            break;
    
        case OAIItemSortBy::INDEXNUMBER:
            j = "IndexNumber";
            break;
    
        case OAIItemSortBy::SIMILARITYSCORE:
            j = "SimilarityScore";
            break;
    
        case OAIItemSortBy::SEARCHSCORE:
            j = "SearchScore";
            break;
    
    }
}
void from_json(const json_t& j, OAIItemSortBy& e) {
    auto s = j.get<std::string>();
    
    if (s == "Default"sv) {
        e = (OAIItemSortBy::DEFAULT);
    } 
    
    else if (s == "AiredEpisodeOrder"sv) {
        e = (OAIItemSortBy::AIREDEPISODEORDER);
    } 
    
    else if (s == "Album"sv) {
        e = (OAIItemSortBy::ALBUM);
    } 
    
    else if (s == "AlbumArtist"sv) {
        e = (OAIItemSortBy::ALBUMARTIST);
    } 
    
    else if (s == "Artist"sv) {
        e = (OAIItemSortBy::ARTIST);
    } 
    
    else if (s == "DateCreated"sv) {
        e = (OAIItemSortBy::DATECREATED);
    } 
    
    else if (s == "OfficialRating"sv) {
        e = (OAIItemSortBy::OFFICIALRATING);
    } 
    
    else if (s == "DatePlayed"sv) {
        e = (OAIItemSortBy::DATEPLAYED);
    } 
    
    else if (s == "PremiereDate"sv) {
        e = (OAIItemSortBy::PREMIEREDATE);
    } 
    
    else if (s == "StartDate"sv) {
        e = (OAIItemSortBy::STARTDATE);
    } 
    
    else if (s == "SortName"sv) {
        e = (OAIItemSortBy::SORTNAME);
    } 
    
    else if (s == "Name"sv) {
        e = (OAIItemSortBy::NAME);
    } 
    
    else if (s == "Random"sv) {
        e = (OAIItemSortBy::RANDOM);
    } 
    
    else if (s == "Runtime"sv) {
        e = (OAIItemSortBy::RUNTIME);
    } 
    
    else if (s == "CommunityRating"sv) {
        e = (OAIItemSortBy::COMMUNITYRATING);
    } 
    
    else if (s == "ProductionYear"sv) {
        e = (OAIItemSortBy::PRODUCTIONYEAR);
    } 
    
    else if (s == "PlayCount"sv) {
        e = (OAIItemSortBy::PLAYCOUNT);
    } 
    
    else if (s == "CriticRating"sv) {
        e = (OAIItemSortBy::CRITICRATING);
    } 
    
    else if (s == "IsFolder"sv) {
        e = (OAIItemSortBy::ISFOLDER);
    } 
    
    else if (s == "IsUnplayed"sv) {
        e = (OAIItemSortBy::ISUNPLAYED);
    } 
    
    else if (s == "IsPlayed"sv) {
        e = (OAIItemSortBy::ISPLAYED);
    } 
    
    else if (s == "SeriesSortName"sv) {
        e = (OAIItemSortBy::SERIESSORTNAME);
    } 
    
    else if (s == "VideoBitRate"sv) {
        e = (OAIItemSortBy::VIDEOBITRATE);
    } 
    
    else if (s == "AirTime"sv) {
        e = (OAIItemSortBy::AIRTIME);
    } 
    
    else if (s == "Studio"sv) {
        e = (OAIItemSortBy::STUDIO);
    } 
    
    else if (s == "IsFavoriteOrLiked"sv) {
        e = (OAIItemSortBy::ISFAVORITEORLIKED);
    } 
    
    else if (s == "DateLastContentAdded"sv) {
        e = (OAIItemSortBy::DATELASTCONTENTADDED);
    } 
    
    else if (s == "SeriesDatePlayed"sv) {
        e = (OAIItemSortBy::SERIESDATEPLAYED);
    } 
    
    else if (s == "ParentIndexNumber"sv) {
        e = (OAIItemSortBy::PARENTINDEXNUMBER);
    } 
    
    else if (s == "IndexNumber"sv) {
        e = (OAIItemSortBy::INDEXNUMBER);
    } 
    
    else if (s == "SimilarityScore"sv) {
        e = (OAIItemSortBy::SIMILARITYSCORE);
    } 
    
    else if (s == "SearchScore"sv) {
        e = (OAIItemSortBy::SEARCHSCORE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIItemSortBy";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIJoinGroupRequestDto& o) {
        j["GroupId"sv] = o.GroupId;
}
void from_json(const json_t& j, OAIJoinGroupRequestDto& o) {
    
    j.at("GroupId"sv).get_to(o.GroupId);
}



void to_json(json_t& j, const OAIKeepUntil& e) {
    switch (e)
    {
    
        case OAIKeepUntil::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIKeepUntil::UNTILDELETED:
            j = "UntilDeleted";
            break;
    
        case OAIKeepUntil::UNTILSPACENEEDED:
            j = "UntilSpaceNeeded";
            break;
    
        case OAIKeepUntil::UNTILWATCHED:
            j = "UntilWatched";
            break;
    
        case OAIKeepUntil::UNTILDATE:
            j = "UntilDate";
            break;
    
    }
}
void from_json(const json_t& j, OAIKeepUntil& e) {
    auto s = j.get<std::string>();
    
    if (s == "UntilDeleted"sv) {
        e = (OAIKeepUntil::UNTILDELETED);
    } 
    
    else if (s == "UntilSpaceNeeded"sv) {
        e = (OAIKeepUntil::UNTILSPACENEEDED);
    } 
    
    else if (s == "UntilWatched"sv) {
        e = (OAIKeepUntil::UNTILWATCHED);
    } 
    
    else if (s == "UntilDate"sv) {
        e = (OAIKeepUntil::UNTILDATE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIKeepUntil";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAILibraryChangedMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAILibraryChangedMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAILibraryOptionInfoDto& o) {
        j["Name"sv] = o.Name;
        j["DefaultEnabled"sv] = o.DefaultEnabled;
}
void from_json(const json_t& j, OAILibraryOptionInfoDto& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    
    j.at("DefaultEnabled"sv).get_to(o.DefaultEnabled);
}




void to_json(json_t& j, const OAILibraryOptions& o) {
        j["Enabled"sv] = o.Enabled;
        j["EnablePhotos"sv] = o.EnablePhotos;
        j["EnableRealtimeMonitor"sv] = o.EnableRealtimeMonitor;
        j["EnableLUFSScan"sv] = o.EnableLUFSScan;
        j["EnableChapterImageExtraction"sv] = o.EnableChapterImageExtraction;
        j["ExtractChapterImagesDuringLibraryScan"sv] = o.ExtractChapterImagesDuringLibraryScan;
        j["EnableTrickplayImageExtraction"sv] = o.EnableTrickplayImageExtraction;
        j["ExtractTrickplayImagesDuringLibraryScan"sv] = o.ExtractTrickplayImagesDuringLibraryScan;
        j["PathInfos"sv] = o.PathInfos;
        j["SaveLocalMetadata"sv] = o.SaveLocalMetadata;
        j["EnableInternetProviders"sv] = o.EnableInternetProviders;
        j["EnableAutomaticSeriesGrouping"sv] = o.EnableAutomaticSeriesGrouping;
        j["EnableEmbeddedTitles"sv] = o.EnableEmbeddedTitles;
        j["EnableEmbeddedExtrasTitles"sv] = o.EnableEmbeddedExtrasTitles;
        j["EnableEmbeddedEpisodeInfos"sv] = o.EnableEmbeddedEpisodeInfos;
        j["AutomaticRefreshIntervalDays"sv] = o.AutomaticRefreshIntervalDays;
        j["PreferredMetadataLanguage"sv] = o.PreferredMetadataLanguage;
        j["MetadataCountryCode"sv] = o.MetadataCountryCode;
        j["SeasonZeroDisplayName"sv] = o.SeasonZeroDisplayName;
        j["MetadataSavers"sv] = o.MetadataSavers;
        j["DisabledLocalMetadataReaders"sv] = o.DisabledLocalMetadataReaders;
        j["LocalMetadataReaderOrder"sv] = o.LocalMetadataReaderOrder;
        j["DisabledSubtitleFetchers"sv] = o.DisabledSubtitleFetchers;
        j["SubtitleFetcherOrder"sv] = o.SubtitleFetcherOrder;
        j["SkipSubtitlesIfEmbeddedSubtitlesPresent"sv] = o.SkipSubtitlesIfEmbeddedSubtitlesPresent;
        j["SkipSubtitlesIfAudioTrackMatches"sv] = o.SkipSubtitlesIfAudioTrackMatches;
        j["SubtitleDownloadLanguages"sv] = o.SubtitleDownloadLanguages;
        j["RequirePerfectSubtitleMatch"sv] = o.RequirePerfectSubtitleMatch;
        j["SaveSubtitlesWithMedia"sv] = o.SaveSubtitlesWithMedia;
        j["SaveLyricsWithMedia"sv] = o.SaveLyricsWithMedia;
        j["AutomaticallyAddToCollection"sv] = o.AutomaticallyAddToCollection;
        j["AllowEmbeddedSubtitles"sv] = o.AllowEmbeddedSubtitles;
        j["TypeOptions"sv] = o.TypeOptions;
}
void from_json(const json_t& j, OAILibraryOptions& o) {
    
    j.at("Enabled"sv).get_to(o.Enabled);
    
    j.at("EnablePhotos"sv).get_to(o.EnablePhotos);
    
    j.at("EnableRealtimeMonitor"sv).get_to(o.EnableRealtimeMonitor);
    
    j.at("EnableLUFSScan"sv).get_to(o.EnableLUFSScan);
    
    j.at("EnableChapterImageExtraction"sv).get_to(o.EnableChapterImageExtraction);
    
    j.at("ExtractChapterImagesDuringLibraryScan"sv).get_to(o.ExtractChapterImagesDuringLibraryScan);
    
    j.at("EnableTrickplayImageExtraction"sv).get_to(o.EnableTrickplayImageExtraction);
    
    j.at("ExtractTrickplayImagesDuringLibraryScan"sv).get_to(o.ExtractTrickplayImagesDuringLibraryScan);
    
    j.at("PathInfos"sv).get_to(o.PathInfos);
    
    j.at("SaveLocalMetadata"sv).get_to(o.SaveLocalMetadata);
    
    j.at("EnableInternetProviders"sv).get_to(o.EnableInternetProviders);
    
    j.at("EnableAutomaticSeriesGrouping"sv).get_to(o.EnableAutomaticSeriesGrouping);
    
    j.at("EnableEmbeddedTitles"sv).get_to(o.EnableEmbeddedTitles);
    
    j.at("EnableEmbeddedExtrasTitles"sv).get_to(o.EnableEmbeddedExtrasTitles);
    
    j.at("EnableEmbeddedEpisodeInfos"sv).get_to(o.EnableEmbeddedEpisodeInfos);
    
    j.at("AutomaticRefreshIntervalDays"sv).get_to(o.AutomaticRefreshIntervalDays);
    if(j.contains("PreferredMetadataLanguage"sv))
    j.at("PreferredMetadataLanguage"sv).get_to(o.PreferredMetadataLanguage);
    if(j.contains("MetadataCountryCode"sv))
    j.at("MetadataCountryCode"sv).get_to(o.MetadataCountryCode);
    
    j.at("SeasonZeroDisplayName"sv).get_to(o.SeasonZeroDisplayName);
    if(j.contains("MetadataSavers"sv))
    j.at("MetadataSavers"sv).get_to(o.MetadataSavers);
    
    j.at("DisabledLocalMetadataReaders"sv).get_to(o.DisabledLocalMetadataReaders);
    if(j.contains("LocalMetadataReaderOrder"sv))
    j.at("LocalMetadataReaderOrder"sv).get_to(o.LocalMetadataReaderOrder);
    
    j.at("DisabledSubtitleFetchers"sv).get_to(o.DisabledSubtitleFetchers);
    
    j.at("SubtitleFetcherOrder"sv).get_to(o.SubtitleFetcherOrder);
    
    j.at("SkipSubtitlesIfEmbeddedSubtitlesPresent"sv).get_to(o.SkipSubtitlesIfEmbeddedSubtitlesPresent);
    
    j.at("SkipSubtitlesIfAudioTrackMatches"sv).get_to(o.SkipSubtitlesIfAudioTrackMatches);
    if(j.contains("SubtitleDownloadLanguages"sv))
    j.at("SubtitleDownloadLanguages"sv).get_to(o.SubtitleDownloadLanguages);
    
    j.at("RequirePerfectSubtitleMatch"sv).get_to(o.RequirePerfectSubtitleMatch);
    
    j.at("SaveSubtitlesWithMedia"sv).get_to(o.SaveSubtitlesWithMedia);
    
    j.at("SaveLyricsWithMedia"sv).get_to(o.SaveLyricsWithMedia);
    
    j.at("AutomaticallyAddToCollection"sv).get_to(o.AutomaticallyAddToCollection);
    
    j.at("AllowEmbeddedSubtitles"sv).get_to(o.AllowEmbeddedSubtitles);
    
    j.at("TypeOptions"sv).get_to(o.TypeOptions);
}




void to_json(json_t& j, const OAILibraryOptionsResultDto& o) {
        j["MetadataSavers"sv] = o.MetadataSavers;
        j["MetadataReaders"sv] = o.MetadataReaders;
        j["SubtitleFetchers"sv] = o.SubtitleFetchers;
        j["TypeOptions"sv] = o.TypeOptions;
}
void from_json(const json_t& j, OAILibraryOptionsResultDto& o) {
    
    j.at("MetadataSavers"sv).get_to(o.MetadataSavers);
    
    j.at("MetadataReaders"sv).get_to(o.MetadataReaders);
    
    j.at("SubtitleFetchers"sv).get_to(o.SubtitleFetchers);
    
    j.at("TypeOptions"sv).get_to(o.TypeOptions);
}




void to_json(json_t& j, const OAILibraryTypeOptionsDto& o) {
        j["Type"sv] = o.Type;
        j["MetadataFetchers"sv] = o.MetadataFetchers;
        j["ImageFetchers"sv] = o.ImageFetchers;
        j["SupportedImageTypes"sv] = o.SupportedImageTypes;
        j["DefaultImageOptions"sv] = o.DefaultImageOptions;
}
void from_json(const json_t& j, OAILibraryTypeOptionsDto& o) {
    if(j.contains("Type"sv))
    j.at("Type"sv).get_to(o.Type);
    
    j.at("MetadataFetchers"sv).get_to(o.MetadataFetchers);
    
    j.at("ImageFetchers"sv).get_to(o.ImageFetchers);
    
    j.at("SupportedImageTypes"sv).get_to(o.SupportedImageTypes);
    
    j.at("DefaultImageOptions"sv).get_to(o.DefaultImageOptions);
}




void to_json(json_t& j, const OAILibraryUpdateInfo& o) {
        j["FoldersAddedTo"sv] = o.FoldersAddedTo;
        j["FoldersRemovedFrom"sv] = o.FoldersRemovedFrom;
        j["ItemsAdded"sv] = o.ItemsAdded;
        j["ItemsRemoved"sv] = o.ItemsRemoved;
        j["ItemsUpdated"sv] = o.ItemsUpdated;
        j["CollectionFolders"sv] = o.CollectionFolders;
        j["IsEmpty"sv] = o.IsEmpty;
}
void from_json(const json_t& j, OAILibraryUpdateInfo& o) {
    
    j.at("FoldersAddedTo"sv).get_to(o.FoldersAddedTo);
    
    j.at("FoldersRemovedFrom"sv).get_to(o.FoldersRemovedFrom);
    
    j.at("ItemsAdded"sv).get_to(o.ItemsAdded);
    
    j.at("ItemsRemoved"sv).get_to(o.ItemsRemoved);
    
    j.at("ItemsUpdated"sv).get_to(o.ItemsUpdated);
    
    j.at("CollectionFolders"sv).get_to(o.CollectionFolders);
    
    j.at("IsEmpty"sv).get_to(o.IsEmpty);
}




void to_json(json_t& j, const OAIListingsProviderInfo& o) {
        j["Id"sv] = o.Id;
        j["Type"sv] = o.Type;
        j["Username"sv] = o.Username;
        j["Password"sv] = o.Password;
        j["ListingsId"sv] = o.ListingsId;
        j["ZipCode"sv] = o.ZipCode;
        j["Country"sv] = o.Country;
        j["Path"sv] = o.Path;
        j["EnabledTuners"sv] = o.EnabledTuners;
        j["EnableAllTuners"sv] = o.EnableAllTuners;
        j["NewsCategories"sv] = o.NewsCategories;
        j["SportsCategories"sv] = o.SportsCategories;
        j["KidsCategories"sv] = o.KidsCategories;
        j["MovieCategories"sv] = o.MovieCategories;
        j["ChannelMappings"sv] = o.ChannelMappings;
        j["MoviePrefix"sv] = o.MoviePrefix;
        j["PreferredLanguage"sv] = o.PreferredLanguage;
        j["UserAgent"sv] = o.UserAgent;
}
void from_json(const json_t& j, OAIListingsProviderInfo& o) {
    if(j.contains("Id"sv))
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("Type"sv))
    j.at("Type"sv).get_to(o.Type);
    if(j.contains("Username"sv))
    j.at("Username"sv).get_to(o.Username);
    if(j.contains("Password"sv))
    j.at("Password"sv).get_to(o.Password);
    if(j.contains("ListingsId"sv))
    j.at("ListingsId"sv).get_to(o.ListingsId);
    if(j.contains("ZipCode"sv))
    j.at("ZipCode"sv).get_to(o.ZipCode);
    if(j.contains("Country"sv))
    j.at("Country"sv).get_to(o.Country);
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("EnabledTuners"sv))
    j.at("EnabledTuners"sv).get_to(o.EnabledTuners);
    
    j.at("EnableAllTuners"sv).get_to(o.EnableAllTuners);
    if(j.contains("NewsCategories"sv))
    j.at("NewsCategories"sv).get_to(o.NewsCategories);
    if(j.contains("SportsCategories"sv))
    j.at("SportsCategories"sv).get_to(o.SportsCategories);
    if(j.contains("KidsCategories"sv))
    j.at("KidsCategories"sv).get_to(o.KidsCategories);
    if(j.contains("MovieCategories"sv))
    j.at("MovieCategories"sv).get_to(o.MovieCategories);
    if(j.contains("ChannelMappings"sv))
    j.at("ChannelMappings"sv).get_to(o.ChannelMappings);
    if(j.contains("MoviePrefix"sv))
    j.at("MoviePrefix"sv).get_to(o.MoviePrefix);
    if(j.contains("PreferredLanguage"sv))
    j.at("PreferredLanguage"sv).get_to(o.PreferredLanguage);
    if(j.contains("UserAgent"sv))
    j.at("UserAgent"sv).get_to(o.UserAgent);
}




void to_json(json_t& j, const OAILiveStreamResponse& o) {
        j["MediaSource"sv] = o.MediaSource;
}
void from_json(const json_t& j, OAILiveStreamResponse& o) {
    
    j.at("MediaSource"sv).get_to(o.MediaSource);
}




void to_json(json_t& j, const OAILiveTvInfo& o) {
        j["Services"sv] = o.Services;
        j["IsEnabled"sv] = o.IsEnabled;
        j["EnabledUsers"sv] = o.EnabledUsers;
}
void from_json(const json_t& j, OAILiveTvInfo& o) {
    
    j.at("Services"sv).get_to(o.Services);
    
    j.at("IsEnabled"sv).get_to(o.IsEnabled);
    
    j.at("EnabledUsers"sv).get_to(o.EnabledUsers);
}




void to_json(json_t& j, const OAILiveTvOptions& o) {
        j["GuideDays"sv] = o.GuideDays;
        j["RecordingPath"sv] = o.RecordingPath;
        j["MovieRecordingPath"sv] = o.MovieRecordingPath;
        j["SeriesRecordingPath"sv] = o.SeriesRecordingPath;
        j["EnableRecordingSubfolders"sv] = o.EnableRecordingSubfolders;
        j["EnableOriginalAudioWithEncodedRecordings"sv] = o.EnableOriginalAudioWithEncodedRecordings;
        j["TunerHosts"sv] = o.TunerHosts;
        j["ListingProviders"sv] = o.ListingProviders;
        j["PrePaddingSeconds"sv] = o.PrePaddingSeconds;
        j["PostPaddingSeconds"sv] = o.PostPaddingSeconds;
        j["MediaLocationsCreated"sv] = o.MediaLocationsCreated;
        j["RecordingPostProcessor"sv] = o.RecordingPostProcessor;
        j["RecordingPostProcessorArguments"sv] = o.RecordingPostProcessorArguments;
        j["SaveRecordingNFO"sv] = o.SaveRecordingNFO;
        j["SaveRecordingImages"sv] = o.SaveRecordingImages;
}
void from_json(const json_t& j, OAILiveTvOptions& o) {
    if(j.contains("GuideDays"sv))
    j.at("GuideDays"sv).get_to(o.GuideDays);
    if(j.contains("RecordingPath"sv))
    j.at("RecordingPath"sv).get_to(o.RecordingPath);
    if(j.contains("MovieRecordingPath"sv))
    j.at("MovieRecordingPath"sv).get_to(o.MovieRecordingPath);
    if(j.contains("SeriesRecordingPath"sv))
    j.at("SeriesRecordingPath"sv).get_to(o.SeriesRecordingPath);
    
    j.at("EnableRecordingSubfolders"sv).get_to(o.EnableRecordingSubfolders);
    
    j.at("EnableOriginalAudioWithEncodedRecordings"sv).get_to(o.EnableOriginalAudioWithEncodedRecordings);
    if(j.contains("TunerHosts"sv))
    j.at("TunerHosts"sv).get_to(o.TunerHosts);
    if(j.contains("ListingProviders"sv))
    j.at("ListingProviders"sv).get_to(o.ListingProviders);
    
    j.at("PrePaddingSeconds"sv).get_to(o.PrePaddingSeconds);
    
    j.at("PostPaddingSeconds"sv).get_to(o.PostPaddingSeconds);
    if(j.contains("MediaLocationsCreated"sv))
    j.at("MediaLocationsCreated"sv).get_to(o.MediaLocationsCreated);
    if(j.contains("RecordingPostProcessor"sv))
    j.at("RecordingPostProcessor"sv).get_to(o.RecordingPostProcessor);
    if(j.contains("RecordingPostProcessorArguments"sv))
    j.at("RecordingPostProcessorArguments"sv).get_to(o.RecordingPostProcessorArguments);
    
    j.at("SaveRecordingNFO"sv).get_to(o.SaveRecordingNFO);
    
    j.at("SaveRecordingImages"sv).get_to(o.SaveRecordingImages);
}




void to_json(json_t& j, const OAILiveTvServiceInfo& o) {
        j["Name"sv] = o.Name;
        j["HomePageUrl"sv] = o.HomePageUrl;
        j["Status"sv] = o.Status;
        j["StatusMessage"sv] = o.StatusMessage;
        j["Version"sv] = o.Version;
        j["HasUpdateAvailable"sv] = o.HasUpdateAvailable;
        j["IsVisible"sv] = o.IsVisible;
        j["Tuners"sv] = o.Tuners;
}
void from_json(const json_t& j, OAILiveTvServiceInfo& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("HomePageUrl"sv))
    j.at("HomePageUrl"sv).get_to(o.HomePageUrl);
    
    j.at("Status"sv).get_to(o.Status);
    if(j.contains("StatusMessage"sv))
    j.at("StatusMessage"sv).get_to(o.StatusMessage);
    if(j.contains("Version"sv))
    j.at("Version"sv).get_to(o.Version);
    
    j.at("HasUpdateAvailable"sv).get_to(o.HasUpdateAvailable);
    
    j.at("IsVisible"sv).get_to(o.IsVisible);
    if(j.contains("Tuners"sv))
    j.at("Tuners"sv).get_to(o.Tuners);
}



void to_json(json_t& j, const OAILiveTvServiceStatus& e) {
    switch (e)
    {
    
        case OAILiveTvServiceStatus::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAILiveTvServiceStatus::OK:
            j = "Ok";
            break;
    
        case OAILiveTvServiceStatus::UNAVAILABLE:
            j = "Unavailable";
            break;
    
    }
}
void from_json(const json_t& j, OAILiveTvServiceStatus& e) {
    auto s = j.get<std::string>();
    
    if (s == "Ok"sv) {
        e = (OAILiveTvServiceStatus::OK);
    } 
    
    else if (s == "Unavailable"sv) {
        e = (OAILiveTvServiceStatus::UNAVAILABLE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAILiveTvServiceStatus";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAILocalizationOption& o) {
        j["Name"sv] = o.Name;
        j["Value"sv] = o.Value;
}
void from_json(const json_t& j, OAILocalizationOption& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Value"sv))
    j.at("Value"sv).get_to(o.Value);
}



void to_json(json_t& j, const OAILocationType& e) {
    switch (e)
    {
    
        case OAILocationType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAILocationType::FILESYSTEM:
            j = "FileSystem";
            break;
    
        case OAILocationType::REMOTE:
            j = "Remote";
            break;
    
        case OAILocationType::VIRTUAL:
            j = "Virtual";
            break;
    
        case OAILocationType::OFFLINE:
            j = "Offline";
            break;
    
    }
}
void from_json(const json_t& j, OAILocationType& e) {
    auto s = j.get<std::string>();
    
    if (s == "FileSystem"sv) {
        e = (OAILocationType::FILESYSTEM);
    } 
    
    else if (s == "Remote"sv) {
        e = (OAILocationType::REMOTE);
    } 
    
    else if (s == "Virtual"sv) {
        e = (OAILocationType::VIRTUAL);
    } 
    
    else if (s == "Offline"sv) {
        e = (OAILocationType::OFFLINE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAILocationType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAILogFile& o) {
        j["DateCreated"sv] = o.DateCreated;
        j["DateModified"sv] = o.DateModified;
        j["Size"sv] = o.Size;
        j["Name"sv] = o.Name;
}
void from_json(const json_t& j, OAILogFile& o) {
    
    j.at("DateCreated"sv).get_to(o.DateCreated);
    
    j.at("DateModified"sv).get_to(o.DateModified);
    
    j.at("Size"sv).get_to(o.Size);
    
    j.at("Name"sv).get_to(o.Name);
}



void to_json(json_t& j, const OAILogLevel& e) {
    switch (e)
    {
    
        case OAILogLevel::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAILogLevel::TRACE:
            j = "Trace";
            break;
    
        case OAILogLevel::DEBUG:
            j = "Debug";
            break;
    
        case OAILogLevel::INFORMATION:
            j = "Information";
            break;
    
        case OAILogLevel::WARNING:
            j = "Warning";
            break;
    
        case OAILogLevel::ERROR:
            j = "Error";
            break;
    
        case OAILogLevel::CRITICAL:
            j = "Critical";
            break;
    
        case OAILogLevel::NONE:
            j = "None";
            break;
    
    }
}
void from_json(const json_t& j, OAILogLevel& e) {
    auto s = j.get<std::string>();
    
    if (s == "Trace"sv) {
        e = (OAILogLevel::TRACE);
    } 
    
    else if (s == "Debug"sv) {
        e = (OAILogLevel::DEBUG);
    } 
    
    else if (s == "Information"sv) {
        e = (OAILogLevel::INFORMATION);
    } 
    
    else if (s == "Warning"sv) {
        e = (OAILogLevel::WARNING);
    } 
    
    else if (s == "Error"sv) {
        e = (OAILogLevel::ERROR);
    } 
    
    else if (s == "Critical"sv) {
        e = (OAILogLevel::CRITICAL);
    } 
    
    else if (s == "None"sv) {
        e = (OAILogLevel::NONE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAILogLevel";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAILyricDto& o) {
        j["Metadata"sv] = o.Metadata;
        j["Lyrics"sv] = o.Lyrics;
}
void from_json(const json_t& j, OAILyricDto& o) {
    
    j.at("Metadata"sv).get_to(o.Metadata);
    
    j.at("Lyrics"sv).get_to(o.Lyrics);
}




void to_json(json_t& j, const OAILyricLine& o) {
        j["Text"sv] = o.Text;
        j["Start"sv] = o.Start;
}
void from_json(const json_t& j, OAILyricLine& o) {
    
    j.at("Text"sv).get_to(o.Text);
    if(j.contains("Start"sv))
    j.at("Start"sv).get_to(o.Start);
}




void to_json(json_t& j, const OAILyricMetadata& o) {
        j["Artist"sv] = o.Artist;
        j["Album"sv] = o.Album;
        j["Title"sv] = o.Title;
        j["Author"sv] = o.Author;
        j["Length"sv] = o.Length;
        j["By"sv] = o.By;
        j["Offset"sv] = o.Offset;
        j["Creator"sv] = o.Creator;
        j["Version"sv] = o.Version;
        j["IsSynced"sv] = o.IsSynced;
}
void from_json(const json_t& j, OAILyricMetadata& o) {
    if(j.contains("Artist"sv))
    j.at("Artist"sv).get_to(o.Artist);
    if(j.contains("Album"sv))
    j.at("Album"sv).get_to(o.Album);
    if(j.contains("Title"sv))
    j.at("Title"sv).get_to(o.Title);
    if(j.contains("Author"sv))
    j.at("Author"sv).get_to(o.Author);
    if(j.contains("Length"sv))
    j.at("Length"sv).get_to(o.Length);
    if(j.contains("By"sv))
    j.at("By"sv).get_to(o.By);
    if(j.contains("Offset"sv))
    j.at("Offset"sv).get_to(o.Offset);
    if(j.contains("Creator"sv))
    j.at("Creator"sv).get_to(o.Creator);
    if(j.contains("Version"sv))
    j.at("Version"sv).get_to(o.Version);
    if(j.contains("IsSynced"sv))
    j.at("IsSynced"sv).get_to(o.IsSynced);
}




void to_json(json_t& j, const OAIMediaAttachment& o) {
        j["Codec"sv] = o.Codec;
        j["CodecTag"sv] = o.CodecTag;
        j["Comment"sv] = o.Comment;
        j["Index"sv] = o.Index;
        j["FileName"sv] = o.FileName;
        j["MimeType"sv] = o.MimeType;
        j["DeliveryUrl"sv] = o.DeliveryUrl;
}
void from_json(const json_t& j, OAIMediaAttachment& o) {
    if(j.contains("Codec"sv))
    j.at("Codec"sv).get_to(o.Codec);
    if(j.contains("CodecTag"sv))
    j.at("CodecTag"sv).get_to(o.CodecTag);
    if(j.contains("Comment"sv))
    j.at("Comment"sv).get_to(o.Comment);
    
    j.at("Index"sv).get_to(o.Index);
    if(j.contains("FileName"sv))
    j.at("FileName"sv).get_to(o.FileName);
    if(j.contains("MimeType"sv))
    j.at("MimeType"sv).get_to(o.MimeType);
    if(j.contains("DeliveryUrl"sv))
    j.at("DeliveryUrl"sv).get_to(o.DeliveryUrl);
}




void to_json(json_t& j, const OAIMediaPathDto& o) {
        j["Name"sv] = o.Name;
        j["Path"sv] = o.Path;
        j["PathInfo"sv] = o.PathInfo;
}
void from_json(const json_t& j, OAIMediaPathDto& o) {
    
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("PathInfo"sv))
    j.at("PathInfo"sv).get_to(o.PathInfo);
}




void to_json(json_t& j, const OAIMediaPathInfo& o) {
        j["Path"sv] = o.Path;
        j["NetworkPath"sv] = o.NetworkPath;
}
void from_json(const json_t& j, OAIMediaPathInfo& o) {
    
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("NetworkPath"sv))
    j.at("NetworkPath"sv).get_to(o.NetworkPath);
}



void to_json(json_t& j, const OAIMediaProtocol& e) {
    switch (e)
    {
    
        case OAIMediaProtocol::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIMediaProtocol::FILE:
            j = "File";
            break;
    
        case OAIMediaProtocol::HTTP:
            j = "Http";
            break;
    
        case OAIMediaProtocol::RTMP:
            j = "Rtmp";
            break;
    
        case OAIMediaProtocol::RTSP:
            j = "Rtsp";
            break;
    
        case OAIMediaProtocol::UDP:
            j = "Udp";
            break;
    
        case OAIMediaProtocol::RTP:
            j = "Rtp";
            break;
    
        case OAIMediaProtocol::FTP:
            j = "Ftp";
            break;
    
    }
}
void from_json(const json_t& j, OAIMediaProtocol& e) {
    auto s = j.get<std::string>();
    
    if (s == "File"sv) {
        e = (OAIMediaProtocol::FILE);
    } 
    
    else if (s == "Http"sv) {
        e = (OAIMediaProtocol::HTTP);
    } 
    
    else if (s == "Rtmp"sv) {
        e = (OAIMediaProtocol::RTMP);
    } 
    
    else if (s == "Rtsp"sv) {
        e = (OAIMediaProtocol::RTSP);
    } 
    
    else if (s == "Udp"sv) {
        e = (OAIMediaProtocol::UDP);
    } 
    
    else if (s == "Rtp"sv) {
        e = (OAIMediaProtocol::RTP);
    } 
    
    else if (s == "Ftp"sv) {
        e = (OAIMediaProtocol::FTP);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIMediaProtocol";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIMediaSourceInfo& o) {
        j["Protocol"sv] = o.Protocol;
        j["Id"sv] = o.Id;
        j["Path"sv] = o.Path;
        j["EncoderPath"sv] = o.EncoderPath;
        j["EncoderProtocol"sv] = o.EncoderProtocol;
        j["Type"sv] = o.Type;
        j["Container"sv] = o.Container;
        j["Size"sv] = o.Size;
        j["Name"sv] = o.Name;
        j["IsRemote"sv] = o.IsRemote;
        j["ETag"sv] = o.ETag;
        j["RunTimeTicks"sv] = o.RunTimeTicks;
        j["ReadAtNativeFramerate"sv] = o.ReadAtNativeFramerate;
        j["IgnoreDts"sv] = o.IgnoreDts;
        j["IgnoreIndex"sv] = o.IgnoreIndex;
        j["GenPtsInput"sv] = o.GenPtsInput;
        j["SupportsTranscoding"sv] = o.SupportsTranscoding;
        j["SupportsDirectStream"sv] = o.SupportsDirectStream;
        j["SupportsDirectPlay"sv] = o.SupportsDirectPlay;
        j["IsInfiniteStream"sv] = o.IsInfiniteStream;
        j["RequiresOpening"sv] = o.RequiresOpening;
        j["OpenToken"sv] = o.OpenToken;
        j["RequiresClosing"sv] = o.RequiresClosing;
        j["LiveStreamId"sv] = o.LiveStreamId;
        j["BufferMs"sv] = o.BufferMs;
        j["RequiresLooping"sv] = o.RequiresLooping;
        j["SupportsProbing"sv] = o.SupportsProbing;
        j["VideoType"sv] = o.VideoType;
        j["IsoType"sv] = o.IsoType;
        j["Video3DFormat"sv] = o.Video3DFormat;
        j["MediaStreams"sv] = o.MediaStreams;
        j["MediaAttachments"sv] = o.MediaAttachments;
        j["Formats"sv] = o.Formats;
        j["Bitrate"sv] = o.Bitrate;
        j["Timestamp"sv] = o.Timestamp;
        j["RequiredHttpHeaders"sv] = o.RequiredHttpHeaders;
        j["TranscodingUrl"sv] = o.TranscodingUrl;
        j["TranscodingSubProtocol"sv] = o.TranscodingSubProtocol;
        j["TranscodingContainer"sv] = o.TranscodingContainer;
        j["AnalyzeDurationMs"sv] = o.AnalyzeDurationMs;
        j["DefaultAudioStreamIndex"sv] = o.DefaultAudioStreamIndex;
        j["DefaultSubtitleStreamIndex"sv] = o.DefaultSubtitleStreamIndex;
}
void from_json(const json_t& j, OAIMediaSourceInfo& o) {
    
    j.at("Protocol"sv).get_to(o.Protocol);
    if(j.contains("Id"sv))
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("EncoderPath"sv))
    j.at("EncoderPath"sv).get_to(o.EncoderPath);
    if(j.contains("EncoderProtocol"sv))
    j.at("EncoderProtocol"sv).get_to(o.EncoderProtocol);
    
    j.at("Type"sv).get_to(o.Type);
    if(j.contains("Container"sv))
    j.at("Container"sv).get_to(o.Container);
    if(j.contains("Size"sv))
    j.at("Size"sv).get_to(o.Size);
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    
    j.at("IsRemote"sv).get_to(o.IsRemote);
    if(j.contains("ETag"sv))
    j.at("ETag"sv).get_to(o.ETag);
    if(j.contains("RunTimeTicks"sv))
    j.at("RunTimeTicks"sv).get_to(o.RunTimeTicks);
    
    j.at("ReadAtNativeFramerate"sv).get_to(o.ReadAtNativeFramerate);
    
    j.at("IgnoreDts"sv).get_to(o.IgnoreDts);
    
    j.at("IgnoreIndex"sv).get_to(o.IgnoreIndex);
    
    j.at("GenPtsInput"sv).get_to(o.GenPtsInput);
    
    j.at("SupportsTranscoding"sv).get_to(o.SupportsTranscoding);
    
    j.at("SupportsDirectStream"sv).get_to(o.SupportsDirectStream);
    
    j.at("SupportsDirectPlay"sv).get_to(o.SupportsDirectPlay);
    
    j.at("IsInfiniteStream"sv).get_to(o.IsInfiniteStream);
    
    j.at("RequiresOpening"sv).get_to(o.RequiresOpening);
    if(j.contains("OpenToken"sv))
    j.at("OpenToken"sv).get_to(o.OpenToken);
    
    j.at("RequiresClosing"sv).get_to(o.RequiresClosing);
    if(j.contains("LiveStreamId"sv))
    j.at("LiveStreamId"sv).get_to(o.LiveStreamId);
    if(j.contains("BufferMs"sv))
    j.at("BufferMs"sv).get_to(o.BufferMs);
    
    j.at("RequiresLooping"sv).get_to(o.RequiresLooping);
    
    j.at("SupportsProbing"sv).get_to(o.SupportsProbing);
    if(j.contains("VideoType"sv))
    j.at("VideoType"sv).get_to(o.VideoType);
    if(j.contains("IsoType"sv))
    j.at("IsoType"sv).get_to(o.IsoType);
    if(j.contains("Video3DFormat"sv))
    j.at("Video3DFormat"sv).get_to(o.Video3DFormat);
    if(j.contains("MediaStreams"sv))
    j.at("MediaStreams"sv).get_to(o.MediaStreams);
    if(j.contains("MediaAttachments"sv))
    j.at("MediaAttachments"sv).get_to(o.MediaAttachments);
    if(j.contains("Formats"sv))
    j.at("Formats"sv).get_to(o.Formats);
    if(j.contains("Bitrate"sv))
    j.at("Bitrate"sv).get_to(o.Bitrate);
    if(j.contains("Timestamp"sv))
    j.at("Timestamp"sv).get_to(o.Timestamp);
    if(j.contains("RequiredHttpHeaders"sv))
    j.at("RequiredHttpHeaders"sv).get_to(o.RequiredHttpHeaders);
    if(j.contains("TranscodingUrl"sv))
    j.at("TranscodingUrl"sv).get_to(o.TranscodingUrl);
    
    j.at("TranscodingSubProtocol"sv).get_to(o.TranscodingSubProtocol);
    if(j.contains("TranscodingContainer"sv))
    j.at("TranscodingContainer"sv).get_to(o.TranscodingContainer);
    if(j.contains("AnalyzeDurationMs"sv))
    j.at("AnalyzeDurationMs"sv).get_to(o.AnalyzeDurationMs);
    if(j.contains("DefaultAudioStreamIndex"sv))
    j.at("DefaultAudioStreamIndex"sv).get_to(o.DefaultAudioStreamIndex);
    if(j.contains("DefaultSubtitleStreamIndex"sv))
    j.at("DefaultSubtitleStreamIndex"sv).get_to(o.DefaultSubtitleStreamIndex);
}



void to_json(json_t& j, const OAIMediaSourceType& e) {
    switch (e)
    {
    
        case OAIMediaSourceType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIMediaSourceType::DEFAULT:
            j = "Default";
            break;
    
        case OAIMediaSourceType::GROUPING:
            j = "Grouping";
            break;
    
        case OAIMediaSourceType::PLACEHOLDER:
            j = "Placeholder";
            break;
    
    }
}
void from_json(const json_t& j, OAIMediaSourceType& e) {
    auto s = j.get<std::string>();
    
    if (s == "Default"sv) {
        e = (OAIMediaSourceType::DEFAULT);
    } 
    
    else if (s == "Grouping"sv) {
        e = (OAIMediaSourceType::GROUPING);
    } 
    
    else if (s == "Placeholder"sv) {
        e = (OAIMediaSourceType::PLACEHOLDER);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIMediaSourceType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIMediaStream& o) {
        j["Codec"sv] = o.Codec;
        j["CodecTag"sv] = o.CodecTag;
        j["Language"sv] = o.Language;
        j["ColorRange"sv] = o.ColorRange;
        j["ColorSpace"sv] = o.ColorSpace;
        j["ColorTransfer"sv] = o.ColorTransfer;
        j["ColorPrimaries"sv] = o.ColorPrimaries;
        j["DvVersionMajor"sv] = o.DvVersionMajor;
        j["DvVersionMinor"sv] = o.DvVersionMinor;
        j["DvProfile"sv] = o.DvProfile;
        j["DvLevel"sv] = o.DvLevel;
        j["RpuPresentFlag"sv] = o.RpuPresentFlag;
        j["ElPresentFlag"sv] = o.ElPresentFlag;
        j["BlPresentFlag"sv] = o.BlPresentFlag;
        j["DvBlSignalCompatibilityId"sv] = o.DvBlSignalCompatibilityId;
        j["Comment"sv] = o.Comment;
        j["TimeBase"sv] = o.TimeBase;
        j["CodecTimeBase"sv] = o.CodecTimeBase;
        j["Title"sv] = o.Title;
        j["VideoRange"sv] = o.VideoRange;
        j["VideoRangeType"sv] = o.VideoRangeType;
        j["VideoDoViTitle"sv] = o.VideoDoViTitle;
        j["AudioSpatialFormat"sv] = o.AudioSpatialFormat;
        j["LocalizedUndefined"sv] = o.LocalizedUndefined;
        j["LocalizedDefault"sv] = o.LocalizedDefault;
        j["LocalizedForced"sv] = o.LocalizedForced;
        j["LocalizedExternal"sv] = o.LocalizedExternal;
        j["LocalizedHearingImpaired"sv] = o.LocalizedHearingImpaired;
        j["DisplayTitle"sv] = o.DisplayTitle;
        j["NalLengthSize"sv] = o.NalLengthSize;
        j["IsInterlaced"sv] = o.IsInterlaced;
        j["IsAVC"sv] = o.IsAVC;
        j["ChannelLayout"sv] = o.ChannelLayout;
        j["BitRate"sv] = o.BitRate;
        j["BitDepth"sv] = o.BitDepth;
        j["RefFrames"sv] = o.RefFrames;
        j["PacketLength"sv] = o.PacketLength;
        j["Channels"sv] = o.Channels;
        j["SampleRate"sv] = o.SampleRate;
        j["IsDefault"sv] = o.IsDefault;
        j["IsForced"sv] = o.IsForced;
        j["IsHearingImpaired"sv] = o.IsHearingImpaired;
        j["Height"sv] = o.Height;
        j["Width"sv] = o.Width;
        j["AverageFrameRate"sv] = o.AverageFrameRate;
        j["RealFrameRate"sv] = o.RealFrameRate;
        j["Profile"sv] = o.Profile;
        j["Type"sv] = o.Type;
        j["AspectRatio"sv] = o.AspectRatio;
        j["Index"sv] = o.Index;
        j["Score"sv] = o.Score;
        j["IsExternal"sv] = o.IsExternal;
        j["DeliveryMethod"sv] = o.DeliveryMethod;
        j["DeliveryUrl"sv] = o.DeliveryUrl;
        j["IsExternalUrl"sv] = o.IsExternalUrl;
        j["IsTextSubtitleStream"sv] = o.IsTextSubtitleStream;
        j["SupportsExternalStream"sv] = o.SupportsExternalStream;
        j["Path"sv] = o.Path;
        j["PixelFormat"sv] = o.PixelFormat;
        j["Level"sv] = o.Level;
        j["IsAnamorphic"sv] = o.IsAnamorphic;
}
void from_json(const json_t& j, OAIMediaStream& o) {
    if(j.contains("Codec"sv))
    j.at("Codec"sv).get_to(o.Codec);
    if(j.contains("CodecTag"sv))
    j.at("CodecTag"sv).get_to(o.CodecTag);
    if(j.contains("Language"sv))
    j.at("Language"sv).get_to(o.Language);
    if(j.contains("ColorRange"sv))
    j.at("ColorRange"sv).get_to(o.ColorRange);
    if(j.contains("ColorSpace"sv))
    j.at("ColorSpace"sv).get_to(o.ColorSpace);
    if(j.contains("ColorTransfer"sv))
    j.at("ColorTransfer"sv).get_to(o.ColorTransfer);
    if(j.contains("ColorPrimaries"sv))
    j.at("ColorPrimaries"sv).get_to(o.ColorPrimaries);
    if(j.contains("DvVersionMajor"sv))
    j.at("DvVersionMajor"sv).get_to(o.DvVersionMajor);
    if(j.contains("DvVersionMinor"sv))
    j.at("DvVersionMinor"sv).get_to(o.DvVersionMinor);
    if(j.contains("DvProfile"sv))
    j.at("DvProfile"sv).get_to(o.DvProfile);
    if(j.contains("DvLevel"sv))
    j.at("DvLevel"sv).get_to(o.DvLevel);
    if(j.contains("RpuPresentFlag"sv))
    j.at("RpuPresentFlag"sv).get_to(o.RpuPresentFlag);
    if(j.contains("ElPresentFlag"sv))
    j.at("ElPresentFlag"sv).get_to(o.ElPresentFlag);
    if(j.contains("BlPresentFlag"sv))
    j.at("BlPresentFlag"sv).get_to(o.BlPresentFlag);
    if(j.contains("DvBlSignalCompatibilityId"sv))
    j.at("DvBlSignalCompatibilityId"sv).get_to(o.DvBlSignalCompatibilityId);
    if(j.contains("Comment"sv))
    j.at("Comment"sv).get_to(o.Comment);
    if(j.contains("TimeBase"sv))
    j.at("TimeBase"sv).get_to(o.TimeBase);
    if(j.contains("CodecTimeBase"sv))
    j.at("CodecTimeBase"sv).get_to(o.CodecTimeBase);
    if(j.contains("Title"sv))
    j.at("Title"sv).get_to(o.Title);
    
    j.at("VideoRange"sv).get_to(o.VideoRange);
    
    j.at("VideoRangeType"sv).get_to(o.VideoRangeType);
    if(j.contains("VideoDoViTitle"sv))
    j.at("VideoDoViTitle"sv).get_to(o.VideoDoViTitle);
    
    j.at("AudioSpatialFormat"sv).get_to(o.AudioSpatialFormat);
    if(j.contains("LocalizedUndefined"sv))
    j.at("LocalizedUndefined"sv).get_to(o.LocalizedUndefined);
    if(j.contains("LocalizedDefault"sv))
    j.at("LocalizedDefault"sv).get_to(o.LocalizedDefault);
    if(j.contains("LocalizedForced"sv))
    j.at("LocalizedForced"sv).get_to(o.LocalizedForced);
    if(j.contains("LocalizedExternal"sv))
    j.at("LocalizedExternal"sv).get_to(o.LocalizedExternal);
    if(j.contains("LocalizedHearingImpaired"sv))
    j.at("LocalizedHearingImpaired"sv).get_to(o.LocalizedHearingImpaired);
    if(j.contains("DisplayTitle"sv))
    j.at("DisplayTitle"sv).get_to(o.DisplayTitle);
    if(j.contains("NalLengthSize"sv))
    j.at("NalLengthSize"sv).get_to(o.NalLengthSize);
    
    j.at("IsInterlaced"sv).get_to(o.IsInterlaced);
    if(j.contains("IsAVC"sv))
    j.at("IsAVC"sv).get_to(o.IsAVC);
    if(j.contains("ChannelLayout"sv))
    j.at("ChannelLayout"sv).get_to(o.ChannelLayout);
    if(j.contains("BitRate"sv))
    j.at("BitRate"sv).get_to(o.BitRate);
    if(j.contains("BitDepth"sv))
    j.at("BitDepth"sv).get_to(o.BitDepth);
    if(j.contains("RefFrames"sv))
    j.at("RefFrames"sv).get_to(o.RefFrames);
    if(j.contains("PacketLength"sv))
    j.at("PacketLength"sv).get_to(o.PacketLength);
    if(j.contains("Channels"sv))
    j.at("Channels"sv).get_to(o.Channels);
    if(j.contains("SampleRate"sv))
    j.at("SampleRate"sv).get_to(o.SampleRate);
    
    j.at("IsDefault"sv).get_to(o.IsDefault);
    
    j.at("IsForced"sv).get_to(o.IsForced);
    
    j.at("IsHearingImpaired"sv).get_to(o.IsHearingImpaired);
    if(j.contains("Height"sv))
    j.at("Height"sv).get_to(o.Height);
    if(j.contains("Width"sv))
    j.at("Width"sv).get_to(o.Width);
    if(j.contains("AverageFrameRate"sv))
    j.at("AverageFrameRate"sv).get_to(o.AverageFrameRate);
    if(j.contains("RealFrameRate"sv))
    j.at("RealFrameRate"sv).get_to(o.RealFrameRate);
    if(j.contains("Profile"sv))
    j.at("Profile"sv).get_to(o.Profile);
    
    j.at("Type"sv).get_to(o.Type);
    if(j.contains("AspectRatio"sv))
    j.at("AspectRatio"sv).get_to(o.AspectRatio);
    
    j.at("Index"sv).get_to(o.Index);
    if(j.contains("Score"sv))
    j.at("Score"sv).get_to(o.Score);
    
    j.at("IsExternal"sv).get_to(o.IsExternal);
    if(j.contains("DeliveryMethod"sv))
    j.at("DeliveryMethod"sv).get_to(o.DeliveryMethod);
    if(j.contains("DeliveryUrl"sv))
    j.at("DeliveryUrl"sv).get_to(o.DeliveryUrl);
    if(j.contains("IsExternalUrl"sv))
    j.at("IsExternalUrl"sv).get_to(o.IsExternalUrl);
    
    j.at("IsTextSubtitleStream"sv).get_to(o.IsTextSubtitleStream);
    
    j.at("SupportsExternalStream"sv).get_to(o.SupportsExternalStream);
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("PixelFormat"sv))
    j.at("PixelFormat"sv).get_to(o.PixelFormat);
    if(j.contains("Level"sv))
    j.at("Level"sv).get_to(o.Level);
    if(j.contains("IsAnamorphic"sv))
    j.at("IsAnamorphic"sv).get_to(o.IsAnamorphic);
}



void to_json(json_t& j, const OAIMediaStreamProtocol& e) {
    switch (e)
    {
    
        case OAIMediaStreamProtocol::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIMediaStreamProtocol::HTTP:
            j = "http";
            break;
    
        case OAIMediaStreamProtocol::HLS:
            j = "hls";
            break;
    
    }
}
void from_json(const json_t& j, OAIMediaStreamProtocol& e) {
    auto s = j.get<std::string>();
    
    if (s == "http"sv) {
        e = (OAIMediaStreamProtocol::HTTP);
    } 
    
    else if (s == "hls"sv) {
        e = (OAIMediaStreamProtocol::HLS);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIMediaStreamProtocol";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIMediaStreamType& e) {
    switch (e)
    {
    
        case OAIMediaStreamType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIMediaStreamType::AUDIO:
            j = "Audio";
            break;
    
        case OAIMediaStreamType::VIDEO:
            j = "Video";
            break;
    
        case OAIMediaStreamType::SUBTITLE:
            j = "Subtitle";
            break;
    
        case OAIMediaStreamType::EMBEDDEDIMAGE:
            j = "EmbeddedImage";
            break;
    
        case OAIMediaStreamType::DATA:
            j = "Data";
            break;
    
        case OAIMediaStreamType::LYRIC:
            j = "Lyric";
            break;
    
    }
}
void from_json(const json_t& j, OAIMediaStreamType& e) {
    auto s = j.get<std::string>();
    
    if (s == "Audio"sv) {
        e = (OAIMediaStreamType::AUDIO);
    } 
    
    else if (s == "Video"sv) {
        e = (OAIMediaStreamType::VIDEO);
    } 
    
    else if (s == "Subtitle"sv) {
        e = (OAIMediaStreamType::SUBTITLE);
    } 
    
    else if (s == "EmbeddedImage"sv) {
        e = (OAIMediaStreamType::EMBEDDEDIMAGE);
    } 
    
    else if (s == "Data"sv) {
        e = (OAIMediaStreamType::DATA);
    } 
    
    else if (s == "Lyric"sv) {
        e = (OAIMediaStreamType::LYRIC);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIMediaStreamType";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIMediaType& e) {
    switch (e)
    {
    
        case OAIMediaType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIMediaType::UNKNOWN:
            j = "Unknown";
            break;
    
        case OAIMediaType::VIDEO:
            j = "Video";
            break;
    
        case OAIMediaType::AUDIO:
            j = "Audio";
            break;
    
        case OAIMediaType::PHOTO:
            j = "Photo";
            break;
    
        case OAIMediaType::BOOK:
            j = "Book";
            break;
    
    }
}
void from_json(const json_t& j, OAIMediaType& e) {
    auto s = j.get<std::string>();
    
    if (s == "Unknown"sv) {
        e = (OAIMediaType::UNKNOWN);
    } 
    
    else if (s == "Video"sv) {
        e = (OAIMediaType::VIDEO);
    } 
    
    else if (s == "Audio"sv) {
        e = (OAIMediaType::AUDIO);
    } 
    
    else if (s == "Photo"sv) {
        e = (OAIMediaType::PHOTO);
    } 
    
    else if (s == "Book"sv) {
        e = (OAIMediaType::BOOK);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIMediaType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIMediaUpdateInfoDto& o) {
        j["Updates"sv] = o.Updates;
}
void from_json(const json_t& j, OAIMediaUpdateInfoDto& o) {
    
    j.at("Updates"sv).get_to(o.Updates);
}




void to_json(json_t& j, const OAIMediaUpdateInfoPathDto& o) {
        j["Path"sv] = o.Path;
        j["UpdateType"sv] = o.UpdateType;
}
void from_json(const json_t& j, OAIMediaUpdateInfoPathDto& o) {
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("UpdateType"sv))
    j.at("UpdateType"sv).get_to(o.UpdateType);
}




void to_json(json_t& j, const OAIMediaUrl& o) {
        j["Url"sv] = o.Url;
        j["Name"sv] = o.Name;
}
void from_json(const json_t& j, OAIMediaUrl& o) {
    if(j.contains("Url"sv))
    j.at("Url"sv).get_to(o.Url);
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
}




void to_json(json_t& j, const OAIMessageCommand& o) {
        j["Header"sv] = o.Header;
        j["Text"sv] = o.Text;
        j["TimeoutMs"sv] = o.TimeoutMs;
}
void from_json(const json_t& j, OAIMessageCommand& o) {
    if(j.contains("Header"sv))
    j.at("Header"sv).get_to(o.Header);
    
    j.at("Text"sv).get_to(o.Text);
    if(j.contains("TimeoutMs"sv))
    j.at("TimeoutMs"sv).get_to(o.TimeoutMs);
}




void to_json(json_t& j, const OAIMetadataConfiguration& o) {
        j["UseFileCreationTimeForDateAdded"sv] = o.UseFileCreationTimeForDateAdded;
}
void from_json(const json_t& j, OAIMetadataConfiguration& o) {
    
    j.at("UseFileCreationTimeForDateAdded"sv).get_to(o.UseFileCreationTimeForDateAdded);
}




void to_json(json_t& j, const OAIMetadataEditorInfo& o) {
        j["ParentalRatingOptions"sv] = o.ParentalRatingOptions;
        j["Countries"sv] = o.Countries;
        j["Cultures"sv] = o.Cultures;
        j["ExternalIdInfos"sv] = o.ExternalIdInfos;
        j["ContentType"sv] = o.ContentType;
        j["ContentTypeOptions"sv] = o.ContentTypeOptions;
}
void from_json(const json_t& j, OAIMetadataEditorInfo& o) {
    
    j.at("ParentalRatingOptions"sv).get_to(o.ParentalRatingOptions);
    
    j.at("Countries"sv).get_to(o.Countries);
    
    j.at("Cultures"sv).get_to(o.Cultures);
    
    j.at("ExternalIdInfos"sv).get_to(o.ExternalIdInfos);
    if(j.contains("ContentType"sv))
    j.at("ContentType"sv).get_to(o.ContentType);
    
    j.at("ContentTypeOptions"sv).get_to(o.ContentTypeOptions);
}



void to_json(json_t& j, const OAIMetadataField& e) {
    switch (e)
    {
    
        case OAIMetadataField::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIMetadataField::CAST:
            j = "Cast";
            break;
    
        case OAIMetadataField::GENRES:
            j = "Genres";
            break;
    
        case OAIMetadataField::PRODUCTIONLOCATIONS:
            j = "ProductionLocations";
            break;
    
        case OAIMetadataField::STUDIOS:
            j = "Studios";
            break;
    
        case OAIMetadataField::TAGS:
            j = "Tags";
            break;
    
        case OAIMetadataField::NAME:
            j = "Name";
            break;
    
        case OAIMetadataField::OVERVIEW:
            j = "Overview";
            break;
    
        case OAIMetadataField::RUNTIME:
            j = "Runtime";
            break;
    
        case OAIMetadataField::OFFICIALRATING:
            j = "OfficialRating";
            break;
    
    }
}
void from_json(const json_t& j, OAIMetadataField& e) {
    auto s = j.get<std::string>();
    
    if (s == "Cast"sv) {
        e = (OAIMetadataField::CAST);
    } 
    
    else if (s == "Genres"sv) {
        e = (OAIMetadataField::GENRES);
    } 
    
    else if (s == "ProductionLocations"sv) {
        e = (OAIMetadataField::PRODUCTIONLOCATIONS);
    } 
    
    else if (s == "Studios"sv) {
        e = (OAIMetadataField::STUDIOS);
    } 
    
    else if (s == "Tags"sv) {
        e = (OAIMetadataField::TAGS);
    } 
    
    else if (s == "Name"sv) {
        e = (OAIMetadataField::NAME);
    } 
    
    else if (s == "Overview"sv) {
        e = (OAIMetadataField::OVERVIEW);
    } 
    
    else if (s == "Runtime"sv) {
        e = (OAIMetadataField::RUNTIME);
    } 
    
    else if (s == "OfficialRating"sv) {
        e = (OAIMetadataField::OFFICIALRATING);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIMetadataField";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIMetadataOptions& o) {
        j["ItemType"sv] = o.ItemType;
        j["DisabledMetadataSavers"sv] = o.DisabledMetadataSavers;
        j["LocalMetadataReaderOrder"sv] = o.LocalMetadataReaderOrder;
        j["DisabledMetadataFetchers"sv] = o.DisabledMetadataFetchers;
        j["MetadataFetcherOrder"sv] = o.MetadataFetcherOrder;
        j["DisabledImageFetchers"sv] = o.DisabledImageFetchers;
        j["ImageFetcherOrder"sv] = o.ImageFetcherOrder;
}
void from_json(const json_t& j, OAIMetadataOptions& o) {
    if(j.contains("ItemType"sv))
    j.at("ItemType"sv).get_to(o.ItemType);
    if(j.contains("DisabledMetadataSavers"sv))
    j.at("DisabledMetadataSavers"sv).get_to(o.DisabledMetadataSavers);
    if(j.contains("LocalMetadataReaderOrder"sv))
    j.at("LocalMetadataReaderOrder"sv).get_to(o.LocalMetadataReaderOrder);
    if(j.contains("DisabledMetadataFetchers"sv))
    j.at("DisabledMetadataFetchers"sv).get_to(o.DisabledMetadataFetchers);
    if(j.contains("MetadataFetcherOrder"sv))
    j.at("MetadataFetcherOrder"sv).get_to(o.MetadataFetcherOrder);
    if(j.contains("DisabledImageFetchers"sv))
    j.at("DisabledImageFetchers"sv).get_to(o.DisabledImageFetchers);
    if(j.contains("ImageFetcherOrder"sv))
    j.at("ImageFetcherOrder"sv).get_to(o.ImageFetcherOrder);
}



void to_json(json_t& j, const OAIMetadataRefreshMode& e) {
    switch (e)
    {
    
        case OAIMetadataRefreshMode::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIMetadataRefreshMode::NONE:
            j = "None";
            break;
    
        case OAIMetadataRefreshMode::VALIDATIONONLY:
            j = "ValidationOnly";
            break;
    
        case OAIMetadataRefreshMode::DEFAULT:
            j = "Default";
            break;
    
        case OAIMetadataRefreshMode::FULLREFRESH:
            j = "FullRefresh";
            break;
    
    }
}
void from_json(const json_t& j, OAIMetadataRefreshMode& e) {
    auto s = j.get<std::string>();
    
    if (s == "None"sv) {
        e = (OAIMetadataRefreshMode::NONE);
    } 
    
    else if (s == "ValidationOnly"sv) {
        e = (OAIMetadataRefreshMode::VALIDATIONONLY);
    } 
    
    else if (s == "Default"sv) {
        e = (OAIMetadataRefreshMode::DEFAULT);
    } 
    
    else if (s == "FullRefresh"sv) {
        e = (OAIMetadataRefreshMode::FULLREFRESH);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIMetadataRefreshMode";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIMovePlaylistItemRequestDto& o) {
        j["PlaylistItemId"sv] = o.PlaylistItemId;
        j["NewIndex"sv] = o.NewIndex;
}
void from_json(const json_t& j, OAIMovePlaylistItemRequestDto& o) {
    
    j.at("PlaylistItemId"sv).get_to(o.PlaylistItemId);
    
    j.at("NewIndex"sv).get_to(o.NewIndex);
}




void to_json(json_t& j, const OAIMovieInfo& o) {
        j["Name"sv] = o.Name;
        j["OriginalTitle"sv] = o.OriginalTitle;
        j["Path"sv] = o.Path;
        j["MetadataLanguage"sv] = o.MetadataLanguage;
        j["MetadataCountryCode"sv] = o.MetadataCountryCode;
        j["ProviderIds"sv] = o.ProviderIds;
        j["Year"sv] = o.Year;
        j["IndexNumber"sv] = o.IndexNumber;
        j["ParentIndexNumber"sv] = o.ParentIndexNumber;
        j["PremiereDate"sv] = o.PremiereDate;
        j["IsAutomated"sv] = o.IsAutomated;
}
void from_json(const json_t& j, OAIMovieInfo& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("OriginalTitle"sv))
    j.at("OriginalTitle"sv).get_to(o.OriginalTitle);
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("MetadataLanguage"sv))
    j.at("MetadataLanguage"sv).get_to(o.MetadataLanguage);
    if(j.contains("MetadataCountryCode"sv))
    j.at("MetadataCountryCode"sv).get_to(o.MetadataCountryCode);
    if(j.contains("ProviderIds"sv))
    j.at("ProviderIds"sv).get_to(o.ProviderIds);
    if(j.contains("Year"sv))
    j.at("Year"sv).get_to(o.Year);
    if(j.contains("IndexNumber"sv))
    j.at("IndexNumber"sv).get_to(o.IndexNumber);
    if(j.contains("ParentIndexNumber"sv))
    j.at("ParentIndexNumber"sv).get_to(o.ParentIndexNumber);
    if(j.contains("PremiereDate"sv))
    j.at("PremiereDate"sv).get_to(o.PremiereDate);
    
    j.at("IsAutomated"sv).get_to(o.IsAutomated);
}




void to_json(json_t& j, const OAIMovieInfoRemoteSearchQuery& o) {
        j["SearchInfo"sv] = o.SearchInfo;
        j["ItemId"sv] = o.ItemId;
        j["SearchProviderName"sv] = o.SearchProviderName;
        j["IncludeDisabledProviders"sv] = o.IncludeDisabledProviders;
}
void from_json(const json_t& j, OAIMovieInfoRemoteSearchQuery& o) {
    if(j.contains("SearchInfo"sv))
    j.at("SearchInfo"sv).get_to(o.SearchInfo);
    
    j.at("ItemId"sv).get_to(o.ItemId);
    if(j.contains("SearchProviderName"sv))
    j.at("SearchProviderName"sv).get_to(o.SearchProviderName);
    
    j.at("IncludeDisabledProviders"sv).get_to(o.IncludeDisabledProviders);
}




void to_json(json_t& j, const OAIMusicVideoInfo& o) {
        j["Name"sv] = o.Name;
        j["OriginalTitle"sv] = o.OriginalTitle;
        j["Path"sv] = o.Path;
        j["MetadataLanguage"sv] = o.MetadataLanguage;
        j["MetadataCountryCode"sv] = o.MetadataCountryCode;
        j["ProviderIds"sv] = o.ProviderIds;
        j["Year"sv] = o.Year;
        j["IndexNumber"sv] = o.IndexNumber;
        j["ParentIndexNumber"sv] = o.ParentIndexNumber;
        j["PremiereDate"sv] = o.PremiereDate;
        j["IsAutomated"sv] = o.IsAutomated;
        j["Artists"sv] = o.Artists;
}
void from_json(const json_t& j, OAIMusicVideoInfo& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("OriginalTitle"sv))
    j.at("OriginalTitle"sv).get_to(o.OriginalTitle);
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("MetadataLanguage"sv))
    j.at("MetadataLanguage"sv).get_to(o.MetadataLanguage);
    if(j.contains("MetadataCountryCode"sv))
    j.at("MetadataCountryCode"sv).get_to(o.MetadataCountryCode);
    if(j.contains("ProviderIds"sv))
    j.at("ProviderIds"sv).get_to(o.ProviderIds);
    if(j.contains("Year"sv))
    j.at("Year"sv).get_to(o.Year);
    if(j.contains("IndexNumber"sv))
    j.at("IndexNumber"sv).get_to(o.IndexNumber);
    if(j.contains("ParentIndexNumber"sv))
    j.at("ParentIndexNumber"sv).get_to(o.ParentIndexNumber);
    if(j.contains("PremiereDate"sv))
    j.at("PremiereDate"sv).get_to(o.PremiereDate);
    
    j.at("IsAutomated"sv).get_to(o.IsAutomated);
    if(j.contains("Artists"sv))
    j.at("Artists"sv).get_to(o.Artists);
}




void to_json(json_t& j, const OAIMusicVideoInfoRemoteSearchQuery& o) {
        j["SearchInfo"sv] = o.SearchInfo;
        j["ItemId"sv] = o.ItemId;
        j["SearchProviderName"sv] = o.SearchProviderName;
        j["IncludeDisabledProviders"sv] = o.IncludeDisabledProviders;
}
void from_json(const json_t& j, OAIMusicVideoInfoRemoteSearchQuery& o) {
    if(j.contains("SearchInfo"sv))
    j.at("SearchInfo"sv).get_to(o.SearchInfo);
    
    j.at("ItemId"sv).get_to(o.ItemId);
    if(j.contains("SearchProviderName"sv))
    j.at("SearchProviderName"sv).get_to(o.SearchProviderName);
    
    j.at("IncludeDisabledProviders"sv).get_to(o.IncludeDisabledProviders);
}




void to_json(json_t& j, const OAINameGuidPair& o) {
        j["Name"sv] = o.Name;
        j["Id"sv] = o.Id;
}
void from_json(const json_t& j, OAINameGuidPair& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    
    j.at("Id"sv).get_to(o.Id);
}




void to_json(json_t& j, const OAINameIdPair& o) {
        j["Name"sv] = o.Name;
        j["Id"sv] = o.Id;
}
void from_json(const json_t& j, OAINameIdPair& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Id"sv))
    j.at("Id"sv).get_to(o.Id);
}




void to_json(json_t& j, const OAINameValuePair& o) {
        j["Name"sv] = o.Name;
        j["Value"sv] = o.Value;
}
void from_json(const json_t& j, OAINameValuePair& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Value"sv))
    j.at("Value"sv).get_to(o.Value);
}




void to_json(json_t& j, const OAINetworkConfiguration& o) {
        j["BaseUrl"sv] = o.BaseUrl;
        j["EnableHttps"sv] = o.EnableHttps;
        j["RequireHttps"sv] = o.RequireHttps;
        j["CertificatePath"sv] = o.CertificatePath;
        j["CertificatePassword"sv] = o.CertificatePassword;
        j["InternalHttpPort"sv] = o.InternalHttpPort;
        j["InternalHttpsPort"sv] = o.InternalHttpsPort;
        j["PublicHttpPort"sv] = o.PublicHttpPort;
        j["PublicHttpsPort"sv] = o.PublicHttpsPort;
        j["AutoDiscovery"sv] = o.AutoDiscovery;
        j["EnableUPnP"sv] = o.EnableUPnP;
        j["EnableIPv4"sv] = o.EnableIPv4;
        j["EnableIPv6"sv] = o.EnableIPv6;
        j["EnableRemoteAccess"sv] = o.EnableRemoteAccess;
        j["LocalNetworkSubnets"sv] = o.LocalNetworkSubnets;
        j["LocalNetworkAddresses"sv] = o.LocalNetworkAddresses;
        j["KnownProxies"sv] = o.KnownProxies;
        j["IgnoreVirtualInterfaces"sv] = o.IgnoreVirtualInterfaces;
        j["VirtualInterfaceNames"sv] = o.VirtualInterfaceNames;
        j["EnablePublishedServerUriByRequest"sv] = o.EnablePublishedServerUriByRequest;
        j["PublishedServerUriBySubnet"sv] = o.PublishedServerUriBySubnet;
        j["RemoteIPFilter"sv] = o.RemoteIPFilter;
        j["IsRemoteIPFilterBlacklist"sv] = o.IsRemoteIPFilterBlacklist;
}
void from_json(const json_t& j, OAINetworkConfiguration& o) {
    
    j.at("BaseUrl"sv).get_to(o.BaseUrl);
    
    j.at("EnableHttps"sv).get_to(o.EnableHttps);
    
    j.at("RequireHttps"sv).get_to(o.RequireHttps);
    
    j.at("CertificatePath"sv).get_to(o.CertificatePath);
    
    j.at("CertificatePassword"sv).get_to(o.CertificatePassword);
    
    j.at("InternalHttpPort"sv).get_to(o.InternalHttpPort);
    
    j.at("InternalHttpsPort"sv).get_to(o.InternalHttpsPort);
    
    j.at("PublicHttpPort"sv).get_to(o.PublicHttpPort);
    
    j.at("PublicHttpsPort"sv).get_to(o.PublicHttpsPort);
    
    j.at("AutoDiscovery"sv).get_to(o.AutoDiscovery);
    
    j.at("EnableUPnP"sv).get_to(o.EnableUPnP);
    
    j.at("EnableIPv4"sv).get_to(o.EnableIPv4);
    
    j.at("EnableIPv6"sv).get_to(o.EnableIPv6);
    
    j.at("EnableRemoteAccess"sv).get_to(o.EnableRemoteAccess);
    
    j.at("LocalNetworkSubnets"sv).get_to(o.LocalNetworkSubnets);
    
    j.at("LocalNetworkAddresses"sv).get_to(o.LocalNetworkAddresses);
    
    j.at("KnownProxies"sv).get_to(o.KnownProxies);
    
    j.at("IgnoreVirtualInterfaces"sv).get_to(o.IgnoreVirtualInterfaces);
    
    j.at("VirtualInterfaceNames"sv).get_to(o.VirtualInterfaceNames);
    
    j.at("EnablePublishedServerUriByRequest"sv).get_to(o.EnablePublishedServerUriByRequest);
    
    j.at("PublishedServerUriBySubnet"sv).get_to(o.PublishedServerUriBySubnet);
    
    j.at("RemoteIPFilter"sv).get_to(o.RemoteIPFilter);
    
    j.at("IsRemoteIPFilterBlacklist"sv).get_to(o.IsRemoteIPFilterBlacklist);
}




void to_json(json_t& j, const OAINewGroupRequestDto& o) {
        j["GroupName"sv] = o.GroupName;
}
void from_json(const json_t& j, OAINewGroupRequestDto& o) {
    
    j.at("GroupName"sv).get_to(o.GroupName);
}




void to_json(json_t& j, const OAINextItemRequestDto& o) {
        j["PlaylistItemId"sv] = o.PlaylistItemId;
}
void from_json(const json_t& j, OAINextItemRequestDto& o) {
    
    j.at("PlaylistItemId"sv).get_to(o.PlaylistItemId);
}




void to_json(json_t& j, const OAIOpenLiveStreamDto& o) {
        j["OpenToken"sv] = o.OpenToken;
        j["UserId"sv] = o.UserId;
        j["PlaySessionId"sv] = o.PlaySessionId;
        j["MaxStreamingBitrate"sv] = o.MaxStreamingBitrate;
        j["StartTimeTicks"sv] = o.StartTimeTicks;
        j["AudioStreamIndex"sv] = o.AudioStreamIndex;
        j["SubtitleStreamIndex"sv] = o.SubtitleStreamIndex;
        j["MaxAudioChannels"sv] = o.MaxAudioChannels;
        j["ItemId"sv] = o.ItemId;
        j["EnableDirectPlay"sv] = o.EnableDirectPlay;
        j["EnableDirectStream"sv] = o.EnableDirectStream;
        j["DeviceProfile"sv] = o.DeviceProfile;
        j["DirectPlayProtocols"sv] = o.DirectPlayProtocols;
}
void from_json(const json_t& j, OAIOpenLiveStreamDto& o) {
    if(j.contains("OpenToken"sv))
    j.at("OpenToken"sv).get_to(o.OpenToken);
    if(j.contains("UserId"sv))
    j.at("UserId"sv).get_to(o.UserId);
    if(j.contains("PlaySessionId"sv))
    j.at("PlaySessionId"sv).get_to(o.PlaySessionId);
    if(j.contains("MaxStreamingBitrate"sv))
    j.at("MaxStreamingBitrate"sv).get_to(o.MaxStreamingBitrate);
    if(j.contains("StartTimeTicks"sv))
    j.at("StartTimeTicks"sv).get_to(o.StartTimeTicks);
    if(j.contains("AudioStreamIndex"sv))
    j.at("AudioStreamIndex"sv).get_to(o.AudioStreamIndex);
    if(j.contains("SubtitleStreamIndex"sv))
    j.at("SubtitleStreamIndex"sv).get_to(o.SubtitleStreamIndex);
    if(j.contains("MaxAudioChannels"sv))
    j.at("MaxAudioChannels"sv).get_to(o.MaxAudioChannels);
    if(j.contains("ItemId"sv))
    j.at("ItemId"sv).get_to(o.ItemId);
    if(j.contains("EnableDirectPlay"sv))
    j.at("EnableDirectPlay"sv).get_to(o.EnableDirectPlay);
    if(j.contains("EnableDirectStream"sv))
    j.at("EnableDirectStream"sv).get_to(o.EnableDirectStream);
    if(j.contains("DeviceProfile"sv))
    j.at("DeviceProfile"sv).get_to(o.DeviceProfile);
    
    j.at("DirectPlayProtocols"sv).get_to(o.DirectPlayProtocols);
}




void to_json(json_t& j, const OAIOutboundKeepAliveMessage& o) {
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIOutboundKeepAliveMessage& o) {
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}


void to_json(json_t& j, const OAIOutboundWebSocketMessage& o) {
}
void from_json(const json_t& j, OAIOutboundWebSocketMessage& o) {
}





void to_json(json_t& j, const OAIPackageInfo& o) {
        j["name"sv] = o.name;
        j["description"sv] = o.description;
        j["overview"sv] = o.overview;
        j["owner"sv] = o.owner;
        j["category"sv] = o.category;
        j["guid"sv] = o.guid;
        j["versions"sv] = o.versions;
        j["imageUrl"sv] = o.imageUrl;
}
void from_json(const json_t& j, OAIPackageInfo& o) {
    
    j.at("name"sv).get_to(o.name);
    
    j.at("description"sv).get_to(o.description);
    
    j.at("overview"sv).get_to(o.overview);
    
    j.at("owner"sv).get_to(o.owner);
    
    j.at("category"sv).get_to(o.category);
    
    j.at("guid"sv).get_to(o.guid);
    
    j.at("versions"sv).get_to(o.versions);
    if(j.contains("imageUrl"sv))
    j.at("imageUrl"sv).get_to(o.imageUrl);
}




void to_json(json_t& j, const OAIParentalRating& o) {
        j["Name"sv] = o.Name;
        j["Value"sv] = o.Value;
}
void from_json(const json_t& j, OAIParentalRating& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Value"sv))
    j.at("Value"sv).get_to(o.Value);
}




void to_json(json_t& j, const OAIPathSubstitution& o) {
        j["From"sv] = o.From;
        j["To"sv] = o.To;
}
void from_json(const json_t& j, OAIPathSubstitution& o) {
    
    j.at("From"sv).get_to(o.From);
    
    j.at("To"sv).get_to(o.To);
}



void to_json(json_t& j, const OAIPersonKind& e) {
    switch (e)
    {
    
        case OAIPersonKind::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIPersonKind::UNKNOWN:
            j = "Unknown";
            break;
    
        case OAIPersonKind::ACTOR:
            j = "Actor";
            break;
    
        case OAIPersonKind::DIRECTOR:
            j = "Director";
            break;
    
        case OAIPersonKind::COMPOSER:
            j = "Composer";
            break;
    
        case OAIPersonKind::WRITER:
            j = "Writer";
            break;
    
        case OAIPersonKind::GUESTSTAR:
            j = "GuestStar";
            break;
    
        case OAIPersonKind::PRODUCER:
            j = "Producer";
            break;
    
        case OAIPersonKind::CONDUCTOR:
            j = "Conductor";
            break;
    
        case OAIPersonKind::LYRICIST:
            j = "Lyricist";
            break;
    
        case OAIPersonKind::ARRANGER:
            j = "Arranger";
            break;
    
        case OAIPersonKind::ENGINEER:
            j = "Engineer";
            break;
    
        case OAIPersonKind::MIXER:
            j = "Mixer";
            break;
    
        case OAIPersonKind::REMIXER:
            j = "Remixer";
            break;
    
        case OAIPersonKind::CREATOR:
            j = "Creator";
            break;
    
        case OAIPersonKind::ARTIST:
            j = "Artist";
            break;
    
        case OAIPersonKind::ALBUMARTIST:
            j = "AlbumArtist";
            break;
    
        case OAIPersonKind::AUTHOR:
            j = "Author";
            break;
    
        case OAIPersonKind::ILLUSTRATOR:
            j = "Illustrator";
            break;
    
        case OAIPersonKind::PENCILLER:
            j = "Penciller";
            break;
    
        case OAIPersonKind::INKER:
            j = "Inker";
            break;
    
        case OAIPersonKind::COLORIST:
            j = "Colorist";
            break;
    
        case OAIPersonKind::LETTERER:
            j = "Letterer";
            break;
    
        case OAIPersonKind::COVERARTIST:
            j = "CoverArtist";
            break;
    
        case OAIPersonKind::EDITOR:
            j = "Editor";
            break;
    
        case OAIPersonKind::TRANSLATOR:
            j = "Translator";
            break;
    
    }
}
void from_json(const json_t& j, OAIPersonKind& e) {
    auto s = j.get<std::string>();
    
    if (s == "Unknown"sv) {
        e = (OAIPersonKind::UNKNOWN);
    } 
    
    else if (s == "Actor"sv) {
        e = (OAIPersonKind::ACTOR);
    } 
    
    else if (s == "Director"sv) {
        e = (OAIPersonKind::DIRECTOR);
    } 
    
    else if (s == "Composer"sv) {
        e = (OAIPersonKind::COMPOSER);
    } 
    
    else if (s == "Writer"sv) {
        e = (OAIPersonKind::WRITER);
    } 
    
    else if (s == "GuestStar"sv) {
        e = (OAIPersonKind::GUESTSTAR);
    } 
    
    else if (s == "Producer"sv) {
        e = (OAIPersonKind::PRODUCER);
    } 
    
    else if (s == "Conductor"sv) {
        e = (OAIPersonKind::CONDUCTOR);
    } 
    
    else if (s == "Lyricist"sv) {
        e = (OAIPersonKind::LYRICIST);
    } 
    
    else if (s == "Arranger"sv) {
        e = (OAIPersonKind::ARRANGER);
    } 
    
    else if (s == "Engineer"sv) {
        e = (OAIPersonKind::ENGINEER);
    } 
    
    else if (s == "Mixer"sv) {
        e = (OAIPersonKind::MIXER);
    } 
    
    else if (s == "Remixer"sv) {
        e = (OAIPersonKind::REMIXER);
    } 
    
    else if (s == "Creator"sv) {
        e = (OAIPersonKind::CREATOR);
    } 
    
    else if (s == "Artist"sv) {
        e = (OAIPersonKind::ARTIST);
    } 
    
    else if (s == "AlbumArtist"sv) {
        e = (OAIPersonKind::ALBUMARTIST);
    } 
    
    else if (s == "Author"sv) {
        e = (OAIPersonKind::AUTHOR);
    } 
    
    else if (s == "Illustrator"sv) {
        e = (OAIPersonKind::ILLUSTRATOR);
    } 
    
    else if (s == "Penciller"sv) {
        e = (OAIPersonKind::PENCILLER);
    } 
    
    else if (s == "Inker"sv) {
        e = (OAIPersonKind::INKER);
    } 
    
    else if (s == "Colorist"sv) {
        e = (OAIPersonKind::COLORIST);
    } 
    
    else if (s == "Letterer"sv) {
        e = (OAIPersonKind::LETTERER);
    } 
    
    else if (s == "CoverArtist"sv) {
        e = (OAIPersonKind::COVERARTIST);
    } 
    
    else if (s == "Editor"sv) {
        e = (OAIPersonKind::EDITOR);
    } 
    
    else if (s == "Translator"sv) {
        e = (OAIPersonKind::TRANSLATOR);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIPersonKind";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIPersonLookupInfo& o) {
        j["Name"sv] = o.Name;
        j["OriginalTitle"sv] = o.OriginalTitle;
        j["Path"sv] = o.Path;
        j["MetadataLanguage"sv] = o.MetadataLanguage;
        j["MetadataCountryCode"sv] = o.MetadataCountryCode;
        j["ProviderIds"sv] = o.ProviderIds;
        j["Year"sv] = o.Year;
        j["IndexNumber"sv] = o.IndexNumber;
        j["ParentIndexNumber"sv] = o.ParentIndexNumber;
        j["PremiereDate"sv] = o.PremiereDate;
        j["IsAutomated"sv] = o.IsAutomated;
}
void from_json(const json_t& j, OAIPersonLookupInfo& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("OriginalTitle"sv))
    j.at("OriginalTitle"sv).get_to(o.OriginalTitle);
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("MetadataLanguage"sv))
    j.at("MetadataLanguage"sv).get_to(o.MetadataLanguage);
    if(j.contains("MetadataCountryCode"sv))
    j.at("MetadataCountryCode"sv).get_to(o.MetadataCountryCode);
    if(j.contains("ProviderIds"sv))
    j.at("ProviderIds"sv).get_to(o.ProviderIds);
    if(j.contains("Year"sv))
    j.at("Year"sv).get_to(o.Year);
    if(j.contains("IndexNumber"sv))
    j.at("IndexNumber"sv).get_to(o.IndexNumber);
    if(j.contains("ParentIndexNumber"sv))
    j.at("ParentIndexNumber"sv).get_to(o.ParentIndexNumber);
    if(j.contains("PremiereDate"sv))
    j.at("PremiereDate"sv).get_to(o.PremiereDate);
    
    j.at("IsAutomated"sv).get_to(o.IsAutomated);
}




void to_json(json_t& j, const OAIPersonLookupInfoRemoteSearchQuery& o) {
        j["SearchInfo"sv] = o.SearchInfo;
        j["ItemId"sv] = o.ItemId;
        j["SearchProviderName"sv] = o.SearchProviderName;
        j["IncludeDisabledProviders"sv] = o.IncludeDisabledProviders;
}
void from_json(const json_t& j, OAIPersonLookupInfoRemoteSearchQuery& o) {
    if(j.contains("SearchInfo"sv))
    j.at("SearchInfo"sv).get_to(o.SearchInfo);
    
    j.at("ItemId"sv).get_to(o.ItemId);
    if(j.contains("SearchProviderName"sv))
    j.at("SearchProviderName"sv).get_to(o.SearchProviderName);
    
    j.at("IncludeDisabledProviders"sv).get_to(o.IncludeDisabledProviders);
}




void to_json(json_t& j, const OAIPinRedeemResult& o) {
        j["Success"sv] = o.Success;
        j["UsersReset"sv] = o.UsersReset;
}
void from_json(const json_t& j, OAIPinRedeemResult& o) {
    
    j.at("Success"sv).get_to(o.Success);
    
    j.at("UsersReset"sv).get_to(o.UsersReset);
}




void to_json(json_t& j, const OAIPingRequestDto& o) {
        j["Ping"sv] = o.Ping;
}
void from_json(const json_t& j, OAIPingRequestDto& o) {
    
    j.at("Ping"sv).get_to(o.Ping);
}



void to_json(json_t& j, const OAIPlayAccess& e) {
    switch (e)
    {
    
        case OAIPlayAccess::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIPlayAccess::FULL:
            j = "Full";
            break;
    
        case OAIPlayAccess::NONE:
            j = "None";
            break;
    
    }
}
void from_json(const json_t& j, OAIPlayAccess& e) {
    auto s = j.get<std::string>();
    
    if (s == "Full"sv) {
        e = (OAIPlayAccess::FULL);
    } 
    
    else if (s == "None"sv) {
        e = (OAIPlayAccess::NONE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIPlayAccess";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIPlayCommand& e) {
    switch (e)
    {
    
        case OAIPlayCommand::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIPlayCommand::PLAYNOW:
            j = "PlayNow";
            break;
    
        case OAIPlayCommand::PLAYNEXT:
            j = "PlayNext";
            break;
    
        case OAIPlayCommand::PLAYLAST:
            j = "PlayLast";
            break;
    
        case OAIPlayCommand::PLAYINSTANTMIX:
            j = "PlayInstantMix";
            break;
    
        case OAIPlayCommand::PLAYSHUFFLE:
            j = "PlayShuffle";
            break;
    
    }
}
void from_json(const json_t& j, OAIPlayCommand& e) {
    auto s = j.get<std::string>();
    
    if (s == "PlayNow"sv) {
        e = (OAIPlayCommand::PLAYNOW);
    } 
    
    else if (s == "PlayNext"sv) {
        e = (OAIPlayCommand::PLAYNEXT);
    } 
    
    else if (s == "PlayLast"sv) {
        e = (OAIPlayCommand::PLAYLAST);
    } 
    
    else if (s == "PlayInstantMix"sv) {
        e = (OAIPlayCommand::PLAYINSTANTMIX);
    } 
    
    else if (s == "PlayShuffle"sv) {
        e = (OAIPlayCommand::PLAYSHUFFLE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIPlayCommand";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIPlayMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIPlayMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}



void to_json(json_t& j, const OAIPlayMethod& e) {
    switch (e)
    {
    
        case OAIPlayMethod::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIPlayMethod::TRANSCODE:
            j = "Transcode";
            break;
    
        case OAIPlayMethod::DIRECTSTREAM:
            j = "DirectStream";
            break;
    
        case OAIPlayMethod::DIRECTPLAY:
            j = "DirectPlay";
            break;
    
    }
}
void from_json(const json_t& j, OAIPlayMethod& e) {
    auto s = j.get<std::string>();
    
    if (s == "Transcode"sv) {
        e = (OAIPlayMethod::TRANSCODE);
    } 
    
    else if (s == "DirectStream"sv) {
        e = (OAIPlayMethod::DIRECTSTREAM);
    } 
    
    else if (s == "DirectPlay"sv) {
        e = (OAIPlayMethod::DIRECTPLAY);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIPlayMethod";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIPlayQueueUpdate& o) {
        j["Reason"sv] = o.Reason;
        j["LastUpdate"sv] = o.LastUpdate;
        j["Playlist"sv] = o.Playlist;
        j["PlayingItemIndex"sv] = o.PlayingItemIndex;
        j["StartPositionTicks"sv] = o.StartPositionTicks;
        j["IsPlaying"sv] = o.IsPlaying;
        j["ShuffleMode"sv] = o.ShuffleMode;
        j["RepeatMode"sv] = o.RepeatMode;
}
void from_json(const json_t& j, OAIPlayQueueUpdate& o) {
    
    j.at("Reason"sv).get_to(o.Reason);
    
    j.at("LastUpdate"sv).get_to(o.LastUpdate);
    
    j.at("Playlist"sv).get_to(o.Playlist);
    
    j.at("PlayingItemIndex"sv).get_to(o.PlayingItemIndex);
    
    j.at("StartPositionTicks"sv).get_to(o.StartPositionTicks);
    
    j.at("IsPlaying"sv).get_to(o.IsPlaying);
    
    j.at("ShuffleMode"sv).get_to(o.ShuffleMode);
    
    j.at("RepeatMode"sv).get_to(o.RepeatMode);
}




void to_json(json_t& j, const OAIPlayQueueUpdateGroupUpdate& o) {
        j["GroupId"sv] = o.GroupId;
        j["Type"sv] = o.Type;
        j["Data"sv] = o.Data;
}
void from_json(const json_t& j, OAIPlayQueueUpdateGroupUpdate& o) {
    
    j.at("GroupId"sv).get_to(o.GroupId);
    
    j.at("Type"sv).get_to(o.Type);
    
    j.at("Data"sv).get_to(o.Data);
}



void to_json(json_t& j, const OAIPlayQueueUpdateReason& e) {
    switch (e)
    {
    
        case OAIPlayQueueUpdateReason::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIPlayQueueUpdateReason::NEWPLAYLIST:
            j = "NewPlaylist";
            break;
    
        case OAIPlayQueueUpdateReason::SETCURRENTITEM:
            j = "SetCurrentItem";
            break;
    
        case OAIPlayQueueUpdateReason::REMOVEITEMS:
            j = "RemoveItems";
            break;
    
        case OAIPlayQueueUpdateReason::MOVEITEM:
            j = "MoveItem";
            break;
    
        case OAIPlayQueueUpdateReason::QUEUE:
            j = "Queue";
            break;
    
        case OAIPlayQueueUpdateReason::QUEUENEXT:
            j = "QueueNext";
            break;
    
        case OAIPlayQueueUpdateReason::NEXTITEM:
            j = "NextItem";
            break;
    
        case OAIPlayQueueUpdateReason::PREVIOUSITEM:
            j = "PreviousItem";
            break;
    
        case OAIPlayQueueUpdateReason::REPEATMODE:
            j = "RepeatMode";
            break;
    
        case OAIPlayQueueUpdateReason::SHUFFLEMODE:
            j = "ShuffleMode";
            break;
    
    }
}
void from_json(const json_t& j, OAIPlayQueueUpdateReason& e) {
    auto s = j.get<std::string>();
    
    if (s == "NewPlaylist"sv) {
        e = (OAIPlayQueueUpdateReason::NEWPLAYLIST);
    } 
    
    else if (s == "SetCurrentItem"sv) {
        e = (OAIPlayQueueUpdateReason::SETCURRENTITEM);
    } 
    
    else if (s == "RemoveItems"sv) {
        e = (OAIPlayQueueUpdateReason::REMOVEITEMS);
    } 
    
    else if (s == "MoveItem"sv) {
        e = (OAIPlayQueueUpdateReason::MOVEITEM);
    } 
    
    else if (s == "Queue"sv) {
        e = (OAIPlayQueueUpdateReason::QUEUE);
    } 
    
    else if (s == "QueueNext"sv) {
        e = (OAIPlayQueueUpdateReason::QUEUENEXT);
    } 
    
    else if (s == "NextItem"sv) {
        e = (OAIPlayQueueUpdateReason::NEXTITEM);
    } 
    
    else if (s == "PreviousItem"sv) {
        e = (OAIPlayQueueUpdateReason::PREVIOUSITEM);
    } 
    
    else if (s == "RepeatMode"sv) {
        e = (OAIPlayQueueUpdateReason::REPEATMODE);
    } 
    
    else if (s == "ShuffleMode"sv) {
        e = (OAIPlayQueueUpdateReason::SHUFFLEMODE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIPlayQueueUpdateReason";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIPlayRequest& o) {
        j["ItemIds"sv] = o.ItemIds;
        j["StartPositionTicks"sv] = o.StartPositionTicks;
        j["PlayCommand"sv] = o.PlayCommand;
        j["ControllingUserId"sv] = o.ControllingUserId;
        j["SubtitleStreamIndex"sv] = o.SubtitleStreamIndex;
        j["AudioStreamIndex"sv] = o.AudioStreamIndex;
        j["MediaSourceId"sv] = o.MediaSourceId;
        j["StartIndex"sv] = o.StartIndex;
}
void from_json(const json_t& j, OAIPlayRequest& o) {
    if(j.contains("ItemIds"sv))
    j.at("ItemIds"sv).get_to(o.ItemIds);
    if(j.contains("StartPositionTicks"sv))
    j.at("StartPositionTicks"sv).get_to(o.StartPositionTicks);
    
    j.at("PlayCommand"sv).get_to(o.PlayCommand);
    
    j.at("ControllingUserId"sv).get_to(o.ControllingUserId);
    if(j.contains("SubtitleStreamIndex"sv))
    j.at("SubtitleStreamIndex"sv).get_to(o.SubtitleStreamIndex);
    if(j.contains("AudioStreamIndex"sv))
    j.at("AudioStreamIndex"sv).get_to(o.AudioStreamIndex);
    if(j.contains("MediaSourceId"sv))
    j.at("MediaSourceId"sv).get_to(o.MediaSourceId);
    if(j.contains("StartIndex"sv))
    j.at("StartIndex"sv).get_to(o.StartIndex);
}




void to_json(json_t& j, const OAIPlayRequestDto& o) {
        j["PlayingQueue"sv] = o.PlayingQueue;
        j["PlayingItemPosition"sv] = o.PlayingItemPosition;
        j["StartPositionTicks"sv] = o.StartPositionTicks;
}
void from_json(const json_t& j, OAIPlayRequestDto& o) {
    
    j.at("PlayingQueue"sv).get_to(o.PlayingQueue);
    
    j.at("PlayingItemPosition"sv).get_to(o.PlayingItemPosition);
    
    j.at("StartPositionTicks"sv).get_to(o.StartPositionTicks);
}



void to_json(json_t& j, const OAIPlaybackErrorCode& e) {
    switch (e)
    {
    
        case OAIPlaybackErrorCode::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIPlaybackErrorCode::NOTALLOWED:
            j = "NotAllowed";
            break;
    
        case OAIPlaybackErrorCode::NOCOMPATIBLESTREAM:
            j = "NoCompatibleStream";
            break;
    
        case OAIPlaybackErrorCode::RATELIMITEXCEEDED:
            j = "RateLimitExceeded";
            break;
    
    }
}
void from_json(const json_t& j, OAIPlaybackErrorCode& e) {
    auto s = j.get<std::string>();
    
    if (s == "NotAllowed"sv) {
        e = (OAIPlaybackErrorCode::NOTALLOWED);
    } 
    
    else if (s == "NoCompatibleStream"sv) {
        e = (OAIPlaybackErrorCode::NOCOMPATIBLESTREAM);
    } 
    
    else if (s == "RateLimitExceeded"sv) {
        e = (OAIPlaybackErrorCode::RATELIMITEXCEEDED);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIPlaybackErrorCode";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIPlaybackInfoDto& o) {
        j["UserId"sv] = o.UserId;
        j["MaxStreamingBitrate"sv] = o.MaxStreamingBitrate;
        j["StartTimeTicks"sv] = o.StartTimeTicks;
        j["AudioStreamIndex"sv] = o.AudioStreamIndex;
        j["SubtitleStreamIndex"sv] = o.SubtitleStreamIndex;
        j["MaxAudioChannels"sv] = o.MaxAudioChannels;
        j["MediaSourceId"sv] = o.MediaSourceId;
        j["LiveStreamId"sv] = o.LiveStreamId;
        j["DeviceProfile"sv] = o.DeviceProfile;
        j["EnableDirectPlay"sv] = o.EnableDirectPlay;
        j["EnableDirectStream"sv] = o.EnableDirectStream;
        j["EnableTranscoding"sv] = o.EnableTranscoding;
        j["AllowVideoStreamCopy"sv] = o.AllowVideoStreamCopy;
        j["AllowAudioStreamCopy"sv] = o.AllowAudioStreamCopy;
        j["AutoOpenLiveStream"sv] = o.AutoOpenLiveStream;
}
void from_json(const json_t& j, OAIPlaybackInfoDto& o) {
    if(j.contains("UserId"sv))
    j.at("UserId"sv).get_to(o.UserId);
    if(j.contains("MaxStreamingBitrate"sv))
    j.at("MaxStreamingBitrate"sv).get_to(o.MaxStreamingBitrate);
    if(j.contains("StartTimeTicks"sv))
    j.at("StartTimeTicks"sv).get_to(o.StartTimeTicks);
    if(j.contains("AudioStreamIndex"sv))
    j.at("AudioStreamIndex"sv).get_to(o.AudioStreamIndex);
    if(j.contains("SubtitleStreamIndex"sv))
    j.at("SubtitleStreamIndex"sv).get_to(o.SubtitleStreamIndex);
    if(j.contains("MaxAudioChannels"sv))
    j.at("MaxAudioChannels"sv).get_to(o.MaxAudioChannels);
    if(j.contains("MediaSourceId"sv))
    j.at("MediaSourceId"sv).get_to(o.MediaSourceId);
    if(j.contains("LiveStreamId"sv))
    j.at("LiveStreamId"sv).get_to(o.LiveStreamId);
    if(j.contains("DeviceProfile"sv))
    j.at("DeviceProfile"sv).get_to(o.DeviceProfile);
    if(j.contains("EnableDirectPlay"sv))
    j.at("EnableDirectPlay"sv).get_to(o.EnableDirectPlay);
    if(j.contains("EnableDirectStream"sv))
    j.at("EnableDirectStream"sv).get_to(o.EnableDirectStream);
    if(j.contains("EnableTranscoding"sv))
    j.at("EnableTranscoding"sv).get_to(o.EnableTranscoding);
    if(j.contains("AllowVideoStreamCopy"sv))
    j.at("AllowVideoStreamCopy"sv).get_to(o.AllowVideoStreamCopy);
    if(j.contains("AllowAudioStreamCopy"sv))
    j.at("AllowAudioStreamCopy"sv).get_to(o.AllowAudioStreamCopy);
    if(j.contains("AutoOpenLiveStream"sv))
    j.at("AutoOpenLiveStream"sv).get_to(o.AutoOpenLiveStream);
}




void to_json(json_t& j, const OAIPlaybackInfoResponse& o) {
        j["MediaSources"sv] = o.MediaSources;
        j["PlaySessionId"sv] = o.PlaySessionId;
        j["ErrorCode"sv] = o.ErrorCode;
}
void from_json(const json_t& j, OAIPlaybackInfoResponse& o) {
    
    j.at("MediaSources"sv).get_to(o.MediaSources);
    if(j.contains("PlaySessionId"sv))
    j.at("PlaySessionId"sv).get_to(o.PlaySessionId);
    if(j.contains("ErrorCode"sv))
    j.at("ErrorCode"sv).get_to(o.ErrorCode);
}



void to_json(json_t& j, const OAIPlaybackOrder& e) {
    switch (e)
    {
    
        case OAIPlaybackOrder::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIPlaybackOrder::DEFAULT:
            j = "Default";
            break;
    
        case OAIPlaybackOrder::SHUFFLE:
            j = "Shuffle";
            break;
    
    }
}
void from_json(const json_t& j, OAIPlaybackOrder& e) {
    auto s = j.get<std::string>();
    
    if (s == "Default"sv) {
        e = (OAIPlaybackOrder::DEFAULT);
    } 
    
    else if (s == "Shuffle"sv) {
        e = (OAIPlaybackOrder::SHUFFLE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIPlaybackOrder";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIPlaybackProgressInfo& o) {
        j["CanSeek"sv] = o.CanSeek;
        j["Item"sv] = o.Item;
        j["ItemId"sv] = o.ItemId;
        j["SessionId"sv] = o.SessionId;
        j["MediaSourceId"sv] = o.MediaSourceId;
        j["AudioStreamIndex"sv] = o.AudioStreamIndex;
        j["SubtitleStreamIndex"sv] = o.SubtitleStreamIndex;
        j["IsPaused"sv] = o.IsPaused;
        j["IsMuted"sv] = o.IsMuted;
        j["PositionTicks"sv] = o.PositionTicks;
        j["PlaybackStartTimeTicks"sv] = o.PlaybackStartTimeTicks;
        j["VolumeLevel"sv] = o.VolumeLevel;
        j["Brightness"sv] = o.Brightness;
        j["AspectRatio"sv] = o.AspectRatio;
        j["PlayMethod"sv] = o.PlayMethod;
        j["LiveStreamId"sv] = o.LiveStreamId;
        j["PlaySessionId"sv] = o.PlaySessionId;
        j["RepeatMode"sv] = o.RepeatMode;
        j["PlaybackOrder"sv] = o.PlaybackOrder;
        j["NowPlayingQueue"sv] = o.NowPlayingQueue;
        j["PlaylistItemId"sv] = o.PlaylistItemId;
}
void from_json(const json_t& j, OAIPlaybackProgressInfo& o) {
    
    j.at("CanSeek"sv).get_to(o.CanSeek);
    if(j.contains("Item"sv))
    j.at("Item"sv).get_to(o.Item);
    
    j.at("ItemId"sv).get_to(o.ItemId);
    if(j.contains("SessionId"sv))
    j.at("SessionId"sv).get_to(o.SessionId);
    if(j.contains("MediaSourceId"sv))
    j.at("MediaSourceId"sv).get_to(o.MediaSourceId);
    if(j.contains("AudioStreamIndex"sv))
    j.at("AudioStreamIndex"sv).get_to(o.AudioStreamIndex);
    if(j.contains("SubtitleStreamIndex"sv))
    j.at("SubtitleStreamIndex"sv).get_to(o.SubtitleStreamIndex);
    
    j.at("IsPaused"sv).get_to(o.IsPaused);
    
    j.at("IsMuted"sv).get_to(o.IsMuted);
    if(j.contains("PositionTicks"sv))
    j.at("PositionTicks"sv).get_to(o.PositionTicks);
    if(j.contains("PlaybackStartTimeTicks"sv))
    j.at("PlaybackStartTimeTicks"sv).get_to(o.PlaybackStartTimeTicks);
    if(j.contains("VolumeLevel"sv))
    j.at("VolumeLevel"sv).get_to(o.VolumeLevel);
    if(j.contains("Brightness"sv))
    j.at("Brightness"sv).get_to(o.Brightness);
    if(j.contains("AspectRatio"sv))
    j.at("AspectRatio"sv).get_to(o.AspectRatio);
    
    j.at("PlayMethod"sv).get_to(o.PlayMethod);
    if(j.contains("LiveStreamId"sv))
    j.at("LiveStreamId"sv).get_to(o.LiveStreamId);
    if(j.contains("PlaySessionId"sv))
    j.at("PlaySessionId"sv).get_to(o.PlaySessionId);
    
    j.at("RepeatMode"sv).get_to(o.RepeatMode);
    
    j.at("PlaybackOrder"sv).get_to(o.PlaybackOrder);
    if(j.contains("NowPlayingQueue"sv))
    j.at("NowPlayingQueue"sv).get_to(o.NowPlayingQueue);
    if(j.contains("PlaylistItemId"sv))
    j.at("PlaylistItemId"sv).get_to(o.PlaylistItemId);
}



void to_json(json_t& j, const OAIPlaybackRequestType& e) {
    switch (e)
    {
    
        case OAIPlaybackRequestType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIPlaybackRequestType::PLAY:
            j = "Play";
            break;
    
        case OAIPlaybackRequestType::SETPLAYLISTITEM:
            j = "SetPlaylistItem";
            break;
    
        case OAIPlaybackRequestType::REMOVEFROMPLAYLIST:
            j = "RemoveFromPlaylist";
            break;
    
        case OAIPlaybackRequestType::MOVEPLAYLISTITEM:
            j = "MovePlaylistItem";
            break;
    
        case OAIPlaybackRequestType::QUEUE:
            j = "Queue";
            break;
    
        case OAIPlaybackRequestType::UNPAUSE:
            j = "Unpause";
            break;
    
        case OAIPlaybackRequestType::PAUSE:
            j = "Pause";
            break;
    
        case OAIPlaybackRequestType::STOP:
            j = "Stop";
            break;
    
        case OAIPlaybackRequestType::SEEK:
            j = "Seek";
            break;
    
        case OAIPlaybackRequestType::BUFFER:
            j = "Buffer";
            break;
    
        case OAIPlaybackRequestType::READY:
            j = "Ready";
            break;
    
        case OAIPlaybackRequestType::NEXTITEM:
            j = "NextItem";
            break;
    
        case OAIPlaybackRequestType::PREVIOUSITEM:
            j = "PreviousItem";
            break;
    
        case OAIPlaybackRequestType::SETREPEATMODE:
            j = "SetRepeatMode";
            break;
    
        case OAIPlaybackRequestType::SETSHUFFLEMODE:
            j = "SetShuffleMode";
            break;
    
        case OAIPlaybackRequestType::PING:
            j = "Ping";
            break;
    
        case OAIPlaybackRequestType::IGNOREWAIT:
            j = "IgnoreWait";
            break;
    
    }
}
void from_json(const json_t& j, OAIPlaybackRequestType& e) {
    auto s = j.get<std::string>();
    
    if (s == "Play"sv) {
        e = (OAIPlaybackRequestType::PLAY);
    } 
    
    else if (s == "SetPlaylistItem"sv) {
        e = (OAIPlaybackRequestType::SETPLAYLISTITEM);
    } 
    
    else if (s == "RemoveFromPlaylist"sv) {
        e = (OAIPlaybackRequestType::REMOVEFROMPLAYLIST);
    } 
    
    else if (s == "MovePlaylistItem"sv) {
        e = (OAIPlaybackRequestType::MOVEPLAYLISTITEM);
    } 
    
    else if (s == "Queue"sv) {
        e = (OAIPlaybackRequestType::QUEUE);
    } 
    
    else if (s == "Unpause"sv) {
        e = (OAIPlaybackRequestType::UNPAUSE);
    } 
    
    else if (s == "Pause"sv) {
        e = (OAIPlaybackRequestType::PAUSE);
    } 
    
    else if (s == "Stop"sv) {
        e = (OAIPlaybackRequestType::STOP);
    } 
    
    else if (s == "Seek"sv) {
        e = (OAIPlaybackRequestType::SEEK);
    } 
    
    else if (s == "Buffer"sv) {
        e = (OAIPlaybackRequestType::BUFFER);
    } 
    
    else if (s == "Ready"sv) {
        e = (OAIPlaybackRequestType::READY);
    } 
    
    else if (s == "NextItem"sv) {
        e = (OAIPlaybackRequestType::NEXTITEM);
    } 
    
    else if (s == "PreviousItem"sv) {
        e = (OAIPlaybackRequestType::PREVIOUSITEM);
    } 
    
    else if (s == "SetRepeatMode"sv) {
        e = (OAIPlaybackRequestType::SETREPEATMODE);
    } 
    
    else if (s == "SetShuffleMode"sv) {
        e = (OAIPlaybackRequestType::SETSHUFFLEMODE);
    } 
    
    else if (s == "Ping"sv) {
        e = (OAIPlaybackRequestType::PING);
    } 
    
    else if (s == "IgnoreWait"sv) {
        e = (OAIPlaybackRequestType::IGNOREWAIT);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIPlaybackRequestType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIPlaybackStartInfo& o) {
        j["CanSeek"sv] = o.CanSeek;
        j["Item"sv] = o.Item;
        j["ItemId"sv] = o.ItemId;
        j["SessionId"sv] = o.SessionId;
        j["MediaSourceId"sv] = o.MediaSourceId;
        j["AudioStreamIndex"sv] = o.AudioStreamIndex;
        j["SubtitleStreamIndex"sv] = o.SubtitleStreamIndex;
        j["IsPaused"sv] = o.IsPaused;
        j["IsMuted"sv] = o.IsMuted;
        j["PositionTicks"sv] = o.PositionTicks;
        j["PlaybackStartTimeTicks"sv] = o.PlaybackStartTimeTicks;
        j["VolumeLevel"sv] = o.VolumeLevel;
        j["Brightness"sv] = o.Brightness;
        j["AspectRatio"sv] = o.AspectRatio;
        j["PlayMethod"sv] = o.PlayMethod;
        j["LiveStreamId"sv] = o.LiveStreamId;
        j["PlaySessionId"sv] = o.PlaySessionId;
        j["RepeatMode"sv] = o.RepeatMode;
        j["PlaybackOrder"sv] = o.PlaybackOrder;
        j["NowPlayingQueue"sv] = o.NowPlayingQueue;
        j["PlaylistItemId"sv] = o.PlaylistItemId;
}
void from_json(const json_t& j, OAIPlaybackStartInfo& o) {
    
    j.at("CanSeek"sv).get_to(o.CanSeek);
    if(j.contains("Item"sv))
    j.at("Item"sv).get_to(o.Item);
    
    j.at("ItemId"sv).get_to(o.ItemId);
    if(j.contains("SessionId"sv))
    j.at("SessionId"sv).get_to(o.SessionId);
    if(j.contains("MediaSourceId"sv))
    j.at("MediaSourceId"sv).get_to(o.MediaSourceId);
    if(j.contains("AudioStreamIndex"sv))
    j.at("AudioStreamIndex"sv).get_to(o.AudioStreamIndex);
    if(j.contains("SubtitleStreamIndex"sv))
    j.at("SubtitleStreamIndex"sv).get_to(o.SubtitleStreamIndex);
    
    j.at("IsPaused"sv).get_to(o.IsPaused);
    
    j.at("IsMuted"sv).get_to(o.IsMuted);
    if(j.contains("PositionTicks"sv))
    j.at("PositionTicks"sv).get_to(o.PositionTicks);
    if(j.contains("PlaybackStartTimeTicks"sv))
    j.at("PlaybackStartTimeTicks"sv).get_to(o.PlaybackStartTimeTicks);
    if(j.contains("VolumeLevel"sv))
    j.at("VolumeLevel"sv).get_to(o.VolumeLevel);
    if(j.contains("Brightness"sv))
    j.at("Brightness"sv).get_to(o.Brightness);
    if(j.contains("AspectRatio"sv))
    j.at("AspectRatio"sv).get_to(o.AspectRatio);
    
    j.at("PlayMethod"sv).get_to(o.PlayMethod);
    if(j.contains("LiveStreamId"sv))
    j.at("LiveStreamId"sv).get_to(o.LiveStreamId);
    if(j.contains("PlaySessionId"sv))
    j.at("PlaySessionId"sv).get_to(o.PlaySessionId);
    
    j.at("RepeatMode"sv).get_to(o.RepeatMode);
    
    j.at("PlaybackOrder"sv).get_to(o.PlaybackOrder);
    if(j.contains("NowPlayingQueue"sv))
    j.at("NowPlayingQueue"sv).get_to(o.NowPlayingQueue);
    if(j.contains("PlaylistItemId"sv))
    j.at("PlaylistItemId"sv).get_to(o.PlaylistItemId);
}




void to_json(json_t& j, const OAIPlaybackStopInfo& o) {
        j["Item"sv] = o.Item;
        j["ItemId"sv] = o.ItemId;
        j["SessionId"sv] = o.SessionId;
        j["MediaSourceId"sv] = o.MediaSourceId;
        j["PositionTicks"sv] = o.PositionTicks;
        j["LiveStreamId"sv] = o.LiveStreamId;
        j["PlaySessionId"sv] = o.PlaySessionId;
        j["Failed"sv] = o.Failed;
        j["NextMediaType"sv] = o.NextMediaType;
        j["PlaylistItemId"sv] = o.PlaylistItemId;
        j["NowPlayingQueue"sv] = o.NowPlayingQueue;
}
void from_json(const json_t& j, OAIPlaybackStopInfo& o) {
    if(j.contains("Item"sv))
    j.at("Item"sv).get_to(o.Item);
    
    j.at("ItemId"sv).get_to(o.ItemId);
    if(j.contains("SessionId"sv))
    j.at("SessionId"sv).get_to(o.SessionId);
    if(j.contains("MediaSourceId"sv))
    j.at("MediaSourceId"sv).get_to(o.MediaSourceId);
    if(j.contains("PositionTicks"sv))
    j.at("PositionTicks"sv).get_to(o.PositionTicks);
    if(j.contains("LiveStreamId"sv))
    j.at("LiveStreamId"sv).get_to(o.LiveStreamId);
    if(j.contains("PlaySessionId"sv))
    j.at("PlaySessionId"sv).get_to(o.PlaySessionId);
    
    j.at("Failed"sv).get_to(o.Failed);
    if(j.contains("NextMediaType"sv))
    j.at("NextMediaType"sv).get_to(o.NextMediaType);
    if(j.contains("PlaylistItemId"sv))
    j.at("PlaylistItemId"sv).get_to(o.PlaylistItemId);
    if(j.contains("NowPlayingQueue"sv))
    j.at("NowPlayingQueue"sv).get_to(o.NowPlayingQueue);
}




void to_json(json_t& j, const OAIPlayerStateInfo& o) {
        j["PositionTicks"sv] = o.PositionTicks;
        j["CanSeek"sv] = o.CanSeek;
        j["IsPaused"sv] = o.IsPaused;
        j["IsMuted"sv] = o.IsMuted;
        j["VolumeLevel"sv] = o.VolumeLevel;
        j["AudioStreamIndex"sv] = o.AudioStreamIndex;
        j["SubtitleStreamIndex"sv] = o.SubtitleStreamIndex;
        j["MediaSourceId"sv] = o.MediaSourceId;
        j["PlayMethod"sv] = o.PlayMethod;
        j["RepeatMode"sv] = o.RepeatMode;
        j["PlaybackOrder"sv] = o.PlaybackOrder;
        j["LiveStreamId"sv] = o.LiveStreamId;
}
void from_json(const json_t& j, OAIPlayerStateInfo& o) {
    if(j.contains("PositionTicks"sv))
    j.at("PositionTicks"sv).get_to(o.PositionTicks);
    
    j.at("CanSeek"sv).get_to(o.CanSeek);
    
    j.at("IsPaused"sv).get_to(o.IsPaused);
    
    j.at("IsMuted"sv).get_to(o.IsMuted);
    if(j.contains("VolumeLevel"sv))
    j.at("VolumeLevel"sv).get_to(o.VolumeLevel);
    if(j.contains("AudioStreamIndex"sv))
    j.at("AudioStreamIndex"sv).get_to(o.AudioStreamIndex);
    if(j.contains("SubtitleStreamIndex"sv))
    j.at("SubtitleStreamIndex"sv).get_to(o.SubtitleStreamIndex);
    if(j.contains("MediaSourceId"sv))
    j.at("MediaSourceId"sv).get_to(o.MediaSourceId);
    if(j.contains("PlayMethod"sv))
    j.at("PlayMethod"sv).get_to(o.PlayMethod);
    
    j.at("RepeatMode"sv).get_to(o.RepeatMode);
    
    j.at("PlaybackOrder"sv).get_to(o.PlaybackOrder);
    if(j.contains("LiveStreamId"sv))
    j.at("LiveStreamId"sv).get_to(o.LiveStreamId);
}




void to_json(json_t& j, const OAIPlaylistCreationResult& o) {
        j["Id"sv] = o.Id;
}
void from_json(const json_t& j, OAIPlaylistCreationResult& o) {
    
    j.at("Id"sv).get_to(o.Id);
}




void to_json(json_t& j, const OAIPlaylistUserPermissions& o) {
        j["UserId"sv] = o.UserId;
        j["CanEdit"sv] = o.CanEdit;
}
void from_json(const json_t& j, OAIPlaylistUserPermissions& o) {
    
    j.at("UserId"sv).get_to(o.UserId);
    
    j.at("CanEdit"sv).get_to(o.CanEdit);
}



void to_json(json_t& j, const OAIPlaystateCommand& e) {
    switch (e)
    {
    
        case OAIPlaystateCommand::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIPlaystateCommand::STOP:
            j = "Stop";
            break;
    
        case OAIPlaystateCommand::PAUSE:
            j = "Pause";
            break;
    
        case OAIPlaystateCommand::UNPAUSE:
            j = "Unpause";
            break;
    
        case OAIPlaystateCommand::NEXTTRACK:
            j = "NextTrack";
            break;
    
        case OAIPlaystateCommand::PREVIOUSTRACK:
            j = "PreviousTrack";
            break;
    
        case OAIPlaystateCommand::SEEK:
            j = "Seek";
            break;
    
        case OAIPlaystateCommand::REWIND:
            j = "Rewind";
            break;
    
        case OAIPlaystateCommand::FASTFORWARD:
            j = "FastForward";
            break;
    
        case OAIPlaystateCommand::PLAYPAUSE:
            j = "PlayPause";
            break;
    
    }
}
void from_json(const json_t& j, OAIPlaystateCommand& e) {
    auto s = j.get<std::string>();
    
    if (s == "Stop"sv) {
        e = (OAIPlaystateCommand::STOP);
    } 
    
    else if (s == "Pause"sv) {
        e = (OAIPlaystateCommand::PAUSE);
    } 
    
    else if (s == "Unpause"sv) {
        e = (OAIPlaystateCommand::UNPAUSE);
    } 
    
    else if (s == "NextTrack"sv) {
        e = (OAIPlaystateCommand::NEXTTRACK);
    } 
    
    else if (s == "PreviousTrack"sv) {
        e = (OAIPlaystateCommand::PREVIOUSTRACK);
    } 
    
    else if (s == "Seek"sv) {
        e = (OAIPlaystateCommand::SEEK);
    } 
    
    else if (s == "Rewind"sv) {
        e = (OAIPlaystateCommand::REWIND);
    } 
    
    else if (s == "FastForward"sv) {
        e = (OAIPlaystateCommand::FASTFORWARD);
    } 
    
    else if (s == "PlayPause"sv) {
        e = (OAIPlaystateCommand::PLAYPAUSE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIPlaystateCommand";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIPlaystateMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIPlaystateMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAIPlaystateRequest& o) {
        j["Command"sv] = o.Command;
        j["SeekPositionTicks"sv] = o.SeekPositionTicks;
        j["ControllingUserId"sv] = o.ControllingUserId;
}
void from_json(const json_t& j, OAIPlaystateRequest& o) {
    
    j.at("Command"sv).get_to(o.Command);
    if(j.contains("SeekPositionTicks"sv))
    j.at("SeekPositionTicks"sv).get_to(o.SeekPositionTicks);
    if(j.contains("ControllingUserId"sv))
    j.at("ControllingUserId"sv).get_to(o.ControllingUserId);
}




void to_json(json_t& j, const OAIPluginInfo& o) {
        j["Name"sv] = o.Name;
        j["Version"sv] = o.Version;
        j["ConfigurationFileName"sv] = o.ConfigurationFileName;
        j["Description"sv] = o.Description;
        j["Id"sv] = o.Id;
        j["CanUninstall"sv] = o.CanUninstall;
        j["HasImage"sv] = o.HasImage;
        j["Status"sv] = o.Status;
}
void from_json(const json_t& j, OAIPluginInfo& o) {
    
    j.at("Name"sv).get_to(o.Name);
    
    j.at("Version"sv).get_to(o.Version);
    if(j.contains("ConfigurationFileName"sv))
    j.at("ConfigurationFileName"sv).get_to(o.ConfigurationFileName);
    
    j.at("Description"sv).get_to(o.Description);
    
    j.at("Id"sv).get_to(o.Id);
    
    j.at("CanUninstall"sv).get_to(o.CanUninstall);
    
    j.at("HasImage"sv).get_to(o.HasImage);
    
    j.at("Status"sv).get_to(o.Status);
}




void to_json(json_t& j, const OAIPluginInstallationCancelledMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIPluginInstallationCancelledMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAIPluginInstallationCompletedMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIPluginInstallationCompletedMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAIPluginInstallationFailedMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIPluginInstallationFailedMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAIPluginInstallingMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIPluginInstallingMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}



void to_json(json_t& j, const OAIPluginStatus& e) {
    switch (e)
    {
    
        case OAIPluginStatus::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIPluginStatus::ACTIVE:
            j = "Active";
            break;
    
        case OAIPluginStatus::RESTART:
            j = "Restart";
            break;
    
        case OAIPluginStatus::DELETED:
            j = "Deleted";
            break;
    
        case OAIPluginStatus::SUPERCEDED:
            j = "Superceded";
            break;
    
        case OAIPluginStatus::MALFUNCTIONED:
            j = "Malfunctioned";
            break;
    
        case OAIPluginStatus::NOTSUPPORTED:
            j = "NotSupported";
            break;
    
        case OAIPluginStatus::DISABLED:
            j = "Disabled";
            break;
    
    }
}
void from_json(const json_t& j, OAIPluginStatus& e) {
    auto s = j.get<std::string>();
    
    if (s == "Active"sv) {
        e = (OAIPluginStatus::ACTIVE);
    } 
    
    else if (s == "Restart"sv) {
        e = (OAIPluginStatus::RESTART);
    } 
    
    else if (s == "Deleted"sv) {
        e = (OAIPluginStatus::DELETED);
    } 
    
    else if (s == "Superceded"sv) {
        e = (OAIPluginStatus::SUPERCEDED);
    } 
    
    else if (s == "Malfunctioned"sv) {
        e = (OAIPluginStatus::MALFUNCTIONED);
    } 
    
    else if (s == "NotSupported"sv) {
        e = (OAIPluginStatus::NOTSUPPORTED);
    } 
    
    else if (s == "Disabled"sv) {
        e = (OAIPluginStatus::DISABLED);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIPluginStatus";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIPluginUninstalledMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIPluginUninstalledMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAIPreviousItemRequestDto& o) {
        j["PlaylistItemId"sv] = o.PlaylistItemId;
}
void from_json(const json_t& j, OAIPreviousItemRequestDto& o) {
    
    j.at("PlaylistItemId"sv).get_to(o.PlaylistItemId);
}







void to_json(json_t& j, const OAIProcessPriorityClass& e) {
    switch (e)
    {
    
        case OAIProcessPriorityClass::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIProcessPriorityClass::NORMAL:
            j = "Normal";
            break;
    
        case OAIProcessPriorityClass::IDLE:
            j = "Idle";
            break;
    
        case OAIProcessPriorityClass::HIGH:
            j = "High";
            break;
    
        case OAIProcessPriorityClass::REALTIME:
            j = "RealTime";
            break;
    
        case OAIProcessPriorityClass::BELOWNORMAL:
            j = "BelowNormal";
            break;
    
        case OAIProcessPriorityClass::ABOVENORMAL:
            j = "AboveNormal";
            break;
    
    }
}
void from_json(const json_t& j, OAIProcessPriorityClass& e) {
    auto s = j.get<std::string>();
    
    if (s == "Normal"sv) {
        e = (OAIProcessPriorityClass::NORMAL);
    } 
    
    else if (s == "Idle"sv) {
        e = (OAIProcessPriorityClass::IDLE);
    } 
    
    else if (s == "High"sv) {
        e = (OAIProcessPriorityClass::HIGH);
    } 
    
    else if (s == "RealTime"sv) {
        e = (OAIProcessPriorityClass::REALTIME);
    } 
    
    else if (s == "BelowNormal"sv) {
        e = (OAIProcessPriorityClass::BELOWNORMAL);
    } 
    
    else if (s == "AboveNormal"sv) {
        e = (OAIProcessPriorityClass::ABOVENORMAL);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIProcessPriorityClass";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIProfileCondition& o) {
        j["Condition"sv] = o.Condition;
        j["Property"sv] = o.Property;
        j["Value"sv] = o.Value;
        j["IsRequired"sv] = o.IsRequired;
}
void from_json(const json_t& j, OAIProfileCondition& o) {
    
    j.at("Condition"sv).get_to(o.Condition);
    
    j.at("Property"sv).get_to(o.Property);
    if(j.contains("Value"sv))
    j.at("Value"sv).get_to(o.Value);
    
    j.at("IsRequired"sv).get_to(o.IsRequired);
}



void to_json(json_t& j, const OAIProfileConditionType& e) {
    switch (e)
    {
    
        case OAIProfileConditionType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIProfileConditionType::EQUALS:
            j = "Equals";
            break;
    
        case OAIProfileConditionType::NOTEQUALS:
            j = "NotEquals";
            break;
    
        case OAIProfileConditionType::LESSTHANEQUAL:
            j = "LessThanEqual";
            break;
    
        case OAIProfileConditionType::GREATERTHANEQUAL:
            j = "GreaterThanEqual";
            break;
    
        case OAIProfileConditionType::EQUALSANY:
            j = "EqualsAny";
            break;
    
    }
}
void from_json(const json_t& j, OAIProfileConditionType& e) {
    auto s = j.get<std::string>();
    
    if (s == "Equals"sv) {
        e = (OAIProfileConditionType::EQUALS);
    } 
    
    else if (s == "NotEquals"sv) {
        e = (OAIProfileConditionType::NOTEQUALS);
    } 
    
    else if (s == "LessThanEqual"sv) {
        e = (OAIProfileConditionType::LESSTHANEQUAL);
    } 
    
    else if (s == "GreaterThanEqual"sv) {
        e = (OAIProfileConditionType::GREATERTHANEQUAL);
    } 
    
    else if (s == "EqualsAny"sv) {
        e = (OAIProfileConditionType::EQUALSANY);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIProfileConditionType";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIProfileConditionValue& e) {
    switch (e)
    {
    
        case OAIProfileConditionValue::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIProfileConditionValue::AUDIOCHANNELS:
            j = "AudioChannels";
            break;
    
        case OAIProfileConditionValue::AUDIOBITRATE:
            j = "AudioBitrate";
            break;
    
        case OAIProfileConditionValue::AUDIOPROFILE:
            j = "AudioProfile";
            break;
    
        case OAIProfileConditionValue::WIDTH:
            j = "Width";
            break;
    
        case OAIProfileConditionValue::HEIGHT:
            j = "Height";
            break;
    
        case OAIProfileConditionValue::HAS64BITOFFSETS:
            j = "Has64BitOffsets";
            break;
    
        case OAIProfileConditionValue::PACKETLENGTH:
            j = "PacketLength";
            break;
    
        case OAIProfileConditionValue::VIDEOBITDEPTH:
            j = "VideoBitDepth";
            break;
    
        case OAIProfileConditionValue::VIDEOBITRATE:
            j = "VideoBitrate";
            break;
    
        case OAIProfileConditionValue::VIDEOFRAMERATE:
            j = "VideoFramerate";
            break;
    
        case OAIProfileConditionValue::VIDEOLEVEL:
            j = "VideoLevel";
            break;
    
        case OAIProfileConditionValue::VIDEOPROFILE:
            j = "VideoProfile";
            break;
    
        case OAIProfileConditionValue::VIDEOTIMESTAMP:
            j = "VideoTimestamp";
            break;
    
        case OAIProfileConditionValue::ISANAMORPHIC:
            j = "IsAnamorphic";
            break;
    
        case OAIProfileConditionValue::REFFRAMES:
            j = "RefFrames";
            break;
    
        case OAIProfileConditionValue::NUMAUDIOSTREAMS:
            j = "NumAudioStreams";
            break;
    
        case OAIProfileConditionValue::NUMVIDEOSTREAMS:
            j = "NumVideoStreams";
            break;
    
        case OAIProfileConditionValue::ISSECONDARYAUDIO:
            j = "IsSecondaryAudio";
            break;
    
        case OAIProfileConditionValue::VIDEOCODECTAG:
            j = "VideoCodecTag";
            break;
    
        case OAIProfileConditionValue::ISAVC:
            j = "IsAvc";
            break;
    
        case OAIProfileConditionValue::ISINTERLACED:
            j = "IsInterlaced";
            break;
    
        case OAIProfileConditionValue::AUDIOSAMPLERATE:
            j = "AudioSampleRate";
            break;
    
        case OAIProfileConditionValue::AUDIOBITDEPTH:
            j = "AudioBitDepth";
            break;
    
        case OAIProfileConditionValue::VIDEORANGETYPE:
            j = "VideoRangeType";
            break;
    
    }
}
void from_json(const json_t& j, OAIProfileConditionValue& e) {
    auto s = j.get<std::string>();
    
    if (s == "AudioChannels"sv) {
        e = (OAIProfileConditionValue::AUDIOCHANNELS);
    } 
    
    else if (s == "AudioBitrate"sv) {
        e = (OAIProfileConditionValue::AUDIOBITRATE);
    } 
    
    else if (s == "AudioProfile"sv) {
        e = (OAIProfileConditionValue::AUDIOPROFILE);
    } 
    
    else if (s == "Width"sv) {
        e = (OAIProfileConditionValue::WIDTH);
    } 
    
    else if (s == "Height"sv) {
        e = (OAIProfileConditionValue::HEIGHT);
    } 
    
    else if (s == "Has64BitOffsets"sv) {
        e = (OAIProfileConditionValue::HAS64BITOFFSETS);
    } 
    
    else if (s == "PacketLength"sv) {
        e = (OAIProfileConditionValue::PACKETLENGTH);
    } 
    
    else if (s == "VideoBitDepth"sv) {
        e = (OAIProfileConditionValue::VIDEOBITDEPTH);
    } 
    
    else if (s == "VideoBitrate"sv) {
        e = (OAIProfileConditionValue::VIDEOBITRATE);
    } 
    
    else if (s == "VideoFramerate"sv) {
        e = (OAIProfileConditionValue::VIDEOFRAMERATE);
    } 
    
    else if (s == "VideoLevel"sv) {
        e = (OAIProfileConditionValue::VIDEOLEVEL);
    } 
    
    else if (s == "VideoProfile"sv) {
        e = (OAIProfileConditionValue::VIDEOPROFILE);
    } 
    
    else if (s == "VideoTimestamp"sv) {
        e = (OAIProfileConditionValue::VIDEOTIMESTAMP);
    } 
    
    else if (s == "IsAnamorphic"sv) {
        e = (OAIProfileConditionValue::ISANAMORPHIC);
    } 
    
    else if (s == "RefFrames"sv) {
        e = (OAIProfileConditionValue::REFFRAMES);
    } 
    
    else if (s == "NumAudioStreams"sv) {
        e = (OAIProfileConditionValue::NUMAUDIOSTREAMS);
    } 
    
    else if (s == "NumVideoStreams"sv) {
        e = (OAIProfileConditionValue::NUMVIDEOSTREAMS);
    } 
    
    else if (s == "IsSecondaryAudio"sv) {
        e = (OAIProfileConditionValue::ISSECONDARYAUDIO);
    } 
    
    else if (s == "VideoCodecTag"sv) {
        e = (OAIProfileConditionValue::VIDEOCODECTAG);
    } 
    
    else if (s == "IsAvc"sv) {
        e = (OAIProfileConditionValue::ISAVC);
    } 
    
    else if (s == "IsInterlaced"sv) {
        e = (OAIProfileConditionValue::ISINTERLACED);
    } 
    
    else if (s == "AudioSampleRate"sv) {
        e = (OAIProfileConditionValue::AUDIOSAMPLERATE);
    } 
    
    else if (s == "AudioBitDepth"sv) {
        e = (OAIProfileConditionValue::AUDIOBITDEPTH);
    } 
    
    else if (s == "VideoRangeType"sv) {
        e = (OAIProfileConditionValue::VIDEORANGETYPE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIProfileConditionValue";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIProgramAudio& e) {
    switch (e)
    {
    
        case OAIProgramAudio::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIProgramAudio::MONO:
            j = "Mono";
            break;
    
        case OAIProgramAudio::STEREO:
            j = "Stereo";
            break;
    
        case OAIProgramAudio::DOLBY:
            j = "Dolby";
            break;
    
        case OAIProgramAudio::DOLBYDIGITAL:
            j = "DolbyDigital";
            break;
    
        case OAIProgramAudio::THX:
            j = "Thx";
            break;
    
        case OAIProgramAudio::ATMOS:
            j = "Atmos";
            break;
    
    }
}
void from_json(const json_t& j, OAIProgramAudio& e) {
    auto s = j.get<std::string>();
    
    if (s == "Mono"sv) {
        e = (OAIProgramAudio::MONO);
    } 
    
    else if (s == "Stereo"sv) {
        e = (OAIProgramAudio::STEREO);
    } 
    
    else if (s == "Dolby"sv) {
        e = (OAIProgramAudio::DOLBY);
    } 
    
    else if (s == "DolbyDigital"sv) {
        e = (OAIProgramAudio::DOLBYDIGITAL);
    } 
    
    else if (s == "Thx"sv) {
        e = (OAIProgramAudio::THX);
    } 
    
    else if (s == "Atmos"sv) {
        e = (OAIProgramAudio::ATMOS);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIProgramAudio";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIPublicSystemInfo& o) {
        j["LocalAddress"sv] = o.LocalAddress;
        j["ServerName"sv] = o.ServerName;
        j["Version"sv] = o.Version;
        j["ProductName"sv] = o.ProductName;
        j["OperatingSystem"sv] = o.OperatingSystem;
        j["Id"sv] = o.Id;
        j["StartupWizardCompleted"sv] = o.StartupWizardCompleted;
}
void from_json(const json_t& j, OAIPublicSystemInfo& o) {
    if(j.contains("LocalAddress"sv))
    j.at("LocalAddress"sv).get_to(o.LocalAddress);
    if(j.contains("ServerName"sv))
    j.at("ServerName"sv).get_to(o.ServerName);
    if(j.contains("Version"sv))
    j.at("Version"sv).get_to(o.Version);
    if(j.contains("ProductName"sv))
    j.at("ProductName"sv).get_to(o.ProductName);
    if(j.contains("OperatingSystem"sv))
    j.at("OperatingSystem"sv).get_to(o.OperatingSystem);
    if(j.contains("Id"sv))
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("StartupWizardCompleted"sv))
    j.at("StartupWizardCompleted"sv).get_to(o.StartupWizardCompleted);
}




void to_json(json_t& j, const OAIQueryFilters& o) {
        j["Genres"sv] = o.Genres;
        j["Tags"sv] = o.Tags;
}
void from_json(const json_t& j, OAIQueryFilters& o) {
    if(j.contains("Genres"sv))
    j.at("Genres"sv).get_to(o.Genres);
    if(j.contains("Tags"sv))
    j.at("Tags"sv).get_to(o.Tags);
}




void to_json(json_t& j, const OAIQueryFiltersLegacy& o) {
        j["Genres"sv] = o.Genres;
        j["Tags"sv] = o.Tags;
        j["OfficialRatings"sv] = o.OfficialRatings;
        j["Years"sv] = o.Years;
}
void from_json(const json_t& j, OAIQueryFiltersLegacy& o) {
    if(j.contains("Genres"sv))
    j.at("Genres"sv).get_to(o.Genres);
    if(j.contains("Tags"sv))
    j.at("Tags"sv).get_to(o.Tags);
    if(j.contains("OfficialRatings"sv))
    j.at("OfficialRatings"sv).get_to(o.OfficialRatings);
    if(j.contains("Years"sv))
    j.at("Years"sv).get_to(o.Years);
}




void to_json(json_t& j, const OAIQueueItem& o) {
        j["Id"sv] = o.Id;
        j["PlaylistItemId"sv] = o.PlaylistItemId;
}
void from_json(const json_t& j, OAIQueueItem& o) {
    
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("PlaylistItemId"sv))
    j.at("PlaylistItemId"sv).get_to(o.PlaylistItemId);
}




void to_json(json_t& j, const OAIQueueRequestDto& o) {
        j["ItemIds"sv] = o.ItemIds;
        j["Mode"sv] = o.Mode;
}
void from_json(const json_t& j, OAIQueueRequestDto& o) {
    
    j.at("ItemIds"sv).get_to(o.ItemIds);
    
    j.at("Mode"sv).get_to(o.Mode);
}




void to_json(json_t& j, const OAIQuickConnectDto& o) {
        j["Secret"sv] = o.Secret;
}
void from_json(const json_t& j, OAIQuickConnectDto& o) {
    
    j.at("Secret"sv).get_to(o.Secret);
}




void to_json(json_t& j, const OAIQuickConnectResult& o) {
        j["Authenticated"sv] = o.Authenticated;
        j["Secret"sv] = o.Secret;
        j["Code"sv] = o.Code;
        j["DeviceId"sv] = o.DeviceId;
        j["DeviceName"sv] = o.DeviceName;
        j["AppName"sv] = o.AppName;
        j["AppVersion"sv] = o.AppVersion;
        j["DateAdded"sv] = o.DateAdded;
}
void from_json(const json_t& j, OAIQuickConnectResult& o) {
    
    j.at("Authenticated"sv).get_to(o.Authenticated);
    
    j.at("Secret"sv).get_to(o.Secret);
    
    j.at("Code"sv).get_to(o.Code);
    
    j.at("DeviceId"sv).get_to(o.DeviceId);
    
    j.at("DeviceName"sv).get_to(o.DeviceName);
    
    j.at("AppName"sv).get_to(o.AppName);
    
    j.at("AppVersion"sv).get_to(o.AppVersion);
    
    j.at("DateAdded"sv).get_to(o.DateAdded);
}



void to_json(json_t& j, const OAIRatingType& e) {
    switch (e)
    {
    
        case OAIRatingType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIRatingType::SCORE:
            j = "Score";
            break;
    
        case OAIRatingType::LIKES:
            j = "Likes";
            break;
    
    }
}
void from_json(const json_t& j, OAIRatingType& e) {
    auto s = j.get<std::string>();
    
    if (s == "Score"sv) {
        e = (OAIRatingType::SCORE);
    } 
    
    else if (s == "Likes"sv) {
        e = (OAIRatingType::LIKES);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIRatingType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIReadyRequestDto& o) {
        j["When"sv] = o.When;
        j["PositionTicks"sv] = o.PositionTicks;
        j["IsPlaying"sv] = o.IsPlaying;
        j["PlaylistItemId"sv] = o.PlaylistItemId;
}
void from_json(const json_t& j, OAIReadyRequestDto& o) {
    
    j.at("When"sv).get_to(o.When);
    
    j.at("PositionTicks"sv).get_to(o.PositionTicks);
    
    j.at("IsPlaying"sv).get_to(o.IsPlaying);
    
    j.at("PlaylistItemId"sv).get_to(o.PlaylistItemId);
}




void to_json(json_t& j, const OAIRecommendationDto& o) {
        j["Items"sv] = o.Items;
        j["RecommendationType"sv] = o.RecommendationType;
        j["BaselineItemName"sv] = o.BaselineItemName;
        j["CategoryId"sv] = o.CategoryId;
}
void from_json(const json_t& j, OAIRecommendationDto& o) {
    if(j.contains("Items"sv))
    j.at("Items"sv).get_to(o.Items);
    
    j.at("RecommendationType"sv).get_to(o.RecommendationType);
    if(j.contains("BaselineItemName"sv))
    j.at("BaselineItemName"sv).get_to(o.BaselineItemName);
    
    j.at("CategoryId"sv).get_to(o.CategoryId);
}



void to_json(json_t& j, const OAIRecommendationType& e) {
    switch (e)
    {
    
        case OAIRecommendationType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIRecommendationType::SIMILARTORECENTLYPLAYED:
            j = "SimilarToRecentlyPlayed";
            break;
    
        case OAIRecommendationType::SIMILARTOLIKEDITEM:
            j = "SimilarToLikedItem";
            break;
    
        case OAIRecommendationType::HASDIRECTORFROMRECENTLYPLAYED:
            j = "HasDirectorFromRecentlyPlayed";
            break;
    
        case OAIRecommendationType::HASACTORFROMRECENTLYPLAYED:
            j = "HasActorFromRecentlyPlayed";
            break;
    
        case OAIRecommendationType::HASLIKEDDIRECTOR:
            j = "HasLikedDirector";
            break;
    
        case OAIRecommendationType::HASLIKEDACTOR:
            j = "HasLikedActor";
            break;
    
    }
}
void from_json(const json_t& j, OAIRecommendationType& e) {
    auto s = j.get<std::string>();
    
    if (s == "SimilarToRecentlyPlayed"sv) {
        e = (OAIRecommendationType::SIMILARTORECENTLYPLAYED);
    } 
    
    else if (s == "SimilarToLikedItem"sv) {
        e = (OAIRecommendationType::SIMILARTOLIKEDITEM);
    } 
    
    else if (s == "HasDirectorFromRecentlyPlayed"sv) {
        e = (OAIRecommendationType::HASDIRECTORFROMRECENTLYPLAYED);
    } 
    
    else if (s == "HasActorFromRecentlyPlayed"sv) {
        e = (OAIRecommendationType::HASACTORFROMRECENTLYPLAYED);
    } 
    
    else if (s == "HasLikedDirector"sv) {
        e = (OAIRecommendationType::HASLIKEDDIRECTOR);
    } 
    
    else if (s == "HasLikedActor"sv) {
        e = (OAIRecommendationType::HASLIKEDACTOR);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIRecommendationType";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIRecordingStatus& e) {
    switch (e)
    {
    
        case OAIRecordingStatus::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIRecordingStatus::NEW:
            j = "New";
            break;
    
        case OAIRecordingStatus::INPROGRESS:
            j = "InProgress";
            break;
    
        case OAIRecordingStatus::COMPLETED:
            j = "Completed";
            break;
    
        case OAIRecordingStatus::CANCELLED:
            j = "Cancelled";
            break;
    
        case OAIRecordingStatus::CONFLICTEDOK:
            j = "ConflictedOk";
            break;
    
        case OAIRecordingStatus::CONFLICTEDNOTOK:
            j = "ConflictedNotOk";
            break;
    
        case OAIRecordingStatus::ERROR:
            j = "Error";
            break;
    
    }
}
void from_json(const json_t& j, OAIRecordingStatus& e) {
    auto s = j.get<std::string>();
    
    if (s == "New"sv) {
        e = (OAIRecordingStatus::NEW);
    } 
    
    else if (s == "InProgress"sv) {
        e = (OAIRecordingStatus::INPROGRESS);
    } 
    
    else if (s == "Completed"sv) {
        e = (OAIRecordingStatus::COMPLETED);
    } 
    
    else if (s == "Cancelled"sv) {
        e = (OAIRecordingStatus::CANCELLED);
    } 
    
    else if (s == "ConflictedOk"sv) {
        e = (OAIRecordingStatus::CONFLICTEDOK);
    } 
    
    else if (s == "ConflictedNotOk"sv) {
        e = (OAIRecordingStatus::CONFLICTEDNOTOK);
    } 
    
    else if (s == "Error"sv) {
        e = (OAIRecordingStatus::ERROR);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIRecordingStatus";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIRefreshProgressMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIRefreshProgressMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAIRemoteImageInfo& o) {
        j["ProviderName"sv] = o.ProviderName;
        j["Url"sv] = o.Url;
        j["ThumbnailUrl"sv] = o.ThumbnailUrl;
        j["Height"sv] = o.Height;
        j["Width"sv] = o.Width;
        j["CommunityRating"sv] = o.CommunityRating;
        j["VoteCount"sv] = o.VoteCount;
        j["Language"sv] = o.Language;
        j["Type"sv] = o.Type;
        j["RatingType"sv] = o.RatingType;
}
void from_json(const json_t& j, OAIRemoteImageInfo& o) {
    if(j.contains("ProviderName"sv))
    j.at("ProviderName"sv).get_to(o.ProviderName);
    if(j.contains("Url"sv))
    j.at("Url"sv).get_to(o.Url);
    if(j.contains("ThumbnailUrl"sv))
    j.at("ThumbnailUrl"sv).get_to(o.ThumbnailUrl);
    if(j.contains("Height"sv))
    j.at("Height"sv).get_to(o.Height);
    if(j.contains("Width"sv))
    j.at("Width"sv).get_to(o.Width);
    if(j.contains("CommunityRating"sv))
    j.at("CommunityRating"sv).get_to(o.CommunityRating);
    if(j.contains("VoteCount"sv))
    j.at("VoteCount"sv).get_to(o.VoteCount);
    if(j.contains("Language"sv))
    j.at("Language"sv).get_to(o.Language);
    
    j.at("Type"sv).get_to(o.Type);
    
    j.at("RatingType"sv).get_to(o.RatingType);
}




void to_json(json_t& j, const OAIRemoteImageResult& o) {
        j["Images"sv] = o.Images;
        j["TotalRecordCount"sv] = o.TotalRecordCount;
        j["Providers"sv] = o.Providers;
}
void from_json(const json_t& j, OAIRemoteImageResult& o) {
    if(j.contains("Images"sv))
    j.at("Images"sv).get_to(o.Images);
    
    j.at("TotalRecordCount"sv).get_to(o.TotalRecordCount);
    if(j.contains("Providers"sv))
    j.at("Providers"sv).get_to(o.Providers);
}




void to_json(json_t& j, const OAIRemoteLyricInfoDto& o) {
        j["Id"sv] = o.Id;
        j["ProviderName"sv] = o.ProviderName;
        j["Lyrics"sv] = o.Lyrics;
}
void from_json(const json_t& j, OAIRemoteLyricInfoDto& o) {
    
    j.at("Id"sv).get_to(o.Id);
    
    j.at("ProviderName"sv).get_to(o.ProviderName);
    
    j.at("Lyrics"sv).get_to(o.Lyrics);
}




void to_json(json_t& j, const OAIRemoteSearchResult& o) {
        j["Name"sv] = o.Name;
        j["ProviderIds"sv] = o.ProviderIds;
        j["ProductionYear"sv] = o.ProductionYear;
        j["IndexNumber"sv] = o.IndexNumber;
        j["IndexNumberEnd"sv] = o.IndexNumberEnd;
        j["ParentIndexNumber"sv] = o.ParentIndexNumber;
        j["PremiereDate"sv] = o.PremiereDate;
        j["ImageUrl"sv] = o.ImageUrl;
        j["SearchProviderName"sv] = o.SearchProviderName;
        j["Overview"sv] = o.Overview;
        j["AlbumArtist"sv] = o.AlbumArtist;
        j["Artists"sv] = o.Artists;
}
void from_json(const json_t& j, OAIRemoteSearchResult& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("ProviderIds"sv))
    j.at("ProviderIds"sv).get_to(o.ProviderIds);
    if(j.contains("ProductionYear"sv))
    j.at("ProductionYear"sv).get_to(o.ProductionYear);
    if(j.contains("IndexNumber"sv))
    j.at("IndexNumber"sv).get_to(o.IndexNumber);
    if(j.contains("IndexNumberEnd"sv))
    j.at("IndexNumberEnd"sv).get_to(o.IndexNumberEnd);
    if(j.contains("ParentIndexNumber"sv))
    j.at("ParentIndexNumber"sv).get_to(o.ParentIndexNumber);
    if(j.contains("PremiereDate"sv))
    j.at("PremiereDate"sv).get_to(o.PremiereDate);
    if(j.contains("ImageUrl"sv))
    j.at("ImageUrl"sv).get_to(o.ImageUrl);
    if(j.contains("SearchProviderName"sv))
    j.at("SearchProviderName"sv).get_to(o.SearchProviderName);
    if(j.contains("Overview"sv))
    j.at("Overview"sv).get_to(o.Overview);
    if(j.contains("AlbumArtist"sv))
    j.at("AlbumArtist"sv).get_to(o.AlbumArtist);
    if(j.contains("Artists"sv))
    j.at("Artists"sv).get_to(o.Artists);
}




void to_json(json_t& j, const OAIRemoteSubtitleInfo& o) {
        j["ThreeLetterISOLanguageName"sv] = o.ThreeLetterISOLanguageName;
        j["Id"sv] = o.Id;
        j["ProviderName"sv] = o.ProviderName;
        j["Name"sv] = o.Name;
        j["Format"sv] = o.Format;
        j["Author"sv] = o.Author;
        j["Comment"sv] = o.Comment;
        j["DateCreated"sv] = o.DateCreated;
        j["CommunityRating"sv] = o.CommunityRating;
        j["FrameRate"sv] = o.FrameRate;
        j["DownloadCount"sv] = o.DownloadCount;
        j["IsHashMatch"sv] = o.IsHashMatch;
        j["AiTranslated"sv] = o.AiTranslated;
        j["MachineTranslated"sv] = o.MachineTranslated;
        j["Forced"sv] = o.Forced;
        j["HearingImpaired"sv] = o.HearingImpaired;
}
void from_json(const json_t& j, OAIRemoteSubtitleInfo& o) {
    if(j.contains("ThreeLetterISOLanguageName"sv))
    j.at("ThreeLetterISOLanguageName"sv).get_to(o.ThreeLetterISOLanguageName);
    if(j.contains("Id"sv))
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("ProviderName"sv))
    j.at("ProviderName"sv).get_to(o.ProviderName);
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Format"sv))
    j.at("Format"sv).get_to(o.Format);
    if(j.contains("Author"sv))
    j.at("Author"sv).get_to(o.Author);
    if(j.contains("Comment"sv))
    j.at("Comment"sv).get_to(o.Comment);
    if(j.contains("DateCreated"sv))
    j.at("DateCreated"sv).get_to(o.DateCreated);
    if(j.contains("CommunityRating"sv))
    j.at("CommunityRating"sv).get_to(o.CommunityRating);
    if(j.contains("FrameRate"sv))
    j.at("FrameRate"sv).get_to(o.FrameRate);
    if(j.contains("DownloadCount"sv))
    j.at("DownloadCount"sv).get_to(o.DownloadCount);
    if(j.contains("IsHashMatch"sv))
    j.at("IsHashMatch"sv).get_to(o.IsHashMatch);
    if(j.contains("AiTranslated"sv))
    j.at("AiTranslated"sv).get_to(o.AiTranslated);
    if(j.contains("MachineTranslated"sv))
    j.at("MachineTranslated"sv).get_to(o.MachineTranslated);
    if(j.contains("Forced"sv))
    j.at("Forced"sv).get_to(o.Forced);
    if(j.contains("HearingImpaired"sv))
    j.at("HearingImpaired"sv).get_to(o.HearingImpaired);
}




void to_json(json_t& j, const OAIRemoveFromPlaylistRequestDto& o) {
        j["PlaylistItemIds"sv] = o.PlaylistItemIds;
        j["ClearPlaylist"sv] = o.ClearPlaylist;
        j["ClearPlayingItem"sv] = o.ClearPlayingItem;
}
void from_json(const json_t& j, OAIRemoveFromPlaylistRequestDto& o) {
    
    j.at("PlaylistItemIds"sv).get_to(o.PlaylistItemIds);
    
    j.at("ClearPlaylist"sv).get_to(o.ClearPlaylist);
    
    j.at("ClearPlayingItem"sv).get_to(o.ClearPlayingItem);
}



void to_json(json_t& j, const OAIRepeatMode& e) {
    switch (e)
    {
    
        case OAIRepeatMode::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIRepeatMode::REPEATNONE:
            j = "RepeatNone";
            break;
    
        case OAIRepeatMode::REPEATALL:
            j = "RepeatAll";
            break;
    
        case OAIRepeatMode::REPEATONE:
            j = "RepeatOne";
            break;
    
    }
}
void from_json(const json_t& j, OAIRepeatMode& e) {
    auto s = j.get<std::string>();
    
    if (s == "RepeatNone"sv) {
        e = (OAIRepeatMode::REPEATNONE);
    } 
    
    else if (s == "RepeatAll"sv) {
        e = (OAIRepeatMode::REPEATALL);
    } 
    
    else if (s == "RepeatOne"sv) {
        e = (OAIRepeatMode::REPEATONE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIRepeatMode";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIRepositoryInfo& o) {
        j["Name"sv] = o.Name;
        j["Url"sv] = o.Url;
        j["Enabled"sv] = o.Enabled;
}
void from_json(const json_t& j, OAIRepositoryInfo& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Url"sv))
    j.at("Url"sv).get_to(o.Url);
    
    j.at("Enabled"sv).get_to(o.Enabled);
}




void to_json(json_t& j, const OAIRestartRequiredMessage& o) {
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIRestartRequiredMessage& o) {
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAIScheduledTaskEndedMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIScheduledTaskEndedMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAIScheduledTasksInfoMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIScheduledTasksInfoMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAIScheduledTasksInfoStartMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIScheduledTasksInfoStartMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAIScheduledTasksInfoStopMessage& o) {
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIScheduledTasksInfoStopMessage& o) {
    
    j.at("MessageType"sv).get_to(o.MessageType);
}



void to_json(json_t& j, const OAIScrollDirection& e) {
    switch (e)
    {
    
        case OAIScrollDirection::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIScrollDirection::HORIZONTAL:
            j = "Horizontal";
            break;
    
        case OAIScrollDirection::VERTICAL:
            j = "Vertical";
            break;
    
    }
}
void from_json(const json_t& j, OAIScrollDirection& e) {
    auto s = j.get<std::string>();
    
    if (s == "Horizontal"sv) {
        e = (OAIScrollDirection::HORIZONTAL);
    } 
    
    else if (s == "Vertical"sv) {
        e = (OAIScrollDirection::VERTICAL);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIScrollDirection";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAISearchHint& o) {
        j["ItemId"sv] = o.ItemId;
        j["Id"sv] = o.Id;
        j["Name"sv] = o.Name;
        j["MatchedTerm"sv] = o.MatchedTerm;
        j["IndexNumber"sv] = o.IndexNumber;
        j["ProductionYear"sv] = o.ProductionYear;
        j["ParentIndexNumber"sv] = o.ParentIndexNumber;
        j["PrimaryImageTag"sv] = o.PrimaryImageTag;
        j["ThumbImageTag"sv] = o.ThumbImageTag;
        j["ThumbImageItemId"sv] = o.ThumbImageItemId;
        j["BackdropImageTag"sv] = o.BackdropImageTag;
        j["BackdropImageItemId"sv] = o.BackdropImageItemId;
        j["Type"sv] = o.Type;
        j["IsFolder"sv] = o.IsFolder;
        j["RunTimeTicks"sv] = o.RunTimeTicks;
        j["MediaType"sv] = o.MediaType;
        j["StartDate"sv] = o.StartDate;
        j["EndDate"sv] = o.EndDate;
        j["Series"sv] = o.Series;
        j["Status"sv] = o.Status;
        j["Album"sv] = o.Album;
        j["AlbumId"sv] = o.AlbumId;
        j["AlbumArtist"sv] = o.AlbumArtist;
        j["Artists"sv] = o.Artists;
        j["SongCount"sv] = o.SongCount;
        j["EpisodeCount"sv] = o.EpisodeCount;
        j["ChannelId"sv] = o.ChannelId;
        j["ChannelName"sv] = o.ChannelName;
        j["PrimaryImageAspectRatio"sv] = o.PrimaryImageAspectRatio;
}
void from_json(const json_t& j, OAISearchHint& o) {
    
    j.at("ItemId"sv).get_to(o.ItemId);
    
    j.at("Id"sv).get_to(o.Id);
    
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("MatchedTerm"sv))
    j.at("MatchedTerm"sv).get_to(o.MatchedTerm);
    if(j.contains("IndexNumber"sv))
    j.at("IndexNumber"sv).get_to(o.IndexNumber);
    if(j.contains("ProductionYear"sv))
    j.at("ProductionYear"sv).get_to(o.ProductionYear);
    if(j.contains("ParentIndexNumber"sv))
    j.at("ParentIndexNumber"sv).get_to(o.ParentIndexNumber);
    if(j.contains("PrimaryImageTag"sv))
    j.at("PrimaryImageTag"sv).get_to(o.PrimaryImageTag);
    if(j.contains("ThumbImageTag"sv))
    j.at("ThumbImageTag"sv).get_to(o.ThumbImageTag);
    if(j.contains("ThumbImageItemId"sv))
    j.at("ThumbImageItemId"sv).get_to(o.ThumbImageItemId);
    if(j.contains("BackdropImageTag"sv))
    j.at("BackdropImageTag"sv).get_to(o.BackdropImageTag);
    if(j.contains("BackdropImageItemId"sv))
    j.at("BackdropImageItemId"sv).get_to(o.BackdropImageItemId);
    
    j.at("Type"sv).get_to(o.Type);
    if(j.contains("IsFolder"sv))
    j.at("IsFolder"sv).get_to(o.IsFolder);
    if(j.contains("RunTimeTicks"sv))
    j.at("RunTimeTicks"sv).get_to(o.RunTimeTicks);
    
    j.at("MediaType"sv).get_to(o.MediaType);
    if(j.contains("StartDate"sv))
    j.at("StartDate"sv).get_to(o.StartDate);
    if(j.contains("EndDate"sv))
    j.at("EndDate"sv).get_to(o.EndDate);
    if(j.contains("Series"sv))
    j.at("Series"sv).get_to(o.Series);
    if(j.contains("Status"sv))
    j.at("Status"sv).get_to(o.Status);
    if(j.contains("Album"sv))
    j.at("Album"sv).get_to(o.Album);
    if(j.contains("AlbumId"sv))
    j.at("AlbumId"sv).get_to(o.AlbumId);
    if(j.contains("AlbumArtist"sv))
    j.at("AlbumArtist"sv).get_to(o.AlbumArtist);
    
    j.at("Artists"sv).get_to(o.Artists);
    if(j.contains("SongCount"sv))
    j.at("SongCount"sv).get_to(o.SongCount);
    if(j.contains("EpisodeCount"sv))
    j.at("EpisodeCount"sv).get_to(o.EpisodeCount);
    if(j.contains("ChannelId"sv))
    j.at("ChannelId"sv).get_to(o.ChannelId);
    if(j.contains("ChannelName"sv))
    j.at("ChannelName"sv).get_to(o.ChannelName);
    if(j.contains("PrimaryImageAspectRatio"sv))
    j.at("PrimaryImageAspectRatio"sv).get_to(o.PrimaryImageAspectRatio);
}




void to_json(json_t& j, const OAISearchHintResult& o) {
        j["SearchHints"sv] = o.SearchHints;
        j["TotalRecordCount"sv] = o.TotalRecordCount;
}
void from_json(const json_t& j, OAISearchHintResult& o) {
    
    j.at("SearchHints"sv).get_to(o.SearchHints);
    
    j.at("TotalRecordCount"sv).get_to(o.TotalRecordCount);
}




void to_json(json_t& j, const OAISeekRequestDto& o) {
        j["PositionTicks"sv] = o.PositionTicks;
}
void from_json(const json_t& j, OAISeekRequestDto& o) {
    
    j.at("PositionTicks"sv).get_to(o.PositionTicks);
}




void to_json(json_t& j, const OAISendCommand& o) {
        j["GroupId"sv] = o.GroupId;
        j["PlaylistItemId"sv] = o.PlaylistItemId;
        j["When"sv] = o.When;
        j["PositionTicks"sv] = o.PositionTicks;
        j["Command"sv] = o.Command;
        j["EmittedAt"sv] = o.EmittedAt;
}
void from_json(const json_t& j, OAISendCommand& o) {
    
    j.at("GroupId"sv).get_to(o.GroupId);
    
    j.at("PlaylistItemId"sv).get_to(o.PlaylistItemId);
    
    j.at("When"sv).get_to(o.When);
    if(j.contains("PositionTicks"sv))
    j.at("PositionTicks"sv).get_to(o.PositionTicks);
    
    j.at("Command"sv).get_to(o.Command);
    
    j.at("EmittedAt"sv).get_to(o.EmittedAt);
}



void to_json(json_t& j, const OAISendCommandType& e) {
    switch (e)
    {
    
        case OAISendCommandType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAISendCommandType::UNPAUSE:
            j = "Unpause";
            break;
    
        case OAISendCommandType::PAUSE:
            j = "Pause";
            break;
    
        case OAISendCommandType::STOP:
            j = "Stop";
            break;
    
        case OAISendCommandType::SEEK:
            j = "Seek";
            break;
    
    }
}
void from_json(const json_t& j, OAISendCommandType& e) {
    auto s = j.get<std::string>();
    
    if (s == "Unpause"sv) {
        e = (OAISendCommandType::UNPAUSE);
    } 
    
    else if (s == "Pause"sv) {
        e = (OAISendCommandType::PAUSE);
    } 
    
    else if (s == "Stop"sv) {
        e = (OAISendCommandType::STOP);
    } 
    
    else if (s == "Seek"sv) {
        e = (OAISendCommandType::SEEK);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAISendCommandType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAISeriesInfo& o) {
        j["Name"sv] = o.Name;
        j["OriginalTitle"sv] = o.OriginalTitle;
        j["Path"sv] = o.Path;
        j["MetadataLanguage"sv] = o.MetadataLanguage;
        j["MetadataCountryCode"sv] = o.MetadataCountryCode;
        j["ProviderIds"sv] = o.ProviderIds;
        j["Year"sv] = o.Year;
        j["IndexNumber"sv] = o.IndexNumber;
        j["ParentIndexNumber"sv] = o.ParentIndexNumber;
        j["PremiereDate"sv] = o.PremiereDate;
        j["IsAutomated"sv] = o.IsAutomated;
}
void from_json(const json_t& j, OAISeriesInfo& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("OriginalTitle"sv))
    j.at("OriginalTitle"sv).get_to(o.OriginalTitle);
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("MetadataLanguage"sv))
    j.at("MetadataLanguage"sv).get_to(o.MetadataLanguage);
    if(j.contains("MetadataCountryCode"sv))
    j.at("MetadataCountryCode"sv).get_to(o.MetadataCountryCode);
    if(j.contains("ProviderIds"sv))
    j.at("ProviderIds"sv).get_to(o.ProviderIds);
    if(j.contains("Year"sv))
    j.at("Year"sv).get_to(o.Year);
    if(j.contains("IndexNumber"sv))
    j.at("IndexNumber"sv).get_to(o.IndexNumber);
    if(j.contains("ParentIndexNumber"sv))
    j.at("ParentIndexNumber"sv).get_to(o.ParentIndexNumber);
    if(j.contains("PremiereDate"sv))
    j.at("PremiereDate"sv).get_to(o.PremiereDate);
    
    j.at("IsAutomated"sv).get_to(o.IsAutomated);
}




void to_json(json_t& j, const OAISeriesInfoRemoteSearchQuery& o) {
        j["SearchInfo"sv] = o.SearchInfo;
        j["ItemId"sv] = o.ItemId;
        j["SearchProviderName"sv] = o.SearchProviderName;
        j["IncludeDisabledProviders"sv] = o.IncludeDisabledProviders;
}
void from_json(const json_t& j, OAISeriesInfoRemoteSearchQuery& o) {
    if(j.contains("SearchInfo"sv))
    j.at("SearchInfo"sv).get_to(o.SearchInfo);
    
    j.at("ItemId"sv).get_to(o.ItemId);
    if(j.contains("SearchProviderName"sv))
    j.at("SearchProviderName"sv).get_to(o.SearchProviderName);
    
    j.at("IncludeDisabledProviders"sv).get_to(o.IncludeDisabledProviders);
}



void to_json(json_t& j, const OAISeriesStatus& e) {
    switch (e)
    {
    
        case OAISeriesStatus::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAISeriesStatus::CONTINUING:
            j = "Continuing";
            break;
    
        case OAISeriesStatus::ENDED:
            j = "Ended";
            break;
    
        case OAISeriesStatus::UNRELEASED:
            j = "Unreleased";
            break;
    
    }
}
void from_json(const json_t& j, OAISeriesStatus& e) {
    auto s = j.get<std::string>();
    
    if (s == "Continuing"sv) {
        e = (OAISeriesStatus::CONTINUING);
    } 
    
    else if (s == "Ended"sv) {
        e = (OAISeriesStatus::ENDED);
    } 
    
    else if (s == "Unreleased"sv) {
        e = (OAISeriesStatus::UNRELEASED);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAISeriesStatus";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAISeriesTimerCancelledMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAISeriesTimerCancelledMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAISeriesTimerCreatedMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAISeriesTimerCreatedMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAISeriesTimerInfoDto& o) {
        j["Id"sv] = o.Id;
        j["Type"sv] = o.Type;
        j["ServerId"sv] = o.ServerId;
        j["ExternalId"sv] = o.ExternalId;
        j["ChannelId"sv] = o.ChannelId;
        j["ExternalChannelId"sv] = o.ExternalChannelId;
        j["ChannelName"sv] = o.ChannelName;
        j["ChannelPrimaryImageTag"sv] = o.ChannelPrimaryImageTag;
        j["ProgramId"sv] = o.ProgramId;
        j["ExternalProgramId"sv] = o.ExternalProgramId;
        j["Name"sv] = o.Name;
        j["Overview"sv] = o.Overview;
        j["StartDate"sv] = o.StartDate;
        j["EndDate"sv] = o.EndDate;
        j["ServiceName"sv] = o.ServiceName;
        j["Priority"sv] = o.Priority;
        j["PrePaddingSeconds"sv] = o.PrePaddingSeconds;
        j["PostPaddingSeconds"sv] = o.PostPaddingSeconds;
        j["IsPrePaddingRequired"sv] = o.IsPrePaddingRequired;
        j["ParentBackdropItemId"sv] = o.ParentBackdropItemId;
        j["ParentBackdropImageTags"sv] = o.ParentBackdropImageTags;
        j["IsPostPaddingRequired"sv] = o.IsPostPaddingRequired;
        j["KeepUntil"sv] = o.KeepUntil;
        j["RecordAnyTime"sv] = o.RecordAnyTime;
        j["SkipEpisodesInLibrary"sv] = o.SkipEpisodesInLibrary;
        j["RecordAnyChannel"sv] = o.RecordAnyChannel;
        j["KeepUpTo"sv] = o.KeepUpTo;
        j["RecordNewOnly"sv] = o.RecordNewOnly;
        j["Days"sv] = o.Days;
        j["DayPattern"sv] = o.DayPattern;
        j["ImageTags"sv] = o.ImageTags;
        j["ParentThumbItemId"sv] = o.ParentThumbItemId;
        j["ParentThumbImageTag"sv] = o.ParentThumbImageTag;
        j["ParentPrimaryImageItemId"sv] = o.ParentPrimaryImageItemId;
        j["ParentPrimaryImageTag"sv] = o.ParentPrimaryImageTag;
}
void from_json(const json_t& j, OAISeriesTimerInfoDto& o) {
    if(j.contains("Id"sv))
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("Type"sv))
    j.at("Type"sv).get_to(o.Type);
    if(j.contains("ServerId"sv))
    j.at("ServerId"sv).get_to(o.ServerId);
    if(j.contains("ExternalId"sv))
    j.at("ExternalId"sv).get_to(o.ExternalId);
    
    j.at("ChannelId"sv).get_to(o.ChannelId);
    if(j.contains("ExternalChannelId"sv))
    j.at("ExternalChannelId"sv).get_to(o.ExternalChannelId);
    if(j.contains("ChannelName"sv))
    j.at("ChannelName"sv).get_to(o.ChannelName);
    if(j.contains("ChannelPrimaryImageTag"sv))
    j.at("ChannelPrimaryImageTag"sv).get_to(o.ChannelPrimaryImageTag);
    if(j.contains("ProgramId"sv))
    j.at("ProgramId"sv).get_to(o.ProgramId);
    if(j.contains("ExternalProgramId"sv))
    j.at("ExternalProgramId"sv).get_to(o.ExternalProgramId);
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Overview"sv))
    j.at("Overview"sv).get_to(o.Overview);
    
    j.at("StartDate"sv).get_to(o.StartDate);
    
    j.at("EndDate"sv).get_to(o.EndDate);
    if(j.contains("ServiceName"sv))
    j.at("ServiceName"sv).get_to(o.ServiceName);
    
    j.at("Priority"sv).get_to(o.Priority);
    
    j.at("PrePaddingSeconds"sv).get_to(o.PrePaddingSeconds);
    
    j.at("PostPaddingSeconds"sv).get_to(o.PostPaddingSeconds);
    
    j.at("IsPrePaddingRequired"sv).get_to(o.IsPrePaddingRequired);
    if(j.contains("ParentBackdropItemId"sv))
    j.at("ParentBackdropItemId"sv).get_to(o.ParentBackdropItemId);
    if(j.contains("ParentBackdropImageTags"sv))
    j.at("ParentBackdropImageTags"sv).get_to(o.ParentBackdropImageTags);
    
    j.at("IsPostPaddingRequired"sv).get_to(o.IsPostPaddingRequired);
    
    j.at("KeepUntil"sv).get_to(o.KeepUntil);
    
    j.at("RecordAnyTime"sv).get_to(o.RecordAnyTime);
    
    j.at("SkipEpisodesInLibrary"sv).get_to(o.SkipEpisodesInLibrary);
    
    j.at("RecordAnyChannel"sv).get_to(o.RecordAnyChannel);
    
    j.at("KeepUpTo"sv).get_to(o.KeepUpTo);
    
    j.at("RecordNewOnly"sv).get_to(o.RecordNewOnly);
    if(j.contains("Days"sv))
    j.at("Days"sv).get_to(o.Days);
    if(j.contains("DayPattern"sv))
    j.at("DayPattern"sv).get_to(o.DayPattern);
    if(j.contains("ImageTags"sv))
    j.at("ImageTags"sv).get_to(o.ImageTags);
    if(j.contains("ParentThumbItemId"sv))
    j.at("ParentThumbItemId"sv).get_to(o.ParentThumbItemId);
    if(j.contains("ParentThumbImageTag"sv))
    j.at("ParentThumbImageTag"sv).get_to(o.ParentThumbImageTag);
    if(j.contains("ParentPrimaryImageItemId"sv))
    j.at("ParentPrimaryImageItemId"sv).get_to(o.ParentPrimaryImageItemId);
    if(j.contains("ParentPrimaryImageTag"sv))
    j.at("ParentPrimaryImageTag"sv).get_to(o.ParentPrimaryImageTag);
}




void to_json(json_t& j, const OAISeriesTimerInfoDtoQueryResult& o) {
        j["Items"sv] = o.Items;
        j["TotalRecordCount"sv] = o.TotalRecordCount;
        j["StartIndex"sv] = o.StartIndex;
}
void from_json(const json_t& j, OAISeriesTimerInfoDtoQueryResult& o) {
    if(j.contains("Items"sv))
    j.at("Items"sv).get_to(o.Items);
    
    j.at("TotalRecordCount"sv).get_to(o.TotalRecordCount);
    
    j.at("StartIndex"sv).get_to(o.StartIndex);
}




void to_json(json_t& j, const OAIServerConfiguration& o) {
        j["LogFileRetentionDays"sv] = o.LogFileRetentionDays;
        j["IsStartupWizardCompleted"sv] = o.IsStartupWizardCompleted;
        j["CachePath"sv] = o.CachePath;
        j["PreviousVersion"sv] = o.PreviousVersion;
        j["PreviousVersionStr"sv] = o.PreviousVersionStr;
        j["EnableMetrics"sv] = o.EnableMetrics;
        j["EnableNormalizedItemByNameIds"sv] = o.EnableNormalizedItemByNameIds;
        j["IsPortAuthorized"sv] = o.IsPortAuthorized;
        j["QuickConnectAvailable"sv] = o.QuickConnectAvailable;
        j["EnableCaseSensitiveItemIds"sv] = o.EnableCaseSensitiveItemIds;
        j["DisableLiveTvChannelUserDataName"sv] = o.DisableLiveTvChannelUserDataName;
        j["MetadataPath"sv] = o.MetadataPath;
        j["MetadataNetworkPath"sv] = o.MetadataNetworkPath;
        j["PreferredMetadataLanguage"sv] = o.PreferredMetadataLanguage;
        j["MetadataCountryCode"sv] = o.MetadataCountryCode;
        j["SortReplaceCharacters"sv] = o.SortReplaceCharacters;
        j["SortRemoveCharacters"sv] = o.SortRemoveCharacters;
        j["SortRemoveWords"sv] = o.SortRemoveWords;
        j["MinResumePct"sv] = o.MinResumePct;
        j["MaxResumePct"sv] = o.MaxResumePct;
        j["MinResumeDurationSeconds"sv] = o.MinResumeDurationSeconds;
        j["MinAudiobookResume"sv] = o.MinAudiobookResume;
        j["MaxAudiobookResume"sv] = o.MaxAudiobookResume;
        j["InactiveSessionThreshold"sv] = o.InactiveSessionThreshold;
        j["LibraryMonitorDelay"sv] = o.LibraryMonitorDelay;
        j["LibraryUpdateDuration"sv] = o.LibraryUpdateDuration;
        j["ImageSavingConvention"sv] = o.ImageSavingConvention;
        j["MetadataOptions"sv] = o.MetadataOptions;
        j["SkipDeserializationForBasicTypes"sv] = o.SkipDeserializationForBasicTypes;
        j["ServerName"sv] = o.ServerName;
        j["UICulture"sv] = o.UICulture;
        j["SaveMetadataHidden"sv] = o.SaveMetadataHidden;
        j["ContentTypes"sv] = o.ContentTypes;
        j["RemoteClientBitrateLimit"sv] = o.RemoteClientBitrateLimit;
        j["EnableFolderView"sv] = o.EnableFolderView;
        j["EnableGroupingIntoCollections"sv] = o.EnableGroupingIntoCollections;
        j["DisplaySpecialsWithinSeasons"sv] = o.DisplaySpecialsWithinSeasons;
        j["CodecsUsed"sv] = o.CodecsUsed;
        j["PluginRepositories"sv] = o.PluginRepositories;
        j["EnableExternalContentInSuggestions"sv] = o.EnableExternalContentInSuggestions;
        j["ImageExtractionTimeoutMs"sv] = o.ImageExtractionTimeoutMs;
        j["PathSubstitutions"sv] = o.PathSubstitutions;
        j["EnableSlowResponseWarning"sv] = o.EnableSlowResponseWarning;
        j["SlowResponseThresholdMs"sv] = o.SlowResponseThresholdMs;
        j["CorsHosts"sv] = o.CorsHosts;
        j["ActivityLogRetentionDays"sv] = o.ActivityLogRetentionDays;
        j["LibraryScanFanoutConcurrency"sv] = o.LibraryScanFanoutConcurrency;
        j["LibraryMetadataRefreshConcurrency"sv] = o.LibraryMetadataRefreshConcurrency;
        j["RemoveOldPlugins"sv] = o.RemoveOldPlugins;
        j["AllowClientLogUpload"sv] = o.AllowClientLogUpload;
        j["DummyChapterDuration"sv] = o.DummyChapterDuration;
        j["ChapterImageResolution"sv] = o.ChapterImageResolution;
        j["ParallelImageEncodingLimit"sv] = o.ParallelImageEncodingLimit;
        j["CastReceiverApplications"sv] = o.CastReceiverApplications;
        j["TrickplayOptions"sv] = o.TrickplayOptions;
}
void from_json(const json_t& j, OAIServerConfiguration& o) {
    
    j.at("LogFileRetentionDays"sv).get_to(o.LogFileRetentionDays);
    
    j.at("IsStartupWizardCompleted"sv).get_to(o.IsStartupWizardCompleted);
    if(j.contains("CachePath"sv))
    j.at("CachePath"sv).get_to(o.CachePath);
    if(j.contains("PreviousVersion"sv))
    j.at("PreviousVersion"sv).get_to(o.PreviousVersion);
    if(j.contains("PreviousVersionStr"sv))
    j.at("PreviousVersionStr"sv).get_to(o.PreviousVersionStr);
    
    j.at("EnableMetrics"sv).get_to(o.EnableMetrics);
    
    j.at("EnableNormalizedItemByNameIds"sv).get_to(o.EnableNormalizedItemByNameIds);
    
    j.at("IsPortAuthorized"sv).get_to(o.IsPortAuthorized);
    
    j.at("QuickConnectAvailable"sv).get_to(o.QuickConnectAvailable);
    
    j.at("EnableCaseSensitiveItemIds"sv).get_to(o.EnableCaseSensitiveItemIds);
    
    j.at("DisableLiveTvChannelUserDataName"sv).get_to(o.DisableLiveTvChannelUserDataName);
    
    j.at("MetadataPath"sv).get_to(o.MetadataPath);
    
    j.at("MetadataNetworkPath"sv).get_to(o.MetadataNetworkPath);
    
    j.at("PreferredMetadataLanguage"sv).get_to(o.PreferredMetadataLanguage);
    
    j.at("MetadataCountryCode"sv).get_to(o.MetadataCountryCode);
    
    j.at("SortReplaceCharacters"sv).get_to(o.SortReplaceCharacters);
    
    j.at("SortRemoveCharacters"sv).get_to(o.SortRemoveCharacters);
    
    j.at("SortRemoveWords"sv).get_to(o.SortRemoveWords);
    
    j.at("MinResumePct"sv).get_to(o.MinResumePct);
    
    j.at("MaxResumePct"sv).get_to(o.MaxResumePct);
    
    j.at("MinResumeDurationSeconds"sv).get_to(o.MinResumeDurationSeconds);
    
    j.at("MinAudiobookResume"sv).get_to(o.MinAudiobookResume);
    
    j.at("MaxAudiobookResume"sv).get_to(o.MaxAudiobookResume);
    
    j.at("InactiveSessionThreshold"sv).get_to(o.InactiveSessionThreshold);
    
    j.at("LibraryMonitorDelay"sv).get_to(o.LibraryMonitorDelay);
    
    j.at("LibraryUpdateDuration"sv).get_to(o.LibraryUpdateDuration);
    
    j.at("ImageSavingConvention"sv).get_to(o.ImageSavingConvention);
    
    j.at("MetadataOptions"sv).get_to(o.MetadataOptions);
    
    j.at("SkipDeserializationForBasicTypes"sv).get_to(o.SkipDeserializationForBasicTypes);
    
    j.at("ServerName"sv).get_to(o.ServerName);
    
    j.at("UICulture"sv).get_to(o.UICulture);
    
    j.at("SaveMetadataHidden"sv).get_to(o.SaveMetadataHidden);
    
    j.at("ContentTypes"sv).get_to(o.ContentTypes);
    
    j.at("RemoteClientBitrateLimit"sv).get_to(o.RemoteClientBitrateLimit);
    
    j.at("EnableFolderView"sv).get_to(o.EnableFolderView);
    
    j.at("EnableGroupingIntoCollections"sv).get_to(o.EnableGroupingIntoCollections);
    
    j.at("DisplaySpecialsWithinSeasons"sv).get_to(o.DisplaySpecialsWithinSeasons);
    
    j.at("CodecsUsed"sv).get_to(o.CodecsUsed);
    
    j.at("PluginRepositories"sv).get_to(o.PluginRepositories);
    
    j.at("EnableExternalContentInSuggestions"sv).get_to(o.EnableExternalContentInSuggestions);
    
    j.at("ImageExtractionTimeoutMs"sv).get_to(o.ImageExtractionTimeoutMs);
    
    j.at("PathSubstitutions"sv).get_to(o.PathSubstitutions);
    
    j.at("EnableSlowResponseWarning"sv).get_to(o.EnableSlowResponseWarning);
    
    j.at("SlowResponseThresholdMs"sv).get_to(o.SlowResponseThresholdMs);
    
    j.at("CorsHosts"sv).get_to(o.CorsHosts);
    if(j.contains("ActivityLogRetentionDays"sv))
    j.at("ActivityLogRetentionDays"sv).get_to(o.ActivityLogRetentionDays);
    
    j.at("LibraryScanFanoutConcurrency"sv).get_to(o.LibraryScanFanoutConcurrency);
    
    j.at("LibraryMetadataRefreshConcurrency"sv).get_to(o.LibraryMetadataRefreshConcurrency);
    
    j.at("RemoveOldPlugins"sv).get_to(o.RemoveOldPlugins);
    
    j.at("AllowClientLogUpload"sv).get_to(o.AllowClientLogUpload);
    
    j.at("DummyChapterDuration"sv).get_to(o.DummyChapterDuration);
    
    j.at("ChapterImageResolution"sv).get_to(o.ChapterImageResolution);
    
    j.at("ParallelImageEncodingLimit"sv).get_to(o.ParallelImageEncodingLimit);
    
    j.at("CastReceiverApplications"sv).get_to(o.CastReceiverApplications);
    
    j.at("TrickplayOptions"sv).get_to(o.TrickplayOptions);
}




void to_json(json_t& j, const OAIServerDiscoveryInfo& o) {
        j["Address"sv] = o.Address;
        j["Id"sv] = o.Id;
        j["Name"sv] = o.Name;
        j["EndpointAddress"sv] = o.EndpointAddress;
}
void from_json(const json_t& j, OAIServerDiscoveryInfo& o) {
    
    j.at("Address"sv).get_to(o.Address);
    
    j.at("Id"sv).get_to(o.Id);
    
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("EndpointAddress"sv))
    j.at("EndpointAddress"sv).get_to(o.EndpointAddress);
}




void to_json(json_t& j, const OAIServerRestartingMessage& o) {
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIServerRestartingMessage& o) {
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAIServerShuttingDownMessage& o) {
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIServerShuttingDownMessage& o) {
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAISessionInfo& o) {
        j["PlayState"sv] = o.PlayState;
        j["AdditionalUsers"sv] = o.AdditionalUsers;
        j["Capabilities"sv] = o.Capabilities;
        j["RemoteEndPoint"sv] = o.RemoteEndPoint;
        j["PlayableMediaTypes"sv] = o.PlayableMediaTypes;
        j["Id"sv] = o.Id;
        j["UserId"sv] = o.UserId;
        j["UserName"sv] = o.UserName;
        j["Client"sv] = o.Client;
        j["LastActivityDate"sv] = o.LastActivityDate;
        j["LastPlaybackCheckIn"sv] = o.LastPlaybackCheckIn;
        j["LastPausedDate"sv] = o.LastPausedDate;
        j["DeviceName"sv] = o.DeviceName;
        j["DeviceType"sv] = o.DeviceType;
        j["NowPlayingItem"sv] = o.NowPlayingItem;
        j["NowViewingItem"sv] = o.NowViewingItem;
        j["DeviceId"sv] = o.DeviceId;
        j["ApplicationVersion"sv] = o.ApplicationVersion;
        j["TranscodingInfo"sv] = o.TranscodingInfo;
        j["IsActive"sv] = o.IsActive;
        j["SupportsMediaControl"sv] = o.SupportsMediaControl;
        j["SupportsRemoteControl"sv] = o.SupportsRemoteControl;
        j["NowPlayingQueue"sv] = o.NowPlayingQueue;
        j["NowPlayingQueueFullItems"sv] = o.NowPlayingQueueFullItems;
        j["HasCustomDeviceName"sv] = o.HasCustomDeviceName;
        j["PlaylistItemId"sv] = o.PlaylistItemId;
        j["ServerId"sv] = o.ServerId;
        j["UserPrimaryImageTag"sv] = o.UserPrimaryImageTag;
        j["SupportedCommands"sv] = o.SupportedCommands;
}
void from_json(const json_t& j, OAISessionInfo& o) {
    if(j.contains("PlayState"sv))
    j.at("PlayState"sv).get_to(o.PlayState);
    if(j.contains("AdditionalUsers"sv))
    j.at("AdditionalUsers"sv).get_to(o.AdditionalUsers);
    if(j.contains("Capabilities"sv))
    j.at("Capabilities"sv).get_to(o.Capabilities);
    if(j.contains("RemoteEndPoint"sv))
    j.at("RemoteEndPoint"sv).get_to(o.RemoteEndPoint);
    if(j.contains("PlayableMediaTypes"sv))
    j.at("PlayableMediaTypes"sv).get_to(o.PlayableMediaTypes);
    if(j.contains("Id"sv))
    j.at("Id"sv).get_to(o.Id);
    
    j.at("UserId"sv).get_to(o.UserId);
    if(j.contains("UserName"sv))
    j.at("UserName"sv).get_to(o.UserName);
    if(j.contains("Client"sv))
    j.at("Client"sv).get_to(o.Client);
    
    j.at("LastActivityDate"sv).get_to(o.LastActivityDate);
    
    j.at("LastPlaybackCheckIn"sv).get_to(o.LastPlaybackCheckIn);
    if(j.contains("LastPausedDate"sv))
    j.at("LastPausedDate"sv).get_to(o.LastPausedDate);
    if(j.contains("DeviceName"sv))
    j.at("DeviceName"sv).get_to(o.DeviceName);
    if(j.contains("DeviceType"sv))
    j.at("DeviceType"sv).get_to(o.DeviceType);
    if(j.contains("NowPlayingItem"sv))
    j.at("NowPlayingItem"sv).get_to(o.NowPlayingItem);
    if(j.contains("NowViewingItem"sv))
    j.at("NowViewingItem"sv).get_to(o.NowViewingItem);
    if(j.contains("DeviceId"sv))
    j.at("DeviceId"sv).get_to(o.DeviceId);
    if(j.contains("ApplicationVersion"sv))
    j.at("ApplicationVersion"sv).get_to(o.ApplicationVersion);
    if(j.contains("TranscodingInfo"sv))
    j.at("TranscodingInfo"sv).get_to(o.TranscodingInfo);
    
    j.at("IsActive"sv).get_to(o.IsActive);
    
    j.at("SupportsMediaControl"sv).get_to(o.SupportsMediaControl);
    
    j.at("SupportsRemoteControl"sv).get_to(o.SupportsRemoteControl);
    if(j.contains("NowPlayingQueue"sv))
    j.at("NowPlayingQueue"sv).get_to(o.NowPlayingQueue);
    if(j.contains("NowPlayingQueueFullItems"sv))
    j.at("NowPlayingQueueFullItems"sv).get_to(o.NowPlayingQueueFullItems);
    
    j.at("HasCustomDeviceName"sv).get_to(o.HasCustomDeviceName);
    if(j.contains("PlaylistItemId"sv))
    j.at("PlaylistItemId"sv).get_to(o.PlaylistItemId);
    if(j.contains("ServerId"sv))
    j.at("ServerId"sv).get_to(o.ServerId);
    if(j.contains("UserPrimaryImageTag"sv))
    j.at("UserPrimaryImageTag"sv).get_to(o.UserPrimaryImageTag);
    if(j.contains("SupportedCommands"sv))
    j.at("SupportedCommands"sv).get_to(o.SupportedCommands);
}



void to_json(json_t& j, const OAISessionMessageType& e) {
    switch (e)
    {
    
        case OAISessionMessageType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAISessionMessageType::FORCEKEEPALIVE:
            j = "ForceKeepAlive";
            break;
    
        case OAISessionMessageType::GENERALCOMMAND:
            j = "GeneralCommand";
            break;
    
        case OAISessionMessageType::USERDATACHANGED:
            j = "UserDataChanged";
            break;
    
        case OAISessionMessageType::SESSIONS:
            j = "Sessions";
            break;
    
        case OAISessionMessageType::PLAY:
            j = "Play";
            break;
    
        case OAISessionMessageType::SYNCPLAYCOMMAND:
            j = "SyncPlayCommand";
            break;
    
        case OAISessionMessageType::SYNCPLAYGROUPUPDATE:
            j = "SyncPlayGroupUpdate";
            break;
    
        case OAISessionMessageType::PLAYSTATE:
            j = "Playstate";
            break;
    
        case OAISessionMessageType::RESTARTREQUIRED:
            j = "RestartRequired";
            break;
    
        case OAISessionMessageType::SERVERSHUTTINGDOWN:
            j = "ServerShuttingDown";
            break;
    
        case OAISessionMessageType::SERVERRESTARTING:
            j = "ServerRestarting";
            break;
    
        case OAISessionMessageType::LIBRARYCHANGED:
            j = "LibraryChanged";
            break;
    
        case OAISessionMessageType::USERDELETED:
            j = "UserDeleted";
            break;
    
        case OAISessionMessageType::USERUPDATED:
            j = "UserUpdated";
            break;
    
        case OAISessionMessageType::SERIESTIMERCREATED:
            j = "SeriesTimerCreated";
            break;
    
        case OAISessionMessageType::TIMERCREATED:
            j = "TimerCreated";
            break;
    
        case OAISessionMessageType::SERIESTIMERCANCELLED:
            j = "SeriesTimerCancelled";
            break;
    
        case OAISessionMessageType::TIMERCANCELLED:
            j = "TimerCancelled";
            break;
    
        case OAISessionMessageType::REFRESHPROGRESS:
            j = "RefreshProgress";
            break;
    
        case OAISessionMessageType::SCHEDULEDTASKENDED:
            j = "ScheduledTaskEnded";
            break;
    
        case OAISessionMessageType::PACKAGEINSTALLATIONCANCELLED:
            j = "PackageInstallationCancelled";
            break;
    
        case OAISessionMessageType::PACKAGEINSTALLATIONFAILED:
            j = "PackageInstallationFailed";
            break;
    
        case OAISessionMessageType::PACKAGEINSTALLATIONCOMPLETED:
            j = "PackageInstallationCompleted";
            break;
    
        case OAISessionMessageType::PACKAGEINSTALLING:
            j = "PackageInstalling";
            break;
    
        case OAISessionMessageType::PACKAGEUNINSTALLED:
            j = "PackageUninstalled";
            break;
    
        case OAISessionMessageType::ACTIVITYLOGENTRY:
            j = "ActivityLogEntry";
            break;
    
        case OAISessionMessageType::SCHEDULEDTASKSINFO:
            j = "ScheduledTasksInfo";
            break;
    
        case OAISessionMessageType::ACTIVITYLOGENTRYSTART:
            j = "ActivityLogEntryStart";
            break;
    
        case OAISessionMessageType::ACTIVITYLOGENTRYSTOP:
            j = "ActivityLogEntryStop";
            break;
    
        case OAISessionMessageType::SESSIONSSTART:
            j = "SessionsStart";
            break;
    
        case OAISessionMessageType::SESSIONSSTOP:
            j = "SessionsStop";
            break;
    
        case OAISessionMessageType::SCHEDULEDTASKSINFOSTART:
            j = "ScheduledTasksInfoStart";
            break;
    
        case OAISessionMessageType::SCHEDULEDTASKSINFOSTOP:
            j = "ScheduledTasksInfoStop";
            break;
    
        case OAISessionMessageType::KEEPALIVE:
            j = "KeepAlive";
            break;
    
    }
}
void from_json(const json_t& j, OAISessionMessageType& e) {
    auto s = j.get<std::string>();
    
    if (s == "ForceKeepAlive"sv) {
        e = (OAISessionMessageType::FORCEKEEPALIVE);
    } 
    
    else if (s == "GeneralCommand"sv) {
        e = (OAISessionMessageType::GENERALCOMMAND);
    } 
    
    else if (s == "UserDataChanged"sv) {
        e = (OAISessionMessageType::USERDATACHANGED);
    } 
    
    else if (s == "Sessions"sv) {
        e = (OAISessionMessageType::SESSIONS);
    } 
    
    else if (s == "Play"sv) {
        e = (OAISessionMessageType::PLAY);
    } 
    
    else if (s == "SyncPlayCommand"sv) {
        e = (OAISessionMessageType::SYNCPLAYCOMMAND);
    } 
    
    else if (s == "SyncPlayGroupUpdate"sv) {
        e = (OAISessionMessageType::SYNCPLAYGROUPUPDATE);
    } 
    
    else if (s == "Playstate"sv) {
        e = (OAISessionMessageType::PLAYSTATE);
    } 
    
    else if (s == "RestartRequired"sv) {
        e = (OAISessionMessageType::RESTARTREQUIRED);
    } 
    
    else if (s == "ServerShuttingDown"sv) {
        e = (OAISessionMessageType::SERVERSHUTTINGDOWN);
    } 
    
    else if (s == "ServerRestarting"sv) {
        e = (OAISessionMessageType::SERVERRESTARTING);
    } 
    
    else if (s == "LibraryChanged"sv) {
        e = (OAISessionMessageType::LIBRARYCHANGED);
    } 
    
    else if (s == "UserDeleted"sv) {
        e = (OAISessionMessageType::USERDELETED);
    } 
    
    else if (s == "UserUpdated"sv) {
        e = (OAISessionMessageType::USERUPDATED);
    } 
    
    else if (s == "SeriesTimerCreated"sv) {
        e = (OAISessionMessageType::SERIESTIMERCREATED);
    } 
    
    else if (s == "TimerCreated"sv) {
        e = (OAISessionMessageType::TIMERCREATED);
    } 
    
    else if (s == "SeriesTimerCancelled"sv) {
        e = (OAISessionMessageType::SERIESTIMERCANCELLED);
    } 
    
    else if (s == "TimerCancelled"sv) {
        e = (OAISessionMessageType::TIMERCANCELLED);
    } 
    
    else if (s == "RefreshProgress"sv) {
        e = (OAISessionMessageType::REFRESHPROGRESS);
    } 
    
    else if (s == "ScheduledTaskEnded"sv) {
        e = (OAISessionMessageType::SCHEDULEDTASKENDED);
    } 
    
    else if (s == "PackageInstallationCancelled"sv) {
        e = (OAISessionMessageType::PACKAGEINSTALLATIONCANCELLED);
    } 
    
    else if (s == "PackageInstallationFailed"sv) {
        e = (OAISessionMessageType::PACKAGEINSTALLATIONFAILED);
    } 
    
    else if (s == "PackageInstallationCompleted"sv) {
        e = (OAISessionMessageType::PACKAGEINSTALLATIONCOMPLETED);
    } 
    
    else if (s == "PackageInstalling"sv) {
        e = (OAISessionMessageType::PACKAGEINSTALLING);
    } 
    
    else if (s == "PackageUninstalled"sv) {
        e = (OAISessionMessageType::PACKAGEUNINSTALLED);
    } 
    
    else if (s == "ActivityLogEntry"sv) {
        e = (OAISessionMessageType::ACTIVITYLOGENTRY);
    } 
    
    else if (s == "ScheduledTasksInfo"sv) {
        e = (OAISessionMessageType::SCHEDULEDTASKSINFO);
    } 
    
    else if (s == "ActivityLogEntryStart"sv) {
        e = (OAISessionMessageType::ACTIVITYLOGENTRYSTART);
    } 
    
    else if (s == "ActivityLogEntryStop"sv) {
        e = (OAISessionMessageType::ACTIVITYLOGENTRYSTOP);
    } 
    
    else if (s == "SessionsStart"sv) {
        e = (OAISessionMessageType::SESSIONSSTART);
    } 
    
    else if (s == "SessionsStop"sv) {
        e = (OAISessionMessageType::SESSIONSSTOP);
    } 
    
    else if (s == "ScheduledTasksInfoStart"sv) {
        e = (OAISessionMessageType::SCHEDULEDTASKSINFOSTART);
    } 
    
    else if (s == "ScheduledTasksInfoStop"sv) {
        e = (OAISessionMessageType::SCHEDULEDTASKSINFOSTOP);
    } 
    
    else if (s == "KeepAlive"sv) {
        e = (OAISessionMessageType::KEEPALIVE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAISessionMessageType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAISessionUserInfo& o) {
        j["UserId"sv] = o.UserId;
        j["UserName"sv] = o.UserName;
}
void from_json(const json_t& j, OAISessionUserInfo& o) {
    
    j.at("UserId"sv).get_to(o.UserId);
    if(j.contains("UserName"sv))
    j.at("UserName"sv).get_to(o.UserName);
}




void to_json(json_t& j, const OAISessionsMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAISessionsMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAISessionsStartMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAISessionsStartMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAISessionsStopMessage& o) {
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAISessionsStopMessage& o) {
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAISetChannelMappingDto& o) {
        j["ProviderId"sv] = o.ProviderId;
        j["TunerChannelId"sv] = o.TunerChannelId;
        j["ProviderChannelId"sv] = o.ProviderChannelId;
}
void from_json(const json_t& j, OAISetChannelMappingDto& o) {
    
    j.at("ProviderId"sv).get_to(o.ProviderId);
    
    j.at("TunerChannelId"sv).get_to(o.TunerChannelId);
    
    j.at("ProviderChannelId"sv).get_to(o.ProviderChannelId);
}




void to_json(json_t& j, const OAISetPlaylistItemRequestDto& o) {
        j["PlaylistItemId"sv] = o.PlaylistItemId;
}
void from_json(const json_t& j, OAISetPlaylistItemRequestDto& o) {
    
    j.at("PlaylistItemId"sv).get_to(o.PlaylistItemId);
}




void to_json(json_t& j, const OAISetRepeatModeRequestDto& o) {
        j["Mode"sv] = o.Mode;
}
void from_json(const json_t& j, OAISetRepeatModeRequestDto& o) {
    
    j.at("Mode"sv).get_to(o.Mode);
}




void to_json(json_t& j, const OAISetShuffleModeRequestDto& o) {
        j["Mode"sv] = o.Mode;
}
void from_json(const json_t& j, OAISetShuffleModeRequestDto& o) {
    
    j.at("Mode"sv).get_to(o.Mode);
}




void to_json(json_t& j, const OAISongInfo& o) {
        j["Name"sv] = o.Name;
        j["OriginalTitle"sv] = o.OriginalTitle;
        j["Path"sv] = o.Path;
        j["MetadataLanguage"sv] = o.MetadataLanguage;
        j["MetadataCountryCode"sv] = o.MetadataCountryCode;
        j["ProviderIds"sv] = o.ProviderIds;
        j["Year"sv] = o.Year;
        j["IndexNumber"sv] = o.IndexNumber;
        j["ParentIndexNumber"sv] = o.ParentIndexNumber;
        j["PremiereDate"sv] = o.PremiereDate;
        j["IsAutomated"sv] = o.IsAutomated;
        j["AlbumArtists"sv] = o.AlbumArtists;
        j["Album"sv] = o.Album;
        j["Artists"sv] = o.Artists;
}
void from_json(const json_t& j, OAISongInfo& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("OriginalTitle"sv))
    j.at("OriginalTitle"sv).get_to(o.OriginalTitle);
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("MetadataLanguage"sv))
    j.at("MetadataLanguage"sv).get_to(o.MetadataLanguage);
    if(j.contains("MetadataCountryCode"sv))
    j.at("MetadataCountryCode"sv).get_to(o.MetadataCountryCode);
    if(j.contains("ProviderIds"sv))
    j.at("ProviderIds"sv).get_to(o.ProviderIds);
    if(j.contains("Year"sv))
    j.at("Year"sv).get_to(o.Year);
    if(j.contains("IndexNumber"sv))
    j.at("IndexNumber"sv).get_to(o.IndexNumber);
    if(j.contains("ParentIndexNumber"sv))
    j.at("ParentIndexNumber"sv).get_to(o.ParentIndexNumber);
    if(j.contains("PremiereDate"sv))
    j.at("PremiereDate"sv).get_to(o.PremiereDate);
    
    j.at("IsAutomated"sv).get_to(o.IsAutomated);
    if(j.contains("AlbumArtists"sv))
    j.at("AlbumArtists"sv).get_to(o.AlbumArtists);
    if(j.contains("Album"sv))
    j.at("Album"sv).get_to(o.Album);
    if(j.contains("Artists"sv))
    j.at("Artists"sv).get_to(o.Artists);
}



void to_json(json_t& j, const OAISortOrder& e) {
    switch (e)
    {
    
        case OAISortOrder::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAISortOrder::ASCENDING:
            j = "Ascending";
            break;
    
        case OAISortOrder::DESCENDING:
            j = "Descending";
            break;
    
    }
}
void from_json(const json_t& j, OAISortOrder& e) {
    auto s = j.get<std::string>();
    
    if (s == "Ascending"sv) {
        e = (OAISortOrder::ASCENDING);
    } 
    
    else if (s == "Descending"sv) {
        e = (OAISortOrder::DESCENDING);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAISortOrder";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAISpecialViewOptionDto& o) {
        j["Name"sv] = o.Name;
        j["Id"sv] = o.Id;
}
void from_json(const json_t& j, OAISpecialViewOptionDto& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Id"sv))
    j.at("Id"sv).get_to(o.Id);
}




void to_json(json_t& j, const OAIStartupConfigurationDto& o) {
        j["UICulture"sv] = o.UICulture;
        j["MetadataCountryCode"sv] = o.MetadataCountryCode;
        j["PreferredMetadataLanguage"sv] = o.PreferredMetadataLanguage;
}
void from_json(const json_t& j, OAIStartupConfigurationDto& o) {
    if(j.contains("UICulture"sv))
    j.at("UICulture"sv).get_to(o.UICulture);
    if(j.contains("MetadataCountryCode"sv))
    j.at("MetadataCountryCode"sv).get_to(o.MetadataCountryCode);
    if(j.contains("PreferredMetadataLanguage"sv))
    j.at("PreferredMetadataLanguage"sv).get_to(o.PreferredMetadataLanguage);
}




void to_json(json_t& j, const OAIStartupRemoteAccessDto& o) {
        j["EnableRemoteAccess"sv] = o.EnableRemoteAccess;
        j["EnableAutomaticPortMapping"sv] = o.EnableAutomaticPortMapping;
}
void from_json(const json_t& j, OAIStartupRemoteAccessDto& o) {
    
    j.at("EnableRemoteAccess"sv).get_to(o.EnableRemoteAccess);
    
    j.at("EnableAutomaticPortMapping"sv).get_to(o.EnableAutomaticPortMapping);
}




void to_json(json_t& j, const OAIStartupUserDto& o) {
        j["Name"sv] = o.Name;
        j["Password"sv] = o.Password;
}
void from_json(const json_t& j, OAIStartupUserDto& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Password"sv))
    j.at("Password"sv).get_to(o.Password);
}




void to_json(json_t& j, const OAIStringGroupUpdate& o) {
        j["GroupId"sv] = o.GroupId;
        j["Type"sv] = o.Type;
        j["Data"sv] = o.Data;
}
void from_json(const json_t& j, OAIStringGroupUpdate& o) {
    
    j.at("GroupId"sv).get_to(o.GroupId);
    
    j.at("Type"sv).get_to(o.Type);
    
    j.at("Data"sv).get_to(o.Data);
}



void to_json(json_t& j, const OAISubtitleDeliveryMethod& e) {
    switch (e)
    {
    
        case OAISubtitleDeliveryMethod::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAISubtitleDeliveryMethod::ENCODE:
            j = "Encode";
            break;
    
        case OAISubtitleDeliveryMethod::EMBED:
            j = "Embed";
            break;
    
        case OAISubtitleDeliveryMethod::EXTERNAL:
            j = "External";
            break;
    
        case OAISubtitleDeliveryMethod::HLS:
            j = "Hls";
            break;
    
        case OAISubtitleDeliveryMethod::DROP:
            j = "Drop";
            break;
    
    }
}
void from_json(const json_t& j, OAISubtitleDeliveryMethod& e) {
    auto s = j.get<std::string>();
    
    if (s == "Encode"sv) {
        e = (OAISubtitleDeliveryMethod::ENCODE);
    } 
    
    else if (s == "Embed"sv) {
        e = (OAISubtitleDeliveryMethod::EMBED);
    } 
    
    else if (s == "External"sv) {
        e = (OAISubtitleDeliveryMethod::EXTERNAL);
    } 
    
    else if (s == "Hls"sv) {
        e = (OAISubtitleDeliveryMethod::HLS);
    } 
    
    else if (s == "Drop"sv) {
        e = (OAISubtitleDeliveryMethod::DROP);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAISubtitleDeliveryMethod";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAISubtitleOptions& o) {
        j["SkipIfEmbeddedSubtitlesPresent"sv] = o.SkipIfEmbeddedSubtitlesPresent;
        j["SkipIfAudioTrackMatches"sv] = o.SkipIfAudioTrackMatches;
        j["DownloadLanguages"sv] = o.DownloadLanguages;
        j["DownloadMovieSubtitles"sv] = o.DownloadMovieSubtitles;
        j["DownloadEpisodeSubtitles"sv] = o.DownloadEpisodeSubtitles;
        j["OpenSubtitlesUsername"sv] = o.OpenSubtitlesUsername;
        j["OpenSubtitlesPasswordHash"sv] = o.OpenSubtitlesPasswordHash;
        j["IsOpenSubtitleVipAccount"sv] = o.IsOpenSubtitleVipAccount;
        j["RequirePerfectMatch"sv] = o.RequirePerfectMatch;
}
void from_json(const json_t& j, OAISubtitleOptions& o) {
    
    j.at("SkipIfEmbeddedSubtitlesPresent"sv).get_to(o.SkipIfEmbeddedSubtitlesPresent);
    
    j.at("SkipIfAudioTrackMatches"sv).get_to(o.SkipIfAudioTrackMatches);
    if(j.contains("DownloadLanguages"sv))
    j.at("DownloadLanguages"sv).get_to(o.DownloadLanguages);
    
    j.at("DownloadMovieSubtitles"sv).get_to(o.DownloadMovieSubtitles);
    
    j.at("DownloadEpisodeSubtitles"sv).get_to(o.DownloadEpisodeSubtitles);
    if(j.contains("OpenSubtitlesUsername"sv))
    j.at("OpenSubtitlesUsername"sv).get_to(o.OpenSubtitlesUsername);
    if(j.contains("OpenSubtitlesPasswordHash"sv))
    j.at("OpenSubtitlesPasswordHash"sv).get_to(o.OpenSubtitlesPasswordHash);
    
    j.at("IsOpenSubtitleVipAccount"sv).get_to(o.IsOpenSubtitleVipAccount);
    
    j.at("RequirePerfectMatch"sv).get_to(o.RequirePerfectMatch);
}



void to_json(json_t& j, const OAISubtitlePlaybackMode& e) {
    switch (e)
    {
    
        case OAISubtitlePlaybackMode::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAISubtitlePlaybackMode::DEFAULT:
            j = "Default";
            break;
    
        case OAISubtitlePlaybackMode::ALWAYS:
            j = "Always";
            break;
    
        case OAISubtitlePlaybackMode::ONLYFORCED:
            j = "OnlyForced";
            break;
    
        case OAISubtitlePlaybackMode::NONE:
            j = "None";
            break;
    
        case OAISubtitlePlaybackMode::SMART:
            j = "Smart";
            break;
    
    }
}
void from_json(const json_t& j, OAISubtitlePlaybackMode& e) {
    auto s = j.get<std::string>();
    
    if (s == "Default"sv) {
        e = (OAISubtitlePlaybackMode::DEFAULT);
    } 
    
    else if (s == "Always"sv) {
        e = (OAISubtitlePlaybackMode::ALWAYS);
    } 
    
    else if (s == "OnlyForced"sv) {
        e = (OAISubtitlePlaybackMode::ONLYFORCED);
    } 
    
    else if (s == "None"sv) {
        e = (OAISubtitlePlaybackMode::NONE);
    } 
    
    else if (s == "Smart"sv) {
        e = (OAISubtitlePlaybackMode::SMART);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAISubtitlePlaybackMode";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAISubtitleProfile& o) {
        j["Format"sv] = o.Format;
        j["Method"sv] = o.Method;
        j["DidlMode"sv] = o.DidlMode;
        j["Language"sv] = o.Language;
        j["Container"sv] = o.Container;
}
void from_json(const json_t& j, OAISubtitleProfile& o) {
    if(j.contains("Format"sv))
    j.at("Format"sv).get_to(o.Format);
    
    j.at("Method"sv).get_to(o.Method);
    if(j.contains("DidlMode"sv))
    j.at("DidlMode"sv).get_to(o.DidlMode);
    if(j.contains("Language"sv))
    j.at("Language"sv).get_to(o.Language);
    if(j.contains("Container"sv))
    j.at("Container"sv).get_to(o.Container);
}




void to_json(json_t& j, const OAISyncPlayCommandMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAISyncPlayCommandMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAISyncPlayGroupUpdateCommandMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAISyncPlayGroupUpdateCommandMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAISyncPlayQueueItem& o) {
        j["ItemId"sv] = o.ItemId;
        j["PlaylistItemId"sv] = o.PlaylistItemId;
}
void from_json(const json_t& j, OAISyncPlayQueueItem& o) {
    
    j.at("ItemId"sv).get_to(o.ItemId);
    
    j.at("PlaylistItemId"sv).get_to(o.PlaylistItemId);
}



void to_json(json_t& j, const OAISyncPlayUserAccessType& e) {
    switch (e)
    {
    
        case OAISyncPlayUserAccessType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAISyncPlayUserAccessType::CREATEANDJOINGROUPS:
            j = "CreateAndJoinGroups";
            break;
    
        case OAISyncPlayUserAccessType::JOINGROUPS:
            j = "JoinGroups";
            break;
    
        case OAISyncPlayUserAccessType::NONE:
            j = "None";
            break;
    
    }
}
void from_json(const json_t& j, OAISyncPlayUserAccessType& e) {
    auto s = j.get<std::string>();
    
    if (s == "CreateAndJoinGroups"sv) {
        e = (OAISyncPlayUserAccessType::CREATEANDJOINGROUPS);
    } 
    
    else if (s == "JoinGroups"sv) {
        e = (OAISyncPlayUserAccessType::JOINGROUPS);
    } 
    
    else if (s == "None"sv) {
        e = (OAISyncPlayUserAccessType::NONE);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAISyncPlayUserAccessType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAISystemInfo& o) {
        j["LocalAddress"sv] = o.LocalAddress;
        j["ServerName"sv] = o.ServerName;
        j["Version"sv] = o.Version;
        j["ProductName"sv] = o.ProductName;
        j["OperatingSystem"sv] = o.OperatingSystem;
        j["Id"sv] = o.Id;
        j["StartupWizardCompleted"sv] = o.StartupWizardCompleted;
        j["OperatingSystemDisplayName"sv] = o.OperatingSystemDisplayName;
        j["PackageName"sv] = o.PackageName;
        j["HasPendingRestart"sv] = o.HasPendingRestart;
        j["IsShuttingDown"sv] = o.IsShuttingDown;
        j["SupportsLibraryMonitor"sv] = o.SupportsLibraryMonitor;
        j["WebSocketPortNumber"sv] = o.WebSocketPortNumber;
        j["CompletedInstallations"sv] = o.CompletedInstallations;
        j["CanSelfRestart"sv] = o.CanSelfRestart;
        j["CanLaunchWebBrowser"sv] = o.CanLaunchWebBrowser;
        j["ProgramDataPath"sv] = o.ProgramDataPath;
        j["WebPath"sv] = o.WebPath;
        j["ItemsByNamePath"sv] = o.ItemsByNamePath;
        j["CachePath"sv] = o.CachePath;
        j["LogPath"sv] = o.LogPath;
        j["InternalMetadataPath"sv] = o.InternalMetadataPath;
        j["TranscodingTempPath"sv] = o.TranscodingTempPath;
        j["CastReceiverApplications"sv] = o.CastReceiverApplications;
        j["HasUpdateAvailable"sv] = o.HasUpdateAvailable;
        j["EncoderLocation"sv] = o.EncoderLocation;
        j["SystemArchitecture"sv] = o.SystemArchitecture;
}
void from_json(const json_t& j, OAISystemInfo& o) {
    if(j.contains("LocalAddress"sv))
    j.at("LocalAddress"sv).get_to(o.LocalAddress);
    if(j.contains("ServerName"sv))
    j.at("ServerName"sv).get_to(o.ServerName);
    if(j.contains("Version"sv))
    j.at("Version"sv).get_to(o.Version);
    if(j.contains("ProductName"sv))
    j.at("ProductName"sv).get_to(o.ProductName);
    if(j.contains("OperatingSystem"sv))
    j.at("OperatingSystem"sv).get_to(o.OperatingSystem);
    if(j.contains("Id"sv))
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("StartupWizardCompleted"sv))
    j.at("StartupWizardCompleted"sv).get_to(o.StartupWizardCompleted);
    if(j.contains("OperatingSystemDisplayName"sv))
    j.at("OperatingSystemDisplayName"sv).get_to(o.OperatingSystemDisplayName);
    if(j.contains("PackageName"sv))
    j.at("PackageName"sv).get_to(o.PackageName);
    
    j.at("HasPendingRestart"sv).get_to(o.HasPendingRestart);
    
    j.at("IsShuttingDown"sv).get_to(o.IsShuttingDown);
    
    j.at("SupportsLibraryMonitor"sv).get_to(o.SupportsLibraryMonitor);
    
    j.at("WebSocketPortNumber"sv).get_to(o.WebSocketPortNumber);
    if(j.contains("CompletedInstallations"sv))
    j.at("CompletedInstallations"sv).get_to(o.CompletedInstallations);
    
    j.at("CanSelfRestart"sv).get_to(o.CanSelfRestart);
    
    j.at("CanLaunchWebBrowser"sv).get_to(o.CanLaunchWebBrowser);
    if(j.contains("ProgramDataPath"sv))
    j.at("ProgramDataPath"sv).get_to(o.ProgramDataPath);
    if(j.contains("WebPath"sv))
    j.at("WebPath"sv).get_to(o.WebPath);
    if(j.contains("ItemsByNamePath"sv))
    j.at("ItemsByNamePath"sv).get_to(o.ItemsByNamePath);
    if(j.contains("CachePath"sv))
    j.at("CachePath"sv).get_to(o.CachePath);
    if(j.contains("LogPath"sv))
    j.at("LogPath"sv).get_to(o.LogPath);
    if(j.contains("InternalMetadataPath"sv))
    j.at("InternalMetadataPath"sv).get_to(o.InternalMetadataPath);
    if(j.contains("TranscodingTempPath"sv))
    j.at("TranscodingTempPath"sv).get_to(o.TranscodingTempPath);
    if(j.contains("CastReceiverApplications"sv))
    j.at("CastReceiverApplications"sv).get_to(o.CastReceiverApplications);
    
    j.at("HasUpdateAvailable"sv).get_to(o.HasUpdateAvailable);
    if(j.contains("EncoderLocation"sv))
    j.at("EncoderLocation"sv).get_to(o.EncoderLocation);
    if(j.contains("SystemArchitecture"sv))
    j.at("SystemArchitecture"sv).get_to(o.SystemArchitecture);
}



void to_json(json_t& j, const OAITaskCompletionStatus& e) {
    switch (e)
    {
    
        case OAITaskCompletionStatus::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAITaskCompletionStatus::COMPLETED:
            j = "Completed";
            break;
    
        case OAITaskCompletionStatus::FAILED:
            j = "Failed";
            break;
    
        case OAITaskCompletionStatus::CANCELLED:
            j = "Cancelled";
            break;
    
        case OAITaskCompletionStatus::ABORTED:
            j = "Aborted";
            break;
    
    }
}
void from_json(const json_t& j, OAITaskCompletionStatus& e) {
    auto s = j.get<std::string>();
    
    if (s == "Completed"sv) {
        e = (OAITaskCompletionStatus::COMPLETED);
    } 
    
    else if (s == "Failed"sv) {
        e = (OAITaskCompletionStatus::FAILED);
    } 
    
    else if (s == "Cancelled"sv) {
        e = (OAITaskCompletionStatus::CANCELLED);
    } 
    
    else if (s == "Aborted"sv) {
        e = (OAITaskCompletionStatus::ABORTED);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAITaskCompletionStatus";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAITaskInfo& o) {
        j["Name"sv] = o.Name;
        j["State"sv] = o.State;
        j["CurrentProgressPercentage"sv] = o.CurrentProgressPercentage;
        j["Id"sv] = o.Id;
        j["LastExecutionResult"sv] = o.LastExecutionResult;
        j["Triggers"sv] = o.Triggers;
        j["Description"sv] = o.Description;
        j["Category"sv] = o.Category;
        j["IsHidden"sv] = o.IsHidden;
        j["Key"sv] = o.Key;
}
void from_json(const json_t& j, OAITaskInfo& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    
    j.at("State"sv).get_to(o.State);
    if(j.contains("CurrentProgressPercentage"sv))
    j.at("CurrentProgressPercentage"sv).get_to(o.CurrentProgressPercentage);
    if(j.contains("Id"sv))
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("LastExecutionResult"sv))
    j.at("LastExecutionResult"sv).get_to(o.LastExecutionResult);
    if(j.contains("Triggers"sv))
    j.at("Triggers"sv).get_to(o.Triggers);
    if(j.contains("Description"sv))
    j.at("Description"sv).get_to(o.Description);
    if(j.contains("Category"sv))
    j.at("Category"sv).get_to(o.Category);
    
    j.at("IsHidden"sv).get_to(o.IsHidden);
    if(j.contains("Key"sv))
    j.at("Key"sv).get_to(o.Key);
}




void to_json(json_t& j, const OAITaskResult& o) {
        j["StartTimeUtc"sv] = o.StartTimeUtc;
        j["EndTimeUtc"sv] = o.EndTimeUtc;
        j["Status"sv] = o.Status;
        j["Name"sv] = o.Name;
        j["Key"sv] = o.Key;
        j["Id"sv] = o.Id;
        j["ErrorMessage"sv] = o.ErrorMessage;
        j["LongErrorMessage"sv] = o.LongErrorMessage;
}
void from_json(const json_t& j, OAITaskResult& o) {
    
    j.at("StartTimeUtc"sv).get_to(o.StartTimeUtc);
    
    j.at("EndTimeUtc"sv).get_to(o.EndTimeUtc);
    
    j.at("Status"sv).get_to(o.Status);
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Key"sv))
    j.at("Key"sv).get_to(o.Key);
    if(j.contains("Id"sv))
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("ErrorMessage"sv))
    j.at("ErrorMessage"sv).get_to(o.ErrorMessage);
    if(j.contains("LongErrorMessage"sv))
    j.at("LongErrorMessage"sv).get_to(o.LongErrorMessage);
}



void to_json(json_t& j, const OAITaskState& e) {
    switch (e)
    {
    
        case OAITaskState::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAITaskState::IDLE:
            j = "Idle";
            break;
    
        case OAITaskState::CANCELLING:
            j = "Cancelling";
            break;
    
        case OAITaskState::RUNNING:
            j = "Running";
            break;
    
    }
}
void from_json(const json_t& j, OAITaskState& e) {
    auto s = j.get<std::string>();
    
    if (s == "Idle"sv) {
        e = (OAITaskState::IDLE);
    } 
    
    else if (s == "Cancelling"sv) {
        e = (OAITaskState::CANCELLING);
    } 
    
    else if (s == "Running"sv) {
        e = (OAITaskState::RUNNING);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAITaskState";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAITaskTriggerInfo& o) {
        j["Type"sv] = o.Type;
        j["TimeOfDayTicks"sv] = o.TimeOfDayTicks;
        j["IntervalTicks"sv] = o.IntervalTicks;
        j["DayOfWeek"sv] = o.DayOfWeek;
        j["MaxRuntimeTicks"sv] = o.MaxRuntimeTicks;
}
void from_json(const json_t& j, OAITaskTriggerInfo& o) {
    if(j.contains("Type"sv))
    j.at("Type"sv).get_to(o.Type);
    if(j.contains("TimeOfDayTicks"sv))
    j.at("TimeOfDayTicks"sv).get_to(o.TimeOfDayTicks);
    if(j.contains("IntervalTicks"sv))
    j.at("IntervalTicks"sv).get_to(o.IntervalTicks);
    if(j.contains("DayOfWeek"sv))
    j.at("DayOfWeek"sv).get_to(o.DayOfWeek);
    if(j.contains("MaxRuntimeTicks"sv))
    j.at("MaxRuntimeTicks"sv).get_to(o.MaxRuntimeTicks);
}




void to_json(json_t& j, const OAIThemeMediaResult& o) {
        j["Items"sv] = o.Items;
        j["TotalRecordCount"sv] = o.TotalRecordCount;
        j["StartIndex"sv] = o.StartIndex;
        j["OwnerId"sv] = o.OwnerId;
}
void from_json(const json_t& j, OAIThemeMediaResult& o) {
    if(j.contains("Items"sv))
    j.at("Items"sv).get_to(o.Items);
    
    j.at("TotalRecordCount"sv).get_to(o.TotalRecordCount);
    
    j.at("StartIndex"sv).get_to(o.StartIndex);
    
    j.at("OwnerId"sv).get_to(o.OwnerId);
}




void to_json(json_t& j, const OAITimerCancelledMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAITimerCancelledMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAITimerCreatedMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAITimerCreatedMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAITimerEventInfo& o) {
        j["Id"sv] = o.Id;
        j["ProgramId"sv] = o.ProgramId;
}
void from_json(const json_t& j, OAITimerEventInfo& o) {
    
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("ProgramId"sv))
    j.at("ProgramId"sv).get_to(o.ProgramId);
}




void to_json(json_t& j, const OAITimerInfoDto& o) {
        j["Id"sv] = o.Id;
        j["Type"sv] = o.Type;
        j["ServerId"sv] = o.ServerId;
        j["ExternalId"sv] = o.ExternalId;
        j["ChannelId"sv] = o.ChannelId;
        j["ExternalChannelId"sv] = o.ExternalChannelId;
        j["ChannelName"sv] = o.ChannelName;
        j["ChannelPrimaryImageTag"sv] = o.ChannelPrimaryImageTag;
        j["ProgramId"sv] = o.ProgramId;
        j["ExternalProgramId"sv] = o.ExternalProgramId;
        j["Name"sv] = o.Name;
        j["Overview"sv] = o.Overview;
        j["StartDate"sv] = o.StartDate;
        j["EndDate"sv] = o.EndDate;
        j["ServiceName"sv] = o.ServiceName;
        j["Priority"sv] = o.Priority;
        j["PrePaddingSeconds"sv] = o.PrePaddingSeconds;
        j["PostPaddingSeconds"sv] = o.PostPaddingSeconds;
        j["IsPrePaddingRequired"sv] = o.IsPrePaddingRequired;
        j["ParentBackdropItemId"sv] = o.ParentBackdropItemId;
        j["ParentBackdropImageTags"sv] = o.ParentBackdropImageTags;
        j["IsPostPaddingRequired"sv] = o.IsPostPaddingRequired;
        j["KeepUntil"sv] = o.KeepUntil;
        j["Status"sv] = o.Status;
        j["SeriesTimerId"sv] = o.SeriesTimerId;
        j["ExternalSeriesTimerId"sv] = o.ExternalSeriesTimerId;
        j["RunTimeTicks"sv] = o.RunTimeTicks;
        j["ProgramInfo"sv] = o.ProgramInfo;
}
void from_json(const json_t& j, OAITimerInfoDto& o) {
    if(j.contains("Id"sv))
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("Type"sv))
    j.at("Type"sv).get_to(o.Type);
    if(j.contains("ServerId"sv))
    j.at("ServerId"sv).get_to(o.ServerId);
    if(j.contains("ExternalId"sv))
    j.at("ExternalId"sv).get_to(o.ExternalId);
    
    j.at("ChannelId"sv).get_to(o.ChannelId);
    if(j.contains("ExternalChannelId"sv))
    j.at("ExternalChannelId"sv).get_to(o.ExternalChannelId);
    if(j.contains("ChannelName"sv))
    j.at("ChannelName"sv).get_to(o.ChannelName);
    if(j.contains("ChannelPrimaryImageTag"sv))
    j.at("ChannelPrimaryImageTag"sv).get_to(o.ChannelPrimaryImageTag);
    if(j.contains("ProgramId"sv))
    j.at("ProgramId"sv).get_to(o.ProgramId);
    if(j.contains("ExternalProgramId"sv))
    j.at("ExternalProgramId"sv).get_to(o.ExternalProgramId);
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Overview"sv))
    j.at("Overview"sv).get_to(o.Overview);
    
    j.at("StartDate"sv).get_to(o.StartDate);
    
    j.at("EndDate"sv).get_to(o.EndDate);
    if(j.contains("ServiceName"sv))
    j.at("ServiceName"sv).get_to(o.ServiceName);
    
    j.at("Priority"sv).get_to(o.Priority);
    
    j.at("PrePaddingSeconds"sv).get_to(o.PrePaddingSeconds);
    
    j.at("PostPaddingSeconds"sv).get_to(o.PostPaddingSeconds);
    
    j.at("IsPrePaddingRequired"sv).get_to(o.IsPrePaddingRequired);
    if(j.contains("ParentBackdropItemId"sv))
    j.at("ParentBackdropItemId"sv).get_to(o.ParentBackdropItemId);
    if(j.contains("ParentBackdropImageTags"sv))
    j.at("ParentBackdropImageTags"sv).get_to(o.ParentBackdropImageTags);
    
    j.at("IsPostPaddingRequired"sv).get_to(o.IsPostPaddingRequired);
    
    j.at("KeepUntil"sv).get_to(o.KeepUntil);
    
    j.at("Status"sv).get_to(o.Status);
    if(j.contains("SeriesTimerId"sv))
    j.at("SeriesTimerId"sv).get_to(o.SeriesTimerId);
    if(j.contains("ExternalSeriesTimerId"sv))
    j.at("ExternalSeriesTimerId"sv).get_to(o.ExternalSeriesTimerId);
    if(j.contains("RunTimeTicks"sv))
    j.at("RunTimeTicks"sv).get_to(o.RunTimeTicks);
    if(j.contains("ProgramInfo"sv))
    j.at("ProgramInfo"sv).get_to(o.ProgramInfo);
}




void to_json(json_t& j, const OAITimerInfoDtoQueryResult& o) {
        j["Items"sv] = o.Items;
        j["TotalRecordCount"sv] = o.TotalRecordCount;
        j["StartIndex"sv] = o.StartIndex;
}
void from_json(const json_t& j, OAITimerInfoDtoQueryResult& o) {
    if(j.contains("Items"sv))
    j.at("Items"sv).get_to(o.Items);
    
    j.at("TotalRecordCount"sv).get_to(o.TotalRecordCount);
    
    j.at("StartIndex"sv).get_to(o.StartIndex);
}




void to_json(json_t& j, const OAITrailerInfo& o) {
        j["Name"sv] = o.Name;
        j["OriginalTitle"sv] = o.OriginalTitle;
        j["Path"sv] = o.Path;
        j["MetadataLanguage"sv] = o.MetadataLanguage;
        j["MetadataCountryCode"sv] = o.MetadataCountryCode;
        j["ProviderIds"sv] = o.ProviderIds;
        j["Year"sv] = o.Year;
        j["IndexNumber"sv] = o.IndexNumber;
        j["ParentIndexNumber"sv] = o.ParentIndexNumber;
        j["PremiereDate"sv] = o.PremiereDate;
        j["IsAutomated"sv] = o.IsAutomated;
}
void from_json(const json_t& j, OAITrailerInfo& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("OriginalTitle"sv))
    j.at("OriginalTitle"sv).get_to(o.OriginalTitle);
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("MetadataLanguage"sv))
    j.at("MetadataLanguage"sv).get_to(o.MetadataLanguage);
    if(j.contains("MetadataCountryCode"sv))
    j.at("MetadataCountryCode"sv).get_to(o.MetadataCountryCode);
    if(j.contains("ProviderIds"sv))
    j.at("ProviderIds"sv).get_to(o.ProviderIds);
    if(j.contains("Year"sv))
    j.at("Year"sv).get_to(o.Year);
    if(j.contains("IndexNumber"sv))
    j.at("IndexNumber"sv).get_to(o.IndexNumber);
    if(j.contains("ParentIndexNumber"sv))
    j.at("ParentIndexNumber"sv).get_to(o.ParentIndexNumber);
    if(j.contains("PremiereDate"sv))
    j.at("PremiereDate"sv).get_to(o.PremiereDate);
    
    j.at("IsAutomated"sv).get_to(o.IsAutomated);
}




void to_json(json_t& j, const OAITrailerInfoRemoteSearchQuery& o) {
        j["SearchInfo"sv] = o.SearchInfo;
        j["ItemId"sv] = o.ItemId;
        j["SearchProviderName"sv] = o.SearchProviderName;
        j["IncludeDisabledProviders"sv] = o.IncludeDisabledProviders;
}
void from_json(const json_t& j, OAITrailerInfoRemoteSearchQuery& o) {
    if(j.contains("SearchInfo"sv))
    j.at("SearchInfo"sv).get_to(o.SearchInfo);
    
    j.at("ItemId"sv).get_to(o.ItemId);
    if(j.contains("SearchProviderName"sv))
    j.at("SearchProviderName"sv).get_to(o.SearchProviderName);
    
    j.at("IncludeDisabledProviders"sv).get_to(o.IncludeDisabledProviders);
}



void to_json(json_t& j, const OAITranscodeReason& e) {
    switch (e)
    {
    
        case OAITranscodeReason::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAITranscodeReason::CONTAINERNOTSUPPORTED:
            j = "ContainerNotSupported";
            break;
    
        case OAITranscodeReason::VIDEOCODECNOTSUPPORTED:
            j = "VideoCodecNotSupported";
            break;
    
        case OAITranscodeReason::AUDIOCODECNOTSUPPORTED:
            j = "AudioCodecNotSupported";
            break;
    
        case OAITranscodeReason::SUBTITLECODECNOTSUPPORTED:
            j = "SubtitleCodecNotSupported";
            break;
    
        case OAITranscodeReason::AUDIOISEXTERNAL:
            j = "AudioIsExternal";
            break;
    
        case OAITranscodeReason::SECONDARYAUDIONOTSUPPORTED:
            j = "SecondaryAudioNotSupported";
            break;
    
        case OAITranscodeReason::VIDEOPROFILENOTSUPPORTED:
            j = "VideoProfileNotSupported";
            break;
    
        case OAITranscodeReason::VIDEOLEVELNOTSUPPORTED:
            j = "VideoLevelNotSupported";
            break;
    
        case OAITranscodeReason::VIDEORESOLUTIONNOTSUPPORTED:
            j = "VideoResolutionNotSupported";
            break;
    
        case OAITranscodeReason::VIDEOBITDEPTHNOTSUPPORTED:
            j = "VideoBitDepthNotSupported";
            break;
    
        case OAITranscodeReason::VIDEOFRAMERATENOTSUPPORTED:
            j = "VideoFramerateNotSupported";
            break;
    
        case OAITranscodeReason::REFFRAMESNOTSUPPORTED:
            j = "RefFramesNotSupported";
            break;
    
        case OAITranscodeReason::ANAMORPHICVIDEONOTSUPPORTED:
            j = "AnamorphicVideoNotSupported";
            break;
    
        case OAITranscodeReason::INTERLACEDVIDEONOTSUPPORTED:
            j = "InterlacedVideoNotSupported";
            break;
    
        case OAITranscodeReason::AUDIOCHANNELSNOTSUPPORTED:
            j = "AudioChannelsNotSupported";
            break;
    
        case OAITranscodeReason::AUDIOPROFILENOTSUPPORTED:
            j = "AudioProfileNotSupported";
            break;
    
        case OAITranscodeReason::AUDIOSAMPLERATENOTSUPPORTED:
            j = "AudioSampleRateNotSupported";
            break;
    
        case OAITranscodeReason::AUDIOBITDEPTHNOTSUPPORTED:
            j = "AudioBitDepthNotSupported";
            break;
    
        case OAITranscodeReason::CONTAINERBITRATEEXCEEDSLIMIT:
            j = "ContainerBitrateExceedsLimit";
            break;
    
        case OAITranscodeReason::VIDEOBITRATENOTSUPPORTED:
            j = "VideoBitrateNotSupported";
            break;
    
        case OAITranscodeReason::AUDIOBITRATENOTSUPPORTED:
            j = "AudioBitrateNotSupported";
            break;
    
        case OAITranscodeReason::UNKNOWNVIDEOSTREAMINFO:
            j = "UnknownVideoStreamInfo";
            break;
    
        case OAITranscodeReason::UNKNOWNAUDIOSTREAMINFO:
            j = "UnknownAudioStreamInfo";
            break;
    
        case OAITranscodeReason::DIRECTPLAYERROR:
            j = "DirectPlayError";
            break;
    
        case OAITranscodeReason::VIDEORANGETYPENOTSUPPORTED:
            j = "VideoRangeTypeNotSupported";
            break;
    
    }
}
void from_json(const json_t& j, OAITranscodeReason& e) {
    auto s = j.get<std::string>();
    
    if (s == "ContainerNotSupported"sv) {
        e = (OAITranscodeReason::CONTAINERNOTSUPPORTED);
    } 
    
    else if (s == "VideoCodecNotSupported"sv) {
        e = (OAITranscodeReason::VIDEOCODECNOTSUPPORTED);
    } 
    
    else if (s == "AudioCodecNotSupported"sv) {
        e = (OAITranscodeReason::AUDIOCODECNOTSUPPORTED);
    } 
    
    else if (s == "SubtitleCodecNotSupported"sv) {
        e = (OAITranscodeReason::SUBTITLECODECNOTSUPPORTED);
    } 
    
    else if (s == "AudioIsExternal"sv) {
        e = (OAITranscodeReason::AUDIOISEXTERNAL);
    } 
    
    else if (s == "SecondaryAudioNotSupported"sv) {
        e = (OAITranscodeReason::SECONDARYAUDIONOTSUPPORTED);
    } 
    
    else if (s == "VideoProfileNotSupported"sv) {
        e = (OAITranscodeReason::VIDEOPROFILENOTSUPPORTED);
    } 
    
    else if (s == "VideoLevelNotSupported"sv) {
        e = (OAITranscodeReason::VIDEOLEVELNOTSUPPORTED);
    } 
    
    else if (s == "VideoResolutionNotSupported"sv) {
        e = (OAITranscodeReason::VIDEORESOLUTIONNOTSUPPORTED);
    } 
    
    else if (s == "VideoBitDepthNotSupported"sv) {
        e = (OAITranscodeReason::VIDEOBITDEPTHNOTSUPPORTED);
    } 
    
    else if (s == "VideoFramerateNotSupported"sv) {
        e = (OAITranscodeReason::VIDEOFRAMERATENOTSUPPORTED);
    } 
    
    else if (s == "RefFramesNotSupported"sv) {
        e = (OAITranscodeReason::REFFRAMESNOTSUPPORTED);
    } 
    
    else if (s == "AnamorphicVideoNotSupported"sv) {
        e = (OAITranscodeReason::ANAMORPHICVIDEONOTSUPPORTED);
    } 
    
    else if (s == "InterlacedVideoNotSupported"sv) {
        e = (OAITranscodeReason::INTERLACEDVIDEONOTSUPPORTED);
    } 
    
    else if (s == "AudioChannelsNotSupported"sv) {
        e = (OAITranscodeReason::AUDIOCHANNELSNOTSUPPORTED);
    } 
    
    else if (s == "AudioProfileNotSupported"sv) {
        e = (OAITranscodeReason::AUDIOPROFILENOTSUPPORTED);
    } 
    
    else if (s == "AudioSampleRateNotSupported"sv) {
        e = (OAITranscodeReason::AUDIOSAMPLERATENOTSUPPORTED);
    } 
    
    else if (s == "AudioBitDepthNotSupported"sv) {
        e = (OAITranscodeReason::AUDIOBITDEPTHNOTSUPPORTED);
    } 
    
    else if (s == "ContainerBitrateExceedsLimit"sv) {
        e = (OAITranscodeReason::CONTAINERBITRATEEXCEEDSLIMIT);
    } 
    
    else if (s == "VideoBitrateNotSupported"sv) {
        e = (OAITranscodeReason::VIDEOBITRATENOTSUPPORTED);
    } 
    
    else if (s == "AudioBitrateNotSupported"sv) {
        e = (OAITranscodeReason::AUDIOBITRATENOTSUPPORTED);
    } 
    
    else if (s == "UnknownVideoStreamInfo"sv) {
        e = (OAITranscodeReason::UNKNOWNVIDEOSTREAMINFO);
    } 
    
    else if (s == "UnknownAudioStreamInfo"sv) {
        e = (OAITranscodeReason::UNKNOWNAUDIOSTREAMINFO);
    } 
    
    else if (s == "DirectPlayError"sv) {
        e = (OAITranscodeReason::DIRECTPLAYERROR);
    } 
    
    else if (s == "VideoRangeTypeNotSupported"sv) {
        e = (OAITranscodeReason::VIDEORANGETYPENOTSUPPORTED);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAITranscodeReason";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAITranscodeSeekInfo& e) {
    switch (e)
    {
    
        case OAITranscodeSeekInfo::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAITranscodeSeekInfo::AUTO:
            j = "Auto";
            break;
    
        case OAITranscodeSeekInfo::BYTES:
            j = "Bytes";
            break;
    
    }
}
void from_json(const json_t& j, OAITranscodeSeekInfo& e) {
    auto s = j.get<std::string>();
    
    if (s == "Auto"sv) {
        e = (OAITranscodeSeekInfo::AUTO);
    } 
    
    else if (s == "Bytes"sv) {
        e = (OAITranscodeSeekInfo::BYTES);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAITranscodeSeekInfo";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAITranscodingInfo& o) {
        j["AudioCodec"sv] = o.AudioCodec;
        j["VideoCodec"sv] = o.VideoCodec;
        j["Container"sv] = o.Container;
        j["IsVideoDirect"sv] = o.IsVideoDirect;
        j["IsAudioDirect"sv] = o.IsAudioDirect;
        j["Bitrate"sv] = o.Bitrate;
        j["Framerate"sv] = o.Framerate;
        j["CompletionPercentage"sv] = o.CompletionPercentage;
        j["Width"sv] = o.Width;
        j["Height"sv] = o.Height;
        j["AudioChannels"sv] = o.AudioChannels;
        j["HardwareAccelerationType"sv] = o.HardwareAccelerationType;
        j["TranscodeReasons"sv] = o.TranscodeReasons;
}
void from_json(const json_t& j, OAITranscodingInfo& o) {
    if(j.contains("AudioCodec"sv))
    j.at("AudioCodec"sv).get_to(o.AudioCodec);
    if(j.contains("VideoCodec"sv))
    j.at("VideoCodec"sv).get_to(o.VideoCodec);
    if(j.contains("Container"sv))
    j.at("Container"sv).get_to(o.Container);
    
    j.at("IsVideoDirect"sv).get_to(o.IsVideoDirect);
    
    j.at("IsAudioDirect"sv).get_to(o.IsAudioDirect);
    if(j.contains("Bitrate"sv))
    j.at("Bitrate"sv).get_to(o.Bitrate);
    if(j.contains("Framerate"sv))
    j.at("Framerate"sv).get_to(o.Framerate);
    if(j.contains("CompletionPercentage"sv))
    j.at("CompletionPercentage"sv).get_to(o.CompletionPercentage);
    if(j.contains("Width"sv))
    j.at("Width"sv).get_to(o.Width);
    if(j.contains("Height"sv))
    j.at("Height"sv).get_to(o.Height);
    if(j.contains("AudioChannels"sv))
    j.at("AudioChannels"sv).get_to(o.AudioChannels);
    if(j.contains("HardwareAccelerationType"sv))
    j.at("HardwareAccelerationType"sv).get_to(o.HardwareAccelerationType);
    
    j.at("TranscodeReasons"sv).get_to(o.TranscodeReasons);
}




void to_json(json_t& j, const OAITranscodingProfile& o) {
        j["Container"sv] = o.Container;
        j["Type"sv] = o.Type;
        j["VideoCodec"sv] = o.VideoCodec;
        j["AudioCodec"sv] = o.AudioCodec;
        j["Protocol"sv] = o.Protocol;
        j["EstimateContentLength"sv] = o.EstimateContentLength;
        j["EnableMpegtsM2TsMode"sv] = o.EnableMpegtsM2TsMode;
        j["TranscodeSeekInfo"sv] = o.TranscodeSeekInfo;
        j["CopyTimestamps"sv] = o.CopyTimestamps;
        j["Context"sv] = o.Context;
        j["EnableSubtitlesInManifest"sv] = o.EnableSubtitlesInManifest;
        j["MaxAudioChannels"sv] = o.MaxAudioChannels;
        j["MinSegments"sv] = o.MinSegments;
        j["SegmentLength"sv] = o.SegmentLength;
        j["BreakOnNonKeyFrames"sv] = o.BreakOnNonKeyFrames;
        j["Conditions"sv] = o.Conditions;
}
void from_json(const json_t& j, OAITranscodingProfile& o) {
    
    j.at("Container"sv).get_to(o.Container);
    
    j.at("Type"sv).get_to(o.Type);
    
    j.at("VideoCodec"sv).get_to(o.VideoCodec);
    
    j.at("AudioCodec"sv).get_to(o.AudioCodec);
    
    j.at("Protocol"sv).get_to(o.Protocol);
    
    j.at("EstimateContentLength"sv).get_to(o.EstimateContentLength);
    
    j.at("EnableMpegtsM2TsMode"sv).get_to(o.EnableMpegtsM2TsMode);
    
    j.at("TranscodeSeekInfo"sv).get_to(o.TranscodeSeekInfo);
    
    j.at("CopyTimestamps"sv).get_to(o.CopyTimestamps);
    
    j.at("Context"sv).get_to(o.Context);
    
    j.at("EnableSubtitlesInManifest"sv).get_to(o.EnableSubtitlesInManifest);
    if(j.contains("MaxAudioChannels"sv))
    j.at("MaxAudioChannels"sv).get_to(o.MaxAudioChannels);
    
    j.at("MinSegments"sv).get_to(o.MinSegments);
    
    j.at("SegmentLength"sv).get_to(o.SegmentLength);
    
    j.at("BreakOnNonKeyFrames"sv).get_to(o.BreakOnNonKeyFrames);
    
    j.at("Conditions"sv).get_to(o.Conditions);
}



void to_json(json_t& j, const OAITransportStreamTimestamp& e) {
    switch (e)
    {
    
        case OAITransportStreamTimestamp::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAITransportStreamTimestamp::NONE:
            j = "None";
            break;
    
        case OAITransportStreamTimestamp::ZERO:
            j = "Zero";
            break;
    
        case OAITransportStreamTimestamp::VALID:
            j = "Valid";
            break;
    
    }
}
void from_json(const json_t& j, OAITransportStreamTimestamp& e) {
    auto s = j.get<std::string>();
    
    if (s == "None"sv) {
        e = (OAITransportStreamTimestamp::NONE);
    } 
    
    else if (s == "Zero"sv) {
        e = (OAITransportStreamTimestamp::ZERO);
    } 
    
    else if (s == "Valid"sv) {
        e = (OAITransportStreamTimestamp::VALID);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAITransportStreamTimestamp";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAITrickplayInfo& o) {
        j["Width"sv] = o.Width;
        j["Height"sv] = o.Height;
        j["TileWidth"sv] = o.TileWidth;
        j["TileHeight"sv] = o.TileHeight;
        j["ThumbnailCount"sv] = o.ThumbnailCount;
        j["Interval"sv] = o.Interval;
        j["Bandwidth"sv] = o.Bandwidth;
}
void from_json(const json_t& j, OAITrickplayInfo& o) {
    
    j.at("Width"sv).get_to(o.Width);
    
    j.at("Height"sv).get_to(o.Height);
    
    j.at("TileWidth"sv).get_to(o.TileWidth);
    
    j.at("TileHeight"sv).get_to(o.TileHeight);
    
    j.at("ThumbnailCount"sv).get_to(o.ThumbnailCount);
    
    j.at("Interval"sv).get_to(o.Interval);
    
    j.at("Bandwidth"sv).get_to(o.Bandwidth);
}




void to_json(json_t& j, const OAITrickplayOptions& o) {
        j["EnableHwAcceleration"sv] = o.EnableHwAcceleration;
        j["EnableHwEncoding"sv] = o.EnableHwEncoding;
        j["ScanBehavior"sv] = o.ScanBehavior;
        j["ProcessPriority"sv] = o.ProcessPriority;
        j["Interval"sv] = o.Interval;
        j["WidthResolutions"sv] = o.WidthResolutions;
        j["TileWidth"sv] = o.TileWidth;
        j["TileHeight"sv] = o.TileHeight;
        j["Qscale"sv] = o.Qscale;
        j["JpegQuality"sv] = o.JpegQuality;
        j["ProcessThreads"sv] = o.ProcessThreads;
}
void from_json(const json_t& j, OAITrickplayOptions& o) {
    
    j.at("EnableHwAcceleration"sv).get_to(o.EnableHwAcceleration);
    
    j.at("EnableHwEncoding"sv).get_to(o.EnableHwEncoding);
    
    j.at("ScanBehavior"sv).get_to(o.ScanBehavior);
    
    j.at("ProcessPriority"sv).get_to(o.ProcessPriority);
    
    j.at("Interval"sv).get_to(o.Interval);
    
    j.at("WidthResolutions"sv).get_to(o.WidthResolutions);
    
    j.at("TileWidth"sv).get_to(o.TileWidth);
    
    j.at("TileHeight"sv).get_to(o.TileHeight);
    
    j.at("Qscale"sv).get_to(o.Qscale);
    
    j.at("JpegQuality"sv).get_to(o.JpegQuality);
    
    j.at("ProcessThreads"sv).get_to(o.ProcessThreads);
}



void to_json(json_t& j, const OAITrickplayScanBehavior& e) {
    switch (e)
    {
    
        case OAITrickplayScanBehavior::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAITrickplayScanBehavior::BLOCKING:
            j = "Blocking";
            break;
    
        case OAITrickplayScanBehavior::NONBLOCKING:
            j = "NonBlocking";
            break;
    
    }
}
void from_json(const json_t& j, OAITrickplayScanBehavior& e) {
    auto s = j.get<std::string>();
    
    if (s == "Blocking"sv) {
        e = (OAITrickplayScanBehavior::BLOCKING);
    } 
    
    else if (s == "NonBlocking"sv) {
        e = (OAITrickplayScanBehavior::NONBLOCKING);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAITrickplayScanBehavior";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAITunerChannelMapping& o) {
        j["Name"sv] = o.Name;
        j["ProviderChannelName"sv] = o.ProviderChannelName;
        j["ProviderChannelId"sv] = o.ProviderChannelId;
        j["Id"sv] = o.Id;
}
void from_json(const json_t& j, OAITunerChannelMapping& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("ProviderChannelName"sv))
    j.at("ProviderChannelName"sv).get_to(o.ProviderChannelName);
    if(j.contains("ProviderChannelId"sv))
    j.at("ProviderChannelId"sv).get_to(o.ProviderChannelId);
    if(j.contains("Id"sv))
    j.at("Id"sv).get_to(o.Id);
}




void to_json(json_t& j, const OAITunerHostInfo& o) {
        j["Id"sv] = o.Id;
        j["Url"sv] = o.Url;
        j["Type"sv] = o.Type;
        j["DeviceId"sv] = o.DeviceId;
        j["FriendlyName"sv] = o.FriendlyName;
        j["ImportFavoritesOnly"sv] = o.ImportFavoritesOnly;
        j["AllowHWTranscoding"sv] = o.AllowHWTranscoding;
        j["EnableStreamLooping"sv] = o.EnableStreamLooping;
        j["Source"sv] = o.Source;
        j["TunerCount"sv] = o.TunerCount;
        j["UserAgent"sv] = o.UserAgent;
        j["IgnoreDts"sv] = o.IgnoreDts;
}
void from_json(const json_t& j, OAITunerHostInfo& o) {
    if(j.contains("Id"sv))
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("Url"sv))
    j.at("Url"sv).get_to(o.Url);
    if(j.contains("Type"sv))
    j.at("Type"sv).get_to(o.Type);
    if(j.contains("DeviceId"sv))
    j.at("DeviceId"sv).get_to(o.DeviceId);
    if(j.contains("FriendlyName"sv))
    j.at("FriendlyName"sv).get_to(o.FriendlyName);
    
    j.at("ImportFavoritesOnly"sv).get_to(o.ImportFavoritesOnly);
    
    j.at("AllowHWTranscoding"sv).get_to(o.AllowHWTranscoding);
    
    j.at("EnableStreamLooping"sv).get_to(o.EnableStreamLooping);
    if(j.contains("Source"sv))
    j.at("Source"sv).get_to(o.Source);
    
    j.at("TunerCount"sv).get_to(o.TunerCount);
    if(j.contains("UserAgent"sv))
    j.at("UserAgent"sv).get_to(o.UserAgent);
    
    j.at("IgnoreDts"sv).get_to(o.IgnoreDts);
}




void to_json(json_t& j, const OAITypeOptions& o) {
        j["Type"sv] = o.Type;
        j["MetadataFetchers"sv] = o.MetadataFetchers;
        j["MetadataFetcherOrder"sv] = o.MetadataFetcherOrder;
        j["ImageFetchers"sv] = o.ImageFetchers;
        j["ImageFetcherOrder"sv] = o.ImageFetcherOrder;
        j["ImageOptions"sv] = o.ImageOptions;
}
void from_json(const json_t& j, OAITypeOptions& o) {
    if(j.contains("Type"sv))
    j.at("Type"sv).get_to(o.Type);
    if(j.contains("MetadataFetchers"sv))
    j.at("MetadataFetchers"sv).get_to(o.MetadataFetchers);
    if(j.contains("MetadataFetcherOrder"sv))
    j.at("MetadataFetcherOrder"sv).get_to(o.MetadataFetcherOrder);
    if(j.contains("ImageFetchers"sv))
    j.at("ImageFetchers"sv).get_to(o.ImageFetchers);
    if(j.contains("ImageFetcherOrder"sv))
    j.at("ImageFetcherOrder"sv).get_to(o.ImageFetcherOrder);
    if(j.contains("ImageOptions"sv))
    j.at("ImageOptions"sv).get_to(o.ImageOptions);
}



void to_json(json_t& j, const OAIUnratedItem& e) {
    switch (e)
    {
    
        case OAIUnratedItem::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIUnratedItem::MOVIE:
            j = "Movie";
            break;
    
        case OAIUnratedItem::TRAILER:
            j = "Trailer";
            break;
    
        case OAIUnratedItem::SERIES:
            j = "Series";
            break;
    
        case OAIUnratedItem::MUSIC:
            j = "Music";
            break;
    
        case OAIUnratedItem::BOOK:
            j = "Book";
            break;
    
        case OAIUnratedItem::LIVETVCHANNEL:
            j = "LiveTvChannel";
            break;
    
        case OAIUnratedItem::LIVETVPROGRAM:
            j = "LiveTvProgram";
            break;
    
        case OAIUnratedItem::CHANNELCONTENT:
            j = "ChannelContent";
            break;
    
        case OAIUnratedItem::OTHER:
            j = "Other";
            break;
    
    }
}
void from_json(const json_t& j, OAIUnratedItem& e) {
    auto s = j.get<std::string>();
    
    if (s == "Movie"sv) {
        e = (OAIUnratedItem::MOVIE);
    } 
    
    else if (s == "Trailer"sv) {
        e = (OAIUnratedItem::TRAILER);
    } 
    
    else if (s == "Series"sv) {
        e = (OAIUnratedItem::SERIES);
    } 
    
    else if (s == "Music"sv) {
        e = (OAIUnratedItem::MUSIC);
    } 
    
    else if (s == "Book"sv) {
        e = (OAIUnratedItem::BOOK);
    } 
    
    else if (s == "LiveTvChannel"sv) {
        e = (OAIUnratedItem::LIVETVCHANNEL);
    } 
    
    else if (s == "LiveTvProgram"sv) {
        e = (OAIUnratedItem::LIVETVPROGRAM);
    } 
    
    else if (s == "ChannelContent"sv) {
        e = (OAIUnratedItem::CHANNELCONTENT);
    } 
    
    else if (s == "Other"sv) {
        e = (OAIUnratedItem::OTHER);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIUnratedItem";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIUpdateLibraryOptionsDto& o) {
        j["Id"sv] = o.Id;
        j["LibraryOptions"sv] = o.LibraryOptions;
}
void from_json(const json_t& j, OAIUpdateLibraryOptionsDto& o) {
    
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("LibraryOptions"sv))
    j.at("LibraryOptions"sv).get_to(o.LibraryOptions);
}




void to_json(json_t& j, const OAIUpdateMediaPathRequestDto& o) {
        j["Name"sv] = o.Name;
        j["PathInfo"sv] = o.PathInfo;
}
void from_json(const json_t& j, OAIUpdateMediaPathRequestDto& o) {
    
    j.at("Name"sv).get_to(o.Name);
    
    j.at("PathInfo"sv).get_to(o.PathInfo);
}




void to_json(json_t& j, const OAIUpdatePlaylistDto& o) {
        j["Name"sv] = o.Name;
        j["Ids"sv] = o.Ids;
        j["Users"sv] = o.Users;
        j["IsPublic"sv] = o.IsPublic;
}
void from_json(const json_t& j, OAIUpdatePlaylistDto& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Ids"sv))
    j.at("Ids"sv).get_to(o.Ids);
    if(j.contains("Users"sv))
    j.at("Users"sv).get_to(o.Users);
    if(j.contains("IsPublic"sv))
    j.at("IsPublic"sv).get_to(o.IsPublic);
}




void to_json(json_t& j, const OAIUpdatePlaylistUserDto& o) {
        j["CanEdit"sv] = o.CanEdit;
}
void from_json(const json_t& j, OAIUpdatePlaylistUserDto& o) {
    if(j.contains("CanEdit"sv))
    j.at("CanEdit"sv).get_to(o.CanEdit);
}




void to_json(json_t& j, const OAIUpdateUserItemDataDto& o) {
        j["Rating"sv] = o.Rating;
        j["PlayedPercentage"sv] = o.PlayedPercentage;
        j["UnplayedItemCount"sv] = o.UnplayedItemCount;
        j["PlaybackPositionTicks"sv] = o.PlaybackPositionTicks;
        j["PlayCount"sv] = o.PlayCount;
        j["IsFavorite"sv] = o.IsFavorite;
        j["Likes"sv] = o.Likes;
        j["LastPlayedDate"sv] = o.LastPlayedDate;
        j["Played"sv] = o.Played;
        j["Key"sv] = o.Key;
        j["ItemId"sv] = o.ItemId;
}
void from_json(const json_t& j, OAIUpdateUserItemDataDto& o) {
    if(j.contains("Rating"sv))
    j.at("Rating"sv).get_to(o.Rating);
    if(j.contains("PlayedPercentage"sv))
    j.at("PlayedPercentage"sv).get_to(o.PlayedPercentage);
    if(j.contains("UnplayedItemCount"sv))
    j.at("UnplayedItemCount"sv).get_to(o.UnplayedItemCount);
    if(j.contains("PlaybackPositionTicks"sv))
    j.at("PlaybackPositionTicks"sv).get_to(o.PlaybackPositionTicks);
    if(j.contains("PlayCount"sv))
    j.at("PlayCount"sv).get_to(o.PlayCount);
    if(j.contains("IsFavorite"sv))
    j.at("IsFavorite"sv).get_to(o.IsFavorite);
    if(j.contains("Likes"sv))
    j.at("Likes"sv).get_to(o.Likes);
    if(j.contains("LastPlayedDate"sv))
    j.at("LastPlayedDate"sv).get_to(o.LastPlayedDate);
    if(j.contains("Played"sv))
    j.at("Played"sv).get_to(o.Played);
    if(j.contains("Key"sv))
    j.at("Key"sv).get_to(o.Key);
    if(j.contains("ItemId"sv))
    j.at("ItemId"sv).get_to(o.ItemId);
}




void to_json(json_t& j, const OAIUpdateUserPassword& o) {
        j["CurrentPassword"sv] = o.CurrentPassword;
        j["CurrentPw"sv] = o.CurrentPw;
        j["NewPw"sv] = o.NewPw;
        j["ResetPassword"sv] = o.ResetPassword;
}
void from_json(const json_t& j, OAIUpdateUserPassword& o) {
    if(j.contains("CurrentPassword"sv))
    j.at("CurrentPassword"sv).get_to(o.CurrentPassword);
    if(j.contains("CurrentPw"sv))
    j.at("CurrentPw"sv).get_to(o.CurrentPw);
    if(j.contains("NewPw"sv))
    j.at("NewPw"sv).get_to(o.NewPw);
    
    j.at("ResetPassword"sv).get_to(o.ResetPassword);
}




void to_json(json_t& j, const OAIUploadSubtitleDto& o) {
        j["Language"sv] = o.Language;
        j["Format"sv] = o.Format;
        j["IsForced"sv] = o.IsForced;
        j["IsHearingImpaired"sv] = o.IsHearingImpaired;
        j["Data"sv] = o.Data;
}
void from_json(const json_t& j, OAIUploadSubtitleDto& o) {
    
    j.at("Language"sv).get_to(o.Language);
    
    j.at("Format"sv).get_to(o.Format);
    
    j.at("IsForced"sv).get_to(o.IsForced);
    
    j.at("IsHearingImpaired"sv).get_to(o.IsHearingImpaired);
    
    j.at("Data"sv).get_to(o.Data);
}




void to_json(json_t& j, const OAIUserConfiguration& o) {
        j["AudioLanguagePreference"sv] = o.AudioLanguagePreference;
        j["PlayDefaultAudioTrack"sv] = o.PlayDefaultAudioTrack;
        j["SubtitleLanguagePreference"sv] = o.SubtitleLanguagePreference;
        j["DisplayMissingEpisodes"sv] = o.DisplayMissingEpisodes;
        j["GroupedFolders"sv] = o.GroupedFolders;
        j["SubtitleMode"sv] = o.SubtitleMode;
        j["DisplayCollectionsView"sv] = o.DisplayCollectionsView;
        j["EnableLocalPassword"sv] = o.EnableLocalPassword;
        j["OrderedViews"sv] = o.OrderedViews;
        j["LatestItemsExcludes"sv] = o.LatestItemsExcludes;
        j["MyMediaExcludes"sv] = o.MyMediaExcludes;
        j["HidePlayedInLatest"sv] = o.HidePlayedInLatest;
        j["RememberAudioSelections"sv] = o.RememberAudioSelections;
        j["RememberSubtitleSelections"sv] = o.RememberSubtitleSelections;
        j["EnableNextEpisodeAutoPlay"sv] = o.EnableNextEpisodeAutoPlay;
        j["CastReceiverId"sv] = o.CastReceiverId;
}
void from_json(const json_t& j, OAIUserConfiguration& o) {
    if(j.contains("AudioLanguagePreference"sv))
    j.at("AudioLanguagePreference"sv).get_to(o.AudioLanguagePreference);
    
    j.at("PlayDefaultAudioTrack"sv).get_to(o.PlayDefaultAudioTrack);
    if(j.contains("SubtitleLanguagePreference"sv))
    j.at("SubtitleLanguagePreference"sv).get_to(o.SubtitleLanguagePreference);
    
    j.at("DisplayMissingEpisodes"sv).get_to(o.DisplayMissingEpisodes);
    
    j.at("GroupedFolders"sv).get_to(o.GroupedFolders);
    
    j.at("SubtitleMode"sv).get_to(o.SubtitleMode);
    
    j.at("DisplayCollectionsView"sv).get_to(o.DisplayCollectionsView);
    
    j.at("EnableLocalPassword"sv).get_to(o.EnableLocalPassword);
    
    j.at("OrderedViews"sv).get_to(o.OrderedViews);
    
    j.at("LatestItemsExcludes"sv).get_to(o.LatestItemsExcludes);
    
    j.at("MyMediaExcludes"sv).get_to(o.MyMediaExcludes);
    
    j.at("HidePlayedInLatest"sv).get_to(o.HidePlayedInLatest);
    
    j.at("RememberAudioSelections"sv).get_to(o.RememberAudioSelections);
    
    j.at("RememberSubtitleSelections"sv).get_to(o.RememberSubtitleSelections);
    
    j.at("EnableNextEpisodeAutoPlay"sv).get_to(o.EnableNextEpisodeAutoPlay);
    if(j.contains("CastReceiverId"sv))
    j.at("CastReceiverId"sv).get_to(o.CastReceiverId);
}




void to_json(json_t& j, const OAIUserDataChangeInfo& o) {
        j["UserId"sv] = o.UserId;
        j["UserDataList"sv] = o.UserDataList;
}
void from_json(const json_t& j, OAIUserDataChangeInfo& o) {
    if(j.contains("UserId"sv))
    j.at("UserId"sv).get_to(o.UserId);
    if(j.contains("UserDataList"sv))
    j.at("UserDataList"sv).get_to(o.UserDataList);
}




void to_json(json_t& j, const OAIUserDataChangedMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIUserDataChangedMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAIUserDeletedMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIUserDeletedMessage& o) {
    
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAIUserDto& o) {
        j["Name"sv] = o.Name;
        j["ServerId"sv] = o.ServerId;
        j["ServerName"sv] = o.ServerName;
        j["Id"sv] = o.Id;
        j["PrimaryImageTag"sv] = o.PrimaryImageTag;
        j["HasPassword"sv] = o.HasPassword;
        j["HasConfiguredPassword"sv] = o.HasConfiguredPassword;
        j["HasConfiguredEasyPassword"sv] = o.HasConfiguredEasyPassword;
        j["EnableAutoLogin"sv] = o.EnableAutoLogin;
        j["LastLoginDate"sv] = o.LastLoginDate;
        j["LastActivityDate"sv] = o.LastActivityDate;
        j["Configuration"sv] = o.Configuration;
        j["Policy"sv] = o.Policy;
        j["PrimaryImageAspectRatio"sv] = o.PrimaryImageAspectRatio;
}
void from_json(const json_t& j, OAIUserDto& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("ServerId"sv))
    j.at("ServerId"sv).get_to(o.ServerId);
    if(j.contains("ServerName"sv))
    j.at("ServerName"sv).get_to(o.ServerName);
    
    j.at("Id"sv).get_to(o.Id);
    if(j.contains("PrimaryImageTag"sv))
    j.at("PrimaryImageTag"sv).get_to(o.PrimaryImageTag);
    
    j.at("HasPassword"sv).get_to(o.HasPassword);
    
    j.at("HasConfiguredPassword"sv).get_to(o.HasConfiguredPassword);
    
    j.at("HasConfiguredEasyPassword"sv).get_to(o.HasConfiguredEasyPassword);
    if(j.contains("EnableAutoLogin"sv))
    j.at("EnableAutoLogin"sv).get_to(o.EnableAutoLogin);
    if(j.contains("LastLoginDate"sv))
    j.at("LastLoginDate"sv).get_to(o.LastLoginDate);
    if(j.contains("LastActivityDate"sv))
    j.at("LastActivityDate"sv).get_to(o.LastActivityDate);
    if(j.contains("Configuration"sv))
    j.at("Configuration"sv).get_to(o.Configuration);
    if(j.contains("Policy"sv))
    j.at("Policy"sv).get_to(o.Policy);
    if(j.contains("PrimaryImageAspectRatio"sv))
    j.at("PrimaryImageAspectRatio"sv).get_to(o.PrimaryImageAspectRatio);
}




void to_json(json_t& j, const OAIUserItemDataDto& o) {
        j["Rating"sv] = o.Rating;
        j["PlayedPercentage"sv] = o.PlayedPercentage;
        j["UnplayedItemCount"sv] = o.UnplayedItemCount;
        j["PlaybackPositionTicks"sv] = o.PlaybackPositionTicks;
        j["PlayCount"sv] = o.PlayCount;
        j["IsFavorite"sv] = o.IsFavorite;
        j["Likes"sv] = o.Likes;
        j["LastPlayedDate"sv] = o.LastPlayedDate;
        j["Played"sv] = o.Played;
        j["Key"sv] = o.Key;
        j["ItemId"sv] = o.ItemId;
}
void from_json(const json_t& j, OAIUserItemDataDto& o) {
    if(j.contains("Rating"sv))
    j.at("Rating"sv).get_to(o.Rating);
    if(j.contains("PlayedPercentage"sv))
    j.at("PlayedPercentage"sv).get_to(o.PlayedPercentage);
    if(j.contains("UnplayedItemCount"sv))
    j.at("UnplayedItemCount"sv).get_to(o.UnplayedItemCount);
    
    j.at("PlaybackPositionTicks"sv).get_to(o.PlaybackPositionTicks);
    
    j.at("PlayCount"sv).get_to(o.PlayCount);
    
    j.at("IsFavorite"sv).get_to(o.IsFavorite);
    if(j.contains("Likes"sv))
    j.at("Likes"sv).get_to(o.Likes);
    if(j.contains("LastPlayedDate"sv))
    j.at("LastPlayedDate"sv).get_to(o.LastPlayedDate);
    
    j.at("Played"sv).get_to(o.Played);
    if(j.contains("Key"sv))
    j.at("Key"sv).get_to(o.Key);
    if(j.contains("ItemId"sv))
    j.at("ItemId"sv).get_to(o.ItemId);
}




void to_json(json_t& j, const OAIUserPolicy& o) {
        j["IsAdministrator"sv] = o.IsAdministrator;
        j["IsHidden"sv] = o.IsHidden;
        j["EnableCollectionManagement"sv] = o.EnableCollectionManagement;
        j["EnableSubtitleManagement"sv] = o.EnableSubtitleManagement;
        j["EnableLyricManagement"sv] = o.EnableLyricManagement;
        j["IsDisabled"sv] = o.IsDisabled;
        j["MaxParentalRating"sv] = o.MaxParentalRating;
        j["BlockedTags"sv] = o.BlockedTags;
        j["AllowedTags"sv] = o.AllowedTags;
        j["EnableUserPreferenceAccess"sv] = o.EnableUserPreferenceAccess;
        j["AccessSchedules"sv] = o.AccessSchedules;
        j["BlockUnratedItems"sv] = o.BlockUnratedItems;
        j["EnableRemoteControlOfOtherUsers"sv] = o.EnableRemoteControlOfOtherUsers;
        j["EnableSharedDeviceControl"sv] = o.EnableSharedDeviceControl;
        j["EnableRemoteAccess"sv] = o.EnableRemoteAccess;
        j["EnableLiveTvManagement"sv] = o.EnableLiveTvManagement;
        j["EnableLiveTvAccess"sv] = o.EnableLiveTvAccess;
        j["EnableMediaPlayback"sv] = o.EnableMediaPlayback;
        j["EnableAudioPlaybackTranscoding"sv] = o.EnableAudioPlaybackTranscoding;
        j["EnableVideoPlaybackTranscoding"sv] = o.EnableVideoPlaybackTranscoding;
        j["EnablePlaybackRemuxing"sv] = o.EnablePlaybackRemuxing;
        j["ForceRemoteSourceTranscoding"sv] = o.ForceRemoteSourceTranscoding;
        j["EnableContentDeletion"sv] = o.EnableContentDeletion;
        j["EnableContentDeletionFromFolders"sv] = o.EnableContentDeletionFromFolders;
        j["EnableContentDownloading"sv] = o.EnableContentDownloading;
        j["EnableSyncTranscoding"sv] = o.EnableSyncTranscoding;
        j["EnableMediaConversion"sv] = o.EnableMediaConversion;
        j["EnabledDevices"sv] = o.EnabledDevices;
        j["EnableAllDevices"sv] = o.EnableAllDevices;
        j["EnabledChannels"sv] = o.EnabledChannels;
        j["EnableAllChannels"sv] = o.EnableAllChannels;
        j["EnabledFolders"sv] = o.EnabledFolders;
        j["EnableAllFolders"sv] = o.EnableAllFolders;
        j["InvalidLoginAttemptCount"sv] = o.InvalidLoginAttemptCount;
        j["LoginAttemptsBeforeLockout"sv] = o.LoginAttemptsBeforeLockout;
        j["MaxActiveSessions"sv] = o.MaxActiveSessions;
        j["EnablePublicSharing"sv] = o.EnablePublicSharing;
        j["BlockedMediaFolders"sv] = o.BlockedMediaFolders;
        j["BlockedChannels"sv] = o.BlockedChannels;
        j["RemoteClientBitrateLimit"sv] = o.RemoteClientBitrateLimit;
        j["AuthenticationProviderId"sv] = o.AuthenticationProviderId;
        j["PasswordResetProviderId"sv] = o.PasswordResetProviderId;
        j["SyncPlayAccess"sv] = o.SyncPlayAccess;
}
void from_json(const json_t& j, OAIUserPolicy& o) {
    
    j.at("IsAdministrator"sv).get_to(o.IsAdministrator);
    
    j.at("IsHidden"sv).get_to(o.IsHidden);
    
    j.at("EnableCollectionManagement"sv).get_to(o.EnableCollectionManagement);
    
    j.at("EnableSubtitleManagement"sv).get_to(o.EnableSubtitleManagement);
    
    j.at("EnableLyricManagement"sv).get_to(o.EnableLyricManagement);
    
    j.at("IsDisabled"sv).get_to(o.IsDisabled);
    if(j.contains("MaxParentalRating"sv))
    j.at("MaxParentalRating"sv).get_to(o.MaxParentalRating);
    if(j.contains("BlockedTags"sv))
    j.at("BlockedTags"sv).get_to(o.BlockedTags);
    if(j.contains("AllowedTags"sv))
    j.at("AllowedTags"sv).get_to(o.AllowedTags);
    
    j.at("EnableUserPreferenceAccess"sv).get_to(o.EnableUserPreferenceAccess);
    if(j.contains("AccessSchedules"sv))
    j.at("AccessSchedules"sv).get_to(o.AccessSchedules);
    if(j.contains("BlockUnratedItems"sv))
    j.at("BlockUnratedItems"sv).get_to(o.BlockUnratedItems);
    
    j.at("EnableRemoteControlOfOtherUsers"sv).get_to(o.EnableRemoteControlOfOtherUsers);
    
    j.at("EnableSharedDeviceControl"sv).get_to(o.EnableSharedDeviceControl);
    
    j.at("EnableRemoteAccess"sv).get_to(o.EnableRemoteAccess);
    
    j.at("EnableLiveTvManagement"sv).get_to(o.EnableLiveTvManagement);
    
    j.at("EnableLiveTvAccess"sv).get_to(o.EnableLiveTvAccess);
    
    j.at("EnableMediaPlayback"sv).get_to(o.EnableMediaPlayback);
    
    j.at("EnableAudioPlaybackTranscoding"sv).get_to(o.EnableAudioPlaybackTranscoding);
    
    j.at("EnableVideoPlaybackTranscoding"sv).get_to(o.EnableVideoPlaybackTranscoding);
    
    j.at("EnablePlaybackRemuxing"sv).get_to(o.EnablePlaybackRemuxing);
    
    j.at("ForceRemoteSourceTranscoding"sv).get_to(o.ForceRemoteSourceTranscoding);
    
    j.at("EnableContentDeletion"sv).get_to(o.EnableContentDeletion);
    if(j.contains("EnableContentDeletionFromFolders"sv))
    j.at("EnableContentDeletionFromFolders"sv).get_to(o.EnableContentDeletionFromFolders);
    
    j.at("EnableContentDownloading"sv).get_to(o.EnableContentDownloading);
    
    j.at("EnableSyncTranscoding"sv).get_to(o.EnableSyncTranscoding);
    
    j.at("EnableMediaConversion"sv).get_to(o.EnableMediaConversion);
    if(j.contains("EnabledDevices"sv))
    j.at("EnabledDevices"sv).get_to(o.EnabledDevices);
    
    j.at("EnableAllDevices"sv).get_to(o.EnableAllDevices);
    if(j.contains("EnabledChannels"sv))
    j.at("EnabledChannels"sv).get_to(o.EnabledChannels);
    
    j.at("EnableAllChannels"sv).get_to(o.EnableAllChannels);
    if(j.contains("EnabledFolders"sv))
    j.at("EnabledFolders"sv).get_to(o.EnabledFolders);
    
    j.at("EnableAllFolders"sv).get_to(o.EnableAllFolders);
    
    j.at("InvalidLoginAttemptCount"sv).get_to(o.InvalidLoginAttemptCount);
    
    j.at("LoginAttemptsBeforeLockout"sv).get_to(o.LoginAttemptsBeforeLockout);
    
    j.at("MaxActiveSessions"sv).get_to(o.MaxActiveSessions);
    
    j.at("EnablePublicSharing"sv).get_to(o.EnablePublicSharing);
    if(j.contains("BlockedMediaFolders"sv))
    j.at("BlockedMediaFolders"sv).get_to(o.BlockedMediaFolders);
    if(j.contains("BlockedChannels"sv))
    j.at("BlockedChannels"sv).get_to(o.BlockedChannels);
    
    j.at("RemoteClientBitrateLimit"sv).get_to(o.RemoteClientBitrateLimit);
    
    j.at("AuthenticationProviderId"sv).get_to(o.AuthenticationProviderId);
    
    j.at("PasswordResetProviderId"sv).get_to(o.PasswordResetProviderId);
    
    j.at("SyncPlayAccess"sv).get_to(o.SyncPlayAccess);
}




void to_json(json_t& j, const OAIUserUpdatedMessage& o) {
        j["Data"sv] = o.Data;
        j["MessageId"sv] = o.MessageId;
        j["MessageType"sv] = o.MessageType;
}
void from_json(const json_t& j, OAIUserUpdatedMessage& o) {
    if(j.contains("Data"sv))
    j.at("Data"sv).get_to(o.Data);
    
    j.at("MessageId"sv).get_to(o.MessageId);
    
    j.at("MessageType"sv).get_to(o.MessageType);
}




void to_json(json_t& j, const OAIUtcTimeResponse& o) {
        j["RequestReceptionTime"sv] = o.RequestReceptionTime;
        j["ResponseTransmissionTime"sv] = o.ResponseTransmissionTime;
}
void from_json(const json_t& j, OAIUtcTimeResponse& o) {
    
    j.at("RequestReceptionTime"sv).get_to(o.RequestReceptionTime);
    
    j.at("ResponseTransmissionTime"sv).get_to(o.ResponseTransmissionTime);
}




void to_json(json_t& j, const OAIValidatePathDto& o) {
        j["ValidateWritable"sv] = o.ValidateWritable;
        j["Path"sv] = o.Path;
        j["IsFile"sv] = o.IsFile;
}
void from_json(const json_t& j, OAIValidatePathDto& o) {
    
    j.at("ValidateWritable"sv).get_to(o.ValidateWritable);
    if(j.contains("Path"sv))
    j.at("Path"sv).get_to(o.Path);
    if(j.contains("IsFile"sv))
    j.at("IsFile"sv).get_to(o.IsFile);
}




void to_json(json_t& j, const OAIVersionInfo& o) {
        j["version"sv] = o.version;
        j["VersionNumber"sv] = o.VersionNumber;
        j["changelog"sv] = o.changelog;
        j["targetAbi"sv] = o.targetAbi;
        j["sourceUrl"sv] = o.sourceUrl;
        j["checksum"sv] = o.checksum;
        j["timestamp"sv] = o.timestamp;
        j["repositoryName"sv] = o.repositoryName;
        j["repositoryUrl"sv] = o.repositoryUrl;
}
void from_json(const json_t& j, OAIVersionInfo& o) {
    
    j.at("version"sv).get_to(o.version);
    
    j.at("VersionNumber"sv).get_to(o.VersionNumber);
    if(j.contains("changelog"sv))
    j.at("changelog"sv).get_to(o.changelog);
    if(j.contains("targetAbi"sv))
    j.at("targetAbi"sv).get_to(o.targetAbi);
    if(j.contains("sourceUrl"sv))
    j.at("sourceUrl"sv).get_to(o.sourceUrl);
    if(j.contains("checksum"sv))
    j.at("checksum"sv).get_to(o.checksum);
    if(j.contains("timestamp"sv))
    j.at("timestamp"sv).get_to(o.timestamp);
    
    j.at("repositoryName"sv).get_to(o.repositoryName);
    
    j.at("repositoryUrl"sv).get_to(o.repositoryUrl);
}



void to_json(json_t& j, const OAIVideo3DFormat& e) {
    switch (e)
    {
    
        case OAIVideo3DFormat::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIVideo3DFormat::HALFSIDEBYSIDE:
            j = "HalfSideBySide";
            break;
    
        case OAIVideo3DFormat::FULLSIDEBYSIDE:
            j = "FullSideBySide";
            break;
    
        case OAIVideo3DFormat::FULLTOPANDBOTTOM:
            j = "FullTopAndBottom";
            break;
    
        case OAIVideo3DFormat::HALFTOPANDBOTTOM:
            j = "HalfTopAndBottom";
            break;
    
        case OAIVideo3DFormat::MVC:
            j = "MVC";
            break;
    
    }
}
void from_json(const json_t& j, OAIVideo3DFormat& e) {
    auto s = j.get<std::string>();
    
    if (s == "HalfSideBySide"sv) {
        e = (OAIVideo3DFormat::HALFSIDEBYSIDE);
    } 
    
    else if (s == "FullSideBySide"sv) {
        e = (OAIVideo3DFormat::FULLSIDEBYSIDE);
    } 
    
    else if (s == "FullTopAndBottom"sv) {
        e = (OAIVideo3DFormat::FULLTOPANDBOTTOM);
    } 
    
    else if (s == "HalfTopAndBottom"sv) {
        e = (OAIVideo3DFormat::HALFTOPANDBOTTOM);
    } 
    
    else if (s == "MVC"sv) {
        e = (OAIVideo3DFormat::MVC);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIVideo3DFormat";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIVideoRange& e) {
    switch (e)
    {
    
        case OAIVideoRange::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIVideoRange::UNKNOWN:
            j = "Unknown";
            break;
    
        case OAIVideoRange::SDR:
            j = "SDR";
            break;
    
        case OAIVideoRange::HDR:
            j = "HDR";
            break;
    
    }
}
void from_json(const json_t& j, OAIVideoRange& e) {
    auto s = j.get<std::string>();
    
    if (s == "Unknown"sv) {
        e = (OAIVideoRange::UNKNOWN);
    } 
    
    else if (s == "SDR"sv) {
        e = (OAIVideoRange::SDR);
    } 
    
    else if (s == "HDR"sv) {
        e = (OAIVideoRange::HDR);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIVideoRange";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIVideoRangeType& e) {
    switch (e)
    {
    
        case OAIVideoRangeType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIVideoRangeType::UNKNOWN:
            j = "Unknown";
            break;
    
        case OAIVideoRangeType::SDR:
            j = "SDR";
            break;
    
        case OAIVideoRangeType::HDR10:
            j = "HDR10";
            break;
    
        case OAIVideoRangeType::HLG:
            j = "HLG";
            break;
    
        case OAIVideoRangeType::DOVI:
            j = "DOVI";
            break;
    
        case OAIVideoRangeType::DOVIWITHHDR10:
            j = "DOVIWithHDR10";
            break;
    
        case OAIVideoRangeType::DOVIWITHHLG:
            j = "DOVIWithHLG";
            break;
    
        case OAIVideoRangeType::DOVIWITHSDR:
            j = "DOVIWithSDR";
            break;
    
        case OAIVideoRangeType::HDR10PLUS:
            j = "HDR10Plus";
            break;
    
    }
}
void from_json(const json_t& j, OAIVideoRangeType& e) {
    auto s = j.get<std::string>();
    
    if (s == "Unknown"sv) {
        e = (OAIVideoRangeType::UNKNOWN);
    } 
    
    else if (s == "SDR"sv) {
        e = (OAIVideoRangeType::SDR);
    } 
    
    else if (s == "HDR10"sv) {
        e = (OAIVideoRangeType::HDR10);
    } 
    
    else if (s == "HLG"sv) {
        e = (OAIVideoRangeType::HLG);
    } 
    
    else if (s == "DOVI"sv) {
        e = (OAIVideoRangeType::DOVI);
    } 
    
    else if (s == "DOVIWithHDR10"sv) {
        e = (OAIVideoRangeType::DOVIWITHHDR10);
    } 
    
    else if (s == "DOVIWithHLG"sv) {
        e = (OAIVideoRangeType::DOVIWITHHLG);
    } 
    
    else if (s == "DOVIWithSDR"sv) {
        e = (OAIVideoRangeType::DOVIWITHSDR);
    } 
    
    else if (s == "HDR10Plus"sv) {
        e = (OAIVideoRangeType::HDR10PLUS);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIVideoRangeType";
        throw std::invalid_argument(ss.str());
    } 
    
}




void to_json(json_t& j, const OAIVideoType& e) {
    switch (e)
    {
    
        case OAIVideoType::INVALID_VALUE_OPENAPI_GENERATED:
            j = "INVALID_VALUE_OPENAPI_GENERATED";
            break;
        case OAIVideoType::VIDEOFILE:
            j = "VideoFile";
            break;
    
        case OAIVideoType::ISO:
            j = "Iso";
            break;
    
        case OAIVideoType::DVD:
            j = "Dvd";
            break;
    
        case OAIVideoType::BLURAY:
            j = "BluRay";
            break;
    
    }
}
void from_json(const json_t& j, OAIVideoType& e) {
    auto s = j.get<std::string>();
    
    if (s == "VideoFile"sv) {
        e = (OAIVideoType::VIDEOFILE);
    } 
    
    else if (s == "Iso"sv) {
        e = (OAIVideoType::ISO);
    } 
    
    else if (s == "Dvd"sv) {
        e = (OAIVideoType::DVD);
    } 
    
    else if (s == "BluRay"sv) {
        e = (OAIVideoType::BLURAY);
    }  else {
        std::stringstream ss;
        ss << "Unexpected value " << s << " in json cannot be converted to enum of type"
           << " OAIVideoType";
        throw std::invalid_argument(ss.str());
    } 
    
}





void to_json(json_t& j, const OAIVirtualFolderInfo& o) {
        j["Name"sv] = o.Name;
        j["Locations"sv] = o.Locations;
        j["CollectionType"sv] = o.CollectionType;
        j["LibraryOptions"sv] = o.LibraryOptions;
        j["ItemId"sv] = o.ItemId;
        j["PrimaryImageItemId"sv] = o.PrimaryImageItemId;
        j["RefreshProgress"sv] = o.RefreshProgress;
        j["RefreshStatus"sv] = o.RefreshStatus;
}
void from_json(const json_t& j, OAIVirtualFolderInfo& o) {
    if(j.contains("Name"sv))
    j.at("Name"sv).get_to(o.Name);
    if(j.contains("Locations"sv))
    j.at("Locations"sv).get_to(o.Locations);
    if(j.contains("CollectionType"sv))
    j.at("CollectionType"sv).get_to(o.CollectionType);
    if(j.contains("LibraryOptions"sv))
    j.at("LibraryOptions"sv).get_to(o.LibraryOptions);
    if(j.contains("ItemId"sv))
    j.at("ItemId"sv).get_to(o.ItemId);
    if(j.contains("PrimaryImageItemId"sv))
    j.at("PrimaryImageItemId"sv).get_to(o.PrimaryImageItemId);
    if(j.contains("RefreshProgress"sv))
    j.at("RefreshProgress"sv).get_to(o.RefreshProgress);
    if(j.contains("RefreshStatus"sv))
    j.at("RefreshStatus"sv).get_to(o.RefreshStatus);
}




void to_json(json_t& j, const OAIWakeOnLanInfo& o) {
        j["MacAddress"sv] = o.MacAddress;
        j["Port"sv] = o.Port;
}
void from_json(const json_t& j, OAIWakeOnLanInfo& o) {
    if(j.contains("MacAddress"sv))
    j.at("MacAddress"sv).get_to(o.MacAddress);
    
    j.at("Port"sv).get_to(o.Port);
}


void to_json(json_t& j, const OAIWebSocketMessage& o) {
}
void from_json(const json_t& j, OAIWebSocketMessage& o) {
}





void to_json(json_t& j, const OAIXbmcMetadataOptions& o) {
        j["UserId"sv] = o.UserId;
        j["ReleaseDateFormat"sv] = o.ReleaseDateFormat;
        j["SaveImagePathsInNfo"sv] = o.SaveImagePathsInNfo;
        j["EnablePathSubstitution"sv] = o.EnablePathSubstitution;
        j["EnableExtraThumbsDuplication"sv] = o.EnableExtraThumbsDuplication;
}
void from_json(const json_t& j, OAIXbmcMetadataOptions& o) {
    if(j.contains("UserId"sv))
    j.at("UserId"sv).get_to(o.UserId);
    
    j.at("ReleaseDateFormat"sv).get_to(o.ReleaseDateFormat);
    
    j.at("SaveImagePathsInNfo"sv).get_to(o.SaveImagePathsInNfo);
    
    j.at("EnablePathSubstitution"sv).get_to(o.EnablePathSubstitution);
    
    j.at("EnableExtraThumbsDuplication"sv).get_to(o.EnableExtraThumbsDuplication);
}

}


IMPL_CONVERT(std::string, jellyfin::model::OAIAccessSchedule) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIActivityLogEntry) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIActivityLogEntryMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIActivityLogEntryQueryResult) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIActivityLogEntryStartMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIActivityLogEntryStopMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIAddVirtualFolderDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIAlbumInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIAlbumInfoRemoteSearchQuery) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIAllThemeMediaResult) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIArtistInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIArtistInfoRemoteSearchQuery) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIAuthenticateUserByName) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIAuthenticationInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIAuthenticationInfoQueryResult) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIAuthenticationResult) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIBaseItemDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIBaseItemDtoImageBlurHashes) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIBaseItemDtoQueryResult) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIBaseItemPerson) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIBaseItemPersonImageBlurHashes) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIBookInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIBookInfoRemoteSearchQuery) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIBoxSetInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIBoxSetInfoRemoteSearchQuery) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIBrandingOptions) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIBufferRequestDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAICastReceiverApplication) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIChannelFeatures) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIChannelMappingOptionsDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}




IMPL_CONVERT(std::string, jellyfin::model::OAIChapterInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIClientCapabilities) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIClientCapabilitiesDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIClientLogDocumentResponseDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAICodecProfile) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAICollectionCreationResult) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}



IMPL_CONVERT(std::string, jellyfin::model::OAIConfigImageTypes) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIConfigurationPageInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIContainerProfile) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAICountryInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAICreatePlaylistDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAICreateUserByName) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAICultureDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}



IMPL_CONVERT(std::string, jellyfin::model::OAIDefaultDirectoryBrowserInfoDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIDeviceInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIDeviceInfoQueryResult) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIDeviceOptions) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIDeviceOptionsDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIDeviceProfile) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIDirectPlayProfile) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIDisplayPreferencesDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}






IMPL_CONVERT(std::string, jellyfin::model::OAIEncodingOptions) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIEndPointInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIExternalIdInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIExternalUrl) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIFileSystemEntryInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIFontFile) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIForceKeepAliveMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIForgotPasswordDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIForgotPasswordPinDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIForgotPasswordResult) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIGeneralCommand) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIGeneralCommandMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIGetProgramsDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIGroupInfoDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIGroupInfoDtoGroupUpdate) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}





IMPL_CONVERT(std::string, jellyfin::model::OAIGroupStateUpdate) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIGroupStateUpdateGroupUpdate) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}



IMPL_CONVERT(std::string, jellyfin::model::OAIGuideInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIIPlugin) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIIgnoreWaitRequestDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIImageInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIImageOption) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIImageProviderInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}




IMPL_CONVERT(std::string, jellyfin::model::OAIInboundKeepAliveMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIInstallationInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIItemCounts) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}




IMPL_CONVERT(std::string, jellyfin::model::OAIJoinGroupRequestDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAILibraryChangedMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAILibraryOptionInfoDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAILibraryOptions) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAILibraryOptionsResultDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAILibraryTypeOptionsDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAILibraryUpdateInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIListingsProviderInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAILiveStreamResponse) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAILiveTvInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAILiveTvOptions) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAILiveTvServiceInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAILocalizationOption) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAILogFile) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAILyricDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAILyricLine) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAILyricMetadata) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIMediaAttachment) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIMediaPathDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIMediaPathInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIMediaSourceInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIMediaStream) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}




IMPL_CONVERT(std::string, jellyfin::model::OAIMediaUpdateInfoDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIMediaUpdateInfoPathDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIMediaUrl) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIMessageCommand) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIMetadataConfiguration) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIMetadataEditorInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIMetadataOptions) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIMovePlaylistItemRequestDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIMovieInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIMovieInfoRemoteSearchQuery) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIMusicVideoInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIMusicVideoInfoRemoteSearchQuery) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAINameGuidPair) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAINameIdPair) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAINameValuePair) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAINetworkConfiguration) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAINewGroupRequestDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAINextItemRequestDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIOpenLiveStreamDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIOutboundKeepAliveMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIPackageInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIParentalRating) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIPathSubstitution) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIPersonLookupInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIPersonLookupInfoRemoteSearchQuery) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIPinRedeemResult) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIPingRequestDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}



IMPL_CONVERT(std::string, jellyfin::model::OAIPlayMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIPlayQueueUpdate) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIPlayQueueUpdateGroupUpdate) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIPlayRequest) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIPlayRequestDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIPlaybackInfoDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIPlaybackInfoResponse) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIPlaybackProgressInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIPlaybackStartInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIPlaybackStopInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIPlayerStateInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIPlaylistCreationResult) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIPlaylistUserPermissions) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIPlaystateMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIPlaystateRequest) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIPluginInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIPluginInstallationCancelledMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIPluginInstallationCompletedMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIPluginInstallationFailedMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIPluginInstallingMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIPluginUninstalledMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIPreviousItemRequestDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}



IMPL_CONVERT(std::string, jellyfin::model::OAIProfileCondition) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}




IMPL_CONVERT(std::string, jellyfin::model::OAIPublicSystemInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIQueryFilters) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIQueryFiltersLegacy) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIQueueItem) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIQueueRequestDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIQuickConnectDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIQuickConnectResult) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIReadyRequestDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIRecommendationDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}



IMPL_CONVERT(std::string, jellyfin::model::OAIRefreshProgressMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIRemoteImageInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIRemoteImageResult) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIRemoteLyricInfoDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIRemoteSearchResult) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIRemoteSubtitleInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIRemoveFromPlaylistRequestDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIRepositoryInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIRestartRequiredMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIScheduledTaskEndedMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIScheduledTasksInfoMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIScheduledTasksInfoStartMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIScheduledTasksInfoStopMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAISearchHint) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISearchHintResult) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISeekRequestDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISendCommand) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAISeriesInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISeriesInfoRemoteSearchQuery) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAISeriesTimerCancelledMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISeriesTimerCreatedMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISeriesTimerInfoDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISeriesTimerInfoDtoQueryResult) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIServerConfiguration) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIServerDiscoveryInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIServerRestartingMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIServerShuttingDownMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISessionInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAISessionUserInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISessionsMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISessionsStartMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISessionsStopMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISetChannelMappingDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISetPlaylistItemRequestDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISetRepeatModeRequestDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISetShuffleModeRequestDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISongInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAISpecialViewOptionDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIStartupConfigurationDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIStartupRemoteAccessDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIStartupUserDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIStringGroupUpdate) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAISubtitleOptions) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAISubtitleProfile) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISyncPlayCommandMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISyncPlayGroupUpdateCommandMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAISyncPlayQueueItem) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAISystemInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAITaskInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAITaskResult) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAITaskTriggerInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIThemeMediaResult) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAITimerCancelledMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAITimerCreatedMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAITimerEventInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAITimerInfoDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAITimerInfoDtoQueryResult) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAITrailerInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAITrailerInfoRemoteSearchQuery) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}



IMPL_CONVERT(std::string, jellyfin::model::OAITranscodingInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAITranscodingProfile) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAITrickplayInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAITrickplayOptions) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAITunerChannelMapping) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAITunerHostInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAITypeOptions) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIUpdateLibraryOptionsDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIUpdateMediaPathRequestDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIUpdatePlaylistDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIUpdatePlaylistUserDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIUpdateUserItemDataDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIUpdateUserPassword) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIUploadSubtitleDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIUserConfiguration) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIUserDataChangeInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIUserDataChangedMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIUserDeletedMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIUserDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIUserItemDataDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIUserPolicy) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIUserUpdatedMessage) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIUtcTimeResponse) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIValidatePathDto) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIVersionInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}





IMPL_CONVERT(std::string, jellyfin::model::OAIVirtualFolderInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}

IMPL_CONVERT(std::string, jellyfin::model::OAIWakeOnLanInfo) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}


IMPL_CONVERT(std::string, jellyfin::model::OAIXbmcMetadataOptions) {
    jellyfin::json_t j;
    to_json(j, in);
    out = j.dump();
}
