#pragma once

#include <QQmlEngine>
#include "service_qml_jellyfin/api.h"
#include "jellyfin/api/OAIUserApi.h"
#include "qcm_interface/global.h"
#include "qcm_interface/model/user_model.h"

#include "core/log.h"
#include "core/qstr_helper.h"

namespace jellyfin_qml
{

namespace model
{

class Auth : public QObject {
    Q_OBJECT
public:
    Auth(QObject* parent = nullptr): QObject(parent) {}
};

} // namespace model

using AuthQuerier_base = ApiQuerier<jellyfin::api::authenticateUserByName, model::Auth>;
class AuthQuerier : public AuthQuerier_base {
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QUrl server READ server WRITE set_server NOTIFY serverChanged FINAL)
public:
    using base_type = AuthQuerier_base;

    AuthQuerier(QObject* parent = nullptr): base_type(parent) { set_autoReload(false); }

    FORWARD_PROPERTY(QString, username, body.Username)
    FORWARD_PROPERTY(QString, password, body.Pw)

    auto server() -> const QUrl& { return m_server; }
    void set_server(const QUrl& url) {
        if (std::exchange(m_server, url) != url) {
            serverChanged();
        }
    }

    void reload() override {
        client().transform([this](auto c) {
            c.set_base(convert_from<std::string>(m_server.toString()));
            base_type::reload();
            return true;
        });
    }

    Q_SIGNAL void serverChanged();

    void handle_output(const AuthQuerier_base::out_type& out) {
        client().transform([&out, this](auto c) -> std::nullptr_t {
            c.set_token(out.AccessToken);
            qcm::Action::instance()->load_session(this->session());
            return {};
        });
    }

private:
    QUrl m_server;
};

} // namespace jellyfin_qml