import QtQuick 2.0

Item {
    id:root
    signal clicked()
    Rectangle{
        id:click
        width: 100
        height: 100
        anchors.centerIn: parent
        color:"white"
        MouseArea{

            anchors.fill:parent
            onClicked: root.clicked()
        }
    }

}
