#include <TextEdit.h>

#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QCoreApplication>

TextEdit::TextEdit(QString fileName) : QsciScintilla(0)
{
    connect( this          , SIGNAL(linesChanged())          , SLOT(mySetMarginWidth())         );

    if( fileName != "") openFile( fileName );

    setFileName( fileName );

    setMarginLineNumbers(1,true);
    m_oldLineNumber = lines();

    setMarginWidth(1, QString::number(lines() )  + "0");
}

TextEdit::~TextEdit()
{

}

void TextEdit::openFile(QString fileName)
{
    QFile file( fileName );

    if( file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        QTextStream stream( &file );
        append( stream.readAll() );
        file.close();

        setModified(false);
    }
    else
    {
        requestClosing(this);
    }
}

void TextEdit::saveFile()
{
    if( getFileName() == "" )
    {
        saveAsFile();
    }
    else
    {
        writeToFile( getFileName() );
    }
}

void TextEdit::saveAsFile()
{
    QFileInfo file(m_fileName);

    QString pom = file.filePath();
    if( pom == "") pom = QDir::homePath();

    QString pomocni = QFileDialog::getSaveFileName( this , "Save", pom );
    if( pomocni != "" ) writeToFile( pomocni );
}

void TextEdit::writeToFile(QString fileName)
{
    QFile file( fileName );

    if( file.open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        QTextStream stream( &file );

        stream << text();

        file.close();

        setFileName( fileName );

        setModified(false);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setIcon( QMessageBox::Critical );
        msgBox.setWindowTitle("Can't save document");
        msgBox.setText("The document '" + getDocumentName() + "' can't be saved.");
        msgBox.setInformativeText("Maybe you don' have the right privilege?");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
}

void TextEdit::mySetMarginWidth()
{
    setMarginWidth(1, QString::number(lines()) + "0");
}

void TextEdit::setFileName(QString fileName)
{
    m_fileName = fileName;
    setTabName( fileName );
}

void TextEdit::setTabName(QString fileName)
{
    if( fileName == "")
    {
        m_tabName = "Untitled";
        m_documentName = "Untitled";
    }
    else
    {
        QFileInfo file(fileName);
        m_documentName = file.fileName();
        if( file.fileName().count() > 25 )
        {
            m_tabName = file.fileName();
            m_tabName.truncate(22);
            m_tabName = m_tabName + "...";
        }
        else
        {
            m_tabName = file.fileName();
        }
    }
}

