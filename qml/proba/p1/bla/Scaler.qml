import Qt 4.7

MouseArea
{
    id : scaler

    width : 20
    height : 20

    property int horizontalScale: 1
    property int verticalScale: 1

    property int minSize: 30

    Rectangle
    {
        anchors.fill : parent

        color : "yellow"
    }

    onPositionChanged:
    {
        if( horizontalScale == 1 && verticalScale == 1 )
        {
            if(  widget.width + mouseX > minSize  ) widget.width += mouseX;
            if(  widget.height + mouseY > minSize  ) widget.height += mouseY;
            return;
        }
        if( horizontalScale == -1 && verticalScale == 1 )
        {
            if(  widget.width - mouseX > minSize  )
            {
                widget.x += mouseX;
                widget.width -= mouseX;
            }

            if(  widget.height + mouseY > minSize  ) widget.height += mouseY;
            return;
        }
        if( horizontalScale == 1 && verticalScale == -1 )
        {
            if(  widget.height - mouseY > minSize  )
            {
                widget.y += mouseY;
                widget.height -= mouseY;
            }

            if(  widget.width + mouseX > minSize  ) widget.width += mouseX;
            return;
        }

        if( horizontalScale == -1 && verticalScale == -1 )
        {
            if(  widget.width - mouseX > minSize  )
            {
                widget.y += mouseY;
                widget.width -= mouseX;
            }
            if(  widget.height - mouseY > minSize  )
            {
                widget.x += mouseX;
                widget.height -= mouseY;
            }
            return;
        }

    }
}
