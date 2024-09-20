#pragma once

#include <QQmlEngine>
#include "service_qml_jellyfin/api.h"
#include "jellyfin/api/OAIUserApi.h"

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
    // using out_type = ncm::api_model::Auth;

    READ_PROPERTY(qint32, code, m_code, infoChanged)

signals:
    void infoChanged();
};

} // namespace model

class AuthQuerier;
} // namespace jellyfin_qml

namespace qcm
{
template<>
inline void api_traits<jellyfin_qml::AuthQuerier>::handle_output() {}
} // namespace qcm

namespace jellyfin_qml
{

using AuthQuerier_base = ApiQuerier<jellyfin::api::authenticateUserByName, model::Auth>;
class AuthQuerier : public AuthQuerier_base {
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QUrl server READ server WRITE set_server NOTIFY serverChanged FINAL)
public:
    AuthQuerier(QObject* parent = nullptr): AuthQuerier_base(parent) { set_autoReload(false); }
    FORWARD_PROPERTY(QString, username, body.Username)
    FORWARD_PROPERTY(QString, password, body.Pw)

    auto server() -> const QUrl& { return m_server; }
    void set_server(const QUrl& url) {
        if (std::exchange(m_server, url) != url) {
            serverChanged();
        }
    }

    void reload() override {
        auto c   = client();
        c.set_base(convert_from<std::string>(m_server.toString()));
        AuthQuerier_base::reload();
    }

Q_SIGNALS:
    void serverChanged();

private:
    QUrl m_server;
};
} // namespace jellyfin_qml
