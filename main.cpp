#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QCommandLineParser>
#include <QDebug>
#include <QTimer>

#include "mediaplayer.h"
#include "playlistmodel.h"
#include "bluetoothmanager.h"
#include "sensorsmanager.h"

/**
 * Helper function to register a gesture handler that connects to the appropriate
 * MediaPlayer actions based on the gesture detected
 */
void setupGestureHandling(SensorsManager *sensors, MediaPlayer *player);

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setApplicationName("Smart Media Player");
    app.setOrganizationName("Smart Media Player");
    app.setOrganizationDomain("smartmediaplayer.example.com");


    // Parse command line arguments
    QCommandLineParser parser;
    parser.setApplicationDescription("Smart Media Player - A Qt-based media player with IoT features");
    parser.addHelpOption();
    parser.addVersionOption();

    // Add option for headless mode
    QCommandLineOption headlessOption(QStringList() << "headless", "Run in headless mode (no GUI)");
    parser.addOption(headlessOption);

    // Process the command line arguments
    parser.process(app);

    // Check if headless mode is requested
    bool headlessMode = parser.isSet(headlessOption);

    // Create instances of our main classes
    MediaPlayer mediaPlayer;
    BluetoothManager bluetoothManager;
    SensorsManager sensorsManager;

    // Connect the gesture handler
    setupGestureHandling(&sensorsManager, &mediaPlayer);

    // Add some sample tracks
    mediaPlayer.playlist()->addItem("Sample Track 1;Artist 1;180");  // 3:00
    mediaPlayer.playlist()->addItem("Sample Track 2;Artist 2;240");  // 4:00
    mediaPlayer.playlist()->addItem("Sample Track 3;Artist 3;200");  // 3:20
    mediaPlayer.playlist()->addItem("Sample Track 4;Artist 4;210");  // 3:30
    mediaPlayer._updateTrackInfo();  // Ensure track info is updated

    qDebug() << "Initialized Smart Media Player with" << mediaPlayer.playlist()->count() << "tracks";

    if (!headlessMode) {
        // Create QML engine and set context properties
        QQmlApplicationEngine engine;

        // Set our C++ objects as context properties for QML
        engine.rootContext()->setContextProperty("mediaPlayer", &mediaPlayer);
        engine.rootContext()->setContextProperty("playlistModel", mediaPlayer.playlist());
        engine.rootContext()->setContextProperty("bluetoothManager", &bluetoothManager);
        engine.rootContext()->setContextProperty("sensorsManager", &sensorsManager);

        // Load the main QML file
        engine.loadFromModule("MediaPlayerV2", "Main");

        if (engine.rootObjects().isEmpty()) {
            qWarning() << "Failed to load QML interface";
            return -1;
        }
    } else {
        // Headless mode - just print periodic status updates
        QTimer statusTimer;
        statusTimer.setInterval(5000);  // Every 5 seconds

        QObject::connect(&statusTimer, &QTimer::timeout, [&]() {
            qDebug() << "=== Player Status ===";
            qDebug() << "Current track:" << mediaPlayer.currentTrackTitle() << "-" << mediaPlayer.currentTrackArtist();
            qDebug() << "Status:" << mediaPlayer.playbackState();
            qDebug() << "Position:" << mediaPlayer.position() / 60 << ":" << mediaPlayer.position() % 60
                     << "/" << mediaPlayer.duration() / 60 << ":" << mediaPlayer.duration() % 60;
            qDebug() << "Volume:" << mediaPlayer.volume() << "%";

            qDebug() << "=== Sensor Data ===";
            qDebug() << "Temperature:" << sensorsManager.temperature() << "°C";
            qDebug() << "Light level:" << sensorsManager.ambientBrightness() << "%";
            qDebug() << "Gesture:" << sensorsManager.gestureDetected();
        });

        statusTimer.start();

        // Start playback in headless mode
        mediaPlayer.play();
    }

    return app.exec();
}

void setupGestureHandling(SensorsManager *sensors, MediaPlayer *player)
{
    QObject::connect(sensors, &SensorsManager::gestureDetectedChanged, [=]() {
        QString gesture = sensors->gestureDetected();

        if (gesture == "None") {
            return;
        }

        if (gesture == "Swipe Left") {
            qDebug() << "Gesture detected: Swipe Left - Next track";
            player->next();
        } else if (gesture == "Swipe Right") {
            qDebug() << "Gesture detected: Swipe Right - Previous track";
            player->previous();
        } else if (gesture == "Swipe Up") {
            int newVolume = qMin(100, player->volume() + 5);
            qDebug() << "Gesture detected: Swipe Up - Increase volume to" << newVolume << "%";
            player->setVolume(newVolume);
        } else if (gesture == "Swipe Down") {
            int newVolume = qMax(0, player->volume() - 5);
            qDebug() << "Gesture detected: Swipe Down - Decrease volume to" << newVolume << "%";
            player->setVolume(newVolume);
        } else if (gesture == "Tap") {
            qDebug() << "Gesture detected: Tap - Play/Pause";
            player->playPause();
        }
    });
}
