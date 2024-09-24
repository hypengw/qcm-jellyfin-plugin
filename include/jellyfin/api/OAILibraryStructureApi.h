#pragma once
/*
 * OAILibraryStructureApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIAddVirtualFolderDto.h"
#include "jellyfin/model/OAICollectionTypeOptions.h"
#include "jellyfin/model/OAIMediaPathDto.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAIUpdateLibraryOptionsDto.h"
#include "jellyfin/model/OAIUpdateMediaPathRequestDto.h"
#include "jellyfin/model/OAIVirtualFolderInfo.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_addMediaPath = std::nullptr_t;
using return_type_addVirtualFolder = std::nullptr_t;
using return_type_getVirtualFolders = std::vector<OAIVirtualFolderInfo>;
using return_type_removeMediaPath = std::nullptr_t;
using return_type_removeVirtualFolder = std::nullptr_t;
using return_type_renameVirtualFolder = std::nullptr_t;
using return_type_updateLibraryOptions = std::nullptr_t;
using return_type_updateMediaPath = std::nullptr_t;
}

namespace api::param 
{
struct addMediaPath {
    OAIMediaPathDto body; // The media path dto.
    std::optional<bool> refreshLibrary; // Whether to refresh the library.
};
struct addVirtualFolder {
    std::optional<std::string> name; // The name of the virtual folder.
    std::optional<OAICollectionTypeOptions> collectionType; // The type of the collection.
    std::optional<std::vector<std::string>> paths; // The paths of the virtual folder.
    std::optional<bool> refreshLibrary; // Whether to refresh the library.
    std::optional<OAIAddVirtualFolderDto> body; // The library options.
};
struct getVirtualFolders {
};
struct removeMediaPath {
    std::optional<std::string> name; // The name of the library.
    std::optional<std::string> path; // The path to remove.
    std::optional<bool> refreshLibrary; // Whether to refresh the library.
};
struct removeVirtualFolder {
    std::optional<std::string> name; // The name of the folder.
    std::optional<bool> refreshLibrary; // Whether to refresh the library.
};
struct renameVirtualFolder {
    std::optional<std::string> name; // The name of the virtual folder.
    std::optional<std::string> newName; // The new name.
    std::optional<bool> refreshLibrary; // Whether to refresh the library.
};
struct updateLibraryOptions {
    std::optional<OAIUpdateLibraryOptionsDto> body; // The library name and options.
};
struct updateMediaPath {
    OAIUpdateMediaPathRequestDto body; // The name of the library and path infos.
};
}

namespace api 
{
// Add a media path to a library.
struct addMediaPath {
public:
    using in_type                      = param::addMediaPath;
    using out_type                     = model::return_type_addMediaPath;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Library/VirtualFolders/Paths"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.refreshLibrary)
            p.set_param("refreshLibrary", convert_from<std::string>(input.refreshLibrary.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: LibraryStructure
 * defaultResponse: 
 */
};
// Adds a virtual folder.
struct addVirtualFolder {
public:
    using in_type                      = param::addVirtualFolder;
    using out_type                     = model::return_type_addVirtualFolder;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Library/VirtualFolders"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.name)
            p.set_param("name", convert_from<std::string>(input.name.value()));
        if(input.collectionType)
            p.set_param("collectionType", convert_from<std::string>(input.collectionType.value()));
        if(input.paths)
            p.set_param("paths", input.paths.value());
        if(input.refreshLibrary)
            p.set_param("refreshLibrary", convert_from<std::string>(input.refreshLibrary.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        if(input.body)
            out = format_param(input.body.value());
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: LibraryStructure
 * defaultResponse: 
 */
};
// Gets all virtual folders.
struct getVirtualFolders {
public:
    using in_type                      = param::getVirtualFolders;
    using out_type                     = model::return_type_getVirtualFolders;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Library/VirtualFolders"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;OAIVirtualFolderInfo&gt;
 * returnFormat: 
 * returnBaseType: OAIVirtualFolderInfo
 * returnContainer: array
 * baseName: LibraryStructure
 * defaultResponse: {}
 */
};
// Remove a media path.
struct removeMediaPath {
public:
    using in_type                      = param::removeMediaPath;
    using out_type                     = model::return_type_removeMediaPath;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return "/Library/VirtualFolders/Paths"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.name)
            p.set_param("name", convert_from<std::string>(input.name.value()));
        if(input.path)
            p.set_param("path", convert_from<std::string>(input.path.value()));
        if(input.refreshLibrary)
            p.set_param("refreshLibrary", convert_from<std::string>(input.refreshLibrary.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: LibraryStructure
 * defaultResponse: 
 */
};
// Removes a virtual folder.
struct removeVirtualFolder {
public:
    using in_type                      = param::removeVirtualFolder;
    using out_type                     = model::return_type_removeVirtualFolder;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return "/Library/VirtualFolders"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.name)
            p.set_param("name", convert_from<std::string>(input.name.value()));
        if(input.refreshLibrary)
            p.set_param("refreshLibrary", convert_from<std::string>(input.refreshLibrary.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: LibraryStructure
 * defaultResponse: 
 */
};
// Renames a virtual folder.
struct renameVirtualFolder {
public:
    using in_type                      = param::renameVirtualFolder;
    using out_type                     = model::return_type_renameVirtualFolder;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Library/VirtualFolders/Name"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.name)
            p.set_param("name", convert_from<std::string>(input.name.value()));
        if(input.newName)
            p.set_param("newName", convert_from<std::string>(input.newName.value()));
        if(input.refreshLibrary)
            p.set_param("refreshLibrary", convert_from<std::string>(input.refreshLibrary.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: LibraryStructure
 * defaultResponse: 
 */
};
// Update library options.
struct updateLibraryOptions {
public:
    using in_type                      = param::updateLibraryOptions;
    using out_type                     = model::return_type_updateLibraryOptions;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Library/VirtualFolders/LibraryOptions"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        if(input.body)
            out = format_param(input.body.value());
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: LibraryStructure
 * defaultResponse: 
 */
};
// Updates a media path.
struct updateMediaPath {
public:
    using in_type                      = param::updateMediaPath;
    using out_type                     = model::return_type_updateMediaPath;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Library/VirtualFolders/Paths/Update"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        out = format_param(input.body);
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: LibraryStructure
 * defaultResponse: 
 */
};
}
}
