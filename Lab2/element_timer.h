#ifndef ELEMENT_TIMER_H
#define ELEMENT_TIMER_H

/*
    K-28
    element_alarm.h
    Purpose: description class ElementTimer
    @author Mariia Kushnirenko
    @version 1.1 20/11/18
*/


#include <QDialog>
#include <QTime>
#include <QTimer>

namespace Ui {
class ElementTimer;
}

class ElementTimer : public QDialog
{
    Q_OBJECT

public:
    explicit ElementTimer(QWidget *parent = nullptr);
    ~ElementTimer();
    QTime time;
    QTime tmp_pause;//for pause
    QTimer *timer;
    bool pause=false;

signals:
    void return_element_timer(ElementTimer *el);

private slots:
    void on_set_timer_time_clicked();
    void stop_timer();

private:
    Ui::ElementTimer *ui;

};

#endif // ELEMENT_TIMER_H
