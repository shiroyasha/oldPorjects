/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

import Qt 4.7
import Qt.labs.particles 1.0

Flipable {
    id: flipable
    property int angle: 0
    
    property bool hasMine : false;
    property bool hasFlag : false;
    property int hint : 0;
    property int surFlags : 0;
    property int col : -1;
    property int row : -1;
    property bool flipped : false;

    transform: Rotation { origin.x: width / 2; origin.y: height / 2 ; axis.x: 1; axis.z: 0; angle: flipable.angle }

    front: Image {
        source: "pics/front.png"; 
	width: flipable.width ; height: flipable.height
	
	Text {
            anchors.centerIn: parent
            text: parent.bla
	    
	    font.pixelSize : parent.height * 0.3
	    
	    font.bold: true
        }
        
        Image {
            anchors.centerIn: parent
            width : parent.width * 0.7
            height : parent.height * 0.7
            source: "pics/flag.png"; opacity: hasFlag
            
            smooth : true

            Behavior on opacity { NumberAnimation {duration: 0} }
        }
    }

    back: Image {
        source: "pics/back.png"
        width: flipable.width ; height: flipable.height
        Text {
            anchors.centerIn: parent
            text: hint;
	    
	    font.pixelSize : parent.height * 0.7
	    
	    color: text == 1 ? "blue" : text == 2 ? "green" : text == 3 ? "red" : text == 4 ? "yellow" : text == 5 ? "white" : text == 6 ? "magenta" : text == 7 ? "cyan" : "black";
	    
	    font.bold: true
            opacity: !hasMine && hint > 0
        }

        Image {
            anchors.centerIn: parent
            width : parent.width * 0.8
            height : parent.height * 0.8
            
            //smooth : true
            source: "pics/bomb.png"; opacity: hasMine;
        }

	Particles {
	    id: particles

	    width: 1; height: 1
	    anchors.centerIn: parent

	    emissionRate: 0
	    lifeSpan: 700; 
	    lifeSpanDeviation: 600
	    angle: 0; 
	    angleDeviation: 360;
	    velocity: 100; 
	    velocityDeviation: 30
	    source: "pics/star.png"
	    
	    states: State 
	    {   name: "exploding"; when: flipped && flipable.hasMine
		StateChangeScript {script: particles.burst(200); }
	    }
	}
    }

    states: State {
        name: "back"; when: flipped
        PropertyChanges { target: flipable; angle: 180 }
    }

    property real pauseDur: 0
    
    transitions: Transition {
        SequentialAnimation {
            ScriptAction {
                script: {
                    var ret = 10
                    if (hasMine && flipped)
                        pauseDur = ret * 3
                    else
                        pauseDur = ret
                }
            }
            PauseAnimation {
                duration: pauseDur
            }
            RotationAnimation { easing.type: Easing.InOutQuad }
        }
    }
}
