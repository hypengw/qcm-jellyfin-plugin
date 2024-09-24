#pragma once

/*
 * OAISetShuffleModeRequestDto.h
 * name: SetShuffleModeRequestDto
 * schemaName: SetShuffleModeRequestDto
 * classFilename: SetShuffleModeRequestDto
 * classVarName: SetShuffleModeRequestDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class SetShuffleModeRequestDto.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIGroupShuffleMode.h"



namespace jellyfin::model {


    class OAISetShuffleModeRequestDto {
    public:
    
        // Gets or sets the shuffle mode.
        OAIGroupShuffleMode Mode;

        OAISetShuffleModeRequestDto();
        ~OAISetShuffleModeRequestDto();
    };
    extern void to_json(json_t&, const OAISetShuffleModeRequestDto&);
    extern void from_json(const json_t&, OAISetShuffleModeRequestDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISetShuffleModeRequestDto);
