import Qt 4.7

Proba
{
    width : 300
    height : 500

    Loader {
        anchors { top: parent.top; topMargin: 10; horizontalCenter: parent.horizontalCenter }

        anchors.fill : parent
        clip: true;
        source: "/media/files/Documentations/qt/demos/declarative/samegame/samegame.qml"
    }
}
