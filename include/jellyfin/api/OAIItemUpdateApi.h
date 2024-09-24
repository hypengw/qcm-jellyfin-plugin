#pragma once
/*
 * OAIItemUpdateApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIBaseItemDto.h"
#include "jellyfin/model/OAIMetadataEditorInfo.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include <string>

namespace jellyfin {
namespace model
{
using return_type_getMetadataEditorInfo = OAIMetadataEditorInfo;
using return_type_updateItem = std::nullptr_t;
using return_type_updateItemContentType = std::nullptr_t;
}

namespace api::param 
{
struct getMetadataEditorInfo {
    std::string itemId; // The item id.
};
struct updateItem {
    std::string itemId; // The item id.
    OAIBaseItemDto body; // The new item properties.
};
struct updateItemContentType {
    std::string itemId; // The item id.
    std::optional<std::string> contentType; // The content type of the item.
};
}

namespace api 
{
// Gets metadata editor info for an item.
struct getMetadataEditorInfo {
public:
    using in_type                      = param::getMetadataEditorInfo;
    using out_type                     = model::return_type_getMetadataEditorInfo;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/MetadataEditor"sv,
            input.itemId
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
 * returnType: OAIMetadataEditorInfo
 * returnFormat: 
 * returnBaseType: OAIMetadataEditorInfo
 * returnContainer: 
 * baseName: ItemUpdate
 * defaultResponse: OAIMetadataEditorInfo()
 */
};
// Updates an item.
struct updateItem {
public:
    using in_type                      = param::updateItem;
    using out_type                     = model::return_type_updateItem;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Items/{}"sv,
            input.itemId
        );
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
 * baseName: ItemUpdate
 * defaultResponse: 
 */
};
// Updates an item&#39;s content type.
struct updateItemContentType {
public:
    using in_type                      = param::updateItemContentType;
    using out_type                     = model::return_type_updateItemContentType;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Items/{}/ContentType"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.contentType)
            p.set_param("contentType", convert_from<std::string>(input.contentType.value()));
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
 * baseName: ItemUpdate
 * defaultResponse: 
 */
};
}
}
