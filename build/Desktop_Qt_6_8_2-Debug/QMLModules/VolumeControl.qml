import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: volumeControlContainer
    color: "transparent"

    property var mediaPlayer: null
    property alias sliderColor: volumeSlider.accentColor

    RowLayout {
        anchors.fill: parent
        spacing: 10

        Label {
            text: "Volume:"
            color: "white"
            font.pixelSize: 14
        }

        Slider {
            id: volumeSlider
            Layout.fillWidth: true
            from: 0
            to: 100
            value: mediaPlayer ? mediaPlayer.volume : 0
            stepSize: 1

            property color accentColor: "#66aaff"

            background: Rectangle {
                x: volumeSlider.leftPadding
                y: volumeSlider.topPadding + volumeSlider.availableHeight / 2 - height / 2
                width: volumeSlider.availableWidth
                height: 6
                radius: 3
                color: "#333333"

                Rectangle {
                    width: volumeSlider.visualPosition * parent.width
                    height: parent.height
                    color: volumeSlider.accentColor
                    radius: 3
                }
            }

            handle: Rectangle {
                x: volumeSlider.leftPadding + volumeSlider.visualPosition * volumeSlider.availableWidth - width / 2
                y: volumeSlider.topPadding + volumeSlider.availableHeight / 2 - height / 2
                width: 18
                height: 18
                radius: 9
                color: volumeSlider.pressed ? Qt.lighter(volumeSlider.accentColor, 1.2) : volumeSlider.accentColor
                border.color: Qt.rgba(volumeSlider.accentColor.r, volumeSlider.accentColor.g, volumeSlider.accentColor.b, 0.5)

                Label {
                    visible: volumeSlider.hovered || volumeSlider.pressed
                    text: volumeSlider.value.toFixed(0)
                    color: "white"
                    font.pixelSize: 10
                    anchors.centerIn: parent
                }
            }

            onMoved: {
                if (mediaPlayer) {
                    mediaPlayer.volume = value;
                }
            }
        }

        Label {
            text: mediaPlayer ? mediaPlayer.volume.toFixed(0) + "%" : "0%"
            color: "white"
            horizontalAlignment: Text.AlignRight
            Layout.minimumWidth: 50
            font.pixelSize: 14
        }

        ToolButton {
            id: muteButton
            icon.name: mediaPlayer && mediaPlayer.volume <= 0 ? "audio-volume-muted" :
                      (mediaPlayer && mediaPlayer.volume < 30 ? "audio-volume-low" :
                       (mediaPlayer && mediaPlayer.volume < 70 ? "audio-volume-medium" : "audio-volume-high"))

            property bool wasMuted: false
            property int lastVolume: 50

            onClicked: {
                if (mediaPlayer) {
                    if (mediaPlayer.volume > 0) {
                        lastVolume = mediaPlayer.volume;
                        mediaPlayer.volume = 0;
                        wasMuted = true;
                    } else if (wasMuted) {
                        mediaPlayer.volume = lastVolume;
                        wasMuted = false;
                    } else {
                        mediaPlayer.volume = 50;
                    }
                }
            }

            ToolTip.text: mediaPlayer && mediaPlayer.volume <= 0 ? "Unmute" : "Mute"
            ToolTip.visible: hovered
        }
    }
}
