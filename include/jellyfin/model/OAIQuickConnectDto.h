#pragma once

/*
 * OAIQuickConnectDto.h
 * name: QuickConnectDto
 * schemaName: QuickConnectDto
 * classFilename: QuickConnectDto
 * classVarName: QuickConnectDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * The quick connect request body.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAIQuickConnectDto {
    public:
    
        // Gets or sets the quick connect secret.
        std::string Secret;

        OAIQuickConnectDto();
        ~OAIQuickConnectDto();
    };
    extern void to_json(json_t&, const OAIQuickConnectDto&);
    extern void from_json(const json_t&, OAIQuickConnectDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIQuickConnectDto);
