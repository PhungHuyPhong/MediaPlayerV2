#include "sensorsmanager.h"

SensorsManager::SensorsManager(QObject *parent)
    : QObject(parent)
{
    _initializeSensors();
    qDebug() << "SensorsManager: Initialized";
}

SensorsManager::~SensorsManager()
{
    // Clean up sensor objects
    if (m_lightSensor) {
        m_lightSensor->stop();
    }
    if (m_proximitySensor) {
        m_proximitySensor->stop();
    }
    if (m_accelerometer) {
        m_accelerometer->stop();
    }
}

int SensorsManager::ambientBrightness() const
{
    if (m_lightSensor && m_lightSensor->reading()) {
        // Convert from the QAmbientLightReading::LightLevel to 0-100
        switch (m_lightSensor->reading()->lightLevel()) {
        case QAmbientLightReading::Dark:
            return 0;
        case QAmbientLightReading::Twilight:
            return 25;
        case QAmbientLightReading::Light:
            return 50;
        case QAmbientLightReading::Bright:
            return 75;
        case QAmbientLightReading::Sunny:
            return 100;
        default:
            return 50;
        }
    }
    return 50;  // Default value
}

bool SensorsManager::isNear() const
{
    if (m_proximitySensor && m_proximitySensor->reading()) {
        return m_proximitySensor->reading()->close();
    }
    return false;  // Default value
}

QVariantMap SensorsManager::acceleration() const
{
    QVariantMap result;

    if (m_accelerometer && m_accelerometer->reading()) {
        result["x"] = m_accelerometer->reading()->x();
        result["y"] = m_accelerometer->reading()->y();
        result["z"] = m_accelerometer->reading()->z();
    } else {
        result["x"] = 0.0f;
        result["y"] = 0.0f;
        result["z"] = 9.8f;  // Earth's gravity
    }

    return result;
}

QString SensorsManager::gestureDetected() const
{
    // In a real implementation, we would use a gesture sensor
    // or analyze the accelerometer data to detect gestures
    return "None";
}

float SensorsManager::temperature() const
{
    // In a real implementation, we would use a temperature sensor
    return 22.5f;  // Default value
}

void SensorsManager::setTempSensorActive(bool active)
{
    qDebug() << "SensorsManager: Temperature sensor set to" << (active ? "active" : "inactive");
    // In a real implementation, we would enable/disable the temperature sensor
}

void SensorsManager::setLightSensorActive(bool active)
{
    if (m_lightSensor) {
        if (active) {
            m_lightSensor->start();
        } else {
            m_lightSensor->stop();
        }
        qDebug() << "SensorsManager: Light sensor set to" << (active ? "active" : "inactive");
    }
}

void SensorsManager::setGestureSensorActive(bool active)
{
    // In a real implementation, we would enable/disable the gesture sensor
    qDebug() << "SensorsManager: Gesture sensor set to" << (active ? "active" : "inactive");
}

void SensorsManager::_initializeSensors()
{
    // Initialize the ambient light sensor
    m_lightSensor = std::make_unique<QAmbientLightSensor>();
    if (m_lightSensor->connectToBackend()) {
        connect(m_lightSensor.get(), &QAmbientLightSensor::readingChanged, this, &SensorsManager::_handleLightReading);
        m_lightSensor->start();
    } else {
        qDebug() << "SensorsManager: Failed to connect to ambient light sensor backend";
    }

    // Initialize the proximity sensor
    m_proximitySensor = std::make_unique<QProximitySensor>();
    if (m_proximitySensor->connectToBackend()) {
        connect(m_proximitySensor.get(), &QProximitySensor::readingChanged, this, &SensorsManager::_handleProximityReading);
        m_proximitySensor->start();
    } else {
        qDebug() << "SensorsManager: Failed to connect to proximity sensor backend";
    }

    // Initialize the accelerometer
    m_accelerometer = std::make_unique<QAccelerometer>();
    if (m_accelerometer->connectToBackend()) {
        connect(m_accelerometer.get(), &QAccelerometer::readingChanged, this, &SensorsManager::_handleAccelerometerReading);
        m_accelerometer->start();
    } else {
        qDebug() << "SensorsManager: Failed to connect to accelerometer backend";
    }
}

void SensorsManager::_handleLightReading()
{
    emit lightChanged();
}

void SensorsManager::_handleProximityReading()
{
    emit proximityChanged();
}

void SensorsManager::_handleAccelerometerReading()
{
    emit accelerometerChanged();
}
