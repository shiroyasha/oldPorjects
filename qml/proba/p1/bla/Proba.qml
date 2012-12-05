import Qt 4.7
import "rad.js" as Zajednicko
import "rotator.qml"

Item
{
    id: widget

    property bool ___doNotUseWithWidgetsItIsForInternalUsageOnly : false

    Rectangle
    {
        id : settings
        color : "#320000ff"
        anchors.fill : parent
        opacity : 0.0

        z: Number.MAX_VALUE

        transitions: Transition {
            PropertyAnimation { properties: "opacity"; duration: 300 }
        }

        states: [
            State {
                name: "settings_on"
                when : widget.___doNotUseWithWidgetsItIsForInternalUsageOnly == true
                PropertyChanges {
                    target: settings
                    opacity : 1.0
                }
            }
        ]


        MouseArea
        {
            Dragger { anchors.centerIn : parent }

            Rotator { anchors.verticalCenter : parent.verticalCenter }
            Rotator { angleToAdd : 90; anchors.horizontalCenter : parent.horizontalCenter }
            Rotator { angleToAdd : -90; anchors.horizontalCenter : parent.horizontalCenter; anchors.bottom : parent.bottom }
            Rotator { angleToAdd : 180; anchors.verticalCenter : parent.verticalCenter; anchors.right : parent.right }

            Scaler { horizontalScale : -1; verticalScale : -1; }
            Scaler { anchors.right : parent.right; verticalScale : -1 }
            Scaler { anchors.bottom : parent.bottom; anchors.right : parent.right }
            Scaler { anchors.bottom : parent.bottom; anchors.left : parent.left; horizontalScale : -1}

            anchors.fill : parent

            id: mouse

            onPressed:
            {
                Zajednicko.zOrder();
                widget.z = widget.z + 1;

                console.log( this )
            }

            onClicked:
            {
                //widget.parent.focus = true
                //widget.destroy()
            }
        }
    }
}
