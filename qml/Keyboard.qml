import QtQuick 2.0

Item {
    id:root
    property int currentIndex
    property int choose
    signal keyChoosed(string keyText)
    signal del()
    Column{
        anchors.centerIn: parent
        spacing: 8
        Row{
            id:row1
            spacing: 8
            Key{
                id:n1
                keyname: "1"
                currentIndex: root.currentIndex
                choose: root.choose
                index:1
                onKeyChoosed: root.keyChoosed(keyText)
            }
            Key{
                id:n2
                keyname:"2"
                currentIndex: root.currentIndex
                choose: root.choose
                index:2
                onKeyChoosed: root.keyChoosed(keyText)
            }
            Key{
                id:n3
                keyname:"3"
                currentIndex: root.currentIndex
                choose: root.choose
                index:3
                onKeyChoosed: root.keyChoosed(keyText)
            }
            Key{
                id:n4
                keyname:"4"
                currentIndex: root.currentIndex
                choose: root.choose
                index:4
                onKeyChoosed: root.keyChoosed(keyText)
            }
            Key{
                id:n5
                keyname:"5"
                currentIndex: root.currentIndex
                choose: root.choose
                index:5
                onKeyChoosed: root.keyChoosed(keyText)
            }
            Key{
                id:n6
                keyname:"6"
                currentIndex: root.currentIndex
                choose: root.choose
                index:6
                onKeyChoosed: root.keyChoosed(keyText)
            }
            Key{
                id:n7
                keyname:"7"
                currentIndex: root.currentIndex
                choose: root.choose
                index:7
                onKeyChoosed: root.keyChoosed(keyText)
            }
            Key{
                id:n8
                keyname:"8"
                currentIndex: root.currentIndex
                choose: root.choose
                index:8
                onKeyChoosed: root.keyChoosed(keyText)
            }
            Key{
                id:n9
                keyname:"9"
                currentIndex: root.currentIndex
                choose: root.choose
                index:9
                onKeyChoosed: root.keyChoosed(keyText)
            }
            Key{
                id:n0
                keyname:"0"
                currentIndex: root.currentIndex
                choose: root.choose
                index:10
                onKeyChoosed: root.keyChoosed(keyText)
            }

        }
        Row{
            id:rowq
            spacing: 8
            Key{
                id:q
                keyname: "Q"
                currentIndex: root.currentIndex
                choose: root.choose
                index:11
                onKeyChoosed: root.keyChoosed(keyText)
            }
            Key{
                id:w
                keyname:"W"
                currentIndex: root.currentIndex
                choose: root.choose
                index:12
                onKeyChoosed: root.keyChoosed(keyText)
            }
            Key{
                id:e
                keyname:"E"
                currentIndex: root.currentIndex
                choose: root.choose
                index:13
                onKeyChoosed: root.keyChoosed(keyText)
            }
            Key{
                id:r
                keyname:"R"
                currentIndex: root.currentIndex
                choose: root.choose
                index:14
                onKeyChoosed: root.keyChoosed(keyText)
            }
            Key{
                id:t
                keyname:"T"
                currentIndex: root.currentIndex
                choose: root.choose
                index:15
                onKeyChoosed: root.keyChoosed(keyText)
            }
            Key{
                id:y
                keyname:"Y"
                currentIndex: root.currentIndex
                choose: root.choose
                index:16
                onKeyChoosed: root.keyChoosed(keyText)
            }
            Key{
                id:u
                keyname:"U"
                currentIndex: root.currentIndex
                choose: root.choose
                index:17
                onKeyChoosed: root.keyChoosed(keyText)
            }
            Key{
                id:i
                keyname:"I"
                currentIndex: root.currentIndex
                choose: root.choose
                index:18
                onKeyChoosed: root.keyChoosed(keyText)
            }
            Key{
                id:o
                keyname:"O"
                currentIndex: root.currentIndex
                choose: root.choose
                index:19
                onKeyChoosed: root.keyChoosed(keyText)
            }
            Key{
                id:p
                keyname:"P"
                currentIndex: root.currentIndex
                choose: root.choose
                index:20
                onKeyChoosed: root.keyChoosed(keyText)
            }

        }
        Row{
        id:rowA
        spacing: 8
        Key{
            id:a
            keyname: "A"
            currentIndex: root.currentIndex
            choose: root.choose
            index:21
            onKeyChoosed: root.keyChoosed(keyText)
        }
        Key{
            id:s
            keyname:"S"
            currentIndex: root.currentIndex
            choose: root.choose
            index:22
            onKeyChoosed: root.keyChoosed(keyText)
        }
        Key{
            id:d
            keyname:"D"
            currentIndex: root.currentIndex
            choose: root.choose
            index:23
            onKeyChoosed: root.keyChoosed(keyText)
        }
        Key{
            id:f
            keyname:"F"
            currentIndex: root.currentIndex
            choose: root.choose
            index:24
            onKeyChoosed: root.keyChoosed(keyText)
        }
        Key{
            id:g
            keyname:"G"
            currentIndex: root.currentIndex
            choose: root.choose
            index:25
            onKeyChoosed: root.keyChoosed(keyText)
        }
        Key{
            id:h
            keyname:"H"
            currentIndex: root.currentIndex
            choose: root.choose
            index:26
            onKeyChoosed: root.keyChoosed(keyText)
        }
        Key{
            id:j
            keyname:"J"
            currentIndex: root.currentIndex
            choose: root.choose
            index:27
            onKeyChoosed: root.keyChoosed(keyText)
        }
        Key{
            id:k
            keyname:"K"
            currentIndex: root.currentIndex
            choose: root.choose
            index:28
            onKeyChoosed: root.keyChoosed(keyText)
        }
        Key{
            id:l
            keyname:"L"
            currentIndex: root.currentIndex
            choose: root.choose
            index:29
            onKeyChoosed: root.keyChoosed(keyText)
        }
        Key{
            id:yinhao
            keyname:"'"
            currentIndex: root.currentIndex
            choose: root.choose
            index:30
            onKeyChoosed: root.keyChoosed(keyText)
        }

    }
        Row{
        id:rowz
        spacing: 8
        Key{
            id:z
            keyname: "Z"
            currentIndex: root.currentIndex
            choose: root.choose
            index:31
            onKeyChoosed: root.keyChoosed(keyText)
        }
        Key{
            id:x
            keyname:"X"
            currentIndex: root.currentIndex
            choose: root.choose
            index:32
            onKeyChoosed: root.keyChoosed(keyText)
        }
        Key{
            id:c
            keyname:"C"
            currentIndex: root.currentIndex
            choose: root.choose
            index:33
            onKeyChoosed: root.keyChoosed(keyText)
        }
        Key{
            id:v
            keyname:"V"
            currentIndex: root.currentIndex
            choose: root.choose
            index:34
            onKeyChoosed: root.keyChoosed(keyText)
        }
        Key{
            id:b
            keyname:"B"
            currentIndex: root.currentIndex
            choose: root.choose
            index:35
            onKeyChoosed: root.keyChoosed(keyText)
        }
        Key{
            id:n
            keyname:"N"
            currentIndex: root.currentIndex
            choose: root.choose
            index:36
            onKeyChoosed: root.keyChoosed(keyText)
        }
        Key{
            id:m
            keyname:"M"
            currentIndex: root.currentIndex
            choose: root.choose
            index:37
            onKeyChoosed: root.keyChoosed(keyText)
        }
        Key{
            id:comma
            keyname:","
            currentIndex: root.currentIndex
            choose: root.choose
            index:38
            onKeyChoosed: root.keyChoosed(keyText)
        }
        Key{
            id:end
            keyname:"."
            currentIndex: root.currentIndex
            choose: root.choose
            index:39
            onKeyChoosed: root.keyChoosed(keyText)
        }
        Key{
            id:question
            keyname:"?"
            currentIndex: root.currentIndex
            choose: root.choose
            index:40
            onKeyChoosed: root.keyChoosed(keyText)
        }

    }
        Row{
            id:spaceanddelete
            spacing:8
            KeyExpend{
                id:space
                width:696
                index_begin: 41
                index_end: 48
                keyname:"Space"
                currentIndex:root.currentIndex
                choose:root.choose
                onKeyChoosed: root.keyChoosed(keyText)


            }
            KeyExpend{
                id:del
                width:168
                index_begin:49
                index_end: 50
                keyname:"Del"
                currentIndex:root.currentIndex
                choose:root.choose
                onKeyChoosed: root.del()
            }


        }

}
}
