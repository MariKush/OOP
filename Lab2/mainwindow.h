#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*
    K-28
    mainwindow.h
    Purpose: description class MainWindow
    @author Mariia Kushnirenko
    @version 1.1 17/11/18
*/


#include <QMainWindow>
#include "timerwindow.h"
#include "alarmwindow.h"
#include "ring.h"
#include "notdisturb.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_gotoTimer_clicked();

    void on_gotoAlarm_clicked();

    void call_ring();

    void on_checkBox_stateChanged(int arg1);

    void on_not_disturb_setting_clicked();

private:
    Ui::MainWindow *ui;
    TimerWindow *timers=new TimerWindow;
    AlarmWindow *alarms=new AlarmWindow;
    Ring general_ring;
    NotDisturb not_disturb_MW;

};

#endif // MAINWINDOW_H
