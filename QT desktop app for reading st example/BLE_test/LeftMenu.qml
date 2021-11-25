import QtQuick 2.12

Item {
    id: root
    clip:true
    property color surficeColor: "lightgreen"
    property color bottomColor:  "lightgreen"
    anchors.left: parent.left

    Rectangle{
        anchors.fill: root
        color:root.bottomColor

        Grid{
            id:comPortsgrid
            spacing: 10
            anchors.top: parent.top
            columns:4
            width:parent.width
        }

        Column{
            spacing: 10
            anchors.bottom: parent.bottom

            Rectangle{
                id:bobinfo
                height:100
                width:root.width
                color:root.surficeColor;
                clip: true
                Column{
                    id:bobtexts
                    Text {
                        id:bobuuid
                        text: ""
                        font.pixelSize: bobinfo.height/(bobtexts.children.length) -5
                        color:"white"
                    }
                    Text {
                        id:bobhwinfo
                        text: ""
                        font.pixelSize: bobinfo.height/(bobtexts.children.length) -5
                        color:"white"
                    }
                    Text {
                        id:bobbuildinfo
                        text: ""
                        font.pixelSize: bobinfo.height/(bobtexts.children.length) -10
                        color:"white"
                    }
                    Text {
                        id:bobgitinfo
                        text: ""
                        font.pixelSize: bobinfo.height/(bobtexts.children.length) -10
                        color:"white"
                    }
                    Connections{
                        target: javible
                        //void inforeceived(QVariant configdescriptor,QVariant hwversion,QVariant fwversion,QVariant uuidstring,QVariant patternsdescriptor,QVariant gitinfo,QVariant buildinfo);
                        function onInforeceived(name,hw,noinfo1,uuidstring,noinfo2,gitinfo,buildinfo){
//                            if( name==="BOB"){
//                                bobuuid.text="BOB uuid: "+uuidstring
//                                bobhwinfo.text="hw version: "+hw;
//                                bobbuildinfo.text=buildinfo
//                                bobgitinfo.text=gitinfo
//                            }
                        }
                    }
                }
            }

            Rectangle{
                id:comportfeedbackboxTX
                clip:true
                height:25
                width:root.width
                color:root.surficeColor;
                opacity:0.3
                Text{
                    id:comportfeedbacktextTX
                    anchors.top: parent.top
                    anchors.left: parent.left
                    font.pixelSize: parent.height -3
                    text: ""
                    color:"white";


                }
                Connections{
                    target: serialCOMs
                    function onSerialtextsent(txt){
                    comportfeedbacktextTX.text="Tx:"+txt
                    }
                }
            }

            Rectangle{
                id:comportfeedbackboxRX
                clip:true
                height:25
                width:root.width
                color:root.surficeColor;
                opacity:0.3
                Text{
                    id:comportfeedbacktextRX
                    anchors.top: parent.top
                    anchors.left: parent.left
                    font.pixelSize: parent.height -3
                    text: ""
                    color:"white";


                }
                Connections{
                    target: serialCOMs
                    function onSerialtextreceived(txt){
                    comportfeedbacktextRX.text="Rx:"+txt
                    }
                }
            }

            Grid{
                id:buttonsgrid
                //rows:1
                columns:3
                //spacing: 3
                SimpleButton{
                    width:root.width/buttonsgrid.columns
                    height:100
                    baseColor: root.surficeColor
                    text: "TEST"
                    function action(){//this is how we pass the javascript function to every button press
                        serialCOMs.writeSerialString(text)
                    }
                }

                SimpleButton{
                    id:testbutton
                    width:root.width/buttonsgrid.columns
                    height:100
                    baseColor: root.surficeColor
                    text: "reset todo"
                    function action(){//this is how we pass the javascript function to every button press
                        serialCOMs.writeSerialString(text)
                    }
                }

                SimpleButton{
                    width:root.width/buttonsgrid.columns
                    height:100
                    baseColor: root.surficeColor
                    text: "reset bob"
                    function action(){//this is how we pass the javascript function to every button press
                        serialCOMs.writeSerialString(text)
                        serialCOMs.closeSerial();
                    }
                }
            }

            Grid{
                id:gridNumbers
                rows:6
                columns:4

                //spacing: 3
                Repeater {
                    model: 9
                    LatchingButton{
                        width:root.width/gridNumbers.columns
                        height:100
                        baseColor: root.surficeColor
                        text: index+1
                        function action(){//this is how we pass the javascript function to every button press
                            //serialCOMs.writeSerial(text)
                            serialCOMs.updateVirtualButtonPad(index+1);
                        }
                        function actionpressed(){}
                        function actionnotpressed(){}
                    }
                }

                LatchingButton{
                    id:turningbuttonleft
                    width:root.width/gridNumbers.columns
                    height:100
                    baseColor: root.surficeColor
                    text: "<-"
                    function action(){//this is how we pass the javascript function to every button press
                        //serialCOMs.writeSerial(text)
                        serialCOMs.turningsignals("turningleft");
                    }
                    function actionpressed(){}
                    function actionnotpressed(){}
                }

                LatchingButton{
                    id:turningbuttonright
                    width:root.width/gridNumbers.columns
                    height:100
                    baseColor: root.surficeColor
                    text: "->"
                    function action(){//this is how we pass the javascript function to every button press
                        //serialCOMs.writeSerial(text)
                        serialCOMs.turningsignals("turningright");
                    }
                    function actionpressed(){}
                    function actionnotpressed(){}
                }
                Repeater {
                    model: 13
                    LatchingButton{
                        width:root.width/gridNumbers.columns
                        height:100
                        baseColor: root.surficeColor
                        text: index+1+9+2
                        function action(){//this is how we pass the javascript function to every button press
                            //serialCOMs.writeSerial(text)
                            serialCOMs.updateVirtualButtonPad(index+1+9+2);
                        }
                        function actionpressed(){}
                        function actionnotpressed(){}
                    }
                }

            }
        }
        Connections{
            target: serialCOMs
            //    void comdiscovered(QVariant data,int alreadyopened);
            function onComdiscovered(data,alreadyopened){
            createCOMportButton(data,alreadyopened);
            }

            function onComerase(){
            eraseCOMportButtons();
            }
        }
    }

    function createCOMportButton(t,alreadyopened){
        var dynamically_COM= Qt.createQmlObject(
                    'LatchingButton{
function action(){}

function actionpressed(){
serialCOMs.openSerial(text)
}
function actionnotpressed(){
serialCOMs.closeSerial(text)
}
}',comPortsgrid,"DynamicallyLocated");//this is how we pass the javascript function to every button press
        dynamically_COM.text=t
        dynamically_COM.width=(comPortsgrid.width/comPortsgrid.columns)-comPortsgrid.spacing;
        dynamically_COM.height=100;
        dynamically_COM.baseColor= root.surficeColor
        if(alreadyopened===1){
            dynamically_COM.state="pressed"
        }else{

        }

    }

    function eraseCOMportButtons(){
        comPortsgrid.children=[]
    }
}
