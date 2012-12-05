
import Qt 4.7
import "MinesCore" 1.0
import "MinesCore/Logic.js" as Logic

Item {
    id: field
    
    property int clickx: 0
    property int clicky: 0
    width: 800; height: 600

    Image { source: "MinesCore/pics/No-Ones-Laughing-3.jpg"; anchors.fill: parent; fillMode: Image.Tile }

      
    Grid 
    {   
	id : gameBoard
	anchors.horizontalCenter: parent.horizontalCenter
	anchors.verticalCenter : parent.verticalCenter

	property int bla : 15
	
	//spacing: 1
	columns: 30
	rows : 16
	
	//width : (Logic.numCols  + 1) / container.width > (Logic.numRows + 1) / container.height ?  container.width / (Logic.numCols  + 1) : container.height / (Logic.numRows + 1)
	//height : width

	width: 900
	height :  500
    }

    MouseArea 
    {
        anchors.fill: gameBoard
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        
        onPressed: 
        {
	    if (mouse.button == undefined || mouse.button == Qt.RightButton) 
	    {
		Logic.flag( mouse.x , mouse.y);
	    }
        }
        onReleased: 
        {            
	    if (mouse.button == Qt.LeftButton) 
	    {
		Logic.flip( mouse.x , mouse.y);
	    }
        }
    }

    Row {
        id: gamedata
        x: 20; spacing : 20;
        anchors.top: field.top; anchors.topMargin: 15

        Column {
	    id : bombs
            spacing: 2
            Image { source: "MinesCore/pics/bomb-color.png" }
            Text { anchors.horizontalCenter: parent.horizontalCenter; color: "white"; text: Logic.numMines }
        }

        Column {
	    id : flags
            spacing: 2
            Image { source: "MinesCore/pics/flag-color.png" }
            Text { anchors.horizontalCenter: parent.horizontalCenter; color: "white"; text: Logic.numFlags }
        }
    }

    Image {
        anchors.top: field.top; anchors.topMargin: 15
        anchors.horizontalCenter: field.horizontalCenter
        source: Logic.isPlaying ? 'MinesCore/pics/face-smile.png' :
        Logic.hasWon ? 'MinesCore/pics/face-smile-big.png': 'MinesCore/pics/face-sad.png'

        MouseArea 
	{ 
	    anchors.fill: parent; 
	    onPressed:
	    {
		  Logic.startNewGame(30,16,99)
	    } 
	}
    }

}
