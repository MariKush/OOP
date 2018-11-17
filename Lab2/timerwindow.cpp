/*
    K-28
    timerwindow.cpp
    Purpose: implementation of class TimerWindow functions
    @author Mariia Kushnirenko
    @version 1.1 17/11/18
*/

#include "timerwindow.h"
#include "ui_timerwindow.h"

TimerWindow::TimerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimerWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this,SLOT(output_list_of_timers()));
    timer->start(10);
}

TimerWindow::~TimerWindow()
{
    delete ui;
}

QString fromqtimer(QTimer *timer)
{
    QTime tmp=QTime::currentTime();
    tmp=tmp.addMSecs(timer->remainingTime());
    return time_to(tmp);

}

void TimerWindow::on_add_new_clicked()
{
    ElementTimer *el_ti=new ElementTimer;
    el_ti->show();
    connect(el_ti,SIGNAL(return_element_timer(ElementTimer *)), this, SLOT(push(ElementTimer *)));
}

void TimerWindow::push(ElementTimer *el)
{
    timers.push_back(el);
    connect(el->timer, SIGNAL(timeout()), this, SLOT(check()));
}

void TimerWindow::check()
{
    emit timer_ring();
}

void TimerWindow::output_list_of_timers()
{
    int current_row=ui->list_of_timers->currentRow();
    ui->list_of_timers->clear();
    int size_of_list=timers.size();
    for(int i=0;i<size_of_list;i++)
    {
        QString s;
        s=fromqtimer(timers[i]->timer);
        ui->list_of_timers->addItem(s);
    }
    ui->list_of_timers->setCurrentRow(current_row);
}
