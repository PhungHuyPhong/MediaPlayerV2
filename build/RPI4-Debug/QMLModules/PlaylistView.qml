import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: playlistViewContainer
    color: Qt.rgba(0.2, 0.2, 0.3, 0.7)
    radius: 5

    property var playlistModel: null
    property var mediaPlayer: null

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10

        Label {
            text: "Playlist"
            font.pixelSize: 20
            font.bold: true
            color: "white"
        }

        // Playlist actions
        RowLayout {
            Layout.fillWidth: true
            spacing: 10

            Button {
                text: "Add Track"
                icon.name: "list-add"
                onClicked: {
                    // In a real app, this would open a file dialog
                    if (playlistModel) {
                        (playlistModel ? playlistModel.addItem : 0)("New Track;New Artist;180");
                    }
                }
                ToolTip.text: "Add a new track to the playlist"
                ToolTip.visible: hovered
            }

            Button {
                text: "Remove Track"
                icon.name: "list-remove"
                enabled: playlistView.currentIndex >= 0
                onClicked: {
                    if (playlistModel && playlistView.currentIndex >= 0) {
                        (playlistModel ? playlistModel.removeItem : 0)(playlistView.currentIndex);
                    }
                }
                ToolTip.text: "Remove selected track from the playlist"
                ToolTip.visible: hovered
            }
        }

        // Playlist view
        ListView {
            id: playlistView
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: playlistModel

            // Update currentIndex when the model's currentIndex changes
            Binding {
                target: playlistView
                property: "currentIndex"
                value: playlistModel ? (playlistModel ? playlistModel.currentIndex : 0) : -1
            }

            delegate: Rectangle {
                width: playlistView.width
                height: 50
                color: index === (playlistModel ? playlistModel.currentIndex : 0) ? "#55aaff" :
                        (index === playlistView.currentIndex ? "#33669a" : "transparent")
                radius: 5

                RowLayout {
                    anchors.fill: parent
                    anchors.margins: 5
                    spacing: 5

                    Label {
                        text: (index + 1) + "."
                        color: "white"
                        font.bold: true
                        Layout.minimumWidth: 30
                    }

                    ColumnLayout {
                        Layout.fillWidth: true
                        spacing: 2

                        Label {
                            text: {
                                const parts = modelData.split(';');
                                return parts[0] || "Unknown Track";
                            }
                            color: "white"
                            font.bold: true
                            Layout.fillWidth: true
                        }

                        Label {
                            text: {
                                const parts = modelData.split(';');
                                return parts[1] || "Unknown Artist";
                            }
                            color: "lightgray"
                            Layout.fillWidth: true
                        }
                    }

                    Label {
                        text: {
                            const parts = modelData.split(';');
                            if (parts.length >= 3) {
                                const dur = parseInt(parts[2]);
                                const min = Math.floor(dur / 60);
                                const sec = dur % 60;
                                return min + ":" + (sec < 10 ? "0" : "") + sec;
                            }
                            return "";
                        }
                        color: "lightgray"
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        playlistView.currentIndex = index;
                    }
                    onDoubleClicked: {
                        if (playlistModel && mediaPlayer) {
                            (playlistModel ? playlistModel.setCurrentIndex : 0)(index);
                            (mediaPlayer ? mediaPlayer.play : 0)();
                        }
                    }
                }
            }
        }

        // Empty state
        Label {
            text: "No tracks in playlist. Click 'Add Track' to add some music."
            color: "lightgray"
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
            visible: playlistModel ? (playlistModel ? playlistModel.count : 0) === 0 : true
        }
    }
}
