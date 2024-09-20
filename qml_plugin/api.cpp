#include "service_qml_jellyfin/api.h"
#include "qcm_interface/global.h"
#include <QUuid>

using namespace qcm;

namespace jellyfin_qml
{

auto detail::get_client() -> jellyfin::Client {
    auto a = Global::instance()->client(provider_name, []() -> Global::Client {
        auto api = make_rc<Global::Client::Api>();

        return { .api = api,
                 .instance =
                     jellyfin::Client(Global::instance()->session(),
                                      Global::instance()->pool_executor(),
                                      Global::instance()->uuid().toString(QUuid::WithoutBraces).toStdString()) };
    });
    return std::any_cast<jellyfin::Client>(a.instance);
}

} // namespace jellyfin_qml