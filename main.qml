import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window{
    id:root
    visible: true
    width: 1200
    height: 800
    title: qsTr("TJU-Keyboard")
    color: "black"
    property int currentIndex: backend.currentIndex
    property int choose: backend.choose
    property int serialPortState: backend.serialPortState
    property int keyState: backend.keyState
    property int rowCoordinate: backend.rowCoordinate
    property int colCoordinate: backend.colCoordinate
    property int intensity: backend.intensityDisplay
    signal pressed(string keyText)
    signal del()
    Keyboard{
        id:keyboard
        anchors.centerIn:parent
        currentIndex: root.currentIndex
        choose: root.choose
        onKeyChoosed: pressed(keyText)
        onDel: root.del()

    }
    onPressed:result.insert(result.cursorPosition,keyText)
    onDel:result.remove(result.cursorPosition-1,result.cursorPosition)
    //onOpen: backend.openSerialPort()
    TextField{
        id: result
        y:80
        width:parent.width
        cursorVisible: true
        placeholderText: "Begin to Type"
        text:""
    }
    Text{
        id:gooInit_idx
        width:150
        height:30
        x:10
        y:500
        text:"goodInit"
        font.pixelSize: 20
        color:"white"
    }
    Rectangle{
        id: goodInit
        x:10
        y:530
        width:100
        height:30
        color:"white"
        TextInput{
            id:goodInit_text
            width: 100
            height: 30
            anchors.centerIn: parent
            cursorVisible: true
            onTextChanged: backend.setGoodInitThreshold(goodInit_text.text)
        }
    }

    onSerialPortStateChanged: {
        if(serialPortState==0)
            openserial.color="white"
        else if(serialPortState==1)
            openserial.color="green"
        else if(serialPortState==-1)
            openserial.color="red"
    }
    onKeyStateChanged: {
        if(keyState==-1)
        {
            init.color='red'
            central.color='white'
            close.color='white'
            move.color='white'
        }
        else if(keyState==1)
        {
            init.color='white'
            central.color='red'
            close.color='white'
            move.color='white'
        }
        else if(keyState==0)
        {
            init.color='white'
            central.color='white'
            close.color='red'
            move.color='white'
        }
        else if(keyState==2)
        {
            init.color='white'
            central.color='white'
            close.color='white'
            move.color='red'
        }


    }
    onRowCoordinateChanged: {
        rowCoordinate_Text.text = rowCoordinate
    }
    onColCoordinateChanged: {
        colCoordinate_Text.text = colCoordinate
    }
    onIntensityChanged: {
        intensity_Text.text = intensity
    }

    Rectangle{
        id: intensity_Rec
        width:120
        height: 30
        x:10
        y:200
        color:"white"
        Text{
            id:intensity_Text
            text:rowCoordinate
            color:"black"
            anchors.centerIn: parent
        }
    }
    Text{
        id:intensity_idx
        width:150
        height:30
        x:10
        y:150
        text:"Intensity"
        font.pixelSize: 20
        color:"white"
    }
    Rectangle{
        id: rowCoordinate_Rec
        width:120
        height: 30
        x:10
        y:300
        color:"white"
        Text{
            id:rowCoordinate_Text
            text:rowCoordinate
            color:"black"
            anchors.centerIn: parent
        }
    }
    Text{
        id:rowCoordinate_idx
        width:150
        height:30
        x:10
        y:250
        text:"Row"
        font.pixelSize: 20
        color:"white"
    }
    Rectangle{
        id: colCoordinate_Rec
        width:120
        height: 30
        x:10
        y:400
        color:"white"
        Text{
            id:colCoordinate_Text
            text:rowCoordinate
            color:"black"
            anchors.centerIn: parent
        }
    }
    Text{
        id:colCoordinate_idx
        width:150
        height:30
        x:10
        y:350
        text:"Column"
        font.pixelSize: 20
        color:"white"
    }



    Rectangle{
        id:openserial
        width: 200
        height: 50
        x:20
        y:20
        color:"white"
        MouseArea{

            anchors.fill:parent
            onClicked: backend.openSerialPort()
        }
        Text{
            id:text
            text:"Open Serial Port"
            anchors.centerIn: parent
        }
    }

    Rectangle{
        id:init
        width: 40
        height: 40
        x:400
        y:20
        color:"white"
        Text{
            id:textu
            text:"IN"
            color: "black"
            font.family: "Ubuntu"
            font.pixelSize:20
            anchors.centerIn: parent
        }
    }
    Rectangle{
        id:central
        width: 40
        height: 40
        x:450
        y:20
        color:"white"
        Text{
            id:textd
            text:"CN"
            color: "black"
            font.family: "Ubuntu"
            font.pixelSize:20
            anchors.centerIn: parent
        }
    }
    Rectangle{
        id:move
        width: 40
        height: 40
        x:500
        y:20
        color:"white"
        Text{
            id:textl
            text:"MV"
            color: "black"
            font.family: "Ubuntu"
            font.pixelSize:20
            anchors.centerIn: parent
        }
    }
    Rectangle{
        id:close
        width: 40
        height: 40
        x:550
        y:20
        color:"white"
        Text{
            id:textr
            text:"CL"
            color: "black"
            font.family: "Ubuntu"
            font.pixelSize:20
            anchors.centerIn: parent
        }
    }


}
