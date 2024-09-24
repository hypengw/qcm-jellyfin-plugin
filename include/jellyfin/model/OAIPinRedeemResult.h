#pragma once

/*
 * OAIPinRedeemResult.h
 * name: PinRedeemResult
 * schemaName: PinRedeemResult
 * classFilename: PinRedeemResult
 * classVarName: PinRedeemResult
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
#include <vector>



namespace jellyfin::model {


    class OAIPinRedeemResult {
    public:
    
        // Gets or sets a value indicating whether this MediaBrowser.Model.Users.PinRedeemResult is success.
        bool Success;

        // Gets or sets the users reset.
        std::vector<std::string> UsersReset;

        OAIPinRedeemResult();
        ~OAIPinRedeemResult();
    };
    extern void to_json(json_t&, const OAIPinRedeemResult&);
    extern void from_json(const json_t&, OAIPinRedeemResult&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIPinRedeemResult);
