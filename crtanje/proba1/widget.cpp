#include "widget.h"
#include <QPainter>
#include <string>
#include <iostream>
#include <QDebug>
#include <QVariant>

const int widget::numOfArgs[] = { 0, 4, 4, 4, 6 };

widget::widget(QWidget *parent) :
    QWidget(parent)
{
    setAttribute( Qt::WA_OpaquePaintEvent, true);
    setAttribute( Qt::WA_NoBackground, true);
}

void widget::paintEvent(QPaintEvent *)
{
    QPainter p;

    p.begin(this);

    p.setRenderHint( QPainter::Antialiasing, true);
    foreach( function func, functionList )
    {
        switch( func.id )
        {
        case 1:
            {
                p.drawLine( func.args.at(0).toInt() , func.args.at(1).toInt() ,  func.args.at(2).toInt(), func.args.at(3).toInt() );
                break;
            }
        case 2:
            {
                p.drawRect( func.args.at(0).toInt() , func.args.at(1).toInt() ,  func.args.at(2).toInt(), func.args.at(3).toInt() );
                break;
            }
        case 3:
            {
                p.drawEllipse( func.args.at(0).toInt() , func.args.at(1).toInt() ,  func.args.at(2).toInt(), func.args.at(3).toInt() );
                break;
            }
        case 4:
            {
                p.drawArc( func.args.at(0).toInt() , func.args.at(1).toInt() ,  func.args.at(2).toInt(), func.args.at(3).toInt() ,
                           func.args.at(4).toInt() , func.args.at(5).toInt());
                break;
            }
        default:
            {
                qDebug() << "no function with that name";
            }
        }
    }
    p.end();
}

void widget::crtaj( QList<function> r )
{
    functionList = r;

    update();
}

void widget::ispishi(int str)
{
    std::cout << str << std::endl;
}
