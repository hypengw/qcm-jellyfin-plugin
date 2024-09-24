#pragma once

/*
 * OAIBaseItemDtoImageBlurHashes.h
 * name: BaseItemDtoImageBlurHashes
 * schemaName: BaseItemDtoImageBlurHashes
 * classFilename: BaseItemDtoImageBlurHashes
 * classVarName: BaseItemDtoImageBlurHashes
 * dataType: rc&lt;json_t&gt;
 * isNullable: true
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Gets or sets the blurhashes for the image tags.  Maps image type to dictionary mapping image tag to blurhash value.
 */


#include "jellyfin/type.h"


#include <map>
#include <string>



namespace jellyfin::model {


    class OAIBaseItemDtoImageBlurHashes {
    public:
    
        std::map<std::string, std::string> Primary;

        std::map<std::string, std::string> Art;

        std::map<std::string, std::string> Backdrop;

        std::map<std::string, std::string> Banner;

        std::map<std::string, std::string> Logo;

        std::map<std::string, std::string> Thumb;

        std::map<std::string, std::string> Disc;

        std::map<std::string, std::string> Box;

        std::map<std::string, std::string> Screenshot;

        std::map<std::string, std::string> Menu;

        std::map<std::string, std::string> Chapter;

        std::map<std::string, std::string> BoxRear;

        std::map<std::string, std::string> Profile;

        OAIBaseItemDtoImageBlurHashes();
        ~OAIBaseItemDtoImageBlurHashes();
    };
    extern void to_json(json_t&, const OAIBaseItemDtoImageBlurHashes&);
    extern void from_json(const json_t&, OAIBaseItemDtoImageBlurHashes&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIBaseItemDtoImageBlurHashes);
