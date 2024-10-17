find_package(
  Qt6 REQUIRED
  COMPONENTS Qml Quick)

set(SOURCES
    include/service_qml_jellyfin/client.h 
    include/service_qml_jellyfin/api/auth.h
    include/service_qml_jellyfin/api.h
    include/service_qml_jellyfin/type.h
    include/service_qml_jellyfin/session.h
    api.cpp
    client.cpp
    model.cpp
    session.cpp
    )

set(QML_FILES
    qml/page/LoginPage.qml
    qml/page/MinePage.qml
    qml/page/test.qml)

set(RESOURCES
    assets/jellyfin.svg)

qt_add_qml_module(
  service_qml_jellyfin
  URI
  Qcm.Service.Jellyfin
  SHARED
  RESOURCE_PREFIX
  /
  VERSION
  ${PROJECT_VERSION}
  QML_FILES
  ${QML_FILES}
  SOURCES
  ${SOURCES}
  RESOURCES
  ${RESOURCES}
  NO_PLUGIN_OPTIONAL
  NO_GENERATE_PLUGIN_SOURCE)

target_sources(
  service_qml_jellyfinplugin
  PRIVATE plugin.cpp)

target_include_directories(
  service_qml_jellyfin
  PUBLIC include
  PRIVATE . include/service_qml_jellyfin include/service_qml_jellyfin/model
          include/service_qml_jellyfin/api)

target_link_libraries(
  service_qml_jellyfin
  PUBLIC Qt::Quick core qcm_interface
  PRIVATE ctre platform jellyfin-cpp meta_model)

target_compile_definitions(
  service_qml_jellyfin
  PRIVATE SERVICE_QML_JF_EXPORT)

set_target_properties(
  service_qml_jellyfin
  PROPERTIES CXX_VISIBILITY_PRESET hidden
             OUTPUT_NAME qcm_service_qml_jellyfin)

qt_install_qml_module(service_qml_jellyfin)
