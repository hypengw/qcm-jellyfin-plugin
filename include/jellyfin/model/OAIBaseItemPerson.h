#pragma once

/*
 * OAIBaseItemPerson.h
 * name: BaseItemPerson
 * schemaName: BaseItemPerson
 * classFilename: BaseItemPerson
 * classVarName: BaseItemPerson
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * This is used by the api to get information about a Person within a BaseItem.
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAIBaseItemPersonImageBlurHashes.h"
#include "jellyfin/model/OAIPersonKind.h"
#include <string>



namespace jellyfin::model {
class OAIBaseItemPersonImageBlurHashes;


    class OAIBaseItemPerson {
    public:
    
        // Gets or sets the name.
        std::optional<std::string> Name;

        // Gets or sets the identifier.
        std::string Id;

        // Gets or sets the role.
        std::optional<std::string> Role;

        // Gets or sets the type.
        OAIPersonKind Type;

        // Gets or sets the primary image tag.
        std::optional<std::string> PrimaryImageTag;

        std::optional<OAIBaseItemPersonImageBlurHashes> ImageBlurHashes;

        OAIBaseItemPerson();
        ~OAIBaseItemPerson();
    };
    extern void to_json(json_t&, const OAIBaseItemPerson&);
    extern void from_json(const json_t&, OAIBaseItemPerson&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIBaseItemPerson);
