import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: sensorPanel
    color: Qt.rgba(0.3, 0.3, 0.4, 0.7)
    radius: 5

    property var sensorsManager: null

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10

        Label {
            text: "Sensors"
            font.pixelSize: 20
            font.bold: true
            color: "white"
        }

        GridLayout {
            columns: 2
            Layout.fillWidth: true
            columnSpacing: 10
            rowSpacing: 8

            // Temperature
            Label {
                text: "Temperature:"
                color: "white"
                font.bold: true
            }

            Label {
                text: sensorsManager ? (sensorsManager ? sensorsManager.temperature : 0).toFixed(1) + "°C" : "N/A"
                color: "white"
            }

            // Ambient Light
            Label {
                text: "Ambient Light:"
                color: "white"
                font.bold: true
            }

            Label {
                text: sensorsManager ? (sensorsManager ? sensorsManager.ambientBrightness : 0) + "%" : "N/A"
                color: "white"
            }

            // Proximity
            Label {
                text: "Proximity:"
                color: "white"
                font.bold: true
            }

            Label {
                text: sensorsManager ? ((sensorsManager ? sensorsManager.isNear : 0) ? "Object Detected" : "No Object") : "N/A"
                color: "white"
            }

            // Gesture Detection
            Label {
                text: "Last Gesture:"
                color: "white"
                font.bold: true
            }

            Label {
                id: gestureLabel
                text: sensorsManager ? (sensorsManager ? sensorsManager.gestureDetected : 0) : "None"
                color: sensorsManager && (sensorsManager ? sensorsManager.gestureDetected : 0) === "None" ? "lightgray" : "#aaddff"
                font.bold: sensorsManager && (sensorsManager ? sensorsManager.gestureDetected : 0) !== "None"

                // Animation for gesture detection
                SequentialAnimation {
                    id: gestureAnimation
                    running: sensorsManager && (sensorsManager ? sensorsManager.gestureDetected : 0) !== "None"
                    loops: 1

                    ColorAnimation {
                        target: gestureLabel
                        property: "color"
                        from: "#aaddff"
                        to: "#ffffff"
                        duration: 200
                    }

                    ColorAnimation {
                        target: gestureLabel
                        property: "color"
                        from: "#ffffff"
                        to: "#aaddff"
                        duration: 500
                    }
                }
            }
        }

        // Sensors control
        GroupBox {
            title: "Sensor Controls"
            Layout.fillWidth: true

            background: Rectangle {
                color: Qt.rgba(0.2, 0.2, 0.3, 0.5)
                radius: 3
                border.color: "#666666"
            }

            label: Label {
                text: parent.title
                color: "white"
                font.bold: true
            }

            ColumnLayout {
                width: parent.width

                // Enable/disable controls
                GridLayout {
                    columns: 2
                    Layout.fillWidth: true

                    Label {
                        text: "Temperature:"
                        color: "white"
                    }

                    Switch {
                        checked: true
                        onToggled: {
                            if (sensorsManager) {
                                 (sensorsManager ? sensorsManager.setTempSensorActive : 0)(checked);
                            }
                        }
                    }

                    Label {
                        text: "Light Sensor:"
                        color: "white"
                    }

                    Switch {
                        checked: true
                        onToggled: {
                            if (sensorsManager) {
                                (sensorsManager ? sensorsManager.setLightSensorActive : 0)(checked);
                            }
                        }
                    }

                    Label {
                        text: "Gesture Detection:"
                        color: "white"
                    }

                    Switch {
                        checked: true
                        onToggled: {
                            if (sensorsManager) {
                                 (sensorsManager ? sensorsManager.setGestureSensorActive : 0)(checked);
                            }
                        }
                    }
                }
            }
        }

        // Gesture guide
        GroupBox {
            title: "Gesture Guide"
            Layout.fillWidth: true

            background: Rectangle {
                color: Qt.rgba(0.2, 0.2, 0.3, 0.5)
                radius: 3
                border.color: "#666666"
            }

            label: Label {
                text: parent.title
                color: "white"
                font.bold: true
            }

            ColumnLayout {
                width: parent.width

                Label {
                    text: "• Swipe Left: Next Track"
                    color: "white"
                }

                Label {
                    text: "• Swipe Right: Previous Track"
                    color: "white"
                }

                Label {
                    text: "• Swipe Up: Volume Up"
                    color: "white"
                }

                Label {
                    text: "• Swipe Down: Volume Down"
                    color: "white"
                }

                Label {
                    text: "• Tap: Play/Pause"
                    color: "white"
                }
            }
        }

        // Spacer
        Item {
            Layout.fillHeight: true
        }
    }
}
