#include "service_qml_jellyfin/api.h"
#include "qcm_interface/global.h"
#include <QUuid>

using namespace qcm;

namespace jellyfin_qml
{
namespace impl
{
struct Client : public ClientBase {
    Client(jellyfin::Client j): jellyfin(j) {}
    jellyfin::Client jellyfin;
};
auto get_client(ClientBase& base) -> jellyfin::Client* {
    return &static_cast<Client&>(base).jellyfin;
}
} // namespace impl

auto detail::get_client() -> jellyfin::Client {
    return jellyfin::Client(
        Global::instance()->session(),
        Global::instance()->pool_executor(),
        Global::instance()->uuid().toString(QUuid::WithoutBraces).toStdString());
}

} // namespace jellyfin_qml