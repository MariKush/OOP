#include "element_alarm.h"
#include "ui_element_alarm.h"

element_alarm::element_alarm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::element_alarm)
{
    ui->setupUi(this);
    ui->timeEdit->setTime(QTime::currentTime());
}

element_alarm::~element_alarm()
{
    delete ui;
}

void element_alarm::on_return_time_clicked()
{
    time=ui->timeEdit->time();
    this->close();
    is_turn=true;
    emit return_element_alarm(this);
}


