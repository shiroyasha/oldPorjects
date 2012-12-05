var component = null
var bindObject = null

function createObjects(path)
{
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
        var widget = component.createObject(desktop);

        if (!widget)
        {
            console.log("something went wrong")
        }
        else
        {
            console.log("uspeh");
            widget.x = 100
            widget.y = 100

            Logic.widgetList.push( widget );
        }
    }
    else if (component.status == Component.Error)
    {
        // Error Handling
        console.log("Error loading component:", component.errorString());
    }
}

function addBinding (from, toObj/*, toProp*/)
{
    if( bindObject ) { bindObject.destroy(); bindObject = null; }

    bindObject = Qt.createQmlObject("import Qt 4.7; Binding {value: " + from + "; target: mouse2 ; property: " + Logic.widgetList[0] + "}", scene)

    if (bindObject)
    {
    }
    else
    {
        console.log("error creating binding object")
        console.log( bindObject.errorString() )
        return false
    }
    return true
}
