/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Mar 11 03:27:50 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action1;
    QAction *actionPrev;
    QAction *actionNext;
    QAction *actionRotate_Left;
    QAction *actionRotate_Right;
    QAction *actionFitInView;
    QAction *actionFullScreen;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QWidget *widget;
    QSlider *horizontalSlider;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(674, 412);
        action1 = new QAction(MainWindow);
        action1->setObjectName(QString::fromUtf8("action1"));
        actionPrev = new QAction(MainWindow);
        actionPrev->setObjectName(QString::fromUtf8("actionPrev"));
        actionNext = new QAction(MainWindow);
        actionNext->setObjectName(QString::fromUtf8("actionNext"));
        actionRotate_Left = new QAction(MainWindow);
        actionRotate_Left->setObjectName(QString::fromUtf8("actionRotate_Left"));
        actionRotate_Right = new QAction(MainWindow);
        actionRotate_Right->setObjectName(QString::fromUtf8("actionRotate_Right"));
        actionFitInView = new QAction(MainWindow);
        actionFitInView->setObjectName(QString::fromUtf8("actionFitInView"));
        actionFitInView->setCheckable(true);
        actionFullScreen = new QAction(MainWindow);
        actionFullScreen->setObjectName(QString::fromUtf8("actionFullScreen"));
        actionFullScreen->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(500);
        spinBox->setSingleStep(10);
        spinBox->setValue(100);

        horizontalLayout->addWidget(spinBox);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(widget);

        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy1);
        horizontalSlider->setMaximumSize(QSize(100, 16777215));
        horizontalSlider->setFocusPolicy(Qt::NoFocus);
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(500);
        horizontalSlider->setSingleStep(10);
        horizontalSlider->setValue(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);
        horizontalSlider->setTickPosition(QSlider::NoTicks);
        horizontalSlider->setTickInterval(50);

        horizontalLayout->addWidget(horizontalSlider);

        MainWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        toolBar->setAllowedAreas(Qt::BottomToolBarArea);
        toolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        toolBar->addAction(action1);
        toolBar->addAction(actionPrev);
        toolBar->addAction(actionNext);
        toolBar->addAction(actionRotate_Left);
        toolBar->addAction(actionRotate_Right);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Squirell Viewer", 0, QApplication::UnicodeUTF8));
        action1->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action1->setToolTip(QApplication::translate("MainWindow", "Open Image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action1->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionPrev->setText(QApplication::translate("MainWindow", "Prev", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPrev->setToolTip(QApplication::translate("MainWindow", "Privious Image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionPrev->setShortcut(QApplication::translate("MainWindow", "Backspace", 0, QApplication::UnicodeUTF8));
        actionNext->setText(QApplication::translate("MainWindow", "Next", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNext->setToolTip(QApplication::translate("MainWindow", "Next Image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNext->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        actionRotate_Left->setText(QApplication::translate("MainWindow", "Rotate Left", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRotate_Left->setToolTip(QApplication::translate("MainWindow", "Rotate Left", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRotate_Left->setShortcut(QApplication::translate("MainWindow", "Left", 0, QApplication::UnicodeUTF8));
        actionRotate_Right->setText(QApplication::translate("MainWindow", "Rotate Right", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRotate_Right->setToolTip(QApplication::translate("MainWindow", "Rotate Right", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRotate_Right->setShortcut(QApplication::translate("MainWindow", "Right", 0, QApplication::UnicodeUTF8));
        actionFitInView->setText(QApplication::translate("MainWindow", "FitInView", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionFitInView->setToolTip(QApplication::translate("MainWindow", "Fit the image in the view", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionFitInView->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        actionFullScreen->setText(QApplication::translate("MainWindow", "FullScreen", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionFullScreen->setToolTip(QApplication::translate("MainWindow", "Toggle Fullscreen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionFullScreen->setShortcut(QApplication::translate("MainWindow", "F11", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "0/0", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
