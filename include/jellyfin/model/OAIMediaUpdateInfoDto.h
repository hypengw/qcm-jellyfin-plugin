#pragma once

/*
 * OAIMediaUpdateInfoDto.h
 * name: MediaUpdateInfoDto
 * schemaName: MediaUpdateInfoDto
 * classFilename: MediaUpdateInfoDto
 * classVarName: MediaUpdateInfoDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Media Update Info Dto.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIMediaUpdateInfoPathDto.h"
#include <vector>



namespace jellyfin::model {
class OAIMediaUpdateInfoPathDto;


    class OAIMediaUpdateInfoDto {
    public:
    
        // Gets or sets the list of updates.
        std::vector<OAIMediaUpdateInfoPathDto> Updates;

        OAIMediaUpdateInfoDto();
        ~OAIMediaUpdateInfoDto();
    };
    extern void to_json(json_t&, const OAIMediaUpdateInfoDto&);
    extern void from_json(const json_t&, OAIMediaUpdateInfoDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMediaUpdateInfoDto);
