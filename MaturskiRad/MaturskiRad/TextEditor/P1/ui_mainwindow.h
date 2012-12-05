/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Apr 7 19:52:53 2010
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
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionSaveAs;
    QAction *actionNew;
    QAction *actionClose;
    QAction *actionQuit;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionSelectAll;
    QAction *actionDeselect;
    QAction *actionFind;
    QAction *actionFind_Next;
    QAction *actionFind_Previous;
    QAction *actionGo_To_Line;
    QAction *actionIndent;
    QAction *actionUnindent;
    QAction *actionUppercase;
    QAction *actionLowercase;
    QAction *actionCapitalize;
    QAction *actionSelect_Font;
    QAction *actionSelect_Font_Color;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *gotoLineWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QSpinBox *gotoLineSpin;
    QWidget *widget_5;
    QPushButton *gotoLineClose;
    QWidget *findWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *findEdit;
    QToolButton *findPrev;
    QToolButton *findNext;
    QLabel *label_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *replaceEdit;
    QToolButton *replacePrev;
    QToolButton *replaceNext;
    QPushButton *replaceAll;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *findClose;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuSettings;
    QMenu *menuHelp;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(668, 492);
        MainWindow->setDocumentMode(true);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionSelectAll = new QAction(MainWindow);
        actionSelectAll->setObjectName(QString::fromUtf8("actionSelectAll"));
        actionDeselect = new QAction(MainWindow);
        actionDeselect->setObjectName(QString::fromUtf8("actionDeselect"));
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        actionFind->setCheckable(true);
        actionFind_Next = new QAction(MainWindow);
        actionFind_Next->setObjectName(QString::fromUtf8("actionFind_Next"));
        actionFind_Previous = new QAction(MainWindow);
        actionFind_Previous->setObjectName(QString::fromUtf8("actionFind_Previous"));
        actionGo_To_Line = new QAction(MainWindow);
        actionGo_To_Line->setObjectName(QString::fromUtf8("actionGo_To_Line"));
        actionGo_To_Line->setCheckable(true);
        actionIndent = new QAction(MainWindow);
        actionIndent->setObjectName(QString::fromUtf8("actionIndent"));
        actionUnindent = new QAction(MainWindow);
        actionUnindent->setObjectName(QString::fromUtf8("actionUnindent"));
        actionUppercase = new QAction(MainWindow);
        actionUppercase->setObjectName(QString::fromUtf8("actionUppercase"));
        actionLowercase = new QAction(MainWindow);
        actionLowercase->setObjectName(QString::fromUtf8("actionLowercase"));
        actionCapitalize = new QAction(MainWindow);
        actionCapitalize->setObjectName(QString::fromUtf8("actionCapitalize"));
        actionSelect_Font = new QAction(MainWindow);
        actionSelect_Font->setObjectName(QString::fromUtf8("actionSelect_Font"));
        actionSelect_Font_Color = new QAction(MainWindow);
        actionSelect_Font_Color->setObjectName(QString::fromUtf8("actionSelect_Font_Color"));
        actionZoom_In = new QAction(MainWindow);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        actionZoom_Out = new QAction(MainWindow);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);

        verticalLayout->addWidget(tabWidget);

        gotoLineWidget = new QWidget(centralWidget);
        gotoLineWidget->setObjectName(QString::fromUtf8("gotoLineWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gotoLineWidget->sizePolicy().hasHeightForWidth());
        gotoLineWidget->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(gotoLineWidget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(gotoLineWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        gotoLineSpin = new QSpinBox(gotoLineWidget);
        gotoLineSpin->setObjectName(QString::fromUtf8("gotoLineSpin"));
        gotoLineSpin->setMinimum(1);
        gotoLineSpin->setMaximum(1);

        horizontalLayout_5->addWidget(gotoLineSpin);

        widget_5 = new QWidget(gotoLineWidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(widget_5);

        gotoLineClose = new QPushButton(gotoLineWidget);
        gotoLineClose->setObjectName(QString::fromUtf8("gotoLineClose"));

        horizontalLayout_5->addWidget(gotoLineClose);


        verticalLayout->addWidget(gotoLineWidget);

        findWidget = new QWidget(centralWidget);
        findWidget->setObjectName(QString::fromUtf8("findWidget"));
        gridLayout = new QGridLayout(findWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(1, 0, 0, 0);
        label = new QLabel(findWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        widget_2 = new QWidget(findWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        findEdit = new QLineEdit(widget_2);
        findEdit->setObjectName(QString::fromUtf8("findEdit"));
        findEdit->setFrame(true);

        horizontalLayout->addWidget(findEdit);

        findPrev = new QToolButton(widget_2);
        findPrev->setObjectName(QString::fromUtf8("findPrev"));
        findPrev->setArrowType(Qt::LeftArrow);

        horizontalLayout->addWidget(findPrev);

        findNext = new QToolButton(widget_2);
        findNext->setObjectName(QString::fromUtf8("findNext"));
        findNext->setArrowType(Qt::RightArrow);

        horizontalLayout->addWidget(findNext);


        gridLayout->addWidget(widget_2, 0, 1, 1, 1);

        label_2 = new QLabel(findWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        widget_3 = new QWidget(findWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        replaceEdit = new QLineEdit(widget_3);
        replaceEdit->setObjectName(QString::fromUtf8("replaceEdit"));
        replaceEdit->setFrame(true);

        horizontalLayout_2->addWidget(replaceEdit);

        replacePrev = new QToolButton(widget_3);
        replacePrev->setObjectName(QString::fromUtf8("replacePrev"));
        replacePrev->setArrowType(Qt::LeftArrow);

        horizontalLayout_2->addWidget(replacePrev);

        replaceNext = new QToolButton(widget_3);
        replaceNext->setObjectName(QString::fromUtf8("replaceNext"));
        replaceNext->setArrowType(Qt::RightArrow);

        horizontalLayout_2->addWidget(replaceNext);


        gridLayout->addWidget(widget_3, 2, 1, 1, 1);

        replaceAll = new QPushButton(findWidget);
        replaceAll->setObjectName(QString::fromUtf8("replaceAll"));

        gridLayout->addWidget(replaceAll, 2, 2, 1, 1);

        widget = new QWidget(findWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        findClose = new QPushButton(widget);
        findClose->setObjectName(QString::fromUtf8("findClose"));

        horizontalLayout_3->addWidget(findClose);


        gridLayout->addWidget(widget, 0, 2, 1, 1);


        verticalLayout->addWidget(findWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 668, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSelectAll);
        menuEdit->addAction(actionDeselect);
        menuEdit->addSeparator();
        menuEdit->addAction(actionFind);
        menuEdit->addAction(actionFind_Next);
        menuEdit->addAction(actionFind_Previous);
        menuEdit->addSeparator();
        menuEdit->addAction(actionGo_To_Line);
        menuTools->addAction(actionIndent);
        menuTools->addAction(actionUnindent);
        menuTools->addSeparator();
        menuTools->addAction(actionUppercase);
        menuTools->addAction(actionLowercase);
        menuTools->addAction(actionCapitalize);
        menuSettings->addAction(actionSelect_Font);
        menuSettings->addAction(actionSelect_Font_Color);
        menuSettings->addSeparator();
        menuSettings->addAction(actionZoom_In);
        menuSettings->addAction(actionZoom_Out);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionSaveAs);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionUndo);
        mainToolBar->addAction(actionRedo);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCut);
        mainToolBar->addAction(actionCopy);
        mainToolBar->addAction(actionPaste);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionFind);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Squirrel Editor", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", 0, QApplication::UnicodeUTF8));
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", 0, QApplication::UnicodeUTF8));
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Z", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setText(QApplication::translate("MainWindow", "SaveAs", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSaveAs->setToolTip(QApplication::translate("MainWindow", "SaveAs", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionQuit->setToolTip(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", 0, QApplication::UnicodeUTF8));
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", 0, QApplication::UnicodeUTF8));
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", 0, QApplication::UnicodeUTF8));
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actionSelectAll->setText(QApplication::translate("MainWindow", "SelectAll", 0, QApplication::UnicodeUTF8));
        actionSelectAll->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        actionDeselect->setText(QApplication::translate("MainWindow", "Deselect", 0, QApplication::UnicodeUTF8));
        actionFind->setText(QApplication::translate("MainWindow", "Find/Replace", 0, QApplication::UnicodeUTF8));
        actionFind->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", 0, QApplication::UnicodeUTF8));
        actionFind_Next->setText(QApplication::translate("MainWindow", "Find Next", 0, QApplication::UnicodeUTF8));
        actionFind_Next->setShortcut(QApplication::translate("MainWindow", "F3", 0, QApplication::UnicodeUTF8));
        actionFind_Previous->setText(QApplication::translate("MainWindow", "Find Previous", 0, QApplication::UnicodeUTF8));
        actionFind_Previous->setShortcut(QApplication::translate("MainWindow", "Shift+F3", 0, QApplication::UnicodeUTF8));
        actionGo_To_Line->setText(QApplication::translate("MainWindow", "Go To Line", 0, QApplication::UnicodeUTF8));
        actionGo_To_Line->setShortcut(QApplication::translate("MainWindow", "Ctrl+G", 0, QApplication::UnicodeUTF8));
        actionIndent->setText(QApplication::translate("MainWindow", "Indent", 0, QApplication::UnicodeUTF8));
        actionIndent->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", 0, QApplication::UnicodeUTF8));
        actionUnindent->setText(QApplication::translate("MainWindow", "Unindent", 0, QApplication::UnicodeUTF8));
        actionUnindent->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+I", 0, QApplication::UnicodeUTF8));
        actionUppercase->setText(QApplication::translate("MainWindow", "Uppercase", 0, QApplication::UnicodeUTF8));
        actionUppercase->setShortcut(QApplication::translate("MainWindow", "Ctrl+U", 0, QApplication::UnicodeUTF8));
        actionLowercase->setText(QApplication::translate("MainWindow", "Lowercase", 0, QApplication::UnicodeUTF8));
        actionLowercase->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+U", 0, QApplication::UnicodeUTF8));
        actionCapitalize->setText(QApplication::translate("MainWindow", "Capitalize", 0, QApplication::UnicodeUTF8));
        actionCapitalize->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+U", 0, QApplication::UnicodeUTF8));
        actionSelect_Font->setText(QApplication::translate("MainWindow", "Select Font", 0, QApplication::UnicodeUTF8));
        actionSelect_Font_Color->setText(QApplication::translate("MainWindow", "Select Font Color", 0, QApplication::UnicodeUTF8));
        actionZoom_In->setText(QApplication::translate("MainWindow", "Zoom In", 0, QApplication::UnicodeUTF8));
        actionZoom_In->setShortcut(QApplication::translate("MainWindow", "Ctrl++", 0, QApplication::UnicodeUTF8));
        actionZoom_Out->setText(QApplication::translate("MainWindow", "Zoom Out", 0, QApplication::UnicodeUTF8));
        actionZoom_Out->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Go to Line", 0, QApplication::UnicodeUTF8));
        gotoLineClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Find", 0, QApplication::UnicodeUTF8));
        findPrev->setText(QApplication::translate("MainWindow", "<", 0, QApplication::UnicodeUTF8));
        findNext->setText(QApplication::translate("MainWindow", "<", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Replace", 0, QApplication::UnicodeUTF8));
        replacePrev->setText(QApplication::translate("MainWindow", "<", 0, QApplication::UnicodeUTF8));
        replaceNext->setText(QApplication::translate("MainWindow", "<", 0, QApplication::UnicodeUTF8));
        replaceAll->setText(QApplication::translate("MainWindow", "Replace All", 0, QApplication::UnicodeUTF8));
        findClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
