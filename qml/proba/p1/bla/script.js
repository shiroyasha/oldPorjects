var component = null
var widget = null

function createWidgets()
{

    createObjects("bla/dva.qml");
    createObjects("bla/jedan.qml");
    createObjects("bla/tri.qml");
}

function createObjects(path)
{
    //console.log("stage 1");
    component = Qt.createComponent(path);

    if (component.status == Component.Ready)
        finishCreation();
    else
        component.statusChanged.connect(finishCreation);
}

function finishCreation()
{
    //console.log("stage 2");
    if (component.status == Component.Ready)
    {
        widget = component.createObject(desktop);

        if (widget == null)
        {
            console.log("something went wrong")
        }
        else
        {
            console.log("uspeh");
            widget.x = 100
            widget.y = 100

            Zajednicko.widgetList.push( widget );
        }
    }
    else if (component.status == Component.Error)
    {
        // Error Handling
        console.log("Error loading component:", component.errorString());
    }
}

function setModifiers( value )
{
    for( var i = 0; i < Zajednicko.widgetList.length ; ++i)
    {
        Zajednicko.widgetList[i].___doNotUseWithWidgetsItIsForInternalUsageOnly = value;
    }
}

function setRecSize(wid)
{
    Zajednicko.widgetList[1].x = 300;
    Zajednicko.widgetList[1].y = 300;
    console.log(wid)
    if( wid == null) return;

    console.log( wid.width, wid.height, wid.x, wid.y)
    //rec.width = wid.width
    //rec.height = wid.height
    //rec.x = wid.x
    //rec.y = wid.y

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

function sayBla()
{
    console.log("bla")
}
