import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import QMLModules

Window {
    width: 800
    height: 600
    visible: true
    title: qsTr("Media Player")

    // Dynamically adjust background brightness based on ambient light
    color: {
        // Map ambient brightness (0-100) to a background color between dark and light
        const brightness = Math.min(sensorsManager.ambientBrightness, 100) / 100;
        return Qt.rgba(0.1 + brightness * 0.2, 0.1 + brightness * 0.2, 0.2 + brightness * 0.2, 1.0);
    }

    // Main layout
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 20

        // Title and status area
        Rectangle {
            Layout.fillWidth: true
            height: 100
            color: "transparent"

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 10

                Label {
                    Layout.fillWidth: true
                    text: mediaPlayer.currentTrackTitle || "No Track Selected"
                    font.pixelSize: 32
                    font.bold: true
                    color: "white"
                    horizontalAlignment: Text.AlignHCenter
                }

                Label {
                    Layout.fillWidth: true
                    text: mediaPlayer.currentTrackArtist || "Unknown Artist"
                    font.pixelSize: 24
                    color: "lightgray"
                    horizontalAlignment: Text.AlignHCenter
                }
                Label {
                    Layout.fillWidth: true
                    text: "Status: " + mediaPlayer.playbackState
                    font.pixelSize: 18
                    color: "lightgray"
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }

        // Progress bar and time display
        ProgressBar {
            Layout.fillWidth: true
            height: 60
            mediaPlayer: mediaPlayer
            progressColor: "#66aaff"
            backgroundColor: "#333333"
            handleColor: "#99ccff"
        }

        // Player controls
        PlayerControls {
            Layout.fillWidth: true
            height: 80
            mediaPlayer: mediaPlayer
        }

        // Volume control
        VolumeControl {
            Layout.fillWidth: true
            height: 50
            mediaPlayer: mediaPlayer
            sliderColor: "#66aaff"
        }

        // Playlist and sensors split view
        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: Qt.rgba(0.2, 0.2, 0.3, 0.7)
            radius: 10

            SplitView {
                anchors.fill: parent
                anchors.margins: 10
                orientation: Qt.Horizontal

                // Playlist on the left
                PlaylistView {
                    SplitView.preferredWidth: parent.width * 0.6
                    SplitView.minimumWidth: 300
                    playlistModel: playlistModel
                    mediaPlayer: mediaPlayer
                }

                // Sensors and Bluetooth panel on the right
                Rectangle {
                    SplitView.preferredWidth: parent.width * 0.4
                    SplitView.minimumWidth: 200
                    color: "transparent"

                    ColumnLayout {
                        anchors.fill: parent
                        spacing: 10

                        // Sensors section
                        SensorsPanel {
                            Layout.fillWidth: true
                            Layout.preferredHeight: 250
                            sensorsManager: sensorsManager
                        }

                        // Bluetooth section
                        BluetoothPanel {
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            bluetoothManager: bluetoothManager
                        }
                    }
                }
            }
        }
    }
}
