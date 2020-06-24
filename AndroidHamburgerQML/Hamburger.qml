import QtQuick 2.0

Item {
  id: root
  property int size : 1
  property real round : 0
  width: 24 * size
  height: 24 * size

  Rectangle {
    id: bar1
    x: 2*size
    y: 5*size
    width: 20*size
    radius : round
    height: 2*size
    antialiasing: true
  }

  Rectangle {
    id: bar2
    x: 2 * size
    y: 10 * size
    width: 20 * size
    radius : round
    height: 2 * size
    antialiasing: true
  }

  Rectangle {
    id: bar3
    x: 2 * size
    y: 15 * size
    width: 20 * size
    height: 2 * size
    radius : round
    antialiasing: true
  }

  property int animationDuration: 350

  state: "menu"
  states: [
    State {
      name: "menu"
    },

    State {
      name: "back"
      PropertyChanges { target: root; rotation: 180 }
      PropertyChanges { target: bar1; rotation: 45; width: 13* size; x: 9.5* size; y: 8* size }
      PropertyChanges { target: bar2; width: 17* size; x: 3* size; y: 12* size }
      PropertyChanges { target: bar3; rotation: -45; width: 13* size; x: 9.5* size; y: 16* size }
    }
  ]

  transitions: [
    Transition {
      RotationAnimation { target: root; direction: RotationAnimation.Clockwise; duration: animationDuration; easing.type: Easing.InOutQuad }
      PropertyAnimation { target: bar1; properties: "rotation, width, x, y"; duration: animationDuration; easing.type: Easing.InOutQuad }
      PropertyAnimation { target: bar2; properties: "rotation, width, x, y"; duration: animationDuration; easing.type: Easing.InOutQuad }
      PropertyAnimation { target: bar3; properties: "rotation, width, x, y"; duration: animationDuration; easing.type: Easing.InOutQuad }
    }
  ]
}
