#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include "example1.h"
#include "example2.h"
#include "example3.h"

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
