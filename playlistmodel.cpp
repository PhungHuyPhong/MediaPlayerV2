#include "playlistmodel.h"

PlaylistModel::PlaylistModel(QObject *parent)
    : QStringListModel(parent)
    , m_currentIndex(-1)
{
    // Initialize with an empty list
    setStringList(QStringList());
}

void PlaylistModel::setCurrentIndex(int index)
{
    if (index >= -1 && index < count() && index != m_currentIndex) {
        m_currentIndex = index;
        emit currentIndexChanged();
        qDebug() << "PlaylistModel: Current index set to" << m_currentIndex + 1;
    }
}

int PlaylistModel::currentIndex() const
{
    return m_currentIndex;
}

void PlaylistModel::addItem(const QString &url)
{
    QStringList list = stringList();
    list.append(url);
    setStringList(list);

    emit countChanged();

    // If this is the first item, set it as current
    if (count() == 1) {
        setCurrentIndex(0);
    }

    qDebug() << "PlaylistModel: Added track" << url;
}

void PlaylistModel::removeItem(int index)
{
    if (index < 0 || index >= count()) {
        return;
    }

    QStringList list = stringList();
    list.removeAt(index);
    setStringList(list);

    // If we removed the current item, update the current index
    if (index == m_currentIndex) {
        if (count() > 0) {
            setCurrentIndex(qMin(index, count() - 1));
        } else {
            setCurrentIndex(-1);
        }
    } else if (index < m_currentIndex) {
        // If we removed an item before the current one, decrement the current index
        setCurrentIndex(m_currentIndex - 1);
    }

    emit countChanged();

    qDebug() << "PlaylistModel: Removed track at index" << index + 1;
}

int PlaylistModel::count() const
{
    return stringList().count();
}

QString PlaylistModel::getUrl(int index) const
{
    if (index < 0 || index >= count()) {
        return QString();
    }

    return stringList().at(index);
}

QString PlaylistModel::currentUrl() const
{
    if (m_currentIndex < 0 || m_currentIndex >= count()) {
        return QString();
    }

    return getUrl(m_currentIndex);
}

void PlaylistModel::next()
{
    if (count() <= 1) {
        return;
    }

    int nextIndex = (m_currentIndex + 1) % count();
    setCurrentIndex(nextIndex);

    qDebug() << "PlaylistModel: Advanced to next track:" << nextIndex;
}

void PlaylistModel::previous()
{
    if (count() <= 1) {
        return;
    }

    int prevIndex = (m_currentIndex - 1 + count()) % count();
    setCurrentIndex(prevIndex);

    qDebug() << "PlaylistModel: Moved to previous track:" << prevIndex;
}
