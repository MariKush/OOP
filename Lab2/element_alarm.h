#ifndef ELEMENT_ALARM_H
#define ELEMENT_ALARM_H
#include<QDateTime>
#include <QDialog>
#include <QDebug>
namespace Ui {
class element_alarm;
}

class element_alarm : public QDialog
{
    Q_OBJECT

public:
    Ui::element_alarm *ui;
    explicit element_alarm(QWidget *parent = nullptr);
    ~element_alarm();

    QTime time;
    bool is_turn = false;
signals:
    void return_element_alarm(element_alarm *el);

private slots:
    void on_return_time_clicked();



private:

};

#endif // ELEMENT_ALARM_H
