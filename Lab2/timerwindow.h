#ifndef TIMERWINDOW_H
#define TIMERWINDOW_H

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
