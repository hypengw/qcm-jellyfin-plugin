#pragma once
/*
 * OAICollectionApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAICollectionCreationResult.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_addToCollection = std::nullptr_t;
using return_type_createCollection = OAICollectionCreationResult;
using return_type_removeFromCollection = std::nullptr_t;
}

namespace api::param 
{
struct addToCollection {
    std::string collectionId; // The collection id.
    std::vector<std::string> ids; // Item ids, comma delimited.
};
struct createCollection {
    std::optional<std::string> name; // The name of the collection.
    std::optional<std::vector<std::string>> ids; // Item Ids to add to the collection.
    std::optional<std::string> parentId; // Optional. Create the collection within a specific folder.
    std::optional<bool> isLocked; // Whether or not to lock the new collection.
};
struct removeFromCollection {
    std::string collectionId; // The collection id.
    std::vector<std::string> ids; // Item ids, comma delimited.
};
}

namespace api 
{
// Adds items to a collection.
struct addToCollection {
public:
    using in_type                      = param::addToCollection;
    using out_type                     = model::return_type_addToCollection;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Collections/{}/Items"sv,
            input.collectionId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("ids", input.ids);
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
 * baseName: Collection
 * defaultResponse: 
 */
};
// Creates a new collection.
struct createCollection {
public:
    using in_type                      = param::createCollection;
    using out_type                     = model::return_type_createCollection;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Collections"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.name)
            p.set_param("name", convert_from<std::string>(input.name.value()));
        if(input.ids)
            p.set_param("ids", input.ids.value());
        if(input.parentId)
            p.set_param("parentId", convert_from<std::string>(input.parentId.value()));
        if(input.isLocked)
            p.set_param("isLocked", convert_from<std::string>(input.isLocked.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: OAICollectionCreationResult
 * returnFormat: 
 * returnBaseType: OAICollectionCreationResult
 * returnContainer: 
 * baseName: Collection
 * defaultResponse: OAICollectionCreationResult()
 */
};
// Removes items from a collection.
struct removeFromCollection {
public:
    using in_type                      = param::removeFromCollection;
    using out_type                     = model::return_type_removeFromCollection;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/Collections/{}/Items"sv,
            input.collectionId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("ids", input.ids);
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
 * baseName: Collection
 * defaultResponse: 
 */
};
}
}
