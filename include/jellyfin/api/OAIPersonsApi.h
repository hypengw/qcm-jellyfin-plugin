#pragma once
/*
 * OAIPersonsApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIBaseItemDto.h"
#include "jellyfin/model/OAIBaseItemDtoQueryResult.h"
#include "jellyfin/model/OAIImageType.h"
#include "jellyfin/model/OAIItemFields.h"
#include "jellyfin/model/OAIItemFilter.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_getPerson = OAIBaseItemDto;
using return_type_getPersons = OAIBaseItemDtoQueryResult;
}

namespace api::param 
{
struct getPerson {
    std::string name; // Person name.
    std::optional<std::string> userId; // Optional. Filter by user id, and attach user data.
};
struct getPersons {
    std::optional<std::int32_t> limit; // Optional. The maximum number of records to return.
    std::optional<std::string> searchTerm; // The search term.
    std::optional<std::vector<OAIItemFields>> fields; // Optional. Specify additional fields of information to return in the output.
    std::optional<std::vector<OAIItemFilter>> filters; // Optional. Specify additional filters to apply.
    std::optional<bool> isFavorite; // Optional filter by items that are marked as favorite, or not. userId is required.
    std::optional<bool> enableUserData; // Optional, include user data.
    std::optional<std::int32_t> imageTypeLimit; // Optional, the max number of images to return, per image type.
    std::optional<std::vector<OAIImageType>> enableImageTypes; // Optional. The image types to include in the output.
    std::optional<std::vector<std::string>> excludePersonTypes; // Optional. If specified results will be filtered to exclude those containing the specified PersonType. Allows multiple, comma-delimited.
    std::optional<std::vector<std::string>> personTypes; // Optional. If specified results will be filtered to include only those containing the specified PersonType. Allows multiple, comma-delimited.
    std::optional<std::string> appearsInItemId; // Optional. If specified, person results will be filtered on items related to said persons.
    std::optional<std::string> userId; // User id.
    std::optional<bool> enableImages; // Optional, include image information in output.
};
}

namespace api 
{
// Get person by name.
struct getPerson {
public:
    using in_type                      = param::getPerson;
    using out_type                     = model::return_type_getPerson;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Persons/{}"sv,
            input.name
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIBaseItemDto
 * returnFormat: 
 * returnBaseType: OAIBaseItemDto
 * returnContainer: 
 * baseName: Persons
 * defaultResponse: OAIBaseItemDto()
 */
};
// Gets all persons.
struct getPersons {
public:
    using in_type                      = param::getPersons;
    using out_type                     = model::return_type_getPersons;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Persons"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.limit)
            p.set_param("limit", convert_from<std::string>(input.limit.value()));
        if(input.searchTerm)
            p.set_param("searchTerm", convert_from<std::string>(input.searchTerm.value()));
        if(input.fields)
            p.set_param("fields", input.fields.value());
        if(input.filters)
            p.set_param("filters", input.filters.value());
        if(input.isFavorite)
            p.set_param("isFavorite", convert_from<std::string>(input.isFavorite.value()));
        if(input.enableUserData)
            p.set_param("enableUserData", convert_from<std::string>(input.enableUserData.value()));
        if(input.imageTypeLimit)
            p.set_param("imageTypeLimit", convert_from<std::string>(input.imageTypeLimit.value()));
        if(input.enableImageTypes)
            p.set_param("enableImageTypes", input.enableImageTypes.value());
        if(input.excludePersonTypes)
            p.set_param("excludePersonTypes", input.excludePersonTypes.value());
        if(input.personTypes)
            p.set_param("personTypes", input.personTypes.value());
        if(input.appearsInItemId)
            p.set_param("appearsInItemId", convert_from<std::string>(input.appearsInItemId.value()));
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.enableImages)
            p.set_param("enableImages", convert_from<std::string>(input.enableImages.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAIBaseItemDtoQueryResult
 * returnFormat: 
 * returnBaseType: OAIBaseItemDtoQueryResult
 * returnContainer: 
 * baseName: Persons
 * defaultResponse: OAIBaseItemDtoQueryResult()
 */
};
}
}
