#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QTimer>
#include <memory>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "playlistmodel.h"

class PLaylistModel;

/**
 * @brief The MediaPlayer class provides a Qt-based media player implementation.
 *
 * This class provides a unified interface for media playback, whether using the real
 * QMediaPlayer (when available) or a simulated implementation (when not). It handles
 * the core media player functionality like playback control, volume adjustment, and
 * track navigation.
 */
class MediaPlayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString playbackState READ playbackState NOTIFY playbackStateChanged)
    Q_PROPERTY(bool playing READ playing NOTIFY playingChanged)
    Q_PROPERTY(int position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(int duration READ duration NOTIFY durationChanged)
    Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(QString currentTrackTitle READ currentTrackTitle NOTIFY currentTrackChanged)
    Q_PROPERTY(QString currentTrackArtist READ currentTrackArtist NOTIFY currentTrackChanged)
    Q_PROPERTY(bool canGoPrevious READ canGoPrevious NOTIFY currentTrackChanged)
    Q_PROPERTY(bool canGoNext READ canGoNext NOTIFY currentTrackChanged)

public:
    explicit MediaPlayer(QObject *parent = nullptr);
    ~MediaPlayer();

    /**
     * @brief Get the current playback state
     * @return The playback state as a string (Playing, Paused, Stopped)
     */
    QString playbackState() const;

    /**
     * @brief Check if the player is currently playing
     * @return True if playing, false otherwise
     */
    bool playing() const;

    /**
     * @brief Get the current playback position
     * @return The position in seconds
     */
    int position() const;

    /**
     * @brief Set the current playback position
     * @param position The position in seconds
     */
    void setPosition(int position);

    /**
     * @brief Get the duration of the current track
     * @return The duration in seconds
     */
    int duration() const;

    /**
     * @brief Get the current volume level
     * @return The volume level (0-100)
     */
    int volume() const;

    /**
     * @brief Set the volume level
     * @param volume The volume level (0-100)
     */
    void setVolume(int volume);

    /**
     * @brief Get the title of the current track
     * @return The track title
     */
    QString currentTrackTitle() const;

    /**
     * @brief Get the artist of the current track
     * @return The track artist
     */
    QString currentTrackArtist() const;

    /**
     * @brief Check if it's possible to go to the previous track
     * @return True if previous track is available
     */
    bool canGoPrevious() const;

    /**
     * @brief Check if it's possible to go to the next track
     * @return True if next track is available
     */
    bool canGoNext() const;

    /**
     * @brief Get the playlist model
     * @return The playlist model
     */
    PlaylistModel* playlist() const;

    /**
     * @brief Start playback of the current track
     */
    Q_INVOKABLE void play();

    /**
     * @brief Pause playback
     */
    Q_INVOKABLE void pause();

    /**
     * @brief Stop playback and reset position
     */
    Q_INVOKABLE void stop();

    /**
     * @brief Toggle between play and pause
     */
    Q_INVOKABLE void playPause();

    /**
     * @brief Play the next track in the playlist
     */
    Q_INVOKABLE void next();

    /**
     * @brief Play the previous track in the playlist
     */
    Q_INVOKABLE void previous();

    /**
     * @brief Update track info from the playlist
     * This is public to allow initial setup in main()
     */
    void _updateTrackInfo();

signals:
    void playbackStateChanged();
    void positionChanged();
    void durationChanged();
    void volumeChanged();
    void currentTrackChanged();
    void playingChanged();

private:
    std::unique_ptr<PlaylistModel> m_playlist;

    std::unique_ptr<QMediaPlayer> m_player;
    std::unique_ptr<QAudioOutput> m_audioOutput;

    void _handlePlaybackStateChanged();

    QString m_currentTrackTitle;
    QString m_currentTrackArtist;
};

#endif // MEDIAPLAYER_H
