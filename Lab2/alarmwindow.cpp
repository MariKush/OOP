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

AlarmWindow::AlarmWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlarmWindow)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(output_list_of_alarm()));
    connect(ui->FiltrBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changed_current_row_in_FiltrBox(int)));
    timer->start(10);
    ui->LineEditForSubname->setHidden(true);
}

AlarmWindow::~AlarmWindow()
{
    delete ui;
}

/*
    Add new alarm after clicked

    @param -
    @return -
*/
void AlarmWindow::on_add_new_alarm_clicked()
{
    ElementAlarm *el_al=new ElementAlarm;
    el_al->show();
    connect(el_al, SIGNAL(return_element_alarm(ElementAlarm *)), this, SLOT(push_alarm(ElementAlarm*)));
}

/*
    Insert alarm clock into list of alarms

    @param ElementAlarm * el
    @return -
*/
void AlarmWindow::push_alarm(ElementAlarm * el)
{
    alarms.push_back(el);
}

/*
    Changed current row in FiltrBox
    (selects whether to display the input field for subname)

    @param int cur
    @return -
*/
void AlarmWindow::changed_current_row_in_FiltrBox(int cur)
{
    switch (cur) {
    case 0:
    {
        ui->LineEditForSubname->setHidden(true);
        break;
    }
    case 1://search substring
    {
        ui->LineEditForSubname->setHidden(false);
        break;
    }
    case 2:
    {
        ui->LineEditForSubname->setHidden(true);
        break;
    }
    }
}

/*
    In the form of a string returns (with flashing ":")
    the difference between current time and given time

    @param QTime time (given time)
    @return QString in the form h:mm:ss (time to given time)
*/
QString AlarmWindow::time_to(QTime time)
{
    QTime tmp;
    tmp.setHMS(0,0,0);
    int secto=QTime::currentTime().secsTo(time);
    tmp=tmp.addSecs(secto);
    QChar s=':';
    if (secto%2==1)s=' ';
    return tmp.toString("h")+s+tmp.toString("mm")+s+tmp.toString("ss");
}

/*
    Information about the item: number, name, time of the call and time to call

    @param ElementAlarm *el - current element,
           int i - current item number
    @return QString
*/
QString for_write(ElementAlarm *el, int i)
{
    QString s=QString::number(i+1)+") ";
    s=s+el->name;
    s=s+el->time.toString(" h:mm ");
    if (el->is_turn) s=s+AlarmWindow::time_to(el->time);
    return s;
}

/*
    Output list of alarms (include filtrs)

    @param -
    @return -
*/
void AlarmWindow::output_list_of_alarm()
{
    int current_row=ui->list_of_alarms->currentRow();
    ui->list_of_alarms->clear();
    int size_list_of_alarms=alarms.size();
    switch (ui->FiltrBox->currentIndex()) {
    case 0://ALL
    {
        if (Complement) break;
        for (int i=0;i<size_list_of_alarms;i++)
        {
            ui->list_of_alarms->addItem(for_write(alarms[i], i));
            if(!alarms[i]->is_turn)
                ui->list_of_alarms->item(i)->setForeground(Qt::red);
        }
        break;
    }
    case 1:
    {
        int count=0;
        QString st=ui->LineEditForSubname->text();
        for (int i=0;i<size_list_of_alarms;i++)
        {
            if (!(alarms[i]->name.contains(st,Qt::CaseInsensitive)^Complement))continue;
            ui->list_of_alarms->addItem(for_write(alarms[i], i));
            if(!alarms[i]->is_turn)
                ui->list_of_alarms->item(count)->setForeground(Qt::red);
            count++;
        }
        break;
    }
    case 2:
    {
        int count=0;
        for (int i=0;i<size_list_of_alarms;i++)
        {
            if(!(alarms[i]->is_turn^Complement))continue;
            ui->list_of_alarms->addItem(for_write(alarms[i], i));
            if(!alarms[i]->is_turn)
                ui->list_of_alarms->item(count)->setForeground(Qt::red);
            count++;
        }
        break;
    }
    }

    ui->list_of_alarms->setCurrentRow(current_row);
    check_alarms();
    output_correct_alarm_buttons_name();
}

/*
    Output correct alarm buttons name

    @param -
    @return -
*/
void AlarmWindow::output_correct_alarm_buttons_name()
{
    int current_row=-1;
    current_row=ui->list_of_alarms->currentRow();

    //button start/stop current
    {
        if (current_row==-1)
        {
            ui->start_stop_alarm->setHidden(true);
        }
        else
        {
            ui->start_stop_alarm->setHidden(false);
            if(alarms[current_row]->is_turn)ui->start_stop_alarm->setText("stop");
            else ui->start_stop_alarm->setText("start");
        }
    }

    //button delete current
    {
        if (current_row==-1) ui->delete_alarm->setHidden(true);
        else ui->delete_alarm->setHidden(false);
    }

}

/*
    Checks whether it is necessary to make a call,
    if necessary, calls the calling function alarm_ring()
    and turns off the alarm clock

    @param -
    @return -
*/
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

/*
    Switches (turns on or off) the alarm clock

    @param -
    @return -
*/
void AlarmWindow::on_start_stop_alarm_clicked()
{
    if(alarms[ui->list_of_alarms->currentRow()]->is_turn)
        alarms[ui->list_of_alarms->currentRow()]->is_turn = false;
    else
        alarms[ui->list_of_alarms->currentRow()]->is_turn = true;
}

/*
    Delete alarm from the list of alarm clocks

    @param -
    @return -
*/
void AlarmWindow::on_delete_alarm_clicked()
{
    alarms.erase(alarms.begin()+ui->list_of_alarms->currentRow());
}

void AlarmWindow::on_ComplementBox_stateChanged()
{
    Complement=!Complement;
}
