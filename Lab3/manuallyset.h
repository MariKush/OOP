#ifndef MANUALLYSET_H
#define MANUALLYSET_H

#include <QDialog>
#include "qcustomplot.h"

namespace Ui {
class ManuallySet;
}

class ManuallySet : public QDialog
{
    Q_OBJECT

public:
    explicit ManuallySet(QWidget *parent = nullptr);
    ~ManuallySet();

private slots:
    void on_pushButtonApply_clicked();

private:
    Ui::ManuallySet *ui;
    QCustomPlot *customPlot;      // Объявляем объект QCustomPlot
    int const MAX_X = 100;
};

#endif // MANUALLYSET_H
