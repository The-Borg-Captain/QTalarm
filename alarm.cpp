#include "alarm.h"
#include "fileio.h"
#include <phonon/AudioOutput>
#include <phonon/MediaObject>
#include <phonon/MediaSource>
#include <QString>


Alarm::Alarm(QObject *parent) :
    QObject(parent)
{
    media = new Phonon::MediaObject(this);
    Phonon::createPath(media, new Phonon::AudioOutput(Phonon::MusicCategory, this));
    
    this->Path="/tmp/QTalarmTmp.wav";
    #ifdef Q_WS_WIN
	//Override Path if Windows
        this->Path="C:\\Users\\cgugas\\Desktop\\QTalarmTmp.wav";
    #endif
    media->setCurrentSource(Phonon::MediaSource(this->Path));
    this->_isPlaying=false;
}

void Alarm::Start()
{
    FileIO::ExtractAudio();
    media->play();
    connect(media,SIGNAL(aboutToFinish()),this,SLOT(RepeatAllTheThings()));
    this->_isPlaying=true;
}

void Alarm::Stop()
{
    media->stop();
    this->_isPlaying=false;
}

void Alarm::RepeatAllTheThings()
{
    media->enqueue(this->Path);
}

bool Alarm::isPlaying()
{
    return this->_isPlaying;
}