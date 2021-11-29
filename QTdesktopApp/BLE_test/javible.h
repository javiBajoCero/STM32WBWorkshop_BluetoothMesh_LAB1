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

    void scanBLE();
    void connnectAndScanforServicesBLE(QString addr);
    void connectServiceAndScanforcharacteristicsBLE(QString uuid);

    void notifythischaracteristic(QString addr);

signals:
     void bledevicediscovered(QVariant name,QVariant addr);
     void bleservicediscovered(QVariant addr);
     void blecharacteristicdiscovered(QVariant uuid,QVariant flags);
     void qdebug(QVariant data);
     void bledeviceupdated(QVariant addr,QVariant rssi,QVariant manufact);
private:
    QString debugString;

    QList<QBluetoothDeviceInfo>     m_devices;
    QList<QBluetoothUuid>           m_services;
    QList<QLowEnergyCharacteristic> m_characteristics;
    QLowEnergyController            *mBLEControl = nullptr;
    QLowEnergyService               *mBLEservice = nullptr;
    QLowEnergyCharacteristic        mBLEcharacteristic;
    QLowEnergyDescriptor            mBLEdescriptor;
    QBluetoothDeviceDiscoveryAgent *discoveryAgent=nullptr;
};

#endif // JAVIBLE_H
