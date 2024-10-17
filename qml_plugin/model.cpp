#include "service_qml_jellyfin/api/auth.h"
#include "service_qml_jellyfin/client.h"
#include "service_qml_jellyfin/model.h"

#include "json_helper/helper.inl"

namespace jellyfin
{
auto api::format_api(std::string_view path, const jellyfin::UrlParams& query,
                     std::string_view body) -> std::string {
    return "";
}

auto api::process_error(std::span<const byte> in) -> std::string {
    auto res = qcm::json::parse(convert_from<std::string_view>(in));
    if (res) {
        auto& j = res.value();
        if (j->contains("errors")) {
            for (const auto& e : j->at("errors")) {
                if (e.is_string()) {
                    std::string out;
                    e.get_to(out);
                    return out;
                }
            }
        }
    }
    return {};
}
} // namespace jellyfin

IMPL_CONVERT(std::string_view, jellyfin_qml::IdType) {
    switch (in) {
    case in_type::Album: out = "album"sv; break;
    case in_type::Artist: out = "artist"sv; break;
    case in_type::Playlist: out = "playlist"sv; break;
    case in_type::User: out = "user"sv; break;
    case in_type::Song: out = "song"sv; break;
    default: {
        _assert_rel_(false);
    }
    }
}

auto jellyfin_qml::to_item_id(IdType type, std::string_view id_str) -> qcm::model::ItemId {
    qcm::model::ItemId id;
    id.set_provider(jellyfin_qml::provider_name);
    id.set_type(convert_from<std::string_view>(type));
    id.set_id(id_str);
    return id;
}
namespace jellyfin_qml
{

} // namespace jellyfin_qml