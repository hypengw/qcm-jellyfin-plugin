#pragma once

/*
 * OAIGeneralCommandType.h
 * name: GeneralCommandType
 * schemaName: GeneralCommandType
 * classFilename: GeneralCommandType
 * classVarName: GeneralCommandType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * This exists simply to identify a set of known commands.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIGeneralCommandType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        MOVEUP, // MoveUp
        MOVEDOWN, // MoveDown
        MOVELEFT, // MoveLeft
        MOVERIGHT, // MoveRight
        PAGEUP, // PageUp
        PAGEDOWN, // PageDown
        PREVIOUSLETTER, // PreviousLetter
        NEXTLETTER, // NextLetter
        TOGGLEOSD, // ToggleOsd
        TOGGLECONTEXTMENU, // ToggleContextMenu
        SELECT, // Select
        BACK, // Back
        TAKESCREENSHOT, // TakeScreenshot
        SENDKEY, // SendKey
        SENDSTRING, // SendString
        GOHOME, // GoHome
        GOTOSETTINGS, // GoToSettings
        VOLUMEUP, // VolumeUp
        VOLUMEDOWN, // VolumeDown
        MUTE, // Mute
        UNMUTE, // Unmute
        TOGGLEMUTE, // ToggleMute
        SETVOLUME, // SetVolume
        SETAUDIOSTREAMINDEX, // SetAudioStreamIndex
        SETSUBTITLESTREAMINDEX, // SetSubtitleStreamIndex
        TOGGLEFULLSCREEN, // ToggleFullscreen
        DISPLAYCONTENT, // DisplayContent
        GOTOSEARCH, // GoToSearch
        DISPLAYMESSAGE, // DisplayMessage
        SETREPEATMODE, // SetRepeatMode
        CHANNELUP, // ChannelUp
        CHANNELDOWN, // ChannelDown
        GUIDE, // Guide
        TOGGLESTATS, // ToggleStats
        PLAYMEDIASOURCE, // PlayMediaSource
        PLAYTRAILERS, // PlayTrailers
        SETSHUFFLEQUEUE, // SetShuffleQueue
        PLAYSTATE, // PlayState
        PLAYNEXT, // PlayNext
        TOGGLEOSDMENU, // ToggleOsdMenu
        PLAY, // Play
        SETMAXSTREAMINGBITRATE, // SetMaxStreamingBitrate
        SETPLAYBACKORDER, // SetPlaybackOrder
    };
    extern void to_json(json_t&, const OAIGeneralCommandType&);
    extern void from_json(const json_t&, OAIGeneralCommandType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIGeneralCommandType);
