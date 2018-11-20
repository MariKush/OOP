#ifndef ALARMWINDOW_H
#define ALARMWINDOW_H

/*
    K-28
    alarmwindow.h
    Purpose: description class AlarmWindow
    @author Mariia Kushnirenko
    @version 1.1 17/11/18
*/

#include <QDialog>
#include "element_alarm.h"

namespace Ui {
class AlarmWindow;
}

class AlarmWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AlarmWindow(QWidget *parent = nullptr);
    ~AlarmWindow();
signals:
    void alarm_ring();

private slots:
    void on_add_new_alarm_clicked();
    void push(ElementAlarm *);
    void output_list_of_alarm();
    void check_alarms();
    void output_correct_buttons_name();
    void on_start_stop_alarm_clicked();
    void on_delete_timer_clicked();

private:
    Ui::AlarmWindow *ui;
    QVector<ElementAlarm*> alarms;
};

inline QString time_to(QTime time)
{
    QTime tmp;
    tmp.setHMS(0,0,0);
    int secto=QTime::currentTime().secsTo(time);
    tmp=tmp.addSecs(secto);
    QChar s=':';
    if (secto%2==1)s=' ';
    return tmp.toString("h")+s+tmp.toString("mm")+s+tmp.toString("ss");
}

#endif // ALARMWINDOW_H
