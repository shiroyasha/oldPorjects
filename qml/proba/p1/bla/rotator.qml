import Qt 4.7

MouseArea
{
    id : rotator

    width : 20
    height : 20

    anchors.verticalCenter : parent.verticalCenter

    Rectangle
    {
        anchors.fill : parent

        color : "red"
    }

    onPositionChanged:
    {
        //console.log(mouseX,mouseY)

        var a = widget.height / 2 - y - mouseY;
        var b = widget.width / 2 - x - mouseX;

        var tg = Math.floor( Math.atan( Math.tan( a/ b) ) * 180 / Math.PI )

        console.log(tg)

        widget.rotation = widget.rotation + tg
    }
}
