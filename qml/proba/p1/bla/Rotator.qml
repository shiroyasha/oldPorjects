import Qt 4.7

MouseArea
{
    id : rotator

    width : 20
    height : 20

    property int angleToAdd : 0


    Rectangle
    {
        anchors.fill : parent

        color : "blue"
    }

    onPositionChanged:
    {
        var a = widget.height / 2 - y - mouseY;
        var b = widget.width / 2 - x - mouseX;

        var tg = Math.floor( Math.atan2( a,b ) * (180.0 / Math.PI) ) - rotator.angleToAdd

        console.log( Math.atan2( a,b ) , Math.atan2( a,b ) * (180.0 / Math.PI) , tg, rotator.angleToAdd )

        widget.rotation = widget.rotation + tg
    }
}
