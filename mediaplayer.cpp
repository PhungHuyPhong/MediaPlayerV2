#include "mediaplayer.h"

MediaPlayer::MediaPlayer(QObject *parent)
    : QObject(parent)
{
    // Create playlist model
    m_playlist = std::make_unique<PlaylistModel>(this);

    // Initialize QMediaPlayer
    m_player = std::make_unique<QMediaPlayer>();
    m_audioOutput = std::make_unique<QAudioOutput>();
    m_player->setAudioOutput(m_audioOutput.get());

    // Set initial volume
    m_audioOutput->setVolume(0.5);  // 50%

    // Connect signals from QMediaPlayer
    connect(m_player.get(), &QMediaPlayer::playbackStateChanged, this, &MediaPlayer::_handlePlaybackStateChanged);
    connect(m_player.get(), &QMediaPlayer::positionChanged, this, &MediaPlayer::positionChanged);
    connect(m_player.get(), &QMediaPlayer::durationChanged, this, &MediaPlayer::durationChanged);
    connect(m_player.get(), &QMediaPlayer::mediaStatusChanged, this, [this](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia) {
            next();
        }
    });

    // Connect to playlist model signals
    connect(m_playlist.get(), &PlaylistModel::currentIndexChanged, this, &MediaPlayer::_updateTrackInfo);

    qDebug() << "MediaPlayer: Initialized";
}

MediaPlayer::~MediaPlayer()
{
    // Stop playback before destroying
    stop();
}

QString MediaPlayer::playbackState() const
{
    switch (m_player->playbackState()) {
    case QMediaPlayer::PlayingState:
        return "Playing";
    case QMediaPlayer::PausedState:
        return "Paused";
    case QMediaPlayer::StoppedState:
    default:
        return "Stopped";
    }
}

bool MediaPlayer::playing() const
{
    return m_player->playbackState() == QMediaPlayer::PlayingState;
}

int MediaPlayer::position() const
{
    return m_player->position() / 1000;  // Convert from ms to seconds
}

void MediaPlayer::setPosition(int position)
{
    m_player->setPosition(position * 1000);  // Convert from seconds to ms
    qDebug() << "MediaPlayer: Seeked to position" << position / 60 << ":" << position % 60;
}

int MediaPlayer::duration() const
{
    return m_player->duration() / 1000;  // Convert from ms to seconds
}

int MediaPlayer::volume() const
{
    return m_audioOutput->volume() * 100;  // Convert from 0-1 to 0-100
}

void MediaPlayer::setVolume(int volume)
{
    if (volume < 0 || volume > 100) {
        return;
    }

    m_audioOutput->setVolume(volume / 100.0);  // Convert from 0-100 to 0-1

    emit volumeChanged();
    qDebug() << "MediaPlayer: Volume set to" << volume << "%";
}

QString MediaPlayer::currentTrackTitle() const
{
    return m_currentTrackTitle;
}

QString MediaPlayer::currentTrackArtist() const
{
    return m_currentTrackArtist;
}

bool MediaPlayer::canGoPrevious() const
{
    return m_playlist->count() > 1;
}

bool MediaPlayer::canGoNext() const
{
    return m_playlist->count() > 1;
}

PlaylistModel* MediaPlayer::playlist() const
{
    return m_playlist.get();
}

void MediaPlayer::play()
{
    if (m_playlist->count() == 0) {
        qDebug() << "MediaPlayer: Cannot play, playlist is empty";
        return;
    }

    // Set media source if needed
    QUrl url(m_playlist->currentUrl());
    if (m_player->source() != url) {
        m_player->setSource(url);
    }

    m_player->play();
}

void MediaPlayer::pause()
{
    m_player->pause();
}

void MediaPlayer::stop()
{
    m_player->stop();
}

void MediaPlayer::playPause()
{
    if (playing()) {
        pause();
    } else {
        play();
    }
}

void MediaPlayer::next()
{
    m_playlist->next();

    // If currently playing, start playing the new track
    if (m_player->playbackState() == QMediaPlayer::PlayingState) {
        QUrl url(m_playlist->currentUrl());
        m_player->setSource(url);
        m_player->play();
    }
}

void MediaPlayer::previous()
{
    m_playlist->previous();

    // If currently playing, start playing the new track
    if (m_player->playbackState() == QMediaPlayer::PlayingState) {
        QUrl url(m_playlist->currentUrl());
        m_player->setSource(url);
        m_player->play();
    }
}

void MediaPlayer::_handlePlaybackStateChanged()
{
    emit playbackStateChanged();
    emit playingChanged();

    qDebug() << "MediaPlayer: Playback state changed to" << playbackState();
}

void MediaPlayer::_updateTrackInfo()
{
    QString currentUrl = m_playlist->currentUrl();
    QStringList parts = currentUrl.split(';');

    if (parts.size() >= 3) {
        m_currentTrackTitle = parts[0];
        m_currentTrackArtist = parts[1];
    } else {
        m_currentTrackTitle = "Unknown Track";
        m_currentTrackArtist = "Unknown Artist";
    }

    emit currentTrackChanged();
}
