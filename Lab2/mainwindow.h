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

private:
    Ui::MainWindow *ui;
    TimerWindow *timers=new TimerWindow;
    AlarmWindow *alarms=new AlarmWindow;
    Ring general_ring;
};

#endif // MAINWINDOW_H
