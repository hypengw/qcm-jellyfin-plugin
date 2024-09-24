#pragma once

/*
 * OAIClientLogDocumentResponseDto.h
 * name: ClientLogDocumentResponseDto
 * schemaName: ClientLogDocumentResponseDto
 * classFilename: ClientLogDocumentResponseDto
 * classVarName: ClientLogDocumentResponseDto
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Client log document response dto.
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAIClientLogDocumentResponseDto {
    public:
    
        // Gets the resulting filename.
        std::string FileName;

        OAIClientLogDocumentResponseDto();
        ~OAIClientLogDocumentResponseDto();
    };
    extern void to_json(json_t&, const OAIClientLogDocumentResponseDto&);
    extern void from_json(const json_t&, OAIClientLogDocumentResponseDto&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIClientLogDocumentResponseDto);
