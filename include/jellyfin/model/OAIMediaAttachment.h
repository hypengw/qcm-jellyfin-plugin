#pragma once

/*
 * OAIMediaAttachment.h
 * name: MediaAttachment
 * schemaName: MediaAttachment
 * classFilename: MediaAttachment
 * classVarName: MediaAttachment
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class MediaAttachment.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIMediaAttachment {
    public:
    
        // Gets or sets the codec.
        std::optional<std::string> Codec;

        // Gets or sets the codec tag.
        std::optional<std::string> CodecTag;

        // Gets or sets the comment.
        std::optional<std::string> Comment;

        // Gets or sets the index.
        std::int32_t Index;

        // Gets or sets the filename.
        std::optional<std::string> FileName;

        // Gets or sets the MIME type.
        std::optional<std::string> MimeType;

        // Gets or sets the delivery URL.
        std::optional<std::string> DeliveryUrl;

        OAIMediaAttachment();
        ~OAIMediaAttachment();
    };
    extern void to_json(json_t&, const OAIMediaAttachment&);
    extern void from_json(const json_t&, OAIMediaAttachment&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMediaAttachment);
