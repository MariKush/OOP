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

#endif // ALARMWINDOW_H
