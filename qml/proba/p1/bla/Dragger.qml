import Qt 4.7

MouseArea
{
    id : dragger

    width : 20
    height : 20

    Rectangle
    {
        anchors.fill : parent

        color : "red"
        radius: 10
    }

    drag.target: widget
    drag.axis: Drag.XandYAxis

    drag.minimumY: Number.MIN_VALUE
    drag.maximumY: Number.MAX_VALUE
    drag.minimumX: Number.MIN_VALUE
    drag.maximumX: Number.MAX_VALUE

}
