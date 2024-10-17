#pragma once

#include "qcm_interface/item_id.h"

namespace jellyfin_qml
{
enum class IdType
{
    Song = 0,
    Album,
    Artist,
    Playlist,
    User,
};
auto to_item_id(IdType, std::string_view) -> qcm::model::ItemId;
} // namespace jellyfin_qml

DECLARE_CONVERT(std::string_view, jellyfin_qml::IdType);