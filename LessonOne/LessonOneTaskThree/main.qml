import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.1

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Task Three")
    color: "#e5ecef"

    Rectangle
    {
        anchors.centerIn: parent
        radius: 5
        width: 300
        height: 300

        Column
        {
            anchors.fill: parent
            padding: 32
            spacing: 17

            TextField
            {
                id: angleA
                placeholderText: "A(example 0,1)"
                horizontalAlignment: TextField.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                selectByMouse: true
            }
            TextField
            {
                id: angleB
                placeholderText: "B(example 0,1)"
                horizontalAlignment: TextField.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                selectByMouse: true
            }
            TextField
            {
                id: angleC
                placeholderText: "C(example 0,1)"
                horizontalAlignment: TextField.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                selectByMouse: true
            }

            Label
            {
                id: area
                anchors.horizontalCenter: parent.horizontalCenter
                text: "S = "
            }

            Button
            {
                id: resultButton
                text: "Result"
                width: 200
                height: 40
                anchors.horizontalCenter: parent.horizontalCenter

                onClicked: calculateArea()

                function calculateArea()
                {
                    var A = angleA.text.split(',')
                    var B = angleB.text.split(',')
                    var C = angleC.text.split(',')

                    var coordAX = parseFloat(A[0])
                    var coordAY = parseFloat(A[1])
                    var coordBX = parseFloat(B[0])
                    var coordBY = parseFloat(B[1])
                    var coordCX = parseFloat(C[0])
                    var coordCY = parseFloat(C[1])

                    var lengthAB = Math.sqrt(Math.pow(coordBX - coordAX, 2) + Math.pow(coordBY - coordAY, 2))
                    var lengthBC = Math.sqrt(Math.pow(coordCX - coordBX, 2) + Math.pow(coordCY - coordBY, 2))
                    var lengthCA = Math.sqrt(Math.pow(coordAX - coordCX, 2) + Math.pow(coordAY - coordCY, 2))


                    var halfPerimetr = (lengthAB + lengthBC + lengthCA) / 2
                    var result = Math.sqrt(halfPerimetr * (halfPerimetr - lengthAB) * (halfPerimetr - lengthBC) * (halfPerimetr - lengthCA))
                    area.text = result
                }
            }
        }

    }
}
