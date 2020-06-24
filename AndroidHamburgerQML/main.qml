import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

Rectangle {
  id : mainRoot
  width: 480
  height: 480
  color: "#9c27b0"

  MouseArea {
    anchors.fill: parent
    onClicked: hamburger.state = hamburger.state === "menu" ? "back" : "menu"
  }

  Hamburger {
    id: hamburger
    anchors.centerIn: parent
    size : sss.value
    round : ssr.value/10
  }

  Rectangle{
      width: mainRoot.width
      height : 70
      color: "#000000"


  GridLayout{
      id: grid
      columns: 2
      columnSpacing: 30
      anchors.horizontalCenter: parent


 Text{
     text: "Size : " + sss.value + "dp."
     color : "#ffffff"
 }
  Slider {
      id : sss
      minimumValue: 1
      value: 2
      stepSize: 1
      maximumValue: 30
  }

  Text{
      text: "Radius : " + ssr.value/10 + "dp."
      color : "#ffffff"
  }
   Slider {
       id : ssr
       minimumValue: 0
       value: 0
       stepSize: 10
       maximumValue: 300
   }

  }
}
}
