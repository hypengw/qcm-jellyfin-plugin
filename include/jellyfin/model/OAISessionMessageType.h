#pragma once

/*
 * OAISessionMessageType.h
 * name: SessionMessageType
 * schemaName: SessionMessageType
 * classFilename: SessionMessageType
 * classVarName: SessionMessageType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * The different kinds of messages that are used in the WebSocket api.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAISessionMessageType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        FORCEKEEPALIVE, // ForceKeepAlive
        GENERALCOMMAND, // GeneralCommand
        USERDATACHANGED, // UserDataChanged
        SESSIONS, // Sessions
        PLAY, // Play
        SYNCPLAYCOMMAND, // SyncPlayCommand
        SYNCPLAYGROUPUPDATE, // SyncPlayGroupUpdate
        PLAYSTATE, // Playstate
        RESTARTREQUIRED, // RestartRequired
        SERVERSHUTTINGDOWN, // ServerShuttingDown
        SERVERRESTARTING, // ServerRestarting
        LIBRARYCHANGED, // LibraryChanged
        USERDELETED, // UserDeleted
        USERUPDATED, // UserUpdated
        SERIESTIMERCREATED, // SeriesTimerCreated
        TIMERCREATED, // TimerCreated
        SERIESTIMERCANCELLED, // SeriesTimerCancelled
        TIMERCANCELLED, // TimerCancelled
        REFRESHPROGRESS, // RefreshProgress
        SCHEDULEDTASKENDED, // ScheduledTaskEnded
        PACKAGEINSTALLATIONCANCELLED, // PackageInstallationCancelled
        PACKAGEINSTALLATIONFAILED, // PackageInstallationFailed
        PACKAGEINSTALLATIONCOMPLETED, // PackageInstallationCompleted
        PACKAGEINSTALLING, // PackageInstalling
        PACKAGEUNINSTALLED, // PackageUninstalled
        ACTIVITYLOGENTRY, // ActivityLogEntry
        SCHEDULEDTASKSINFO, // ScheduledTasksInfo
        ACTIVITYLOGENTRYSTART, // ActivityLogEntryStart
        ACTIVITYLOGENTRYSTOP, // ActivityLogEntryStop
        SESSIONSSTART, // SessionsStart
        SESSIONSSTOP, // SessionsStop
        SCHEDULEDTASKSINFOSTART, // ScheduledTasksInfoStart
        SCHEDULEDTASKSINFOSTOP, // ScheduledTasksInfoStop
        KEEPALIVE, // KeepAlive
    };
    extern void to_json(json_t&, const OAISessionMessageType&);
    extern void from_json(const json_t&, OAISessionMessageType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISessionMessageType);
