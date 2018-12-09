#ifndef EXAMPLE2_H
#define EXAMPLE2_H

#include <QDialog>
#include "qcustomplot.h"

namespace Ui {
class Example2;
}

class Example2 : public QDialog
{
    Q_OBJECT

public:
    explicit Example2(QWidget *parent = nullptr);
    ~Example2();

private:
    Ui::Example2 *ui;
    QCustomPlot *customPlot;    // Объявляем графическое полотно
    QCPGraph *graphic;          // Объявляем график

private slots:
    void slotRangeChanged (const QCPRange &newRange);
};

#endif // EXAMPLE2_H

