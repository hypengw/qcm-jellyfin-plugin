#pragma once
#include "qcm_interface/model/session.h"
#include "service_qml_jellyfin/export.h"

namespace jellyfin_qml
{
class SERVICE_QML_JF_API Session : public qcm::model::Session {
    Q_OBJECT
    QML_ELEMENT
public:
    Session(QObject* parent = nullptr);
    ~Session() override;
};
} // namespace jellyfin_qml