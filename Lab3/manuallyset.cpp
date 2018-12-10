#include "manuallyset.h"
#include "ui_manuallyset.h"
#include <QDebug>

ManuallySet::ManuallySet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManuallySet)
{
    ui->setupUi(this);

    customPlot = new QCustomPlot(); // Инициализируем графическое полотно
    ui->gridLayout->addWidget(customPlot,0,0,1,1);  // Устанавливаем customPlot в окно проложения

    customPlot->setInteraction(QCP::iRangeZoom,true);   // Включаем взаимодействие удаления/приближения
    customPlot->setInteraction(QCP::iRangeDrag, true);  // Включаем взаимодействие перетаскивания графика
    customPlot->axisRect()->setRangeDrag(Qt::Horizontal | Qt::Vertical);
    customPlot->axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);

    // Подписываем оси координат
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");

    //Установим область, которая будет показываться на графике
    customPlot->xAxis->setRange(-MAX_X, MAX_X);//Для оси Ox
}

ManuallySet::~ManuallySet()
{
    delete ui;
}

void ManuallySet::on_pushButtonApply_clicked()
{
    double a = -MAX_X; //Начало интервала, где рисуем график по оси Ox
    double b =  MAX_X; //Конец интервала, где рисуем график по оси Ox
    double h = 0.01; //Шаг, с которым будем пробегать по оси Ox

    int N=(b-a)/h + 2; //Вычисляем количество точек, которые будем отрисовывать
    QVector<double> x(N), y(N); //Массивы координат точек

    int A = ui->spinBoxA->value();
    int B = ui->spinBoxB->value();
    int C = ui->spinBoxC->value();

    //Вычисляем наши данные
    int i=0;
    for (double X=a; X<=b; X+=h)//Пробегаем по всем точкам
    {
        x[i] = X;
        y[i] = A*X*X+B*X+C;//Формула нашей функции
        qDebug() << i  << ") " << x[i] << " " << y[i];
        i++;
    }

    customPlot->clearGraphs();//Если нужно, но очищаем все графики
    //Добавляем один график в widget
    //customPlot->addGraph();
    //Говорим, что отрисовать нужно график по нашим двум массивам x и y
    //customPlot->graph(0)->setData(x, y);

    customPlot->addGraph(customPlot->xAxis, customPlot->yAxis);
    customPlot->graph(0)->setData(x,y);     // Устанавливаем координаты точек графика

    //Установим область, которая будет показываться на графике
    customPlot->xAxis->setRange(a, b);//Для оси Ox

    //Для показа границ по оси Oy сложнее, так как надо по правильному
    //вычислить минимальное и максимальное значение в векторах
    double minY = y[0], maxY = y[0];
    for (int i=1; i<N; i++)
    {
        if (y[i]<minY) minY = y[i];
        if (y[i]>maxY) maxY = y[i];
    }
    customPlot->yAxis->setRange(minY, maxY);//Для оси Oy

    //И перерисуем график на нашем widget
    customPlot->replot();
}
