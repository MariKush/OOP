#ifndef TIMERWINDOW_H
#define TIMERWINDOW_H

/*
    K-28
    timerwindow.h
    Purpose: description class TimerWindow
    @author Mariia Kushnirenko
    @version 1.1 20/11/18
*/

#include "alarmwindow.h"
#include <element_timer.h>

namespace Ui {
class TimerWindow;
}

class TimerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TimerWindow(QWidget *parent = nullptr);
    ~TimerWindow();
signals:
    void timer_ring();

private slots:
    void on_add_new_timer_clicked();
    void push_timer(ElementTimer *el);
    void output_correct_timer_buttons_name();
    void output_list_of_timers();
    void check_timer();
    void on_start_stop_timer_clicked();
    void on_pause_continue_timer_clicked();
    void on_delete_timer_clicked();

private:
    Ui::TimerWindow *ui;
    QVector<ElementTimer*> timers;
};

#endif // TIMERWINDOW_H
