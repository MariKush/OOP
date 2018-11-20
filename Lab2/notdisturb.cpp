#include "notdisturb.h"
#include "ui_notdisturb.h"

NotDisturb::NotDisturb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NotDisturb)
{
    ui->setupUi(this);
}

NotDisturb::~NotDisturb()
{
    delete ui;
}

bool NotDisturb::can_call()
{
    qDebug()<<1;
    if (!not_disturb) return true;
    qDebug()<<2;
    if (ui->timeEdit_since->time()<ui->timeEdit_to->time())
    {
        qDebug()<<3;
        if (QTime::currentTime()>ui->timeEdit_since->time()&&QTime::currentTime()<ui->timeEdit_to->time())return false;
        qDebug()<<4;
        return true;
    }
    else
    {
        qDebug()<<5;
        if (QTime::currentTime()>ui->timeEdit_since->time()||QTime::currentTime()<ui->timeEdit_to->time())return false;//becouse 02:00 is between 23:00 and 05:00
        qDebug()<<6;
        return true;
    }


}
