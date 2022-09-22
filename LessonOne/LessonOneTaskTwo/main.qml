import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.1

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("TaskTwo")
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
                placeholderText: "A"
                horizontalAlignment: TextField.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                selectByMouse: true
            }
            TextField
            {
                id: angleB
                placeholderText: "B"
                horizontalAlignment: TextField.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                selectByMouse: true
            }
            TextField
            {
                id: angleC
                placeholderText: "C"
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
                    var halfPerimetr = (parseFloat(angleA.text) + parseFloat(angleB.text) + parseFloat(angleC.text)) / 2
                    var result = Math.sqrt(halfPerimetr * (halfPerimetr - parseFloat(angleA.text)) * (halfPerimetr - parseFloat(angleB.text)) * (halfPerimetr - parseFloat(angleC.text)))
                    area.text = result
                }
            }
        }

    }
}
