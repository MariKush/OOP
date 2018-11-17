#ifndef TIMERWINDOW_H
#define TIMERWINDOW_H

/*
    K-28
    timerwindow.h
    Purpose: description class TimerWindow
    @author Mariia Kushnirenko
    @version 1.1 17/11/18
*/


#include <QDialog>

namespace Ui {
class TimerWindow;
}

class TimerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TimerWindow(QWidget *parent = nullptr);
    ~TimerWindow();

private:
    Ui::TimerWindow *ui;
};

#endif // TIMERWINDOW_H
