import Qt 4.7

import "bla/script.js" as Logic
import "bla/rad.js" as Zajednicko

Rectangle
{
    id : scene
    width: 800
    height : 800

    focus : true

    Rectangle
    {
        id : desktop
        anchors.fill : parent

        Image {
            id: backImage
            source: "/media/files/Pictures/Wallpapers/butterflies_ hurricanes.jpg"

            anchors.fill : parent
        }
        MouseArea {
            id : back
            anchors.fill : parent

            acceptedButtons: Qt.LeftButton | Qt.RightButton

            onPressed:
            {
                if( back.pressedButtons == Qt.RightButton )
                {
                    Logic.createWidgets()
                }
            }
        }
    }

    Keys.onPressed:
    {
        if (event.key == Qt.Key_Meta )
        {
            Logic.setModifiers(true)

            event.accepted = true;
        }
    }

    Keys.onReleased:
    {
        if (event.key == Qt.Key_Meta )
        {
            Logic.setModifiers(false)

            event.accepted = true;
        }
    }

    Component.onCompleted:
    {
        Logic.createWidgets();
    }
}
