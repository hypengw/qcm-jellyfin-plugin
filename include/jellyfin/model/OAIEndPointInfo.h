#pragma once

/*
 * OAIEndPointInfo.h
 * name: EndPointInfo
 * schemaName: EndPointInfo
 * classFilename: EndPointInfo
 * classVarName: EndPointInfo
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



namespace jellyfin::model {


    class OAIEndPointInfo {
    public:
    
        bool IsLocal;

        bool IsInNetwork;

        OAIEndPointInfo();
        ~OAIEndPointInfo();
    };
    extern void to_json(json_t&, const OAIEndPointInfo&);
    extern void from_json(const json_t&, OAIEndPointInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIEndPointInfo);
