#ifndef MPLAYERPROCESS_H
#define MPLAYERPROCESS_H

#include <QProcess>
#include <QSize>

class MPlayerProcess : public QProcess
{
    Q_OBJECT
public:
    MPlayerProcess(QWidget *videoWidget);
    ~MPlayerProcess();

    bool isPlaying() const { return m_isPlaying; }
    QSize getSize() const  { return m_videoSize; }

signals:
    void mediaPosition(int);
    void volumeChanged(int);
    void durationChanged(int);
    void volumeLevelChanged(int);
    void fileNameChanged(QString);
    void paused();
    void sizeChanged();

public slots:
    void openStream(QString);
    void togglePlayPause();
    void setMediaPosition(int);
    void setVolume(int);
    void setLoop(bool);
    void setSpeed(int);
    void setAudioDelay(int);


protected slots:
    void readStandardOutput();

private:
    bool            m_isPlaying;
    int             m_duration;
    QSize           m_videoSize;
};

#endif // MPLAYERPROCESS_H
