#include "example3.h"
#include "ui_example3.h"

Example3::Example3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Example3)
{
    ui->setupUi(this);
    resize(500,400);

    setWindowTitle(QString::fromUtf8("Гистограмма"));
    customPlot = new QCustomPlot(this);
    vbox = new QVBoxLayout(this);

    update();

    vbox->addWidget(customPlot);
    res = new QPushButton(QString::fromUtf8("Показать или обновить гистограмму"),this);
    vbox->addWidget(res);
    setLayout(vbox);

    // Сигналы
    connect(res,SIGNAL(clicked()),this,SLOT(update()));
}

Example3::~Example3()
{
    delete ui;
}

void Example3::update()
{

    histogram = new QCPBars(customPlot->xAxis, customPlot->yAxis);

    customPlot->addPlottable(histogram);

    // Установки цвета:
    QPen pen;
    pen.setWidthF(1.5);//Толщина контура столбца
    histogram->setName(QString::fromUtf8("Гистограмма")); // Легенда
    pen.setColor(QColor(50, 50, 100));// Цвет контура столбца
    histogram->setPen(pen);

    // Цвет самого столбца, четвертый параметр - прозрачность
    histogram->setBrush(QColor(50, 50, 250, 70));

    // Установки значений оси X:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    labels << "1" << "2" << "3" << "4" << "5" << "6" << "7";

    customPlot->xAxis->setAutoTicks(false);
    customPlot->xAxis->setAutoTickLabels(false);

    customPlot->xAxis->setTickVector(ticks);
    customPlot->xAxis->setTickVectorLabels(labels);


    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->setRange(0, 8);

    // Установки значений оси Y:
    customPlot->yAxis->setRange(0, 12.1);
    customPlot->yAxis->setPadding(5);
    customPlot->yAxis->setLabel(QString::fromUtf8("Значения элементов"));
    customPlot->yAxis->grid()->setSubGridVisible(true);

    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);


    // Данные:
    QVector<double> histogramData;
    qsrand (time(nullptr));
    histogramData  << qrand() % 10 + 2.5
                << qrand() % 10 + 2.5
                << qrand() % 10 + 2.5
                << qrand() % 10 + 2.5
                << qrand() % 10 + 2.5
                << qrand() % 10 + 2.5
                << qrand() % 10 + 2.5;
    histogram->setData(ticks, histogramData);

    // Легенда:
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 200));

    QPen legendPen;
    legendPen.setColor(QColor(130, 130, 130, 200));
    customPlot->legend->setBorderPen(legendPen);

    //шрифти
    QFont legendFont = font();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    customPlot->replot();

    // Сброс всех установок графика:
    customPlot->removePlottable(histogram);

}


