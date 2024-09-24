#pragma once

/*
 * OAIQuickConnectResult.h
 * name: QuickConnectResult
 * schemaName: QuickConnectResult
 * classFilename: QuickConnectResult
 * classVarName: QuickConnectResult
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Stores the state of an quick connect request.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>



namespace jellyfin::model {


    class OAIQuickConnectResult {
    public:
    
        // Gets or sets a value indicating whether this request is authorized.
        bool Authenticated;

        // Gets the secret value used to uniquely identify this request. Can be used to retrieve authentication information.
        std::string Secret;

        // Gets the user facing code used so the user can quickly differentiate this request from others.
        std::string Code;

        // Gets the requesting device id.
        std::string DeviceId;

        // Gets the requesting device name.
        std::string DeviceName;

        // Gets the requesting app name.
        std::string AppName;

        // Gets the requesting app version.
        std::string AppVersion;

        // Gets or sets the DateTime that this request was created.
        std::string DateAdded;

        OAIQuickConnectResult();
        ~OAIQuickConnectResult();
    };
    extern void to_json(json_t&, const OAIQuickConnectResult&);
    extern void from_json(const json_t&, OAIQuickConnectResult&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIQuickConnectResult);
