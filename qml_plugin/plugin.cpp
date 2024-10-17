#include <QtCore/qtsymbolmacros.h>
#include <QtQml/qqmlextensionplugin.h>
#include <QtQml/qqmlengine.h>

#include <iostream>
#include "core/log.h"
#include "qcm_interface/plugin.h"
#include "qcm_interface/enum.h"
#include "qcm_interface/model/page.h"
#include "service_qml_jellyfin/session.h"

#define QRC_URL  u"qrc:/Qcm/Service/Jellyfin/"
#define PAGE_URL QRC_URL u"qml/page/"

QT_DECLARE_EXTERN_SYMBOL_VOID(qml_register_types_Qcm_Service_Jellyfin);
class Qcm_Service_JellyfinPlugin : public QQmlEngineExtensionPlugin,
                                   public qcm::QcmPluginInterface {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid)
    Q_INTERFACES(qcm::QcmPluginInterface)

public:
    Qcm_Service_JellyfinPlugin(QObject* parent = nullptr)
        : QQmlEngineExtensionPlugin(parent), m_router(new qcm::Router(this)) {
        QT_KEEP_SYMBOL(qml_register_types_Qcm_Service_Jellyfin);

        m_router->register_path(qcm::enums::PluginBasicPage::BPageLogin, PAGE_URL u"LoginPage.qml");

        m_info.set_name("jellyfin");
        m_info.set_fullname("Jellyfin");
        m_info.set_icon(QUrl(QStringLiteral(QRC_URL u"assets/jellyfin.svg")));
    }

    void initializeEngine(QQmlEngine* engine, const char* uri) override {
        Q_UNUSED(engine);
        Q_UNUSED(uri);
    }

    auto router() -> qcm::Router* override { return m_router; }
    auto info() -> const qcm::model::PluginInfo& override { return m_info; }

    auto create_session() -> up<qcm::model::Session> override {
        return make_up<jellyfin_qml::Session>();
    }
    auto uniq(const QUrl&, const QVariant&) -> QString override { return {}; }

private:
    qcm::Router*           m_router;
    qcm::model::PluginInfo m_info;
};

#include "plugin.moc"