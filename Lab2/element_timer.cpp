/*
    K-28
    element_alarm.cpp
    Purpose: implementation of class ElementTimer functions
    @author Mariia Kushnirenko
    @version 1.1 20/11/18
*/



#include "element_timer.h"
#include "ui_element_timer.h"

ElementTimer::ElementTimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ElementTimer)
{
    ui->setupUi(this);
    timer= new QTimer;
    tmp_pause.setHMS(0,0,0);
}

ElementTimer::~ElementTimer()
{
    timer->stop();
    delete timer;
    delete ui;
}

/*
    Setting timer time

    @param -
    @return -
*/
void ElementTimer::on_set_timer_time_clicked()
{
    time=ui->timeEdit->time();
    emit return_element_timer(this);
    this->close();
    timer->start(time.msecsSinceStartOfDay());
    connect(timer, SIGNAL(timeout()), this,SLOT(stop_timer()));
}

/*
    Stop timer

    @param -
    @return -
*/
void ElementTimer::stop_timer()
{
    this->timer->stop();
}
