#ifndef ELEMENT_ALARM_H
#define ELEMENT_ALARM_H

/*
    K-28
    element_alarm.h
    Purpose: description class ElementAlarm
    @author Mariia Kushnirenko
    @version 1.1 17/11/18
*/


#include<QDateTime>
#include <QDialog>
#include <QDebug>

static int current_index_alarm=1;

namespace Ui {
class ElementAlarm;
}

class ElementAlarm : public QDialog
{
    Q_OBJECT

public:
    Ui::ElementAlarm *ui;
    explicit ElementAlarm(QWidget *parent = nullptr);
    ~ElementAlarm();
    QString name;
    QTime time;
    bool is_turn = false;
signals:
    void return_element_alarm(ElementAlarm *el);

private slots:
    void on_set_time_alarm_clicked();



private:

};

#endif // ELEMENT_ALARM_H
