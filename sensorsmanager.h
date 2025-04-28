#ifndef SENSORSMANAGER_H
#define SENSORSMANAGER_H

#include <QObject>
#include <QVariantMap>
#include <QTimer>
#include <memory>
#include <QSensor>
#include <QDebug>
#include <QDateTime>
#include <QRandomGenerator>
#include <QAmbientLightSensor>
#include <QProximitySensor>
#include <QAccelerometer>

class QAmbientLightSensor;
class QProximitySensor;
class QAccelerometer;

/**
 * @brief The SensorsManager class provides access to device sensors.
 *
 * This class provides a unified interface for accessing device sensors such as the
 * ambient light sensor, proximity sensor, accelerometer, and temperature sensor.
 * It supports both a real implementation using Qt Sensors and a simulated implementation
 * for testing without actual sensor hardware.
 */
class SensorsManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int ambientBrightness READ ambientBrightness NOTIFY lightChanged)
    Q_PROPERTY(bool isNear READ isNear NOTIFY proximityChanged)
    Q_PROPERTY(QVariantMap acceleration READ acceleration NOTIFY accelerometerChanged)
    Q_PROPERTY(QString gestureDetected READ gestureDetected NOTIFY gestureDetectedChanged)
    Q_PROPERTY(float temperature READ temperature NOTIFY temperatureChanged)

public:
    explicit SensorsManager(QObject *parent = nullptr);
    ~SensorsManager();

    /**
     * @brief Get the ambient brightness level
     * @return The brightness level (0-100)
     */
    int ambientBrightness() const;

    /**
     * @brief Check if an object is near the proximity sensor
     * @return True if an object is near, false otherwise
     */
    bool isNear() const;

    /**
     * @brief Get the current acceleration values
     * @return A map with "x", "y", and "z" keys for the acceleration values
     */
    QVariantMap acceleration() const;

    /**
     * @brief Get the currently detected gesture
     * @return The gesture name ("Swipe Left", "Swipe Right", "Swipe Up", "Swipe Down", "Tap", or "None")
     */
    QString gestureDetected() const;

    /**
     * @brief Get the current temperature reading
     * @return The temperature in degrees Celsius
     */
    float temperature() const;

    /**
     * @brief Enable or disable the temperature sensor
     * @param active True to enable, false to disable
     */
    Q_INVOKABLE void setTempSensorActive(bool active);

    /**
     * @brief Enable or disable the light sensor
     * @param active True to enable, false to disable
     */
    Q_INVOKABLE void setLightSensorActive(bool active);

    /**
     * @brief Enable or disable the gesture sensor
     * @param active True to enable, false to disable
     */
    Q_INVOKABLE void setGestureSensorActive(bool active);

signals:
    void lightChanged();
    void proximityChanged();
    void accelerometerChanged();
    void gestureDetectedChanged();
    void temperatureChanged();

private:
    void _initializeSensors();

    std::unique_ptr<QAmbientLightSensor> m_lightSensor;
    std::unique_ptr<QProximitySensor> m_proximitySensor;
    std::unique_ptr<QAccelerometer> m_accelerometer;

    void _handleLightReading();
    void _handleProximityReading();
    void _handleAccelerometerReading();
};
#endif // SENSORSMANAGER_H
