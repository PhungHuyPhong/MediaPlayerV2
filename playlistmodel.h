#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QObject>
#include <QObject>
#include <QStringListModel>
#include <QStringList>
#include <QDebug>

/**
 * @brief The PlaylistModel class manages a list of tracks with their metadata.
 *
 * This class extends QStringListModel to provide additional functionality specific to
 * a media player playlist. It stores track information (title, artist, duration) in
 * a semicolon-separated format: "title;artist;duration_in_seconds"
 */
class PlaylistModel : public QStringListModel
{
    Q_OBJECT
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged)
    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    explicit PlaylistModel(QObject *parent = nullptr);

    /**
     * @brief Set the current track index
     * @param index The index to set as current
     */
    void setCurrentIndex(int index);

    /**
     * @brief Get the current track index
     * @return The current track index
     */
    int currentIndex() const;

    /**
     * @brief Add a track to the playlist
     * @param url Track information in format "title;artist;duration"
     */
    Q_INVOKABLE void addItem(const QString &url);

    /**
     * @brief Remove a track from the playlist
     * @param index The index of the track to remove
     */
    Q_INVOKABLE void removeItem(int index);

    /**
     * @brief Get the number of tracks in the playlist
     * @return The number of tracks
     */
    Q_INVOKABLE int count() const;

    /**
     * @brief Get the track information at a specific index
     * @param index The index of the track
     * @return The track information string
     */
    Q_INVOKABLE QString getUrl(int index) const;

    /**
     * @brief Get the current track information
     * @return The current track information string
     */
    QString currentUrl() const;

    /**
     * @brief Move to the next track in the playlist
     */
    Q_INVOKABLE void next();

    /**
     * @brief Move to the previous track in the playlist
     */
    Q_INVOKABLE void previous();

signals:
    void currentIndexChanged();
    void countChanged();

private:
    int m_currentIndex;
};

#endif // PLAYLISTMODEL_H
