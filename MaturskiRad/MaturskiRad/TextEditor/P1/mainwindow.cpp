#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <Qsci/qsciscintilla.h>
#include <TextEdit.h>
//#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFontDialog>
#include <QColorDialog>
#include <QSettings>

MainWindow::MainWindow(QStringList files, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionOpen->setIcon( QIcon::fromTheme("document-open") );
    ui->actionNew->setIcon( QIcon::fromTheme("document-new") );
    ui->actionClose->setIcon( QIcon::fromTheme("document-close"));
    ui->actionQuit->setIcon( QIcon::fromTheme("application-exit"));
    ui->actionSave->setIcon( QIcon::fromTheme("document-save"));
    ui->actionSaveAs->setIcon( QIcon::fromTheme("document-save-as"));
    ui->actionCut->setIcon( QIcon::fromTheme("edit-cut"));
    ui->actionCopy->setIcon( QIcon::fromTheme("edit-copy"));
    ui->actionPaste->setIcon( QIcon::fromTheme("edit-paste"));
    ui->actionSelectAll->setIcon( QIcon::fromTheme("edit-select-all"));
    ui->actionUndo->setIcon( QIcon::fromTheme("edit-undo"));
    ui->actionRedo->setIcon( QIcon::fromTheme("edit-redo"));
    ui->actionFind->setIcon( QIcon::fromTheme("edit-find"));
    ui->actionIndent->setIcon( QIcon::fromTheme("format-indent-more"));
    ui->actionUnindent->setIcon( QIcon::fromTheme("format-indent-less"));
    ui->actionZoom_In->setIcon( QIcon::fromTheme("format-font-size-more"));
    ui->actionZoom_Out->setIcon( QIcon::fromTheme("format-font-size-less"));

    ui->findWidget->hide();
    ui->gotoLineWidget->hide();

    QSettings set;
    if( set.contains("font") && set.contains("font-size") && set.contains("font-weight") && set.contains("font-italic") )
    {
        m_textFont = QFont( set.value("font").toString()     , set.value("font-size").toInt() ,
                            set.value("font-weight").toInt() , set.value("font-italic").toBool() );
    }
    else
    {
         m_textFont = font();
         set.setValue("font", m_textFont.family() );
         set.setValue("font-size", m_textFont.pointSize() );
         set.setValue("font-weight", m_textFont.weight() );
         set.setValue("font-italic" , m_textFont.italic() );
    }

    if( set.contains("color-red") && set.contains("color-green") && set.contains("color-blue") && set.contains("color-alpha") )
    {
        m_textColor = QColor( set.value("color-red").toInt() , set.value("color-green").toInt() ,
                              set.value("color-blue").toInt(), set.value("color-alpha").toInt() );
    }
    else
    {
        m_textColor = QColor( Qt::black );

        set.setValue("color-red"   , m_textColor.red()   );
        set.setValue("color-green" , m_textColor.green() );
        set.setValue("color-blue"  , m_textColor.blue()  );
        set.setValue("color-alpha" , m_textColor.alpha() );
    }

    if( set.contains("last-path"))
    {
        m_lastPath = set.value("last-path").toString();
    }
    else
    {
        m_lastPath = QDir::homePath();

        set.setValue("last-path", m_lastPath );
    }


    //qDebug() << files.count();
    if( files.count() == 0)
    {
        createTab("");
    }
    else
    {
        foreach( QString name, files)
        {
            createTab( name );
        }
    }

    connect( ui->actionUndo            , SIGNAL(triggered())              , this                   , SLOT(undo())                 );
    connect( ui->actionRedo            , SIGNAL(triggered())              , this                   , SLOT(redo())                 );
    connect( ui->actionOpen            , SIGNAL(triggered())              , this                   , SLOT(open())                 );
    connect( ui->actionSave            , SIGNAL(triggered())              , this                   , SLOT(save())                 );
    connect( ui->actionSaveAs          , SIGNAL(triggered())              , this                   , SLOT(saveAs())               );
    connect( ui->tabWidget             , SIGNAL(currentChanged(int))      , this                   , SLOT(configureGui(int))      );
    connect( ui->tabWidget             , SIGNAL(tabCloseRequested(int))   , this                   , SLOT(closeTab(int))          );
    connect( ui->actionNew             , SIGNAL(triggered())              , this                   , SLOT(newTab())               );
    connect( ui->actionClose           , SIGNAL(triggered())              , this                   , SLOT(closeTabFromMenu())     );
    connect( ui->actionQuit            , SIGNAL(triggered())              , this                   , SLOT(quitFromMenu())         );

    //find
    connect( ui->actionFind               , SIGNAL(triggered())              , this                   , SLOT(toggleFindWidget())     );
    connect( ui->findClose                , SIGNAL(clicked())                , this                   , SLOT(toggleFindWidget())     );
    connect( ui->findEdit                 , SIGNAL(textChanged(QString))     , this                   , SLOT(findFirst(QString))     );
    connect( ui->findNext                 , SIGNAL(clicked())                , this                   , SLOT(findNext())             );
    connect( ui->findPrev                 , SIGNAL(clicked())                , this                   , SLOT(findPrev())             );
    connect( ui->actionFind_Next          , SIGNAL(triggered())              , this                   , SLOT(findNext())             );
    connect( ui->actionFind_Previous      , SIGNAL(triggered())              , this                   , SLOT(findPrev())             );
    connect( ui->replaceNext              , SIGNAL(clicked())                , this                   , SLOT(replaceNext())          );
    connect( ui->replacePrev              , SIGNAL(clicked())                , this                   , SLOT(replacePrevious())      );
    connect( ui->replaceAll               , SIGNAL(clicked())                , this                   , SLOT(replaceAll())           );

    //gotoLine
    connect( ui->gotoLineClose            , SIGNAL(clicked())                , this                   , SLOT(toggleGotoLine())       );
    connect( ui->actionGo_To_Line         , SIGNAL(triggered())              , this                   , SLOT(toggleGotoLine())       );
    connect( ui->gotoLineSpin             , SIGNAL(valueChanged(int))        , this                   , SLOT(gotoLine(int))          );

    //select
    connect( ui->actionSelectAll          , SIGNAL(triggered())              , this                   , SLOT(selectAll())            );
    connect( ui->actionDeselect           , SIGNAL(triggered())              , this                   , SLOT(deselect())             );

    //copy-paste
    connect( ui->actionCopy               , SIGNAL(triggered())              , this                   , SLOT(copy())                 );
    connect( ui->actionCut                , SIGNAL(triggered())              , this                   , SLOT(cut())                  );
    connect( ui->actionPaste              , SIGNAL(triggered())              , this                   , SLOT(paste())                );

    //tools
    connect( ui->actionIndent             , SIGNAL(triggered())              , this                   , SLOT(indent())               );
    connect( ui->actionUnindent           , SIGNAL(triggered())              , this                   , SLOT(unindent())             );
    connect( ui->actionUppercase          , SIGNAL(triggered())              , this                   , SLOT(uppercase())            );
    connect( ui->actionLowercase          , SIGNAL(triggered())              , this                   , SLOT(lowercase())            );
    connect( ui->actionCapitalize         , SIGNAL(triggered())              , this                   , SLOT(capitalize())           );

    //settings
    connect( ui->actionSelect_Font        , SIGNAL(triggered())              , this                   , SLOT(selectFont())           );
    connect( ui->actionSelect_Font_Color  , SIGNAL(triggered())              , this                   , SLOT(selectFontColor())      );
    connect( ui->actionZoom_In            , SIGNAL(triggered())              , this                   , SLOT(zoomIn())               );
    connect( ui->actionZoom_Out           , SIGNAL(triggered())              , this                   , SLOT(zoomOut())              );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    quitFromMenu();
    Q_UNUSED(e)
}
//Find--------------------------------------------------------------------------------------
void MainWindow::toggleFindWidget()
{
    ui->findWidget->setVisible( !ui->findWidget->isVisible() );
    ui->actionFind->setChecked( ui->findWidget->isVisible() );
}

void MainWindow::findFirst(QString value)
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        edit->findFirst(value, false, true, false, true, true, 0, 0 , true);
    }
}

void MainWindow::findNext()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
         edit->findFirst( ui->findEdit->text() , false, true, false, true);
    }
}

void MainWindow::findPrev()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        int line, pos;
        edit->getCursorPosition( &line, &pos );
        edit->findFirst( ui->findEdit->text() , false, true, false, true, false, line, pos - ui->findEdit->text().count() , true);
    }
}

void MainWindow::replaceNext()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        edit->replace( ui->replaceEdit->text() );
        findNext();
    }
}

void MainWindow::replacePrevious()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        //qDebug() << "bla";
        edit->replace( ui->replaceEdit->text() );
        findPrev();
    }
}

void MainWindow::replaceAll()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        edit->findFirst( ui->findEdit->text() , false, true, false, false, true, 0, 0 , true);
        edit->replace( ui->replaceEdit->text() );

        while( edit->findFirst( ui->findEdit->text() , false, true, false, false) )
        {
            edit->replace( ui->replaceEdit->text() );
        }
    }
}

//Goto Line--------------------------------------------------------------------------------------------

void MainWindow::toggleGotoLine()
{
    ui->gotoLineWidget->setVisible( !ui->gotoLineWidget->isVisible() );
    ui->actionGo_To_Line->setChecked( ui->gotoLineWidget->isVisible() );
}

void MainWindow::gotoLine(int value)
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        edit->setCursorPosition(value, 0);
    }
}

void MainWindow::setGotoMaximum()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        ui->gotoLineSpin->setMaximum( edit->lines() );
    }
}

//select----------------------------------------------------------------------------------------------------------------

void MainWindow::selectAll()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        edit->selectAll(true);
    }
}

void MainWindow::deselect()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        edit->selectAll(false);

    }
}

//Copy-Paste-------------------------------------------------------------------------------------------------------------

void MainWindow::toggleCopyAction(bool value)
{
    ui->actionCut->setEnabled(value);
    ui->actionCopy->setEnabled(value);
}

void MainWindow::copy()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        edit->copy();
    }
}

void MainWindow::cut()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        edit->cut();
    }
}

void MainWindow::paste()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        edit->paste();
    }
}

//Tools-------------------------------------------------------------------------------------------------------------------

void MainWindow::indent()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        int l1, l2, p1, p2;

        edit->getSelection(&l1,&p1,&l2,&p2);

        for( int i = l1 ; i <= l2; ++i)
        {
            edit->indent( i );
        }
    }
}

void MainWindow::unindent()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        int l1, l2, p1, p2;

        edit->getSelection(&l1,&p1,&l2,&p2);

        for( int i = l1 ; i <= l2; ++i)
        {
            edit->unindent( i );
        }
    }
}

void MainWindow::uppercase()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        QString pomocni = edit->selectedText().toUpper();

        int l1, l2, p1, p2;

        edit->getSelection(&l1,&p1,&l2,&p2);

        edit->removeSelectedText();

        edit->insertAt( pomocni , l1, p1);
    }
}

void MainWindow::lowercase()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        QString pomocni = edit->selectedText().toLower();

        int l1, l2, p1, p2;

        edit->getSelection(&l1,&p1,&l2,&p2);

        edit->removeSelectedText();

        edit->insertAt( pomocni , l1, p1);
    }
}

void MainWindow::capitalize()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        QString pomocni = edit->selectedText()[0].toUpper() + edit->selectedText().remove(0,1).toLower();

        int l1, l2, p1, p2;

        edit->getSelection(&l1,&p1,&l2,&p2);

        edit->removeSelectedText();

        edit->insertAt( pomocni , l1, p1);
    }
}

//Settings----------------------------------------------------------------------------------------------------------------------

void MainWindow::selectFont()
{
    bool ok;
    QFont font = QFontDialog::getFont( &ok, m_textFont, this);
    if (ok)
    {
        for( int i=0; i < ui->tabWidget->count(); ++i)
        {
            TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->widget(i) );
            if(edit)
            {
                edit->setFont( font );
                edit->mySetMarginWidth();

                m_textFont = font;

                QSettings set;

                set.setValue("font", m_textFont.family() );
                set.setValue("font-size", m_textFont.pointSize() );
                set.setValue("font-weight", m_textFont.weight() );
                set.setValue("font-italic" , m_textFont.italic() );
            }
        }
    }
}

void MainWindow::selectFontColor()
{
    QColor color = QColorDialog::getColor( m_textColor , this );
    //qDebug() << color;
    for( int i=0; i < ui->tabWidget->count(); ++i)
    {
        TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->widget(i) );
        if(edit)
        {
            edit->setColor( color );
            edit->mySetMarginWidth();

            m_textColor = color;

            QSettings set;

            set.setValue("color-red"   , m_textColor.red()   );
            set.setValue("color-green" , m_textColor.green() );
            set.setValue("color-blue"  , m_textColor.blue()  );
            set.setValue("color-alpha" , m_textColor.alpha() );
        }
    }
}

void MainWindow::zoomIn()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        edit->zoomIn();
        edit->mySetMarginWidth();
    }
}

void MainWindow::zoomOut()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        edit->zoomOut();
        edit->mySetMarginWidth();
    }
}

//-------------------------------------------------------------------------------------------------------------------------------

void MainWindow::quitFromMenu()
{
    //qDebug() << ui->tabWidget->count();
    int end = ui->tabWidget->count();

    for(int i= end - 1; i >= 0; --i)
    {
        //qDebug() << i;
        if( closeTab(i) == QMessageBox::Cancel ) return;
    }

    exit(0);

}

void MainWindow::newTab()
{
    createTab("");
}

void MainWindow::closeTabFromMenu()
{
    closeTab( ui->tabWidget->currentIndex() );
}

void MainWindow::requestedClosing(TextEdit *value)
{
    closeTab( ui->tabWidget->indexOf( value ));
}

void MainWindow::createTab(QString fileName)
{
    TextEdit *editWidget = new TextEdit(fileName);
    ui->tabWidget->addTab(editWidget, editWidget->getTabName() );
    ui->tabWidget->setCurrentWidget( editWidget );

    editWidget->setFont( m_textFont );
    editWidget->setColor( m_textColor );

    //connect( editWidget     , SIGNAL(textChanged())                   , this         , SLOT(configureGui())               );
    connect( editWidget     , SIGNAL(modificationChanged(bool))       , this         , SLOT(configureGui(bool))           );
    connect( editWidget     , SIGNAL(linesChanged())                  , this         , SLOT(setGotoMaximum())             );
    connect( editWidget     , SIGNAL(copyAvailable(bool))             , this         , SLOT(toggleCopyAction(bool))       );
    connect( editWidget     , SIGNAL(requestClosing(TextEdit*))       , this         , SLOT(requestedClosing(TextEdit*))  );

    configureGui();
}

void MainWindow::undo()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        edit->undo();
    }
}

void MainWindow::redo()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        edit->redo();
    }
}

void MainWindow::open()
{
    QStringList  fileNames = QFileDialog::getOpenFileNames(this, "Select files to edit", m_lastPath );
    if( !fileNames.empty() )
    {
        foreach( QString name, fileNames)
        {
            m_lastPath = name;
            createTab( name );
        }
    }

    QSettings set;
    set.setValue("last-path", m_lastPath );
}

void MainWindow::save()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        edit->saveFile();
    }
}

void MainWindow::saveAs()
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->currentWidget() );
    if(edit)
    {
        edit->saveAsFile();
    }
}

void MainWindow::configureGui()
{
    configureGui( ui->tabWidget->currentIndex() );
}

void MainWindow::configureGui(bool value)
{
    configureGui( ui->tabWidget->currentIndex() );
    Q_UNUSED(value)
}

void MainWindow::configureGui(int index)
{
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->widget(index) );
    if(edit)
    {
        //qDebug() << edit->isModified();
        ui->actionRedo->setEnabled( edit->isRedoAvailable() );
        ui->actionUndo->setEnabled( edit->isUndoAvailable() );
        ui->actionSave->setEnabled( edit->isModified() );

        int l1,p1,l2,p2;
        edit->getSelection(&l1,&p1,&l2,&p2);

        ui->actionCut->setEnabled( (p1 - p2) != 0 );
        ui->actionCopy->setEnabled( (p1 - p2) != 0 );


        ui->tabWidget->setTabText( ui->tabWidget->currentIndex(), edit->getTabName() );
        ui->gotoLineSpin->setMaximum( edit->lines() );

        setWindowTitle("Squirrel Editor - " + edit->getDocumentName() );
    }
}

int MainWindow::closeTab(int value)
{
    //qDebug() << value;
    TextEdit *edit = dynamic_cast<TextEdit*>( ui->tabWidget->widget(value) );
    if( edit )
    {
        //qDebug() << "tu sam2";
        if( edit->isModified() )
        {
            QMessageBox msgBox;
            msgBox.setIcon( QMessageBox::Warning );
            msgBox.setWindowTitle("Save Document");
            msgBox.setText("The document '" + edit->getDocumentName() + "' has been modified.");
            msgBox.setInformativeText("Do you want to save your changes?");
            msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Save);
            int ret = msgBox.exec();

            if( ret == QMessageBox::Save )
            {
                edit->saveFile();
                ui->tabWidget->removeTab( value );
                delete edit;
            }
            else if( ret == QMessageBox::Discard )
            {
                ui->tabWidget->removeTab( value );
                delete edit;
            }
            else if( ret == QMessageBox::Cancel )
            {
                return ret;
            }

        }
        else
        {
            ui->tabWidget->removeTab( value );
            delete edit;
        }

        if( ui->tabWidget->count() == 0 )
        {
            createTab("");
        }
    }
    return QMessageBox::NoButton;
}

