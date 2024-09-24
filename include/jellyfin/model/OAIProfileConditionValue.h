#pragma once

/*
 * OAIProfileConditionValue.h
 * name: ProfileConditionValue
 * schemaName: ProfileConditionValue
 * classFilename: ProfileConditionValue
 * classVarName: ProfileConditionValue
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIProfileConditionValue {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        AUDIOCHANNELS, // AudioChannels
        AUDIOBITRATE, // AudioBitrate
        AUDIOPROFILE, // AudioProfile
        WIDTH, // Width
        HEIGHT, // Height
        HAS64BITOFFSETS, // Has64BitOffsets
        PACKETLENGTH, // PacketLength
        VIDEOBITDEPTH, // VideoBitDepth
        VIDEOBITRATE, // VideoBitrate
        VIDEOFRAMERATE, // VideoFramerate
        VIDEOLEVEL, // VideoLevel
        VIDEOPROFILE, // VideoProfile
        VIDEOTIMESTAMP, // VideoTimestamp
        ISANAMORPHIC, // IsAnamorphic
        REFFRAMES, // RefFrames
        NUMAUDIOSTREAMS, // NumAudioStreams
        NUMVIDEOSTREAMS, // NumVideoStreams
        ISSECONDARYAUDIO, // IsSecondaryAudio
        VIDEOCODECTAG, // VideoCodecTag
        ISAVC, // IsAvc
        ISINTERLACED, // IsInterlaced
        AUDIOSAMPLERATE, // AudioSampleRate
        AUDIOBITDEPTH, // AudioBitDepth
        VIDEORANGETYPE, // VideoRangeType
    };
    extern void to_json(json_t&, const OAIProfileConditionValue&);
    extern void from_json(const json_t&, OAIProfileConditionValue&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIProfileConditionValue);
