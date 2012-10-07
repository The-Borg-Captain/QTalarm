#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QObject>
#include <QTime>
#include <QDateTime>

class Schedule : public QObject
{
    Q_OBJECT
public:
    explicit Schedule(QObject *parent = 0);
    void SetSchedule(bool,QDateTime,bool,QTime,bool,QTime);
    void SetWDEnabled(bool);
    void SetWEEnabled(bool);
    void SetCustEnabled(bool);
    void SetWD(QTime);
    void SetWE(QTime);
    void SetCust(QDateTime);
    bool GetWDEnabled();
    bool GetWEEnabled();
    bool GetCustomEnabled();
    QTime GetWD();
    QTime GetWE();
    QDateTime GetCustom();

private:
    QTime _WDAlarm;
    QTime _WEAlarm;
    QDateTime _CustomAlarm;
    bool _WDEnabled;
    bool _WEEnabled;
    bool _CustomEnabled;
    
signals:
    
public slots:
    
};

#endif // SCHEDULE_H