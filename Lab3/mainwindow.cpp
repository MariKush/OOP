#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include "example1.h"
#include "example2.h"
#include "example3.h"
#include "manuallyset.h"
#include "QMessageBox"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton1_clicked()
{ 
    Example1 *f = new Example1();
    f->show();
}

void MainWindow::on_pushButton2_clicked()
{
    Example2 *f = new Example2();
    f->show();
    //this->close();
}

void MainWindow::on_pushButton3_clicked()
{
    Example3 *f = new Example3();
    f->show();

}


void MainWindow::on_pushButtonManually_clicked()
{
    ManuallySet *f = new ManuallySet();
    f->show();
}

void MainWindow::on_pushButtonInfo_clicked()
{
    QMessageBox::information(this, "Information",
                                  "Examples:\n"
                                  "\t - 1 -  \n"
                                  "a) Draw the one graph on several points;\n"
                                  "b) Have a vertically movable line;\n"
                                  "c) For a vertical line will follow the router, which will be up to the next point on the graph of the vertical line.\n"
                                  "\t - 2 -  \n"
                                  "The build of charts with time. \n"
                                  "\t - 3 -  \n"
                                  "The program displays a histogram, the column values of which are set randomly. \n"
                              );
}
