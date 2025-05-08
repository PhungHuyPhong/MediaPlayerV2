import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: playerControls
    color: "transparent"

    property var mediaPlayer: null
    property color activeColor: "#66aaff"
    property color buttonColor: "#333333"
    property color textColor: "white"

    // Visual feedback when player is active
    Rectangle {
        id: activeBorder
        anchors.fill: parent
        anchors.margins: -4
        color: "transparent"
        border.width: mediaPlayer && (mediaPlayer ? mediaPlayer.playing : 0) ? 2 : 0
        border.color: activeColor
        opacity: 0.7
        radius: 8
        visible: mediaPlayer && (mediaPlayer ? mediaPlayer.playing : 0)

        SequentialAnimation on border.color {
            running: mediaPlayer && (mediaPlayer ? mediaPlayer.playing : 0)
            loops: Animation.Infinite
            ColorAnimation { from: activeColor; to: Qt.lighter(activeColor, 1.3); duration: 1000 }
            ColorAnimation { from: Qt.lighter(activeColor, 1.3); to: activeColor; duration: 1000 }
        }
    }

    RowLayout {
        anchors.centerIn: parent
        spacing: 20

        // Previous button
        Button {
            id: prevButton
            icon.name: "media-skip-backward"
            icon.width: 24
            icon.height: 24
            icon.color: enabled ? textColor : "gray"

            enabled: mediaPlayer ? mediaPlayer.canGoPrevious : false

            background: Rectangle {
                implicitWidth: 60
                implicitHeight: 60
                radius: width / 2
                color: prevButton.pressed ? Qt.darker(buttonColor, 1.2) :
                       (prevButton.hovered ? Qt.lighter(buttonColor, 1.2) : buttonColor)

                Label {
                    anchors.centerIn: parent
                    text: "⏮"
                    font.pixelSize: 24
                    color: prevButton.enabled ? textColor : "gray"
                    visible: !prevButton.icon.name
                }

                // Ripple effect on click
                Rectangle {
                    id: prevRipple
                    anchors.centerIn: parent
                    width: 0
                    height: 0
                    radius: width / 2
                    color: Qt.rgba(activeColor.r, activeColor.g, activeColor.b, 0.3)
                    opacity: 0

                    PropertyAnimation {
                        id: prevRippleAnim
                        target: prevRipple
                        properties: "width,height,opacity"
                        from: 0
                        to: parent.width * 2
                        duration: 300
                        onFinished: prevRipple.opacity = 0
                    }
                }
            }

            onClicked: {
                prevRippleAnim.start()
                (mediaPlayer ? mediaPlayer.previous : 0)()
            }

            ToolTip.text: "Play previous track"
            ToolTip.visible: hovered
            ToolTip.delay: 500
        }

        // Play/Pause button
        Button {
            id: playPauseButton
            icon.name: mediaPlayer && (mediaPlayer ? mediaPlayer.playing : 0) ? "media-playback-pause" : "media-playback-start"
            icon.width: 32
            icon.height: 32
            icon.color: textColor

            background: Rectangle {
                implicitWidth: 80
                implicitHeight: 80
                radius: width / 2
                color: playPauseButton.pressed ? Qt.darker(activeColor, 1.2) :
                       (playPauseButton.hovered ? Qt.lighter(activeColor, 1.1) : activeColor)

                Label {
                    anchors.centerIn: parent
                    text: mediaPlayer && (mediaPlayer ? mediaPlayer.playing : 0) ? "⏸" : "▶"
                    font.pixelSize: 32
                    color: textColor
                    visible: !playPauseButton.icon.name
                }

                // Pulse animation when playing
                Rectangle {
                    anchors.centerIn: parent
                    width: parent.width
                    height: parent.height
                    radius: width / 2
                    color: "transparent"
                    border.width: 2
                    border.color: activeColor
                    opacity: 0
                    visible: mediaPlayer && (mediaPlayer ? mediaPlayer.playing : 0)

                    SequentialAnimation on opacity {
                        running: mediaPlayer && (mediaPlayer ? mediaPlayer.playing : 0)
                        loops: Animation.Infinite
                        NumberAnimation { from: 0; to: 0.7; duration: 800; easing.type: Easing.OutQuad }
                        NumberAnimation { from: 0.7; to: 0; duration: 800; easing.type: Easing.InQuad }
                    }
                }

                // Ripple effect on click
                Rectangle {
                    id: playRipple
                    anchors.centerIn: parent
                    width: 0
                    height: 0
                    radius: width / 2
                    color: Qt.rgba(1, 1, 1, 0.3)
                    opacity: 0

                    PropertyAnimation {
                        id: playRippleAnim
                        target: playRipple
                        properties: "width,height,opacity"
                        from: 0
                        to: parent.width * 2
                        duration: 300
                        onFinished: playRipple.opacity = 0
                    }
                }
            }

            onClicked: {
                playRippleAnim.start()
                (mediaPlayer ? mediaPlayer.playPause : 0)()
            }

            ToolTip.text: mediaPlayer && (mediaPlayer ? mediaPlayer.playing : 0) ? "Pause playback" : "Start playback"
            ToolTip.visible: hovered
            ToolTip.delay: 500
        }

        // Stop button
        Button {
            id: stopButton
            icon.name: "media-playback-stop"
            icon.width: 24
            icon.height: 24
            icon.color: textColor

            background: Rectangle {
                implicitWidth: 60
                implicitHeight: 60
                radius: width / 2
                color: stopButton.pressed ? Qt.darker(buttonColor, 1.2) :
                       (stopButton.hovered ? Qt.lighter(buttonColor, 1.2) : buttonColor)

                Label {
                    anchors.centerIn: parent
                    text: "⏹"
                    font.pixelSize: 24
                    color: textColor
                    visible: !stopButton.icon.name
                }

                // Ripple effect on click
                Rectangle {
                    id: stopRipple
                    anchors.centerIn: parent
                    width: 0
                    height: 0
                    radius: width / 2
                    color: Qt.rgba(activeColor.r, activeColor.g, activeColor.b, 0.3)
                    opacity: 0

                    PropertyAnimation {
                        id: stopRippleAnim
                        target: stopRipple
                        properties: "width,height,opacity"
                        from: 0
                        to: parent.width * 2
                        duration: 300
                        onFinished: stopRipple.opacity = 0
                    }
                }
            }

            onClicked: {
                stopRippleAnim.start()
                (mediaPlayer ? mediaPlayer.stop : 0)()
            }

            ToolTip.text: "Stop playback"
            ToolTip.visible: hovered
            ToolTip.delay: 500
        }

        // Next button
        Button {
            id: nextButton
            icon.name: "media-skip-forward"
            icon.width: 24
            icon.height: 24
            icon.color: enabled ? textColor : "gray"

            enabled: mediaPlayer ? (mediaPlayer ? mediaPlayer.canGoNext : 0) : false

            background: Rectangle {
                implicitWidth: 60
                implicitHeight: 60
                radius: width / 2
                color: nextButton.pressed ? Qt.darker(buttonColor, 1.2) :
                       (nextButton.hovered ? Qt.lighter(buttonColor, 1.2) : buttonColor)

                Label {
                    anchors.centerIn: parent
                    text: "⏭"
                    font.pixelSize: 24
                    color: nextButton.enabled ? textColor : "gray"
                    visible: !nextButton.icon.name
                }

                // Ripple effect on click
                Rectangle {
                    id: nextRipple
                    anchors.centerIn: parent
                    width: 0
                    height: 0
                    radius: width / 2
                    color: Qt.rgba(activeColor.r, activeColor.g, activeColor.b, 0.3)
                    opacity: 0

                    PropertyAnimation {
                        id: nextRippleAnim
                        target: nextRipple
                        properties: "width,height,opacity"
                        from: 0
                        to: parent.width * 2
                        duration: 300
                        onFinished: nextRipple.opacity = 0
                    }
                }
            }

            onClicked: {
                nextRippleAnim.start()
                (mediaPlayer ? mediaPlayer.next : 0)()
            }

            ToolTip.text: "Play next track"
            ToolTip.visible: hovered
            ToolTip.delay: 500
        }
    }
}
