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
    ui->NameEdit->setMaxLength(8);
    ui->TimesToRepeat->setValue(1);
    ui->NameEdit->setText( "Timer"+QString::number(current_index_timer));
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
    if (ui->NameEdit->text().isEmpty())
    {
        name="Timer"+QString::number(current_index_timer);
    }
    else
    {
        name=ui->NameEdit->text();
    }
    current_index_timer++;
    time=ui->timeEdit->time();
    TimesToRepeat=ui->TimesToRepeat->value();
    emit return_element_timer(this);
    this->close();
    connect(timer, SIGNAL(timeout()), this,SLOT(stop_timer()));
    if (TimesToRepeat>0)
        timer->start(time.msecsSinceStartOfDay());
}

/*
    Stop timer

    @param -
    @return -
*/
void ElementTimer::stop_timer()
{
    TimesToRepeat--;
    if (TimesToRepeat==0)
    {
        this->timer->stop();
    }

}
