import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts

import Qcm.App as QA
import Qcm.Material as MD
import Qcm.Service.Jellyfin as QJF

MD.Page {
    id: root
    title: qsTr('log in')

    QJF.Session {
        id: m_session
    }
    QJF.AuthQuerier {
        id: m_auth_querier
        session: m_session
    }

    ColumnLayout {
        anchors.fill: parent

        readonly property bool loginCodeOk: false

        onLoginCodeOkChanged: {}

        ColumnLayout {
            Layout.alignment: Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.maximumWidth: 400 - 64
            spacing: 12

            MD.IconSvg {
                Layout.alignment: Qt.AlignHCenter
                source: 'qrc:/Qcm/Service/Jellyfin/assets/jellyfin.svg'
                size: 128
            }

            MD.Text {
                Layout.alignment: Qt.AlignHCenter
                text: qsTr('log into jellyfin')
                font.capitalization: Font.Capitalize
                typescale: MD.Token.typescale.title_large
            }
            MD.Pane {
                id: mail_pane
                Layout.fillWidth: true

                ColumnLayout {
                    anchors.fill: parent

                    MD.TextField {
                        id: tf_server
                        Layout.fillWidth: true
                        placeholderText: 'Server'
                    }
                    MD.TextField {
                        id: tf_username
                        Layout.fillWidth: true
                        placeholderText: 'User'
                    }
                    MD.TextField {
                        id: tf_password
                        Layout.fillWidth: true
                        echoMode: TextInput.Password
                        placeholderText: 'Password'
                    }
                    MD.Text {
                        MD.MatProp.textColor: MD.Token.color.error
                        text: {
                            switch (0) {
                            case 501:
                                return qsTr('Email not found');
                            case 502:
                                return qsTr('Invalid email or password');
                            default:
                                return '';
                            }
                        }
                    }
                    MD.Button {
                        Layout.fillWidth: true
                        // enabled: qr_login.status !== QA.enums.Querying
                        font.capitalization: Font.Capitalize
                        highlighted: true
                        text: qsTr('log in')

                        Component.onCompleted: {
                            tf_username.accepted.connect(clicked);
                            tf_password.accepted.connect(clicked);
                        }
                        onClicked: {
                            const q = m_auth_querier;
                            q.server = tf_server.text;
                            q.username = tf_username.text;
                            q.password = tf_password.text;
                            q.query();
                        }
                    }
                }
            }
        }
    }
}
