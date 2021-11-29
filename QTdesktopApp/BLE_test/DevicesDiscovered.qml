import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
Item {
    id: root
    clip:true
    property color surficeColor: "lightgreen"
    property color bottomColor:  "lightgreen"
    anchors.left: parent.left
    Row{
        id:rows
        spacing: 3
        anchors.fill:parent

        Column{
            id:columnbuttons
            width: parent.width/rows.children.length
            SimpleButton{
                width:parent.width
                height:100
                baseColor: "#00699e"
                text: "Scan BLE"
                textcolor:"white"
                texthoverColor:root.bottomColor
                function action(){//this is how we pass the javascript function to every button press
                    console.log(text)
                    columndevices.children=[]
                    columnservices.children=[]
                    columncharacteristics.children=[]
                    javible.scanBLE();
                }
            }

            Connections{
                target: javible
                function onBledevicediscovered(name,addr){
                console.log(name);console.log(addr);
                createDevice(name,addr);
                }
            }
        }

        Column{
            id:columndevices
            width: parent.width/rows.children.length

            Connections{
                target: javible
                function onBleservicediscovered(addr){
                console.log(addr);
                createService(addr);
                }
            }

        }

        Column{
            id:columnservices
            width: parent.width/rows.children.length

            Connections{
                target: javible
                function onBlecharacteristicdiscovered(uuid,flags){
                console.log(uuid);console.log(flags);
                createCharacteristic(uuid,flags);
                }
            }
        }

        Column{
            id:columncharacteristics
            width: parent.width/rows.children.length
        }
    }



    function createDevice(name,addr){
        var DeviceButton= Qt.createQmlObject('DeviceButton{}',columndevices,"DynamicallyLocated");
        DeviceButton.width=columndevices.width
        DeviceButton.height=100
        DeviceButton.name=name
        DeviceButton.addr=addr
        DeviceButton.textcolor="white"
        DeviceButton.texthoverColor="red"
        //looks still bad to me
        //https://martin.ankerl.com/2009/12/09/how-to-create-random-colors-programmatically/
        var golden_ratio_conjugate = 0.618033988749895
        var r = (Math.random() + golden_ratio_conjugate)%1
        var g = (Math.random() + golden_ratio_conjugate)%1
        var b = (Math.random() + golden_ratio_conjugate)%1
        DeviceButton.baseColor=Qt.rgba(r,g,b,1);
    }

    function createService(addr){
        var ServiceButton= Qt.createQmlObject('ServiceButton{}',columnservices,"DynamicallyLocated");
        ServiceButton.width=columnservices.width
        ServiceButton.height=100
        ServiceButton.name="service:"
        ServiceButton.addr=addr
        ServiceButton.textcolor="white"
        ServiceButton.texthoverColor="red"
        //looks still bad to me
        //https://martin.ankerl.com/2009/12/09/how-to-create-random-colors-programmatically/
        var golden_ratio_conjugate = 0.618033988749895
        var r = (Math.random() + golden_ratio_conjugate)%1
        var g = (Math.random() + golden_ratio_conjugate)%1
        var b = (Math.random() + golden_ratio_conjugate)%1
        ServiceButton.baseColor=Qt.rgba(r,g,b,1);
    }

    function createCharacteristic(uuid,flags){
        var ServiceButton= Qt.createQmlObject('CharacteristicButton{}',columncharacteristics,"DynamicallyLocated");
        ServiceButton.width=columnservices.width
        ServiceButton.height=100
        ServiceButton.name="characteristic:"
        ServiceButton.addr=uuid
        ServiceButton.flags=flags
        ServiceButton.textcolor="white"
        ServiceButton.texthoverColor="red"
        //looks still bad to me
        //https://martin.ankerl.com/2009/12/09/how-to-create-random-colors-programmatically/
        var golden_ratio_conjugate = 0.618033988749895
        var r = (Math.random() + golden_ratio_conjugate)%1
        var g = (Math.random() + golden_ratio_conjugate)%1
        var b = (Math.random() + golden_ratio_conjugate)%1
        ServiceButton.baseColor=Qt.rgba(r,g,b,1);
    }

}
