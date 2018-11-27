/*
    K-28
    element_alarm.cpp
    Purpose: implementation of class ElementAlarm functions
    @author Mariia Kushnirenko
    @version 1.1 17/11/18
*/


#include "element_alarm.h"
#include "ui_element_alarm.h"

static int current_index_alarm=1;

ElementAlarm::ElementAlarm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ElementAlarm)
{
    ui->setupUi(this);
    ui->timeEdit->setTime(QTime::currentTime());
    ui->NameEdit->setMaxLength(8);
    QStringList strList;
    strList<<"Monday"<<"Tuesday"<<"Wednesday"<<"Thursday"<<"Friday"<<"Saturday"<<"Sunday";
    ui->WeekDay->addItems(strList);
    QListWidgetItem* item;
    for(int i = 0; i < 7; ++i)
    {
        item = ui->WeekDay->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
    }
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
    if(ui->NameEdit->text().isEmpty())
    {
        name="Alarm"+QString::number(current_index_alarm);
    }
    else
        name=ui->NameEdit->text();
    current_index_alarm++;
    for (int i = 0; i < 7; ++i)
    {
        WeekDay[i]=ui->WeekDay->item(i)->checkState();
    }
    emit return_element_alarm(this);
}


