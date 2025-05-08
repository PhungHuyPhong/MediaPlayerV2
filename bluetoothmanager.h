#ifndef BLUETOOTHMANAGER_H
#define BLUETOOTHMANAGER_H

#include <QObject>
#include <QList>
#include <QVariantList>
#include <QVariantMap>
#include <QTimer>
#include <memory>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothDeviceInfo>
#include <QDebug>
#include <QRandomGenerator>

/**
 * @brief The BluetoothManager class provides Bluetooth device discovery and connection.
 *
 * This class provides functionality for scanning for Bluetooth devices, listing available
 * devices, and connecting to them. It supports both a real implementation using Qt Bluetooth
 * and a simulated implementation for testing without actual Bluetooth hardware.
 */
class BluetoothManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool scanning READ isScanning NOTIFY scanningChanged)
    Q_PROPERTY(QVariantList devices READ devices NOTIFY devicesChanged)
    Q_PROPERTY(QVariantMap connectedDevice READ connectedDevice NOTIFY connectionChanged)

    Q_PROPERTY(bool bluetoothEnabled READ bluetoothEnabled WRITE setBluetoothEnabled NOTIFY bluetoothEnabledChanged)
    Q_PROPERTY(QString connectedDeviceName READ connectedDeviceName NOTIFY connectedDeviceNameChanged)

public:
    explicit BluetoothManager(QObject *parent = nullptr);
    ~BluetoothManager();

    /**
     * @brief Check if device discovery is currently in progress
     * @return True if scanning, false otherwise
     */
    bool isScanning() const;

    /**
     * @brief Get the list of discovered devices
     * @return A list of devices, each as a map with "name" and "address" keys
     */
    QVariantList devices() const;

    /**
     * @brief Get information about the currently connected device
     * @return A map with "name" and "address" keys, or an empty map if no device is connected
     */
    QVariantMap connectedDevice() const;

    /**
     * @brief Start scanning for Bluetooth devices
     */
    Q_INVOKABLE void startDiscovery();

    /**
     * @brief Stop scanning for Bluetooth devices
     */
    Q_INVOKABLE void stopDiscovery();

    /**
     * @brief Connect to a Bluetooth device by address
     * @param address The address of the device to connect to
     * @return True if connection was successful, false otherwise
     */
    Q_INVOKABLE bool connectToDevice(const QString &address);

    /**
     * @brief Disconnect from the currently connected device
     */
    Q_INVOKABLE void disconnect();

    bool bluetoothEnabled() const;

    void setBluetoothEnabled(bool enabled);

    QString connectedDeviceName() const;

signals:
    void scanningChanged();
    void devicesChanged();
    void connectionChanged();
    void errorOccurred(const QString &error);
    void bluetoothEnabledChanged();
    void connectedDeviceNameChanged();
private:
    bool m_isScanning;
    QList<QBluetoothDeviceInfo> m_devices;
    QBluetoothDeviceInfo m_connectedDevice;
    bool m_isConnected;

    std::unique_ptr<QBluetoothDeviceDiscoveryAgent> m_discoveryAgent;

    void _deviceDiscovered(const QBluetoothDeviceInfo &info);
    void _discoveryFinished();
    void _discoveryError(QBluetoothDeviceDiscoveryAgent::Error error);

    // Helper function to convert device info to a map
    QVariantMap _deviceInfoToMap(const QBluetoothDeviceInfo &info) const;
};

#endif // BLUETOOTHMANAGER_H
