import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id:root
    visibility: "Windowed"//"Maximized"//"FullScreen"//"Windowed"
    width: 640
    height: 480
    visible: true
    title: qsTr("Luxae's DonLight flasher")
    color: "white"
    opacity: 1

    LeftMenu{
        id:leftmenu
        height: root.height
        width: root.width/5
        surficeColor: "#696152"
        bottomColor: "#2d2a24"
    }

}
