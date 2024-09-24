#pragma once

/*
 * OAIGroupUpdateType.h
 * name: GroupUpdateType
 * schemaName: GroupUpdateType
 * classFilename: GroupUpdateType
 * classVarName: GroupUpdateType
 * dataType: std::string
 * isNullable: false
 * isDeprecated: false
 * isEnum: true, isModel: false
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Enum GroupUpdateType.
 */


#include "jellyfin/type.h"





namespace jellyfin::model {

    enum class OAIGroupUpdateType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        USERJOINED, // UserJoined
        USERLEFT, // UserLeft
        GROUPJOINED, // GroupJoined
        GROUPLEFT, // GroupLeft
        STATEUPDATE, // StateUpdate
        PLAYQUEUE, // PlayQueue
        NOTINGROUP, // NotInGroup
        GROUPDOESNOTEXIST, // GroupDoesNotExist
        CREATEGROUPDENIED, // CreateGroupDenied
        JOINGROUPDENIED, // JoinGroupDenied
        LIBRARYACCESSDENIED, // LibraryAccessDenied
    };
    extern void to_json(json_t&, const OAIGroupUpdateType&);
    extern void from_json(const json_t&, OAIGroupUpdateType&);

} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIGroupUpdateType);
