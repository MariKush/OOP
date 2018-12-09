#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "example1.h"

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
    //this->close();

}
