#ifndef JAVIBLE_H
#define JAVIBLE_H

#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothDeviceInfo>
#include <QLowEnergyController>

#include <QDebug>
#include <QList>

class javiBLE : public QObject
{
    Q_OBJECT
public:
    explicit javiBLE(QObject *parent = nullptr);

public slots:
    void deviceDiscoveryCacelledSLOT();
    void deviceDiscoveredSLOT(const QBluetoothDeviceInfo &device);
    void deviceUpdatedSLOT(const QBluetoothDeviceInfo  &device,QBluetoothDeviceInfo::Fields updatedFields);
    void discoveryerrorSLOT(const QBluetoothDeviceDiscoveryAgent::Error error);
    void discoveryfinishedSLOT();

    void controlConected();
    void controlConnectionUpdated(const QLowEnergyConnectionParameters &parameters);
    void controlDisonnected();
    void controlDiscoveryFinished();
    void controlError(QLowEnergyController::Error error);
    void controlServiceDiscovered(const QBluetoothUuid &uuid);
    void controlStateChanged(QLowEnergyController::ControllerState state);

    void serviceStateChanged(QLowEnergyService::ServiceState newstate);
    void serviceCharacteristicChanged(const QLowEnergyCharacteristic &info,const QByteArray &value);
    void serviceCharacteristicRead(const QLowEnergyCharacteristic &info,const QByteArray &value);
    void serviceCharacteristicWritten(const QLowEnergyCharacteristic &info,const QByteArray &value);
    void serviceDescriptorRead(const QLowEnergyDescriptor &info,const QByteArray &value);
    void serviceDescriptorWritten(const QLowEnergyDescriptor &info,const QByteArray &value);
    void serviceError(QLowEnergyService::ServiceError error);

signals:


private:
    QList<QBluetoothDeviceInfo> m_devices;
    QLowEnergyController *mBLEControl = nullptr;
    QLowEnergyService    *mBLEservice = nullptr;
};

#endif // JAVIBLE_H
