/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Apr 9 12:10:32 2010
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
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionPlay;
    QAction *actionMute;
    QAction *actionVideoOptions;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *videoWidget;
    QToolBar *mainToolBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QFormLayout *formLayout;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QComboBox *comboBoxSub;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonFont;
    QPushButton *pushButtonColor;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QSlider *horizontalSliderSubSize;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QSpinBox *spinBox;
    QGroupBox *groupBox_4;
    QFormLayout *formLayout_5;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QSpinBox *spinBoxSpeed;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QComboBox *comboBoxAspect;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QSpinBox *spinBoxAVDelay;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QCheckBox *checkBoxLoop;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_7;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(689, 460);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
        actionMute = new QAction(MainWindow);
        actionMute->setObjectName(QString::fromUtf8("actionMute"));
        actionVideoOptions = new QAction(MainWindow);
        actionVideoOptions->setObjectName(QString::fromUtf8("actionVideoOptions"));
        actionVideoOptions->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        videoWidget = new QWidget(centralWidget);
        videoWidget->setObjectName(QString::fromUtf8("videoWidget"));
        videoWidget->setContextMenuPolicy(Qt::NoContextMenu);
        videoWidget->setAutoFillBackground(true);

        horizontalLayout->addWidget(videoWidget);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::TopToolBarArea);
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setMinimumSize(QSize(169, 368));
        dockWidget->setFeatures(QDockWidget::DockWidgetClosable);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        formLayout = new QFormLayout(dockWidgetContents);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(0, 0, 0, 0);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        groupBox_2 = new QGroupBox(dockWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFlat(false);
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        comboBoxSub = new QComboBox(groupBox_2);
        comboBoxSub->setObjectName(QString::fromUtf8("comboBoxSub"));

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, comboBoxSub);

        widget = new QWidget(groupBox_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButtonFont = new QPushButton(widget);
        pushButtonFont->setObjectName(QString::fromUtf8("pushButtonFont"));

        horizontalLayout_2->addWidget(pushButtonFont);

        pushButtonColor = new QPushButton(widget);
        pushButtonColor->setObjectName(QString::fromUtf8("pushButtonColor"));

        horizontalLayout_2->addWidget(pushButtonColor);


        formLayout_2->setWidget(3, QFormLayout::SpanningRole, widget);

        widget_4 = new QWidget(groupBox_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(widget_4);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label);

        horizontalSliderSubSize = new QSlider(widget_4);
        horizontalSliderSubSize->setObjectName(QString::fromUtf8("horizontalSliderSubSize"));
        horizontalSliderSubSize->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSliderSubSize);


        formLayout_2->setWidget(1, QFormLayout::SpanningRole, widget_4);

        widget_5 = new QWidget(groupBox_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        spinBox = new QSpinBox(widget_5);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout_5->addWidget(spinBox);


        formLayout_2->setWidget(2, QFormLayout::SpanningRole, widget_5);


        formLayout->setWidget(1, QFormLayout::SpanningRole, groupBox_2);

        groupBox_4 = new QGroupBox(dockWidgetContents);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        formLayout_5 = new QFormLayout(groupBox_4);
        formLayout_5->setSpacing(6);
        formLayout_5->setContentsMargins(0, 0, 0, 0);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        widget_2 = new QWidget(groupBox_4);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_8 = new QHBoxLayout(widget_2);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_8->addWidget(label_2);

        spinBoxSpeed = new QSpinBox(widget_2);
        spinBoxSpeed->setObjectName(QString::fromUtf8("spinBoxSpeed"));
        spinBoxSpeed->setFrame(true);
        spinBoxSpeed->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        spinBoxSpeed->setReadOnly(false);
        spinBoxSpeed->setKeyboardTracking(true);
        spinBoxSpeed->setMinimum(40);
        spinBoxSpeed->setMaximum(800);
        spinBoxSpeed->setSingleStep(10);
        spinBoxSpeed->setValue(100);

        horizontalLayout_8->addWidget(spinBoxSpeed);


        formLayout_5->setWidget(0, QFormLayout::SpanningRole, widget_2);

        widget_6 = new QWidget(groupBox_4);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(widget_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        comboBoxAspect = new QComboBox(widget_6);
        comboBoxAspect->setObjectName(QString::fromUtf8("comboBoxAspect"));

        horizontalLayout_6->addWidget(comboBoxAspect);


        formLayout_5->setWidget(1, QFormLayout::SpanningRole, widget_6);

        widget_7 = new QWidget(groupBox_4);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_7 = new QHBoxLayout(widget_7);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(widget_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(label_6);

        spinBoxAVDelay = new QSpinBox(widget_7);
        spinBoxAVDelay->setObjectName(QString::fromUtf8("spinBoxAVDelay"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBoxAVDelay->sizePolicy().hasHeightForWidth());
        spinBoxAVDelay->setSizePolicy(sizePolicy1);
        spinBoxAVDelay->setReadOnly(false);
        spinBoxAVDelay->setAccelerated(false);
        spinBoxAVDelay->setMinimum(-500);
        spinBoxAVDelay->setMaximum(500);

        horizontalLayout_7->addWidget(spinBoxAVDelay);


        formLayout_5->setWidget(2, QFormLayout::SpanningRole, widget_7);

        widget_3 = new QWidget(groupBox_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_3);

        checkBoxLoop = new QCheckBox(widget_3);
        checkBoxLoop->setObjectName(QString::fromUtf8("checkBoxLoop"));
        sizePolicy1.setHeightForWidth(checkBoxLoop->sizePolicy().hasHeightForWidth());
        checkBoxLoop->setSizePolicy(sizePolicy1);
        checkBoxLoop->setTristate(false);

        horizontalLayout_3->addWidget(checkBoxLoop);


        formLayout_5->setWidget(4, QFormLayout::SpanningRole, widget_3);

        widget_8 = new QWidget(groupBox_4);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_10 = new QHBoxLayout(widget_8);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_7 = new QLabel(widget_8);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(label_7);

        widget_9 = new QWidget(widget_8);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        sizePolicy.setHeightForWidth(widget_9->sizePolicy().hasHeightForWidth());
        widget_9->setSizePolicy(sizePolicy);
        horizontalLayout_9 = new QHBoxLayout(widget_9);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        pushButton = new QPushButton(widget_9);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_9->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_9);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_9->addWidget(pushButton_2);


        horizontalLayout_10->addWidget(widget_9);


        formLayout_5->setWidget(3, QFormLayout::SpanningRole, widget_8);


        formLayout->setWidget(2, QFormLayout::SpanningRole, groupBox_4);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget);

        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionPlay);
        mainToolBar->addAction(actionVideoOptions);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionPlay->setText(QApplication::translate("MainWindow", "Play", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPlay->setToolTip(QApplication::translate("MainWindow", "Play", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionPlay->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        actionMute->setText(QApplication::translate("MainWindow", "Mute", 0, QApplication::UnicodeUTF8));
        actionVideoOptions->setText(QApplication::translate("MainWindow", "VideoOptions", 0, QApplication::UnicodeUTF8));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "Video Options", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Subtitle", 0, QApplication::UnicodeUTF8));
        comboBoxSub->clear();
        comboBoxSub->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "No Subtitle", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Load Subtitle", 0, QApplication::UnicodeUTF8)
        );
        pushButtonFont->setText(QApplication::translate("MainWindow", "Font", 0, QApplication::UnicodeUTF8));
        pushButtonColor->setText(QApplication::translate("MainWindow", "Color", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Size", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Delay", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Playback", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Speed", 0, QApplication::UnicodeUTF8));
        spinBoxSpeed->setSuffix(QApplication::translate("MainWindow", " %", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Aspect Ratio", 0, QApplication::UnicodeUTF8));
        comboBoxAspect->clear();
        comboBoxAspect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Auto", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1:1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3:2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4:3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5:4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "14:9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "14:10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "16:9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "16:10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2.35:1", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("MainWindow", "A/V Delay", 0, QApplication::UnicodeUTF8));
        spinBoxAVDelay->setSpecialValueText(QString());
        spinBoxAVDelay->setSuffix(QApplication::translate("MainWindow", " sec", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Loop", 0, QApplication::UnicodeUTF8));
        checkBoxLoop->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "Audio", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "<", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", ">", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
