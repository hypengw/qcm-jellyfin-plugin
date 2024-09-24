#pragma once

/*
 * OAILogFile.h
 * name: LogFile
 * schemaName: LogFile
 * classFilename: LogFile
 * classVarName: LogFile
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAILogFile {
    public:
    
        // Gets or sets the date created.
        std::string DateCreated;

        // Gets or sets the date modified.
        std::string DateModified;

        // Gets or sets the size.
        std::int64_t Size;

        // Gets or sets the name.
        std::string Name;

        OAILogFile();
        ~OAILogFile();
    };
    extern void to_json(json_t&, const OAILogFile&);
    extern void from_json(const json_t&, OAILogFile&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAILogFile);
