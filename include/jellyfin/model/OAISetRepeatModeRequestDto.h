#pragma once

/*
 * OAISetRepeatModeRequestDto.h
 * name: SetRepeatModeRequestDto
 * schemaName: SetRepeatModeRequestDto
 * classFilename: SetRepeatModeRequestDto
 * classVarName: SetRepeatModeRequestDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class SetRepeatModeRequestDto.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIGroupRepeatMode.h"



namespace jellyfin::model {


    class OAISetRepeatModeRequestDto {
    public:
    
        // Gets or sets the repeat mode.
        OAIGroupRepeatMode Mode;

        OAISetRepeatModeRequestDto();
        ~OAISetRepeatModeRequestDto();
    };
    extern void to_json(json_t&, const OAISetRepeatModeRequestDto&);
    extern void from_json(const json_t&, OAISetRepeatModeRequestDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAISetRepeatModeRequestDto);
