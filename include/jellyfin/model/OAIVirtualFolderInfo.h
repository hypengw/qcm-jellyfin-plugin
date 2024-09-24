#pragma once

/*
 * OAIVirtualFolderInfo.h
 * name: VirtualFolderInfo
 * schemaName: VirtualFolderInfo
 * classFilename: VirtualFolderInfo
 * classVarName: VirtualFolderInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Used to hold information about a user&#39;s list of configured virtual folders.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAICollectionTypeOptions.h"
#include "jellyfin/model/OAILibraryOptions.h"
#include <string>
#include <vector>



namespace jellyfin::model {
class OAILibraryOptions;


    class OAIVirtualFolderInfo {
    public:
    
        // Gets or sets the name.
        std::optional<std::string> Name;

        // Gets or sets the locations.
        std::optional<std::vector<std::string>> Locations;

        // Gets or sets the type of the collection.
        std::optional<OAICollectionTypeOptions> CollectionType;

        std::optional<OAILibraryOptions> LibraryOptions;

        // Gets or sets the item identifier.
        std::optional<std::string> ItemId;

        // Gets or sets the primary image item identifier.
        std::optional<std::string> PrimaryImageItemId;

        std::optional<double> RefreshProgress;

        std::optional<std::string> RefreshStatus;

        OAIVirtualFolderInfo();
        ~OAIVirtualFolderInfo();
    };
    extern void to_json(json_t&, const OAIVirtualFolderInfo&);
    extern void from_json(const json_t&, OAIVirtualFolderInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIVirtualFolderInfo);
