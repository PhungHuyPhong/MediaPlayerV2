import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: bluetoothPanel
    color: "#487eb0" //1
    radius: 5

    property var bluetoothManager: null

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10

        // Header
        Label {
            text: qsTr("Bluetooth")
            font.pixelSize: 18
            font.bold: true
            color: "#7f8fa6" //2
        }

        // Bluetooth switch
        Switch {
            id: btSwitch
            text: qsTr("Bluetooth")
            checked: (bluetoothManager ? bluetoothManager.bluetoothEnabled : false)
            onCheckedChanged: bluetoothManager.setBluetoothEnabled(checked)
        }

        // Scan button
        Button {
            text: (bluetoothManager ? bluetoothManager.scanning : false) ? qsTr("Scanning...") : qsTr("Scan for Devices")
            enabled: btSwitch.checked && !(bluetoothManager ? bluetoothManager.scanning : false)
            Layout.fillWidth: true

            onClicked: {
                bluetoothManager.startScan();
            }
        }

        // Connected device info
        ColumnLayout {
            Layout.fillWidth: true
            spacing: 5
            visible: (bluetoothManager ? bluetoothManager.connected : false)

            Label {
                text: qsTr("Connected Device:")
                font.bold: true
                color: "#7f8fa6" //2
            }

            Label {
                text: (bluetoothManager ? (bluetoothManager ? bluetoothManager.connected : false)DeviceName : "N/A")
                color: "#e84118" //3
                font.pixelSize: 16
            }

            Button {
                text: qsTr("Disconnect")
                Layout.fillWidth: true
                onClicked: bluetoothManager.disconnectFromDevice()
            }
        }

        // Device list
        ListView {
            id: deviceListView
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            visible: !(bluetoothManager ? bluetoothManager.connected : false)

            model: {
                var count = bluetoothManager.deviceCount();
                return count;
            }

            delegate: ItemDelegate {
                width: deviceListView.width
                height: 60

                onClicked: {
                    bluetoothManager.connectToDevice(index);
                }

                RowLayout {
                    anchors.fill: parent
                    anchors.margins: 10
                    spacing: 10

                    // Icon based on device type
                    Item {
                        Layout.preferredWidth: 40
                        Layout.preferredHeight: 40

                        Text {
                            anchors.centerIn: parent
                            text: {
                                var device = bluetoothManager.getDeviceAt(index);
                                if (device.type === "Audio Device") {
                                    return "🔊";
                                } else if (device.type === "Phone") {
                                    return "📱";
                                } else if (device.type === "Computer") {
                                    return "💻";
                                } else {
                                    return "📶";
                                }
                            }
                            font.pixelSize: 24
                        }
                    }

                    ColumnLayout {
                        Layout.fillWidth: true
                        spacing: 4

                        Label {
                            text: {
                                var device = bluetoothManager.getDeviceAt(index);
                                return device.name || "Unknown Device";
                            }
                            font.bold: true
                            color: "#7f8fa6" //2
                        }

                        Label {
                            text: {
                                var device = bluetoothManager.getDeviceAt(index);
                                return device.address;
                            }
                            font.pixelSize: 12
                            color: "#9c88ff" //4
                        }
                    }

                    // Signal strength indicator
                    Label {
                        text: {
                            var device = bluetoothManager.getDeviceAt(index);
                            var rssi = device.rssi || -100;

                            if (rssi > -60) return "●●●●";
                            else if (rssi > -70) return "●●●○";
                            else if (rssi > -80) return "●●○○";
                            else if (rssi > -90) return "●○○○";
                            else return "○○○○";
                        }
                        font.pixelSize: 14
                        color: "#e84118" //3
                    }
                }
            }

            ScrollBar.vertical: ScrollBar {}
        }

        // Empty state
        Label {
            text: qsTr("No devices found")
            visible: deviceListView.count === 0 && !(bluetoothManager ? bluetoothManager.connected : false)
            Layout.alignment: Qt.AlignCenter
            color: "#9c88ff" //4
        }

        BusyIndicator {
            visible: (bluetoothManager ? bluetoothManager.scanning : false)
            Layout.alignment: Qt.AlignCenter
            running: visible
        }
    }
}
