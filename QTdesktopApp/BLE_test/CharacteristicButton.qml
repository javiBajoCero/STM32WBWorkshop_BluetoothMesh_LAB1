import QtQuick 2.12

Item {
    id:root
    clip: true
    property int enabledbutton: 1

    property color baseColor: "black"
    property color hoverColor: baseColor
    property color texthoverColor: "black"

    property string name: "no text set"
    property string addr: "no text set"
    property string flags: "no text set"
    property string textcolor: "lightblue"

    property int depth: 3

    property int textrotation: 0

        Rectangle{
            id:buttonsurfice
            clip: true
            color: parent.baseColor
            //border.color: "white"

            x:0
            y:0
            width: root.width-root.depth
            height: root.height-root.depth

            Column{
                id:textcolumn
                anchors.fill: parent
                anchors.centerIn: buttonsurfice.Center
                Text {
                    id: buttonname
                    text: root.name
                    color: root.textcolor
                    font.pointSize: buttonsurfice.width/20
                    font.letterSpacing: 0
                    rotation: textrotation
                }
                Text {
                    id: butonaddr
                    text: root.addr
                    color: root.textcolor
                    font.pointSize: buttonsurfice.width/20
                    font.letterSpacing: 0
                    rotation: textrotation
                }

                Text {
                    id: butonflags
                    text: root.flags
                    color: root.textcolor
                    font.pointSize: buttonsurfice.width/20
                    font.letterSpacing: 0
                    rotation: textrotation
                }
            }


            MouseArea{
                id:mousearea
                anchors.fill:parent
                hoverEnabled: true

                onEntered:{
                    parent.color =root.hoverColor
                    buttonname.color =root.texthoverColor
                    butonaddr.color =root.texthoverColor
                }

                onExited: {
                    parent.color =root.baseColor
                    buttonname.color = root.textcolor
                    butonaddr.color =root.textcolor
                }

                onPressed:{
                    //console.log("click"+mouse.button)
                    if(enabledbutton===1){
                      console.log(buttonname.text);
                        action();

                    }
                        buttonsurfice.x= buttonsurfice.x +root.depth
                        buttonsurfice.y= buttonsurfice.y +root.depth

                }

                onReleased: {
                    buttonsurfice.x= buttonsurfice.x -root.depth
                    buttonsurfice.y= buttonsurfice.y -root.depth

                }

            }

        }

        function action(){//this is how we pass the javascript function to every button press
            if(butonflags.text==" Notify"){
                console.log(" Notify action()")
                javible.notifythischaracteristic(root.addr);
            }

            //javible.connnectAndScanforServicesBLE(root.addr);
        }
}
