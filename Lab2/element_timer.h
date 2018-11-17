#ifndef ELEMENT_TIMER_H
#define ELEMENT_TIMER_H

#include <QDialog>
#include <QTime>
#include <QTimer>

namespace Ui {
class ElementTimer;
}

class ElementTimer : public QDialog
{
    Q_OBJECT

public:
    explicit ElementTimer(QWidget *parent = nullptr);
    ~ElementTimer();
    QTime time;
    QTimer *timer;
signals:
    void return_element_timer(ElementTimer *el);
private slots:
    void on_return_time_clicked();
    void stop_timer();

private:
    Ui::ElementTimer *ui;

};

#endif // ELEMENT_TIMER_H
