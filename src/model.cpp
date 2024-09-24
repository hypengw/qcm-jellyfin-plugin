
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

OAIAccessSchedule::OAIAccessSchedule(): 
    Id(0), 
    UserId({}), 
    DayOfWeek((OAIDynamicDayOfWeek)0), 
    StartHour(0.0), 
    EndHour(0.0) {}
OAIAccessSchedule::~OAIAccessSchedule() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIActivityLogEntry::OAIActivityLogEntry(): 
    Id(0L), 
    Name({}), 
    Overview({}), 
    ShortOverview({}), 
    Type({}), 
    ItemId({}), 
    Date({}), 
    UserId({}), 
    UserPrimaryImageTag({}), 
    Severity((OAILogLevel)0) {}
OAIActivityLogEntry::~OAIActivityLogEntry() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIActivityLogEntryMessage::OAIActivityLogEntryMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIActivityLogEntryMessage::~OAIActivityLogEntryMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIActivityLogEntryQueryResult::OAIActivityLogEntryQueryResult(): 
    Items({}), 
    TotalRecordCount(0), 
    StartIndex(0) {}
OAIActivityLogEntryQueryResult::~OAIActivityLogEntryQueryResult() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIActivityLogEntryStartMessage::OAIActivityLogEntryStartMessage(): 
    Data({}), 
    MessageType((OAISessionMessageType)0) {}
OAIActivityLogEntryStartMessage::~OAIActivityLogEntryStartMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIActivityLogEntryStopMessage::OAIActivityLogEntryStopMessage(): 
    MessageType((OAISessionMessageType)0) {}
OAIActivityLogEntryStopMessage::~OAIActivityLogEntryStopMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIAddVirtualFolderDto::OAIAddVirtualFolderDto(): 
    LibraryOptions({}) {}
OAIAddVirtualFolderDto::~OAIAddVirtualFolderDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIAlbumInfo::OAIAlbumInfo(): 
    Name({}), 
    OriginalTitle({}), 
    Path({}), 
    MetadataLanguage({}), 
    MetadataCountryCode({}), 
    ProviderIds({}), 
    Year(0), 
    IndexNumber(0), 
    ParentIndexNumber(0), 
    PremiereDate({}), 
    IsAutomated(false), 
    AlbumArtists({}), 
    ArtistProviderIds({}), 
    SongInfos({}) {}
OAIAlbumInfo::~OAIAlbumInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIAlbumInfoRemoteSearchQuery::OAIAlbumInfoRemoteSearchQuery(): 
    SearchInfo({}), 
    ItemId({}), 
    SearchProviderName({}), 
    IncludeDisabledProviders(false) {}
OAIAlbumInfoRemoteSearchQuery::~OAIAlbumInfoRemoteSearchQuery() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIAllThemeMediaResult::OAIAllThemeMediaResult(): 
    ThemeVideosResult({}), 
    ThemeSongsResult({}), 
    SoundtrackSongsResult({}) {}
OAIAllThemeMediaResult::~OAIAllThemeMediaResult() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIArtistInfo::OAIArtistInfo(): 
    Name({}), 
    OriginalTitle({}), 
    Path({}), 
    MetadataLanguage({}), 
    MetadataCountryCode({}), 
    ProviderIds({}), 
    Year(0), 
    IndexNumber(0), 
    ParentIndexNumber(0), 
    PremiereDate({}), 
    IsAutomated(false), 
    SongInfos({}) {}
OAIArtistInfo::~OAIArtistInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIArtistInfoRemoteSearchQuery::OAIArtistInfoRemoteSearchQuery(): 
    SearchInfo({}), 
    ItemId({}), 
    SearchProviderName({}), 
    IncludeDisabledProviders(false) {}
OAIArtistInfoRemoteSearchQuery::~OAIArtistInfoRemoteSearchQuery() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIAudioSpatialFormat) {
    switch(in) {
        case in_type::NONE: out = "NONE"; break;
        case in_type::DOLBYATMOS: out = "DOLBYATMOS"; break;
        case in_type::DTSX: out = "DTSX"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIAuthenticateUserByName::OAIAuthenticateUserByName(): 
    Username({}), 
    Pw({}) {}
OAIAuthenticateUserByName::~OAIAuthenticateUserByName() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIAuthenticationInfo::OAIAuthenticationInfo(): 
    Id(0L), 
    AccessToken({}), 
    DeviceId({}), 
    AppName({}), 
    AppVersion({}), 
    DeviceName({}), 
    UserId({}), 
    IsActive(false), 
    DateCreated({}), 
    DateRevoked({}), 
    DateLastActivity({}), 
    UserName({}) {}
OAIAuthenticationInfo::~OAIAuthenticationInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIAuthenticationInfoQueryResult::OAIAuthenticationInfoQueryResult(): 
    Items({}), 
    TotalRecordCount(0), 
    StartIndex(0) {}
OAIAuthenticationInfoQueryResult::~OAIAuthenticationInfoQueryResult() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIAuthenticationResult::OAIAuthenticationResult(): 
    User({}), 
    SessionInfo({}), 
    AccessToken({}), 
    ServerId({}) {}
OAIAuthenticationResult::~OAIAuthenticationResult() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIBaseItemDto::OAIBaseItemDto(): 
    Name({}), 
    OriginalTitle({}), 
    ServerId({}), 
    Id({}), 
    Etag({}), 
    SourceType({}), 
    PlaylistItemId({}), 
    DateCreated({}), 
    DateLastMediaAdded({}), 
    ExtraType((OAIExtraType)0), 
    AirsBeforeSeasonNumber(0), 
    AirsAfterSeasonNumber(0), 
    AirsBeforeEpisodeNumber(0), 
    CanDelete(false), 
    CanDownload(false), 
    HasLyrics(false), 
    HasSubtitles(false), 
    PreferredMetadataLanguage({}), 
    PreferredMetadataCountryCode({}), 
    Container({}), 
    SortName({}), 
    ForcedSortName({}), 
    Video3DFormat((OAIVideo3DFormat)0), 
    PremiereDate({}), 
    ExternalUrls({}), 
    MediaSources({}), 
    CriticRating(0.0f), 
    ProductionLocations({}), 
    Path({}), 
    EnableMediaSourceDisplay(false), 
    OfficialRating({}), 
    CustomRating({}), 
    ChannelId({}), 
    ChannelName({}), 
    Overview({}), 
    Taglines({}), 
    Genres({}), 
    CommunityRating(0.0f), 
    CumulativeRunTimeTicks(0L), 
    RunTimeTicks(0L), 
    PlayAccess((OAIPlayAccess)0), 
    AspectRatio({}), 
    ProductionYear(0), 
    IsPlaceHolder(false), 
    Number({}), 
    ChannelNumber({}), 
    IndexNumber(0), 
    IndexNumberEnd(0), 
    ParentIndexNumber(0), 
    RemoteTrailers({}), 
    ProviderIds({}), 
    IsHD(false), 
    IsFolder(false), 
    ParentId({}), 
    Type((OAIBaseItemKind)0), 
    People({}), 
    Studios({}), 
    GenreItems({}), 
    ParentLogoItemId({}), 
    ParentBackdropItemId({}), 
    ParentBackdropImageTags({}), 
    LocalTrailerCount(0), 
    UserData({}), 
    RecursiveItemCount(0), 
    ChildCount(0), 
    SeriesName({}), 
    SeriesId({}), 
    SeasonId({}), 
    SpecialFeatureCount(0), 
    DisplayPreferencesId({}), 
    Status({}), 
    AirTime({}), 
    AirDays({}), 
    Tags({}), 
    PrimaryImageAspectRatio(0.0), 
    Artists({}), 
    ArtistItems({}), 
    Album({}), 
    CollectionType((OAICollectionType)0), 
    DisplayOrder({}), 
    AlbumId({}), 
    AlbumPrimaryImageTag({}), 
    SeriesPrimaryImageTag({}), 
    AlbumArtist({}), 
    AlbumArtists({}), 
    SeasonName({}), 
    MediaStreams({}), 
    VideoType((OAIVideoType)0), 
    PartCount(0), 
    MediaSourceCount(0), 
    ImageTags({}), 
    BackdropImageTags({}), 
    ScreenshotImageTags({}), 
    ParentLogoImageTag({}), 
    ParentArtItemId({}), 
    ParentArtImageTag({}), 
    SeriesThumbImageTag({}), 
    ImageBlurHashes(OAIBaseItemDtoImageBlurHashes()), 
    SeriesStudio({}), 
    ParentThumbItemId({}), 
    ParentThumbImageTag({}), 
    ParentPrimaryImageItemId({}), 
    ParentPrimaryImageTag({}), 
    Chapters({}), 
    Trickplay({}), 
    LocationType((OAILocationType)0), 
    IsoType((OAIIsoType)0), 
    MediaType((OAIMediaType)0), 
    EndDate({}), 
    LockedFields({}), 
    TrailerCount(0), 
    MovieCount(0), 
    SeriesCount(0), 
    ProgramCount(0), 
    EpisodeCount(0), 
    SongCount(0), 
    AlbumCount(0), 
    ArtistCount(0), 
    MusicVideoCount(0), 
    LockData(false), 
    Width(0), 
    Height(0), 
    CameraMake({}), 
    CameraModel({}), 
    Software({}), 
    ExposureTime(0.0), 
    FocalLength(0.0), 
    ImageOrientation((OAIImageOrientation)0), 
    Aperture(0.0), 
    ShutterSpeed(0.0), 
    Latitude(0.0), 
    Longitude(0.0), 
    Altitude(0.0), 
    IsoSpeedRating(0), 
    SeriesTimerId({}), 
    ProgramId({}), 
    ChannelPrimaryImageTag({}), 
    StartDate({}), 
    CompletionPercentage(0.0), 
    IsRepeat(false), 
    EpisodeTitle({}), 
    ChannelType((OAIChannelType)0), 
    Audio((OAIProgramAudio)0), 
    IsMovie(false), 
    IsSports(false), 
    IsSeries(false), 
    IsLive(false), 
    IsNews(false), 
    IsKids(false), 
    IsPremiere(false), 
    TimerId({}), 
    NormalizationGain(0.0f), 
    CurrentProgram(nullptr) {}
OAIBaseItemDto::~OAIBaseItemDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIBaseItemDtoImageBlurHashes::OAIBaseItemDtoImageBlurHashes(): 
    Primary({}), 
    Art({}), 
    Backdrop({}), 
    Banner({}), 
    Logo({}), 
    Thumb({}), 
    Disc({}), 
    Box({}), 
    Screenshot({}), 
    Menu({}), 
    Chapter({}), 
    BoxRear({}), 
    Profile({}) {}
OAIBaseItemDtoImageBlurHashes::~OAIBaseItemDtoImageBlurHashes() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIBaseItemDtoQueryResult::OAIBaseItemDtoQueryResult(): 
    Items({}), 
    TotalRecordCount(0), 
    StartIndex(0) {}
OAIBaseItemDtoQueryResult::~OAIBaseItemDtoQueryResult() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIBaseItemKind) {
    switch(in) {
        case in_type::AGGREGATEFOLDER: out = "AGGREGATEFOLDER"; break;
        case in_type::AUDIO: out = "AUDIO"; break;
        case in_type::AUDIOBOOK: out = "AUDIOBOOK"; break;
        case in_type::BASEPLUGINFOLDER: out = "BASEPLUGINFOLDER"; break;
        case in_type::BOOK: out = "BOOK"; break;
        case in_type::BOXSET: out = "BOXSET"; break;
        case in_type::CHANNEL: out = "CHANNEL"; break;
        case in_type::CHANNELFOLDERITEM: out = "CHANNELFOLDERITEM"; break;
        case in_type::COLLECTIONFOLDER: out = "COLLECTIONFOLDER"; break;
        case in_type::EPISODE: out = "EPISODE"; break;
        case in_type::FOLDER: out = "FOLDER"; break;
        case in_type::GENRE: out = "GENRE"; break;
        case in_type::MANUALPLAYLISTSFOLDER: out = "MANUALPLAYLISTSFOLDER"; break;
        case in_type::MOVIE: out = "MOVIE"; break;
        case in_type::LIVETVCHANNEL: out = "LIVETVCHANNEL"; break;
        case in_type::LIVETVPROGRAM: out = "LIVETVPROGRAM"; break;
        case in_type::MUSICALBUM: out = "MUSICALBUM"; break;
        case in_type::MUSICARTIST: out = "MUSICARTIST"; break;
        case in_type::MUSICGENRE: out = "MUSICGENRE"; break;
        case in_type::MUSICVIDEO: out = "MUSICVIDEO"; break;
        case in_type::PERSON: out = "PERSON"; break;
        case in_type::PHOTO: out = "PHOTO"; break;
        case in_type::PHOTOALBUM: out = "PHOTOALBUM"; break;
        case in_type::PLAYLIST: out = "PLAYLIST"; break;
        case in_type::PLAYLISTSFOLDER: out = "PLAYLISTSFOLDER"; break;
        case in_type::PROGRAM: out = "PROGRAM"; break;
        case in_type::RECORDING: out = "RECORDING"; break;
        case in_type::SEASON: out = "SEASON"; break;
        case in_type::SERIES: out = "SERIES"; break;
        case in_type::STUDIO: out = "STUDIO"; break;
        case in_type::TRAILER: out = "TRAILER"; break;
        case in_type::TVCHANNEL: out = "TVCHANNEL"; break;
        case in_type::TVPROGRAM: out = "TVPROGRAM"; break;
        case in_type::USERROOTFOLDER: out = "USERROOTFOLDER"; break;
        case in_type::USERVIEW: out = "USERVIEW"; break;
        case in_type::VIDEO: out = "VIDEO"; break;
        case in_type::YEAR: out = "YEAR"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIBaseItemPerson::OAIBaseItemPerson(): 
    Name({}), 
    Id({}), 
    Role({}), 
    Type((OAIPersonKind)0), 
    PrimaryImageTag({}), 
    ImageBlurHashes(OAIBaseItemPersonImageBlurHashes()) {}
OAIBaseItemPerson::~OAIBaseItemPerson() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIBaseItemPersonImageBlurHashes::OAIBaseItemPersonImageBlurHashes(): 
    Primary({}), 
    Art({}), 
    Backdrop({}), 
    Banner({}), 
    Logo({}), 
    Thumb({}), 
    Disc({}), 
    Box({}), 
    Screenshot({}), 
    Menu({}), 
    Chapter({}), 
    BoxRear({}), 
    Profile({}) {}
OAIBaseItemPersonImageBlurHashes::~OAIBaseItemPersonImageBlurHashes() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIBookInfo::OAIBookInfo(): 
    Name({}), 
    OriginalTitle({}), 
    Path({}), 
    MetadataLanguage({}), 
    MetadataCountryCode({}), 
    ProviderIds({}), 
    Year(0), 
    IndexNumber(0), 
    ParentIndexNumber(0), 
    PremiereDate({}), 
    IsAutomated(false), 
    SeriesName({}) {}
OAIBookInfo::~OAIBookInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIBookInfoRemoteSearchQuery::OAIBookInfoRemoteSearchQuery(): 
    SearchInfo({}), 
    ItemId({}), 
    SearchProviderName({}), 
    IncludeDisabledProviders(false) {}
OAIBookInfoRemoteSearchQuery::~OAIBookInfoRemoteSearchQuery() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIBoxSetInfo::OAIBoxSetInfo(): 
    Name({}), 
    OriginalTitle({}), 
    Path({}), 
    MetadataLanguage({}), 
    MetadataCountryCode({}), 
    ProviderIds({}), 
    Year(0), 
    IndexNumber(0), 
    ParentIndexNumber(0), 
    PremiereDate({}), 
    IsAutomated(false) {}
OAIBoxSetInfo::~OAIBoxSetInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIBoxSetInfoRemoteSearchQuery::OAIBoxSetInfoRemoteSearchQuery(): 
    SearchInfo({}), 
    ItemId({}), 
    SearchProviderName({}), 
    IncludeDisabledProviders(false) {}
OAIBoxSetInfoRemoteSearchQuery::~OAIBoxSetInfoRemoteSearchQuery() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIBrandingOptions::OAIBrandingOptions(): 
    LoginDisclaimer({}), 
    CustomCss({}), 
    SplashscreenEnabled(false) {}
OAIBrandingOptions::~OAIBrandingOptions() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIBufferRequestDto::OAIBufferRequestDto(): 
    When({}), 
    PositionTicks(0L), 
    IsPlaying(false), 
    PlaylistItemId({}) {}
OAIBufferRequestDto::~OAIBufferRequestDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAICastReceiverApplication::OAICastReceiverApplication(): 
    Id({}), 
    Name({}) {}
OAICastReceiverApplication::~OAICastReceiverApplication() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIChannelFeatures::OAIChannelFeatures(): 
    Name({}), 
    Id({}), 
    CanSearch(false), 
    MediaTypes({}), 
    ContentTypes({}), 
    MaxPageSize(0), 
    AutoRefreshLevels(0), 
    DefaultSortFields({}), 
    SupportsSortOrderToggle(false), 
    SupportsLatestMedia(false), 
    CanFilter(false), 
    SupportsContentDownloading(false) {}
OAIChannelFeatures::~OAIChannelFeatures() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIChannelItemSortField) {
    switch(in) {
        case in_type::NAME: out = "NAME"; break;
        case in_type::COMMUNITYRATING: out = "COMMUNITYRATING"; break;
        case in_type::PREMIEREDATE: out = "PREMIEREDATE"; break;
        case in_type::DATECREATED: out = "DATECREATED"; break;
        case in_type::RUNTIME: out = "RUNTIME"; break;
        case in_type::PLAYCOUNT: out = "PLAYCOUNT"; break;
        case in_type::COMMUNITYPLAYCOUNT: out = "COMMUNITYPLAYCOUNT"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIChannelMappingOptionsDto::OAIChannelMappingOptionsDto(): 
    TunerChannels({}), 
    ProviderChannels({}), 
    Mappings({}), 
    ProviderName({}) {}
OAIChannelMappingOptionsDto::~OAIChannelMappingOptionsDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIChannelMediaContentType) {
    switch(in) {
        case in_type::CLIP: out = "CLIP"; break;
        case in_type::PODCAST: out = "PODCAST"; break;
        case in_type::TRAILER: out = "TRAILER"; break;
        case in_type::MOVIE: out = "MOVIE"; break;
        case in_type::EPISODE: out = "EPISODE"; break;
        case in_type::SONG: out = "SONG"; break;
        case in_type::MOVIEEXTRA: out = "MOVIEEXTRA"; break;
        case in_type::TVEXTRA: out = "TVEXTRA"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIChannelMediaType) {
    switch(in) {
        case in_type::AUDIO: out = "AUDIO"; break;
        case in_type::VIDEO: out = "VIDEO"; break;
        case in_type::PHOTO: out = "PHOTO"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIChannelType) {
    switch(in) {
        case in_type::TV: out = "TV"; break;
        case in_type::RADIO: out = "RADIO"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIChapterInfo::OAIChapterInfo(): 
    StartPositionTicks(0L), 
    Name({}), 
    ImagePath({}), 
    ImageDateModified({}), 
    ImageTag({}) {}
OAIChapterInfo::~OAIChapterInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIClientCapabilities::OAIClientCapabilities(): 
    PlayableMediaTypes({}), 
    SupportedCommands({}), 
    SupportsMediaControl(false), 
    SupportsPersistentIdentifier(false), 
    DeviceProfile({}), 
    AppStoreUrl({}), 
    IconUrl({}), 
    SupportsContentUploading(false), 
    SupportsSync(false) {}
OAIClientCapabilities::~OAIClientCapabilities() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIClientCapabilitiesDto::OAIClientCapabilitiesDto(): 
    PlayableMediaTypes({}), 
    SupportedCommands({}), 
    SupportsMediaControl(false), 
    SupportsPersistentIdentifier(false), 
    DeviceProfile({}), 
    AppStoreUrl({}), 
    IconUrl({}), 
    SupportsContentUploading(false), 
    SupportsSync(false) {}
OAIClientCapabilitiesDto::~OAIClientCapabilitiesDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIClientLogDocumentResponseDto::OAIClientLogDocumentResponseDto(): 
    FileName({}) {}
OAIClientLogDocumentResponseDto::~OAIClientLogDocumentResponseDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAICodecProfile::OAICodecProfile(): 
    Type((OAICodecType)0), 
    Conditions({}), 
    ApplyConditions({}), 
    Codec({}), 
    Container({}) {}
OAICodecProfile::~OAICodecProfile() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAICodecType) {
    switch(in) {
        case in_type::VIDEO: out = "VIDEO"; break;
        case in_type::VIDEOAUDIO: out = "VIDEOAUDIO"; break;
        case in_type::AUDIO: out = "AUDIO"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAICollectionCreationResult::OAICollectionCreationResult(): 
    Id({}) {}
OAICollectionCreationResult::~OAICollectionCreationResult() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAICollectionType) {
    switch(in) {
        case in_type::UNKNOWN: out = "UNKNOWN"; break;
        case in_type::MOVIES: out = "MOVIES"; break;
        case in_type::TVSHOWS: out = "TVSHOWS"; break;
        case in_type::MUSIC: out = "MUSIC"; break;
        case in_type::MUSICVIDEOS: out = "MUSICVIDEOS"; break;
        case in_type::TRAILERS: out = "TRAILERS"; break;
        case in_type::HOMEVIDEOS: out = "HOMEVIDEOS"; break;
        case in_type::BOXSETS: out = "BOXSETS"; break;
        case in_type::BOOKS: out = "BOOKS"; break;
        case in_type::PHOTOS: out = "PHOTOS"; break;
        case in_type::LIVETV: out = "LIVETV"; break;
        case in_type::PLAYLISTS: out = "PLAYLISTS"; break;
        case in_type::FOLDERS: out = "FOLDERS"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAICollectionTypeOptions) {
    switch(in) {
        case in_type::MOVIES: out = "MOVIES"; break;
        case in_type::TVSHOWS: out = "TVSHOWS"; break;
        case in_type::MUSIC: out = "MUSIC"; break;
        case in_type::MUSICVIDEOS: out = "MUSICVIDEOS"; break;
        case in_type::HOMEVIDEOS: out = "HOMEVIDEOS"; break;
        case in_type::BOXSETS: out = "BOXSETS"; break;
        case in_type::BOOKS: out = "BOOKS"; break;
        case in_type::MIXED: out = "MIXED"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIConfigImageTypes::OAIConfigImageTypes(): 
    BackdropSizes({}), 
    BaseUrl({}), 
    LogoSizes({}), 
    PosterSizes({}), 
    ProfileSizes({}), 
    SecureBaseUrl({}), 
    StillSizes({}) {}
OAIConfigImageTypes::~OAIConfigImageTypes() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIConfigurationPageInfo::OAIConfigurationPageInfo(): 
    Name({}), 
    EnableInMainMenu(false), 
    MenuSection({}), 
    MenuIcon({}), 
    DisplayName({}), 
    PluginId({}) {}
OAIConfigurationPageInfo::~OAIConfigurationPageInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIContainerProfile::OAIContainerProfile(): 
    Type((OAIDlnaProfileType)0), 
    Conditions({}), 
    Container({}) {}
OAIContainerProfile::~OAIContainerProfile() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAICountryInfo::OAICountryInfo(): 
    Name({}), 
    DisplayName({}), 
    TwoLetterISORegionName({}), 
    ThreeLetterISORegionName({}) {}
OAICountryInfo::~OAICountryInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAICreatePlaylistDto::OAICreatePlaylistDto(): 
    Name({}), 
    Ids({}), 
    UserId({}), 
    MediaType((OAIMediaType)0), 
    Users({}), 
    IsPublic(false) {}
OAICreatePlaylistDto::~OAICreatePlaylistDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAICreateUserByName::OAICreateUserByName(): 
    Name({}), 
    Password({}) {}
OAICreateUserByName::~OAICreateUserByName() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAICultureDto::OAICultureDto(): 
    Name({}), 
    DisplayName({}), 
    TwoLetterISOLanguageName({}), 
    ThreeLetterISOLanguageName({}), 
    ThreeLetterISOLanguageNames({}) {}
OAICultureDto::~OAICultureDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIDayOfWeek) {
    switch(in) {
        case in_type::SUNDAY: out = "SUNDAY"; break;
        case in_type::MONDAY: out = "MONDAY"; break;
        case in_type::TUESDAY: out = "TUESDAY"; break;
        case in_type::WEDNESDAY: out = "WEDNESDAY"; break;
        case in_type::THURSDAY: out = "THURSDAY"; break;
        case in_type::FRIDAY: out = "FRIDAY"; break;
        case in_type::SATURDAY: out = "SATURDAY"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIDayPattern) {
    switch(in) {
        case in_type::DAILY: out = "DAILY"; break;
        case in_type::WEEKDAYS: out = "WEEKDAYS"; break;
        case in_type::WEEKENDS: out = "WEEKENDS"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIDefaultDirectoryBrowserInfoDto::OAIDefaultDirectoryBrowserInfoDto(): 
    Path({}) {}
OAIDefaultDirectoryBrowserInfoDto::~OAIDefaultDirectoryBrowserInfoDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIDeviceInfo::OAIDeviceInfo(): 
    Name({}), 
    CustomName({}), 
    AccessToken({}), 
    Id({}), 
    LastUserName({}), 
    AppName({}), 
    AppVersion({}), 
    LastUserId({}), 
    DateLastActivity({}), 
    Capabilities({}), 
    IconUrl({}) {}
OAIDeviceInfo::~OAIDeviceInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIDeviceInfoQueryResult::OAIDeviceInfoQueryResult(): 
    Items({}), 
    TotalRecordCount(0), 
    StartIndex(0) {}
OAIDeviceInfoQueryResult::~OAIDeviceInfoQueryResult() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIDeviceOptions::OAIDeviceOptions(): 
    Id(0), 
    DeviceId({}), 
    CustomName({}) {}
OAIDeviceOptions::~OAIDeviceOptions() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIDeviceOptionsDto::OAIDeviceOptionsDto(): 
    Id(0), 
    DeviceId({}), 
    CustomName({}) {}
OAIDeviceOptionsDto::~OAIDeviceOptionsDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIDeviceProfile::OAIDeviceProfile(): 
    Name({}), 
    Id({}), 
    MaxStreamingBitrate(0), 
    MaxStaticBitrate(0), 
    MusicStreamingTranscodingBitrate(0), 
    MaxStaticMusicBitrate(0), 
    DirectPlayProfiles({}), 
    TranscodingProfiles({}), 
    ContainerProfiles({}), 
    CodecProfiles({}), 
    SubtitleProfiles({}) {}
OAIDeviceProfile::~OAIDeviceProfile() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIDirectPlayProfile::OAIDirectPlayProfile(): 
    Container({}), 
    AudioCodec({}), 
    VideoCodec({}), 
    Type((OAIDlnaProfileType)0) {}
OAIDirectPlayProfile::~OAIDirectPlayProfile() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIDisplayPreferencesDto::OAIDisplayPreferencesDto(): 
    Id({}), 
    ViewType({}), 
    SortBy({}), 
    IndexBy({}), 
    RememberIndexing(false), 
    PrimaryImageHeight(0), 
    PrimaryImageWidth(0), 
    CustomPrefs({}), 
    ScrollDirection((OAIScrollDirection)0), 
    ShowBackdrop(false), 
    RememberSorting(false), 
    SortOrder((OAISortOrder)0), 
    ShowSidebar(false), 
    Client({}) {}
OAIDisplayPreferencesDto::~OAIDisplayPreferencesDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIDlnaProfileType) {
    switch(in) {
        case in_type::AUDIO: out = "AUDIO"; break;
        case in_type::VIDEO: out = "VIDEO"; break;
        case in_type::PHOTO: out = "PHOTO"; break;
        case in_type::SUBTITLE: out = "SUBTITLE"; break;
        case in_type::LYRIC: out = "LYRIC"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIDownMixStereoAlgorithms) {
    switch(in) {
        case in_type::NONE: out = "NONE"; break;
        case in_type::DAVE750: out = "DAVE750"; break;
        case in_type::NIGHTMODEDIALOGUE: out = "NIGHTMODEDIALOGUE"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIDynamicDayOfWeek) {
    switch(in) {
        case in_type::SUNDAY: out = "SUNDAY"; break;
        case in_type::MONDAY: out = "MONDAY"; break;
        case in_type::TUESDAY: out = "TUESDAY"; break;
        case in_type::WEDNESDAY: out = "WEDNESDAY"; break;
        case in_type::THURSDAY: out = "THURSDAY"; break;
        case in_type::FRIDAY: out = "FRIDAY"; break;
        case in_type::SATURDAY: out = "SATURDAY"; break;
        case in_type::EVERYDAY: out = "EVERYDAY"; break;
        case in_type::WEEKDAY: out = "WEEKDAY"; break;
        case in_type::WEEKEND: out = "WEEKEND"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIEmbeddedSubtitleOptions) {
    switch(in) {
        case in_type::ALLOWALL: out = "ALLOWALL"; break;
        case in_type::ALLOWTEXT: out = "ALLOWTEXT"; break;
        case in_type::ALLOWIMAGE: out = "ALLOWIMAGE"; break;
        case in_type::ALLOWNONE: out = "ALLOWNONE"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIEncodingContext) {
    switch(in) {
        case in_type::STREAMING: out = "STREAMING"; break;
        case in_type::STATIC: out = "STATIC"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIEncodingOptions::OAIEncodingOptions(): 
    EncodingThreadCount(0), 
    TranscodingTempPath({}), 
    FallbackFontPath({}), 
    EnableFallbackFont(false), 
    EnableAudioVbr(false), 
    DownMixAudioBoost(0.0), 
    DownMixStereoAlgorithm((OAIDownMixStereoAlgorithms)0), 
    MaxMuxingQueueSize(0), 
    EnableThrottling(false), 
    ThrottleDelaySeconds(0), 
    EnableSegmentDeletion(false), 
    SegmentKeepSeconds(0), 
    HardwareAccelerationType({}), 
    EncoderAppPath({}), 
    EncoderAppPathDisplay({}), 
    VaapiDevice({}), 
    EnableTonemapping(false), 
    EnableVppTonemapping(false), 
    EnableVideoToolboxTonemapping(false), 
    TonemappingAlgorithm({}), 
    TonemappingMode({}), 
    TonemappingRange({}), 
    TonemappingDesat(0.0), 
    TonemappingPeak(0.0), 
    TonemappingParam(0.0), 
    VppTonemappingBrightness(0.0), 
    VppTonemappingContrast(0.0), 
    H264Crf(0), 
    H265Crf(0), 
    EncoderPreset({}), 
    DeinterlaceDoubleRate(false), 
    DeinterlaceMethod({}), 
    EnableDecodingColorDepth10Hevc(false), 
    EnableDecodingColorDepth10Vp9(false), 
    EnableEnhancedNvdecDecoder(false), 
    PreferSystemNativeHwDecoder(false), 
    EnableIntelLowPowerH264HwEncoder(false), 
    EnableIntelLowPowerHevcHwEncoder(false), 
    EnableHardwareEncoding(false), 
    AllowHevcEncoding(false), 
    AllowAv1Encoding(false), 
    EnableSubtitleExtraction(false), 
    HardwareDecodingCodecs({}), 
    AllowOnDemandMetadataBasedKeyframeExtractionForExtensions({}) {}
OAIEncodingOptions::~OAIEncodingOptions() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIEndPointInfo::OAIEndPointInfo(): 
    IsLocal(false), 
    IsInNetwork(false) {}
OAIEndPointInfo::~OAIEndPointInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIExternalIdInfo::OAIExternalIdInfo(): 
    Name({}), 
    Key({}), 
    Type((OAIExternalIdMediaType)0), 
    UrlFormatString({}) {}
OAIExternalIdInfo::~OAIExternalIdInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIExternalIdMediaType) {
    switch(in) {
        case in_type::ALBUM: out = "ALBUM"; break;
        case in_type::ALBUMARTIST: out = "ALBUMARTIST"; break;
        case in_type::ARTIST: out = "ARTIST"; break;
        case in_type::BOXSET: out = "BOXSET"; break;
        case in_type::EPISODE: out = "EPISODE"; break;
        case in_type::MOVIE: out = "MOVIE"; break;
        case in_type::OTHERARTIST: out = "OTHERARTIST"; break;
        case in_type::PERSON: out = "PERSON"; break;
        case in_type::RELEASEGROUP: out = "RELEASEGROUP"; break;
        case in_type::SEASON: out = "SEASON"; break;
        case in_type::SERIES: out = "SERIES"; break;
        case in_type::TRACK: out = "TRACK"; break;
        case in_type::BOOK: out = "BOOK"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIExternalUrl::OAIExternalUrl(): 
    Name({}), 
    Url({}) {}
OAIExternalUrl::~OAIExternalUrl() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIExtraType) {
    switch(in) {
        case in_type::UNKNOWN: out = "UNKNOWN"; break;
        case in_type::CLIP: out = "CLIP"; break;
        case in_type::TRAILER: out = "TRAILER"; break;
        case in_type::BEHINDTHESCENES: out = "BEHINDTHESCENES"; break;
        case in_type::DELETEDSCENE: out = "DELETEDSCENE"; break;
        case in_type::INTERVIEW: out = "INTERVIEW"; break;
        case in_type::SCENE: out = "SCENE"; break;
        case in_type::SAMPLE: out = "SAMPLE"; break;
        case in_type::THEMESONG: out = "THEMESONG"; break;
        case in_type::THEMEVIDEO: out = "THEMEVIDEO"; break;
        case in_type::FEATURETTE: out = "FEATURETTE"; break;
        case in_type::SHORT: out = "SHORT"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIFileSystemEntryInfo::OAIFileSystemEntryInfo(): 
    Name({}), 
    Path({}), 
    Type((OAIFileSystemEntryType)0) {}
OAIFileSystemEntryInfo::~OAIFileSystemEntryInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIFileSystemEntryType) {
    switch(in) {
        case in_type::FILE: out = "FILE"; break;
        case in_type::DIRECTORY: out = "DIRECTORY"; break;
        case in_type::NETWORKCOMPUTER: out = "NETWORKCOMPUTER"; break;
        case in_type::NETWORKSHARE: out = "NETWORKSHARE"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIFontFile::OAIFontFile(): 
    Name({}), 
    Size(0L), 
    DateCreated({}), 
    DateModified({}) {}
OAIFontFile::~OAIFontFile() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIForceKeepAliveMessage::OAIForceKeepAliveMessage(): 
    Data(0), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIForceKeepAliveMessage::~OAIForceKeepAliveMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIForgotPasswordAction) {
    switch(in) {
        case in_type::CONTACTADMIN: out = "CONTACTADMIN"; break;
        case in_type::PINCODE: out = "PINCODE"; break;
        case in_type::INNETWORKREQUIRED: out = "INNETWORKREQUIRED"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIForgotPasswordDto::OAIForgotPasswordDto(): 
    EnteredUsername({}) {}
OAIForgotPasswordDto::~OAIForgotPasswordDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIForgotPasswordPinDto::OAIForgotPasswordPinDto(): 
    Pin({}) {}
OAIForgotPasswordPinDto::~OAIForgotPasswordPinDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIForgotPasswordResult::OAIForgotPasswordResult(): 
    Action((OAIForgotPasswordAction)0), 
    PinFile({}), 
    PinExpirationDate({}) {}
OAIForgotPasswordResult::~OAIForgotPasswordResult() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIGeneralCommand::OAIGeneralCommand(): 
    Name((OAIGeneralCommandType)0), 
    ControllingUserId({}), 
    Arguments({}) {}
OAIGeneralCommand::~OAIGeneralCommand() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIGeneralCommandMessage::OAIGeneralCommandMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIGeneralCommandMessage::~OAIGeneralCommandMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIGeneralCommandType) {
    switch(in) {
        case in_type::MOVEUP: out = "MOVEUP"; break;
        case in_type::MOVEDOWN: out = "MOVEDOWN"; break;
        case in_type::MOVELEFT: out = "MOVELEFT"; break;
        case in_type::MOVERIGHT: out = "MOVERIGHT"; break;
        case in_type::PAGEUP: out = "PAGEUP"; break;
        case in_type::PAGEDOWN: out = "PAGEDOWN"; break;
        case in_type::PREVIOUSLETTER: out = "PREVIOUSLETTER"; break;
        case in_type::NEXTLETTER: out = "NEXTLETTER"; break;
        case in_type::TOGGLEOSD: out = "TOGGLEOSD"; break;
        case in_type::TOGGLECONTEXTMENU: out = "TOGGLECONTEXTMENU"; break;
        case in_type::SELECT: out = "SELECT"; break;
        case in_type::BACK: out = "BACK"; break;
        case in_type::TAKESCREENSHOT: out = "TAKESCREENSHOT"; break;
        case in_type::SENDKEY: out = "SENDKEY"; break;
        case in_type::SENDSTRING: out = "SENDSTRING"; break;
        case in_type::GOHOME: out = "GOHOME"; break;
        case in_type::GOTOSETTINGS: out = "GOTOSETTINGS"; break;
        case in_type::VOLUMEUP: out = "VOLUMEUP"; break;
        case in_type::VOLUMEDOWN: out = "VOLUMEDOWN"; break;
        case in_type::MUTE: out = "MUTE"; break;
        case in_type::UNMUTE: out = "UNMUTE"; break;
        case in_type::TOGGLEMUTE: out = "TOGGLEMUTE"; break;
        case in_type::SETVOLUME: out = "SETVOLUME"; break;
        case in_type::SETAUDIOSTREAMINDEX: out = "SETAUDIOSTREAMINDEX"; break;
        case in_type::SETSUBTITLESTREAMINDEX: out = "SETSUBTITLESTREAMINDEX"; break;
        case in_type::TOGGLEFULLSCREEN: out = "TOGGLEFULLSCREEN"; break;
        case in_type::DISPLAYCONTENT: out = "DISPLAYCONTENT"; break;
        case in_type::GOTOSEARCH: out = "GOTOSEARCH"; break;
        case in_type::DISPLAYMESSAGE: out = "DISPLAYMESSAGE"; break;
        case in_type::SETREPEATMODE: out = "SETREPEATMODE"; break;
        case in_type::CHANNELUP: out = "CHANNELUP"; break;
        case in_type::CHANNELDOWN: out = "CHANNELDOWN"; break;
        case in_type::GUIDE: out = "GUIDE"; break;
        case in_type::TOGGLESTATS: out = "TOGGLESTATS"; break;
        case in_type::PLAYMEDIASOURCE: out = "PLAYMEDIASOURCE"; break;
        case in_type::PLAYTRAILERS: out = "PLAYTRAILERS"; break;
        case in_type::SETSHUFFLEQUEUE: out = "SETSHUFFLEQUEUE"; break;
        case in_type::PLAYSTATE: out = "PLAYSTATE"; break;
        case in_type::PLAYNEXT: out = "PLAYNEXT"; break;
        case in_type::TOGGLEOSDMENU: out = "TOGGLEOSDMENU"; break;
        case in_type::PLAY: out = "PLAY"; break;
        case in_type::SETMAXSTREAMINGBITRATE: out = "SETMAXSTREAMINGBITRATE"; break;
        case in_type::SETPLAYBACKORDER: out = "SETPLAYBACKORDER"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIGetProgramsDto::OAIGetProgramsDto(): 
    ChannelIds({}), 
    UserId({}), 
    MinStartDate({}), 
    HasAired(false), 
    IsAiring(false), 
    MaxStartDate({}), 
    MinEndDate({}), 
    MaxEndDate({}), 
    IsMovie(false), 
    IsSeries(false), 
    IsNews(false), 
    IsKids(false), 
    IsSports(false), 
    StartIndex(0), 
    Limit(0), 
    SortBy({}), 
    SortOrder({}), 
    Genres({}), 
    GenreIds({}), 
    EnableImages(false), 
    EnableTotalRecordCount(false), 
    ImageTypeLimit(0), 
    EnableImageTypes({}), 
    EnableUserData(false), 
    SeriesTimerId({}), 
    LibrarySeriesId({}), 
    Fields({}) {}
OAIGetProgramsDto::~OAIGetProgramsDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIGroupInfoDto::OAIGroupInfoDto(): 
    GroupId({}), 
    GroupName({}), 
    State((OAIGroupStateType)0), 
    Participants({}), 
    LastUpdatedAt({}) {}
OAIGroupInfoDto::~OAIGroupInfoDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIGroupInfoDtoGroupUpdate::OAIGroupInfoDtoGroupUpdate(): 
    GroupId({}), 
    Type((OAIGroupUpdateType)0), 
    Data({}) {}
OAIGroupInfoDtoGroupUpdate::~OAIGroupInfoDtoGroupUpdate() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIGroupQueueMode) {
    switch(in) {
        case in_type::QUEUE: out = "QUEUE"; break;
        case in_type::QUEUENEXT: out = "QUEUENEXT"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIGroupRepeatMode) {
    switch(in) {
        case in_type::REPEATONE: out = "REPEATONE"; break;
        case in_type::REPEATALL: out = "REPEATALL"; break;
        case in_type::REPEATNONE: out = "REPEATNONE"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIGroupShuffleMode) {
    switch(in) {
        case in_type::SORTED: out = "SORTED"; break;
        case in_type::SHUFFLE: out = "SHUFFLE"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIGroupStateType) {
    switch(in) {
        case in_type::IDLE: out = "IDLE"; break;
        case in_type::WAITING: out = "WAITING"; break;
        case in_type::PAUSED: out = "PAUSED"; break;
        case in_type::PLAYING: out = "PLAYING"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIGroupStateUpdate::OAIGroupStateUpdate(): 
    State((OAIGroupStateType)0), 
    Reason((OAIPlaybackRequestType)0) {}
OAIGroupStateUpdate::~OAIGroupStateUpdate() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIGroupStateUpdateGroupUpdate::OAIGroupStateUpdateGroupUpdate(): 
    GroupId({}), 
    Type((OAIGroupUpdateType)0), 
    Data({}) {}
OAIGroupStateUpdateGroupUpdate::~OAIGroupStateUpdateGroupUpdate() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIGroupUpdateType) {
    switch(in) {
        case in_type::USERJOINED: out = "USERJOINED"; break;
        case in_type::USERLEFT: out = "USERLEFT"; break;
        case in_type::GROUPJOINED: out = "GROUPJOINED"; break;
        case in_type::GROUPLEFT: out = "GROUPLEFT"; break;
        case in_type::STATEUPDATE: out = "STATEUPDATE"; break;
        case in_type::PLAYQUEUE: out = "PLAYQUEUE"; break;
        case in_type::NOTINGROUP: out = "NOTINGROUP"; break;
        case in_type::GROUPDOESNOTEXIST: out = "GROUPDOESNOTEXIST"; break;
        case in_type::CREATEGROUPDENIED: out = "CREATEGROUPDENIED"; break;
        case in_type::JOINGROUPDENIED: out = "JOINGROUPDENIED"; break;
        case in_type::LIBRARYACCESSDENIED: out = "LIBRARYACCESSDENIED"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIGuideInfo::OAIGuideInfo(): 
    StartDate({}), 
    EndDate({}) {}
OAIGuideInfo::~OAIGuideInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIHardwareEncodingType) {
    switch(in) {
        case in_type::AMF: out = "AMF"; break;
        case in_type::QSV: out = "QSV"; break;
        case in_type::NVENC: out = "NVENC"; break;
        case in_type::V4L2M2M: out = "V4L2M2M"; break;
        case in_type::VAAPI: out = "VAAPI"; break;
        case in_type::VIDEOTOOLBOX: out = "VIDEOTOOLBOX"; break;
        case in_type::RKMPP: out = "RKMPP"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIIPlugin::OAIIPlugin(): 
    Name({}), 
    Description({}), 
    Id({}), 
    Version({}), 
    AssemblyFilePath({}), 
    CanUninstall(false), 
    DataFolderPath({}) {}
OAIIPlugin::~OAIIPlugin() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIIgnoreWaitRequestDto::OAIIgnoreWaitRequestDto(): 
    IgnoreWait(false) {}
OAIIgnoreWaitRequestDto::~OAIIgnoreWaitRequestDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIImageFormat) {
    switch(in) {
        case in_type::BMP: out = "BMP"; break;
        case in_type::GIF: out = "GIF"; break;
        case in_type::JPG: out = "JPG"; break;
        case in_type::PNG: out = "PNG"; break;
        case in_type::WEBP: out = "WEBP"; break;
        case in_type::SVG: out = "SVG"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIImageInfo::OAIImageInfo(): 
    ImageType((OAIImageType)0), 
    ImageIndex(0), 
    ImageTag({}), 
    Path({}), 
    BlurHash({}), 
    Height(0), 
    Width(0), 
    Size(0L) {}
OAIImageInfo::~OAIImageInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIImageOption::OAIImageOption(): 
    Type((OAIImageType)0), 
    Limit(0), 
    MinWidth(0) {}
OAIImageOption::~OAIImageOption() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIImageOrientation) {
    switch(in) {
        case in_type::TOPLEFT: out = "TOPLEFT"; break;
        case in_type::TOPRIGHT: out = "TOPRIGHT"; break;
        case in_type::BOTTOMRIGHT: out = "BOTTOMRIGHT"; break;
        case in_type::BOTTOMLEFT: out = "BOTTOMLEFT"; break;
        case in_type::LEFTTOP: out = "LEFTTOP"; break;
        case in_type::RIGHTTOP: out = "RIGHTTOP"; break;
        case in_type::RIGHTBOTTOM: out = "RIGHTBOTTOM"; break;
        case in_type::LEFTBOTTOM: out = "LEFTBOTTOM"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIImageProviderInfo::OAIImageProviderInfo(): 
    Name({}), 
    SupportedImages({}) {}
OAIImageProviderInfo::~OAIImageProviderInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIImageResolution) {
    switch(in) {
        case in_type::MATCHSOURCE: out = "MATCHSOURCE"; break;
        case in_type::P144: out = "P144"; break;
        case in_type::P240: out = "P240"; break;
        case in_type::P360: out = "P360"; break;
        case in_type::P480: out = "P480"; break;
        case in_type::P720: out = "P720"; break;
        case in_type::P1080: out = "P1080"; break;
        case in_type::P1440: out = "P1440"; break;
        case in_type::P2160: out = "P2160"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIImageSavingConvention) {
    switch(in) {
        case in_type::LEGACY: out = "LEGACY"; break;
        case in_type::COMPATIBLE: out = "COMPATIBLE"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIImageType) {
    switch(in) {
        case in_type::PRIMARY: out = "PRIMARY"; break;
        case in_type::ART: out = "ART"; break;
        case in_type::BACKDROP: out = "BACKDROP"; break;
        case in_type::BANNER: out = "BANNER"; break;
        case in_type::LOGO: out = "LOGO"; break;
        case in_type::THUMB: out = "THUMB"; break;
        case in_type::DISC: out = "DISC"; break;
        case in_type::BOX: out = "BOX"; break;
        case in_type::SCREENSHOT: out = "SCREENSHOT"; break;
        case in_type::MENU: out = "MENU"; break;
        case in_type::CHAPTER: out = "CHAPTER"; break;
        case in_type::BOXREAR: out = "BOXREAR"; break;
        case in_type::PROFILE: out = "PROFILE"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIInboundKeepAliveMessage::OAIInboundKeepAliveMessage(): 
    MessageType((OAISessionMessageType)0) {}
OAIInboundKeepAliveMessage::~OAIInboundKeepAliveMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

} // namespace jellyfin::model



namespace jellyfin::model {

OAIInstallationInfo::OAIInstallationInfo(): 
    Guid({}), 
    Name({}), 
    Version({}), 
    Changelog({}), 
    SourceUrl({}), 
    Checksum({}), 
    PackageInfo({}) {}
OAIInstallationInfo::~OAIInstallationInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIIsoType) {
    switch(in) {
        case in_type::DVD: out = "DVD"; break;
        case in_type::BLURAY: out = "BLURAY"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIItemCounts::OAIItemCounts(): 
    MovieCount(0), 
    SeriesCount(0), 
    EpisodeCount(0), 
    ArtistCount(0), 
    ProgramCount(0), 
    TrailerCount(0), 
    SongCount(0), 
    AlbumCount(0), 
    MusicVideoCount(0), 
    BoxSetCount(0), 
    BookCount(0), 
    ItemCount(0) {}
OAIItemCounts::~OAIItemCounts() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIItemFields) {
    switch(in) {
        case in_type::AIRTIME: out = "AIRTIME"; break;
        case in_type::CANDELETE: out = "CANDELETE"; break;
        case in_type::CANDOWNLOAD: out = "CANDOWNLOAD"; break;
        case in_type::CHANNELINFO: out = "CHANNELINFO"; break;
        case in_type::CHAPTERS: out = "CHAPTERS"; break;
        case in_type::TRICKPLAY: out = "TRICKPLAY"; break;
        case in_type::CHILDCOUNT: out = "CHILDCOUNT"; break;
        case in_type::CUMULATIVERUNTIMETICKS: out = "CUMULATIVERUNTIMETICKS"; break;
        case in_type::CUSTOMRATING: out = "CUSTOMRATING"; break;
        case in_type::DATECREATED: out = "DATECREATED"; break;
        case in_type::DATELASTMEDIAADDED: out = "DATELASTMEDIAADDED"; break;
        case in_type::DISPLAYPREFERENCESID: out = "DISPLAYPREFERENCESID"; break;
        case in_type::ETAG: out = "ETAG"; break;
        case in_type::EXTERNALURLS: out = "EXTERNALURLS"; break;
        case in_type::GENRES: out = "GENRES"; break;
        case in_type::HOMEPAGEURL: out = "HOMEPAGEURL"; break;
        case in_type::ITEMCOUNTS: out = "ITEMCOUNTS"; break;
        case in_type::MEDIASOURCECOUNT: out = "MEDIASOURCECOUNT"; break;
        case in_type::MEDIASOURCES: out = "MEDIASOURCES"; break;
        case in_type::ORIGINALTITLE: out = "ORIGINALTITLE"; break;
        case in_type::OVERVIEW: out = "OVERVIEW"; break;
        case in_type::PARENTID: out = "PARENTID"; break;
        case in_type::PATH: out = "PATH"; break;
        case in_type::PEOPLE: out = "PEOPLE"; break;
        case in_type::PLAYACCESS: out = "PLAYACCESS"; break;
        case in_type::PRODUCTIONLOCATIONS: out = "PRODUCTIONLOCATIONS"; break;
        case in_type::PROVIDERIDS: out = "PROVIDERIDS"; break;
        case in_type::PRIMARYIMAGEASPECTRATIO: out = "PRIMARYIMAGEASPECTRATIO"; break;
        case in_type::RECURSIVEITEMCOUNT: out = "RECURSIVEITEMCOUNT"; break;
        case in_type::SETTINGS: out = "SETTINGS"; break;
        case in_type::SCREENSHOTIMAGETAGS: out = "SCREENSHOTIMAGETAGS"; break;
        case in_type::SERIESPRIMARYIMAGE: out = "SERIESPRIMARYIMAGE"; break;
        case in_type::SERIESSTUDIO: out = "SERIESSTUDIO"; break;
        case in_type::SORTNAME: out = "SORTNAME"; break;
        case in_type::SPECIALEPISODENUMBERS: out = "SPECIALEPISODENUMBERS"; break;
        case in_type::STUDIOS: out = "STUDIOS"; break;
        case in_type::TAGLINES: out = "TAGLINES"; break;
        case in_type::TAGS: out = "TAGS"; break;
        case in_type::REMOTETRAILERS: out = "REMOTETRAILERS"; break;
        case in_type::MEDIASTREAMS: out = "MEDIASTREAMS"; break;
        case in_type::SEASONUSERDATA: out = "SEASONUSERDATA"; break;
        case in_type::SERVICENAME: out = "SERVICENAME"; break;
        case in_type::THEMESONGIDS: out = "THEMESONGIDS"; break;
        case in_type::THEMEVIDEOIDS: out = "THEMEVIDEOIDS"; break;
        case in_type::EXTERNALETAG: out = "EXTERNALETAG"; break;
        case in_type::PRESENTATIONUNIQUEKEY: out = "PRESENTATIONUNIQUEKEY"; break;
        case in_type::INHERITEDPARENTALRATINGVALUE: out = "INHERITEDPARENTALRATINGVALUE"; break;
        case in_type::EXTERNALSERIESID: out = "EXTERNALSERIESID"; break;
        case in_type::SERIESPRESENTATIONUNIQUEKEY: out = "SERIESPRESENTATIONUNIQUEKEY"; break;
        case in_type::DATELASTREFRESHED: out = "DATELASTREFRESHED"; break;
        case in_type::DATELASTSAVED: out = "DATELASTSAVED"; break;
        case in_type::REFRESHSTATE: out = "REFRESHSTATE"; break;
        case in_type::CHANNELIMAGE: out = "CHANNELIMAGE"; break;
        case in_type::ENABLEMEDIASOURCEDISPLAY: out = "ENABLEMEDIASOURCEDISPLAY"; break;
        case in_type::WIDTH: out = "WIDTH"; break;
        case in_type::HEIGHT: out = "HEIGHT"; break;
        case in_type::EXTRAIDS: out = "EXTRAIDS"; break;
        case in_type::LOCALTRAILERCOUNT: out = "LOCALTRAILERCOUNT"; break;
        case in_type::ISHD: out = "ISHD"; break;
        case in_type::SPECIALFEATURECOUNT: out = "SPECIALFEATURECOUNT"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIItemFilter) {
    switch(in) {
        case in_type::ISFOLDER: out = "ISFOLDER"; break;
        case in_type::ISNOTFOLDER: out = "ISNOTFOLDER"; break;
        case in_type::ISUNPLAYED: out = "ISUNPLAYED"; break;
        case in_type::ISPLAYED: out = "ISPLAYED"; break;
        case in_type::ISFAVORITE: out = "ISFAVORITE"; break;
        case in_type::ISRESUMABLE: out = "ISRESUMABLE"; break;
        case in_type::LIKES: out = "LIKES"; break;
        case in_type::DISLIKES: out = "DISLIKES"; break;
        case in_type::ISFAVORITEORLIKES: out = "ISFAVORITEORLIKES"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIItemSortBy) {
    switch(in) {
        case in_type::DEFAULT: out = "DEFAULT"; break;
        case in_type::AIREDEPISODEORDER: out = "AIREDEPISODEORDER"; break;
        case in_type::ALBUM: out = "ALBUM"; break;
        case in_type::ALBUMARTIST: out = "ALBUMARTIST"; break;
        case in_type::ARTIST: out = "ARTIST"; break;
        case in_type::DATECREATED: out = "DATECREATED"; break;
        case in_type::OFFICIALRATING: out = "OFFICIALRATING"; break;
        case in_type::DATEPLAYED: out = "DATEPLAYED"; break;
        case in_type::PREMIEREDATE: out = "PREMIEREDATE"; break;
        case in_type::STARTDATE: out = "STARTDATE"; break;
        case in_type::SORTNAME: out = "SORTNAME"; break;
        case in_type::NAME: out = "NAME"; break;
        case in_type::RANDOM: out = "RANDOM"; break;
        case in_type::RUNTIME: out = "RUNTIME"; break;
        case in_type::COMMUNITYRATING: out = "COMMUNITYRATING"; break;
        case in_type::PRODUCTIONYEAR: out = "PRODUCTIONYEAR"; break;
        case in_type::PLAYCOUNT: out = "PLAYCOUNT"; break;
        case in_type::CRITICRATING: out = "CRITICRATING"; break;
        case in_type::ISFOLDER: out = "ISFOLDER"; break;
        case in_type::ISUNPLAYED: out = "ISUNPLAYED"; break;
        case in_type::ISPLAYED: out = "ISPLAYED"; break;
        case in_type::SERIESSORTNAME: out = "SERIESSORTNAME"; break;
        case in_type::VIDEOBITRATE: out = "VIDEOBITRATE"; break;
        case in_type::AIRTIME: out = "AIRTIME"; break;
        case in_type::STUDIO: out = "STUDIO"; break;
        case in_type::ISFAVORITEORLIKED: out = "ISFAVORITEORLIKED"; break;
        case in_type::DATELASTCONTENTADDED: out = "DATELASTCONTENTADDED"; break;
        case in_type::SERIESDATEPLAYED: out = "SERIESDATEPLAYED"; break;
        case in_type::PARENTINDEXNUMBER: out = "PARENTINDEXNUMBER"; break;
        case in_type::INDEXNUMBER: out = "INDEXNUMBER"; break;
        case in_type::SIMILARITYSCORE: out = "SIMILARITYSCORE"; break;
        case in_type::SEARCHSCORE: out = "SEARCHSCORE"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIJoinGroupRequestDto::OAIJoinGroupRequestDto(): 
    GroupId({}) {}
OAIJoinGroupRequestDto::~OAIJoinGroupRequestDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIKeepUntil) {
    switch(in) {
        case in_type::UNTILDELETED: out = "UNTILDELETED"; break;
        case in_type::UNTILSPACENEEDED: out = "UNTILSPACENEEDED"; break;
        case in_type::UNTILWATCHED: out = "UNTILWATCHED"; break;
        case in_type::UNTILDATE: out = "UNTILDATE"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAILibraryChangedMessage::OAILibraryChangedMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAILibraryChangedMessage::~OAILibraryChangedMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAILibraryOptionInfoDto::OAILibraryOptionInfoDto(): 
    Name({}), 
    DefaultEnabled(false) {}
OAILibraryOptionInfoDto::~OAILibraryOptionInfoDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAILibraryOptions::OAILibraryOptions(): 
    Enabled(false), 
    EnablePhotos(false), 
    EnableRealtimeMonitor(false), 
    EnableLUFSScan(false), 
    EnableChapterImageExtraction(false), 
    ExtractChapterImagesDuringLibraryScan(false), 
    EnableTrickplayImageExtraction(false), 
    ExtractTrickplayImagesDuringLibraryScan(false), 
    PathInfos({}), 
    SaveLocalMetadata(false), 
    EnableInternetProviders(false), 
    EnableAutomaticSeriesGrouping(false), 
    EnableEmbeddedTitles(false), 
    EnableEmbeddedExtrasTitles(false), 
    EnableEmbeddedEpisodeInfos(false), 
    AutomaticRefreshIntervalDays(0), 
    PreferredMetadataLanguage({}), 
    MetadataCountryCode({}), 
    SeasonZeroDisplayName({}), 
    MetadataSavers({}), 
    DisabledLocalMetadataReaders({}), 
    LocalMetadataReaderOrder({}), 
    DisabledSubtitleFetchers({}), 
    SubtitleFetcherOrder({}), 
    SkipSubtitlesIfEmbeddedSubtitlesPresent(false), 
    SkipSubtitlesIfAudioTrackMatches(false), 
    SubtitleDownloadLanguages({}), 
    RequirePerfectSubtitleMatch(false), 
    SaveSubtitlesWithMedia(false), 
    SaveLyricsWithMedia(false), 
    AutomaticallyAddToCollection(false), 
    AllowEmbeddedSubtitles((OAIEmbeddedSubtitleOptions)0), 
    TypeOptions({}) {}
OAILibraryOptions::~OAILibraryOptions() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAILibraryOptionsResultDto::OAILibraryOptionsResultDto(): 
    MetadataSavers({}), 
    MetadataReaders({}), 
    SubtitleFetchers({}), 
    TypeOptions({}) {}
OAILibraryOptionsResultDto::~OAILibraryOptionsResultDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAILibraryTypeOptionsDto::OAILibraryTypeOptionsDto(): 
    Type({}), 
    MetadataFetchers({}), 
    ImageFetchers({}), 
    SupportedImageTypes({}), 
    DefaultImageOptions({}) {}
OAILibraryTypeOptionsDto::~OAILibraryTypeOptionsDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAILibraryUpdateInfo::OAILibraryUpdateInfo(): 
    FoldersAddedTo({}), 
    FoldersRemovedFrom({}), 
    ItemsAdded({}), 
    ItemsRemoved({}), 
    ItemsUpdated({}), 
    CollectionFolders({}), 
    IsEmpty(false) {}
OAILibraryUpdateInfo::~OAILibraryUpdateInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIListingsProviderInfo::OAIListingsProviderInfo(): 
    Id({}), 
    Type({}), 
    Username({}), 
    Password({}), 
    ListingsId({}), 
    ZipCode({}), 
    Country({}), 
    Path({}), 
    EnabledTuners({}), 
    EnableAllTuners(false), 
    NewsCategories({}), 
    SportsCategories({}), 
    KidsCategories({}), 
    MovieCategories({}), 
    ChannelMappings({}), 
    MoviePrefix({}), 
    PreferredLanguage({}), 
    UserAgent({}) {}
OAIListingsProviderInfo::~OAIListingsProviderInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAILiveStreamResponse::OAILiveStreamResponse(): 
    MediaSource({}) {}
OAILiveStreamResponse::~OAILiveStreamResponse() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAILiveTvInfo::OAILiveTvInfo(): 
    Services({}), 
    IsEnabled(false), 
    EnabledUsers({}) {}
OAILiveTvInfo::~OAILiveTvInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAILiveTvOptions::OAILiveTvOptions(): 
    GuideDays(0), 
    RecordingPath({}), 
    MovieRecordingPath({}), 
    SeriesRecordingPath({}), 
    EnableRecordingSubfolders(false), 
    EnableOriginalAudioWithEncodedRecordings(false), 
    TunerHosts({}), 
    ListingProviders({}), 
    PrePaddingSeconds(0), 
    PostPaddingSeconds(0), 
    MediaLocationsCreated({}), 
    RecordingPostProcessor({}), 
    RecordingPostProcessorArguments({}), 
    SaveRecordingNFO(false), 
    SaveRecordingImages(false) {}
OAILiveTvOptions::~OAILiveTvOptions() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAILiveTvServiceInfo::OAILiveTvServiceInfo(): 
    Name({}), 
    HomePageUrl({}), 
    Status((OAILiveTvServiceStatus)0), 
    StatusMessage({}), 
    Version({}), 
    HasUpdateAvailable(false), 
    IsVisible(false), 
    Tuners({}) {}
OAILiveTvServiceInfo::~OAILiveTvServiceInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAILiveTvServiceStatus) {
    switch(in) {
        case in_type::OK: out = "OK"; break;
        case in_type::UNAVAILABLE: out = "UNAVAILABLE"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAILocalizationOption::OAILocalizationOption(): 
    Name({}), 
    Value({}) {}
OAILocalizationOption::~OAILocalizationOption() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAILocationType) {
    switch(in) {
        case in_type::FILESYSTEM: out = "FILESYSTEM"; break;
        case in_type::REMOTE: out = "REMOTE"; break;
        case in_type::VIRTUAL: out = "VIRTUAL"; break;
        case in_type::OFFLINE: out = "OFFLINE"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAILogFile::OAILogFile(): 
    DateCreated({}), 
    DateModified({}), 
    Size(0L), 
    Name({}) {}
OAILogFile::~OAILogFile() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAILogLevel) {
    switch(in) {
        case in_type::TRACE: out = "TRACE"; break;
        case in_type::DEBUG: out = "DEBUG"; break;
        case in_type::INFORMATION: out = "INFORMATION"; break;
        case in_type::WARNING: out = "WARNING"; break;
        case in_type::ERROR: out = "ERROR"; break;
        case in_type::CRITICAL: out = "CRITICAL"; break;
        case in_type::NONE: out = "NONE"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAILyricDto::OAILyricDto(): 
    Metadata({}), 
    Lyrics({}) {}
OAILyricDto::~OAILyricDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAILyricLine::OAILyricLine(): 
    Text({}), 
    Start(0L) {}
OAILyricLine::~OAILyricLine() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAILyricMetadata::OAILyricMetadata(): 
    Artist({}), 
    Album({}), 
    Title({}), 
    Author({}), 
    Length(0L), 
    By({}), 
    Offset(0L), 
    Creator({}), 
    Version({}), 
    IsSynced(false) {}
OAILyricMetadata::~OAILyricMetadata() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIMediaAttachment::OAIMediaAttachment(): 
    Codec({}), 
    CodecTag({}), 
    Comment({}), 
    Index(0), 
    FileName({}), 
    MimeType({}), 
    DeliveryUrl({}) {}
OAIMediaAttachment::~OAIMediaAttachment() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIMediaPathDto::OAIMediaPathDto(): 
    Name({}), 
    Path({}), 
    PathInfo({}) {}
OAIMediaPathDto::~OAIMediaPathDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIMediaPathInfo::OAIMediaPathInfo(): 
    Path({}), 
    NetworkPath({}) {}
OAIMediaPathInfo::~OAIMediaPathInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIMediaProtocol) {
    switch(in) {
        case in_type::FILE: out = "FILE"; break;
        case in_type::HTTP: out = "HTTP"; break;
        case in_type::RTMP: out = "RTMP"; break;
        case in_type::RTSP: out = "RTSP"; break;
        case in_type::UDP: out = "UDP"; break;
        case in_type::RTP: out = "RTP"; break;
        case in_type::FTP: out = "FTP"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIMediaSourceInfo::OAIMediaSourceInfo(): 
    Protocol((OAIMediaProtocol)0), 
    Id({}), 
    Path({}), 
    EncoderPath({}), 
    EncoderProtocol((OAIMediaProtocol)0), 
    Type((OAIMediaSourceType)0), 
    Container({}), 
    Size(0L), 
    Name({}), 
    IsRemote(false), 
    ETag({}), 
    RunTimeTicks(0L), 
    ReadAtNativeFramerate(false), 
    IgnoreDts(false), 
    IgnoreIndex(false), 
    GenPtsInput(false), 
    SupportsTranscoding(false), 
    SupportsDirectStream(false), 
    SupportsDirectPlay(false), 
    IsInfiniteStream(false), 
    RequiresOpening(false), 
    OpenToken({}), 
    RequiresClosing(false), 
    LiveStreamId({}), 
    BufferMs(0), 
    RequiresLooping(false), 
    SupportsProbing(false), 
    VideoType((OAIVideoType)0), 
    IsoType((OAIIsoType)0), 
    Video3DFormat((OAIVideo3DFormat)0), 
    MediaStreams({}), 
    MediaAttachments({}), 
    Formats({}), 
    Bitrate(0), 
    Timestamp((OAITransportStreamTimestamp)0), 
    RequiredHttpHeaders({}), 
    TranscodingUrl({}), 
    TranscodingSubProtocol((OAIMediaStreamProtocol)0), 
    TranscodingContainer({}), 
    AnalyzeDurationMs(0), 
    DefaultAudioStreamIndex(0), 
    DefaultSubtitleStreamIndex(0) {}
OAIMediaSourceInfo::~OAIMediaSourceInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIMediaSourceType) {
    switch(in) {
        case in_type::DEFAULT: out = "DEFAULT"; break;
        case in_type::GROUPING: out = "GROUPING"; break;
        case in_type::PLACEHOLDER: out = "PLACEHOLDER"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIMediaStream::OAIMediaStream(): 
    Codec({}), 
    CodecTag({}), 
    Language({}), 
    ColorRange({}), 
    ColorSpace({}), 
    ColorTransfer({}), 
    ColorPrimaries({}), 
    DvVersionMajor(0), 
    DvVersionMinor(0), 
    DvProfile(0), 
    DvLevel(0), 
    RpuPresentFlag(0), 
    ElPresentFlag(0), 
    BlPresentFlag(0), 
    DvBlSignalCompatibilityId(0), 
    Comment({}), 
    TimeBase({}), 
    CodecTimeBase({}), 
    Title({}), 
    VideoRange((OAIVideoRange)0), 
    VideoRangeType((OAIVideoRangeType)0), 
    VideoDoViTitle({}), 
    AudioSpatialFormat((OAIAudioSpatialFormat)0), 
    LocalizedUndefined({}), 
    LocalizedDefault({}), 
    LocalizedForced({}), 
    LocalizedExternal({}), 
    LocalizedHearingImpaired({}), 
    DisplayTitle({}), 
    NalLengthSize({}), 
    IsInterlaced(false), 
    IsAVC(false), 
    ChannelLayout({}), 
    BitRate(0), 
    BitDepth(0), 
    RefFrames(0), 
    PacketLength(0), 
    Channels(0), 
    SampleRate(0), 
    IsDefault(false), 
    IsForced(false), 
    IsHearingImpaired(false), 
    Height(0), 
    Width(0), 
    AverageFrameRate(0.0f), 
    RealFrameRate(0.0f), 
    Profile({}), 
    Type((OAIMediaStreamType)0), 
    AspectRatio({}), 
    Index(0), 
    Score(0), 
    IsExternal(false), 
    DeliveryMethod((OAISubtitleDeliveryMethod)0), 
    DeliveryUrl({}), 
    IsExternalUrl(false), 
    IsTextSubtitleStream(false), 
    SupportsExternalStream(false), 
    Path({}), 
    PixelFormat({}), 
    Level(0.0), 
    IsAnamorphic(false) {}
OAIMediaStream::~OAIMediaStream() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIMediaStreamProtocol) {
    switch(in) {
        case in_type::HTTP: out = "HTTP"; break;
        case in_type::HLS: out = "HLS"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIMediaStreamType) {
    switch(in) {
        case in_type::AUDIO: out = "AUDIO"; break;
        case in_type::VIDEO: out = "VIDEO"; break;
        case in_type::SUBTITLE: out = "SUBTITLE"; break;
        case in_type::EMBEDDEDIMAGE: out = "EMBEDDEDIMAGE"; break;
        case in_type::DATA: out = "DATA"; break;
        case in_type::LYRIC: out = "LYRIC"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIMediaType) {
    switch(in) {
        case in_type::UNKNOWN: out = "UNKNOWN"; break;
        case in_type::VIDEO: out = "VIDEO"; break;
        case in_type::AUDIO: out = "AUDIO"; break;
        case in_type::PHOTO: out = "PHOTO"; break;
        case in_type::BOOK: out = "BOOK"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIMediaUpdateInfoDto::OAIMediaUpdateInfoDto(): 
    Updates({}) {}
OAIMediaUpdateInfoDto::~OAIMediaUpdateInfoDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIMediaUpdateInfoPathDto::OAIMediaUpdateInfoPathDto(): 
    Path({}), 
    UpdateType({}) {}
OAIMediaUpdateInfoPathDto::~OAIMediaUpdateInfoPathDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIMediaUrl::OAIMediaUrl(): 
    Url({}), 
    Name({}) {}
OAIMediaUrl::~OAIMediaUrl() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIMessageCommand::OAIMessageCommand(): 
    Header({}), 
    Text({}), 
    TimeoutMs(0L) {}
OAIMessageCommand::~OAIMessageCommand() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIMetadataConfiguration::OAIMetadataConfiguration(): 
    UseFileCreationTimeForDateAdded(false) {}
OAIMetadataConfiguration::~OAIMetadataConfiguration() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIMetadataEditorInfo::OAIMetadataEditorInfo(): 
    ParentalRatingOptions({}), 
    Countries({}), 
    Cultures({}), 
    ExternalIdInfos({}), 
    ContentType((OAICollectionType)0), 
    ContentTypeOptions({}) {}
OAIMetadataEditorInfo::~OAIMetadataEditorInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIMetadataField) {
    switch(in) {
        case in_type::CAST: out = "CAST"; break;
        case in_type::GENRES: out = "GENRES"; break;
        case in_type::PRODUCTIONLOCATIONS: out = "PRODUCTIONLOCATIONS"; break;
        case in_type::STUDIOS: out = "STUDIOS"; break;
        case in_type::TAGS: out = "TAGS"; break;
        case in_type::NAME: out = "NAME"; break;
        case in_type::OVERVIEW: out = "OVERVIEW"; break;
        case in_type::RUNTIME: out = "RUNTIME"; break;
        case in_type::OFFICIALRATING: out = "OFFICIALRATING"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIMetadataOptions::OAIMetadataOptions(): 
    ItemType({}), 
    DisabledMetadataSavers({}), 
    LocalMetadataReaderOrder({}), 
    DisabledMetadataFetchers({}), 
    MetadataFetcherOrder({}), 
    DisabledImageFetchers({}), 
    ImageFetcherOrder({}) {}
OAIMetadataOptions::~OAIMetadataOptions() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIMetadataRefreshMode) {
    switch(in) {
        case in_type::NONE: out = "NONE"; break;
        case in_type::VALIDATIONONLY: out = "VALIDATIONONLY"; break;
        case in_type::DEFAULT: out = "DEFAULT"; break;
        case in_type::FULLREFRESH: out = "FULLREFRESH"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIMovePlaylistItemRequestDto::OAIMovePlaylistItemRequestDto(): 
    PlaylistItemId({}), 
    NewIndex(0) {}
OAIMovePlaylistItemRequestDto::~OAIMovePlaylistItemRequestDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIMovieInfo::OAIMovieInfo(): 
    Name({}), 
    OriginalTitle({}), 
    Path({}), 
    MetadataLanguage({}), 
    MetadataCountryCode({}), 
    ProviderIds({}), 
    Year(0), 
    IndexNumber(0), 
    ParentIndexNumber(0), 
    PremiereDate({}), 
    IsAutomated(false) {}
OAIMovieInfo::~OAIMovieInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIMovieInfoRemoteSearchQuery::OAIMovieInfoRemoteSearchQuery(): 
    SearchInfo({}), 
    ItemId({}), 
    SearchProviderName({}), 
    IncludeDisabledProviders(false) {}
OAIMovieInfoRemoteSearchQuery::~OAIMovieInfoRemoteSearchQuery() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIMusicVideoInfo::OAIMusicVideoInfo(): 
    Name({}), 
    OriginalTitle({}), 
    Path({}), 
    MetadataLanguage({}), 
    MetadataCountryCode({}), 
    ProviderIds({}), 
    Year(0), 
    IndexNumber(0), 
    ParentIndexNumber(0), 
    PremiereDate({}), 
    IsAutomated(false), 
    Artists({}) {}
OAIMusicVideoInfo::~OAIMusicVideoInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIMusicVideoInfoRemoteSearchQuery::OAIMusicVideoInfoRemoteSearchQuery(): 
    SearchInfo({}), 
    ItemId({}), 
    SearchProviderName({}), 
    IncludeDisabledProviders(false) {}
OAIMusicVideoInfoRemoteSearchQuery::~OAIMusicVideoInfoRemoteSearchQuery() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAINameGuidPair::OAINameGuidPair(): 
    Name({}), 
    Id({}) {}
OAINameGuidPair::~OAINameGuidPair() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAINameIdPair::OAINameIdPair(): 
    Name({}), 
    Id({}) {}
OAINameIdPair::~OAINameIdPair() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAINameValuePair::OAINameValuePair(): 
    Name({}), 
    Value({}) {}
OAINameValuePair::~OAINameValuePair() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAINetworkConfiguration::OAINetworkConfiguration(): 
    BaseUrl({}), 
    EnableHttps(false), 
    RequireHttps(false), 
    CertificatePath({}), 
    CertificatePassword({}), 
    InternalHttpPort(0), 
    InternalHttpsPort(0), 
    PublicHttpPort(0), 
    PublicHttpsPort(0), 
    AutoDiscovery(false), 
    EnableUPnP(false), 
    EnableIPv4(false), 
    EnableIPv6(false), 
    EnableRemoteAccess(false), 
    LocalNetworkSubnets({}), 
    LocalNetworkAddresses({}), 
    KnownProxies({}), 
    IgnoreVirtualInterfaces(false), 
    VirtualInterfaceNames({}), 
    EnablePublishedServerUriByRequest(false), 
    PublishedServerUriBySubnet({}), 
    RemoteIPFilter({}), 
    IsRemoteIPFilterBlacklist(false) {}
OAINetworkConfiguration::~OAINetworkConfiguration() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAINewGroupRequestDto::OAINewGroupRequestDto(): 
    GroupName({}) {}
OAINewGroupRequestDto::~OAINewGroupRequestDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAINextItemRequestDto::OAINextItemRequestDto(): 
    PlaylistItemId({}) {}
OAINextItemRequestDto::~OAINextItemRequestDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIOpenLiveStreamDto::OAIOpenLiveStreamDto(): 
    OpenToken({}), 
    UserId({}), 
    PlaySessionId({}), 
    MaxStreamingBitrate(0), 
    StartTimeTicks(0L), 
    AudioStreamIndex(0), 
    SubtitleStreamIndex(0), 
    MaxAudioChannels(0), 
    ItemId({}), 
    EnableDirectPlay(false), 
    EnableDirectStream(false), 
    DeviceProfile({}), 
    DirectPlayProtocols({}) {}
OAIOpenLiveStreamDto::~OAIOpenLiveStreamDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIOutboundKeepAliveMessage::OAIOutboundKeepAliveMessage(): 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIOutboundKeepAliveMessage::~OAIOutboundKeepAliveMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

} // namespace jellyfin::model



namespace jellyfin::model {

OAIPackageInfo::OAIPackageInfo(): 
    name({}), 
    description({}), 
    overview({}), 
    owner({}), 
    category({}), 
    guid({}), 
    versions({}), 
    imageUrl({}) {}
OAIPackageInfo::~OAIPackageInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIParentalRating::OAIParentalRating(): 
    Name({}), 
    Value(0) {}
OAIParentalRating::~OAIParentalRating() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIPathSubstitution::OAIPathSubstitution(): 
    From({}), 
    To({}) {}
OAIPathSubstitution::~OAIPathSubstitution() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIPersonKind) {
    switch(in) {
        case in_type::UNKNOWN: out = "UNKNOWN"; break;
        case in_type::ACTOR: out = "ACTOR"; break;
        case in_type::DIRECTOR: out = "DIRECTOR"; break;
        case in_type::COMPOSER: out = "COMPOSER"; break;
        case in_type::WRITER: out = "WRITER"; break;
        case in_type::GUESTSTAR: out = "GUESTSTAR"; break;
        case in_type::PRODUCER: out = "PRODUCER"; break;
        case in_type::CONDUCTOR: out = "CONDUCTOR"; break;
        case in_type::LYRICIST: out = "LYRICIST"; break;
        case in_type::ARRANGER: out = "ARRANGER"; break;
        case in_type::ENGINEER: out = "ENGINEER"; break;
        case in_type::MIXER: out = "MIXER"; break;
        case in_type::REMIXER: out = "REMIXER"; break;
        case in_type::CREATOR: out = "CREATOR"; break;
        case in_type::ARTIST: out = "ARTIST"; break;
        case in_type::ALBUMARTIST: out = "ALBUMARTIST"; break;
        case in_type::AUTHOR: out = "AUTHOR"; break;
        case in_type::ILLUSTRATOR: out = "ILLUSTRATOR"; break;
        case in_type::PENCILLER: out = "PENCILLER"; break;
        case in_type::INKER: out = "INKER"; break;
        case in_type::COLORIST: out = "COLORIST"; break;
        case in_type::LETTERER: out = "LETTERER"; break;
        case in_type::COVERARTIST: out = "COVERARTIST"; break;
        case in_type::EDITOR: out = "EDITOR"; break;
        case in_type::TRANSLATOR: out = "TRANSLATOR"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIPersonLookupInfo::OAIPersonLookupInfo(): 
    Name({}), 
    OriginalTitle({}), 
    Path({}), 
    MetadataLanguage({}), 
    MetadataCountryCode({}), 
    ProviderIds({}), 
    Year(0), 
    IndexNumber(0), 
    ParentIndexNumber(0), 
    PremiereDate({}), 
    IsAutomated(false) {}
OAIPersonLookupInfo::~OAIPersonLookupInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIPersonLookupInfoRemoteSearchQuery::OAIPersonLookupInfoRemoteSearchQuery(): 
    SearchInfo({}), 
    ItemId({}), 
    SearchProviderName({}), 
    IncludeDisabledProviders(false) {}
OAIPersonLookupInfoRemoteSearchQuery::~OAIPersonLookupInfoRemoteSearchQuery() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIPinRedeemResult::OAIPinRedeemResult(): 
    Success(false), 
    UsersReset({}) {}
OAIPinRedeemResult::~OAIPinRedeemResult() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIPingRequestDto::OAIPingRequestDto(): 
    Ping(0L) {}
OAIPingRequestDto::~OAIPingRequestDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIPlayAccess) {
    switch(in) {
        case in_type::FULL: out = "FULL"; break;
        case in_type::NONE: out = "NONE"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIPlayCommand) {
    switch(in) {
        case in_type::PLAYNOW: out = "PLAYNOW"; break;
        case in_type::PLAYNEXT: out = "PLAYNEXT"; break;
        case in_type::PLAYLAST: out = "PLAYLAST"; break;
        case in_type::PLAYINSTANTMIX: out = "PLAYINSTANTMIX"; break;
        case in_type::PLAYSHUFFLE: out = "PLAYSHUFFLE"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIPlayMessage::OAIPlayMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIPlayMessage::~OAIPlayMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIPlayMethod) {
    switch(in) {
        case in_type::TRANSCODE: out = "TRANSCODE"; break;
        case in_type::DIRECTSTREAM: out = "DIRECTSTREAM"; break;
        case in_type::DIRECTPLAY: out = "DIRECTPLAY"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIPlayQueueUpdate::OAIPlayQueueUpdate(): 
    Reason((OAIPlayQueueUpdateReason)0), 
    LastUpdate({}), 
    Playlist({}), 
    PlayingItemIndex(0), 
    StartPositionTicks(0L), 
    IsPlaying(false), 
    ShuffleMode((OAIGroupShuffleMode)0), 
    RepeatMode((OAIGroupRepeatMode)0) {}
OAIPlayQueueUpdate::~OAIPlayQueueUpdate() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIPlayQueueUpdateGroupUpdate::OAIPlayQueueUpdateGroupUpdate(): 
    GroupId({}), 
    Type((OAIGroupUpdateType)0), 
    Data({}) {}
OAIPlayQueueUpdateGroupUpdate::~OAIPlayQueueUpdateGroupUpdate() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIPlayQueueUpdateReason) {
    switch(in) {
        case in_type::NEWPLAYLIST: out = "NEWPLAYLIST"; break;
        case in_type::SETCURRENTITEM: out = "SETCURRENTITEM"; break;
        case in_type::REMOVEITEMS: out = "REMOVEITEMS"; break;
        case in_type::MOVEITEM: out = "MOVEITEM"; break;
        case in_type::QUEUE: out = "QUEUE"; break;
        case in_type::QUEUENEXT: out = "QUEUENEXT"; break;
        case in_type::NEXTITEM: out = "NEXTITEM"; break;
        case in_type::PREVIOUSITEM: out = "PREVIOUSITEM"; break;
        case in_type::REPEATMODE: out = "REPEATMODE"; break;
        case in_type::SHUFFLEMODE: out = "SHUFFLEMODE"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIPlayRequest::OAIPlayRequest(): 
    ItemIds({}), 
    StartPositionTicks(0L), 
    PlayCommand((OAIPlayCommand)0), 
    ControllingUserId({}), 
    SubtitleStreamIndex(0), 
    AudioStreamIndex(0), 
    MediaSourceId({}), 
    StartIndex(0) {}
OAIPlayRequest::~OAIPlayRequest() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIPlayRequestDto::OAIPlayRequestDto(): 
    PlayingQueue({}), 
    PlayingItemPosition(0), 
    StartPositionTicks(0L) {}
OAIPlayRequestDto::~OAIPlayRequestDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIPlaybackErrorCode) {
    switch(in) {
        case in_type::NOTALLOWED: out = "NOTALLOWED"; break;
        case in_type::NOCOMPATIBLESTREAM: out = "NOCOMPATIBLESTREAM"; break;
        case in_type::RATELIMITEXCEEDED: out = "RATELIMITEXCEEDED"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIPlaybackInfoDto::OAIPlaybackInfoDto(): 
    UserId({}), 
    MaxStreamingBitrate(0), 
    StartTimeTicks(0L), 
    AudioStreamIndex(0), 
    SubtitleStreamIndex(0), 
    MaxAudioChannels(0), 
    MediaSourceId({}), 
    LiveStreamId({}), 
    DeviceProfile({}), 
    EnableDirectPlay(false), 
    EnableDirectStream(false), 
    EnableTranscoding(false), 
    AllowVideoStreamCopy(false), 
    AllowAudioStreamCopy(false), 
    AutoOpenLiveStream(false) {}
OAIPlaybackInfoDto::~OAIPlaybackInfoDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIPlaybackInfoResponse::OAIPlaybackInfoResponse(): 
    MediaSources({}), 
    PlaySessionId({}), 
    ErrorCode((OAIPlaybackErrorCode)0) {}
OAIPlaybackInfoResponse::~OAIPlaybackInfoResponse() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIPlaybackOrder) {
    switch(in) {
        case in_type::DEFAULT: out = "DEFAULT"; break;
        case in_type::SHUFFLE: out = "SHUFFLE"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIPlaybackProgressInfo::OAIPlaybackProgressInfo(): 
    CanSeek(false), 
    Item({}), 
    ItemId({}), 
    SessionId({}), 
    MediaSourceId({}), 
    AudioStreamIndex(0), 
    SubtitleStreamIndex(0), 
    IsPaused(false), 
    IsMuted(false), 
    PositionTicks(0L), 
    PlaybackStartTimeTicks(0L), 
    VolumeLevel(0), 
    Brightness(0), 
    AspectRatio({}), 
    PlayMethod((OAIPlayMethod)0), 
    LiveStreamId({}), 
    PlaySessionId({}), 
    RepeatMode((OAIRepeatMode)0), 
    PlaybackOrder((OAIPlaybackOrder)0), 
    NowPlayingQueue({}), 
    PlaylistItemId({}) {}
OAIPlaybackProgressInfo::~OAIPlaybackProgressInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIPlaybackRequestType) {
    switch(in) {
        case in_type::PLAY: out = "PLAY"; break;
        case in_type::SETPLAYLISTITEM: out = "SETPLAYLISTITEM"; break;
        case in_type::REMOVEFROMPLAYLIST: out = "REMOVEFROMPLAYLIST"; break;
        case in_type::MOVEPLAYLISTITEM: out = "MOVEPLAYLISTITEM"; break;
        case in_type::QUEUE: out = "QUEUE"; break;
        case in_type::UNPAUSE: out = "UNPAUSE"; break;
        case in_type::PAUSE: out = "PAUSE"; break;
        case in_type::STOP: out = "STOP"; break;
        case in_type::SEEK: out = "SEEK"; break;
        case in_type::BUFFER: out = "BUFFER"; break;
        case in_type::READY: out = "READY"; break;
        case in_type::NEXTITEM: out = "NEXTITEM"; break;
        case in_type::PREVIOUSITEM: out = "PREVIOUSITEM"; break;
        case in_type::SETREPEATMODE: out = "SETREPEATMODE"; break;
        case in_type::SETSHUFFLEMODE: out = "SETSHUFFLEMODE"; break;
        case in_type::PING: out = "PING"; break;
        case in_type::IGNOREWAIT: out = "IGNOREWAIT"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIPlaybackStartInfo::OAIPlaybackStartInfo(): 
    CanSeek(false), 
    Item({}), 
    ItemId({}), 
    SessionId({}), 
    MediaSourceId({}), 
    AudioStreamIndex(0), 
    SubtitleStreamIndex(0), 
    IsPaused(false), 
    IsMuted(false), 
    PositionTicks(0L), 
    PlaybackStartTimeTicks(0L), 
    VolumeLevel(0), 
    Brightness(0), 
    AspectRatio({}), 
    PlayMethod((OAIPlayMethod)0), 
    LiveStreamId({}), 
    PlaySessionId({}), 
    RepeatMode((OAIRepeatMode)0), 
    PlaybackOrder((OAIPlaybackOrder)0), 
    NowPlayingQueue({}), 
    PlaylistItemId({}) {}
OAIPlaybackStartInfo::~OAIPlaybackStartInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIPlaybackStopInfo::OAIPlaybackStopInfo(): 
    Item({}), 
    ItemId({}), 
    SessionId({}), 
    MediaSourceId({}), 
    PositionTicks(0L), 
    LiveStreamId({}), 
    PlaySessionId({}), 
    Failed(false), 
    NextMediaType({}), 
    PlaylistItemId({}), 
    NowPlayingQueue({}) {}
OAIPlaybackStopInfo::~OAIPlaybackStopInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIPlayerStateInfo::OAIPlayerStateInfo(): 
    PositionTicks(0L), 
    CanSeek(false), 
    IsPaused(false), 
    IsMuted(false), 
    VolumeLevel(0), 
    AudioStreamIndex(0), 
    SubtitleStreamIndex(0), 
    MediaSourceId({}), 
    PlayMethod((OAIPlayMethod)0), 
    RepeatMode((OAIRepeatMode)0), 
    PlaybackOrder((OAIPlaybackOrder)0), 
    LiveStreamId({}) {}
OAIPlayerStateInfo::~OAIPlayerStateInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIPlaylistCreationResult::OAIPlaylistCreationResult(): 
    Id({}) {}
OAIPlaylistCreationResult::~OAIPlaylistCreationResult() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIPlaylistUserPermissions::OAIPlaylistUserPermissions(): 
    UserId({}), 
    CanEdit(false) {}
OAIPlaylistUserPermissions::~OAIPlaylistUserPermissions() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIPlaystateCommand) {
    switch(in) {
        case in_type::STOP: out = "STOP"; break;
        case in_type::PAUSE: out = "PAUSE"; break;
        case in_type::UNPAUSE: out = "UNPAUSE"; break;
        case in_type::NEXTTRACK: out = "NEXTTRACK"; break;
        case in_type::PREVIOUSTRACK: out = "PREVIOUSTRACK"; break;
        case in_type::SEEK: out = "SEEK"; break;
        case in_type::REWIND: out = "REWIND"; break;
        case in_type::FASTFORWARD: out = "FASTFORWARD"; break;
        case in_type::PLAYPAUSE: out = "PLAYPAUSE"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIPlaystateMessage::OAIPlaystateMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIPlaystateMessage::~OAIPlaystateMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIPlaystateRequest::OAIPlaystateRequest(): 
    Command((OAIPlaystateCommand)0), 
    SeekPositionTicks(0L), 
    ControllingUserId({}) {}
OAIPlaystateRequest::~OAIPlaystateRequest() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIPluginInfo::OAIPluginInfo(): 
    Name({}), 
    Version({}), 
    ConfigurationFileName({}), 
    Description({}), 
    Id({}), 
    CanUninstall(false), 
    HasImage(false), 
    Status((OAIPluginStatus)0) {}
OAIPluginInfo::~OAIPluginInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIPluginInstallationCancelledMessage::OAIPluginInstallationCancelledMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIPluginInstallationCancelledMessage::~OAIPluginInstallationCancelledMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIPluginInstallationCompletedMessage::OAIPluginInstallationCompletedMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIPluginInstallationCompletedMessage::~OAIPluginInstallationCompletedMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIPluginInstallationFailedMessage::OAIPluginInstallationFailedMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIPluginInstallationFailedMessage::~OAIPluginInstallationFailedMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIPluginInstallingMessage::OAIPluginInstallingMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIPluginInstallingMessage::~OAIPluginInstallingMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIPluginStatus) {
    switch(in) {
        case in_type::ACTIVE: out = "ACTIVE"; break;
        case in_type::RESTART: out = "RESTART"; break;
        case in_type::DELETED: out = "DELETED"; break;
        case in_type::SUPERCEDED: out = "SUPERCEDED"; break;
        case in_type::MALFUNCTIONED: out = "MALFUNCTIONED"; break;
        case in_type::NOTSUPPORTED: out = "NOTSUPPORTED"; break;
        case in_type::DISABLED: out = "DISABLED"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIPluginUninstalledMessage::OAIPluginUninstalledMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIPluginUninstalledMessage::~OAIPluginUninstalledMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIPreviousItemRequestDto::OAIPreviousItemRequestDto(): 
    PlaylistItemId({}) {}
OAIPreviousItemRequestDto::~OAIPreviousItemRequestDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIProcessPriorityClass) {
    switch(in) {
        case in_type::NORMAL: out = "NORMAL"; break;
        case in_type::IDLE: out = "IDLE"; break;
        case in_type::HIGH: out = "HIGH"; break;
        case in_type::REALTIME: out = "REALTIME"; break;
        case in_type::BELOWNORMAL: out = "BELOWNORMAL"; break;
        case in_type::ABOVENORMAL: out = "ABOVENORMAL"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIProfileCondition::OAIProfileCondition(): 
    Condition((OAIProfileConditionType)0), 
    Property((OAIProfileConditionValue)0), 
    Value({}), 
    IsRequired(false) {}
OAIProfileCondition::~OAIProfileCondition() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIProfileConditionType) {
    switch(in) {
        case in_type::EQUALS: out = "EQUALS"; break;
        case in_type::NOTEQUALS: out = "NOTEQUALS"; break;
        case in_type::LESSTHANEQUAL: out = "LESSTHANEQUAL"; break;
        case in_type::GREATERTHANEQUAL: out = "GREATERTHANEQUAL"; break;
        case in_type::EQUALSANY: out = "EQUALSANY"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIProfileConditionValue) {
    switch(in) {
        case in_type::AUDIOCHANNELS: out = "AUDIOCHANNELS"; break;
        case in_type::AUDIOBITRATE: out = "AUDIOBITRATE"; break;
        case in_type::AUDIOPROFILE: out = "AUDIOPROFILE"; break;
        case in_type::WIDTH: out = "WIDTH"; break;
        case in_type::HEIGHT: out = "HEIGHT"; break;
        case in_type::HAS64BITOFFSETS: out = "HAS64BITOFFSETS"; break;
        case in_type::PACKETLENGTH: out = "PACKETLENGTH"; break;
        case in_type::VIDEOBITDEPTH: out = "VIDEOBITDEPTH"; break;
        case in_type::VIDEOBITRATE: out = "VIDEOBITRATE"; break;
        case in_type::VIDEOFRAMERATE: out = "VIDEOFRAMERATE"; break;
        case in_type::VIDEOLEVEL: out = "VIDEOLEVEL"; break;
        case in_type::VIDEOPROFILE: out = "VIDEOPROFILE"; break;
        case in_type::VIDEOTIMESTAMP: out = "VIDEOTIMESTAMP"; break;
        case in_type::ISANAMORPHIC: out = "ISANAMORPHIC"; break;
        case in_type::REFFRAMES: out = "REFFRAMES"; break;
        case in_type::NUMAUDIOSTREAMS: out = "NUMAUDIOSTREAMS"; break;
        case in_type::NUMVIDEOSTREAMS: out = "NUMVIDEOSTREAMS"; break;
        case in_type::ISSECONDARYAUDIO: out = "ISSECONDARYAUDIO"; break;
        case in_type::VIDEOCODECTAG: out = "VIDEOCODECTAG"; break;
        case in_type::ISAVC: out = "ISAVC"; break;
        case in_type::ISINTERLACED: out = "ISINTERLACED"; break;
        case in_type::AUDIOSAMPLERATE: out = "AUDIOSAMPLERATE"; break;
        case in_type::AUDIOBITDEPTH: out = "AUDIOBITDEPTH"; break;
        case in_type::VIDEORANGETYPE: out = "VIDEORANGETYPE"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIProgramAudio) {
    switch(in) {
        case in_type::MONO: out = "MONO"; break;
        case in_type::STEREO: out = "STEREO"; break;
        case in_type::DOLBY: out = "DOLBY"; break;
        case in_type::DOLBYDIGITAL: out = "DOLBYDIGITAL"; break;
        case in_type::THX: out = "THX"; break;
        case in_type::ATMOS: out = "ATMOS"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIPublicSystemInfo::OAIPublicSystemInfo(): 
    LocalAddress({}), 
    ServerName({}), 
    Version({}), 
    ProductName({}), 
    OperatingSystem({}), 
    Id({}), 
    StartupWizardCompleted(false) {}
OAIPublicSystemInfo::~OAIPublicSystemInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIQueryFilters::OAIQueryFilters(): 
    Genres({}), 
    Tags({}) {}
OAIQueryFilters::~OAIQueryFilters() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIQueryFiltersLegacy::OAIQueryFiltersLegacy(): 
    Genres({}), 
    Tags({}), 
    OfficialRatings({}), 
    Years({}) {}
OAIQueryFiltersLegacy::~OAIQueryFiltersLegacy() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIQueueItem::OAIQueueItem(): 
    Id({}), 
    PlaylistItemId({}) {}
OAIQueueItem::~OAIQueueItem() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIQueueRequestDto::OAIQueueRequestDto(): 
    ItemIds({}), 
    Mode((OAIGroupQueueMode)0) {}
OAIQueueRequestDto::~OAIQueueRequestDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIQuickConnectDto::OAIQuickConnectDto(): 
    Secret({}) {}
OAIQuickConnectDto::~OAIQuickConnectDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIQuickConnectResult::OAIQuickConnectResult(): 
    Authenticated(false), 
    Secret({}), 
    Code({}), 
    DeviceId({}), 
    DeviceName({}), 
    AppName({}), 
    AppVersion({}), 
    DateAdded({}) {}
OAIQuickConnectResult::~OAIQuickConnectResult() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIRatingType) {
    switch(in) {
        case in_type::SCORE: out = "SCORE"; break;
        case in_type::LIKES: out = "LIKES"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIReadyRequestDto::OAIReadyRequestDto(): 
    When({}), 
    PositionTicks(0L), 
    IsPlaying(false), 
    PlaylistItemId({}) {}
OAIReadyRequestDto::~OAIReadyRequestDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIRecommendationDto::OAIRecommendationDto(): 
    Items({}), 
    RecommendationType((OAIRecommendationType)0), 
    BaselineItemName({}), 
    CategoryId({}) {}
OAIRecommendationDto::~OAIRecommendationDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIRecommendationType) {
    switch(in) {
        case in_type::SIMILARTORECENTLYPLAYED: out = "SIMILARTORECENTLYPLAYED"; break;
        case in_type::SIMILARTOLIKEDITEM: out = "SIMILARTOLIKEDITEM"; break;
        case in_type::HASDIRECTORFROMRECENTLYPLAYED: out = "HASDIRECTORFROMRECENTLYPLAYED"; break;
        case in_type::HASACTORFROMRECENTLYPLAYED: out = "HASACTORFROMRECENTLYPLAYED"; break;
        case in_type::HASLIKEDDIRECTOR: out = "HASLIKEDDIRECTOR"; break;
        case in_type::HASLIKEDACTOR: out = "HASLIKEDACTOR"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIRecordingStatus) {
    switch(in) {
        case in_type::NEW: out = "NEW"; break;
        case in_type::INPROGRESS: out = "INPROGRESS"; break;
        case in_type::COMPLETED: out = "COMPLETED"; break;
        case in_type::CANCELLED: out = "CANCELLED"; break;
        case in_type::CONFLICTEDOK: out = "CONFLICTEDOK"; break;
        case in_type::CONFLICTEDNOTOK: out = "CONFLICTEDNOTOK"; break;
        case in_type::ERROR: out = "ERROR"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIRefreshProgressMessage::OAIRefreshProgressMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIRefreshProgressMessage::~OAIRefreshProgressMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIRemoteImageInfo::OAIRemoteImageInfo(): 
    ProviderName({}), 
    Url({}), 
    ThumbnailUrl({}), 
    Height(0), 
    Width(0), 
    CommunityRating(0.0), 
    VoteCount(0), 
    Language({}), 
    Type((OAIImageType)0), 
    RatingType((OAIRatingType)0) {}
OAIRemoteImageInfo::~OAIRemoteImageInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIRemoteImageResult::OAIRemoteImageResult(): 
    Images({}), 
    TotalRecordCount(0), 
    Providers({}) {}
OAIRemoteImageResult::~OAIRemoteImageResult() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIRemoteLyricInfoDto::OAIRemoteLyricInfoDto(): 
    Id({}), 
    ProviderName({}), 
    Lyrics({}) {}
OAIRemoteLyricInfoDto::~OAIRemoteLyricInfoDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIRemoteSearchResult::OAIRemoteSearchResult(): 
    Name({}), 
    ProviderIds({}), 
    ProductionYear(0), 
    IndexNumber(0), 
    IndexNumberEnd(0), 
    ParentIndexNumber(0), 
    PremiereDate({}), 
    ImageUrl({}), 
    SearchProviderName({}), 
    Overview({}), 
    AlbumArtist(nullptr), 
    Artists({}) {}
OAIRemoteSearchResult::~OAIRemoteSearchResult() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIRemoteSubtitleInfo::OAIRemoteSubtitleInfo(): 
    ThreeLetterISOLanguageName({}), 
    Id({}), 
    ProviderName({}), 
    Name({}), 
    Format({}), 
    Author({}), 
    Comment({}), 
    DateCreated({}), 
    CommunityRating(0.0f), 
    FrameRate(0.0f), 
    DownloadCount(0), 
    IsHashMatch(false), 
    AiTranslated(false), 
    MachineTranslated(false), 
    Forced(false), 
    HearingImpaired(false) {}
OAIRemoteSubtitleInfo::~OAIRemoteSubtitleInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIRemoveFromPlaylistRequestDto::OAIRemoveFromPlaylistRequestDto(): 
    PlaylistItemIds({}), 
    ClearPlaylist(false), 
    ClearPlayingItem(false) {}
OAIRemoveFromPlaylistRequestDto::~OAIRemoveFromPlaylistRequestDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIRepeatMode) {
    switch(in) {
        case in_type::REPEATNONE: out = "REPEATNONE"; break;
        case in_type::REPEATALL: out = "REPEATALL"; break;
        case in_type::REPEATONE: out = "REPEATONE"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIRepositoryInfo::OAIRepositoryInfo(): 
    Name({}), 
    Url({}), 
    Enabled(false) {}
OAIRepositoryInfo::~OAIRepositoryInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIRestartRequiredMessage::OAIRestartRequiredMessage(): 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIRestartRequiredMessage::~OAIRestartRequiredMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIScheduledTaskEndedMessage::OAIScheduledTaskEndedMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIScheduledTaskEndedMessage::~OAIScheduledTaskEndedMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIScheduledTasksInfoMessage::OAIScheduledTasksInfoMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIScheduledTasksInfoMessage::~OAIScheduledTasksInfoMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIScheduledTasksInfoStartMessage::OAIScheduledTasksInfoStartMessage(): 
    Data({}), 
    MessageType((OAISessionMessageType)0) {}
OAIScheduledTasksInfoStartMessage::~OAIScheduledTasksInfoStartMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIScheduledTasksInfoStopMessage::OAIScheduledTasksInfoStopMessage(): 
    MessageType((OAISessionMessageType)0) {}
OAIScheduledTasksInfoStopMessage::~OAIScheduledTasksInfoStopMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIScrollDirection) {
    switch(in) {
        case in_type::HORIZONTAL: out = "HORIZONTAL"; break;
        case in_type::VERTICAL: out = "VERTICAL"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAISearchHint::OAISearchHint(): 
    ItemId({}), 
    Id({}), 
    Name({}), 
    MatchedTerm({}), 
    IndexNumber(0), 
    ProductionYear(0), 
    ParentIndexNumber(0), 
    PrimaryImageTag({}), 
    ThumbImageTag({}), 
    ThumbImageItemId({}), 
    BackdropImageTag({}), 
    BackdropImageItemId({}), 
    Type((OAIBaseItemKind)0), 
    IsFolder(false), 
    RunTimeTicks(0L), 
    MediaType((OAIMediaType)0), 
    StartDate({}), 
    EndDate({}), 
    Series({}), 
    Status({}), 
    Album({}), 
    AlbumId({}), 
    AlbumArtist({}), 
    Artists({}), 
    SongCount(0), 
    EpisodeCount(0), 
    ChannelId({}), 
    ChannelName({}), 
    PrimaryImageAspectRatio(0.0) {}
OAISearchHint::~OAISearchHint() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISearchHintResult::OAISearchHintResult(): 
    SearchHints({}), 
    TotalRecordCount(0) {}
OAISearchHintResult::~OAISearchHintResult() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISeekRequestDto::OAISeekRequestDto(): 
    PositionTicks(0L) {}
OAISeekRequestDto::~OAISeekRequestDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISendCommand::OAISendCommand(): 
    GroupId({}), 
    PlaylistItemId({}), 
    When({}), 
    PositionTicks(0L), 
    Command((OAISendCommandType)0), 
    EmittedAt({}) {}
OAISendCommand::~OAISendCommand() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAISendCommandType) {
    switch(in) {
        case in_type::UNPAUSE: out = "UNPAUSE"; break;
        case in_type::PAUSE: out = "PAUSE"; break;
        case in_type::STOP: out = "STOP"; break;
        case in_type::SEEK: out = "SEEK"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAISeriesInfo::OAISeriesInfo(): 
    Name({}), 
    OriginalTitle({}), 
    Path({}), 
    MetadataLanguage({}), 
    MetadataCountryCode({}), 
    ProviderIds({}), 
    Year(0), 
    IndexNumber(0), 
    ParentIndexNumber(0), 
    PremiereDate({}), 
    IsAutomated(false) {}
OAISeriesInfo::~OAISeriesInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISeriesInfoRemoteSearchQuery::OAISeriesInfoRemoteSearchQuery(): 
    SearchInfo({}), 
    ItemId({}), 
    SearchProviderName({}), 
    IncludeDisabledProviders(false) {}
OAISeriesInfoRemoteSearchQuery::~OAISeriesInfoRemoteSearchQuery() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAISeriesStatus) {
    switch(in) {
        case in_type::CONTINUING: out = "CONTINUING"; break;
        case in_type::ENDED: out = "ENDED"; break;
        case in_type::UNRELEASED: out = "UNRELEASED"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAISeriesTimerCancelledMessage::OAISeriesTimerCancelledMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAISeriesTimerCancelledMessage::~OAISeriesTimerCancelledMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISeriesTimerCreatedMessage::OAISeriesTimerCreatedMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAISeriesTimerCreatedMessage::~OAISeriesTimerCreatedMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISeriesTimerInfoDto::OAISeriesTimerInfoDto(): 
    Id({}), 
    Type({}), 
    ServerId({}), 
    ExternalId({}), 
    ChannelId({}), 
    ExternalChannelId({}), 
    ChannelName({}), 
    ChannelPrimaryImageTag({}), 
    ProgramId({}), 
    ExternalProgramId({}), 
    Name({}), 
    Overview({}), 
    StartDate({}), 
    EndDate({}), 
    ServiceName({}), 
    Priority(0), 
    PrePaddingSeconds(0), 
    PostPaddingSeconds(0), 
    IsPrePaddingRequired(false), 
    ParentBackdropItemId({}), 
    ParentBackdropImageTags({}), 
    IsPostPaddingRequired(false), 
    KeepUntil((OAIKeepUntil)0), 
    RecordAnyTime(false), 
    SkipEpisodesInLibrary(false), 
    RecordAnyChannel(false), 
    KeepUpTo(0), 
    RecordNewOnly(false), 
    Days({}), 
    DayPattern((OAIDayPattern)0), 
    ImageTags({}), 
    ParentThumbItemId({}), 
    ParentThumbImageTag({}), 
    ParentPrimaryImageItemId({}), 
    ParentPrimaryImageTag({}) {}
OAISeriesTimerInfoDto::~OAISeriesTimerInfoDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISeriesTimerInfoDtoQueryResult::OAISeriesTimerInfoDtoQueryResult(): 
    Items({}), 
    TotalRecordCount(0), 
    StartIndex(0) {}
OAISeriesTimerInfoDtoQueryResult::~OAISeriesTimerInfoDtoQueryResult() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIServerConfiguration::OAIServerConfiguration(): 
    LogFileRetentionDays(0), 
    IsStartupWizardCompleted(false), 
    CachePath({}), 
    PreviousVersion({}), 
    PreviousVersionStr({}), 
    EnableMetrics(false), 
    EnableNormalizedItemByNameIds(false), 
    IsPortAuthorized(false), 
    QuickConnectAvailable(false), 
    EnableCaseSensitiveItemIds(false), 
    DisableLiveTvChannelUserDataName(false), 
    MetadataPath({}), 
    MetadataNetworkPath({}), 
    PreferredMetadataLanguage({}), 
    MetadataCountryCode({}), 
    SortReplaceCharacters({}), 
    SortRemoveCharacters({}), 
    SortRemoveWords({}), 
    MinResumePct(0), 
    MaxResumePct(0), 
    MinResumeDurationSeconds(0), 
    MinAudiobookResume(0), 
    MaxAudiobookResume(0), 
    InactiveSessionThreshold(0), 
    LibraryMonitorDelay(0), 
    LibraryUpdateDuration(0), 
    ImageSavingConvention((OAIImageSavingConvention)0), 
    MetadataOptions({}), 
    SkipDeserializationForBasicTypes(false), 
    ServerName({}), 
    UICulture({}), 
    SaveMetadataHidden(false), 
    ContentTypes({}), 
    RemoteClientBitrateLimit(0), 
    EnableFolderView(false), 
    EnableGroupingIntoCollections(false), 
    DisplaySpecialsWithinSeasons(false), 
    CodecsUsed({}), 
    PluginRepositories({}), 
    EnableExternalContentInSuggestions(false), 
    ImageExtractionTimeoutMs(0), 
    PathSubstitutions({}), 
    EnableSlowResponseWarning(false), 
    SlowResponseThresholdMs(0L), 
    CorsHosts({}), 
    ActivityLogRetentionDays(0), 
    LibraryScanFanoutConcurrency(0), 
    LibraryMetadataRefreshConcurrency(0), 
    RemoveOldPlugins(false), 
    AllowClientLogUpload(false), 
    DummyChapterDuration(0), 
    ChapterImageResolution((OAIImageResolution)0), 
    ParallelImageEncodingLimit(0), 
    CastReceiverApplications({}), 
    TrickplayOptions({}) {}
OAIServerConfiguration::~OAIServerConfiguration() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIServerDiscoveryInfo::OAIServerDiscoveryInfo(): 
    Address({}), 
    Id({}), 
    Name({}), 
    EndpointAddress({}) {}
OAIServerDiscoveryInfo::~OAIServerDiscoveryInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIServerRestartingMessage::OAIServerRestartingMessage(): 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIServerRestartingMessage::~OAIServerRestartingMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIServerShuttingDownMessage::OAIServerShuttingDownMessage(): 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIServerShuttingDownMessage::~OAIServerShuttingDownMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISessionInfo::OAISessionInfo(): 
    PlayState({}), 
    AdditionalUsers({}), 
    Capabilities({}), 
    RemoteEndPoint({}), 
    PlayableMediaTypes({}), 
    Id({}), 
    UserId({}), 
    UserName({}), 
    Client({}), 
    LastActivityDate({}), 
    LastPlaybackCheckIn({}), 
    LastPausedDate({}), 
    DeviceName({}), 
    DeviceType({}), 
    NowPlayingItem({}), 
    NowViewingItem({}), 
    DeviceId({}), 
    ApplicationVersion({}), 
    TranscodingInfo({}), 
    IsActive(false), 
    SupportsMediaControl(false), 
    SupportsRemoteControl(false), 
    NowPlayingQueue({}), 
    NowPlayingQueueFullItems({}), 
    HasCustomDeviceName(false), 
    PlaylistItemId({}), 
    ServerId({}), 
    UserPrimaryImageTag({}), 
    SupportedCommands({}) {}
OAISessionInfo::~OAISessionInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAISessionMessageType) {
    switch(in) {
        case in_type::FORCEKEEPALIVE: out = "FORCEKEEPALIVE"; break;
        case in_type::GENERALCOMMAND: out = "GENERALCOMMAND"; break;
        case in_type::USERDATACHANGED: out = "USERDATACHANGED"; break;
        case in_type::SESSIONS: out = "SESSIONS"; break;
        case in_type::PLAY: out = "PLAY"; break;
        case in_type::SYNCPLAYCOMMAND: out = "SYNCPLAYCOMMAND"; break;
        case in_type::SYNCPLAYGROUPUPDATE: out = "SYNCPLAYGROUPUPDATE"; break;
        case in_type::PLAYSTATE: out = "PLAYSTATE"; break;
        case in_type::RESTARTREQUIRED: out = "RESTARTREQUIRED"; break;
        case in_type::SERVERSHUTTINGDOWN: out = "SERVERSHUTTINGDOWN"; break;
        case in_type::SERVERRESTARTING: out = "SERVERRESTARTING"; break;
        case in_type::LIBRARYCHANGED: out = "LIBRARYCHANGED"; break;
        case in_type::USERDELETED: out = "USERDELETED"; break;
        case in_type::USERUPDATED: out = "USERUPDATED"; break;
        case in_type::SERIESTIMERCREATED: out = "SERIESTIMERCREATED"; break;
        case in_type::TIMERCREATED: out = "TIMERCREATED"; break;
        case in_type::SERIESTIMERCANCELLED: out = "SERIESTIMERCANCELLED"; break;
        case in_type::TIMERCANCELLED: out = "TIMERCANCELLED"; break;
        case in_type::REFRESHPROGRESS: out = "REFRESHPROGRESS"; break;
        case in_type::SCHEDULEDTASKENDED: out = "SCHEDULEDTASKENDED"; break;
        case in_type::PACKAGEINSTALLATIONCANCELLED: out = "PACKAGEINSTALLATIONCANCELLED"; break;
        case in_type::PACKAGEINSTALLATIONFAILED: out = "PACKAGEINSTALLATIONFAILED"; break;
        case in_type::PACKAGEINSTALLATIONCOMPLETED: out = "PACKAGEINSTALLATIONCOMPLETED"; break;
        case in_type::PACKAGEINSTALLING: out = "PACKAGEINSTALLING"; break;
        case in_type::PACKAGEUNINSTALLED: out = "PACKAGEUNINSTALLED"; break;
        case in_type::ACTIVITYLOGENTRY: out = "ACTIVITYLOGENTRY"; break;
        case in_type::SCHEDULEDTASKSINFO: out = "SCHEDULEDTASKSINFO"; break;
        case in_type::ACTIVITYLOGENTRYSTART: out = "ACTIVITYLOGENTRYSTART"; break;
        case in_type::ACTIVITYLOGENTRYSTOP: out = "ACTIVITYLOGENTRYSTOP"; break;
        case in_type::SESSIONSSTART: out = "SESSIONSSTART"; break;
        case in_type::SESSIONSSTOP: out = "SESSIONSSTOP"; break;
        case in_type::SCHEDULEDTASKSINFOSTART: out = "SCHEDULEDTASKSINFOSTART"; break;
        case in_type::SCHEDULEDTASKSINFOSTOP: out = "SCHEDULEDTASKSINFOSTOP"; break;
        case in_type::KEEPALIVE: out = "KEEPALIVE"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAISessionUserInfo::OAISessionUserInfo(): 
    UserId({}), 
    UserName({}) {}
OAISessionUserInfo::~OAISessionUserInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISessionsMessage::OAISessionsMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAISessionsMessage::~OAISessionsMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISessionsStartMessage::OAISessionsStartMessage(): 
    Data({}), 
    MessageType((OAISessionMessageType)0) {}
OAISessionsStartMessage::~OAISessionsStartMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISessionsStopMessage::OAISessionsStopMessage(): 
    MessageType((OAISessionMessageType)0) {}
OAISessionsStopMessage::~OAISessionsStopMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISetChannelMappingDto::OAISetChannelMappingDto(): 
    ProviderId({}), 
    TunerChannelId({}), 
    ProviderChannelId({}) {}
OAISetChannelMappingDto::~OAISetChannelMappingDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISetPlaylistItemRequestDto::OAISetPlaylistItemRequestDto(): 
    PlaylistItemId({}) {}
OAISetPlaylistItemRequestDto::~OAISetPlaylistItemRequestDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISetRepeatModeRequestDto::OAISetRepeatModeRequestDto(): 
    Mode((OAIGroupRepeatMode)0) {}
OAISetRepeatModeRequestDto::~OAISetRepeatModeRequestDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISetShuffleModeRequestDto::OAISetShuffleModeRequestDto(): 
    Mode((OAIGroupShuffleMode)0) {}
OAISetShuffleModeRequestDto::~OAISetShuffleModeRequestDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISongInfo::OAISongInfo(): 
    Name({}), 
    OriginalTitle({}), 
    Path({}), 
    MetadataLanguage({}), 
    MetadataCountryCode({}), 
    ProviderIds({}), 
    Year(0), 
    IndexNumber(0), 
    ParentIndexNumber(0), 
    PremiereDate({}), 
    IsAutomated(false), 
    AlbumArtists({}), 
    Album({}), 
    Artists({}) {}
OAISongInfo::~OAISongInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAISortOrder) {
    switch(in) {
        case in_type::ASCENDING: out = "ASCENDING"; break;
        case in_type::DESCENDING: out = "DESCENDING"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAISpecialViewOptionDto::OAISpecialViewOptionDto(): 
    Name({}), 
    Id({}) {}
OAISpecialViewOptionDto::~OAISpecialViewOptionDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIStartupConfigurationDto::OAIStartupConfigurationDto(): 
    UICulture({}), 
    MetadataCountryCode({}), 
    PreferredMetadataLanguage({}) {}
OAIStartupConfigurationDto::~OAIStartupConfigurationDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIStartupRemoteAccessDto::OAIStartupRemoteAccessDto(): 
    EnableRemoteAccess(false), 
    EnableAutomaticPortMapping(false) {}
OAIStartupRemoteAccessDto::~OAIStartupRemoteAccessDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIStartupUserDto::OAIStartupUserDto(): 
    Name({}), 
    Password({}) {}
OAIStartupUserDto::~OAIStartupUserDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIStringGroupUpdate::OAIStringGroupUpdate(): 
    GroupId({}), 
    Type((OAIGroupUpdateType)0), 
    Data({}) {}
OAIStringGroupUpdate::~OAIStringGroupUpdate() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAISubtitleDeliveryMethod) {
    switch(in) {
        case in_type::ENCODE: out = "ENCODE"; break;
        case in_type::EMBED: out = "EMBED"; break;
        case in_type::EXTERNAL: out = "EXTERNAL"; break;
        case in_type::HLS: out = "HLS"; break;
        case in_type::DROP: out = "DROP"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAISubtitleOptions::OAISubtitleOptions(): 
    SkipIfEmbeddedSubtitlesPresent(false), 
    SkipIfAudioTrackMatches(false), 
    DownloadLanguages({}), 
    DownloadMovieSubtitles(false), 
    DownloadEpisodeSubtitles(false), 
    OpenSubtitlesUsername({}), 
    OpenSubtitlesPasswordHash({}), 
    IsOpenSubtitleVipAccount(false), 
    RequirePerfectMatch(false) {}
OAISubtitleOptions::~OAISubtitleOptions() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAISubtitlePlaybackMode) {
    switch(in) {
        case in_type::DEFAULT: out = "DEFAULT"; break;
        case in_type::ALWAYS: out = "ALWAYS"; break;
        case in_type::ONLYFORCED: out = "ONLYFORCED"; break;
        case in_type::NONE: out = "NONE"; break;
        case in_type::SMART: out = "SMART"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAISubtitleProfile::OAISubtitleProfile(): 
    Format({}), 
    Method((OAISubtitleDeliveryMethod)0), 
    DidlMode({}), 
    Language({}), 
    Container({}) {}
OAISubtitleProfile::~OAISubtitleProfile() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISyncPlayCommandMessage::OAISyncPlayCommandMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAISyncPlayCommandMessage::~OAISyncPlayCommandMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISyncPlayGroupUpdateCommandMessage::OAISyncPlayGroupUpdateCommandMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAISyncPlayGroupUpdateCommandMessage::~OAISyncPlayGroupUpdateCommandMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAISyncPlayQueueItem::OAISyncPlayQueueItem(): 
    ItemId({}), 
    PlaylistItemId({}) {}
OAISyncPlayQueueItem::~OAISyncPlayQueueItem() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAISyncPlayUserAccessType) {
    switch(in) {
        case in_type::CREATEANDJOINGROUPS: out = "CREATEANDJOINGROUPS"; break;
        case in_type::JOINGROUPS: out = "JOINGROUPS"; break;
        case in_type::NONE: out = "NONE"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAISystemInfo::OAISystemInfo(): 
    LocalAddress({}), 
    ServerName({}), 
    Version({}), 
    ProductName({}), 
    OperatingSystem({}), 
    Id({}), 
    StartupWizardCompleted(false), 
    OperatingSystemDisplayName({}), 
    PackageName({}), 
    HasPendingRestart(false), 
    IsShuttingDown(false), 
    SupportsLibraryMonitor(false), 
    WebSocketPortNumber(0), 
    CompletedInstallations({}), 
    CanSelfRestart(false), 
    CanLaunchWebBrowser(false), 
    ProgramDataPath({}), 
    WebPath({}), 
    ItemsByNamePath({}), 
    CachePath({}), 
    LogPath({}), 
    InternalMetadataPath({}), 
    TranscodingTempPath({}), 
    CastReceiverApplications({}), 
    HasUpdateAvailable(false), 
    EncoderLocation({}), 
    SystemArchitecture({}) {}
OAISystemInfo::~OAISystemInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAITaskCompletionStatus) {
    switch(in) {
        case in_type::COMPLETED: out = "COMPLETED"; break;
        case in_type::FAILED: out = "FAILED"; break;
        case in_type::CANCELLED: out = "CANCELLED"; break;
        case in_type::ABORTED: out = "ABORTED"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAITaskInfo::OAITaskInfo(): 
    Name({}), 
    State((OAITaskState)0), 
    CurrentProgressPercentage(0.0), 
    Id({}), 
    LastExecutionResult({}), 
    Triggers({}), 
    Description({}), 
    Category({}), 
    IsHidden(false), 
    Key({}) {}
OAITaskInfo::~OAITaskInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAITaskResult::OAITaskResult(): 
    StartTimeUtc({}), 
    EndTimeUtc({}), 
    Status((OAITaskCompletionStatus)0), 
    Name({}), 
    Key({}), 
    Id({}), 
    ErrorMessage({}), 
    LongErrorMessage({}) {}
OAITaskResult::~OAITaskResult() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAITaskState) {
    switch(in) {
        case in_type::IDLE: out = "IDLE"; break;
        case in_type::CANCELLING: out = "CANCELLING"; break;
        case in_type::RUNNING: out = "RUNNING"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAITaskTriggerInfo::OAITaskTriggerInfo(): 
    Type({}), 
    TimeOfDayTicks(0L), 
    IntervalTicks(0L), 
    DayOfWeek((OAIDayOfWeek)0), 
    MaxRuntimeTicks(0L) {}
OAITaskTriggerInfo::~OAITaskTriggerInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIThemeMediaResult::OAIThemeMediaResult(): 
    Items({}), 
    TotalRecordCount(0), 
    StartIndex(0), 
    OwnerId({}) {}
OAIThemeMediaResult::~OAIThemeMediaResult() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAITimerCancelledMessage::OAITimerCancelledMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAITimerCancelledMessage::~OAITimerCancelledMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAITimerCreatedMessage::OAITimerCreatedMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAITimerCreatedMessage::~OAITimerCreatedMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAITimerEventInfo::OAITimerEventInfo(): 
    Id({}), 
    ProgramId({}) {}
OAITimerEventInfo::~OAITimerEventInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAITimerInfoDto::OAITimerInfoDto(): 
    Id({}), 
    Type({}), 
    ServerId({}), 
    ExternalId({}), 
    ChannelId({}), 
    ExternalChannelId({}), 
    ChannelName({}), 
    ChannelPrimaryImageTag({}), 
    ProgramId({}), 
    ExternalProgramId({}), 
    Name({}), 
    Overview({}), 
    StartDate({}), 
    EndDate({}), 
    ServiceName({}), 
    Priority(0), 
    PrePaddingSeconds(0), 
    PostPaddingSeconds(0), 
    IsPrePaddingRequired(false), 
    ParentBackdropItemId({}), 
    ParentBackdropImageTags({}), 
    IsPostPaddingRequired(false), 
    KeepUntil((OAIKeepUntil)0), 
    Status((OAIRecordingStatus)0), 
    SeriesTimerId({}), 
    ExternalSeriesTimerId({}), 
    RunTimeTicks(0L), 
    ProgramInfo({}) {}
OAITimerInfoDto::~OAITimerInfoDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAITimerInfoDtoQueryResult::OAITimerInfoDtoQueryResult(): 
    Items({}), 
    TotalRecordCount(0), 
    StartIndex(0) {}
OAITimerInfoDtoQueryResult::~OAITimerInfoDtoQueryResult() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAITrailerInfo::OAITrailerInfo(): 
    Name({}), 
    OriginalTitle({}), 
    Path({}), 
    MetadataLanguage({}), 
    MetadataCountryCode({}), 
    ProviderIds({}), 
    Year(0), 
    IndexNumber(0), 
    ParentIndexNumber(0), 
    PremiereDate({}), 
    IsAutomated(false) {}
OAITrailerInfo::~OAITrailerInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAITrailerInfoRemoteSearchQuery::OAITrailerInfoRemoteSearchQuery(): 
    SearchInfo({}), 
    ItemId({}), 
    SearchProviderName({}), 
    IncludeDisabledProviders(false) {}
OAITrailerInfoRemoteSearchQuery::~OAITrailerInfoRemoteSearchQuery() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAITranscodeReason) {
    switch(in) {
        case in_type::CONTAINERNOTSUPPORTED: out = "CONTAINERNOTSUPPORTED"; break;
        case in_type::VIDEOCODECNOTSUPPORTED: out = "VIDEOCODECNOTSUPPORTED"; break;
        case in_type::AUDIOCODECNOTSUPPORTED: out = "AUDIOCODECNOTSUPPORTED"; break;
        case in_type::SUBTITLECODECNOTSUPPORTED: out = "SUBTITLECODECNOTSUPPORTED"; break;
        case in_type::AUDIOISEXTERNAL: out = "AUDIOISEXTERNAL"; break;
        case in_type::SECONDARYAUDIONOTSUPPORTED: out = "SECONDARYAUDIONOTSUPPORTED"; break;
        case in_type::VIDEOPROFILENOTSUPPORTED: out = "VIDEOPROFILENOTSUPPORTED"; break;
        case in_type::VIDEOLEVELNOTSUPPORTED: out = "VIDEOLEVELNOTSUPPORTED"; break;
        case in_type::VIDEORESOLUTIONNOTSUPPORTED: out = "VIDEORESOLUTIONNOTSUPPORTED"; break;
        case in_type::VIDEOBITDEPTHNOTSUPPORTED: out = "VIDEOBITDEPTHNOTSUPPORTED"; break;
        case in_type::VIDEOFRAMERATENOTSUPPORTED: out = "VIDEOFRAMERATENOTSUPPORTED"; break;
        case in_type::REFFRAMESNOTSUPPORTED: out = "REFFRAMESNOTSUPPORTED"; break;
        case in_type::ANAMORPHICVIDEONOTSUPPORTED: out = "ANAMORPHICVIDEONOTSUPPORTED"; break;
        case in_type::INTERLACEDVIDEONOTSUPPORTED: out = "INTERLACEDVIDEONOTSUPPORTED"; break;
        case in_type::AUDIOCHANNELSNOTSUPPORTED: out = "AUDIOCHANNELSNOTSUPPORTED"; break;
        case in_type::AUDIOPROFILENOTSUPPORTED: out = "AUDIOPROFILENOTSUPPORTED"; break;
        case in_type::AUDIOSAMPLERATENOTSUPPORTED: out = "AUDIOSAMPLERATENOTSUPPORTED"; break;
        case in_type::AUDIOBITDEPTHNOTSUPPORTED: out = "AUDIOBITDEPTHNOTSUPPORTED"; break;
        case in_type::CONTAINERBITRATEEXCEEDSLIMIT: out = "CONTAINERBITRATEEXCEEDSLIMIT"; break;
        case in_type::VIDEOBITRATENOTSUPPORTED: out = "VIDEOBITRATENOTSUPPORTED"; break;
        case in_type::AUDIOBITRATENOTSUPPORTED: out = "AUDIOBITRATENOTSUPPORTED"; break;
        case in_type::UNKNOWNVIDEOSTREAMINFO: out = "UNKNOWNVIDEOSTREAMINFO"; break;
        case in_type::UNKNOWNAUDIOSTREAMINFO: out = "UNKNOWNAUDIOSTREAMINFO"; break;
        case in_type::DIRECTPLAYERROR: out = "DIRECTPLAYERROR"; break;
        case in_type::VIDEORANGETYPENOTSUPPORTED: out = "VIDEORANGETYPENOTSUPPORTED"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAITranscodeSeekInfo) {
    switch(in) {
        case in_type::AUTO: out = "AUTO"; break;
        case in_type::BYTES: out = "BYTES"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAITranscodingInfo::OAITranscodingInfo(): 
    AudioCodec({}), 
    VideoCodec({}), 
    Container({}), 
    IsVideoDirect(false), 
    IsAudioDirect(false), 
    Bitrate(0), 
    Framerate(0.0f), 
    CompletionPercentage(0.0), 
    Width(0), 
    Height(0), 
    AudioChannels(0), 
    HardwareAccelerationType((OAIHardwareEncodingType)0), 
    TranscodeReasons({}) {}
OAITranscodingInfo::~OAITranscodingInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAITranscodingProfile::OAITranscodingProfile(): 
    Container({}), 
    Type((OAIDlnaProfileType)0), 
    VideoCodec({}), 
    AudioCodec({}), 
    Protocol((OAIMediaStreamProtocol)0), 
    EstimateContentLength(false), 
    EnableMpegtsM2TsMode(false), 
    TranscodeSeekInfo((OAITranscodeSeekInfo)0), 
    CopyTimestamps(false), 
    Context((OAIEncodingContext)0), 
    EnableSubtitlesInManifest(false), 
    MaxAudioChannels({}), 
    MinSegments(0), 
    SegmentLength(0), 
    BreakOnNonKeyFrames(false), 
    Conditions({}) {}
OAITranscodingProfile::~OAITranscodingProfile() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAITransportStreamTimestamp) {
    switch(in) {
        case in_type::NONE: out = "NONE"; break;
        case in_type::ZERO: out = "ZERO"; break;
        case in_type::VALID: out = "VALID"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAITrickplayInfo::OAITrickplayInfo(): 
    Width(0), 
    Height(0), 
    TileWidth(0), 
    TileHeight(0), 
    ThumbnailCount(0), 
    Interval(0), 
    Bandwidth(0) {}
OAITrickplayInfo::~OAITrickplayInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAITrickplayOptions::OAITrickplayOptions(): 
    EnableHwAcceleration(false), 
    EnableHwEncoding(false), 
    ScanBehavior((OAITrickplayScanBehavior)0), 
    ProcessPriority((OAIProcessPriorityClass)0), 
    Interval(0), 
    WidthResolutions({}), 
    TileWidth(0), 
    TileHeight(0), 
    Qscale(0), 
    JpegQuality(0), 
    ProcessThreads(0) {}
OAITrickplayOptions::~OAITrickplayOptions() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAITrickplayScanBehavior) {
    switch(in) {
        case in_type::BLOCKING: out = "BLOCKING"; break;
        case in_type::NONBLOCKING: out = "NONBLOCKING"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAITunerChannelMapping::OAITunerChannelMapping(): 
    Name({}), 
    ProviderChannelName({}), 
    ProviderChannelId({}), 
    Id({}) {}
OAITunerChannelMapping::~OAITunerChannelMapping() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAITunerHostInfo::OAITunerHostInfo(): 
    Id({}), 
    Url({}), 
    Type({}), 
    DeviceId({}), 
    FriendlyName({}), 
    ImportFavoritesOnly(false), 
    AllowHWTranscoding(false), 
    EnableStreamLooping(false), 
    Source({}), 
    TunerCount(0), 
    UserAgent({}), 
    IgnoreDts(false) {}
OAITunerHostInfo::~OAITunerHostInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAITypeOptions::OAITypeOptions(): 
    Type({}), 
    MetadataFetchers({}), 
    MetadataFetcherOrder({}), 
    ImageFetchers({}), 
    ImageFetcherOrder({}), 
    ImageOptions({}) {}
OAITypeOptions::~OAITypeOptions() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIUnratedItem) {
    switch(in) {
        case in_type::MOVIE: out = "MOVIE"; break;
        case in_type::TRAILER: out = "TRAILER"; break;
        case in_type::SERIES: out = "SERIES"; break;
        case in_type::MUSIC: out = "MUSIC"; break;
        case in_type::BOOK: out = "BOOK"; break;
        case in_type::LIVETVCHANNEL: out = "LIVETVCHANNEL"; break;
        case in_type::LIVETVPROGRAM: out = "LIVETVPROGRAM"; break;
        case in_type::CHANNELCONTENT: out = "CHANNELCONTENT"; break;
        case in_type::OTHER: out = "OTHER"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIUpdateLibraryOptionsDto::OAIUpdateLibraryOptionsDto(): 
    Id({}), 
    LibraryOptions({}) {}
OAIUpdateLibraryOptionsDto::~OAIUpdateLibraryOptionsDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIUpdateMediaPathRequestDto::OAIUpdateMediaPathRequestDto(): 
    Name({}), 
    PathInfo({}) {}
OAIUpdateMediaPathRequestDto::~OAIUpdateMediaPathRequestDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIUpdatePlaylistDto::OAIUpdatePlaylistDto(): 
    Name({}), 
    Ids({}), 
    Users({}), 
    IsPublic(false) {}
OAIUpdatePlaylistDto::~OAIUpdatePlaylistDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIUpdatePlaylistUserDto::OAIUpdatePlaylistUserDto(): 
    CanEdit(false) {}
OAIUpdatePlaylistUserDto::~OAIUpdatePlaylistUserDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIUpdateUserItemDataDto::OAIUpdateUserItemDataDto(): 
    Rating(0.0), 
    PlayedPercentage(0.0), 
    UnplayedItemCount(0), 
    PlaybackPositionTicks(0L), 
    PlayCount(0), 
    IsFavorite(false), 
    Likes(false), 
    LastPlayedDate({}), 
    Played(false), 
    Key({}), 
    ItemId({}) {}
OAIUpdateUserItemDataDto::~OAIUpdateUserItemDataDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIUpdateUserPassword::OAIUpdateUserPassword(): 
    CurrentPassword({}), 
    CurrentPw({}), 
    NewPw({}), 
    ResetPassword(false) {}
OAIUpdateUserPassword::~OAIUpdateUserPassword() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIUploadSubtitleDto::OAIUploadSubtitleDto(): 
    Language({}), 
    Format({}), 
    IsForced(false), 
    IsHearingImpaired(false), 
    Data({}) {}
OAIUploadSubtitleDto::~OAIUploadSubtitleDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIUserConfiguration::OAIUserConfiguration(): 
    AudioLanguagePreference({}), 
    PlayDefaultAudioTrack(false), 
    SubtitleLanguagePreference({}), 
    DisplayMissingEpisodes(false), 
    GroupedFolders({}), 
    SubtitleMode((OAISubtitlePlaybackMode)0), 
    DisplayCollectionsView(false), 
    EnableLocalPassword(false), 
    OrderedViews({}), 
    LatestItemsExcludes({}), 
    MyMediaExcludes({}), 
    HidePlayedInLatest(false), 
    RememberAudioSelections(false), 
    RememberSubtitleSelections(false), 
    EnableNextEpisodeAutoPlay(false), 
    CastReceiverId({}) {}
OAIUserConfiguration::~OAIUserConfiguration() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIUserDataChangeInfo::OAIUserDataChangeInfo(): 
    UserId({}), 
    UserDataList({}) {}
OAIUserDataChangeInfo::~OAIUserDataChangeInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIUserDataChangedMessage::OAIUserDataChangedMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIUserDataChangedMessage::~OAIUserDataChangedMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIUserDeletedMessage::OAIUserDeletedMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIUserDeletedMessage::~OAIUserDeletedMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIUserDto::OAIUserDto(): 
    Name({}), 
    ServerId({}), 
    ServerName({}), 
    Id({}), 
    PrimaryImageTag({}), 
    HasPassword(false), 
    HasConfiguredPassword(false), 
    HasConfiguredEasyPassword(false), 
    EnableAutoLogin(false), 
    LastLoginDate({}), 
    LastActivityDate({}), 
    Configuration({}), 
    Policy({}), 
    PrimaryImageAspectRatio(0.0) {}
OAIUserDto::~OAIUserDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIUserItemDataDto::OAIUserItemDataDto(): 
    Rating(0.0), 
    PlayedPercentage(0.0), 
    UnplayedItemCount(0), 
    PlaybackPositionTicks(0L), 
    PlayCount(0), 
    IsFavorite(false), 
    Likes(false), 
    LastPlayedDate({}), 
    Played(false), 
    Key({}), 
    ItemId({}) {}
OAIUserItemDataDto::~OAIUserItemDataDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIUserPolicy::OAIUserPolicy(): 
    IsAdministrator(false), 
    IsHidden(false), 
    EnableCollectionManagement(false), 
    EnableSubtitleManagement(false), 
    EnableLyricManagement(false), 
    IsDisabled(false), 
    MaxParentalRating(0), 
    BlockedTags({}), 
    AllowedTags({}), 
    EnableUserPreferenceAccess(false), 
    AccessSchedules({}), 
    BlockUnratedItems({}), 
    EnableRemoteControlOfOtherUsers(false), 
    EnableSharedDeviceControl(false), 
    EnableRemoteAccess(false), 
    EnableLiveTvManagement(false), 
    EnableLiveTvAccess(false), 
    EnableMediaPlayback(false), 
    EnableAudioPlaybackTranscoding(false), 
    EnableVideoPlaybackTranscoding(false), 
    EnablePlaybackRemuxing(false), 
    ForceRemoteSourceTranscoding(false), 
    EnableContentDeletion(false), 
    EnableContentDeletionFromFolders({}), 
    EnableContentDownloading(false), 
    EnableSyncTranscoding(false), 
    EnableMediaConversion(false), 
    EnabledDevices({}), 
    EnableAllDevices(false), 
    EnabledChannels({}), 
    EnableAllChannels(false), 
    EnabledFolders({}), 
    EnableAllFolders(false), 
    InvalidLoginAttemptCount(0), 
    LoginAttemptsBeforeLockout(0), 
    MaxActiveSessions(0), 
    EnablePublicSharing(false), 
    BlockedMediaFolders({}), 
    BlockedChannels({}), 
    RemoteClientBitrateLimit(0), 
    AuthenticationProviderId({}), 
    PasswordResetProviderId({}), 
    SyncPlayAccess((OAISyncPlayUserAccessType)0) {}
OAIUserPolicy::~OAIUserPolicy() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIUserUpdatedMessage::OAIUserUpdatedMessage(): 
    Data({}), 
    MessageId({}), 
    MessageType((OAISessionMessageType)0) {}
OAIUserUpdatedMessage::~OAIUserUpdatedMessage() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIUtcTimeResponse::OAIUtcTimeResponse(): 
    RequestReceptionTime({}), 
    ResponseTransmissionTime({}) {}
OAIUtcTimeResponse::~OAIUtcTimeResponse() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIValidatePathDto::OAIValidatePathDto(): 
    ValidateWritable(false), 
    Path({}), 
    IsFile(false) {}
OAIValidatePathDto::~OAIValidatePathDto() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIVersionInfo::OAIVersionInfo(): 
    version({}), 
    VersionNumber({}), 
    changelog({}), 
    targetAbi({}), 
    sourceUrl({}), 
    checksum({}), 
    timestamp({}), 
    repositoryName({}), 
    repositoryUrl({}) {}
OAIVersionInfo::~OAIVersionInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIVideo3DFormat) {
    switch(in) {
        case in_type::HALFSIDEBYSIDE: out = "HALFSIDEBYSIDE"; break;
        case in_type::FULLSIDEBYSIDE: out = "FULLSIDEBYSIDE"; break;
        case in_type::FULLTOPANDBOTTOM: out = "FULLTOPANDBOTTOM"; break;
        case in_type::HALFTOPANDBOTTOM: out = "HALFTOPANDBOTTOM"; break;
        case in_type::MVC: out = "MVC"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIVideoRange) {
    switch(in) {
        case in_type::UNKNOWN: out = "UNKNOWN"; break;
        case in_type::SDR: out = "SDR"; break;
        case in_type::HDR: out = "HDR"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIVideoRangeType) {
    switch(in) {
        case in_type::UNKNOWN: out = "UNKNOWN"; break;
        case in_type::SDR: out = "SDR"; break;
        case in_type::HDR10: out = "HDR10"; break;
        case in_type::HLG: out = "HLG"; break;
        case in_type::DOVI: out = "DOVI"; break;
        case in_type::DOVIWITHHDR10: out = "DOVIWITHHDR10"; break;
        case in_type::DOVIWITHHLG: out = "DOVIWITHHLG"; break;
        case in_type::DOVIWITHSDR: out = "DOVIWITHSDR"; break;
        case in_type::HDR10PLUS: out = "HDR10PLUS"; break;
        default: break;
    }
}


namespace jellyfin::model {
 
} // namespace jellyfin::model

IMPL_CONVERT(std::string, jellyfin::model::OAIVideoType) {
    switch(in) {
        case in_type::VIDEOFILE: out = "VIDEOFILE"; break;
        case in_type::ISO: out = "ISO"; break;
        case in_type::DVD: out = "DVD"; break;
        case in_type::BLURAY: out = "BLURAY"; break;
        default: break;
    }
}


namespace jellyfin::model {

OAIVirtualFolderInfo::OAIVirtualFolderInfo(): 
    Name({}), 
    Locations({}), 
    CollectionType((OAICollectionTypeOptions)0), 
    LibraryOptions({}), 
    ItemId({}), 
    PrimaryImageItemId({}), 
    RefreshProgress(0.0), 
    RefreshStatus({}) {}
OAIVirtualFolderInfo::~OAIVirtualFolderInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

OAIWakeOnLanInfo::OAIWakeOnLanInfo(): 
    MacAddress({}), 
    Port(0) {}
OAIWakeOnLanInfo::~OAIWakeOnLanInfo() {}
 
} // namespace jellyfin::model



namespace jellyfin::model {

} // namespace jellyfin::model



namespace jellyfin::model {

OAIXbmcMetadataOptions::OAIXbmcMetadataOptions(): 
    UserId({}), 
    ReleaseDateFormat({}), 
    SaveImagePathsInNfo(false), 
    EnablePathSubstitution(false), 
    EnableExtraThumbsDuplication(false) {}
OAIXbmcMetadataOptions::~OAIXbmcMetadataOptions() {}
 
} // namespace jellyfin::model


