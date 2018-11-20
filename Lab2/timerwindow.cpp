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



void TimerWindow::output_correct_buttons_name()
{
    int current_row=-1;
    current_row=ui->list_of_timers->currentRow();

    //start/stop
    {
        if (current_row==-1)
        {
            ui->start_stop_timer->setHidden(true);
        }
        else
        {
            ui->start_stop_timer->setHidden(false);
            if(timers[current_row]->timer->isActive()||timers[current_row]->pause)
                ui->start_stop_timer->setText("Stop");
            else ui->start_stop_timer->setText("Start");
        }
    }

    //delete current
    {
        if (current_row==-1) ui->delete_timer->setHidden(true);
        else ui->delete_timer->setHidden(false);
    }

    //pause_continue_timer current
    {
        if (current_row==-1||
           (!timers[current_row]->timer->isActive()&&!timers[current_row]->pause))
            ui->pause_continue_timer->setHidden(true);
        else
        {
            ui->pause_continue_timer->setHidden(false);
            if(timers[current_row]->timer->isActive()&&!timers[current_row]->pause)
                ui->pause_continue_timer->setText("pause");
            else ui->pause_continue_timer->setText("continue");
        }
    }
}

void TimerWindow::output_list_of_timers()
{
    output_correct_buttons_name();
    int current_row=ui->list_of_timers->currentRow();
    ui->list_of_timers->clear();
    int size_of_list=timers.size();
    for(int i=0;i<size_of_list;i++)
    {
        QString s;
        s = timers[i]->time.toString("h:mm:ss");
        if(timers[i]->timer->isActive()||timers[i]->pause)
        {
            if (!timers[i]->pause)
            {
                QTime t(0, 0, 0);
                t=t.addMSecs(timers[i]->timer->remainingTime());
                s=s+" "+t.toString("h:mm:ss:zzz");
            }
            else
                s=s+" "+timers[i]->tmp_pause.toString("h:mm:ss:zzz");
        }
        ui->list_of_timers->addItem(s);
        if(!timers[i]->timer->isActive()&&!timers[i]->pause)
            ui->list_of_timers->item(i)->setForeground(Qt::red);
    }
    ui->list_of_timers->setCurrentRow(current_row);
}

void TimerWindow::on_start_stop_timer_clicked()
{
    int current_row=ui->list_of_timers->currentRow();
    if (timers[current_row]->timer->isActive()||timers[current_row]->pause)//stop
    {
        timers[current_row]->pause=false;
        timers[current_row]->tmp_pause.setHMS(0,0,0);
        timers[current_row]->timer->stop();
    }
    else//start
    {
        timers[current_row]->timer->start(timers[current_row]->time.msecsSinceStartOfDay());
    }
}

void TimerWindow::on_pause_continue_timer_clicked()
{
    ElementTimer* element=timers[ui->list_of_timers->currentRow()];
    if (element->pause)
    {
        element->pause=false;
        element->timer->start(element->tmp_pause.msecsSinceStartOfDay());
        element->tmp_pause.setHMS(0,0,0);
    }
    else
    {
        element->pause=true;
        element->tmp_pause=element->tmp_pause.addMSecs(element->timer->remainingTime());
        element->timer->stop();
    }
}

void TimerWindow::on_delete_timer_clicked()
{
    int current_row=ui->list_of_timers->currentRow();
    timers[current_row]->~ElementTimer();
    timers.erase(timers.begin()+current_row);
}
