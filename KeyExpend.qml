import QtQuick 2.0

Item {
    id: root
    width: 80
    height: 80
    property alias keyname: keyname.text
    property int currentIndex: 0
    property int index_begin:0
    property int index_end:0
    property int choose:0
    signal keyChoosed(string keyText)


    Rectangle{
        id: key
        anchors.fill: parent
        radius: 8
        color: "grey"
    }
    Text{
        id:keyname
        anchors.centerIn: parent
        color: "white"
        font.family: "Ubuntu"
        font.pixelSize:30
        text: "A"

    }
    onCurrentIndexChanged: changeCurrentColor()
    function changeCurrentColor(){
        if(currentIndex>=index_begin && currentIndex<=index_end)
        {
           key.color="orange"
        }
        else
            key.color="grey"
    }
    onChooseChanged: {
        if(choose == 1 && currentIndex>=index_begin && currentIndex<=index_end)
        {
            keyChoosed(" ")

        }



    }




}
