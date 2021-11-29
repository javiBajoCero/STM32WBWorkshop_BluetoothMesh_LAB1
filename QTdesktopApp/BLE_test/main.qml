import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15

Window {
    id:root
    visibility: "Maximized"//"Maximized"//"FullScreen"//"Windowed"
//    width: 640
//    height: 480
    visible: true
    title: qsTr("BLE stuff")
    color: "#525150"
    opacity: 1
    Column{
        id:maincolumn
        anchors.fill:parent
        DevicesDiscovered{
            id:devicespanel
            height: parent.height
            width: parent.width
            surficeColor: "#696152"
            bottomColor: root.color
        }

//        Rectangle{
//            id:qdebugconsole
//            clip:true
//            height:parent.height/2
//            width:parent.width
//            color:"#696152";
//            opacity:1
//            Text{
//                id:feedbackqdebugtext
//                anchors.top: parent.top
//                anchors.left: parent.left
//                font.pixelSize: parent.height/50
//                text: ""
//                color:"white";


//            }
//            Connections{
//                target: javible
//                function onQdebug(data){
//                feedbackqdebugtext.text=data
//                }
//            }
//        }
    }


}
