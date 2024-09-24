#pragma once
/*
 * OAIPackageApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIPackageInfo.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include "jellyfin/model/OAIRepositoryInfo.h"
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_cancelPackageInstallation = std::nullptr_t;
using return_type_getPackageInfo = OAIPackageInfo;
using return_type_getPackages = std::vector<OAIPackageInfo>;
using return_type_getRepositories = std::vector<OAIRepositoryInfo>;
using return_type_installPackage = std::nullptr_t;
using return_type_setRepositories = std::nullptr_t;
}

namespace api::param 
{
struct cancelPackageInstallation {
    std::string packageId; // Installation Id.
};
struct getPackageInfo {
    std::string name; // The name of the package.
    std::optional<std::string> assemblyGuid; // The GUID of the associated assembly.
};
struct getPackages {
};
struct getRepositories {
};
struct installPackage {
    std::string name; // Package name.
    std::optional<std::string> assemblyGuid; // GUID of the associated assembly.
    std::optional<std::string> version; // Optional version. Defaults to latest version.
    std::optional<std::string> repositoryUrl; // Optional. Specify the repository to install from.
};
struct setRepositories {
    std::vector<OAIRepositoryInfo> body; // The list of package repositories.
};
}

namespace api 
{
// Cancels a package installation.
struct cancelPackageInstallation {
public:
    using in_type                      = param::cancelPackageInstallation;
    using out_type                     = model::return_type_cancelPackageInstallation;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/Packages/Installing/{}"sv,
            input.packageId
        );
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
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Package
 * defaultResponse: 
 */
};
// Gets a package by name or assembly GUID.
struct getPackageInfo {
public:
    using in_type                      = param::getPackageInfo;
    using out_type                     = model::return_type_getPackageInfo;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Packages/{}"sv,
            input.name
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.assemblyGuid)
            p.set_param("assemblyGuid", convert_from<std::string>(input.assemblyGuid.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIPackageInfo
 * returnFormat: 
 * returnBaseType: OAIPackageInfo
 * returnContainer: 
 * baseName: Package
 * defaultResponse: OAIPackageInfo()
 */
};
// Gets available packages.
struct getPackages {
public:
    using in_type                      = param::getPackages;
    using out_type                     = model::return_type_getPackages;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Packages"sv; 
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
 * returnType: std::vector&lt;OAIPackageInfo&gt;
 * returnFormat: 
 * returnBaseType: OAIPackageInfo
 * returnContainer: array
 * baseName: Package
 * defaultResponse: {}
 */
};
// Gets all package repositories.
struct getRepositories {
public:
    using in_type                      = param::getRepositories;
    using out_type                     = model::return_type_getRepositories;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Repositories"sv; 
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
 * returnType: std::vector&lt;OAIRepositoryInfo&gt;
 * returnFormat: 
 * returnBaseType: OAIRepositoryInfo
 * returnContainer: array
 * baseName: Package
 * defaultResponse: {}
 */
};
// Installs a package.
struct installPackage {
public:
    using in_type                      = param::installPackage;
    using out_type                     = model::return_type_installPackage;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Packages/Installed/{}"sv,
            input.name
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.assemblyGuid)
            p.set_param("assemblyGuid", convert_from<std::string>(input.assemblyGuid.value()));
        if(input.version)
            p.set_param("version", convert_from<std::string>(input.version.value()));
        if(input.repositoryUrl)
            p.set_param("repositoryUrl", convert_from<std::string>(input.repositoryUrl.value()));
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
 * baseName: Package
 * defaultResponse: 
 */
};
// Sets the enabled and existing package repositories.
struct setRepositories {
public:
    using in_type                      = param::setRepositories;
    using out_type                     = model::return_type_setRepositories;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Repositories"sv; 
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
 * baseName: Package
 * defaultResponse: 
 */
};
}
}
