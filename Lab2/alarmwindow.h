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
    static QString time_to(QTime time);
signals:
    void alarm_ring();


private slots:
    void on_add_new_alarm_clicked();
    void push_alarm(ElementAlarm *);
    void output_list_of_alarm();
    void check_alarms();
    void output_correct_alarm_buttons_name();
    void on_start_stop_alarm_clicked();
    void on_delete_alarm_clicked();
    void changed_current_row_in_FiltrBox(int);
    void on_ComplementBox_stateChanged(int arg1);

private:
    Ui::AlarmWindow *ui;
    QVector<ElementAlarm*> alarms;
    bool Complement=false;

};

#endif // ALARMWINDOW_H
