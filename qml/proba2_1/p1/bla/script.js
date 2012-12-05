var widgetList = new Array();
var bindingList = new Array();

function createWidgets()
{
    Creator.createObjects("bla/dva.qml");
    Creator.createObjects("bla/jedan.qml");
}

function setRecSize(widget)
{
    console.log(widgetList.length)

    if( !widget ) return;

    console.log( wid.width, wid.height, wid.x, wid.y)

    Qt.createComponent("")

    mouse2.width = wid.width
    mouse2.height = wid.height
    mouse2.x = wid.x
    mouse2.y = wid.y

    mouse2.drag.target = wid;
    mouse2.drag.axis = Drag.XandYAxis;

    mouse2.drag.minimumY= 0
    mouse2.drag.maximumY= desktop.height
    mouse2.drag.minimumX= 0
    mouse2.drag.maximumX= desktop.width
}

function setRec( xx, yy)
{
    rec.x = xx
    rec.y = yy
}
