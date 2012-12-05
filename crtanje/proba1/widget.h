#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QVariant>

#define NUMBER_OF_FUNCTIONS 5

struct function
{
    int             id;
    QList<QVariant> args;
};

class widget : public QWidget
{
    Q_OBJECT
public:
    explicit widget(QWidget *parent = 0);

    void paintEvent(QPaintEvent *);

    static const int numOfArgs[NUMBER_OF_FUNCTIONS];

signals:

public slots:

    void crtaj(QList<function>);

    void ispishi(int);

private:

    QList<function> functionList;

};

#endif // WIDGET_H
