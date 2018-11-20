/*
    K-28
    element_alarm.cpp
    Purpose: implementation of class ElementAlarm functions
    @author Mariia Kushnirenko
    @version 1.1 17/11/18
*/


#include "element_alarm.h"
#include "ui_element_alarm.h"

ElementAlarm::ElementAlarm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ElementAlarm)
{
    ui->setupUi(this);
    ui->timeEdit->setTime(QTime::currentTime());
}

ElementAlarm::~ElementAlarm()
{
    delete ui;
}

/*
    Setting the alarm for a certain time

    @param -
    @return -
*/
void ElementAlarm::on_set_time_alarm_clicked()
{
    time=ui->timeEdit->time();
    time.setHMS(time.hour(), time.minute(),0);
    this->close();
    is_turn=true;
    emit return_element_alarm(this);
}


