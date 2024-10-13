#include "service_qml_jellyfin/client.h"
#include "service_qml_jellyfin/api.h"

#include <QUuid>
#include <asio/bind_executor.hpp>
#include "core/qstr_helper.h"

#include "qcm_interface/async.inl"
#include "qcm_interface/global.h"
#include "qcm_interface/model/session.h"

#include "asio_helper/detached_log.h"
#include "asio_qt/qt_holder.h"

namespace jellyfin_qml::impl
{

using ClientBase = qcm::ClientBase;
template<typename T>
using Result = qcm::Client::Result<T>;

struct Client : public ClientBase {
    Client(jellyfin::Client c): jellyfin(c) {}
    jellyfin::Client jellyfin;
};

static auto get_client(ClientBase& c) -> jellyfin::Client* {
    return &static_cast<Client&>(c).jellyfin;
}

static auto server_url(ClientBase& cbase, const qcm::model::ItemId& id) -> std::string {
    auto c = get_client(cbase);
    return "";
}

static void play_state(ClientBase& cbase, qcm::enums::PlaybackState state,
                       qcm::model::ItemId itemId, qcm::model::ItemId sourceId, i64 played_second,
                       QVariantMap) {}

static auto router(ClientBase& cbase) -> rc<qcm::Router> {
    auto c = *get_client(cbase);
    return {};
}

static auto logout(ClientBase& cbase) -> asio::awaitable<void> {
    auto c = *get_client(cbase);
    co_return;
}
static auto session_check(ClientBase& cbase, helper::QWatcher<qcm::model::Session> session)
    -> asio::awaitable<Result<bool>> {
    auto c = *get_client(cbase);
    co_return false;
}

void save(ClientBase& cbase, const std::filesystem::path& path) { auto c = *get_client(cbase); }

void load(ClientBase& cbase, const std::filesystem::path& path) { auto c = *get_client(cbase); }

bool make_request(ClientBase& cbase, request::Request& req, const QUrl& url,
                  const qcm::Client::ReqInfo& info) {
    auto c = *get_client(cbase);
    std::visit(overloaded { [c, &url, &req](const qcm::Client::ReqInfoImg& info) {
               } },
               info);
    return true;
}

auto collect(ClientBase& cbase, qcm::model::ItemId id, bool act) -> asio::awaitable<Result<bool>> {
    auto c = *get_client(cbase);
    co_return false;
}

auto media_url(ClientBase& cbase, qcm::model::ItemId id,
               qcm::enums::AudioQuality quality) -> asio::awaitable<Result<QUrl>> {
    auto c = *get_client(cbase);
    co_return QUrl {};
}

} // namespace jellyfin_qml::impl

namespace jellyfin_qml
{

auto create_client() -> qcm::Client {
    auto c = jellyfin::Client(
        qcm::Global::instance()->session(),
        qcm::Global::instance()->pool_executor(),
        qcm::Global::instance()->uuid().toString(QUuid::WithoutBraces).toStdString());

    auto api      = make_rc<qcm::Global::Client::Api>();
    auto instance = make_rc<impl::Client>(c);

    api->provider      = provider_name;
    api->server_url    = impl::server_url;
    api->make_request  = impl::make_request;
    api->play_state    = impl::play_state;
    api->router        = impl::router;
    api->logout        = impl::logout;
    api->session_check = impl::session_check;
    api->collect       = impl::collect;
    api->media_url     = impl::media_url;
    api->save          = impl::save;
    api->load          = impl::load;

    return { .api = api, .instance = instance };
}

} // namespace jellyfin_qml

auto jellyfin_qml::get_jellfin_client(const qcm::Client& c) -> std::optional<jellyfin::Client> {
    if (c.api->provider == provider_name) {
        return *impl::get_client(*c.instance);
    } else {
        return std::nullopt;
    }
}
//auto jellyfin_qml::uniq(const QUrl& url, const QVariant& info) -> QString {
//    auto size = info.value<QSize>();
//    return "";
//}