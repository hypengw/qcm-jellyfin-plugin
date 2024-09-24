#pragma once

/*
 * OAIGroupUpdate.h
 * name: GroupUpdate
 * schemaName: GroupUpdate
 * classFilename: GroupUpdate
 * classVarName: GroupUpdate
 * dataType: OAIOneOfGroupInfoDtoGroupUpdateGroupStateUpdateGroupUpdateStringGroupUpdatePlayQueueUpdateGroupUpdate
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Group update without data.
 */

#include <variant>

#include "jellyfin/type.h"


#include "jellyfin/model/OAIGroupInfoDtoGroupUpdate.h"
#include "jellyfin/model/OAIGroupStateUpdateGroupUpdate.h"
#include "jellyfin/model/OAIGroupUpdateType.h"
#include "jellyfin/model/OAIPlayQueueUpdate.h"
#include "jellyfin/model/OAIPlayQueueUpdateGroupUpdate.h"
#include "jellyfin/model/OAIStringGroupUpdate.h"
#include <string>



namespace jellyfin::model {
class OAIPlayQueueUpdate;

    class OAIGroupUpdate
    {
    public:
        OAIGroupUpdate() = default;
        ~OAIGroupUpdate() = default;

        /// OAIGroupUpdate members
        using VariantType = std::variant<OAIGroupInfoDtoGroupUpdate, OAIGroupStateUpdateGroupUpdate, OAIPlayQueueUpdateGroupUpdate, OAIStringGroupUpdate>;

        const VariantType& getVariant() const;
        void setVariant(VariantType value);

    protected:
        VariantType m_variantValue;
    };
    extern void to_json(json_t&, const OAIGroupUpdate&);
    extern void from_json(const json_t&, OAIGroupUpdate&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIGroupUpdate);
