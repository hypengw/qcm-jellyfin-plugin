#pragma once

/*
 * OAIFontFile.h
 * name: FontFile
 * schemaName: FontFile
 * classFilename: FontFile
 * classVarName: FontFile
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Class FontFile.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIFontFile {
    public:
    
        // Gets or sets the name.
        std::optional<std::string> Name;

        // Gets or sets the size.
        std::int64_t Size;

        // Gets or sets the date created.
        std::string DateCreated;

        // Gets or sets the date modified.
        std::string DateModified;

        OAIFontFile();
        ~OAIFontFile();
    };
    extern void to_json(json_t&, const OAIFontFile&);
    extern void from_json(const json_t&, OAIFontFile&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIFontFile);
