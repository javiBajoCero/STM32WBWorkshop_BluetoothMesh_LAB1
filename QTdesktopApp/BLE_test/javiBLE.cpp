#include "javible.h"
#include "QTime"
#include "QCoreApplication"
//https://doc.qt.io/qt-5/qtbluetooth-le-overview.html
#include "QLowEnergyController"

//static void delay(int segundos)
//{
//    QTime dieTime= QTime::currentTime().addSecs(segundos);
//    while (QTime::currentTime() < dieTime)
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//}


javiBLE::javiBLE(QObject *parent) : QObject(parent)
{
    // Create a discovery agent and connect to its signals
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    connect(discoveryAgent, SIGNAL(canceled()),this, SLOT(deviceDiscoveryCacelledSLOT()));
    connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),this, SLOT(deviceDiscoveredSLOT(QBluetoothDeviceInfo)));
    connect(discoveryAgent, SIGNAL(deviceUpdated(QBluetoothDeviceInfo,QBluetoothDeviceInfo::Fields)),this, SLOT(deviceUpdatedSLOT(QBluetoothDeviceInfo,QBluetoothDeviceInfo::Fields)));
    connect(discoveryAgent, SIGNAL(error(QBluetoothDeviceDiscoveryAgent::Error )),this, SLOT(discoveryerrorSLOT(QBluetoothDeviceDiscoveryAgent::Error )));
    connect(discoveryAgent, SIGNAL(finished()),this, SLOT(discoveryfinishedSLOT()));




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
        emit bledevicediscovered(device.name(),device.address().toString());

       qDebug() <<"Low Energy device found. Scanning more...";
        qDebug()<< "debugging info-----------------------------------";
        qDebug()<<"name: "<<device.name();
        qDebug()<<"address: "<<device.address().toString();
        qDebug()<<"deviceUuid: "<<device.deviceUuid();
        qDebug()<<"coreConfigurations: "<<device.coreConfigurations();
        qDebug()<<"majorDeviceClass: "<<device.majorDeviceClass();
        qDebug()<<"minorDeviceClass: "<<device.minorDeviceClass();
        qDebug()<<"manufacturerData: "<<device.manufacturerData();
        qDebug()<<"manufacturerIds: "<<device.manufacturerIds();
        qDebug()<<"rssi: "<<device.rssi();
        qDebug()<<"serviceClasses: "<<device.serviceClasses();
        qDebug()<<"serviceUuids: "<<device.serviceUuids();
        qDebug()<< "--------------------------------------------------";

    }
}

void javiBLE::deviceUpdatedSLOT(const QBluetoothDeviceInfo &device, QBluetoothDeviceInfo::Fields updatedFields)
{
    qDebug() << "BLE Updated device:" << device.name() << '(' << device.address().toString() << ')'<< updatedFields ;
    if(updatedFields ==0){
        qDebug() << "updated none";
    }else {
        if((updatedFields & QBluetoothDeviceInfo::Field::RSSI)==updatedFields){
           qDebug() << "updated new rrsi: " <<device.rssi();
           emit bledeviceupdated(device.address().toString(),device.rssi(),"stm32");
        }
        if((updatedFields & QBluetoothDeviceInfo::Field::ManufacturerData)==updatedFields){
            qDebug() << "updated ManufacturerData: " <<device.manufacturerData();
        }
        if((updatedFields & QBluetoothDeviceInfo::Field::All)==updatedFields){
            qDebug() << "updated all";
            qDebug() << "updated rrsi: " <<device.rssi();
            qDebug() << "updated ManufacturerData: " <<device.manufacturerData();
        }
    }

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
    emit bleservicediscovered(uuid);
    qDebug() << "controlServiceDiscovered:";
    m_services.append(uuid);
}

void javiBLE::controlStateChanged(QLowEnergyController::ControllerState state)
{
    qDebug() << "controlStateChanged:" << state;
}

void javiBLE::serviceStateChanged(QLowEnergyService::ServiceState newstate)
{
    qDebug() << "serviceStateChanged:" << newstate;
    debugString.append("serviceStateChanged"+QString(newstate)+"\n\r");
    emit qdebug(debugString);
    if(newstate==QLowEnergyService::ServiceDiscovered){
        qDebug() <<mBLEservice->serviceName();
        debugString.append(QString(mBLEservice->serviceName())+"\n\r");
        emit qdebug(debugString);
        m_characteristics=mBLEservice->characteristics();
        for(int i=0; i < m_characteristics.size();i++)
        {
            qDebug() << "m_characteristics name: "<< m_characteristics.at(i).name()<<"uuid: "<< m_characteristics.at(i).uuid()<<"data: "<< m_characteristics.at(i).value();

            QString properties;
            if(m_characteristics.at(i).properties()==QLowEnergyCharacteristic::Unknown){
                properties="Unknown";
            }else{
                if(m_characteristics.at(i).properties()&QLowEnergyCharacteristic::Broadcasting){
                  properties+=" Broadcasting";
                }
                if(m_characteristics.at(i).properties()&QLowEnergyCharacteristic::Read){
                  properties+=" Read";
                }
                if(m_characteristics.at(i).properties()&QLowEnergyCharacteristic::WriteNoResponse){
                  properties+=" WriteNoResponse";
                }
                if(m_characteristics.at(i).properties()&QLowEnergyCharacteristic::Write){
                  properties+=" Write";
                }
                if(m_characteristics.at(i).properties()&QLowEnergyCharacteristic::Notify){
                  properties+=" Notify";
                }
                if(m_characteristics.at(i).properties()&QLowEnergyCharacteristic::Indicate){
                  properties+=" Indicate";
                }
                if(m_characteristics.at(i).properties()&QLowEnergyCharacteristic::WriteSigned){
                  properties+=" WriteSigned";
                }
                if(m_characteristics.at(i).properties()&QLowEnergyCharacteristic::ExtendedProperty){
                  properties+=" ExtendedProperty";
                }

            }
//            switch (m_characteristics.at(i).properties()) {
//            case QLowEnergyCharacteristic::Unknown:
//                properties="Unknown";
//                break;
//            case QLowEnergyCharacteristic::Broadcasting:
//                 properties="Broadcasting";
//                break;
//            case QLowEnergyCharacteristic::Read:
//                properties="Read";
//                break;
//            case QLowEnergyCharacteristic::WriteNoResponse:
//                properties="WriteNoResponse";
//                break;
//            case QLowEnergyCharacteristic::Write:
//                properties="Write";
//                break;
//            case QLowEnergyCharacteristic::Notify:
//                properties="Notify";
//                break;
//            case QLowEnergyCharacteristic::Indicate:
//                properties="Indicate";
//                break;
//            case QLowEnergyCharacteristic::WriteSigned:
//                properties="WriteSigned";
//                break;
//            case QLowEnergyCharacteristic::ExtendedProperty:
//                properties="ExtendedProperty";
//                break;
//            default:
//                properties="no properties?";
//                break;

//            }
            emit blecharacteristicdiscovered(m_characteristics.at(i).uuid(),properties);
            debugString.append(QString(m_characteristics.at(i).name())+"\n\r");
            //debugString.append(QString(m_characteristics.at(i).properties())+"\n\r");
            emit qdebug(debugString);
            qDebug() <<m_characteristics.at(i).name();
            qDebug() <<m_characteristics.at(i).properties();
        }
    }
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

void javiBLE::scanBLE()
{
    debugString.append("SCAN started\n\r");
    emit qdebug(debugString);

    if(mBLEservice!=nullptr){
        mBLEservice->disconnect();
    }
//    mBLEservice->disconnect();
//    mBLEservice->~QLowEnergyService();
//    mBLEservice=nullptr;

    if(mBLEControl!=nullptr){
        mBLEControl->disconnectFromDevice();
        mBLEControl->disconnect();
    }
//    mBLEControl->disconnectFromDevice();
//    mBLEControl->disconnect();
//    mBLEControl->~QLowEnergyController();
//    mBLEControl=nullptr;

    m_devices.clear();
    m_services.clear();
    m_characteristics.clear();
    discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);

}

void javiBLE::connnectAndScanforServicesBLE(QString addr)
{
    if(mBLEservice!=nullptr){
        mBLEservice->disconnect();
    }
    if(mBLEControl!=nullptr){
        mBLEControl->disconnectFromDevice();
        mBLEControl->disconnect();
    }

//    m_services.clear();
//    m_characteristics.clear();

    qDebug() << "connnectAndScanforServicesBLE:";
    debugString.append("connnectAndScanforServicesBLE\n\r");
    emit qdebug(debugString);

    for(int i=0; i < m_devices.size();i++)
    {
        if(m_devices.at(i).deviceUuid() == QBluetoothUuid(addr))
        {
            qDebug() <<addr;
            debugString.append(addr+"\n\r");
            emit qdebug(debugString);

            mBLEControl = QLowEnergyController::createCentral(m_devices.at(i), this);
            connect(mBLEControl, SIGNAL(connected()),                                              this, SLOT(controlConected()));
            connect(mBLEControl, SIGNAL(connectionUpdated(QLowEnergyConnectionParameters)),        this, SLOT(controlConnectionUpdated(QLowEnergyConnectionParameters)));
            connect(mBLEControl, SIGNAL(disconnected()),                                           this, SLOT(controlDisonnected()));
            connect(mBLEControl, SIGNAL(discoveryFinished()),                                      this, SLOT(controlDiscoveryFinished()));
            connect(mBLEControl, SIGNAL(error(QLowEnergyController::Error)),                       this, SLOT(controlError(QLowEnergyController::Error)));
            connect(mBLEControl, SIGNAL(serviceDiscovered(QBluetoothUuid)),                        this, SLOT(controlServiceDiscovered(QBluetoothUuid)));
            connect(mBLEControl, SIGNAL(stateChanged(QLowEnergyController::ControllerState)),      this, SLOT(controlStateChanged(QLowEnergyController::ControllerState)));
            mBLEControl->connectToDevice();
            break;
        }
    }

}

void javiBLE::connectServiceAndScanforcharacteristicsBLE(QString uuid)
{

            mBLEservice=mBLEControl->createServiceObject(QBluetoothUuid(uuid), this);
            connect(mBLEservice, SIGNAL(stateChanged(QLowEnergyService::ServiceState)),                 this, SLOT(serviceStateChanged(QLowEnergyService::ServiceState)));
            connect(mBLEservice, SIGNAL(characteristicChanged(QLowEnergyCharacteristic,QByteArray)),    this, SLOT(serviceCharacteristicChanged(QLowEnergyCharacteristic,QByteArray)));
            connect(mBLEservice, SIGNAL(characteristicRead(QLowEnergyCharacteristic,QByteArray)),       this, SLOT(serviceCharacteristicRead(QLowEnergyCharacteristic,QByteArray)));
            connect(mBLEservice, SIGNAL(characteristicWritten(QLowEnergyCharacteristic,QByteArray)),    this, SLOT(serviceCharacteristicWritten(QLowEnergyCharacteristic,QByteArray)));
            connect(mBLEservice, SIGNAL(descriptorRead(QLowEnergyDescriptor,QByteArray)),               this, SLOT(serviceDescriptorRead(QLowEnergyDescriptor,QByteArray)));
            connect(mBLEservice, SIGNAL(descriptorWritten(QLowEnergyDescriptor,QByteArray)),            this, SLOT(serviceDescriptorWritten(QLowEnergyDescriptor,QByteArray)));
            connect(mBLEservice, SIGNAL(error(QLowEnergyService::ServiceError)),                        this, SLOT(serviceError(QLowEnergyService::ServiceError)));
            mBLEservice->discoverDetails();

}

void javiBLE::notifythischaracteristic(QString addr)
{
//    QLowEnergyDescriptor descriptor;
//    mBLEservice->readDescriptor(descriptor);
//    qDebug() <<descriptor.name();
//    qDebug() <<descriptor.uuid();
//    qDebug() <<descriptor.value();
//    qDebug() <<descriptor.type();

//    QLowEnergyCharacteristic characteristic;
//    mBLEservice->readCharacteristic(characteristic);
//    qDebug() <<characteristic.name();
//    qDebug() <<characteristic.uuid();
//    qDebug() <<characteristic.value();
//    qDebug() <<characteristic.properties();
    for(int i=0; i < m_characteristics.size();i++)
    {
        if(m_characteristics.at(i).Notify){
            qDebug()<<"found a notifiable characteristic " <<m_characteristics.at(i).uuid() ;
            mBLEcharacteristic=m_characteristics.at(i);
            mBLEdescriptor=mBLEcharacteristic.descriptor(QBluetoothUuid::ClientCharacteristicConfiguration);
            if(mBLEdescriptor.isValid()){
                mBLEservice->writeDescriptor(mBLEdescriptor, QByteArray::fromHex("0100"));
            }
        }

    }

}
