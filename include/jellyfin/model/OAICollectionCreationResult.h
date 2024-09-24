#pragma once

/*
 * OAICollectionCreationResult.h
 * name: CollectionCreationResult
 * schemaName: CollectionCreationResult
 * classFilename: CollectionCreationResult
 * classVarName: CollectionCreationResult
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include <string>



namespace jellyfin::model {


    class OAICollectionCreationResult {
    public:
    
        std::string Id;

        OAICollectionCreationResult();
        ~OAICollectionCreationResult();
    };
    extern void to_json(json_t&, const OAICollectionCreationResult&);
    extern void from_json(const json_t&, OAICollectionCreationResult&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAICollectionCreationResult);
