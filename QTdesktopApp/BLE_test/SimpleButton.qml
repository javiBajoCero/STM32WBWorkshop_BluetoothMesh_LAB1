import QtQuick 2.12

Item {
    id:root
    clip: true
    property int enabledbutton: 1

    property color baseColor: "black"
    property color hoverColor: baseColor
    property color texthoverColor: "black"

    property string text: "no text set"
    property string textcolor: "lightblue"

    property int depth: 3

    property int textrotation: 0

    property int textsize: (buttonsurfice.width/8)

        Rectangle{
            id:buttonsurfice
            clip: true
            color: root.baseColor
            //border.color: "white"

            x:0
            y:0
            width: root.width-root.depth
            height: root.height-root.depth

            Text {
                id: buttontext
                anchors.centerIn: parent
                text: root.text
                color: root.textcolor
                font.pointSize: textsize
                font.letterSpacing: 0
                rotation: textrotation
            }
            MouseArea{
                id:mousearea
                anchors.fill:parent
                hoverEnabled: true

                onEntered:{
                    parent.color =root.hoverColor
                    buttontext.color =root.texthoverColor
                }

                onExited: {
                    parent.color =root.baseColor
                    buttontext.color = root.textcolor
                }

                onPressed:{
                    //console.log("click"+mouse.button)
                    if(enabledbutton===1){
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
}
