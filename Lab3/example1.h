#ifndef EXAMPLE1_H
#define EXAMPLE1_H

#include <QDialog>
#include <qcustomplot.h>
#include <QDebug>

namespace Ui {
class Example1;
}

class Example1 : public QDialog
{
    Q_OBJECT

public:
    explicit Example1(QWidget *parent = nullptr);
    ~Example1();

private:
    Ui::Example1 *ui;
    QCustomPlot *wGraphic;      // Объявляем объект QCustomPlot
    QCPCurve *verticalLine;     // Объявляем объект для вертикальной линии
    QCPItemTracer *tracer;      // Трасировщик по точкам графика

private slots:
    void slotMousePress(QMouseEvent * event);
    void slotMouseMove(QMouseEvent * event);
};

#endif // EXAMPLE1_H


