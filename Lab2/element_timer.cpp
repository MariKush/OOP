#include "element_timer.h"
#include "ui_element_timer.h"

ElementTimer::ElementTimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ElementTimer)
{
    ui->setupUi(this);
    timer= new QTimer;
}

ElementTimer::~ElementTimer()
{
    delete ui;
}

void ElementTimer::on_return_time_clicked()
{
    time=ui->timeEdit->time();
    emit return_element_timer(this);
    this->close();
    timer->start(time.msecsSinceStartOfDay());
    connect(timer, SIGNAL(timeout()), this,SLOT(stop_timer()));
}

void ElementTimer::stop_timer()
{
    this->timer->stop();
}
