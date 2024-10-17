#include "service_qml_jellyfin/session.h"
#include "service_qml_jellyfin/api.h"
#include "service_qml_jellyfin/client.h"

#define QRC_URL  u"qrc:/Qcm/Service/Jellyfin/"
#define PAGE_URL QRC_URL u"qml/page/"

namespace jellyfin_qml
{
namespace
{
auto main_pages() -> std::vector<qcm::model::Page> {
    return { qcm::model::Page {
        "library", "library_music", QStringLiteral(PAGE_URL "MinePage.qml"), true, true } };
}
} // namespace

Session::Session(QObject* parent): qcm::model::Session(parent) {
    set_valid(true);
    set_pages(main_pages());
    set_client(jellyfin_qml::create_client());

    connect(
        this,
        &Session::userChanged,
        this,
        [this] {
            auto user = this->user();
            if (user == nullptr || user->token().isEmpty()) return;
            client()
                .and_then(jellyfin_qml::get_jellfin_client)
                .transform([user](auto c) -> std::nullptr_t {
                    c.set_token(user->token().toStdString());
                    c.set_base(user->server().toString().toStdString());
                    return {};
                });
        },
        Qt::DirectConnection);
}
Session::~Session() {}

} // namespace jellyfin_qml
