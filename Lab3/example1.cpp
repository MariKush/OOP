#include "example1.h"
#include "ui_example1.h"
#include <QApplication>

Example1::Example1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Example1)
{
    ui->setupUi(this);
    //  this->setGeometry(300,100,640,480);

      // Инициализируем объект полотна для графика ...
      wGraphic = new QCustomPlot();
      ui->gridLayout->addWidget(wGraphic,1,0,1,1); // ... и устанавливаем

      // Инициализируем вертикальную линию
      verticalLine = new QCPCurve(wGraphic->xAxis, wGraphic->yAxis);

      // Подключаем сигналы событий мыши от полотна графика к слотам для их обработки
      connect(wGraphic, &QCustomPlot::mousePress, this, &Example1::slotMousePress);
      connect(wGraphic, &QCustomPlot::mouseMove, this, &Example1::slotMouseMove);

      // создаём вектора для вертикальной линии
      QVector<double> x(2) , y(2);
          x[0] = 0;
          y[0] = -50;
          x[1] = 0;
          y[1] = 50;


      wGraphic->addGraph(wGraphic->xAxis, wGraphic->yAxis);
              //addPlottable(verticalLine);   // Добавляем линию на полотно
      //customPlot->graph()->data()->set(timeData);
      //wGraphic->graph()->addPlottable(verticalLine);
      verticalLine->setName("Vertical");      // Устанавливаем ей наименование
      verticalLine->setData(x, y);            // И устанавливаем координаты

      // создаём вектора для графика
      QVector<double> x1(5) , y1(5);
          x1[0] = -45;
          y1[0] = -43;
          x1[1] = 46;
          y1[1] = 42;
          x1[2] = -25;
          y1[2] = -24;
          x1[3] = -12;
          y1[3] = 10;
          x1[4] = 25;
          y1[4] = 26;

      // Добавляем график на полотно
      wGraphic->addGraph(wGraphic->xAxis, wGraphic->yAxis);
      wGraphic->graph(0)->setData(x1,y1);     // Устанавливаем координаты точек графика

      // Инициализируем трассировщик
      tracer = new QCPItemTracer(wGraphic);
      tracer->setGraph(wGraphic->graph(0));   // Трассировщик будет работать с графиком

      // Подписываем оси координат
      wGraphic->xAxis->setLabel("x");
      wGraphic->yAxis->setLabel("y");

      // Устанавливаем максимальные и минимальные значения координат
      wGraphic->xAxis->setRange(-50,50);
      wGraphic->yAxis->setRange(-50,50);

      // Отрисовываем содержимое полотна
      wGraphic->replot();
}

Example1::~Example1()
{
    delete ui;

}

void Example1::slotMousePress(QMouseEvent *event)
{
    // Определяем координату X на графике, где был произведён клик мышью
    double coordX = wGraphic->xAxis->pixelToCoord(event->pos().x());

    // Подготавливаем координаты по оси X для переноса вертикальной линии
    QVector<double> x(2), y(2);
    x[0] = coordX;
    y[0] = -50;
    x[1] = coordX;
    y[1] = 50;

    // Устанавливаем новые координаты
    verticalLine->setData(x, y);

    // По координате X клика мыши определим ближайшие координаты для трассировщика
    tracer->setGraphKey(coordX);

    // Выводим координаты точки графика, где установился трассировщик, в lineEdit
    ui->lineEdit->setText("x: " + QString::number(tracer->position->key()) +
                          " y: " + QString::number(tracer->position->value()));
    wGraphic->replot(); // Перерисовываем содержимое полотна графика
}

void Example1::slotMouseMove(QMouseEvent *event)
{
    /* Если при передвижении мыши, ей кнопки нажаты,
     * то вызываем отработку координат мыши
     * через слот клика
     * */
    if(QApplication::mouseButtons()) slotMousePress(event);
}



