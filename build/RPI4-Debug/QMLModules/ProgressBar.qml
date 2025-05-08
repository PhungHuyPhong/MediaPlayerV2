import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: progressBarContainer
    color: "transparent"

    property var mediaPlayer: null
    property alias progressColor: progressFill.color
    property alias backgroundColor: progressBackground.color
    property alias handleColor: progressHandle.color

    RowLayout {
        anchors.fill: parent
        spacing: 10

        // Current position
        Label {
            id: positionLabel
            text: {
                if (!mediaPlayer) return "0:00";

                const pos = (mediaPlayer ? mediaPlayer.position : 0);
                const min = Math.floor(pos / 60);
                const sec = pos % 60;
                return min + ":" + (sec < 10 ? "0" : "") + sec;
            }
            color: "white"
            font.pixelSize: 16
        }

        // Progress bar
        Rectangle {
            id: progressBackground
            Layout.fillWidth: true
            height: 20
            color: "#333333"
            radius: 10

            // Filled part
            Rectangle {
                id: progressFill
                width: parent.width * (mediaPlayer ? (mediaPlayer ? mediaPlayer.position : 0) / Math.max(1, (mediaPlayer ? mediaPlayer.duration : 0)) : 0)
                height: parent.height
                color: "#66aaff"
                radius: 10
            }

            // Handle for seeking
            Rectangle {
                id: progressHandle
                width: 20
                height: 20
                radius: 10
                color: "#99ccff"
                x: parent.width * (mediaPlayer ? (mediaPlayer ? mediaPlayer.position : 0) / Math.max(1, (mediaPlayer ? mediaPlayer.duration : 0)) : 0) - width / 2
                y: 0

                // Dragging logic
                MouseArea {
                    anchors.fill: parent
                    drag.target: parent
                    drag.axis: Drag.XAxis
                    drag.minimumX: -width / 2
                    drag.maximumX: progressBackground.width - width / 2

                    onPositionChanged: {
                        if (drag.active && mediaPlayer) {
                            const pos = (parent.x + width / 2) / progressBackground.width;
                            (mediaPlayer ? mediaPlayer.position : 0) = pos * (mediaPlayer ? mediaPlayer.duration : 0);
                        }
                    }
                }
            }

            // Click anywhere on the progress bar to seek
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (mediaPlayer) {
                        const pos = mouseX / width;
                        (mediaPlayer ? mediaPlayer.position : 0) = pos * (mediaPlayer ? mediaPlayer.duration : 0);
                    }
                }
                // Ensure we're below the handle's mouse area in z-order
                z: progressHandle.z - 1
            }
        }

        // Duration
        Label {
            id: durationLabel
            text: {
                if (!mediaPlayer) return "0:00";

                const dur = (mediaPlayer ? mediaPlayer.duration : 0);
                const min = Math.floor(dur / 60);
                const sec = dur % 60;
                return min + ":" + (sec < 10 ? "0" : "") + sec;
            }
            color: "white"
            font.pixelSize: 16
        }
    }
}
