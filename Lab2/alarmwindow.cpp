/*
    K-28
    alarmwindow.cpp
    Purpose: implementation of class AlarmWindow functions
    @author Mariia Kushnirenko
    @version 1.1 17/11/18
*/


#include "alarmwindow.h"
#include "ui_alarmwindow.h"
#include <QTimer>
#include <QColor>

/*
    Calculating time to a given time point

    @param QTime time
    @return string in the form h:mm:ss
*/



AlarmWindow::AlarmWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlarmWindow)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(output_list_of_alarm()));
    timer->start(10);

}

AlarmWindow::~AlarmWindow()
{
    delete ui;
}

void AlarmWindow::on_add_new_alarm_clicked()
{
    ElementAlarm *el_al=new ElementAlarm;
    el_al->show();
    connect(el_al, SIGNAL(return_element_alarm(ElementAlarm *)), this, SLOT(push(ElementAlarm*)));
}

void AlarmWindow::push(ElementAlarm * el)
{
    alarms.push_back(el);
}

void AlarmWindow::output_list_of_alarm()
{
    int current_row=ui->list_of_alarms->currentRow();
    ui->list_of_alarms->clear();
    int size_list_of_alarms=alarms.size();
    for (int i=0;i<size_list_of_alarms;i++)
    {
        QString s;
        s=alarms[i]->time.toString("h:mm ");
        if (alarms[i]->is_turn) s=s+time_to(alarms[i]->time);

        ui->list_of_alarms->addItem(s);
        if(!alarms[i]->is_turn)
            ui->list_of_alarms->item(i)->setForeground(Qt::red);
    }
    ui->list_of_alarms->setCurrentRow(current_row);
    check_alarms();
    output_correct_buttons_name();
}

void AlarmWindow::output_correct_buttons_name()
{
    int current_row=-1;
    current_row=ui->list_of_alarms->currentRow();

    //start/stop
    {
        if (current_row==-1)
        {
            ui->start_stop_alarm->setHidden(true);
        }
        else
        {
            ui->start_stop_alarm->setHidden(false);
            if(alarms[current_row]->is_turn)ui->start_stop_alarm->setText("Stop");
            else ui->start_stop_alarm->setText("Start");
        }
    }

    //delete current
    {
        if (current_row==-1) ui->delete_timer->setHidden(true);
        else ui->delete_timer->setHidden(false);
    }

}

void AlarmWindow::check_alarms()
{
    int size_list_of_alrms=alarms.size();
    for (int i=0;i<size_list_of_alrms;i++)
    {
        if (alarms[i]->is_turn)
        {
            if (alarms[i]->time.hour()==QTime::currentTime().hour()&&
                alarms[i]->time.minute()==QTime::currentTime().minute())
            {
                emit alarm_ring();
                alarms[i]->is_turn=false;
            }
        }
    }
}

void AlarmWindow::on_start_stop_alarm_clicked()
{
    alarms[ui->list_of_alarms->currentRow()]->is_turn-=1;
}

void AlarmWindow::on_delete_timer_clicked()
{
    alarms.erase(alarms.begin()+ui->list_of_alarms->currentRow());
}
