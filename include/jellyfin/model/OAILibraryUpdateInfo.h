#pragma once

/*
 * OAILibraryUpdateInfo.h
 * name: LibraryUpdateInfo
 * schemaName: LibraryUpdateInfo
 * classFilename: LibraryUpdateInfo
 * classVarName: LibraryUpdateInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class LibraryUpdateInfo.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {


    class OAILibraryUpdateInfo {
    public:
    
        // Gets or sets the folders added to.
        std::vector<std::string> FoldersAddedTo;

        // Gets or sets the folders removed from.
        std::vector<std::string> FoldersRemovedFrom;

        // Gets or sets the items added.
        std::vector<std::string> ItemsAdded;

        // Gets or sets the items removed.
        std::vector<std::string> ItemsRemoved;

        // Gets or sets the items updated.
        std::vector<std::string> ItemsUpdated;

        std::vector<std::string> CollectionFolders;

        bool IsEmpty;

        OAILibraryUpdateInfo();
        ~OAILibraryUpdateInfo();
    };
    extern void to_json(json_t&, const OAILibraryUpdateInfo&);
    extern void from_json(const json_t&, OAILibraryUpdateInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAILibraryUpdateInfo);
