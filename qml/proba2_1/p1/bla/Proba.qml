import Qt 4.7

Item
{
    id: smeh
    property bool __isModifierclicked : false
    property bool __mouseOver : mouse1.enabled

    focus : true

    MouseArea
    {

        anchors.fill : parent
        hoverEnabled : true

        enabled : __isModifierclicked

        id: mouse1
        drag.target: smeh
        drag.axis: Drag.XandYAxis
        drag.minimumY: 0
        drag.maximumY: parent.parent.height
        drag.minimumX: 0
        drag.maximumX: parent.parent.width

        z: Number.MAX_VALUE

        onClicked:
        {
            smeh.parent.focus = true
            smeh.destroy()
        }
    }

    states: [
        State {
            name: "bla"
            when: mouse1.containsMouse && __isModifierclicked
            PropertyChanges {
                target: rec
                visible : true
            }
        },
        State {
            name: "bla"
            when: mouse1.enabled && __isModifierclicked
            PropertyChanges {
                target: moouse1
                containsMouse : false
            }
        }
    ]

    Rectangle
    {
        id : rec
        color : "#320000ff"
        anchors.fill : parent
        visible : false

        z: Number.MAX_VALUE
    }

    transitions: Transition {
        NumberAnimation { properties: rotation; duration: 2000 }
    }
}
