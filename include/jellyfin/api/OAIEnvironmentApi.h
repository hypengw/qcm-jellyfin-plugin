#pragma once
/*
 * OAIEnvironmentApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIDefaultDirectoryBrowserInfoDto.h"
#include "jellyfin/model/OAIFileSystemEntryInfo.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAIValidatePathDto.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getDefaultDirectoryBrowser = OAIDefaultDirectoryBrowserInfoDto;
using return_type_getDirectoryContents = std::vector<OAIFileSystemEntryInfo>;
using return_type_getDrives = std::vector<OAIFileSystemEntryInfo>;
using return_type_getNetworkShares = std::vector<OAIFileSystemEntryInfo>;
using return_type_getParentPath = std::string;
using return_type_validatePath = std::nullptr_t;
}

namespace api::param 
{
struct getDefaultDirectoryBrowser {
};
struct getDirectoryContents {
    std::string path; // The path.
    std::optional<bool> includeFiles; // An optional filter to include or exclude files from the results. true/false.
    std::optional<bool> includeDirectories; // An optional filter to include or exclude folders from the results. true/false.
};
struct getDrives {
};
struct getNetworkShares {
};
struct getParentPath {
    std::string path; // The path.
};
struct validatePath {
    OAIValidatePathDto body; // Validate request object.
};
}

namespace api 
{
// Get Default directory browser.
struct getDefaultDirectoryBrowser {
public:
    using in_type                      = param::getDefaultDirectoryBrowser;
    using out_type                     = model::return_type_getDefaultDirectoryBrowser;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Environment/DefaultDirectoryBrowser"sv; 
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
 * returnType: OAIDefaultDirectoryBrowserInfoDto
 * returnFormat: 
 * returnBaseType: OAIDefaultDirectoryBrowserInfoDto
 * returnContainer: 
 * baseName: Environment
 * defaultResponse: OAIDefaultDirectoryBrowserInfoDto()
 */
};
// Gets the contents of a given directory in the file system.
struct getDirectoryContents {
public:
    using in_type                      = param::getDirectoryContents;
    using out_type                     = model::return_type_getDirectoryContents;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Environment/DirectoryContents"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("path", convert_from<std::string>(input.path));
        if(input.includeFiles)
            p.set_param("includeFiles", convert_from<std::string>(input.includeFiles.value()));
        if(input.includeDirectories)
            p.set_param("includeDirectories", convert_from<std::string>(input.includeDirectories.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;OAIFileSystemEntryInfo&gt;
 * returnFormat: 
 * returnBaseType: OAIFileSystemEntryInfo
 * returnContainer: array
 * baseName: Environment
 * defaultResponse: {}
 */
};
// Gets available drives from the server&#39;s file system.
struct getDrives {
public:
    using in_type                      = param::getDrives;
    using out_type                     = model::return_type_getDrives;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Environment/Drives"sv; 
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
 * returnType: std::vector&lt;OAIFileSystemEntryInfo&gt;
 * returnFormat: 
 * returnBaseType: OAIFileSystemEntryInfo
 * returnContainer: array
 * baseName: Environment
 * defaultResponse: {}
 */
};
// Gets network paths.
struct getNetworkShares {
public:
    using in_type                      = param::getNetworkShares;
    using out_type                     = model::return_type_getNetworkShares;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Environment/NetworkShares"sv; 
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
 * returnType: std::vector&lt;OAIFileSystemEntryInfo&gt;
 * returnFormat: 
 * returnBaseType: OAIFileSystemEntryInfo
 * returnContainer: array
 * baseName: Environment
 * defaultResponse: {}
 */
};
// Gets the parent path of a given path.
struct getParentPath {
public:
    using in_type                      = param::getParentPath;
    using out_type                     = model::return_type_getParentPath;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Environment/ParentPath"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("path", convert_from<std::string>(input.path));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::string
 * returnFormat: 
 * returnBaseType: std::string
 * returnContainer: 
 * baseName: Environment
 * defaultResponse: {}
 */
};
// Validates path.
struct validatePath {
public:
    using in_type                      = param::validatePath;
    using out_type                     = model::return_type_validatePath;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Environment/ValidatePath"sv; 
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
 * baseName: Environment
 * defaultResponse: 
 */
};
}
}
