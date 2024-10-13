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

template<>
inline void AuthQuerier_base::helper_type::handle_output(const api_type&, model_type&,
                                                         const out_type& in) {
    // detail::get_client().set_token(in.AccessToken);
    // auto               user = new qcm::model::UserAccount;
    // qcm::model::ItemId id;
    // id.set_id(convert_from<QString>(fmt::format("{}", in.User->Id)));
    // id.set_provider(provider_name);
    // user->set_userId(id);
    // user->set_token(convert_from<QString>(in.AccessToken.value_or("")));
    // qcm::Global::instance()->user_model()->check_user(user);
}

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

private:
    QUrl m_server;
};

} // namespace jellyfin_qml