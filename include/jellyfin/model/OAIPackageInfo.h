#pragma once

/*
 * OAIPackageInfo.h
 * name: PackageInfo
 * schemaName: PackageInfo
 * classFilename: PackageInfo
 * classVarName: PackageInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class PackageInfo.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIVersionInfo.h"
#include <string>
#include <vector>



namespace jellyfin::model {
class OAIVersionInfo;


    class OAIPackageInfo {
    public:
    
        // Gets or sets the name.
        std::string name;

        // Gets or sets a long description of the plugin containing features or helpful explanations.
        std::string description;

        // Gets or sets a short overview of what the plugin does.
        std::string overview;

        // Gets or sets the owner.
        std::string owner;

        // Gets or sets the category.
        std::string category;

        // Gets or sets the guid of the assembly associated with this plugin.  This is used to identify the proper item for automatic updates.
        std::string guid;

        // Gets or sets the versions.
        std::vector<OAIVersionInfo> versions;

        // Gets or sets the image url for the package.
        std::optional<std::string> imageUrl;

        OAIPackageInfo();
        ~OAIPackageInfo();
    };
    extern void to_json(json_t&, const OAIPackageInfo&);
    extern void from_json(const json_t&, OAIPackageInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPackageInfo);
