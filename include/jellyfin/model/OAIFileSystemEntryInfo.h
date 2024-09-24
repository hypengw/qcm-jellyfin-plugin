#pragma once

/*
 * OAIFileSystemEntryInfo.h
 * name: FileSystemEntryInfo
 * schemaName: FileSystemEntryInfo
 * classFilename: FileSystemEntryInfo
 * classVarName: FileSystemEntryInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class FileSystemEntryInfo.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIFileSystemEntryType.h"
#include <string>



namespace jellyfin::model {


    class OAIFileSystemEntryInfo {
    public:
    
        // Gets the name.
        std::string Name;

        // Gets the path.
        std::string Path;

        // Gets the type.
        OAIFileSystemEntryType Type;

        OAIFileSystemEntryInfo();
        ~OAIFileSystemEntryInfo();
    };
    extern void to_json(json_t&, const OAIFileSystemEntryInfo&);
    extern void from_json(const json_t&, OAIFileSystemEntryInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIFileSystemEntryInfo);
