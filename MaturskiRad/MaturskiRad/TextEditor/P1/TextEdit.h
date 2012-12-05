#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <Qsci/qsciscintilla.h>
#include <QFileInfo>

class TextEdit : public QsciScintilla
{
    Q_OBJECT

public:
    TextEdit(QString fileName);
    ~TextEdit();

    QString getFileName() const { return m_fileName; }
    QString getDocumentName() const { return m_documentName; }

    QString getTabName() const { return m_tabName; }

    void openFile( QString fileName );

    void saveFile();
    void saveAsFile();
    void setTabName( QString fileName );
    void setFileName( QString fileName );

public slots:
    void mySetMarginWidth();

protected slots:
    void writeToFile( QString fileName );

signals:
    void updateGui();
    void requestClosing( TextEdit* );
    void fileWriteError( TextEdit* );

private:
    QString             m_fileName;
    QString             m_tabName;
    QString             m_documentName;
    int                 m_oldLineNumber;
};

#endif // TEXTEDIT_H
