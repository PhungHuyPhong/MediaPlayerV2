#include "bluetoothmanager.h"
\
bool m_bluetoothEnabled = false;
QString m_connectedDeviceName;

BluetoothManager::BluetoothManager(QObject *parent)
    : QObject(parent)
    , m_isScanning(false)
    , m_isConnected(false)
{

    // Initialize the Bluetooth discovery agent
    m_discoveryAgent = std::make_unique<QBluetoothDeviceDiscoveryAgent>(this);

    // Connect signals from the discovery agent
    connect(m_discoveryAgent.get(), &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &BluetoothManager::_deviceDiscovered);
    connect(m_discoveryAgent.get(), &QBluetoothDeviceDiscoveryAgent::finished,
            this, &BluetoothManager::_discoveryFinished);
    connect(m_discoveryAgent.get(), &QBluetoothDeviceDiscoveryAgent::errorOccurred,
            this, &BluetoothManager::_discoveryError);

    qDebug() << "BluetoothManager: Initialized";
}

BluetoothManager::~BluetoothManager()
{
    if (m_discoveryAgent && m_isScanning) {
        m_discoveryAgent->stop();
    }
}

bool BluetoothManager::isScanning() const
{
    return m_isScanning;
}

QVariantList BluetoothManager::devices() const
{
    QVariantList result;
    for (const auto &device : m_devices) {
        result.append(_deviceInfoToMap(device));
    }
    return result;
}

QVariantMap BluetoothManager::connectedDevice() const
{
    if (m_isConnected) {
        return _deviceInfoToMap(m_connectedDevice);
    }
    return QVariantMap();
}

void BluetoothManager::startDiscovery()
{
    if (m_isScanning) {
        return;
    }

    qDebug() << "BluetoothManager: Starting device discovery";
    m_isScanning = true;
    emit scanningChanged();

    m_discoveryAgent->start();
}

void BluetoothManager::stopDiscovery()
{
    if (!m_isScanning) {
        return;
    }

    qDebug() << "BluetoothManager: Stopping device discovery";

    m_discoveryAgent->stop();

    m_isScanning = false;
    emit scanningChanged();
}

bool BluetoothManager::connectToDevice(const QString &address)
{
    // Find the device with the given address
    for (const auto &device : m_devices) {
        if (device.address().toString() == address) {
            qDebug() << "BluetoothManager: Connecting to device" << device.name();

            // In a real implementation, we would establish a connection here
            // For now, we just simulate a successful connection
            m_connectedDevice = device;
            m_isConnected = true;
            emit connectionChanged();

            qDebug() << "BluetoothManager: Connected to" << device.name();
            return true;
        }
    }

    qDebug() << "BluetoothManager: Device with address" << address << "not found";
    return false;
}

void BluetoothManager::disconnect()
{
    if (m_isConnected) {
        qDebug() << "BluetoothManager: Disconnecting from" << m_connectedDevice.name();
        m_isConnected = false;
        emit connectionChanged();
    }
}

void BluetoothManager::_deviceDiscovered(const QBluetoothDeviceInfo &info)
{
    qDebug() << "BluetoothManager: Discovered device" << info.name() << info.address().toString();

    // Check if the device is already in our list
    for (const auto &device : m_devices) {
        if (device.address() == info.address()) {
            return;
        }
    }

    // Add the device to our list
    m_devices.append(info);
    emit devicesChanged();
}

void BluetoothManager::_discoveryFinished()
{
    qDebug() << "BluetoothManager: Discovery finished, found" << m_devices.size() << "devices";
    m_isScanning = false;
    emit scanningChanged();
}

void BluetoothManager::_discoveryError(QBluetoothDeviceDiscoveryAgent::Error error)
{
    QString errorString = m_discoveryAgent->errorString();
    qDebug() << "BluetoothManager: Discovery error:" << error << "-" << errorString;

    emit errorOccurred(errorString);

    m_isScanning = false;
    emit scanningChanged();
}

QVariantMap BluetoothManager::_deviceInfoToMap(const QBluetoothDeviceInfo &info) const
{
    QVariantMap map;
    map["name"] = info.name();
    map["address"] = info.address().toString();
    return map;
}

bool BluetoothManager::bluetoothEnabled() const {
    return m_bluetoothEnabled;
}

void BluetoothManager::setBluetoothEnabled(bool enabled) {
    if (m_bluetoothEnabled != enabled) {
        m_bluetoothEnabled = enabled;
        emit bluetoothEnabledChanged();
    }
}

QString BluetoothManager::connectedDeviceName() const {
    return m_connectedDeviceName;
}
