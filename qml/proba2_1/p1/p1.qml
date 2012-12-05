import Qt 4.7

import "bla/script.js" as Logic
import "bla/objectCreation.js" as Creator

Rectangle
{
    id : scene
    width: 1024
    height : 800

    focus : true

    Rectangle
    {
        id : desktop

        anchors.fill : parent;
    }


    MouseArea
    {
        id : mouse
        anchors.fill : parent

        //hoverEnabled : true

        enabled : false

        onPressed:
        {
            Creator.addBinding( "target" , mouse2.drag );

            rec.visible = true;
            mouse2.visible = true;
        }

        onPositionChanged:
        {
            Logic.setRec( mouseX, mouseY)
        }

        z: Number.MAX_VALUE - 1
    }

    MouseArea
    {
        id : mouse2

        z: Number.MAX_VALUE

        visible : false

        Rectangle
        {
            id : rec
            color : "#320000ff"

            anchors.fill : mouse2
        }
    }

    Keys.onPressed:
    {
        console.log("bla");
        if (event.key == Qt.Key_Meta )
        {
            console.log("pritisni")

            mouse.enabled = true;

            event.accepted = true;
        }
    }

    Keys.onReleased:
    {
        width = width + 10
        if (event.key == Qt.Key_Meta )
        {
            console.log("otpusti")
            mouse.enabled = false;
            rec.visible = false;
            mouse2.visible = false;

            event.accepted = true;
        }
    }

    Component.onCompleted:
    {
        console.log("stage -1")
        Logic.createWidgets();
    }

}
