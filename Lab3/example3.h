#ifndef EXAMPLE3_H
#define EXAMPLE3_H

#include <QDialog>
#include "qcustomplot.h"

namespace Ui {
class Example3;
}

class Example3 : public QDialog
{
    Q_OBJECT

public:
    explicit Example3(QWidget *parent = nullptr);
    ~Example3();

private:
    Ui::Example3 *ui;
    QCustomPlot *customPlot;
    QVBoxLayout *vbox;//выстраивает виджеты вертикально
    QPushButton *res;
    QCPBars *histogram;//График, представляющий гистограмму на графике.

private slots:
    void update();
};

#endif // EXAMPLE3_H
