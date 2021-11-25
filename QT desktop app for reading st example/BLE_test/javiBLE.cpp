#include "javible.h"
#include "QTime"
#include "QCoreApplication"
//https://doc.qt.io/qt-5/qtbluetooth-le-overview.html
#include "QLowEnergyController"

static void delay(int segundos)
{
    QTime dieTime= QTime::currentTime().addSecs(segundos);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


javiBLE::javiBLE(QObject *parent) : QObject(parent)
{
    // Create a discovery agent and connect to its signals
    QBluetoothDeviceDiscoveryAgent *discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    connect(discoveryAgent, SIGNAL(canceled()),this, SLOT(deviceDiscoveryCacelledSLOT()));
    connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),this, SLOT(deviceDiscoveredSLOT(QBluetoothDeviceInfo)));
    connect(discoveryAgent, SIGNAL(deviceUpdated(QBluetoothDeviceInfo,QBluetoothDeviceInfo::Fields)),this, SLOT(deviceUpdatedSLOT(QBluetoothDeviceInfo,QBluetoothDeviceInfo::Fields)));
    connect(discoveryAgent, SIGNAL(error(QBluetoothDeviceDiscoveryAgent::Error )),this, SLOT(discoveryerrorSLOT(QBluetoothDeviceDiscoveryAgent::Error )));
    connect(discoveryAgent, SIGNAL(finished()),this, SLOT(discoveryfinishedSLOT()));

    // Start a discovery
    discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
  qDebug() <<"delay javiBLE";
  delay(3);

}

void javiBLE::deviceDiscoveryCacelledSLOT()
{
    qDebug() << "BLE discovery cancelled:";
}

void javiBLE::deviceDiscoveredSLOT(const QBluetoothDeviceInfo &device)
{
    // If device is LowEnergy-device, add it to the list
    if (device.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration)
    {
        qDebug() << "BLE Found new device:" << device.name() << '(' << device.address().toString() << ')';
        m_devices.append(QBluetoothDeviceInfo(device));
        qDebug() <<"Low Energy device found. Scanning more...";


        //Create a Controller
        if(device.name()=="MY_CUSTOM"){
             qDebug() <<"bing";
             mBLEControl = QLowEnergyController::createCentral(device, this);

             connect(mBLEControl, SIGNAL(connected()),                                              this, SLOT(controlConected()));
             connect(mBLEControl, SIGNAL(connectionUpdated(QLowEnergyConnectionParameters)),        this, SLOT(controlConnectionUpdated(QLowEnergyConnectionParameters)));
             connect(mBLEControl, SIGNAL(disconnected()),                                           this, SLOT(controlDisonnected()));
             connect(mBLEControl, SIGNAL(discoveryFinished()),                                      this, SLOT(controlDiscoveryFinished()));
             connect(mBLEControl, SIGNAL(error(QLowEnergyController::Error)),                       this, SLOT(controlError(QLowEnergyController::Error)));
             connect(mBLEControl, SIGNAL(serviceDiscovered(QBluetoothUuid)),                        this, SLOT(controlServiceDiscovered(QBluetoothUuid)));
             connect(mBLEControl, SIGNAL(stateChanged(QLowEnergyController::ControllerState)),      this, SLOT(controlStateChanged(QLowEnergyController::ControllerState)));

             mBLEControl->connectToDevice();
        }

    }
}

void javiBLE::deviceUpdatedSLOT(const QBluetoothDeviceInfo &device, QBluetoothDeviceInfo::Fields updatedFields)
{
    qDebug() << "BLE Updated device:" << device.name() << '(' << device.address().toString() << ')'<< updatedFields ;
}

void javiBLE::discoveryerrorSLOT(const QBluetoothDeviceDiscoveryAgent::Error error)
{
     qDebug() << "BLE discovery error:" << error;
}

void javiBLE::discoveryfinishedSLOT()
{
    qDebug() << "BLE discovery finished:";
}

void javiBLE::controlConected()
{
     qDebug() << "controlConected";
     mBLEControl->discoverServices();
}

void javiBLE::controlConnectionUpdated(const QLowEnergyConnectionParameters &parameters)
{
    qDebug() << "controlConnectionUpdated: ";// <<parameters;
}

void javiBLE::controlDisonnected()
{
    qDebug() << "controlDisonnected";
}

void javiBLE::controlDiscoveryFinished()
{
    qDebug() << "controlDiscoveryFinished";

}

void javiBLE::controlError(QLowEnergyController::Error error)
{
    qDebug() << "controlError:" << error;
}

void javiBLE::controlServiceDiscovered(const QBluetoothUuid &uuid)
{
    qDebug() << "controlServiceDiscovered:" << uuid;
    if(uuid==QBluetoothUuid(QString("{0000fe40-cc7a-482a-984a-7f2ed5b3e58f}"))){
        mBLEservice=mBLEControl->createServiceObject(uuid, this);

        connect(mBLEservice, SIGNAL(stateChanged(QLowEnergyService::ServiceState)),                 this, SLOT(serviceStateChanged(QLowEnergyService::ServiceState)));
        connect(mBLEservice, SIGNAL(characteristicChanged(QLowEnergyCharacteristic,QByteArray)),    this, SLOT(serviceCharacteristicChanged(QLowEnergyCharacteristic,QByteArray)));
        connect(mBLEservice, SIGNAL(characteristicRead(QLowEnergyCharacteristic,QByteArray)),       this, SLOT(serviceCharacteristicRead(QLowEnergyCharacteristic,QByteArray)));
        connect(mBLEservice, SIGNAL(characteristicWritten(QLowEnergyCharacteristic,QByteArray)),    this, SLOT(serviceCharacteristicWritten(QLowEnergyCharacteristic,QByteArray)));
        connect(mBLEservice, SIGNAL(descriptorRead(QLowEnergyDescriptor,QByteArray)),               this, SLOT(serviceDescriptorRead(QLowEnergyDescriptor,QByteArray)));
        connect(mBLEservice, SIGNAL(descriptorWritten(QLowEnergyDescriptor,QByteArray)),            this, SLOT(serviceDescriptorWritten(QLowEnergyDescriptor,QByteArray)));
        connect(mBLEservice, SIGNAL(error(QLowEnergyService::ServiceError)),                        this, SLOT(serviceError(QLowEnergyService::ServiceError)));
        qDebug() <<"delay controlServiceDiscovered";
        delay(3);
        mBLEservice->discoverDetails();
        qDebug() <<"delay discoverDetails";
        delay(30);

    }
}

void javiBLE::controlStateChanged(QLowEnergyController::ControllerState state)
{
    qDebug() << "controlStateChanged:" << state;
}

void javiBLE::serviceStateChanged(QLowEnergyService::ServiceState newstate)
{
    qDebug() << "serviceStateChanged:" << newstate;
}

void javiBLE::serviceCharacteristicChanged(const QLowEnergyCharacteristic &info, const QByteArray &value)
{
      qDebug() << "serviceCharacteristicChanged:" <<value;
}

void javiBLE::serviceCharacteristicRead(const QLowEnergyCharacteristic &info, const QByteArray &value)
{
    qDebug() << "serviceCharacteristicRead:" <<value;
}

void javiBLE::serviceCharacteristicWritten(const QLowEnergyCharacteristic &info, const QByteArray &value)
{
    qDebug() << "serviceCharacteristicWritten:" <<value;
}

void javiBLE::serviceDescriptorRead(const QLowEnergyDescriptor &info, const QByteArray &value)
{
    qDebug() << "serviceDescriptorRead:" <<value;
}

void javiBLE::serviceDescriptorWritten(const QLowEnergyDescriptor &info, const QByteArray &value)
{
    qDebug() << "serviceDescriptorWritten:" <<value;
}

void javiBLE::serviceError(QLowEnergyService::ServiceError error)
{
    qDebug() << "serviceError:" <<error;
}
